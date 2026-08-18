import re

with open("ts_129_212_text.txt", "r", encoding="utf-8") as f:
    text = f.read()

lines = text.split('\n')
for i, line in enumerate(lines):
    if '4b.6.' in line or '4b.6 ' in line or '<TDF-Session-Request>' in line or '< TDF-Session-Request >' in line.replace(' ', ''):
        print(f"Line {i}: {line}")
        if '::=' in lines[i+1] or '::=' in lines[i+2]:
            print("\n".join(lines[i:i+30]))
            
# Also check for exactly how TSR is defined in the text
matches = re.finditer(r"<\s*TDF-Session-Request\s*>.*?::=.*?(?:<\s*TDF-Session-Answer\s*>|4b\.6\.|4b\.6\.2|$)", text, re.DOTALL | re.IGNORECASE)
for match in matches:
    print("\nMATCH FOUND:")
    print(match.group(0)[:1000])
