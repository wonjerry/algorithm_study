/**
 * 
 * is-Toeplitz-Matrix: https://leetcode.com/problems/toeplitz-matrix/submissions/
 * 
 * 대각선의 모든 원소가 같은 원소인지 확인하는 문제이다.
 */

/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
const isToeplitzMatrix = (matrix) => {
  const rows = matrix.length
  const cols = matrix[0].length
  for (let i = 0; i < rows - 1; i++) {
      for (let j = 0; j < cols - 1; j++) {
          if (matrix[i][j] !== matrix[i + 1][j + 1]) {
              return false
          }
      }
  }
  
  return true
}