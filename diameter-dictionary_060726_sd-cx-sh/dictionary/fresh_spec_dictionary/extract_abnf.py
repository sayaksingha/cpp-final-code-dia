import csv
import re

with open('../ts_129_212_text.txt', 'r', encoding='utf-8') as f:
    text = f.read()

command_names = [
    ("TDFSessionRequest", "5b.6.2 TDF-Session-Request"),
    ("TDFSessionAnswer", "5b.6.3 TDF-Session-Answ"),
    ("CreditControlRequestSd", "5b.6.4 CC-Request"),
    ("CreditControlAnswerSd", "5b.6.5 CC-Answer"),
    ("ReAuthRequestSd", "5b.6.6 Re-Auth-Request"),
    ("ReAuthAnswerSd", "5b.6.7 Re-Auth-Answer")
]

worksheets = []

for dict_name, section_title in command_names:
    idx = text.rfind(section_title)
    if idx == -1:
        print(f"Could not find {section_title}")
        continue
    
    block = text[idx:idx+5000] 
    
    m = re.search(r'<[^>]+>\s*::=\s*<\s*Diameter Header:\s*(\d+)(.*?)\s*>((?:(?!5b\.6|5c).)*)', block, re.DOTALL)
    if m:
        cmd_code = m.group(1).strip()
        flags_str = m.group(2).strip(', ')
        abnf_body = m.group(3)
        
        for line in abnf_body.split('\n'):
            line = line.strip()
            if not line: continue
            
            if not (line.startswith('<') or line.startswith('{') or line.startswith('[') or line.startswith('*')):
                break
                
            avp_matches = re.findall(r'(<[^>]+>|\{[^}]+\}|\[[^\]]+\]|\*\[[^\]]+\])', line)
            
            for avp_match in avp_matches:
                avp_match = avp_match.strip()
                if avp_match.startswith('<') and avp_match.endswith('>'):
                    bracket = '< >'
                    multiple = 'no'
                    avp_name = avp_match.strip('<> ').strip()
                elif avp_match.startswith('{') and avp_match.endswith('}'):
                    bracket = '{ }'
                    multiple = 'no'
                    avp_name = avp_match.strip('{} ').strip()
                elif avp_match.startswith('[') and avp_match.endswith(']'):
                    bracket = '[ ]'
                    multiple = 'no'
                    avp_name = avp_match.strip('[] ').strip()
                elif avp_match.startswith('*[') and avp_match.endswith(']'):
                    bracket = '*[ ]'
                    multiple = 'yes'
                    avp_name = avp_match.strip('*[] ').strip()
                else:
                    bracket = 'unknown'
                    multiple = 'no'
                    avp_name = avp_match.strip('{}[]*<> ')
                
                if avp_name == 'AVP': continue
                if avp_name.startswith('Diameter Header'): continue
                
                worksheets.append({
                    "Command": dict_name,
                    "Code": cmd_code,
                    "Flags": flags_str,
                    "AVP": avp_name,
                    "Bracket": bracket,
                    "Multiple": multiple
                })
    else:
        print(f"Failed to extract ABNF for {dict_name}")

with open('step_1_2_worksheets.csv', 'w', newline='') as csvfile:
    fieldnames = ['Command', 'Code', 'Flags', 'AVP', 'Bracket', 'Multiple']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()
    for row in worksheets:
        writer.writerow(row)

print("Generated step_1_2_worksheets.csv with", len(worksheets), "AVPs mapped across 6 commands.")
