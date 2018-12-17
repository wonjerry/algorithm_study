/**
 * 
 * letter-case-permutation: https://leetcode.com/problems/letter-case-permutation/submissions/
 * 
 * 이 문제는 permutation을 찾는데, 어떤 문자열에서 알파벳만 대문자 소문자로 바꿨을 때의 모든 경우의 수를 찾는 문제이다.
 * permutaion을 찾는 문제는 두가지 유형이 있다.
 * - 배열을 for문으로 다 돌면서 모든 경우의 수를 찾는 문제
 * - 지금 현재상태를 뺐을때 다음 상태는 재귀로 넘겨버리고 신경쓰지 않는 subset으로 생각하고 permutation을 찾는 문제
 * 
 * 이렇게 두가지가 있다. (내가 알고있는 것은) 지금 문제는 후자에 속하며 항상 자기 자신만 신경쓰고 나머지는 다시 재귀로 돌려서 해결하였다.
 */

/**
 * @param {string} S
 * @return {string[]}
 */
const letterCasePermutation = (S) => {
  if (S.length === 0) {
      return [S]
  }

  S = S.toLowerCase()
  let result = []
  const permutations = letterCasePermutation(S.slice(1))
  result = result.concat(permutations.map((permutation) => `${S[0]}${permutation}`))
  if ('a' <= S[0] && S[0] <= 'z') {
    const upperCase = S[0].toUpperCase()
    result = result.concat(permutations.map((permutation) => `${upperCase}${permutation}`))
  }

  return result
}
