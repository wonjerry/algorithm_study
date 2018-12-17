/**
 * 
 * invert-binary-tree: https://leetcode.com/problems/invert-binary-tree/
 * 
 * tree의 좌 우를 바꾸는 문제이다.
 * 각 sub트리로 내려가면서 좌 우를 바꿔주며 위로 올라오면 결국 모든 노드의 좌 우가 바뀔테니 재귀적으로 처리 해 주면 된다.
 * 주의할 점은 왼쪽 또는 오른쪽 노드가 있을때만 뭔가 값을 할당해 주는 것이 아니라 없을때는 null을 할당해줘야 한다는 점이다.
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
 * @return {TreeNode}
 */
const invertTree = (root) => {
  if (root === null) {
      return root
  }

  const leftChild = root.left
  const rightChild = root.right

  root.right = leftChild ? invertTree(leftChild) : null
  root.left = rightChild ? invertTree(rightChild) : null

  return root
}
