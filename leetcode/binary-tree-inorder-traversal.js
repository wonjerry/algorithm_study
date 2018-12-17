/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
const inorderTraversal = (root) => {
  if (root === null) {
      return []
  }

  let history = []
  history = history.concat(inorderTraversal(root.left))
  history.push(root.val)
  history = history.concat(inorderTraversal(root.right))

  return history
}
