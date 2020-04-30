/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  const brackets = {
    ')': '(',
    ']': '[',
    '}': '{',
  }
  const stack = []
  const openBrackets = Object.keys(brackets).map((key) => brackets[key])
  for (const character of s) {
      if (openBrackets.includes(character)) {
        stack.push(character)
        continue
      }
      if (brackets[character] !== stack.pop()) {
        return false
      }
  }
  return stack.length === 0
};