/*
 * @lc app=leetcode.cn id=617 lang=java
 *
 * [617] 合并二叉树
 *
 * https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (78.88%)
 * Likes:    938
 * Dislikes: 0
 * Total Accepted:    264.3K
 * Total Submissions: 335K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给你两棵二叉树： root1 和 root2 。
 * 
 * 
 * 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为
 * null 的节点将直接作为新二叉树的节点。
 * 
 * 返回合并后的二叉树。
 * 
 * 注意: 合并过程必须从两个树的根节点开始。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * 输出：[3,4,5,5,4,null,7]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root1 = [1], root2 = [1,2]
 * 输出：[2,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两棵树中的节点数目在范围 [0, 2000] 内
 * -10^4 <= Node.val <= 10^4
 * 
 * 
 */
import java.util.Objects;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
// @lc code=start
class Solution {
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2){
        if      ( Objects.equals(root1, null) &&  Objects.equals(root2, null)){return null;}
        else if ( Objects.equals(root1, null) && !Objects.equals(root2, null)){return root2;}
        else if (!Objects.equals(root1, null) &&  Objects.equals(root2, null)){return root1;}
        else{
            root1.val += root2.val;
            root1.left = mergeTrees(root1.left, root2.left);
            root1.right = mergeTrees(root1.right, root2.right);
            return root1;
        }
    }
    
    public TreeNode mergeTrees_wrong(TreeNode root1, TreeNode root2) {
        TreeNode root = new TreeNode();
        System.out.println(Objects.equals(root, null));
        // root = null;
        // System.out.println(Objects.equals(root, null));
        // TreeNode parent = new TreeNode();
        dfs(root1, root2, root);
        return root;
    }

    public void dfs(TreeNode root1, TreeNode root2, TreeNode node){
        if      ( Objects.equals(root1, null) &&  Objects.equals(root2, null)){
            System.out.println("s 1");
        }
        else if ( Objects.equals(root1, null) && !Objects.equals(root2, null)){
            System.out.println("s 2");
            node = root2;
        }
        else if (!Objects.equals(root1, null) &&  Objects.equals(root2, null)){
            System.out.println("s 3");
            node = root1;
        }
        else{
            System.out.println("s 4");
            node = (TreeNode) node;
            node.val = root1.val + root2.val;
            node.left = null;
            node.right = null;
            dfs(root1.left, root2.left, node.left);
            dfs(root1.right, root2.right, node.right);
        }
    }

    public void dfs_no_way(TreeNode root1, TreeNode root2, TreeNode node, TreeNode parent){
        if      ( Objects.equals(root1, null) &&  Objects.equals(root2, null)){
            System.out.println("s 1");
            node = null;
        }
        else if ( Objects.equals(root1, null) && !Objects.equals(root2, null)){
            System.out.println("s 2");
            node.val = root2.val;
            node.left = root2.left;
            node.right = root2.right;
        }
        else if (!Objects.equals(root1, null) &&  Objects.equals(root2, null)){
            System.out.println("s 3");
            node.val = root1.val;
            node.left = root1.left;
            node.right = root1.right;
        }
        else{
            System.out.println("s 4");
            node.val = root1.val + root2.val;
            node.left = new TreeNode();
            node.right = new TreeNode();
            dfs_no_way(root1, root2, node, parent);
            dfs_no_way(root1, root2, node, parent);
        }
    }
}
// @lc code=end