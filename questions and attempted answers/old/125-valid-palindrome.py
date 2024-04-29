"""
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
通过次数139,654提交次数305,103
"""

import string
import re

class Solution:
    def isPalindrome(self, s: str):
        punct = string.punctuation
        s = re.sub("[{0}\s+]".format(punct), "", s)
        length = len(s)
        if(length==0):
            return True
        
        for i in range(length // 2):
            if s[i].lower() == s[length - i - 1].lower():
                continue

            else:
                return False
            
        return True


if __name__ == "__main__":
    s2 = "A man, a plan, a canal: Panama"
    s3 = "race a car"
    s = Solution()
    print(s.isPalindrome(s2))
    print(s.isPalindrome(s3))