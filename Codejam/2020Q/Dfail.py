import sys

t, b = map(int, input().strip().split())

def Reverse(s):
  return s[::-1]

def BitFlip(s):
  return ''.join(str(1 - int(c)) for c in s)

while t > 0:
  rep = []

  ress = ""
  rese = ""

  pos = 1
  ite = 1

  pos01 = []
  pos10 = []
  
  is_reverse = False
  is_inverse = False

  while pos <= b//2:
    if ite%10 == 1 and ite > 1:
      is_reverse = False
      is_inverse = False

      repused = [1,2,b-1,b]
      if len(rep) > 0: repused = rep
      real = ress[repused[0]-1] + ress[repused[1]-1] + rese[b-repused[-2]] + rese[b-repused[-1]]
      curr = ""
      for r in repused:
        print(r, flush=True)
        curr += input()

      print('curr', curr, file=sys.stderr)
      print('real', real, file=sys.stderr)

      if Reverse(curr) == real: is_reverse = True
      if BitFlip(curr) == real: is_inverse = True

    print(pos, flush=True)
    xs = int(input())
    if is_inverse: xs = 1-xs
    if is_reverse:
      rese += str(xs)
    else:
      ress += str(xs)

    print(b-pos+1, flush=True)
    xe = int(input())
    if is_inverse: xe = 1-xe
    if is_reverse:
      ress += str(xe)
    else:
      rese += str(xe)

    
    if len(rep) == 0:
      if xs == 0 and xe == 1:
        pos01.append(pos)
      elif xs == 1 and xe == 0:
        pos10.append(pos)

      if len(pos01) >= 1 and len(pos10) >= 1:
        rep.append(min(pos01[0], pos10[0]))
        rep.append(max(pos01[0], pos10[0]))

        rep.append(min(b-pos01[0]+1, b-pos10[0]+1))
        rep.append(max(b-pos01[0]+1, b-pos10[0]+1))
    

    pos += 1

    ite+=2

  res = ress + rese[::-1]

  if is_reverse: res = Reverse(res)
  if is_inverse: res = BitFlip(res)

  print(res)
  ok = input()
  if ok == 'N': exit()

  t-=1