/**
 * 
 * Longest palindrome: https://leetcode.com/problems/longest-palindrome
 * 
 * 주어진 문자들로 만들 수 있는 팰린드롬의 최대 길이를 알아내는 문제이다.
 * 일단 각 문자들의 개수를 새고, 만약 어떤 문자의 개수가 1이상의 수 라면 그 수의 짝수개는 무조건 팰린드롬에 들어갈 수 있다.
 * 만약 1개이거나 홀수개라면 만약 지금 결과값이 짝수라면 가운데에 하나 들어갈 수 있으므로 1을 더해줄 수 있다.
 */

/**
 * @param {string} s
 * @return {number}
 */
const longestPalindrome = (s) => {
  const dic = new Map()
  let result = 0
  s.split('').forEach((letter) => {
    if (dic.has(letter)) {
      dic.set(letter, dic.get(letter) + 1)
    } else {
      dic.set(letter, 1)
    }
  })

  dic.forEach((value, key) => {
    result += value - value % 2
    if (value % 2 !== 0 && result % 2 === 0) {
      result += 1
    }
  })

  return result

}