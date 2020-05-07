/**
 * 사실 이문제는 처음에는 엄청 어렵게 풀었다.
 * [0 ~ n-1]의 누적 합을 배열 sums 구한 후, sums[j] - sums[i] == i부터 j까지의 subarray의 합 이라는 가설을 세우고
 * 모든 경우의 수를 구해서 문제를 풀었고, O(N^2)의 시간 복잡도가 걸렸다.
 *
 * 사실 이건 dp 문제이기때문에 뭔가 점화식을 세워보면, d[i] = i로 끝나는 subArray의 합중 최대값 이라는 가설을 세우고,
 * d[i] = max(i-1로 끝나는 subArray의 합중 최대값 + 현재값, 현재값)이라는 점화식을 세울 수 있다.
 * 즉 이전 연속합을 이어갈 것인가, 아니면 새로 연속합을 시작할 것인가의 문제이다.
 *
 * d[i - 1] + 현재값이 현재값보다 작다는것은 결국 연속해서 더해봤자 작다는 의미이다.
 * 그러므로 현재값부터 새로히 연속합을 구하는것이 맞다.
 *
 * 사실 지금 온전히 이해가가는건 아니지만, 이후에 내공이 더 쌓이고 보면 아하 하는 순간이 올것이라 생각된다.
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  const d = new Array(nums.length)
  d[0] = nums[0]
  for(let i = 1; i < nums.length; i++) {
      d[i] = Math.max(d[i - 1] + nums[i], nums[i])
  }
  return Math.max(...d)
};