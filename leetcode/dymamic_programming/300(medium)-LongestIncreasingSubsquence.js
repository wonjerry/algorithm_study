function lengthOfLIS(nums) {
  const d = new Array(nums.length).fill(1)
  // 0 ~ N까지 loop
  // index, index 이하의 값들 중, d의 값이 최대인 값을 구해서 d[i] + 1을 해줄꺼임

  for(let i = 0; i < nums.length; i++) {
    let maxLength = 0
    for(let j = 0; j < i; j++) {
      if (nums[j] < nums[i] && maxLength < d[j]) {
        maxLength = d[j]
      }
    }
    d[i] += maxLength
  }

  return Math.max(0, ...d)
}