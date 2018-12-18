/**
 *
 * subsets: https://leetcode.com/problems/subsets/submissions/
 *
 * 이 문제는 모든 경우의 수를 찾는 문제인데, 재귀적으로 생각하면 좀 쉽게 해결할 수 있다.
 * 만약 [1, 2, 3]이 있다고 하자, 이때 모든 경우의 수는 [1] + subsets([2, 3])이라고 생각할 수 있다.
 * 즉 나를 두고 나머지 부분 문제를 해결하고 나서 나를 모든 경우에 붙여 넣으면 된다!
 */

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const subsets = (nums, start = 0) => {
  const length = nums.length
  let result = [[]]

  for (let i = start; i < length; i++) {
    const subResult = subsets(nums, i + 1)
    result = result.concat(subResult.map((arr) => {
      arr.push(nums[i])
      return arr
    }))
  }

  return result
}
