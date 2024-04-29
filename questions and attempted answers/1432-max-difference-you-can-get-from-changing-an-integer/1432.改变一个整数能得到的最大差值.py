#
# @lc app=leetcode.cn id=1432 lang=python3
#
# [1432] 改变一个整数能得到的最大差值
#

# @lc code=start
from xmlrpc.client import Boolean


class Solution:
    def maxDiff(self, num: int) -> int:
        num_str = str(num)
        return eval(self.maxAfter(num_str)) - eval(self.minAfter(num_str, True))

    def maxAfter(self, num: str):
        if num[0] != '9':
            num = num.replace(num[0], '9')
            return num
        elif len(num) == 1:
            return num
        else:
            return '9' + self.maxAfter(num[1:])

    def minAfter(self, num: str, first: Boolean):
        if num[0] != '1' and num[0] != '0':
            if first:
                num = num.replace(num[0], '1')
            else:
                num = num.replace(num[0], '0')
            
        elif len(num) == 1:
            pass
        else:
            return num[0] + self.minAfter(num[1:], False)

        return num
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    num = '1101011'
    print(s.minAfter(num, True))