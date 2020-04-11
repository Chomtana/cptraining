import sys

t, b = map(int, input().strip().split())

def Reverse(s):
  return s[::-1]

def BitFlip(s):
  return ''.join(str(1 - int(c)) for c in s)

while t > 0:
  def perform(b):
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

  full = perform(10)

  if b==20:
    repaircount = 0
    while len(full) < 20 and repaircount<110:
      s = perform(10)
      if full != s and full[::-1] != s and BitFlip(full) != s and BitFlip(Reverse(full)) != s:
        full += s
      if repaircount >= 100:
        full += s
        break
      repaircount += 10

    checkpos = [1,2,3,4,5,16,17,18,19,20]
    checksum = []

    for i in checkpos:
      print(i, flush=True)
      checksum.append(input())

    #print(checksum, file=sys.stderr)

    def check(s):
      for i in range(10):
        if s[checkpos[i]-1] != checksum[i]:
          return False
      return True

    def final():
      ans = []

      for i in range(4):
        for j in range(4):
          s = full

          first_part = s[0:10]
          second_part = s[10:]

          if i == 1: first_part = first_part[::-1]
          if i == 2: first_part = BitFlip(first_part)
          if i == 3: first_part = BitFlip(Reverse(first_part))

          if j == 1: second_part = second_part[::-1]
          if j == 2: second_part = BitFlip(second_part)
          if j == 3: second_part = BitFlip(Reverse(second_part))

          #print(full, file=sys.stderr)

          if check(first_part+second_part):
            ans.append(first_part+second_part)
          elif check(second_part+first_part):
            ans.append(second_part+first_part)
      if len(ans) == 0: print('No sol', file=sys.stderr)
      return ans

    ans = final()

    if len(ans) == 1: print(ans[0])
    else:
      checkpos = [6,7,8,9,10,11,12,13,14,15]
      checksum = []

      for i in checkpos:
        print(i, flush=True)
        checksum.append(input())

      def check2(s):
        for i in range(10):
          if s[checkpos[i]-1] != checksum[i]:
            return False
        return True

      def final2():
        ans = []

        for i in range(4):
          for j in range(4):
            s = full

            first_part = s[0:10]
            second_part = s[10:]

            if i == 1: first_part = first_part[::-1]
            if i == 2: first_part = BitFlip(first_part)
            if i == 3: first_part = BitFlip(Reverse(first_part))

            if j == 1: second_part = second_part[::-1]
            if j == 2: second_part = BitFlip(second_part)
            if j == 3: second_part = BitFlip(Reverse(second_part))

            #print(first_part, second_part, file=sys.stderr)

            if check2(first_part+second_part):
              ans.append(first_part+second_part)
            elif check2(second_part+first_part):
              ans.append(second_part+first_part)
        if len(ans) == 0: print('No sol 2', file=sys.stderr)
        return ans

      ans = final2()
      if len(ans) == 1: print(ans[0])
      else:
        checkpos = [2,4,6,8,10,11,13,15,17,19]
        checksum = []

        for i in checkpos:
          print(i, flush=True)
          checksum.append(input())

        def check3(s):
          for i in range(10):
            if s[checkpos[i]-1] != checksum[i]:
              return False
          return True

        def final3():
          ans = []

          for i in range(4):
            for j in range(4):
              s = full

              first_part = s[0:10]
              second_part = s[10:]

              if i == 1: first_part = first_part[::-1]
              if i == 2: first_part = BitFlip(first_part)
              if i == 3: first_part = BitFlip(Reverse(first_part))

              if j == 1: second_part = second_part[::-1]
              if j == 2: second_part = BitFlip(second_part)
              if j == 3: second_part = BitFlip(Reverse(second_part))

              #print(first_part, second_part, file=sys.stderr)

              if check3(first_part+second_part):
                ans.append(first_part+second_part)
              elif check3(second_part+first_part):
                ans.append(second_part+first_part)
          if len(ans) == 0: print('No sol 2', file=sys.stderr)
          return ans

        ans = final3()

        if len(ans) > 0: print(ans[0])
        else: print(full)
  else:
    print(full)

  ok = input()
  if ok == 'N': exit()

  t-=1