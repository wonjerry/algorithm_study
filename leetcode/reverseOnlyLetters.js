/**
 * 
 * reverse only letters: https://leetcode.com/problems/reverse-only-letters/
 * 
 * 어떤 특수문자가 붙던 알파벳끼리만 reverse 하는 문제이다.
 * 어떤 문자가 알파벳이라면 스택에 넣어두고 다시한번 돌면서 만약 알파벳이면 스택에서 꺼내고 아니라면 그냥 원래있던 문자를 붙여서 return한다.
 */

const isAlpabet = (character) => {
  return ('a' <= character && character <= 'z') || ('A' <= character && character <= 'Z')
}

/**
 * @param {string} S
 * @return {string}
 */
const reverseOnlyLetters = (S) => {
  const stack = []
  S.split('').forEach((character) => {
    if (isAlpabet(character)) {
      stack.push(character)
    }
  })

  let result = ''
  S.split('').forEach((character) => {
    if (isAlpabet(character)) {
      result += stack.pop(character)
    } else {
      result += character
    }
  })

  return result
}
