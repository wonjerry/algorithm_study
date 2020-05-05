// 이 문제를 해결하려면 중복되는 수가 있기때문에 무조건 sort를 해줘야 하고 거기서 searching을 해줘야 하기에
// 직접 sort와 binary search를 구현하였다.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */

function search(nums, target) {
  const sortedArray = Array.from(nums)
  divideAndQuenqer(sortedArray, 0, sortedArray.length - 1)
  // target number를 이분탐색을 통해 search 한다.
  const targetIndex = binarySearch(sortedArray, target)
  return targetIndex !== -1
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

function divideAndQuenqer(nums, start, end) {
  if (start >= end) {
    return
  }
  const mid = Number.parseInt((start + end) / 2)
  divideAndQuenqer(nums, start, mid)
  divideAndQuenqer(nums, mid + 1, end)
  mergeSort(nums, start, mid, mid + 1, end)
}

function mergeSort(nums, start1, end1, start2, end2) {
  let start1Index = start1
  let start2Index = start2
  const result = []
  while (start1Index <= end1 && start2Index <= end2) {
    if (nums[start1Index] === nums[start2Index]) {
      result.push(nums[start1Index++])
      result.push(nums[start2Index++])
    } else if (nums[start1Index] < nums[start2Index]) {
      result.push(nums[start1Index++])
    } else if (nums[start1Index] > nums[start2Index]) {
      result.push(nums[start2Index++])
    }
  }
  while (start1Index <= end1) {
    result.push(nums[start1Index++])
  }
  while (start2Index <= end2) {
    result.push(nums[start2Index++])
  }
  for (let i = start1; i <= end2; i++) {
    nums[i] = result[i - start1]
  }
}

