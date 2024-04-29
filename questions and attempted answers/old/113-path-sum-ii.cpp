/*
113. 路径总和 II
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 一下的代码虽然正确，但是由于多次使用了temp 直接传入参数，导致空间复杂度和时间复杂度大幅增加。
// 最好的做法便是，一开始设置temp的类变量，并再加入到结果的时候，拷贝一份。
class Solution
{
public:
    vector<vector<int>> res;
    void hasPathSum(TreeNode *root, int sum, vector<int> temp)
    {
        if (root == NULL)
        {
            return;
        }
        else if (root->left == NULL && root->right == NULL && root->val == sum)
        {
            temp.push_back(root->val);
            res.push_back(temp);
            return;
        }
        else
        {
            temp.push_back(root->val);
            hasPathSum(root->left, sum - root->val, temp);
            hasPathSum(root->right, sum - root->val, temp);
            return;
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> temp;
        temp.clear();
        hasPathSum(root, sum, temp);
        return res;
    }
};