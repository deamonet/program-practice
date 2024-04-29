#coding: utf-8
import sys


def amountOfCombination(nums, target):
    global amount
    amount = 0
    used = [False for i in nums]
    depth = 0
    for i, num in enumerate(nums):
        used[i] = True
        dfs(used, target - num, depth + 1, nums)

    
    print(amount)


def dfs(used, remaining, depth, nums):
    print(remaining)
    global amount
    if remaining == 0:
        amount += 1
        return
    elif depth == 4:
        return
    else:
        for i, num in enumerate(nums):
            if used[i]:
                continue
            else:
                used[i] = True
                dfs(used, remaining - num, depth + 1, nums)


def main():
    nums = 2,2,2,2,2
    target = 10
    amountOfCombination(nums, target)
  
if __name__=='__main__':
   main()