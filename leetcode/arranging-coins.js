/**
 *
 * arranging coins: https://leetcode.com/problems/arranging-coins
 *
 * 이 문제는 k번째 줄 까지의 합이 n보다 작은 그 범위를 찾는 문제이다.
 * 이런 경계값 찾는 문제는 보통 이분탐색을 통해서 그 경계까지 logN의 시간을 걸려서 올라가게 된다.
 *
 * 이때 중요한 것은 정답은 mid가 아니다. mid는 탐색 도중에 start가 end보다 커질때 또는 end가 start보다 작아질 때
 * 멈추게 되는데, mid는 그 경계값이라고 보장할 수 없다.
 *
 * 어떤 범위 n보다 작거나 같을 때 그때의 mid값을 따로 저장 해 두고 그것을 정답으로 해야한다.
 */


/**
 * @param {number} n
 * @return {number}
 */
const arrangeCoins = (n) => {
  let start = 0
  let end = n
  let mid = Math.floor((start + end) / 2)
  let ans = 0

  while (start <= end) {
    mid = Math.floor((start + end) / 2)
    coins = Math.floor((mid * (mid + 1)) / 2)

    if (coins <= n) {
        if (ans < mid) {
            ans = mid
        }
        start = mid + 1
    } else {
        end = mid - 1
    }
  }

  return ans
}