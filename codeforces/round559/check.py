def check(s):
	# length
	k = dict()
	for i in range(len(s)):
		for j in range(i+1,len(s)+1):
			if s[i:j] not in k:
				k.update({s[i:j]: 1})
			else:
				k[s[i:j]] += 1
	ans = len(s)
	for key, val in k.items():
		if(val == 1):
			ans = min(ans, len(key))
	return ans


def brute(n):
	tmp = 'f"{i:0' + str(n) + 'b}"'
	for i in range((1<<n)):
		ans = check(eval(tmp))
		if(ans%2 == n%2):
			print(eval(tmp), ans)
