// 복합적 개념이 들어간 문제!!!!
// BST의 특성을 이용해서 sorting된 node list를 뽑이내고, 그걸 merge sort로 풀어내야 완벽한 풀이이다.

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {number[]}
 */
var getAllElements = function(root1, root2) {
    const nodes1 = []
    inorder(root1, nodes1)
    const nodes2 = []
    inorder(root2, nodes2)
    return mergeNodes(nodes1, nodes2)
};

/**
 * @param {TreeNode} root
 * @param {number[]} nodes
 * @return {number[]}
 */
function inorder(root, nodes) {
  if (root === null) {
    return
  }

  inorder(root.left, nodes)
  nodes.push(root.val)
  inorder(root.right, nodes)
}

/**
 * @param {number[]} nodes1
 * @param {number[]} nodes2
 * @return {number[]}
 */
function mergeNodes(nodes1, nodes2) {
  let index1 = 0
  let index2 = 0
  let result = []

  while(index1 !== nodes1.length && index2 !== nodes2.length) {
    const value1 = nodes1[index1]
    const value2 = nodes2[index2]
    if (value1 === value2) {
      result.push(value1)
      result.push(value2)
      index1++
      index2++
    } else if (value1 < value2) {
      result.push(value1)
      index1++
    } else {
      result.push(value2)
      index2++
    }
  }

  while(index1 !== nodes1.length) {
    result.push(nodes1[index1++])
  }

  while(index2 !== nodes2.length) {
    result.push(nodes2[index2++])
  }

  return result
}
