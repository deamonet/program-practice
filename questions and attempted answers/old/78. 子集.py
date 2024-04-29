"""
78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
"""

class Solution:
    def subsets(self, nums):
        # 回溯算法，其实就是选择去掉哪一个数字
        self.nums = nums
        self.length = len(nums)
        if (self.length == 0 or self.length == 1):
            return [nums]
        self.res = []
        self.path = []
        self.chosen = [False for i in range(self.length)]
        self.sets = {}
        self.backtracking(0)
        self.res.append([])
        return self.res


    def backtracking(self, depth):
        if depth == self.length:
            return

        for i in range(self.length):
            if not self.chosen[i]:
                print(self.chosen)
                self.chosen[i] = True
                self.path.append(self.nums[i])
                value = 
                if not self.sets.get(value, False):
                    self.sets[value] = True
                    self.res.append(self.path.copy())
                
                self.backtracking(depth + 1)
                self.path.pop()
                self.chosen[i] = False

            
s = Solution()
sl = list(range(3))
res = s.subsets(sl)
print(res)
print(len(res))


"""
评论区：
我觉得很多题解包括官方题解 都把纯递归给写成了回溯。 回溯一定要体现失败后终止 退回上一层这个过程 这个题里并没有任何地方会"失败"。 真正的回溯可以参考N-Queen那道题，当没有任何格子可以放棋子时退回上一层。
回溯本质上虽然是递归 但不是所有递归都是回溯。例如这一道题跟回溯并没有什么关系


优秀解答：
思路一:库函数
"""
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(nums)+1):
            for tmp in itertools.combinations(nums, i):
                res.append(tmp)
        return res

#思路二:迭代
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for i in nums:
            res = res + [[i] + num for num in res]
        return res

# 思路三:递归(回溯算法)

# pythonjava
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        
        def helper(i, tmp):
            res.append(tmp)
            for j in range(i, n):
                helper(j + 1,tmp + [nums[j]] )
                
        helper(0, [])
        return res  
"""
类似题目还有:

39.组合总和

40. 组合总和 II

46. 全排列

47. 全排列 II

78. 子集

90. 子集 II

这类题目都是同一类型的,用回溯算法!

其实回溯算法关键在于:不合适就退回上一步

然后通过约束条件, 减少时间复杂度.

大家可以从下面的解法找出一点感觉!

78. 子集
"""
class Solution:
	def subsets(self, nums):		
                if not nums:
			return []
		res = []
		n = len(nums)

		def helper(idx, temp_list):
			res.append(temp_list)
			for i in range(idx, n):
				helper(i + 1, temp_list + [nums[i]])

		helper(0, [])
		return res
# 90. 子集 II

class Solution(object):
    def subsetsWithDup(self, nums):
        """
: type nums: List[int]
: rtype: List[List[int]]
"""
        if not nums:
            return []
        n = len(nums)
        res = []
        nums.sort()
		# 思路1
        def helper1(idx, n, temp_list):
            if temp_list not in res:
                res.append(temp_list)
            for i in range(idx, n):
                helper1(i + 1, n, temp_list + [nums[i]])
		# 思路2
        def helper2(idx, n, temp_list):
            res.append(temp_list)
            for i in range(idx, n):
                if i > idx and  nums[i] == nums[i - 1]:
                    continue
                helper2(i + 1, n, temp_list + [nums[i]])

        helper2(0, n, [])
        return res
# 46. 全排列

class Solution(object):
    def permute(self, nums):
        """
: type nums: List[int]
: rtype: List[List[int]]
"""
        if not nums:
            return
        res = []
        n = len(nums)
        visited = [0] * n
        def helper1(temp_list,length):
            if length == n:
                res.append(temp_list)
            for i in range(n):
                if visited[i] :
                    continue
                visited[i] = 1
                helper1(temp_list+[nums[i]],length+1)
                visited[i] = 0
        def helper2(nums,temp_list,length):
            if length == n:
                res.append(temp_list)
            for i in range(len(nums)):
                helper2(nums[:i]+nums[i+1:],temp_list+[nums[i]],length+1)
        helper1([],0)
        return res
# 47. 全排列 II

class Solution(object):
    def permuteUnique(self, nums):
        """
: type nums: List[int]
: rtype: List[List[int]]
"""
                if not nums:
			return []
		nums.sort()
		n = len(nums)
		visited = [0] * n
		res = []

		def helper1(temp_list, length):
			# if length == n and temp_list not in res:
			# 	res.append(temp_list)
			if length == n:
				res.append(temp_list)
			for i in range(n):
				if visited[i] or (i > 0 and nums[i] == nums[i - 1] and not visited[i - 1]):
					continue
				visited[i] = 1
				helper1(temp_list + [nums[i]], length + 1)
				visited[i] = 0

		def helper2(nums, temp_list, length):
			if length == n and temp_list not in res:
				res.append(temp_list)
			for i in range(len(nums)):
				helper2(nums[:i] + nums[i + 1:], temp_list + [nums[i]], length + 1)

		helper1([],0)
		# helper2(nums, [], 0)
		return res
# 39.组合总和

class Solution(object):
    def combinationSum(self, candidates, target):
        """
: type candidates: List[int]
: type target: int
: rtype: List[List[int]]
"""
        if not candidates:
            return []
        if min(candidates) > target:
            return []
        candidates.sort()
        res = []

        def helper(candidates, target, temp_list):
            if target == 0:
                res.append(temp_list)
            if target < 0:
                return
            for i in range(len(candidates)):
                if candidates[i] > target:
                    break
                helper(candidates[i:], target - candidates[i], temp_list + [candidates[i]])
        helper(candidates,target,[])
        return res
# 40. 组合总和 II

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates:
            return []
        candidates.sort()
        n = len(candidates)
        res = []
        
        def backtrack(i, tmp_sum, tmp_list):
            if tmp_sum == target:
                res.append(tmp_list)
                return 
            for j in range(i, n):
                if tmp_sum + candidates[j]  > target : break
                if j > i and candidates[j] == candidates[j-1]:continue
                backtrack(j + 1, tmp_sum + candidates[j], tmp_list + [candidates[j]])
        backtrack(0, 0, [])    
        return res
"""
作者：powcai
链接：https://leetcode-cn.com/problems/subsets/solution/hui-su-suan-fa-by-powcai-5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

"""



"""
优秀解答二：


第二种通用方法就是回溯算法。旧文回溯算法详解写过回溯算法的模板：

result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
只要改造回溯算法的模板就行了：

vector<vector<int>> res;

vector<vector<int>> subsets(vector<int>& nums) {
    // 记录走过的路径
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}

void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    // 注意 i 从 start 开始递增
    for (int i = start; i < nums.size(); i++) {
        // 做选择
        track.push_back(nums[i]);
        // 回溯
        backtrack(nums, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}
可以看见，对 res 的更新是一个前序遍历，也就是说，res 就是树上的所有节点：

作者：labuladong
链接：https://leetcode-cn.com/problems/subsets/solution/hui-su-si-xiang-tuan-mie-pai-lie-zu-he-zi-ji-wen-t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

"""