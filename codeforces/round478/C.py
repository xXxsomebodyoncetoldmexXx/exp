def lb(arr, val):
	le = 0
	ri = len(arr)
	while le < ri:
		mid = (le+ri)//2
		if arr[mid] >= val:
			ri = mid
		else:
			le = mid+1
	return le

n, q = map(int, input().split(" "))
war = list(map(int, input().split(" ")))
arr = list(map(int, input().split(" ")))
pre = [war[0]]
for i in range(1, len(war)):
	pre.append(pre[i-1]+war[i])
totalHeal = pre[-1]
curArrw = 0
for i in range(q):
	curArrw += arr[i]
	if curArrw >= totalHeal:
		print(n)
		curArrw = 0
	else:
		idx = lb(pre, curArrw)
		if (pre[idx]-curArrw > 0):
			idx-=1
		idx += 1
		print(n - idx)
