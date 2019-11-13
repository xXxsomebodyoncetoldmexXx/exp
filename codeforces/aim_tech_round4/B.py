r, c = list(map(int, input().split(" ")))
matrix = []
for _ in range(r):
	matrix.append(list(map(int, input().split(" "))))

ans = 0
for i in range(r):
	zero = 0
	one = 0
	for j in range(c):
		if(matrix[i][j]):
			one += 1
		else:
			zero +=1
	ans += pow(2, one) - 1
	ans += pow(2, zero) -1

for i in range(c):
	zero = 0
	one  = 0
	for j in range(r):
		if(matrix[j][i]):
			one += 1
		else:
			zero += 1
	ans += pow(2, one) - 1
	ans += pow(2, zero) - 1
ans -= r*c
print(ans)
