import pprint
import tqdm


class Solution:
    def permute(self, nums):
        return self.arrange(nums)

    def arrange(self, nums):
        if len(nums) == 0:
            return nums
        elif len(nums) == 1:
            return nums
        elif len(nums) == 2:
            return [nums, nums[::-1]]
        
        res_ls = []
        for i, v in enumerate(nums):
            remain = nums[:i]
            remain.extend(nums[i+1:])
            ls = self.arrange(remain)
            for res in ls:
                res.insert(0, v)
                res_ls.append(res)
        
        return res_ls


s=Solution()
pprint.pprint(s.permute(list(range(8))))