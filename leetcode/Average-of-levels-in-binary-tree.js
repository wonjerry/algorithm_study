/**
 * 
 * average-of-levels-in-binary-tree: https://leetcode.com/problems/average-of-levels-in-binary-tree/
 * 
 * 현재 큐가 비면 childrenQueue에 있던 애들을 가져오고 계속해서 레별별로 평균을 연산하여 저장한다.
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
 * @return {number[]}
 */
const averageOfLevels = (root) => {
  let queue = []
  let childrenQueue = []
  const result = []
  childrenQueue.push(root)
  while(queue.length || childrenQueue.length) {
    if (queue.length === 0) {
        result.push(childrenQueue.reduce((acc, node) => acc += node.val, 0) / childrenQueue.length)
        queue = Array.from(childrenQueue)
        childrenQueue = []
    }
    const node = queue.shift()
    if (node.left) {
      childrenQueue.push(node.left)
    }

    if (node.right) {
      childrenQueue.push(node.right)
    }
  }

  return result
}
