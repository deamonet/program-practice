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
        if(valList[i]==NULL){
            cout<<" NULL ";
            continue;
        }
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
        if (elements.size() == sum)
        {
            return root;
        }
        ShowVec2(upper_que);
        cout << "\n";
        cout << "upper_que size\t" << upper_que.size();
        cout << "\n";
        for (int n = 0; n < upper_que.size(); n++)
        {
            cout << "n\t" << n;
            cout << "\n";
            if(upper_que[n]==NULL){continue;}
            if (upper_que[n]->val != -1)
            {
                if (elements.size() - sum >= 2)
                {
                    cout << "sum\t" << sum;
                    cout << "\t";
                    cout << "element sum\t" << elements[sum];
                    cout << "\t";
                    if (elements[sum] == 0)
                    {
                        upper_que[n]->left = NULL;
                        new_upper_que.push_back(NULL);
                    }
                    else
                    {
                        TreeNode *left_node = new TreeNode(elements[sum]);
                        cout << "left node\t" << left_node->val;
                        cout << "\t";
                        upper_que[n]->left = left_node;
                        new_upper_que.push_back(left_node);
                    }

                    if (elements[sum + 1] == 0)
                    {
                        cout << "\n\nYES\n\n";
                        upper_que[n]->right = NULL;
                        new_upper_que.push_back(NULL);
                    }
                    else
                    {
                        TreeNode *right_node = new TreeNode(elements[sum + 1]);
                        cout << "right node\t" << right_node->val;
                        cout << "\n";
                        upper_que[n]->right = right_node;
                        new_upper_que.push_back(right_node);
                    }
                    sum = sum + 2;
                }
                else if (elements.size() - sum == 1)
                {
                    cout << "\n\nSUM = 5\n\n";
                    cout << "sum\t" << sum;
                    cout << "\t";
                    cout << "element sum\t" << elements[sum];
                    cout << "\t";
                    if (elements[sum] == 0)
                    {
                        upper_que[n]->left = NULL;
                        new_upper_que.push_back(NULL);
                    }
                    else
                    {
                        TreeNode *left_node = new TreeNode(elements[sum]);
                        cout << "left node\t" << left_node->val;
                        cout << "\t";
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

int main(void)
{
    // static const int arr[] = {1,2,3,4,-1,5,6,7,8,9,10};
    // static const int arr[] = {2, 3, 3, 4, 5, 5};
    static const int arr[] = {1, 0, 4, 5, 7};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ShowVec(vec);
    TreeNode *root = create_binary_tree(vec);
    print2D(root);
    return 0;
}
