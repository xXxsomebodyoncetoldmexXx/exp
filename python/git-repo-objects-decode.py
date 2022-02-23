import requests
from zlib import decompress
from bs4 import BeautifulSoup as bs4

s = requests.Session()

URL = "<.git URL>"


def decode_object(data):
    return decompress(data)


def walk_repo(path):
    resp = s.get(path)
    soup = bs4(resp.text, "lxml")
    for link in soup.find_all("a"):
        link = link.get("href")
        if not link.startswith(".."):
            child = path + link
            if link.endswith("/"):
                walk_repo(child)
            elif len(link) == 38:  # hash
                print(child)
                data = s.get(child).content
                content = decode_object(data)
                try:
                    print(content.decode())
                except UnicodeDecodeError:
                    print("Binary file")
                print("=" * 100, end="\n\n\n")


walk_repo(URL)
