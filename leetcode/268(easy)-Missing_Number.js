var missingNumber = function(nums) {
  const sortedNums = nums.sort((a, b) => a - b)
  const max = sortedNums[sortedNums.length - 1]
  for (var i = 0; i < max; i++) {
      // 연속되지 않으면 i가 정답
      if (sortedNums[i] != i) {
          return i
      }
  }
  // 모두 연속하면 n이 길이와 같기 때문에 length를 return
  return sortedNums.length
};