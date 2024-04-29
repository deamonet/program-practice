from string import ascii_lowercase

# @lc app=leetcode.cn id=17 lang=python3
# [17] 电话号码的字母组合

#  @lc code=start

class Solution:
    def letterCombinations(self, digits):
        if len(digits) == 0:
            return []

        ret = [""]
        ret2 = []
        for num in digits:
            num = int(num)
            if num < 2:
                continue
            elif num < 7:
                tls = ascii_lowercase[3*num - 6: 3*num - 3]
            elif num == 7:
                tls = ascii_lowercase[3*num - 6: 3*num - 2]
            elif num < 9:
                tls = ascii_lowercase[3*num - 5: 3*num - 2]
            else:
                tls = ascii_lowercase[3*num - 5: 3*num - 1]

            print(num)
            print(tls)            
            for stg in ret:
                for letter in tls:
                    ret2.append(stg + letter)

            print(ret)
            ret = ret2.copy()
            ret2 = []
            
        return ret
# @lc code=end


if __name__ == "__main__":
    s = Solution()
    ret = s.letterCombinations("2334")
    print(ret)
