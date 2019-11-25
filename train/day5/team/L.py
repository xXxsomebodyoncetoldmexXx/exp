k = int(input())
s = list(input())
ans = 0
while(int(''.join(s), 2) > k):
  try:
    idx = s[1:].index('1')+1
    del s[idx]
  except:
    s = s[:-1]
  # print(s)
  ans += 1
print(ans)
