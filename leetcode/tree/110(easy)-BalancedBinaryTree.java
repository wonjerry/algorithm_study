/**
 * Balanced tree란 두 subtree의 높이 차가 1을 넘으면 안됀다 (<= 1)
 * 또한! 두 subtree가 모두 balanced tree여야만 한다!!! <- 이것때매 삽질함 ㅠㅠㅠ
 *
 * 어쨌든 결국 이 문제도 tree는 subtree의 모음이다 라는 공식으로 해결!!
 */

public static boolean isBalanced(TreeNode root) {
  if (root == null) {
    return true;
  }
  if (!isBalanced(root.left) || !isBalanced(root.right)) {
    return false;
  }
  int leftHeight = calculateHeight(root.left);
  int rightHeight = calculateHeight(root.right);
  return Math.abs(leftHeight - rightHeight) <= 1;
}

public static int calculateHeight(TreeNode root) {
  if (root == null) {
    return 0;
  }
  return Math.max(calculateHeight(root.left), calculateHeight(root.right)) + 1;
}