#
# @lc app=leetcode.cn id=695 lang=python3
#
# [695] 岛屿的最大面积
#
# https://leetcode-cn.com/problems/max-area-of-island/description/
#
# algorithms
# Medium (67.38%)
# Likes:    750
# Dislikes: 0
# Total Accepted:    190.5K
# Total Submissions: 282.8K
# Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
#
# 给你一个大小为 m x n 的二进制矩阵 grid 。
# 
# 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid
# 的四个边缘都被 0（代表水）包围着。
# 
# 岛屿的面积是岛上值为 1 的单元格的数目。
# 
# 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：grid =
# [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
# 输出：6
# 解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
# 
# 
# 示例 2：
# 
# 
# 输入：grid = [[0,0,0,0,0,0,0,0]]
# 输出：0
# 
# 
# 
# 
# 提示：
# 
# 
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 50
# grid[i][j] 为 0 或 1
# 
# 
#
from typing import List
# @lc code=start
from queue import Queue
class Solution:
    def __init__(self) -> None:
        self.directions = [1, -1]
        self.grid = [[]]

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        maxArea = 0
        workque = Queue()
        for starter_r, starter_c in self.find_new_start_point():
            workque.put((starter_r, starter_c))
            area = 0
            while not workque.empty():
                r, c = workque.get()
                if self.grid[r][c] == 1:
                    area += 1
                    self.grid[r][c] = 0
                else:
                    continue

                for direct in self.directions:
                    if r + direct >= 0 and r + direct < len(grid):
                        workque.put((r+direct, c))
                    if c + direct >= 0 and c + direct < len(grid[0]):
                        workque.put((r, c+direct))

            if area > maxArea:
                maxArea = area
        
        return maxArea

    def find_new_start_point(self):
        for i in range(len(self.grid)):
            for j in range(len(self.grid[0])):
                if self.grid[i][j] == 1:
                    yield i, j
# @lc code=end

if __name__ == "__main__":
    grid = [
        [0,0,1,0,0,0,0,1,0,0,0,0,0],
        [0,0,0,0,0,0,0,1,1,1,0,0,0],
        [0,1,1,0,1,0,0,0,0,0,0,0,0],
        [0,1,0,0,1,1,0,0,1,0,1,0,0],
        [0,1,0,0,1,1,0,0,1,1,1,0,0],
        [0,0,0,0,0,0,0,0,0,0,1,0,0],
        [0,0,0,0,0,0,0,1,1,1,0,0,0],
        [0,0,0,0,0,0,0,1,1,0,0,0,0]
        ]
    grid = [
        [0,0,0,0,0,0,0,1,1,1,0,0,0]
        ]

    grid = [[1]]
    grid = [[1, 0]]
    s = Solution()
    ret = s.maxAreaOfIsland(grid)
    print(ret)
