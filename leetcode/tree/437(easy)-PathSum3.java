/**
 * 이 문제는 모든 tree의 path 중, sum을 만족하는 path가 있는지 구하는 것이며, 꼭 root가 아닌, 중간 자식 노드부터 시작해도 된다.
 *
 * 이 문제를 해결하려면, sum에 대해서 root node부터 시작한 path, right, left node부터 시작한 path를 전부 계산 해주어야 한다.
 */

public class PathSum3 {
  public static int pathSum(TreeNode root, int sum) {
    int result = 0;
    if (root == null) {
      return result;
    }

    result = checkPath(root, sum);
    result += pathSum(root.left, sum);
    result += pathSum(root.right, sum);

    return result;
  }

  public static int checkPath(TreeNode root, int sum) {
    int result = 0;
    if (root == null) {
      return result;
    }
    if (sum - root.val == 0) {
      result++;
    }

    if (root.left != null) {
      result += checkPath(root.left, sum - root.val);
    }
    if (root.right != null) {
      result += checkPath(root.right, sum - root.val);
    }

    return result;
  }
}
