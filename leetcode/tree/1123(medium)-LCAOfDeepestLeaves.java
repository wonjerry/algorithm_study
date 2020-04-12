class Solution {
  public TreeNode lcaDeepestLeaves(TreeNode root) {
      if (root == null) {
        return root;
      }

      int leftHeight = height(root.left);
      int rightHeight = height(root.right);
      if (leftHeight == rightHeight) {
        return root;
      }
      return lcaDeepestLeaves(leftHeight > rightHeight ? lcaDeepestLeaves(root.left) : lcaDeepestLeaves(root.right));
  }

  public static int height(TreeNode root) {
      if (root == null) {
        return 0;
      }
      return Math.max(height(root.left), height(root.right)) + 1;
    }
}