
# VEDICT : TL

n = int(input())

t = dict()

def binS(a, b):
  val = a*b
  st = 1
  ed = min(a, b)
  mid = val//3
  check = val//3
  while(st <= ed):
    mid = (st+ed)//2
    check = mid**3
    if check == val:
      break
    elif check > val:
      ed = mid-1
    else:
      st = mid+1
  if (check == val) and (a%mid == 0) and (b%mid == 0):
    return "Yes"
  return "No"

for _ in range(n):
  a, b = list(map(int, input().split(" ")))
  # if t[(a, b)] == "":
  if (a, b) not in t:
    t[(a, b)] = binS(a, b)
    t[(b, a)] = t[(a, b)]
  print(t[(a, b)])
