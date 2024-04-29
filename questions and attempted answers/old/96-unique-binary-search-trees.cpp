/*
96. 不同的二叉搜索树
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;


// 我的思路： 
// 1. 回想搜索二叉树的性质：左子数上的节点全部小于根节点，右子数上的节点全部大于根节点。
//    但是这里的重点根本就不是大小关系，而是数量关系。也即是左子树实际上等价于相同数量的从1开始的二叉树。
// 2. 如果用dp(n)表示1,2,3...n 的二叉树的数量
//    那么对于根节点是 x 的二叉树，左子树的数量是dp(x-1)，右子树的数量是dp(n-x) （注意到x+1到n 等价于1到n-1）
// 3. dp(n) 则由 sumd[dp(x-1) * dp(n-x)] 其中 1<= x <= n；令 dp(0)=1。

// 另外注明：这就是组合数学中的卡特兰数

class Solution
{
public:
   int numTrees(int n)
   {
      if (n == 0)
      {
         return 0;
      }
      int dp[n + 1];
      dp[0] = 1;
      dp[1] = 1;
      for (int k = 2; k < n + 1; k++)
      {
         dp[k] = 0;
         for (int l = 1; l < k + 1; l++)
         {
            dp[k] += dp[l - 1] * dp[k - l];
         }
         cout<<dp[k]<<"\n";
      }
      return dp[n];
   }
};

int main()
{
   int n = 20;
   Solution s;
   cout << s.numTrees(n);
}