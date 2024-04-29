/*
102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/


#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

// 二叉树

// Definition for a binary tree TreeNode.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// C++ Program to print binary tree in 2D
#include <bits/stdc++.h>

// using namespace std;
#define COUNT 10

// A binary tree TreeNode
// class TreeNode
// {
// public:
//     int val;
//     TreeNode *left, *right;

//     /* Constructor that allocates a new TreeNode with the
//     given val and NULL left and right pointers. */
//     TreeNode(int val)
//     {
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(TreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current TreeNode after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->val << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(TreeNode *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// This code is contributed by rathbhupendra

void ShowVec(const vector<int> &valList)
{
    int count = valList.size();
    cout << "[ ";
    for (int i = 0; i < count; i++)
    {
        if (i == count - 1)
        {
            cout << valList[i];
        }
        else
        {
            cout << valList[i] << ", ";
        }
    };
    cout << " ]";
}

void ShowVec2(const vector<TreeNode *> &valList)
{
    int count = valList.size();
    cout << "[ ";
    for (int i = 0; i < count; i++)
    {
        if (i == count - 1)
        {
            cout << valList[i]->val;
        }
        else
        {
            cout << valList[i]->val << ", ";
        }
    };
    cout << " ]";
}

TreeNode *create_binary_tree(vector<int> elements)
{
    cout << "\nBING CREATING BINARY TREE\n";
    TreeNode *root = new TreeNode(elements[0]);
    cout << "root" << root->val;
    cout << "\n";
    vector<TreeNode *> upper_que;
    vector<TreeNode *> new_upper_que;
    upper_que.push_back(root);
    int sum = 1;
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements.size() - sum == 0)
        {
            return root;
        }
        ShowVec2(upper_que);
        cout << "\n";
        cout << "upper_que size" << upper_que.size();
        cout << "\n";
        for (int n = 0; n < upper_que.size(); n++)
        {
            cout << "n\t" << n;
            cout << "\n";
            if (upper_que[n]->val != -1)
            {
                if (elements.size() - sum >= 2)
                {
                    cout << "sum" << sum;
                    cout << "\t";
                    cout << "element sum" << elements[sum];
                    cout << "\t";
                    TreeNode *left_node = new TreeNode(elements[sum]);
                    cout << "left node" << left_node->val;
                    cout << "\t";
                    TreeNode *right_node = new TreeNode(elements[sum + 1]);
                    cout << "right node" << right_node->val;
                    cout << "\n";
                    upper_que[n]->left = left_node;
                    upper_que[n]->right = right_node;
                    sum = sum + 2;
                    new_upper_que.push_back(left_node);
                    new_upper_que.push_back(right_node);
                }
                else if (elements.size() - sum == 1)
                {
                    cout << "\n\nSUM = 5\n\n";
                    cout << "sum" << sum;
                    cout << "\t";
                    cout << "element sum" << elements[sum];
                    cout << "\t";
                    TreeNode *left_node = new TreeNode(elements[sum]);
                    cout << "left node" << left_node->val;
                    cout << "\n";
                    upper_que[n]->left = left_node;
                    sum = sum + 2;
                    new_upper_que.push_back(left_node);
                    return root;
                }
            }
        }
        upper_que.clear();
        upper_que = new_upper_que;
        new_upper_que.clear();
    }
    return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<TreeNode *> upper_level, lower_level;
        vector<int> medium;
        vector<vector<int>> res;
        upper_level.push_back(root);
        medium.push_back(root->val);
        res.push_back(medium);
        while (!upper_level.empty())
        {
            medium.clear();
            lower_level.clear();
            for (int n = 0; n < upper_level.size(); n++)
            {
                if (upper_level[n]->left != NULL)
                {
                    lower_level.push_back(upper_level[n]->left);
                    medium.push_back(upper_level[n]->left->val);
                }
                if (upper_level[n]->right != NULL)
                {
                    lower_level.push_back(upper_level[n]->right);
                    medium.push_back(upper_level[n]->right->val);
                }
            }
            if(!medium.empty())
            {
                res.push_back(medium);
            }
            upper_level = lower_level;
        }
        return res;
    }
};

int main(void)
{
    return 0;
}