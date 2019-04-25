import sys

mod = [11,10,13,14,15,17,18]
comp = []
for x in range(1000005):
  comp.append((
    x%mod[0],
    x%mod[1],
    x%mod[2],
    x%mod[3],
    x%mod[4],
    x%mod[5],
    x%mod[6],
  ))

t, n, g = map(int,input().strip().split())

#print("dasdasdasd")

for _ in range(1,t+1):

  modres = [-1,-1,-1,-1,-1,-1,-1]

  curri = 0
  for m in mod:
    print(" ".join([str(m)]*18))
    x = map(int,input().strip().split())
    modres[curri] = sum(x)%m
    sys.stdout.flush()
    curri += 1

  modres = tuple(modres)

  for i in range(1,len(comp)):
    if (modres == comp[i]):
      print(i)
      sys.stdout.flush()
      verdict = int(input())
      if (verdict == -1): exit()
      break