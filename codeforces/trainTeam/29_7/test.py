def check(s):
  s = str(s)
  ans = 0
  for i in range(len(s)-1):
    for j in s[i+1:]:
      ans += int(s[i]) * int(j)
  return ans

n = int(input())
for _ in range(n):
  l = int(input())
  r = int(input())
  m = int(input())
  x = 0
  for i in range(l, r+1):
    print(f"{i:02d}: {i%m:02d}, {check(i)%m:02d}")
    if((i%m) == (check(i)%m)):
      x+=1
  print(x)
