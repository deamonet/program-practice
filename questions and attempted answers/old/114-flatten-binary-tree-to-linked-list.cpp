/*
114. 二叉树展开为链表
给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define COUNT 10
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

// 新版本的show vec
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

class Solution
{
public:
    TreeNode *pre_order(TreeNode *root)
    {
        if(root!=nullptr)
        {cout << "YES3";
        cout << "\n";
        TreeNode *left_last_node = pre_order(root->left);
        TreeNode *right_last_node = pre_order(root->right);
        if(left_last_node && right_last_node)
        {
            cout << "YES4";
            cout << "\n";
            left_last_node->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            return right_last_node;
        }
        else if (!left_last_node && right_last_node)
        {
            cout << "YES5";
            cout << "\n";
            return right_last_node;
        }
        else if (left_last_node && !right_last_node)
        {
            cout << "YES6";
            cout << "\n";
            root->right = root->left;
            root->left = nullptr;
            return left_last_node;
        }
        else
        {
            cout << "YES7";
            cout << "\n";
            return root;
        }}
        else
        {
            cout << "YES8";
            cout << "\n";
            return root;
        }
        
    }
    void flatten(TreeNode *root)
    {
        cout<<"YES1";
        cout<<"\n";
        if (root)
        {
            cout << "YES2";
            cout << "\n";
            TreeNode *node = pre_order(root);
            return;
        }
        else
        {
            return;
        }
    }
};

int main(void)
{
    static const int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::const_iterator first = vec.begin() + 3;
    vector<int>::const_iterator last = vec.begin() + 6;
    vector<int> subvec(first, last);
    ShowVec(vec);
    cout << "\n\n";
    TreeNode *root = create_binary_tree_no_print(vec);
    print2D(root);
    Solution s;
    s.flatten(root);
    print2D(root);
}