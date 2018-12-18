const checkRange = (index, size) => {
  return 0 <= index && index < size
}

const findLongestSubstring = (str) => {
  const p = Array(str.length).fill(0)
  const length = str.length
  let c = 0
  let r = 0

  for (let i = 0; i < length; i++) {
    if (i < r) {
      p[i] = Math.min(r - i, p[2 * c - i])
    }

    while (checkRange(i - (p[i] + 1), length) && checkRange(i + (p[i] + 1), length) && str[i - (p[i] + 1)] === str[i + (p[i] + 1)] ) {
      p[i]++
    }

    if (p[i] + i > r) {
      r = p[i] + i
      c = i
    }
  }

  return p
}

/**
 * @param {string} s
 * @return {string}
 */
const longestPalindrome = (s) => {
  const splittedString = '#' + s.split('').join('#') + '#'
  const result = findLongestSubstring(splittedString)
  let max = {
      c: 0,
      r: 0
  }
  result.forEach((rad, index) => {
      if (max.r < rad) {
          max.c = index
          max.r = rad
      }
  })
  const start = max.c - max.r
  const end = max.c + max.r + 1
  return splittedString.slice(start, end).split('#').join('')
}
