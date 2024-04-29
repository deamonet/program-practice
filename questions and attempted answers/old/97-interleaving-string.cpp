/*
97. 交错字符串
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;


// dp[i+j+1]表示s3[0,i+j+1]可以由 s1[0,i]和s2[0,j]的部分交错构成或者不构成。


// 显然我的思路是错的，也许是一半的错误。

// 最好的办法是利用动态规划，当然这道题目也可以用bfs，广度优先搜索。
// 由s1 和 s2构成一个二维的矩阵，再加上零项，就构成了字符交错组成s3的可行性路径。

// 如图
//   Ø d b b c a
// Ø T F F F F F
// a T F F F F F
// a T T T T T F
// b F T T F T F
// c F F T T T T
// c F F F T F T

// 把矩阵中的每一个作为横纵座标dp(i, j)，
// 表示s3的前i+j个字符是否可以被s1的前i个字符和s2的前j个字符交错表示
// （注意我特意没有用s1[i] s2[j]这种表示法，因为这种表示法下的字符是从0开始计数的。

// 那么构建状态转移方程的关键就在于利用 dp(i,j) 和dp(i-1,j) 以及 dp(i,j-1)之间的关系
// 后两者分别对应于dp(i,j)的左侧格子和上方的格子。
// 因为可以发现的是：无论是左侧还是上方到dp(i,j)的递进，仅仅用到了s1或者s2的一个字符。
// 那么就可以通过判断s1的第i个字符或者是s2的第j个字符 与 s3 的第i+j个字符相等来比较这种递进是否成立。
// 如果递进关系和旁路格子都是true，那么当前格子也是true。以此继续下去，就会生成一条true路径。
// 把这种关系用数学公式描述就是：
// dp(i, j) = [dp(i - 1, j) and s1(i) == s3(i + j)] or [dp(i - 1, j) and s2(j) == s3(i + j)]
// 其中 s(x)表示的是字符串s第x个字符；
// dp(i,j)表示的是s1的前i个字符和s2的前j个字符是否可以组成s3的前i+j个字符。
// （这里我特地没有使用字符串的定位方法，是为了统一dp中的i, j和字符串函数的i, j的含义

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        cout << "s1.size()\t" << s1.size();
        cout << "\n";
        cout << "s2.size()\t" << s2.size();
        cout << "\n";
        cout << "s3.size()\t" << s3.size();
        cout << "\n";
        if (s3.size() != s1.size() + s2.size())
        {
            cout << "YES\n";
            return false;
        }

        int k = 0, i = 0, j = 0;
        for (; k < s3.size(); k++)
        {
                if (s3[k] == s1[i])
                {
                    i++;
                }            
                else if (s3[k] == s2[j])
                {
                    j++;
                }
                else
                {
                    cout << "fuck2\n";
                    return false;
                }
        }

        if (k < s3.size() || i < s1.size() || j < s2.size())
        {
            cout << "k\t" << k;
            cout << "\n";
            cout << "i\t" << i;
            cout << "\n";
            cout << "j\t" << j;
            cout << "\n";
            cout << "fuck3\n";
            return false;
        }
        cout << "YES FINAL\n";
        return true;
    }
};

int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution s;
    cout << s.isInterleave(s1, s2, s3);

}