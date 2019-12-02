def f(x):
  if x < 10:
    return x
  ans = 9 + (x//10)
  if int(str(x)[0]) > int(str(x)[-1]):
    ans -= 1
  return ans

l, r = list(map(int, input().split(" ")))

print(f(r) - f(l-1))
