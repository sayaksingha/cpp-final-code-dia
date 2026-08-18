import requests
import PyPDF2
import io

url = "https://www.etsi.org/deliver/etsi_ts/129200_129299/129212/19.01.00_60/ts_129212v190100p.pdf"
response = requests.get(url)
pdf_file = io.BytesIO(response.content)

reader = PyPDF2.PdfReader(pdf_file)
full_text = []
for page in reader.pages:
    text = page.extract_text()
    if text:
        full_text.append(text)

with open("ts_129_212_text.txt", "w", encoding="utf-8") as f:
    f.write("\n".join(full_text))

print("Dumped to ts_129_212_text.txt")
