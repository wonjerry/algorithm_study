/**
 *
 * @param {*} candidates
 * @param {*} target
 */

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
const combinationSum = (candidates, target) => {
  const size = candidates.length
  let result = []
  for (let i = 0; i < size; i++) {
    if (target - candidates[i] > 0) {
      const temp = combinationSum(candidates.slice(i), target - candidates[i])
      temp.forEach((ele) => {
        ele.push(candidates[i])
        result.push(ele)
      })
    }

    if (target - candidates[i] === 0) {
      result.push([candidates[i]])
    }
  }
  return result
}
