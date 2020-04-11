import sys

t, b = map(int, input().strip().split())

def Reverse(s):
  return s[::-1]

def BitFlip(s):
  return ''.join(str(1 - int(c)) for c in s)

while t > 0:
  def perform():
    res = ""

    pos = 1
    ite = 1

    while pos <= b:
      if False:
        print(1, flush=True)
        input()
      else:
        print(pos, flush=True)
        x = int(input())
        #print(ite, pos, x, file=sys.stderr)
        res += str(x)
        pos+=1
      ite+=1

    return res

  print(perform())
  ok = input()
  if ok == 'N': exit()

  t-=1