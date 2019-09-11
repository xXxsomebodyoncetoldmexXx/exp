import string
import sys
import random
import argparse

pool = string.ascii_lowercase

def de(s):
	global pool
	r = 0
	l = len(pool)-1
	for c in s[::-1]:
		r += (pool.index(c)+1) + r*l
	return r

def en(n):
	global pool
	r = ""
	l = len(pool)
	while(n > 0):
		flag = False
		r += pool[(n%l)-1]
		flag = ((n%l) == 0)
		# print((n%l)-1, n)
		n = n // l - flag
	return r

def test(n):
	global pool
	for l in range(n):
		source = ''.join(random.SystemRandom().choices(pool, k=random.randrange(10000)))
		flag = (source == en(de(source)))
		print("{}...{:>5d}".format(source[0:20], len(source)), flag)
		if not flag:
			print("Wrong answer")
			print(source)
			print(en(de(source)))
			sys.exit(1)

def main():
	parser = argparse.ArgumentParser(description="A tool to convert character string to number for easier binary search")

	parser.add_argument("input", nargs="?", help="Value to encode or decode")

	parser.add_argument("-e", "--encode", dest="encode", action="store_true", help="Change to encode the number")

	parser.add_argument("-c", "--case-sensitive", dest="case_sensitive", action="store_true", help="'a' and 'A' are two diffirent value")

	parser.add_argument("-n", "--number", dest="number", action="store_true", help="include number")

	parser.add_argument("-t", "--test",dest="num", help="Test the program with <NUM> times", type=int)

	parser.set_defaults(encode=False)
	parser.set_defaults(case_sensitive=False)
	parser.set_defaults(number=False)
	args = parser.parse_args()

	global pool

	if len(sys.argv) < 2:
		parser.print_help()
		sys.exit(1)

	if args.case_sensitive:
		pool += string.ascii_uppercase
	if args.number:
		pool = string.digits + pool

	if args.num:
		test(args.num)
		sys.exit(0)

	if not args.input:
		print("Require input value!")
		parser.print_help()
		sys.exit(1)

	if args.encode:
		print(en(int(args.input)))
	else:
		print(de(args.input))

if __name__ == '__main__':
	main()