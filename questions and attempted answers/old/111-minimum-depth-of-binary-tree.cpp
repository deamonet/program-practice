/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
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

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            return minDepth(root->right) + 1;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            return minDepth(root->left) + 1;
        }
        else
        {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
};

// 还可以进一步简化代码。以下三种情况都可以归类到同一种情况：

if (root->left == NULL && root->right == NULL)
{
    return 1;
}
else if (root->left == NULL && root->right != NULL)
{
    return minDepth(root->right) + 1;
}
else(root->left != NULL && root->right == NULL)
{
    return minDepth(root->left) + 1;

// 以下这种情况

if (root->left == NULL || root->right == NUll)
{
    return minDepth(root->left) + minDepth(root->right) + 1;
}

// 最终代码是

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else if (root->left == NULL || root->right == NUll)
            return minDepth(root->left) + minDepth(root->right) + 1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};