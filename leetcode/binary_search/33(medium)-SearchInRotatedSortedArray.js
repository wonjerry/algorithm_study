// 포인트는 length가 넘어가는 인덱스를 rotate하게 구하려면 %를 쓸 수 있다.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function sanitizeIndex(index, minValueIndex, length) {
  const sanitizedIndex = index + minValueIndex
  return sanitizedIndex % length
}

function search(nums, target) {
  // 최소값의 index를 구한다.
  let minValueIndex = 0
  let minValue = Number.MAX_SAFE_INTEGER
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] < minValue) {
      minValueIndex = i
      minValue = nums[i]
    }
  }
  // 최소값의 index만큼 왼쪽으로 shift한다.
  const shiftedArray = []
  for (let i = 0; i < nums.length; i++) {
    const index = sanitizeIndex(i, minValueIndex, nums.length)
    shiftedArray[i] = nums[index]
  }
  // target number를 이분탐색을 통해 search 한다.
  const targetIndex = binarySearch(shiftedArray, target)
  if (targetIndex === -1) {
    return targetIndex
  }
  return sanitizeIndex(targetIndex, minValueIndex, nums.length)
}

function binarySearch(nums, target) {
  let start = 0
  let end = nums.length - 1
  let mid = Number.parseInt((start + end) / 2)
  while (start <= end) {
    mid = Number.parseInt((start + end) / 2)
    if (target < nums[mid]) {
      end = mid - 1
    } else if (target > nums[mid]) {
      start = mid + 1
    } else {
      return mid
    }
  }
  return -1
}
