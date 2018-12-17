/**
 * 
 * single-number: https://leetcode.com/problems/single-number/
 * 이 문제는 array안에 딱 한개만 한개이고 다른 모든 숫자는 두개씩 있을 때, 딱 한가지 숫자를 찾아내는 문제이다.
 * 비트연산을 통해 xor로 값을 쌓아보다 보면 딱 한가지 숫자의 비트는 꺼지지 않으므로 바로 알아낼 수 있다.
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
const singleNumber = (nums) => {
  return nums.reduce((acc, num) => acc ^ num, 0)    
}
