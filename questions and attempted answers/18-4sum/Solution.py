from typing import List
#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        print(f"four sum {nums}")
        ret = []
        if len(nums) < 4:
            return []
        else:
            for i in range(len(nums)-3):
                print(nums[i])
                new = self.threeSum(nums[i], nums[i+1:], target)
                ret.extend(new)

            return ret
    
    def threeSum(self, one, nums, target):
        print(f"three nums {nums}")
        ret = []
        if len(nums) < 3:
            return []
        else:
            for second in range(len(nums)-2):
                L = second + 1
                R = len(nums) - 1
                while L < R:
                    approach = one + nums[second] + nums[L] + nums[R]
                    print(f"ONE {one}\tsecond {nums[second]}\tL {L}\tR {R} \tapproach {approach}")
                    if approach == target:
                        ret.append([one, nums[second], nums[L], nums[R]])
                        L += 1
                    elif approach < target:
                        L += 1
                    else:
                        R -= 1

            return ret
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    n = [2, 2, 2, 2, 2]
    ret = s.fourSum(n, 8)
    print(ret)