/**
 * 
 * valid-anagram: https://leetcode.com/problems/valid-anagram/
 * 
 * 이 문제는 두 문장이 같은 알파벳으로 이루어져있는지 아닌지를 판별하는 문제이다.
 * 이렇게 풀면 O(nlogn) 이라는 시간이 걸린다.
 * O(n)만에 풀려면 한 문자열에 대해 map에 넣으면서 각 알파벳순으로 카운팅을 하고
 * 다른 문자열에 대해 돌면서 map에서 빼준 후 모든 원소가 0인지를 체크하면 O(N)만에 해결할 수 있다.
 */

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isAnagram = (s, t) => {
  if (s.length !== t.length) {
      return false
  }
  return s.split('').sort().join() === t.split('').sort().join()
}