n = int(input())
for _ in range(n):
	input()
	child = int(input())
	total = 0
	for _ in range(child):
		total += int(input())
	if total%child == 0:
		print("YES")
	else:
		print("NO")
