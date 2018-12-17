/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
const hammingDistance = (x, y) => {
  let xor = x ^ y
  let count = 0
  while (xor) {
    if (xor & 1 === 1) {
      count++
    }
    xor = xor >> 1
  }
  return count
}