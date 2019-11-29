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
    x = 1
    ys = 1
    ye = 1000000000000000000
    y = 1
    lastpossible = -1
    while(ys<=ye):
      y = (ys+ye)//2
      target = Decimal(y)/Decimal(x)
      if (target > r[0] and target<r[1]):
        lastpossible = y
      if(target <= r[0]):
        ys = y+1
      else:
        ye = y-1
    for yy in range(y-100,y+100):
      if yy>0:
        target = Decimal(yy)/Decimal(x)
        if (target > r[0] and target<r[1]):
          if ans=="NOSOL": ans = str(x)+" "+str(yy)
        else:
          x = 1
          xs = 1
          xe = 1000000000000000000
          y = 1
          lastpossible = -1
          while(xs<=xe):
            x = (xs+xe)//2
            target = Decimal(y)/Decimal(x)
            #print(x)
            if (target > r[0] and target<r[1]):
              lastpossible = x
            if(target <= r[0]):
              xs = x+1
            else:
              xe = x-1
          for xx in range(x-100,x+100):
            if xx>0:
              target = Decimal(y)/Decimal(xx)
              if (target > r[0] and target<r[1]):
                if ans=="NOSOL": ans = str(xx)+" "+str(y)

  else:
    if ans=="NOSOL": ans = "IMPOSSIBLE"
  print("Case #"+str(_)+": "+str(ans))