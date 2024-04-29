#
# @lc app=leetcode.cn id=778 lang=python3
#
# [778] 水位上升的泳池中游泳
#

# @lc code=start
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        dp_grid = grid.copy()
        for level in dp_grid:
            for dp in dp_grid:
                dp = 0

        dp[0][0] = grid[0][0]
        dp[1][0] = max(grid[1][0], dp[0][0])
        dp[0][1] = max(grid[0][1], dp[0][0])
        
# @lc code=end