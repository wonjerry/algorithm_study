/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums) {
  const subArray = []
  let zeroCount = 0
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== 0) {
      subArray.push(nums[i])
    } else {
      zeroCount++
    }
  }
  for (let i = 0; i < zeroCount; i++) {
    subArray.push(0)
  }
  for (let i = 0; i < nums.length; i++) {
    nums[i] = subArray[i]
  }

}
