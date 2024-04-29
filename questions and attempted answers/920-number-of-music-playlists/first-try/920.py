#
# @lc app=leetcode.cn id=920 lang=python3
#
# [920] 播放列表的数量
#
# @lc code=start
def numMusicPlaylists(n: int, goal: int, k: int) -> int:
    ret = 0
    path = []
    used = dict([[i, k] for i in range(n)])
    if n == 0:
        print("NOWHERE")
        return ret
    
    return dfs(ret, path, 0, used, n, goal, k)


def dfs(ret, path, depth, used, n, goal, k):
    if depth == goal:
        ret += 1
        return ret

    for i in range(n):
        if used[i] >= k:
            temp = used[i]
            used[i] = 0
            path.append(i)
            dfs(ret, path, depth+1, used, n, goal, k)
            path.pop()
            used[i] = temp
        else:
            used[i] += 1
# @lc code=end

if __name__ == "__main__":
    ret = numMusicPlaylists(1, 1, 0)
    print(ret)