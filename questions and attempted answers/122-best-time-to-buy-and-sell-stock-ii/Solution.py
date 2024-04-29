from typing import List
#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 只要今天的价格比昨天高就卖出，同时昨天也要买入
        
        i = 0
        ret = 0
        for i in range(len(prices)-1):
            if prices[i] < prices[i+1]:
                ret += prices[i+1] - prices[i]

        return ret
# @lc code=end

if __name__ == "__main__":
    prices = [1]
    s = Solution()
    ret = s.maxProfit(prices=prices)
    print(ret)