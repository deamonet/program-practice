/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if ((root->left == NULL) && (root->right == NULL))
        {
            return true;
        }
        else if ((!(root->left == NULL) && (root->right == NULL)) || ((root->left == NULL) && !(root->right == NULL)))
        {
            return false;
        }
        else if (root->left->val == root->right->val)
        {
            TreeNode *virtual_root = new TreeNode(0);
            virtual_root->left = root->left->left;
            virtual_root->right = root->right->right;
            if (!isSymmetric(virtual_root))
            {
                return false;
            }
            virtual_root->left = root->left->right;
            virtual_root->right = root->right->left;
            if (!isSymmetric(virtual_root))
            {
                return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 迭代

// 队列 vector 容器

class Solution
{
public:
    queue<TreeNode *> workque;
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        workque.push(root);
        while (!workque.empty())
        {
            cout << "workque.front()->left\t" << workque.front()->left->val;
            cout << "\n";
            cout << "workque.front()->right\t" << workque.front()->right;
            cout << "\n";
            if (workque.front()->right == NULL)
            {
                cout << "YES";
            };
            if ((workque.front()->left == NULL) && (workque.front()->right == NULL))
            {
                workque.pop();
            }
            else if ((workque.front()->left != NULL && workque.front()->right == NULL) ||
                     (workque.front()->left == NULL && workque.front()->right != NULL))
            {
                return false;
            }
            else if (workque.front()->left->val == workque.front()->right->val)
            {
                cout << "work.front()->val" << workque.front()->val;

                TreeNode *virtual_root = new TreeNode(0);
                virtual_root->left = workque.front()->left->left;
                virtual_root->right = workque.front()->right->right;

                cout << "\n";
                cout << "virtual_root\n";
                print2D(virtual_root);
                cout << "\n\n";
                workque.push(virtual_root);

                TreeNode *virtual_root2 = new TreeNode(0);
                virtual_root2->left = workque.front()->left->right;
                virtual_root2->right = workque.front()->right->left;

                cout << "virtual_root2\n";
                print2D(virtual_root2);
                cout << "\n\n";
                workque.push(virtual_root2);

                workque.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{
    // static const int arr[] = {1,2,3,4,-1,5,6,7,8,9,10};
    // static const int arr[] = {2, 3, 3, 4, 5, 5};
    static const int arr[] = {1, 2, 2, 4, 5, 5};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ShowVec(vec);
    TreeNode *root = create_binary_tree(vec);
    print2D(root);
    Solution s;
    bool res = s.isSymmetric(root);

    cout << "\nRESULT\t";
    cout << res;
    return 0;
}