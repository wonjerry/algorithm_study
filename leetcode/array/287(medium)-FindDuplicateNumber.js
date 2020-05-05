// 단순하게 이렇게 풀어도 되지만, 지금은 시간복잡도가 O(N^2) 이고,
// Set을 이용하면 O(N)에 풀 수 있다.

/**
 * @param {number[]} nums
 * @return {number}
 */
function findDuplicate(nums) {
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i]
    for (let j = i + 1; j < nums.length; j++) {
      if (num === nums[j]) {
        return num
      }
    }
  }
  return -1
}
