a, b = list(map(int, input().split(" ")))
if a == b:
  print(1)
  exit(0)
diff = b - a

beginB = b - diff + 1

ans = beginB
last = beginB
for i in range(beginB+1, b+1):
  ans *= i
  if last%10 == ans%10:
    break
  last = ans

print(ans%10)
