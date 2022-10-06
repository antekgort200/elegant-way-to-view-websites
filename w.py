import requests
from bs4 import BeautifulSoup

r = requests.get(input(">>> "))
print(r)
soup = BeautifulSoup(r.content, "html.parser")
x = soup.prettify()
for i in x.splitlines():
    if "<" in i:
        pass
    else:
        print(i)
