#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#
from typing import List
# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        cnt = 0
        while left <= right and cnt < 10:
            mid = left + (right - left) // 2
            print(f"left {left}\tright {right} mid\t{mid}")
            cnt += 1
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                return mid
            
        return left
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    nums = [-40, -30, -20, -10, 0, 10, 20, 30]
    tar = 10
    ret = s.searchInsert(nums, tar)
    print(ret)