from string import printable
from more_itertools import roundrobin
import concurrent.futures

INFILE = "audio.rpa"
OUTFILE = "aud.txt"

with open(INFILE, "rb") as f:
  content = f.read().decode("latin-1")

content = content.split("\n")

def work(arg):
  start, step = arg
  print("Starting process", start)
  nw_content = list()
  for line in content[start::step]:
    chk = 0
    for ch in printable:
      chk += line.count(ch)
    if chk > len(line)/2 and len(line) > 1:
      nw_content.append(line + "\n")
    else:
      nw_content.append("")
  return nw_content

def main():

  worker = 8
  rg = [(sa, worker) for sa in range(worker)]
  tmp = list()

  with concurrent.futures.ProcessPoolExecutor(max_workers=worker) as exe:
    for nw in exe.map(work, rg):
      tmp.append(nw)

  # print(content[:8])
  # print("--")
  # for thg in tmp:
  #   print(thg[0])

  final = list(roundrobin(*tmp))


  with open(OUTFILE, "w") as f:
    f.writelines(final)

if __name__ == '__main__':
  main()
