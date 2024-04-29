/*
105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
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

void ShowVec(const vector<int> &valList)
{
    int count = valList.size();
    for (int i = 0; i < count; i++)
    {
        cout << valList[i] << "\t";
    };
    cout << "\n";
}

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

// 以下这种递归会抛出 资源分配错误
// class Solution
// {
// public:
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         if(preorder.empty()){return NULL;}
//         else if(preorder.size()==1)
//         {
//             TreeNode *node = new TreeNode(preorder[0]);
//             return node;
//         }
//         else
//         {
//             int root_value = preorder[0];
//             int root_postion = 0;
//             for (int i = 0; i < inorder.size(); i++)
//             {
//                 if (inorder[i] == root_value)
//                 {
//                     root_postion = i;
//                     break;
//                 }
//             }
//             vector<int> left_sub_pre_order(preorder.begin() + 1, preorder.begin() + root_postion);
//             vector<int> right_sub_pre_order(inorder.begin() + root_postion, inorder.end());

//             vector<int> left_sub_in_order(inorder.begin(), inorder.begin() + root_postion - 1);
//             vector<int> right_sub_in_order(inorder.begin() + root_postion, inorder.end());

//             TreeNode *root = new TreeNode(root_value);
//             root->left = buildTree(left_sub_pre_order, left_sub_in_order);
//             root->right = buildTree(right_sub_pre_order, right_sub_in_order);
//             return root;
//         }
//     }
// };

// 迭代法
class Solution
{
public:
    TreeNode *buildTreePrac(vector<int> &preorder, vector<int> &inorder, short int order_range[])
    {
        if (order_range[1] < order_range[0])
        {
            cout << "YES1\n";
            return NULL;
        }
        else if (order_range[1] == order_range[0])
        {
            cout << "YES2\n";
            TreeNode *node = new TreeNode(preorder[order_range[0]]);
            cout << "node_value\t" << node->val;
            cout << "\n";
            return node;
        }
        else
        {
            cout << "YES3\n";
            short int root_value = preorder[order_range[0]];
            cout << "root_value\t" << root_value;
            cout << "\n";
            cout << "order_range\t";
            for (int i = 0; i < 4; i++)
            {
                cout << order_range[i] << ", ";
            }
            cout << "\n";
            if(root_value==7)
            {
                cout <<"\n\tseven\t\n";
            }
            short int root_position = 0;
            for (short int i = order_range[2]; i <= order_range[3]; i++)
            {
                if (inorder[i] == root_value)
                {
                    root_position = i;
                    break;
                }
            }
            TreeNode *root = new TreeNode(root_value);
            short int new_range[4];
            new_range[0] = order_range[0] + 1;
            new_range[1] = order_range[0] + root_position - order_range[2];
            new_range[2] = order_range[2];
            new_range[3] = root_position - 1;
            root->left = buildTreePrac(preorder, inorder, new_range);
            new_range[0] = order_range[0] + root_position - order_range[2] + 1;
            new_range[1] = order_range[1];
            new_range[2] = root_position + 1;
            new_range[3] = order_range[3];
            root->right = buildTreePrac(preorder, inorder, new_range);
            return root;
        }
    };

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return NULL;
        }
        else if (preorder.size() == 1)
        {
            TreeNode *node = new TreeNode(preorder[0]);
            return node;
        }
        else
        {
            cout <<"YES\n";
            short int end = (short int) preorder.size()-1;
            short int order_range[4] = {0, end, 0, end};
            return buildTreePrac(preorder, inorder, order_range);
        }
    }
};

int main(void)
{
    static const int pre[] = {3, 9, 20, 15, 7};
    static const int in[] = {9, 3, 15, 20, 7};
    vector<int> preorder(pre, pre + sizeof(pre) / sizeof(pre[0]));
    vector<int> inorder(in, in + sizeof(in) / sizeof(in[0]));
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    print2D(root);
}
