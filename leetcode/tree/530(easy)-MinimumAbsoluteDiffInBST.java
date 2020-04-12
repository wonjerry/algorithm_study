/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public int getMinimumDifference(TreeNode root) {
      if (root == null) {
          return Integer.MAX_VALUE;
      }
      int diff = traverse(root.left, root);
      diff = Math.min(diff, traverse(root.right, root));

      return Math.min(diff, Math.min(getMinimumDifference(root.left), getMinimumDifference(root.right)));
  }

  public int traverse(TreeNode root, TreeNode target) {
      if (root == null) {
          return Integer.MAX_VALUE;
      }
      int diff = Math.abs(root.val - target.val);
      diff = Math.min(diff, traverse(root.left, target));
      diff = Math.min(diff, traverse(root.right, target));
      return diff;
  }
}
