/*
95. 不同的二叉搜索树 II
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

#define COUNT 10

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// A binary tree node
// class TreeNode
// {
// public:
//    int val;
//    TreeNode *left, *right;

//    /* Constructor that allocates a new node with the  
//     given val and NULL left and right pointers. */
//    TreeNode(int val)
//    {
//       this->val = val;
//       this->left = NULL;
//       this->right = NULL;
//    }
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

   // Print current node after space
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

// Driver code
// int main()
// {
//    TreeNode *root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);

//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);

//    root->left->left->left = new TreeNode(8);
//    root->left->left->right = new TreeNode(9);
//    root->left->right->left = new TreeNode(10);
//    root->left->right->right = new TreeNode(11);
//    root->right->left->left = new TreeNode(12);
//    root->right->left->right = new TreeNode(13);
//    root->right->right->left = new TreeNode(14);
//    root->right->right->right = new TreeNode(15);

//    print2D(root);

//    return 0;
// }

// This code is contributed by rathbhupendra


// 深度优先遍历 DFS


class Solution
{
public:
   vector<TreeNode *> res;

   vector<TreeNode *> generateTrees(int n)
   {
      bool used[n];
      for (int i = 0; i < n; i++)
      {
         used[i] = false;
      }

      for (int i = 0; i < n; i++)
      {
         cout << "main for loop i\t\t\t" << i << "\n\n";
         used[i] = true;
         TreeNode *root = new TreeNode(i + 1);
         TreeNode *real_root = root;
         int depth = 0;
         back_trace(real_root, root, 0, n, used, depth, n);
         used[i] = false;
         cout<<"\n";
      }
      return res;
   }

   void back_trace(TreeNode *root, TreeNode *tree, int lrange, int rrange,  bool used[], int depth, int n)
   {
      cout << "\n begin a new recurrsive function!\n";
      cout << "depth\t\t" << depth << "\n";
      cout << "tree\t\t" << tree->val << "\n";
      cout<<"\n";

      for(int i=0; i<n; i++)
      {
         if(used[i]){continue;}
         else{break;}
         
         res.push_back(root);
         return;
      }

      for (int i = lrange; i < tree->val - 1; i++)
      {
         cout << "below loop i\t" << i + 1<< "\n";
         if (!used[i])
         {
            cout << "pass loop i\t" << i + 1<< "\n";
            TreeNode *lchild = new TreeNode(i + 1);
            tree->left = lchild;
            used[i] = true;
            back_trace(root, lchild, lrange, tree->val, used, depth + 1, n);
            used[i] = false;
         }
      }

      for (int i = tree->val; i < rrange; i++)
      {
         cout << "beyond loop i\t" << i+1 << "\n";
         if (!used[i])
         {
            cout << "pass loop i\t" << i+1 << "\n";
            TreeNode *rchild = new TreeNode(i + 1);
            tree->right = rchild;
            used[i] = true;
            back_trace(root, rchild, tree->val, rrange, used, depth + 1, n);
            used[i] = false;
         }
      }

      cout<<"\n\n";
      // return root;
   }
};


int main()
{
   int n = 3;
   Solution s;
   vector<TreeNode *> res= s.generateTrees(n);

   for(int i=0; i<res.size(); i++)
   {
      print2D(res[i]);
      cout<<"==========================";
   }
   return 0;
}