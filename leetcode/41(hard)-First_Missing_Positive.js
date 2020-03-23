var firstMissingPositive = function(nums) {
  // 음수인 경우 제외
  const positiveNums = nums.filter((num) => num > 0)
  // 모두 음수이면 정답은 1
  if (positiveNums.length == 0) return 1

  const min = Math.min(...positiveNums)
  const max = Math.max(...positiveNums)

  // 최소값이 1이 아니면 정답은 1
  if (min != 1) return 1

  const hashSet = {}
  for (var i = 0; i < positiveNums.length; i++) {
      hashSet[positiveNums[i]] = positiveNums[i]
  }
  // min부터 max까지 돌면서 연속되지 않으면 return
  for (var i = min; i <= max; i++) {
      if (!hashSet[i]) return i
  }

  // min(1) ~ max(n) 까지 모두 연속한다면 length +1
  return Object.keys(hashSet).length + 1
}; 