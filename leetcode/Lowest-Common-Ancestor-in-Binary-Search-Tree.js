/**
 * 
 * lowest common ancestor: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 * 
 * 공통조상을 찾는 문제는 좀 어려운 문제이다. 그러나 BST의 특성을 이용한다면 조금 수월해진다.
 * 만약 두 값이 현재 노드의 값보다 크다면 오른쪽으로, 작다면 왼쪽으로 이동하면 된다.
 * 그러다가 한쪽은 작고 한쪽은 큰 상황이 벌어지거나 한쪽은 현재노드와 같고 한쪽은 크거나 같은, 즉 갈라지는 경우가 생긴다면
 * 그 노드가 바로 공통 조상임을 알 수 있다.
 * 
 * 따라서 결국 같이 오른쪽 또는 왼쪽을 가보다보면 정답을 알 수 있다.
 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
const lowestCommonAncestor = (root, p, q) => {
  if (root.val < p.val && root.val < q.val) {
    return lowestCommonAncestor(root.right, p, q)
  }

  if (root.val > p.val && root.val > q.val) {
    return lowestCommonAncestor(root.left, p, q)
  }

  return root
}
