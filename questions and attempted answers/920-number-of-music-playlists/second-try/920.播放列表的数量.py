# 还是动态规划
# dp[j,i] 定义成已经选择k不同首歌，播放列表长度为j时，最大播放列表的数量。
# 那么播放列表长度增加一个，有两种选择，选择一首新歌，或者选择一首旧的。

# 选择旧歌时，可选的从已有的 i 首歌中间选，除此之外，还要减去 K 首。
# dp[j+1, i] = dp[j,i] * (i - K)
# 选择新歌时，可选的有 N - i
# dp[j+1, i+1] = dp[j,i] * (N - i)

#
# @lc app=leetcode.cn id=920 lang=python3
#
# [920] 播放列表的数量
#

# @lc code=start
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        ls = [0 for _ in range(n+1)]
        dp = [ls.copy() for _ in range(goal+1)]
        dp[1][1] = 1
        for j in range(1, goal+1):
            print(3000)
            for i in range(1, n+1):
                dp[j][i] += dp[j-1][i] * max((i-k), 0)
                dp[j][i] += dp[j-1][i-1] * (n-i+1)
        
        return dp[goal][n]
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    ret = s.numMusicPlaylists(3, 3, 1)
    print(ret)