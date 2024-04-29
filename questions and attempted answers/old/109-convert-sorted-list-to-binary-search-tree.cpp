/*
109. 有序链表转换二叉搜索树
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <string>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 分析，如果一共有n个元素，那么存在最大的k，p = Σ_{i=0}^{k} 2^i，使得n - p = m，m大于或等于0。
// 那么根节点选择是 p（从0计数的第p个节点作为根节点）。
// 无需递归

// 之前的分析错误，链表由于数量未知，实则不能用这种东西计算

// 利用快慢指针确定中间节点。
// 链表转成数组，直接确定中间节点。
// 利用中序遍历搜索二叉树的结果刚好就是一个升序的数组。


class Solution
{
public:
    TreeNode* triangle(ListNode *head)
    {
        TreeNode *root = new TreeNode(head->next->val);
        TreeNode *left_node = new TreeNode(head->val);
        TreeNode *right_node = new TreeNode(head->next->next->val);
        root->left = left_node;
        root->right = right_node;
        return root;
    }

    TreeNode* sortedListToBST(ListNode *head)
    {
        int sum=0;
        for(int i=0; sum<n; i++)
        {
            sum += 2^i;
        }

        ListNode *link_node = head;
        while()
        {
            
        }
    }
};