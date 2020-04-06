
// Tree는 무적권 recursive하다
// 현재 tree의 subtree의 모음으로 생각하고 recursive하게 생각!!!!!
// root또한 결국 subtree이다.

// Solution
public static boolean isSymmetric(TreeNode root) {
  return isMirror(root, root);
}

public static boolean isMirror(TreeNode t1, TreeNode t2) {
  if (t1 == null && t2 == null) {
    return true;
  }

  if (t1 == null || t2 == null) {
    return false;
  }

  return (t1.val == t2.val)
      && isMirror(t1.left, t2.right)
      && isMirror(t1.right, t2.left);
}

// My answer
public static boolean isSymmetric(TreeNode root) {
  if (root == null) {
    return true;
  }
  Queue<TreeNode> q = new ArrayDeque<>();
  if (root.left == null && root.right == null) {
    return true;
  }
  if (root.left == null || root.right == null) {
    return false;
  }
  q.add(root.left);
  q.add(root.right);

  return checkSymmetric(q);
}

public static boolean checkSymmetric(Queue<TreeNode> q) {
  ArrayList<TreeNode> nodes = new ArrayList<>();
  while(!q.isEmpty()) {
    nodes.add(q.poll());
  }

  int length = nodes.size() / 2;
  for(int i = 0; i < length; i++) {
    if (nodes.get(i).val != nodes.get(nodes.size() - 1 - i).val) {
      return false;
    }
  }

  if (nodes.stream().allMatch(treeNode -> treeNode.left == null && treeNode.right == null)) {
    return true;
  }

  for(TreeNode node: nodes) {
    if (node.left == null) {
      q.add(new TreeNode(-1));
    } else {
      q.add(node.left);
    }
    if (node.right == null) {
      q.add(new TreeNode(-1));
    } else {
      q.add(node.right);
    }
  }

  return checkSymmetric(q);
}
