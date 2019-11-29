from decimal import *

import itertools

t = int(input().strip())
for _ in range(1,t+1):
  n = int(input().strip())
  data = []
  for i in range(n):
    data.append(tuple(map(int,input().strip().split())))
  #bf = list(itertools.permutations(data))
  def check(row):
    s = Decimal(1)/Decimal(1e20)
    e = Decimal(1e20)
    for i in range(1,len(row)):
      a,b = row[i-1]
      c,d = row[i]
      if b-d != 0:
        x = Decimal(a-c)/Decimal(d-b)
        if a==c:
          if b>=d: return False
        else:
          if (d-b > 0):
            s = max(s,x)
          else:
            e = min(e,x)
      else:
        if (a>=c): return False
    if (s<e): return (s,e)
    return False
  ans = "NOSOL"
  #for row in bf:
  r = check(data)
  if r != False:
    #print(r)
    for x in range(1,200):
      for y in range(1,200):
        target = Decimal(y)/Decimal(x)
        if (target > r[0] and target<r[1]):
          if ans == "NOSOL":
            ans = str(x)+" "+str(y)

  else:
    ans = "IMPOSSIBLE"
  print("Case #"+str(_)+": "+str(ans))