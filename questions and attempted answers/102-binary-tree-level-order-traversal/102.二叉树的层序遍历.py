#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
#
from typing import List
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ret = []
        if root == None:
            return []
        
        que = deque()
        que.append(root)
        while que:
            ls = []
            for i in range(len(que)):
                node = que.popleft()
                ls.append(node.val)
                if node.left:
                    que.append(node.left)

                if node.right:
                    que.append(node.right)

            ret.append(ls)
        
        return ret
# @lc code=end