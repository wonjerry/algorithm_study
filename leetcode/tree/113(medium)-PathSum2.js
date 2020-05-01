/**
 * @param {TreeNode} node
 * @return {boolean}
 */
function isLeaf(node) {
  return node && !node.left && !node.right
}

/**
* @param {TreeNode} root
* @param {number} sum
* @return {number[][]}
*/
var pathSum = function (root, sum) {
  if (root === null) {
    return []
  }
  if (isLeaf(root)) {
    return sum - root.val === 0 ? [[root.val]] : []
  }
  const result = []
  const leftResults = pathSum(root.left, sum - root.val)
  for (let leftResult of leftResults) {
    result.push([root.val, ...leftResult])
  }
  const rightResults = pathSum(root.right, sum - root.val)
  for (let rightResult of rightResults) {
    result.push([root.val, ...rightResult])
  }
  return result
};

function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}
