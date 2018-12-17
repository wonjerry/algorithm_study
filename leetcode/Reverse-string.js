/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
const reverseStr = (s, k) => {
  if (s.length <= k) {
    return s.split('').reverse().join('')
  }

  const len = s.length
  const splitedString = s.split('')
  let result = ''
  
  for (let i = 0; i < len; i += k) {
    if (i % (2 * k) === 0) {
      result += splitedString.slice(i, i + k).reverse().join('')
    } else {
      result += splitedString.slice(i, i + k).join('')
    }
  }

  return result
}