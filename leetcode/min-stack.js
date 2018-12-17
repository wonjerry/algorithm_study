/**
 * min-stack: https://leetcode.com/problems/min-stack/
 *
 * 이 문제는 stack에서 getMin을 했을 때 항상 현재 가장 작은 원소를 리턴하는 문제이다.
 *
 * getMin 할때마다 정렬을 한다면 상수시간이 보장될 수 없고 항상 NlogN의 시간이 걸릴것이다.
 * 핵심 아이디어는 push하는 시점에 들어온 값과 현재 min값을 비교해서 min값을 계산하고 stack과 같이
 * 저장 해 두는 것이다.
 *
 */

/**
 * initialize your data structure here.
 */
const MinStack = function() {
  this.stack = []
  this.minValues = []
}

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  this.stack.push(x)
  if (this.minValues.length === 0) {
    this.minValues.push(x)
    return
  }

  if (x < this.getMin()) {
    this.minValues.push(x)
  } else {
    this.minValues.push(this.getMin())
  }
}

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  this.stack.pop()
  this.minValues.pop()
}

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this.stack[this.stack.length - 1]
}

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return this.minValues[this.minValues.length - 1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = Object.create(MinStack).createNew()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
