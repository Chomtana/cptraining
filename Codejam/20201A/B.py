t = int(input())
for _ in range(1,t+1):
  n = int(input())
  print("Case #%d:" % (_))
  print("1 1")
  n -= 1

  curr = 1
  while True:
    n -= curr
    if n >= 0:
      print("%d %d" % (curr+1, curr))
      curr += 1
    else:
      n += curr
      break

  # at (curr, curr-1)
  for i in range(n):
    print("%d %d" % (curr, curr))
    curr -= 1