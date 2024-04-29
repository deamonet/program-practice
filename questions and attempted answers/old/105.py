"""
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
"""



# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None



"""
执行用时 :376 ms, 在所有 Python3 提交中击败了12.69%的用户
内存消耗 :87.8 MB, 在所有 Python3 提交中击败了11.11%的用户

C++如果按这个思路写，会报bad_alloc的错误
"""

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if(len(preorder) == 0):
            return
        elif(len(preorder) == 1):
            node = TreeNode(preorder[0])
            return node
        
        root_value = preorder[0]
        for i, value in enumerate(inorder):
            if value == root_value:
                pos = i
                print('yes')
                break
        
        root = TreeNode(root_value)
        preorder[1:]

        root.left = self.buildTree(preorder[1:pos+1], inorder[:pos])
        root.right = self.buildTree(preorder[pos+1:], inorder[pos+1:])

        return root
