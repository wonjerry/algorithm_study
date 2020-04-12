
class Solution {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
      TreeNode a = p;
  TreeNode b = q;
  int aHeight = depth(root, a, 0);
  int bHeight = depth(root, b, 0);

  while(aHeight != bHeight) {
    if (aHeight > bHeight) {
      a = findParent(root, a);
      aHeight--;
    }

    if (aHeight < bHeight) {
      b = findParent(root, b);
      bHeight--;
    }
  }

  if (a == null) {
    return root;
  }

  while(a.val != b.val) {
    a = findParent(root, a);
    b = findParent(root, b);
  }

  return a;
  }

  public TreeNode findParent(TreeNode root, TreeNode child) {
  if (root == null) {
    return null;
  }

  if (root.left != null && root.left.val == child.val) {
    return root;
  }

  if (root.right != null && root.right.val == child.val) {
    return root;
  }

  TreeNode left = findParent(root.left, child);
  TreeNode right = findParent(root.right, child);

  return left != null ? left : right;
}

public int depth(TreeNode root, TreeNode target, int depth) {
  if (root == null) {
    return 0;
  }

  if (root.val == target.val) {
    return depth;
  }

  return Math.max(depth(root.left, target, depth + 1), depth(root.right, target, depth + 1));
}
}