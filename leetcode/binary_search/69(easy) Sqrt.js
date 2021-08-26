/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
  if (x === 1 || x === 0) {
    return x
  }
  let start = 0
  let end = x

  let ans = start
  while (start <= end) {
    const mid = Math.floor((start + end) / 2)

    if (mid * mid === x) {
      ans = mid
      break
    }

    if (mid * mid < x) {
      ans = mid // 최대값 저장
      start = mid + 1
    }

    if (mid * mid > x) {
      end = mid - 1
    }
  }

  return ans
}
