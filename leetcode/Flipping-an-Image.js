/**
 * Flipping an image: https://leetcode.com/problems/flipping-an-image/submissions/
 */

/**
 * @param {number[][]} A
 * @return {number[][]}
 */
const flipAndInvertImage = (A) => {
  return A.map((row) => {
    return row.reverse().map((data) => 1 - data )
  })
}
