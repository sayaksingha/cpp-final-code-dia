import re

with open("ts_129_212_text.txt", "r", encoding="utf-8") as f:
    text = f.read()

lines = text.split('\n')
printing = False
count = 0
for line in lines:
    if '5b.6 ' in line or '5b.6.' in line:
        printing = True
    if '5c.1 ' in line or '5c.2 ' in line:
        break
    
    if printing:
        if '<' in line and '>' in line and '::=' in line:
            print("-----------------------------------------")
            print(line)
        elif ('{' in line and '}' in line) or ('[' in line and ']' in line) or ('<' in line and '>' in line):
            if '::=' not in line:
                print(line.strip())
