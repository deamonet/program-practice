#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        elif x == 0:
            return True
        else:
            ls = []
            while x != 0:
                a = x % 10
                x = x // 10
                ls.append(a)
            
            for i in range(len(ls) // 2):
                if ls[i] != ls[-i-1]:
                    return False

            return True
            
# @lc code=end


# 更好的比较做法：每一步筛选出个位数，然后乘10，变成高位，进而组装成反过来完整的数。


