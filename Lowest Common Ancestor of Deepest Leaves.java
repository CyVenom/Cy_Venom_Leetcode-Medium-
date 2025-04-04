class Solution {
    private int maxDepth = -1;
    private TreeNode lca = null;

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        dfs(root, 0);
        return lca;
    }

    private int dfs(TreeNode node, int depth) {
        if (node == null) return depth - 1;
        maxDepth = Math.max(maxDepth, depth);
        int left = dfs(node.left, depth + 1);
        int right = dfs(node.right, depth + 1);
        if (left == maxDepth && right == maxDepth) {
            lca = node;
        }
        return Math.max(left, right);
    }
}
