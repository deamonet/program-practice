/*
91. 解码方法
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

// 思路：深度优先遍历DFS。
// 终止条件：可选为零。
// 每一层循环：

// or 递归


// 递归的时间复杂度太久了，严重超时。这题用这种办法做出不来

class Solution
{
public:
    int res = 0;
    int numDecodings(string s)
    {
        int length = s.size();
        if (length == 0)
        {
            return 0;
        }

        // 如果存在开头为零的数字。。。。妈的，题目根本没说有这种情况，我怎么猜得到。

        back_trace(0, length, s);
        return res;
    }

    void back_trace(int start, int length, string s)
    {
        if (start == length)
        {
            res++;
            return;
        }
        else if (start > length)
        {
            return;
        }
        else
        {
            int cnt = 0;
            for (int i = 1; i < 3; i++)
            {
                string temp = s.substr(start, i);
                if(temp[0] == '0'){return;};
                cout << "cnt\t" << cnt << "\n";
                cout << "start\t" << start << "\n";
                cout << "temp\t" << temp << "\n";
                cout << "res\t" << res << "\n\n";
                int num = std::stoi(temp, 0, 10);
                if (num > 0 && num < 27)
                {
                    back_trace(start + i, length, s);
                }
                cnt++;
            }
        }
    }
};

int main()
{
    // string a = "12";
    // string a = "226";
    // string a = "";
    // string a = "1";
    // string a = "1278471837";
    // string a = "3892143895229831729873182718638163484619872997439278482973982";
    // string a = "101";
    // string a = "-1";
    string a = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
    Solution s;
    int res = s.numDecodings(a);
    cout << res;
}

/*
本题利用动态规划比较容易解决，但需要注意分情况讨论

dp[i] 为 Str[0...i] 的译码方法总数

分情况讨论 ( 建立最优子结构 )

若 s[i] = '0'，那么若 s[i] = '1' or '2'，则 dp[i] = dp[i-2]；否则return 0

    解释：s[i-1] + s[i] 唯一被译码，不增加情况

若 s[i-1] = '1'，则 dp[i] = dp[i-1] + dp[i-2]

    解释：s[i-l]与s[i]分开译码，为dp[i-l]；合并译码，为dp[i-2]

若 s[i-1] = '2' and '1'<= S[i] <='6'，则 dp[i] = dp[i-1] + dp[i-2]

    解释：同上


由分析可知，dp[i] 仅可能与前两项有关，故可以用单变量代替 dp[] 数组，将空间复杂度从 O(n) 降到 O(1)


当然还存在第四种情况：else。也就是s[i-1]为0,3-9（此时已排除s[i]==0的情况），
dp[i]=dp[i-1]。代码中cur相当于dp[i-1],所以直接省略了一个else语句。

*/

// 这个是C++
// 代码中 pre 是 dp[i-2]，curr 是 dp[i-1]

int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    int pre = 1, curr = 1; //dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++)
    {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2')
                curr = pre;
            else
                return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}
