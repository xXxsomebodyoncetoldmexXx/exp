# def tranf(s, flag, t, mid):
# 	s = int(str(s) + str(s)[:mid + flag:][::-1])
# 	# print(s)
# 	if(s <= t):
# 		return False
# 	return True

# n = int(input())
# for _ in range(n):
# 	s = input()
# 	fi = ""
# 	k = len(s)//2
# 	flg = (len(s)%2 == 0)
# 	if flg:
# 		fi = s[:len(s)//2]
# 	else:
# 		fi = s[:k+1]
# 	s = int(s)
# 	fi = int(fi)
# 	while not tranf(fi, flg, s, k):
# 		fi+=1
# 	fi = str(fi)
# 	print(fi + fi[:k + flg:][::-1])

n = int(input())
n +=1
while(str(n) != str(n)[::-1]):
	n +=1
print(n)
