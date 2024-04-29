import java.util.Queue;
import java.util.List;
import java.util.ArrayList;
import java.util.ArrayDeque;
import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层序遍历
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<>();
        Queue<TreeNode> que = new ArrayDeque<>();
        if (root == null){return ret;}
        que.add(root);
        while (!que.isEmpty()){
            List<Integer> level = new ArrayList<>();
            for (int i=0; i<que.size(); i++){
                // 这里写错了，que的长度在循环里会变化，导致错误
                // 这里的长度是只每一层的元素的个数
                TreeNode node = que.poll();
                level.add(node.val);
                if (node.left != null){que.add(node.left);}
                if (node.right != null){que.add(node.right);}
            }
            ret.add(level);
        }        
        return ret;
    }

    public List<List<Integer>> levelOrder2(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> queue = new ArrayDeque<>();
        if (root != null) {
            queue.add(root);
        }
        while (!queue.isEmpty()) {
            int n = queue.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < n; i++) { 
                TreeNode node = queue.poll();
                level.add(node.val);
                if (node.left != null) {queue.add(node.left);}
                if (node.right != null) {queue.add(node.right);}
            }
            res.add(level);
        }
        return res;
    }    
}
// @lc code=end
