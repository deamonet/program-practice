"""
129. 求根到叶子节点数字之和
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
通过次数32,051提交次数49,942
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sumNumbers(self, root):
        self.res = 0
        self.pre_traversal(root, 0)
        return self.res
        
        
    def pre_traversal(self, root, value):
        if root == None:
            return
        elif root.left == None and root.right == None:
            value = value * 10 + root.val
            self.res += value
            return
        else:
            value = value * 10 + root.val
            self.pre_traversal(root.left, value)
            self.pre_traversal(root.right, value)



# 建立二叉树是以层序遍历方式输入，节点不存在时以 'None' 表示
def creatTree(nodeList):
    if nodeList[0] == None:
        return None
    head = TreeNode(nodeList[0])
    Nodes = [head]
    j = 1
    for node in Nodes:
        if node != None:
            node.left = (TreeNode(
                nodeList[j]) if nodeList[j] != None else None)
            Nodes.append(node.left)
            j += 1
            if j == len(nodeList):
                return head
            node.right = (TreeNode(
                nodeList[j])if nodeList[j] != None else None)
            j += 1
            Nodes.append(node.right)
            if j == len(nodeList):
                return head



if __name__ == "__main__":
    nodeList = [1, 2, 3, 4]
    root = creatTree(nodeList)
    s= Solution()
    print(s.sumNumbers(root))
