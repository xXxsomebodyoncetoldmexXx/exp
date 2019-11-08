n = int(input())
for _ in range(n):
	a, b = input().split(" ")
	a = a[::-1]
	b = b[::-1]
	ans = int(str(int(a) + int(b))[::-1])
	print(ans)
