function sortColors(nums) {
  let countForZero = 0
  let countForOne = 0
  for(const num of nums) {
    if (num === 0) countForZero++
    if (num === 1) countForOne++
  }
  for(let i = 0; i < nums.length; i++) {
    if (i < countForZero) {
      nums[i] = 0
    } else if (i < countForZero + countForOne) {
      nums[i] = 1
    } else {
      nums[i] = 2
    }
  }
}