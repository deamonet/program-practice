/*
110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
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


// 注意关键词：高度平衡的二叉树。含义是每一个节点的左右子树的高度差不超过1.

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int left_height = height(root->left);
            int right_height = height(root->right);
            if (left_height >= right_height)
            {
                return left_height + 1;
            }
            else
            {
                return right_height + 1;
            }
        }
    }

    bool isBalanced(TreeNode *root)
    {
        int left_height = height(root->left);
        int right_height = height(root->right);
        int res = abs(left_height - right_height);
        if (res <= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



// 没有看太懂的一个解法
/*
附上一个我觉得很啰嗦的解法...但是我觉得树的递归大部分都可以这么套路的解决，相当于一个解题模版（初学数据结构的菜鸡
模版一共三步，就是递归的三部曲：
找终止条件：什么时候递归到头了？此题自然是root为空的时候，空树当然是平衡的。
思考返回值，每一级递归应该向上返回什么信息？参考我代码中的注释。
单步操作应该怎么写？因为递归就是大量的调用自身的重复操作，因此从宏观上考虑，只用想想单步怎么写就行了，左树和右树应该看成一个整体，即此时树一共三个节点：root，root.left，root.right。
如果独立写递归函数有困难的，可以参考一下我写的一个博客，附有详细的图文介绍：博客链接
class Solution {
    //这个ReturnNode是参考我描述的递归套路的第二步：思考返回值是什么
    //一棵树是BST等价于它的左、右俩子树都是BST且俩子树高度差不超过1
    //因此我认为返回值应该包含当前树是否是BST和当前树的高度这两个信息
    private class ReturnNode{
        boolean isB;
        int depth;
        public ReturnNode(int depth, boolean isB){
            this.isB = isB;
            this.depth = depth;
        }
    }
    //主函数
    public boolean isBalanced(TreeNode root) {
        return isBST(root).isB;
    }
    //参考递归套路的第三部：描述单次执行过程是什么样的
    //这里的单次执行过程具体如下：
    //是否终止?->没终止的话，判断是否满足不平衡的三个条件->返回值
    public ReturnNode isBST(TreeNode root){
        if(root == null){
            return new ReturnNode(0, true);
        }
        //不平衡的情况有3种：左树不平衡、右树不平衡、左树和右树差的绝对值大于1
        ReturnNode left = isBST(root.left);
        ReturnNode right = isBST(root.right);
        if(left.isB == false || right.isB == false){
            return new ReturnNode(0, false); 
        }
        if(Math.abs(left.depth - right.depth) > 1){
            return new ReturnNode(0, false);
        }
        //不满足上面3种情况，说明平衡了，树的深度为左右俩子树最大深度+1
        return new ReturnNode(Math.max(left.depth, right.depth) + 1, true);
    }
}
*/

// 递归解决，计算子树高度， - 1表示子树已经不平衡了

class Solution
{
public
    boolean isBalanced(TreeNode root)
    {
        return height(root) >= 0;
    }

private
    int height(TreeNode root)
    {
        if (root == null)
            return 0;
        int lh = height(root.left), rh = height(root.right);
        if (lh >= 0 && rh >= 0 && Math.abs(lh - rh) <= 1)
        {
            return Math.max(lh, rh) + 1;
        }
        else
        {
            return -1;
        }
    }
}