#
# @lc app=leetcode.cn id=956 lang=python3
#
# [956] 最高的广告牌
#
from typing import Optional, List
# @lc code=start
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        dp = {0: 0}
        for length in rods:
            dp1 = dp.copy()
            for diff in list(dp1.keys()):
                # 这里的 length 加在上面还是下面都是一样的。
                dp[diff + length] = max(dp.get(diff + length, 0), dp1[diff] + length)
                dp[diff - length] = max(dp.get(diff - length, 0), dp1[diff])

        return dp[0]

    
    def tallestBillboard2(self, rods):
        dp = {0: 0}
        for x in rods:
            # 这里实际运行会报错，提示字典不能在迭代过程中被修改。
            # 代码源自英文leetcode投票数最高的评论。
            for d, y in dp.items():
                dp[d + x] = max(dp.get(x + d, 0), y)
                dp[abs(d - x)] = max(dp.get(abs(d - x), 0), y + min(d, x))
        return dp[0]


    def tallestBillboard3(self, rods):
        dp = {0: 0}
        for i in rods:
            for k, b in list(dp.items()):
                dp[k + i] = max(dp.get(k + i, 0), b + i)
                dp[k - i] = max(dp.get(k - i, 0), b)
        return dp[0]
# @lc code=end
if __name__ == "__main__":
    rods = [1, 2, 3, 6]
    s = Solution()
    l = s.tallestBillboard3(rods)
    print(l)