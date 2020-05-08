/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
  const sums = new Array(nums.length)
  sums[0] = nums[0]
  for(let i = 1; i < nums.length; i++) {
      sums[i] = sums[i - 1] + nums[i]
  }
  this.sums = sums
  this.nums = Array.from(nums)
};

/**
* @param {number} i
* @param {number} j
* @return {number}
*/
NumArray.prototype.sumRange = function(i, j) {
  return this.sums[j] - this.sums[i] + this.nums[i]
};

/**
* Your NumArray object will be instantiated and called as such:
* var obj = new NumArray(nums)
* var param_1 = obj.sumRange(i,j)
*/