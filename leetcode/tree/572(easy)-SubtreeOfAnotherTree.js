/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} s
 * @param {TreeNode} t
 * @return {boolean}
 */
var isSubtree = function(s, t) {
  // s tree 안에서 t의 구조를 가지는 subtree 찾기
  // 1. s 안에서 t의 root와 같은 값을 가지는 노드를 찾는다.
  // 1-1 만약 같은 값을 가지는 노드가 없다면 false
  // 2. 두 tree를 traverse한 결과를 가져온다. (List)
  // 3. 정확히 같은 List인지를 체크해서 맞다면 true, 아니면 false
  if (s === null) {
      return t === null
  }
  return checkSameTree(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t)
};

/**
* @param {TreeNode} s
* @param {TreeNode} t
* @return {boolean}
*/
function checkSameTree(s, t) {
if (s === null && t === null) {
  return true
}

if (!(s !== null && t !== null)) {
  return false
}

return s.val === t.val && checkSameTree(s.left, t.left) && checkSameTree(s.right, t.right)
}
