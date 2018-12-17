/**
 * 
 * maximum-depth-of-binary-tree: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * dfs로 tree의 높이를 찾는 문제이다. 
 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

const dfs = (node, maxDepth) => {
  if (node === null) {
    return maxDepth === 0 ? 0 : maxDepth - 1
  }

  return Math.max(dfs(node.left, maxDepth + 1), dfs(node.right, maxDepth + 1), maxDepth + 1)
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
const maxDepth = (root) => {
  return dfs(root, 0)
}
