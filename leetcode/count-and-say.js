/**
 * @param {number} n
 * @return {string}
 */
const countAndSay = (n) => {
  if (n === 1) {
    return '1'
  }

  const numbers = countAndSay(n - 1)
  const length = numbers.length
  let count = 1
  let result =''
  for (let i = 1; i < length; i++) {
    if (numbers[i - 1] !== numbers[n]) {
      result += count + numbers[n - 1]
    } else {
      count++
    }
  }
  result += count + numbers[length - 1]
  return result
}
