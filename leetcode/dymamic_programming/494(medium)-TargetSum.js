/**
 * @param {number[]} nums
 * @param {number} sum
 * @return {number}
 */
 var findTargetSumWays = function(nums, sum) {
  const d = new Array(nums.length)
  for(let i = 0; i < d.length; i++) {
    d[i] = []
  }
  return calculateTargetSumCount(nums, nums.length - 1, sum, d)
};

/**
 * @param {number[]} nums
 * @param {number} index
 * @param {number} sum
 * @param {number[]} d
 * @return {number}
 */
function calculateTargetSumCount(nums, index, sum, d) {
  if (index < 0) {
    return sum === 0 ? 1 : 0
  }
  if (d[index][sum]) {
    return d[index][sum]
  }
  const minusResult = calculateTargetSumCount(nums, index - 1, sum - nums[index], d)
  const plusResult = calculateTargetSumCount(nums, index - 1,  sum + nums[index], d)
  return d[index][sum] = minusResult + plusResult
}
