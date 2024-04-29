/*
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

#define COUNT 10

// 二叉树
// Definition for a binary tree TreeNode.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

TreeNode *create_binary_tree_no_print(vector<int> elements)
{
    TreeNode *root = new TreeNode(elements[0]);
    vector<TreeNode *> upper_que;
    vector<TreeNode *> new_upper_que;
    upper_que.push_back(root);
    int sum = 1;
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements.size() == sum)
        {
            return root;
        }
        for (int n = 0; n < upper_que.size(); n++)
        {
            if (upper_que[n] == NULL)
            {
                continue;
            }
            if (upper_que[n]->val != -1)
            {
                if (elements.size() - sum >= 2)
                {
                    if (elements[sum] == 0)
                    {
                        upper_que[n]->left = NULL;
                        new_upper_que.push_back(NULL);
                    }
                    else
                    {
                        TreeNode *left_node = new TreeNode(elements[sum]);
                        upper_que[n]->left = left_node;
                        new_upper_que.push_back(left_node);
                    }

                    if (elements[sum + 1] == 0)
                    {
                        upper_que[n]->right = NULL;
                        new_upper_que.push_back(NULL);
                    }
                    else
                    {
                        TreeNode *right_node = new TreeNode(elements[sum + 1]);
                        upper_que[n]->right = right_node;
                        new_upper_que.push_back(right_node);
                    }
                    sum = sum + 2;
                }
                else if (elements.size() - sum == 1)
                {
                    if (elements[sum] == 0)
                    {
                        upper_que[n]->left = NULL;
                        new_upper_que.push_back(NULL);
                    }
                    else
                    {
                        TreeNode *left_node = new TreeNode(elements[sum]);
                        upper_que[n]->left = left_node;
                        new_upper_que.push_back(left_node);
                    }
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

// 深度优先搜索
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if(root==NULL){return 0;}
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        if(left_depth >= right_depth)
        {
            return ++left_depth;
        }else
        {
            return ++right_depth;
        }
    }
};

int main(void)
{
    static const int arr[] = {1, 0, 4, 5, 7, 9, 0, 2, 0, 2, 0, 2, 9, 3,4,6, 0};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    TreeNode *root = create_binary_tree_no_print(vec);
    print2D(root);
    Solution s;
    int res = s.maxDepth(root);
    cout<<"\n";
    cout<<res;
    cout << "\n";
    return 0;
}
