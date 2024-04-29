#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#
from fileinput import close
from typing import List
# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort()
        closest = 1000
        for i in range(n-2):
            L = i + 1
            R = n - 1
            approach = nums[i] + nums[L] + nums[R]
            if approach - target > 0:
                R -= 1
            else:
                L += 1

            if abs(approach - target) < closest:
                closest = abs(approach - target)
                closest_approach = approachx

        return closest_approach
# @lc code=end

if __name__ == "__main__":
    nums = [-1,2,1,-4]
    target = 1
    s = Solution()
    ret = s.threeSumClosest(nums, target)
    print(ret)