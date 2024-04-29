import pysnooper


class Solution:
    def jump(self, nums):
        i = 0
        length = len(nums)

        if length == 0:
            return 0
        
        if length == 1:
            return 0
        
        if length == 2:
            return 1

        cnt = 0
        begin = 1
        while i < length:
            if length - nums[i] - i <= 1:
                return cnt + 1

            max = 1
            max_point = 1
            end = nums[i]+1
            
            for j in range(begin, end):
                temp = nums[j + i]
                if max + max_point <= temp + j :
                    max = temp
                    max_point = j

            i += max_point
            print(i, end='\t\t')
            print(nums[i])
            cnt += 1
            begin = end - max_point

            if cnt > length:
                break

        return cnt

s=Solution()
nums = list(range(100000000))
print(s.jump(nums))