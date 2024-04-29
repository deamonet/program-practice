import java.util.Objects;

public class BalancedBinaryTree {
    public boolean IsBalanced_Solution(TreeNode root) {
        if (Objects.isNull(root)) {
            return true;
        } else {
            return IsBalanced_Solution(root.left) && IsBalanced_Solution(root.right);
        }
    }

    public int treeHigh(TreeNode root) {
        if (Objects.isNull(root)) {
            return 0;
        } else if (Objects.isNull(root.left)) {
            return treeHigh(root.right);
        } else if (Objects.isNull(root.right)) {
            return treeHigh(root.left);
        } else {
            return 1 + max(treeHigh(root.left), treeHigh(root.right));
        }
    }
}
