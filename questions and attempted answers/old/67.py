def addBinary(a, b):
        res = ""
        cnt = 0
        length = min(len(a), len(b))
        for i in range(1, length+1):
            sum = eval(a[-i]) + eval(b[-i]) + cnt
            if sum == 2:
                cnt = 1
                sum = 0
            
            res = str(sum) + res
        return a[length:] + b[length:] + res

if __name__ == '__main__':
    a = '10010'
    b = '101'
    s = addBinary(a, b)
    print(s)
