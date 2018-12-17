/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const search = (nums, target) => {
  const size = nums.length
  let start = 0
  let end = size - 1
  let mid = Math.floor((start + end) / 2)

  while (start <= end) {
    mid = Math.floor((start + end) / 2)
    if (nums[mid] === target) {
      return mid
    }

    if (nums[mid] < target) {
      start = mid + 1
    }

    if (nums[mid] < target) {
      end = mid - 1
    }
  }

  return -1
}
