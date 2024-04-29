/*
98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>


using namespace std;

// 动态规划的办法：
// 思路可能是后序遍历。左右子树都是搜索二叉树且
// 左子树最大值小于，右子树最小值大于根节点，那么新加入的根节点成为一个更大的二叉搜索数




// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int MAX_INT = 2147483647;
    int MIN_INT = -2147483648;

    int return_function(int max, int min, bool left)
    {
        if (left)
        {
            return max;
        }
        else
        {
            return min;
        }
    }

    int wrong_return_function(bool left)
    {
        if (left)
        {
            return MAX_INT;
        }
        else
        {
            return MIN_INT;
        }
    }

    int valid(TreeNode *root, int upper_value, bool left)
    {
        if (!root)
        {
            int max = valid(root->left, root->val, true);
            int min = valid(root->right, root->val, false);

            if (root->left == NULL)
            {
                if (min > root->val)
                {
                    return return_function(root->val, min, left);
                }
                else
                {
                    return wrong_return_function(left);
                }
            }
            else if (root->right == NULL)
            {
                if (max < root->val)
                {
                    return return_function(max, root->val, left);
                }
                else
                {
                    return wrong_return_function(left);
                }
            }
            else
            {
                if (min > root->val && max < root->val)
                {
                    return return_function(max, min, left);
                }
                else
                {
                    return wrong_return_function(left);
                }
            }
        }
        else
        {
            return upper_value;
        }
    }

    bool isValidBST(TreeNode *root)
    {
        int res = valid(root, root->val, true);
        if (res < MAX_INT && res > MIN_INT)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};