class Solution:
    def generate(self, numRows: int):
        res = []
        if numRows == 0:
            return res
        
        factorial = [1]
        for i in range(0, numRows):
            factorial.append(factorial[i] * (i+1))
        
        
        if numRows % 2 == 0:
            for i in range(0, numRows // 2):
                res.append(factorial[-1] // 
                           (factorial[i] * factorial[numRows-i]))
            
            temp = res.copy()
            res.append(factorial[-1]// (factorial[numRows // 2]**2))
            temp.reverse()
            return res + temp
        
        else:
            for i in range(0, numRows // 2 + 1):
                res.append(factorial[-1] //
                           (factorial[i] * factorial[numRows-i]))
        
            temp = res.copy()
            temp.reverse()
            return res + temp
        
        
    


if __name__ == "__main__":
    s = Solution()
    res = s.generate(0)
    print(res)
    print("\n")
    print(len(res))
