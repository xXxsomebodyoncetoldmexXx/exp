import requests
from pprint import pprint

raw = '''
POST /youtubei/v1/log_event?alt=json&key=AIzaSyAO_FJ2SlqU8Q4STEHLGCilw_Y9_11qcW8 HTTP/2
Host: www.youtube.com
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:79.0) Gecko/20100101 Firefox/79.0
Accept: */*
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate, br
Referer: https://www.youtube.com/watch?v=TG-RGt7Q1oI&list=RDMMOZT7RzD8FpA&index=17
Content-Type: application/json
X-Goog-Visitor-Id: CgtpcG5USUp0US00cyii1-T5BQ%3D%3D
Authorization: SAPISIDHASH 1597582400_576f1d4c03c3a851992f29486b348b58c75189e3
X-Goog-AuthUser: 0
x-origin: https://www.youtube.com
X-YouTube-Client-Name: 1
X-YouTube-Client-Version: 2.20200814.00.00
X-YouTube-Device: cbr=Firefox&cbrver=79.0&ceng=Gecko&cengver=79.0&cos=Windows&cosver=10.0
X-Youtube-Identity-Token: QUFFLUhqbE45aG5BN2tUNXk2YkZ3VjBaZzFsQ1R5UThld3w=
X-YouTube-Page-CL: 326505813
X-YouTube-Page-Label: youtube.ytfe.desktop_20200813_0_RC0
X-YouTube-Variants-Checksum: b8b4158b341701c7e3acc37d2407298c
X-YouTube-Utc-Offset: 420
X-YouTube-Time-Zone: Asia/Bangkok
X-YouTube-Ad-Signals: dt=1597581686111&flash=0&frm&u_tz=420&u_his=17&u_java&u_h=1440&u_w=2560&u_ah=1440&u_aw=2560&u_cd=24&u_nplug&u_nmime&bc=31&bih=1365&biw=2543&brdim=-8%2C-8%2C-8%2C-8%2C2560%2C0%2C2576%2C1456%2C2560%2C1365&vis=1&wgl=true&ca_type=image
Content-Length: 4806
Origin: https://www.youtube.com
Connection: keep-alive
Cookie: VISITOR_INFO1_LIVE=ipnTIJtQ-4s; SID=zQcJNlxNkKczE41pXn9Z4pPD5lZxemKVADsdyhjWQAxx6uAuuCKWxWSqMufkhLO5zwgP3A.; __Secure-3PSID=zQcJNlxNkKczE41pXn9Z4pPD5lZxemKVADsdyhjWQAxx6uAuOT1KyNspkcws6KGW8aMqlQ.; HSID=Ake7i8mIsIPBG1W5f; SSID=ANQs-Ocp6dETc5za_; APISID=SNc2wTX2p2s73drj/AkDWvOJoyXqB6_F1b; SAPISID=g1wuNZ1wjkz6pPuq/AdaTjMIwNig_kpmyc; __Secure-3PAPISID=g1wuNZ1wjkz6pPuq/AdaTjMIwNig_kpmyc; CONSENT=YES+VN.vi+20180304-09-0; LOGIN_INFO=AFmmF2swRgIhAPxtwj53fLQTB2Q6ZwafZS4CvjHxUFHdhWpR8lGKg0F3AiEAz9Q4WK_HIJVOehknGmYNMmhiy4VA6h8iJnTt8ZsiVOg:QUQ3MjNmeHB6Qlhzc1MteWd2VVRqZGN6TzNXXzlKRFhmcDNHWmVMUk81dzFhR1BKNU80aHJWTXM3ZjAxRmhkRGtjWUJQWmY4WERVN2JfWW04cDlORm5zVVEtSGlhMWYtM1VFZXpwRHRTWGlqYTdiRW8yTkFvLU9TTnI3QkRZUnItQXhvUzNnclpETFNKSXRUU1B6N1NPcXlKNTQzYkdjNkwzYmRYMnEtVlIwSmtvcE9uNnpHa3dV; SIDCC=AJi4QfFoIMZ5GGH2HKGBma_QGd9D58By2KJfLXWZQOgczATyQNEpPW56-w21hf-_rVW40S8zHKOq; PREF=al=vi&f6=400&f5=30030&hl=en; YSC=IbdXicH7GCY
TE: Trailers'''


class mks(requests.Session):
	def __init__(self, rawHeader=None):
		requests.Session.__init__(self)
		if rawHeader:
			self.h, self.c = self.upHC(rawHeader)
		else:
			self.h, self.c = (dict(), dict())
		self.headers.update(self.h)
		self.cookies.update(self.c)

	def upHC(self, s):
		headers = dict()
		cookie = dict()
		for line in s.strip().split("\n"):
			try:
				tp, cont = line.split(": ")
			except ValueError:
				# Ignore GET HEAD POST PUT DELETE CONNECT OPTIONS TRACE PATCH
				continue
			if tp not in ("Content-Length", None):
				if tp == "Cookie":
					cookie = self.upC(cont)
				else:
					if cont.isdecimal():
						cont = int(cont)
					headers[tp] = cont
		if not self.h or self.c:
			self.h, self.c = headers, cookie
		return (headers, cookie)

	def upC(self, s):
		cookie = dict()
		for line in s.split("; "):
			tp, cont = line.split("=", 1)
			if cont.isdecimal():
				cont = int(cont)
			elif cont.lower() in ("true", "false"):
				cont = (True, False)[cont.lower() == "false"]
			cookie[tp] = cont
		return cookie

	def bf(self):
		print("HEADERS".center(80, "-"))
		pprint(self.h)
		print()
		print("COOKIES".center(80, "-"))
		pprint(self.c)


def main():
	obj = mks(raw)
	obj.bf()
	

if __name__ == '__main__':
	main()
