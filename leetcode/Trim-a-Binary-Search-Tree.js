/**
 * Trim a binary tree: https://leetcode.com/problems/trim-a-binary-search-tree/
 * 이 문제는 Tree의 특성과 BST의 특성을 적절히 잘 조합하면 풀 수 있는 문제이다.
 * 
 * Tree의 특성: Tree는 작은 subtree의 모임이라는 것이고
 * BST의 특성: 어떤 값을 찾을 때 현재 노드의 값보다 작거나 크면 그 반대편은 철저하게 신경쓸 필요가 없다는점이다.
 * 
 * 이 문제에서는 L과 R이 주어졌을때 그 내부값만 존재하도록 하는 문제이다.
 * 만약 어떤 노드가 L, R의 범위 내에 없다면 어떻게 찾아야 할까?
 * 만약 L보다 작다면 그 노드를 포함한 해당 서브트리는 다 잘라내야한다.
 * 만약 R보다 크다면 그 노드를 포함한 해당 서브트리는 다 잘라내야 한다.
 * 두 범위내에 있는 노드라면 다시 재귀적으로 왼쪽, 오른쪽 자식 서브트리를 재귀적으로 넣어서 결과값을 가져온다.
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
 * @param {number} L
 * @param {number} R
 * @return {TreeNode}
 */
const trimBST = (root, L, R) => {
    if (!root) {
      return null
    }

    if (root.val < L) {
      return trimBST(root.right, L, R)
    }

    if (root.val > R) {
      return trimBST(root.left, L, R)
    }

    root.left = trimBST(root.left, L, R)
    root.right = trimBST(root.right, L, R)

    return root
}
