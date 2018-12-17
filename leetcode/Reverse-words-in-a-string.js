/**
 * @param {string} s
 * @return {string}
 */
const reverseWords = (s) => {
  let stack = []
  let result = ''
  s.split('').forEach((character) => {
    if (character === ' ') {
      result += stack.reverse().join('') + character
      stack = []
      return
    }
    stack.push(character)
  })
    
  if (stack.length !== 0) {
      result += stack.reverse().join('')
  }

  return result
}
