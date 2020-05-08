function rob(nums) {
  const d = []
  return go(nums, 0, d)
}

function go(nums, index, d) {
  if (index >= nums.length) {
    return d[index] = 0
  }
  if (d[index] !== undefined) {
    return d[index]
  }
  const skipHouse = go(nums, index + 1, d)
  const robHouse = nums[index] + go(nums, index + 2, d)
  return d[index] = Math.max(skipHouse, robHouse)
}
