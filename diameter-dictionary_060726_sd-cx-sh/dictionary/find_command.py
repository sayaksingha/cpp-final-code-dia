import re

with open("ts_129_212_text.txt", "r", encoding="utf-8") as f:
    text = f.read()

lines = text.split('\n')
for i, line in enumerate(lines):
    if '8388637' in line and '::=' in line:
        print(f"Found command definition at line {i}:")
        for j in range(i, i+50):
            if lines[j].strip() == '':
                # print empty lines too, just in case
                pass
            print(lines[j])
            # stop if we hit another ::=
            if j > i and '::=' in lines[j]:
                break
        print("--------------------")
