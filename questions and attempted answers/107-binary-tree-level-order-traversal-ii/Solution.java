import java.util.Queue;
import java.util.List;
import java.util.ArrayList;
import java.util.ArrayDeque;
import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=107 lang=java
 *
 * .get(107) 二叉树的层序遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<>();
        Queue<TreeNode> que = new ArrayDeque<>();
        if (root == null){return ret;}
        que.add(root);
        while (!que.isEmpty()){
            List<Integer> level = new ArrayList<>();
            int n = que.size();
            for (int i=0; i<n; i++){
                TreeNode node = que.poll();
                level.add(node.val);
                if (node.left != null){que.add(node.left);}
                if (node.right != null){que.add(node.right);}
            }
            ret.add(level);
        }
        
        int length = ret.size();
        List<Integer> temp;
        for (int i=0; i<length/2; i++){
            temp = ret.get(i);
            ret.set(i, ret.get(length-i-1));
            ret.set(length-i-1, temp);
        }
        return ret;
    }
}
// @lc code=end
