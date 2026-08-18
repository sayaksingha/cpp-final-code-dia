#!/usr/bin/env python3
"""
Diameter Specification Scraper – Recursively resolves AVPs,
searching the web for missing definitions (using DuckDuckGo)
and outputting a structured JSON for later XML generation.

Handles:
  - Plain text (RFCs as .txt, 3GPP TS text files)
  - HTML (IETF tools pages like https://datatracker.ietf.org/doc/html/rfc7944)
  - PDF (ETSI specs like https://www.etsi.org/.../ts_129212v190100p.pdf)
"""

import os
import re
import json
import urllib.request
import sys
import ssl
import tempfile
from html.parser import HTMLParser
from collections import OrderedDict

# ── Optional PDF support ─────────────────────────────────────────
try:
    from PyPDF2 import PdfReader
    PDF_SUPPORT = True
except ImportError:
    PDF_SUPPORT = False

# ── Web search setup ──────────────────────────────────────────────
try:
    try:
        from ddgs import DDGS
    except ImportError:
        from duckduckgo_search import DDGS
    SEARCH_ENABLED = True
except ImportError:
    SEARCH_ENABLED = False
    print("\n[INFO] 'ddgs' not installed.")
    print("       Install with: pip install ddgs")
    print("       Web search will be disabled; you can still paste direct URLs.\n")

# ── HTML to text conversion ───────────────────────────────────────
class HTMLStripper(HTMLParser):
    """Simple HTML to plain text converter, preserving line breaks."""
    def __init__(self):
        super().__init__()
        self.reset()
        self.strict = False
        self.convert_charrefs = True
        self.text = []
    def handle_data(self, d):
        self.text.append(d)
    def handle_starttag(self, tag, attrs):
        if tag in ('br', 'p', 'div', 'li', 'tr'):
            self.text.append('\n')
    def get_text(self):
        return ''.join(self.text)

def html_to_text(html_content):
    stripper = HTMLStripper()
    stripper.feed(html_content)
    return stripper.get_text()

# ── Fetch helper (PDF, HTML, plain text) ──────────────────────────
def fetch_document(source, cache=None):
    """
    Retrieve text from URL or local file.
    Detects PDF, HTML, or plain text and extracts accordingly.
    Saves extracted text to a local file for verification.
    """
    if cache and source in cache:
        return cache[source]

    text = ""
    safe_filename = re.sub(r'[^A-Za-z0-9_\-]', '_', source.split('/')[-1])
    if not safe_filename: safe_filename = "document"
    debug_file = f"extracted_text_{safe_filename}.txt"

    if source.startswith(('http://', 'https://')):
        print(f"[DOWNLOAD] {source}")
        ctx = ssl.create_default_context()
        ctx.check_hostname = False
        ctx.verify_mode = ssl.CERT_NONE
        try:
            req = urllib.request.Request(source, headers={'User-Agent': 'Mozilla/5.0'})
            with urllib.request.urlopen(req, context=ctx) as resp:
                content_type = resp.headers.get('Content-Type', '')
                raw_data = resp.read()
        except Exception as e:
            print(f"[ERROR] Download failed: {e}")
            return ""

        # Detect PDF by content type or magic bytes
        if 'pdf' in content_type.lower() or (len(raw_data) > 4 and raw_data[:4] == b'%PDF'):
            print("[INFO] Detected PDF document.")
            if PDF_SUPPORT:
                text = extract_pdf_text(raw_data)
            else:
                print("[WARNING] PyPDF2 is not installed. Cannot extract text from PDF.")
                return ""

        # Detect HTML
        elif 'text/html' in content_type.lower() or raw_data.strip().startswith(b'<'):
            print("[INFO] Detected HTML document. Stripping tags...")
            try:
                html = raw_data.decode('utf-8', errors='ignore')
            except:
                html = raw_data.decode('latin-1', errors='ignore')
            text = html_to_text(html)

        # Assume plain text
        else:
            try:
                text = raw_data.decode('utf-8', errors='ignore')
            except:
                text = raw_data.decode('latin-1', errors='ignore')

    else:
        # Local file
        if not os.path.exists(source):
            print(f"[ERROR] File not found: {source}")
            return ""
        # Check extension
        ext = os.path.splitext(source)[1].lower()
        if ext == '.pdf':
            print("[INFO] Local PDF file detected.")
            if PDF_SUPPORT:
                try:
                    reader = PdfReader(source)
                    for page in reader.pages:
                        text += page.extract_text() + "\n"
                    print(f"[INFO] Extracted {len(text)} characters from PDF.")
                except Exception as e:
                    print(f"[ERROR] PDF extraction failed: {e}")
                    return ""
            else:
                print("[WARNING] PyPDF2 not installed. Provide a plain text file instead.")
                return ""
        elif ext in ('.html', '.htm'):
            print("[INFO] Local HTML file detected.")
            with open(source, 'r', encoding='utf-8', errors='ignore') as f:
                html = f.read()
            text = html_to_text(html)
        else:
            # Plain text
            print(f"[READ] Local file: {source}")
            with open(source, 'r', encoding='utf-8', errors='ignore') as f:
                text = f.read()
                
    if text:
        with open(debug_file, 'w', encoding='utf-8') as f:
            f.write(text)
        print(f"[VERIFICATION] Saved raw extracted text to: {debug_file}")

    if cache is not None:
        cache[source] = text
        
    return text

def extract_pdf_text(pdf_bytes):
    """Extract text from PDF bytes using PyPDF2."""
    with tempfile.NamedTemporaryFile(delete=False, suffix='.pdf') as tmp:
        tmp.write(pdf_bytes)
        tmp_path = tmp.name
    try:
        reader = PdfReader(tmp_path)
        text = ""
        for page in reader.pages:
            text += page.extract_text() + "\n"
        print(f"[INFO] Extracted {len(text)} characters from PDF.")
        return text
    except Exception as e:
        print(f"[ERROR] PDF extraction failed: {e}")
        return ""
    finally:
        os.unlink(tmp_path)

# ── Web search function ───────────────────────────────────────────
def search_web(query):
    if not SEARCH_ENABLED:
        return None
    print(f"\n[SEARCH] Query: '{query}'")
    try:
        results = list(DDGS().text(query, max_results=5))
        if not results:
            print("[SEARCH] No results found.")
            url = input(f"  Enter URL manually (or Enter to skip): ").strip()
            return url if url else None
        print("\n--- Top Results ---")
        for i, r in enumerate(results):
            print(f"  [{i+1}] {r.get('title', 'No title')}")
            print(f"       {r.get('href', '')}")
        while True:
            choice = input(f"Enter number (1-{len(results)}), paste a URL, or Enter to skip: ").strip()
            if not choice:
                return None
            if choice.isdigit():
                idx = int(choice) - 1
                if 0 <= idx < len(results):
                    return results[idx].get('href')
                print("Invalid number.")
            elif choice.startswith('http'):
                return choice
            else:
                print("Please enter a valid URL or a number.")
    except Exception as e:
        print(f"[SEARCH ERROR] {e}")
        return None

# ── ABNF extraction (improved) ────────────────────────────────────
def extract_abnf_block(text, start_pos):
    line_end = text.find('\n', start_pos)
    if line_end == -1:
        line_end = len(text)
    abnf_lines = []
    pos = start_pos
    first_line = text[start_pos:line_end].strip()
    if not first_line:
        return "", start_pos
    abnf_lines.append(first_line)
    pos = line_end + 1
    
    # Allow a small lookahead for blank lines interrupting the block
    blank_lines_count = 0
    
    while pos < len(text):
        next_line_end = text.find('\n', pos)
        if next_line_end == -1:
            next_line_end = len(text)
        line = text[pos:next_line_end].strip()
        
        # PDF pagination artifacts often interrupt blocks. Skip them.
        if '3GPP TS' in line or 'ETSI TS' in line or 'Release' in line:
            pos = next_line_end + 1
            continue
            
        if not line:
            blank_lines_count += 1
            if blank_lines_count > 2:
                break # Too many blank lines, probably end of block
            pos = next_line_end + 1
            continue
            
        blank_lines_count = 0
        
        # In Diameter ABNF, every single AVP definition line MUST contain a bracket or the ::= operator
        if ('[' in line or '{' in line or '<' in line or
            '::=' in line or
            'Diameter Header' in line):
            abnf_lines.append(line)
            pos = next_line_end + 1
        else:
            break
            
    cleaned = [l for l in abnf_lines if l and not l.startswith(';')]
    return '\n'.join(cleaned), pos

# ── Parse AVPs from ABNF string ───────────────────────────────────
def parse_avps_from_abnf(abnf_text):
    avps = []
    for line in abnf_text.split('\n'):
        # Skip the definition line so we don't accidentally parse the command itself as an AVP!
        if '::=' in line:
            continue
            
        for match in re.finditer(r'(\*?\[?)(<[^>]+>|\{[^}]+\}|\[[^\]]+\])', line):
            bracket = match.group(2)
            name = re.sub(r'[<>{}\[\]]', '', bracket).strip()
            if name == 'AVP' or 'Diameter Header' in name:
                continue
            multiple = 'yes' if match.group(1).startswith('*') else 'no'
            avps.append({"name": name, "multiple": multiple, "bracket": bracket})
    return avps

# ── Command detection ─────────────────────────────────────────────
def find_commands(text):
    print("\n--- Scanning for Diameter Commands ---")
    commands = []
    pattern = re.compile(
        r'<([A-Za-z0-9\-]+)>\s*::=\s*<\s*Diameter\s*Header:\s*(\d+)\s*,?\s*(.*?)\s*>',
        re.IGNORECASE
    )
    for match in pattern.finditer(text):
        cmd_name = match.group(1)
        cmd_code = match.group(2)
        flags = match.group(3)
        abnf_str, _ = extract_abnf_block(text, match.start())
        avps = parse_avps_from_abnf(abnf_str)
        commands.append({
            "command": cmd_name,
            "code": cmd_code,
            "flags": flags,
            "avps": avps,
            "abnf_raw": abnf_str
        })
        print(f"  Found Command: {cmd_name} (code {cmd_code}) - {len(avps)} AVPs")
    return commands

# ── AVP detail resolution ─────────────────────────────────────────
def resolve_avp_details(avp_name, text, source_ref):
    # 1. Table row
    table_pat = re.compile(
        rf'^{re.escape(avp_name)}\s+(\d+)\s+\S+\s+(\S+)\s+',
        re.MULTILINE | re.IGNORECASE
    )
    m = table_pat.search(text)
    if m:
        return {
            "Code": m.group(1),
            "Type": m.group(2),
            "M-Bit": "must",
            "Vendor-ID": "0",
            "Source Reference": source_ref,
            "Status": "Auto-Extracted (Table)"
        }

    # 2. AVP header
    header_pat = re.compile(
        rf'{re.escape(avp_name)}\s*::=\s*<\s*AVP\s*Header:\s*(\d+)\s*(.*?)>',
        re.IGNORECASE
    )
    m = header_pat.search(text)
    if m:
        code = m.group(1)
        rest = m.group(2).strip()
        vendor = "0"
        m_bit = "must"
        if re.search(r'V(?:endor)?\s*=\s*(\d+)', rest, re.IGNORECASE):
            vendor = re.search(r'V(?:endor)?\s*=\s*(\d+)', rest, re.IGNORECASE).group(1)
        if re.search(r'\bM\b', rest):
            m_bit = "must"
        else:
            m_bit = "may"
        return {
            "Code": code,
            "Type": "",
            "M-Bit": m_bit,
            "Vendor-ID": vendor,
            "Source Reference": source_ref,
            "Status": "AVP Header Found"
        }

    # 3. Prose
    prose_pat = re.compile(
        rf'{re.escape(avp_name)}\s*\(AVP\s+code\s+(\d+)\).*?type\s+(\w+)',
        re.IGNORECASE | re.DOTALL
    )
    m = prose_pat.search(text)
    if m:
        return {
            "Code": m.group(1),
            "Type": m.group(2),
            "M-Bit": "must",
            "Vendor-ID": "0",
            "Source Reference": source_ref,
            "Status": "Auto-Extracted (Prose)"
        }

    # 4. External reference (from Re-used AVP Table)
    ext_table_pat = re.compile(
        rf'^{re.escape(avp_name)}\s+(?:IETF\s+)?(RFC\s*\d+|3GPP\s*TS\s*[\d.]+|ETSI\s*TS\s*[\d\s]+|ITU-T\s*\S+)',
        re.MULTILINE | re.IGNORECASE
    )
    m = ext_table_pat.search(text)
    if m:
        return {
            "Code": "",
            "Type": "",
            "M-Bit": "",
            "Vendor-ID": "",
            "Source Reference": m.group(1),
            "Status": "External Reference"
        }

    # 5. External reference (from Prose)
    ext_prose_pat = re.compile(
        rf'{re.escape(avp_name)}.*?(?:defined\s+in|see|refer\s+to).*?((?:RFC\s*\d+|3GPP\s*TS\s*[\d.]+|ITU-T\s*\S+))',
        re.IGNORECASE
    )
    m = ext_prose_pat.search(text)
    if m:
        return {
            "Code": "",
            "Type": "",
            "M-Bit": "",
            "Vendor-ID": "",
            "Source Reference": m.group(1),
            "Status": "External Reference"
        }


    return None

# ── Grouped AVP detection ─────────────────────────────────────────
def find_grouped_definition(avp_name, text):
    pattern = re.compile(
        rf'{re.escape(avp_name)}\s*::=\s*<\s*AVP\s*Header:.*?>',
        re.IGNORECASE
    )
    m = pattern.search(text)
    if m:
        abnf, _ = extract_abnf_block(text, m.start())
        children = parse_avps_from_abnf(abnf)
        if children:
            return children, abnf
    return None, None

# ── Recursive resolver ────────────────────────────────────────────
def process_avps_recursively(avp_names, start_text, start_ref, global_avps):
    pending = list(avp_names)
    doc_cache = {}
    visited_external = set()

    while pending:
        name = pending.pop(0)
        if name in global_avps:
            continue

        print(f"\n[RESOLVING] {name}")
        details = resolve_avp_details(name, start_text, start_ref)

        if details and details["Status"].startswith("External Reference"):
            ref = details["Source Reference"]
            print(f"  -> External ref: {ref}")
            # We need to search for this reference's URL if not visited
            if ref not in visited_external:
                visited_external.add(ref)
                # Show reference and give user the option to provide a link directly
                user_url = input(f"  Provide URL for {ref} directly, or press Enter to auto-search: ").strip()
                if user_url.startswith("http"):
                    url = user_url
                elif SEARCH_ENABLED:
                    url = search_web(f'"{name}" diameter AVP {ref}')
                else:
                    url = None
                if url:
                    ext_text = fetch_document(url, doc_cache)
                    if ext_text:
                        new_det = resolve_avp_details(name, ext_text, url)
                        if new_det:
                            details = new_det
            if details["Status"] == "External Reference":
                details["Status"] = "External - Manual entry needed"
                global_avps[name] = details
                continue

        if not details:
            print(f"  No definition found in current source.")
            if SEARCH_ENABLED:
                # Build a relaxed query that doesn't use restrictive site: operators,
                # which often cause DuckDuckGo to return empty results.
                query = f'"{name}" diameter AVP RFC 3GPP'
                print(f"[SEARCH] Query: '{query}'")
                url = search_web(query)
            else:
                url = input(f"  Enter URL to search for {name}: ").strip()
            if url:
                ext_text = fetch_document(url, doc_cache)
                details = resolve_avp_details(name, ext_text, url)
            if not details:
                details = {
                    "Code": "", "Type": "", "M-Bit": "", "Vendor-ID": "",
                    "Source Reference": "Unknown",
                    "Status": "Manual Entry Required"
                }

        # Grouped check
        grouped_children = None
        sources_to_check = []
        if details.get("Source Reference") not in ("Unknown", start_ref):
            ref_text = doc_cache.get(details["Source Reference"], "")
            if ref_text:
                sources_to_check.append(ref_text)
        sources_to_check.append(start_text)

        for src in sources_to_check:
            children, _ = find_grouped_definition(name, src)
            if children:
                grouped_children = children
                break

        if grouped_children:
            if details["Type"] != "Grouped":
                details["Type"] = "Grouped"
            details["Children"] = grouped_children
            print(f"  -> Grouped AVP with {len(grouped_children)} children")
            for child in grouped_children:
                if child["name"] not in global_avps:
                    pending.append(child["name"])
        else:
            if not details.get("Type"):
                pass

        global_avps[name] = details
        print(f"  => STATUS: {details['Status']} | CODE: {details.get('Code','?')} | TYPE: {details.get('Type','?')}")

# ── Main entry point ──────────────────────────────────────────────
def main():
    print("=" * 60)
    print("  DIAMETER SPECIFICATION SCRAPER (PDF/HTML/Text)")
    print("=" * 60)

    source = input("Enter URL or file path of the main specification: ").strip()
    if not source:
        print("No source provided. Exiting.")
        return

    text = fetch_document(source)
    if not text:
        print("Failed to load document. Exiting.")
        return

    commands = find_commands(text)
    if not commands:
        print("[WARNING] No Diameter commands found in the document.")
        print("          This may happen if the spec is not in plain text or is structured differently.")

    if commands:
        print("\n--- Command Filtering ---")
        for i, cmd in enumerate(commands):
            print(f"  [{i+1}] {cmd['command']} (Code: {cmd['code']}) - {len(cmd['avps'])} AVPs")
        print("\nTS 29.212 contains multiple interfaces (Gx, Sd, St, etc.).")
        choice = input("Enter comma-separated numbers to include (e.g., 9,10,11,12) or press Enter to process ALL: ").strip()
        
        if choice:
            selected_indices = []
            for part in choice.split(','):
                if part.strip().isdigit():
                    idx = int(part.strip()) - 1
                    if 0 <= idx < len(commands):
                        selected_indices.append(idx)
            if selected_indices:
                commands = [commands[i] for i in selected_indices]
                print(f"Filtered down to {len(commands)} commands.")

    root_avps = set()
    for cmd in commands:
        for avp in cmd['avps']:
            root_avps.add(avp['name'])

    global_avps = OrderedDict()

    if root_avps:
        print(f"\nStarting recursive resolution of {len(root_avps)} root AVPs...")
        process_avps_recursively(list(root_avps), text, source, global_avps)
    else:
        print("\nNo commands found. You can manually enter AVP names to resolve.")
        names_input = input("Enter comma-separated AVP names (or press Enter to finish): ").strip()
        if names_input:
            avp_list = [n.strip() for n in names_input.split(',') if n.strip()]
            process_avps_recursively(avp_list, text, source, global_avps)

    output = {
        "commands": commands,
        "avps": global_avps
    }

    out_file = "avp_verification_tracking.json"
    with open(out_file, 'w', encoding='utf-8') as f:
        json.dump(output, f, indent=4, ensure_ascii=False)

    print("\n" + "=" * 60)
    print(f"SUCCESS: AVP tracking data saved to '{out_file}'")
    print("Next step: review the JSON, then run generate_xml_from_json.py")
    print("=" * 60)

if __name__ == "__main__":
    import warnings
    warnings.filterwarnings("ignore", module="duckduckgo_search")
    main()