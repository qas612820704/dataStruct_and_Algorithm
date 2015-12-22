#!/usr/bin/python3

# 問題 :
#   一個集合 S 擁有 n(ie. SIZE) 個數字
#   而這 n 個數字介於 1 ~ m(ie. MAX_INT) 之間
#   給定一個 sum
#   找可否存在一個 S 的子集合, 其中的元素相加後為 m
#   試在 O(mn) 的時間內
# 


# 設定 :
MAX_INT = 20
SIZE = 5

import random
ary = [random.randint(1,MAX_INT) for _ in range(0,SIZE)]

SUM = sum(ary)


def canSum(ary, sumation):
  # aryCanSum = [
  #   [i==0 or i in ary for i in range(0,sumation+1)]*len(ary) +1
  # ]
  m = sumation
  n = len(ary)
  can = [[[] for _ in range(0,m+1)] for _ in range(0,n+1)]
  can[0][0] = [0]
  for i in range(1,n+1):
    print('i =',i)
    can[i][0] = [0]
    for k in range(1,m+1):
      print('\tk =',k)
      if can[i-1][k]:
        can[i][k] = can[i-1][k].copy()
      else:
        take = ary[i-1]
        index = k - take
        if index >= 0:
          if can[i-1][index]:
            can[i][k] = can[i-1][index].copy()
            can[i][k].append(take)
        #   else:
        #     can[i][k] = False
        # else:
        #   can[i][k] = False
      print('\t\t', can[i])
  if can[n][m]:
    can[n][m].remove(0)
    return can[n][m]
  return can[n][m]
def main():
  print(canSum(ary, SUM))

if '__main__' == __name__:
  main()
