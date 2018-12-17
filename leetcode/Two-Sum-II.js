/**
 * 
 * two-sum-II: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
 * 
 * 이 문제는 단순하게 풀면 O(N^2)에 풀린다.
 * 왜냐하면 어떤 한 원소에서 다른 원소를 찾을 때 리니어하게 찾기 때문이다.
 * 
 * 따라서 리니어한 search를 개선하면 되므로 이분탐색을 통해 logN으로 탐색시간을 줄인다.
 * 그렇게하면 결과적으로 O(NlogN)의 시간 복잡도가 나온다.
 */

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (numbers, target) => {
  const size = numbers.length
  for (let i = 0; i < size; i++) {
    let start = i + 1
    let end = size - 1
    let mid = Math.floor((start + end) / 2)

    while(start <= end) {
      mid = Math.floor((start + end) / 2)

      if (numbers[i] + numbers[mid] === target) {
        return [i + 1, mid + 1]
      }

      if (numbers[i] + numbers[mid] < target) {
        end = mid - 1
      }

      if (numbers[i] + numbers[mid] > target) {
        start = mid + 1
      }
    }
  }

  return [-1, -1]
}