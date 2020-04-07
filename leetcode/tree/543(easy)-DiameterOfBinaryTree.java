/**
 * Tree의 지름을 구하는 문제.
 *
 * 자칫 왼쪽의 height와 오른쪽의 height를 더하는 것으로 생각할 수 있지만, 예외 케이스가 존재한다.
 * 만약 왼쪽 자식의 height는 1인데 오른쪽 자식의 오른쪽 자식과 왼쪽 자식의 height가 각각 10이라면 당얀히
 * 오른쪽 자식의 오른쪽, 왼쪽 height를 더하는게 tree의 지름이다.
 *
 * 따라서 이 문제를 해결해기 위해서, 모든 tree node를 순회하면서 왼쪽, 오른쪽 height를 구하여 더하고, 왼쪽, 오른쪽에 대해서 지름을 구한것의 최댓값을 구한다.
 */


class Solution {
  public int diameterOfBinaryTree(TreeNode root) {
      if (root == null) {
        return 0;
      }
      return Math.max(Math.max(height(root.left) + height(root.right), diameterOfBinaryTree(root.left)), diameterOfBinaryTree(root.right));
  }

  public int height(TreeNode root) {
      if (root == null) {
        return 0;
      }

      return Math.max(height(root.left), height(root.right)) + 1;
    }
}

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int x) { val = x; }
}