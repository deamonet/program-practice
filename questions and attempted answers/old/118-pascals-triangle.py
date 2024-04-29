class Solution:
    def generate(self, numRows: int):
        res = []
        if numRows == 0:
            return res
        pre = [1]
        res.append(pre)
        for i in range(0, numRows-1):
            middle = []
            length = len(pre)
            for j in range(length):
                if j == 0:
                    middle.append(pre[j])
                else:
                    middle.append(pre[j-1] + pre[j])

            middle.append(1)
            pre = middle
            res.append(middle)

        return res


if __name__ == "__main__":
    s = Solution()
    res = s.generate(0)
    print(res)
    
