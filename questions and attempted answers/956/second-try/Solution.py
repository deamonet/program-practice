# 动态规划

# 定义dp[diff]是当前高度差为diff的最高高度（短边的长度或者长边的长边）
# 增加左边的杆子，高度差 + ，增加右边的杆子，高度差 - 。
# 在这种定义下，dp[diff]是 所有增加左边杆子的长度。 + 的总和。
# 新增加一个杆子，有三种可能：+ 或者 - 或者丢弃。
# 当前 dp[a] = n, rod b

# dp[a+b] = max(dp[a] + b, dp[a+b]) 
# dp[a-b] = max(dp[a], dp[a-b])

# 因为 dp[a] 可能并不是第一次出现，所以需要与上一次的自己比较。

#
# @lc app=leetcode.cn id=956 lang=python3
#
# [956] 最高的广告牌
#
from typing import List
# @lc code=start
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        dp = dict()
        dp[0] = 0
        for rod in rods:
            for diff in list(dp.keys()):
                dp[diff + rod] = max(dp[diff] + rod, dp.get(diff + rod, 0))
                dp[diff - rod] = max(dp[diff], dp.get(diff - rod, 0))
        
        return dp[0]
# @lc code=end

if __name__ == "__main__":
    rods = [1, 1]
    s = Solution()
    ret = s.tallestBillboard(rods)
    print(ret)