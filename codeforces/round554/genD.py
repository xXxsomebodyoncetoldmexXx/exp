from itertools import permutations
from collections import Counter as C

def check(s):
  stack = []
  for i in s:
    if i == ']':
      if len(stack) == 0:
        return False
      stack.pop()
    else:
      stack.append("[")
  if len(stack) != 0:
    return False
  return True


# n = int(input("n: "))
n = 1000
pool = "[]"*n
ans = C()
for s in permutations(pool):
  s = ''.join(s)
  if check(s) and s not in ans:
    ans.update({s})

print(len(ans))
# for key, num in ans.items():
#   print(key)
# print(ans)
