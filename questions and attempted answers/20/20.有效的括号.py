#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        while "()" in s or "[]" in s or r"{}" in s:
            s = s.replace("()", "")
            s = s.replace("[]", "")
            s = s.replace(r"{}", "")

        if s == "":
            return True
        else:
            return False

# @lc code=end
s = Solution()
print(s.isValid(r"([]{}())[]{[()]}[]{[({}()[]{})]}({}[][()()])"))