"""
128. 最长连续序列
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
通过次数65,793提交次数128,238
"""

import string
from collections import deque  # line 158
from typing import List
from collections import defaultdict  # line 141
from pprint import pprint
from tqdm import tqdm



# 垃圾版本
class Solution_worse:
    def longestConsecutive(self, nums):
        nums.sort()
        nums_dic = dict(enumerate(nums))
        maxium = 0
        temporary_count = 1
        for i in range(len(nums)-1):
            if nums_dic[i+1] - nums_dic[i] == 1:
                temporary_count += 1
            else:
                if temporary_count > maxium:
                    maxium = temporary_count
                
                temporary_count = 1
                
        return maxium


# 以下的算法目测时间复杂度是 O(3n) = O(n)
class Solution:
    def longestConsecutive(self, nums):
        nums_set = set(nums)
        consecutive_length = dict()
        visitied = set()
        for number in nums_set:
            if not number in visitied:
                next_number = number + 1
                visitied.add(number)
                consecutive_length[number] = 1
                while next_number in nums_set:
                    visitied.add(next_number)
                    consecutive_length[number] += 1
                    next_number += 1
        
        begin_nums_set = set(consecutive_length.keys())
        visitied.clear()
        for number in begin_nums_set:
            if not number in visitied:
                visitied.add(number)
                final_number = number + consecutive_length[number]
                if final_number in begin_nums_set:
                    consecutive_length[number] += consecutive_length[final_number]
                    
        print(consecutive_length)
        maximum = 0
        for length in consecutive_length.values():
            if maximum < length:
                maximum = length
                
        return maximum
                
                
                    
if __name__ == "__main__":
    nums = [100, 4, 200, 1, 3, 2, 5, 6, 9, 10, 39, 7, 8, 100, 13, 40, 30, 48, 84, 495, 12, 11]
    s = Solution()
    print(s.longestConsecutive(nums))
