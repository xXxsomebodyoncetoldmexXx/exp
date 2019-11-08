ar = [1]
for i in range(1, 101):
	ar.append(ar[-1]*i)


n = int(input())
for _ in range(n):
	k = int(input())
	print(ar[k])
