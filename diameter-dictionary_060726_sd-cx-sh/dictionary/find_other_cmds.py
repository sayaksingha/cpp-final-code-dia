import re

with open("ts_129_212_text.txt", "r", encoding="utf-8") as f:
    text = f.read()

lines = text.split('\n')
for i, line in enumerate(lines):
    if '5b.6.4 CC-Request (CCR) Command' in line or '5b.6.5 CC-Answer (CCA) Command' in line or '5b.6.6 Re-Auth-Request (RAR) Command' in line or '5b.6.7 Re-Auth-Answer (RAA) Command' in line:
        print(f"Found command section at line {i}: {line}")
        # find the next ::=
        for j in range(i, i+150):
            if '::=' in lines[j]:
                for k in range(j, j+70):
                    if lines[k].strip() == '': continue
                    print(lines[k])
                    if '::=' in lines[k] and k > j:
                        break
                break
        print("--------------------")
