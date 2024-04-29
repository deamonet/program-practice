#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#
# https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (38.61%)
# Likes:    7282
# Dislikes: 0
# Total Accepted:    1.6M
# Total Submissions: 4.2M
# Testcase Example:  '"abcabcbb"'
#
# 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
# 
# 
# 
# 示例 1:
# 
# 
# 输入: s = "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
# 
# 
# 示例 2:
# 
# 
# 输入: s = "bbbbb"
# 输出: 1
# 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
# 
# 
# 示例 3:
# 
# 
# 输入: s = "pwwkew"
# 输出: 3
# 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
# 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
# 
# 
# 
# 
# 提示：
# 
# 
# 0 <= s.length <= 5 * 10^4
# s 由英文字母、数字、符号和空格组成
# 
# 
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # sliding window
        if len(s) == 0:
            return 0
        
        start, ret = 0, 0
        dic = dict()
        for end, end_str in enumerate(s):
            print(f"{start}\t\t\t{end}\t\t\t{ret}")
            if dic.get(end_str, -1) != -1:
                print('begin duplicates')
                # 保持滑动窗口一直向前移动
                # 之前的数也算进滑动窗口的可能
                start = max(dic[end_str] + 1, start) 
            
            ret = max(end - start + 1, ret)
            dic[end_str] = end
            print(f"{start}\t\t\t{end}\t\t\t{ret}")
            print("========================================")
        return ret
# @lc code=end

if __name__ == "__main__":
    string = "27211312"
    s = Solution()
    ret = s.lengthOfLongestSubstring(string)
    print(ret)