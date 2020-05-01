/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function (matrix) {
  const d = []
  // 초기화
  for (let i = 0; i < matrix.length; i++) {
    d.push([])
    for (let j = 0; j < matrix[i].length; j++) {
      d[i].push(-1)
    }
  }

  for (let y = matrix.length - 1; y >= 0; y--) {
    for (let x = matrix[y].length - 1; x >= 0; x--) {
      validateSquare(matrix, d, y, x)
    }
  }

  let max = 0
  for (let i = 0; i < d.length; i++) {
    max = Math.max(max, ...d[i])
  }

  return max * max
};

/**
 * @param {character[][]} matrix
 * @param {number[][]} d
 * @param {number} yIndex
 * @param {number} xIndex
 * @return {number}
 */
function validateSquare(matrix, d, yIndex, xIndex) {
  if (xIndex < 0 || yIndex < 0) {
    return -1
  }

  if (d[yIndex][xIndex] !== -1) {
    return d[yIndex][xIndex]
  }

  if (matrix[yIndex][xIndex] === '0') {
    return d[yIndex][xIndex] = 0
  }

  const top = validateSquare(matrix, d, yIndex - 1, xIndex)
  const left = validateSquare(matrix, d, yIndex, xIndex - 1)
  const topLeft = validateSquare(matrix, d, yIndex - 1, xIndex - 1)

  if (top === -1 || left === -1 || topLeft === - 1) {
    return d[yIndex][xIndex] = Number(matrix[yIndex][xIndex])
  }

  if (left === top && top === topLeft) {
    return d[yIndex][xIndex] = left + 1
  }

  return d[yIndex][xIndex] = Math.min(left, top, topLeft) + 1
}
