#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>


using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 因为对于任意一个数而言，遍历出来的序列都是一样的，所以我们只需要比较遍历序列的异同就好了


class Solution
{
public:
    vector<int> preOrder(TreeNode *root, vector<int> data)
    {
        if(root!=NULL)
        {
            data.push_back(root->val);
            data = preOrder(root->left, data);
            data = preOrder(root->right, data);
        }
        else
        {
            return data;
        }
    }


    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> seq1, seq2;
        seq1 = preOrder(p, seq1);
        seq2 = preOrder(q, seq2);
        
        if(seq1.size()!=seq2.size()) return false;
        for(int i=0; i<seq1.size(); i++)
        {
            if(seq1[i] != seq2[i]) return false;
        }
        return true;

    }
};