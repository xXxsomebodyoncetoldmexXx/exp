import string
import sys
import random

def de(s):
	r = 0
	l = len(string.ascii_uppercase)-1
	for c in s[::-1]:
		r += ((ord(c))&0x1f) + r*l
	return r

def en(n):
	r = ""
	l = len(string.ascii_uppercase)
	while(n > 0):
		flag = False
		r += string.ascii_lowercase[(n%l)-1]
		flag = ((n%l) == 0)
		# print((n%l)-1, n)
		n = n // l - flag
	return r

def main():
	if len(sys.argv) < 2 or len(sys.argv) > 3:
		print("[USAGE]: python3 base26Conv.py [-e] S")
		exit()
	if len(sys.argv) == 2:
		print(de(sys.argv[1]))
	elif sys.argv[1] == "-e":
		print(en(int(sys.argv[2])))
	elif sys.argv[1] == "--test":
		for loop in range(int(sys.argv[2])):
			source = ''.join(random.SystemRandom().choices(string.ascii_lowercase, k=random.randrange(10000)))
			flag = (source == en(de(source)))
			print("{}...{:>5d}".format(source[0:20], len(source)), flag)
			if not flag:
				print("Wrong answer")
				print(source)
				print(en(de(source)))

	else:
		print("Unknow options")

if __name__ == '__main__':
	main()