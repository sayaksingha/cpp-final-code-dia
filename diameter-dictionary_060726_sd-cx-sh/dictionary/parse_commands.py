import re

with open("ts_129_212_text.txt", "r", encoding="utf-8") as f:
    text = f.read()

# Commands are usually specified like:
# < TDF-Session-Request > ::= < Diameter Header: 8388637, REQ, PXY >
# < Session-Id >
# { Auth-Application-Id }
# { Origin-Host }
# ...

commands = [
    ("TDF-Session-Request (TSR)", r"<\s*TDF-Session-Request\s*>.*?::=.*?<.*?>(.*?)(?:<\s*TDF-Session-Answer\s*>|5\.6\.|$)"),
    ("TDF-Session-Answer (TSA)", r"<\s*TDF-Session-Answer\s*>.*?::=.*?<.*?>(.*?)(?:<\s*CC-Request\s*>|5\.6\.|$)"),
    ("CC-Request (CCR) Sd", r"<\s*CC-Request\s*>.*?::=.*?<.*?>(.*?)(?:<\s*CC-Answer\s*>|5\.6\.|$)"),
    ("CC-Answer (CCA) Sd", r"<\s*CC-Answer\s*>.*?::=.*?<.*?>(.*?)(?:<\s*Re-Auth-Request\s*>|5\.6\.|$)"),
    ("Re-Auth-Request (RAR) Sd", r"<\s*Re-Auth-Request\s*>.*?::=.*?<.*?>(.*?)(?:<\s*Re-Auth-Answer\s*>|5\.6\.|$)"),
    ("Re-Auth-Answer (RAA) Sd", r"<\s*Re-Auth-Answer\s*>.*?::=.*?<.*?>(.*?)(?:5\.6\.|$)"),
]

for name, pattern in commands:
    print(f"\n--- {name} ---")
    match = re.search(pattern, text, re.DOTALL | re.IGNORECASE)
    if match:
        content = match.group(1).strip()
        lines = [line.strip() for line in content.split('\n') if line.strip()]
        # Just grab the AVP list part, stop when we see regular text paragraphs
        avps = []
        for line in lines:
            if re.match(r'^[\{\[\<].*[\}\]\>]$', line) or line.startswith('*'):
                 avps.append(line)
            else:
                 # maybe it's just an AVP wrapped awkwardly
                 if '[' in line or '{' in line or '<' in line:
                     avps.append(line)
                 # limit check to prevent printing huge paragraphs
                 if len(avps) > 50:
                     break
        print("\n".join(avps[:40]))
    else:
        print("Not found.")

