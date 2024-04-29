import sys

def path(n, res):
    if res.get(n, 0) != 0:
        return res
    if n == 1:
        res[1] = 1
        return res
    elif n == 2:
        res[2] = 2
        return res
    else:
        resn = path(n-1, res)[n-1] + path(n-2, res)[n-2]
        res[n] = resn
        return res


if __name__ == "__main__":
    # 读取第一行的n
#coding=utf-8
# 本题为考试单行多行输入输出规范示例，无需提交，不计分。
    n = int(sys.stdin.readline().strip())
    for line in sys.stdin:
        a = line.split()
        print(int(a[0]) + int(a[1]))