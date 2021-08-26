function searchInsertPosition(nums, target) {
  // 리니어하게 찾으면 O(N)
  // 이분탐색으로 하면 O(logN)
  let left = 0
  let right = nums.length - 1
  let mid = 0
  while(left <= right) {
    mid = Math.floor((left + right) / 2)
    if (nums[mid] === target) {
      return mid
    }
    if (nums[mid] < target) {
      left = mid + 1
    } else if(nums[mid] > target) {
      right = mid - 1
    }
  }
  return right + 1
}
