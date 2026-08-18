import json
import sys

def build_grouped_avp(name, avps_dict, out_lines, processed):
    if name in processed:
        return
    processed.add(name)
    
    details = avps_dict.get(name)
    if not details or details.get("Type", "").lower() != "grouped":
        return
        
    children = details.get("Children", [])
    out_lines.append(f"    <grouped-avp = {name} >")
    
    for child in children:
        child_name = child.get("name")
        bracket = child.get("bracket")
        if bracket == '< >' or bracket == '{ }' or bracket == '[ ]' or bracket == '*[ ]':
            xml_avp = f"        <avp = {child_name} >"
        else:
            xml_avp = f"        <avp = {child_name} >"
        out_lines.append(xml_avp)
        
    out_lines.append("    </grouped-avp>")
    out_lines.append("")
    
    # Recursively build nested grouped AVPs
    for child in children:
        child_name = child.get("name")
        build_grouped_avp(child_name, avps_dict, out_lines, processed)

def main():
    print("==================================================")
    print("  GENERIC DIAMETER XML DICTIONARY COMPILER  ")
    print("==================================================")
    
    json_file = 'avp_verification_tracking.json'
    try:
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
    except FileNotFoundError:
        print(f"[ERROR] {json_file} not found. Run diameter_spec_scraper.py first.")
        sys.exit(1)
        
    commands = data.get('commands', [])
    avps = data.get('avps', {})
    
    if not commands or not avps:
        print("[ERROR] JSON file is empty or missing data.")
        sys.exit(1)
        
    out_lines = []
    out_lines.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>")
    out_lines.append("<dictionary>")
    out_lines.append("")
    
    # 1. COMMAND BLOCKS
    for cmd in commands:
        cmd_name = cmd.get('command')
        cmd_code = cmd.get('code')
        flags_str = cmd.get('flags', '')
        
        if 'REQ' in flags_str and 'PXY' in flags_str:
            xml_flags = "request proxyable null null"
        elif 'REQ' in flags_str:
            xml_flags = "request null null null"
        elif 'PXY' in flags_str:
            xml_flags = "proxyable null null null"
        else:
            xml_flags = "null null null null"
            
        out_lines.append(f"    <command = {cmd_name}>")
        out_lines.append(f"        <cmd-code = {cmd_code} >")
        out_lines.append(f"        <command-flags = {xml_flags} >")
        out_lines.append(f"        <protocol-version = 1 >")
        out_lines.append("    </command>")
        out_lines.append("")
        
    # 2. MESSAGE BLOCKS
    for cmd in commands:
        cmd_name = cmd.get('command')
        out_lines.append(f"    <message = {cmd_name}>")
        
        for avp_entry in cmd.get('avps', []):
            name = avp_entry.get('name')
            out_lines.append(f"        <avp = {name} >")
            
        out_lines.append("    </message>")
        out_lines.append("")
        
    # 3. GROUPED AVP BLOCKS
    out_lines.append("    <!-- Grouped AVP Definitions -->")
    processed_grouped = set()
    for name, details in avps.items():
        if details.get("Type", "").lower() == "grouped":
            build_grouped_avp(name, avps, out_lines, processed_grouped)
            
    # 4. FLAT AVP DEFINITIONS
    out_lines.append("    <!-- Flat AVP Definitions -->")
    for name, details in avps.items():
        if not details: continue
        
        code = details.get('Code', '')
        v_id = details.get('Vendor-ID', '')
        avp_type = details.get('Type', '')
        m_bit = details.get('M-Bit', 'must')
        
        vendor_attr = f' vendor="{v_id}"' if v_id and v_id != "Unknown" and v_id != "10415" else ""
        out_lines.append(f'    <avp-def = {name} code="{code}" mandatory="{m_bit}"{vendor_attr}>')
        out_lines.append(f'        <type = {avp_type} >')
        out_lines.append('    </avp-def>')
        out_lines.append("")

    out_lines.append("</dictionary>")
    
    out_file = 'diameter.dictionary.generic'
    with open(out_file, 'w', encoding='utf-8') as f:
        f.write("\n".join(out_lines))
        
    print(f"\nSUCCESS: Generated '{out_file}' from JSON data.")
    print(f"Contains {len(commands)} commands, {len(processed_grouped)} grouped AVPs, and {len(avps)} total definitions.")
    
if __name__ == "__main__":
    main()
