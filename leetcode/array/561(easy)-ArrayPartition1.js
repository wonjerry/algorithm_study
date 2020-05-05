/**
 * @param {number[]} nums
 * @return {number}
 */
function arrayPairSum(nums) {
  let sumOfMins = 0
  const sortedArray = nums.sort((a, b) => a - b)
  for (let i = 0; i < sortedArray.length; i += 2) {
    sumOfMins += sortedArray[i]
  }
  return sumOfMins
}
