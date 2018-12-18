const findMinimumNumber = (n, d) => {
  if (d[n] !== -1) {
    return d[n]
  }

  if (n <= 0) {
    return 0
  }

  const maxSquareNumber = Math.floor(Math.sqrt(n))
  let min = Number.MAX_SAFE_INTEGER
  for (let i = maxSquareNumber; i > 0; i--) {
    if (n - i * i === 0) {
      min = 1
      break
    }

    if (n - i * i > 0) {
      min = Math.min(min, findMinimumNumber(n - i * i) + 1)
    }
  }

  return d[n] = min
}

/**
 * @param {number} n
 * @return {number}
 */
const numSquares = (n) => {
  const d = Array(n + 1).fill(-1)
  return findMinimumNumber(n, d)
}
