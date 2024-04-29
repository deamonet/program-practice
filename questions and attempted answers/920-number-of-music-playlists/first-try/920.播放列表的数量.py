#
# @lc app=leetcode.cn id=920 lang=python3
#
# [920] 播放列表的数量
#
# @lc code=start
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        ret = 0
        used = dict([[i, k] for i in range(n)])
        if n == 0:
            print("NOWHERE")
            return ret
        
        return self.dfs(ret, 0, used, n, goal, k)


    def dfs(self, ret, depth, used, n, goal, k):
        if depth == goal:
            ret += 1
            return ret

        for i in range(n):
            if used[i] >= k:
                temp = used[i]
                used[i] = 0
                self.dfs(ret, depth+1, used, n, goal, k)
                used[i] = temp
            else:
                used[i] += 1
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    ret = s.numMusicPlaylists(1, 1, 0)
    print(ret)