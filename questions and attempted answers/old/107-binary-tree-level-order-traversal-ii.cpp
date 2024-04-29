/*
107. 二叉树的层次遍历 II
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

int main()
{
    Solution s;
    vector<int> nums;
    vector<vector<int>> data;
    int rows = 3, cols = 3;
    for (int j = 0; j < rows; j++)
    {
        nums.clear();
        for (int i = 0; i < cols; i++)
        {
            nums.push_back(i + cols * j);
        };
        data.push_back(nums);
    };
    Show2Vec(data); 
    cout << "\n\n";
    ShowVec(s.spiralOrder(data));
}