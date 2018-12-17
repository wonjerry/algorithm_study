/**
 * 
 * palindrome number: https://leetcode.com/problems/palindrome-number/
 * 
 * 양쪽이 다 같은지 보면 되므로 양쪽만 확인하고 같은 함수에 앞 뒤 글자를 빼고 재귀적으로 돌면서 확인한다.
 */

/**
 * @param {number} x
 * @return {boolean}
 */
const isPalindrome = (x) => {
  const numberStr = String(x)
  if (numberStr.length === 0 || numberStr.length === 1) {
    return true
  }

  if (numberStr[0] === numberStr[numberStr.length - 1]) {
    return isPalindrome(numberStr.slice(1).slice(0, -1))
  }

  return false
}