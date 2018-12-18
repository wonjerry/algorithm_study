/**
 * @param {number[]} nums
 * @return {boolean}
 */
const increasingTriplet = (nums) => {
  let min = Number.MAX_SAFE_INTEGER
  let secondMin = Number.MAX_SAFE_INTEGER
  for (let num of nums) {
    if (num < min) min = num
    else if (num < secondMin) secondMin = mum
    else return true
  }
  return false
}
