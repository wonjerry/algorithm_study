/**
 * Peek-index-in-a-Mountain-Array: https://leetcode.com/problems/peak-index-in-a-mountain-array
 * 
 * 그냥 리니어하게 탐색할 수도 있지만 이분탐색을 사용하면 O(logN)만에 해결가능하다.
 */

const checkRange = (index, size) => {
  return 0 <= index && index < size
}

/**
 * @param {number[]} A
 * @return {number}
 */
const peakIndexInMountainArray = (A) => {
  const size = A.length
  let start = 0
  let end = size - 1
  let mid = Math.floor((start + end) / 2)

  while (start <= end) {
    mid = Math.floor((start + end) / 2)
    
    if (checkRange(mid - 1, size) && checkRange(mid + 1, size) && A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
      break
    }

    if (checkRange(mid + 1, size) && A[mid] < A[mid + 1]) {
      start = mid + 1
    }

    if (checkRange(mid - 1, size) && A[mid - 1] < A[mid]) {
      end = mid - 1
    }
  }

  return mid
}