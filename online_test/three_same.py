import sys 


def remove_threesome(str):
    n = len(str)
    if n == 0 or n == 1 or n == 2:
        return str
    else:
        i = 1
        cnt = 0
        conti = ""
        res = ""
        while i < n:
            print(i, conti, cnt, res)
            if conti == "":
                if str[i-1] == str[i]:
                    conti = str[i]
                    if i == n - 1:
                        res += str[i-1]
                        res += str[i]
                else:
                    res += str[i-1]
                    if i == n - 1:
                        res += str[i]

            elif conti == str[i]:
                cnt += 1
            elif conti != str[i]:
                if cnt == 0:
                    res += str[i-2]
                    res += str[i-1]
                
                conti = ""
                cnt = 0
            else:
                pass

            i += 1

        return res

a = "222BCC111CB"
print(remove_threesome(a))