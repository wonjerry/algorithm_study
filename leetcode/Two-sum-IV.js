/**
 * 
 * Tow Sum IV: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 * 
 * 이 문제는 BST의 특성을 이용해서 탐색을 빠르게 하느냐가 관건인 문제이다.
 * 일반적으로 어떤 array에서 어떤 두 값을 찾으려면 N^2의 시간이 걸린다.
 * 하지만 BST라면 logN만에 원하는 target값을 찾을 수 있으므로
 * - Tree를 순회하면서
 * - 각 Node의 값을 target에서 빼고 남은 값이 tree에 있는지 없는지 확인한다.
 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

const isExistInBST = (root, now, target) => {
  if (root === null) {
    return false
  }
    
  if (root.val > target) {
    return isExistInBST(root.left, now, target)
  }

  if (root.val < target) {
    return isExistInBST(root.right, now, target)
  }

  return target !== now
}

const traversal = (root, node, k) => {
  if (node === null) {
    return false
  }

  if (isExistInBST(root, node.val, k - node.val)) {
    return true
  }

  return traversal(root, node.left, k) || traversal(root, node.right, k)
}

/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {boolean}
 */
const findTarget = (root, k) => {
  return traversal(root, root, k)

}
