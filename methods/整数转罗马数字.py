class Solution:
    def intToRoman(self, num: int) -> str:
        """
        d = {1 : 'I' , 5  : 'V' , 10  : 'X', 50: 'L',
             100: 'C', 500: 'D' , 1000: 'M',
             4 : 'IV', 9  : 'IX',   40: 'XL',
             90: 'XC', 400: 'CD',  900:'CM'}

        res = ''
        l = list(d.keys())
        l.sort(reverse=True)

        if not num:
            return ''

        if num < 4:
            return num * 'I'

        cnt = 0
        d2 = dict(enumerate(l))

        temp = num - d2[cnt]
        while cnt < 13:
            if temp < 0:
                cnt += 1
                temp = num - d2[cnt]
            elif temp > 0:
                res += d[d2[cnt]]
                temp = temp - d2[cnt]
            else:
                res += d[d2[cnt]]
                break

        return res
        """
        d = {1 : 'I' , 5  : 'V' , 10  : 'X', 50: 'L',
             100: 'C', 500: 'D' , 1000: 'M',
             4 : 'IV', 9  : 'IX',   40: 'XL',
             90: 'XC', 400: 'CD',  900:'CM'}

        res = ''
        l = list(d.keys())
        l.sort(reverse=True)

        if not num:
            return ''

        if num < 4:
            return num * 'I'

        cnt = 0
        d2 = dict(enumerate(l))

        while cnt < 13:
            while num >= d2[cnt]:
                num -= d2[cnt]
                res += d[d2[cnt]]
            cnt += 1

        return res

    def romanToInt(self, s: str) -> int:
        d = {'I': 1, 'IV': 4, 'V': 5, 'IX': 9, 'X': 10, 'XL': 40, 'L': 50, 'XC': 90, 'C': 100, 'CD': 400, 'D': 500, 'CM': 900, 'M': 1000}
        
        l = list(d.items())
        l = sorted(l, key=lambda x: x[1], reverse=True)

        index = 0
        res = 0
        cnt = 0
        while index < 13 and cnt < 20:
            cnt += 1
            roman = l[index][0]
            length = len(roman)
            while s.find(roman) == 0:
                s = s[length:]
                res += d[roman]
            
            index += 1

        return res

s = Solution()


for i in range(1000):
    roman = s.intToRoman(i)
    print(i, end='\t')
    print(roman, end='\t')
    num = s.romanToInt(roman)
    print(num, end='\t')
    if i == num:
        print("YES")


