/**
 * @param {number[]} nums
 * @return {number}
 */
const lengthOfLIS = (nums) => {
  if (nums.length === 0) {
    return 0
  }

  const d = Array(nums.length).fill(1)
  const size = nums.length
  let max = 1

  for (let i = size - 1; i >= 0; i--) {
    for (let j = i + 1; j < size; j++) {
      if (nums[i] < nums[j]) {
        d[i] = Math.max(d[i], 1 + d[j])
      }
      max = Math.max(max, d[i])
    }
  }
  return max
}
