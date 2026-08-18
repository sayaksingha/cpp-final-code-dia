import re

with open("ts_129_212_text.txt", "r", encoding="utf-8") as f:
    text = f.read()

# Let's find any occurrences of TDF-Session-Request
matches = re.finditer(r"<\s*TDF-Session-Request\s*>.*?::=.*?(?:<\s*TDF-Session-Answer\s*>|5\.6\.|5\.6\.2|$)", text, re.DOTALL | re.IGNORECASE)
found = False
for match in matches:
    found = True
    print(match.group(0)[:1000])

if not found:
    print("Could not find < TDF-Session-Request >")

print("\n--- Let's search for exact string 'TDF-Session-Request' ---")
lines = text.split('\n')
for i, line in enumerate(lines):
    if 'TDF-Session-Request' in line:
        print(f"Line {i}: {line}")
        if '::=' in lines[i+1] or '::=' in lines[i+2]:
            print("\n".join(lines[i:i+30]))
            break
