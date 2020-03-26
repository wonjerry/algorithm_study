/*
  이 문제는 arr에서 숫자들간의 차이를 구했을 때 그 차이들이 양수 음수가 번갈아서 나오는가에 대한 문제이다.

  증가하는 부분 수열 문제를 변형한 문제로
  up[n]: n번째 인덱스까지의 수열에서 가장 긴 연속하는 wiggle sequence 길이
  down[n]: n번째 인덱스까지의 수열에서 가장 긴 연속하는 wiggle sequence 길이

  result = max(up[length - 1], down[length - 1])
*/


let up = []
let down = []

var wiggleMaxLength = function(nums) {
    if (nums.length < 2) return nums.length

    let up = [1]
    let down = [1]

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] - nums[i - 1] < 0) {
            down[i] = up[i - 1] + 1
            up[i] = up[i - 1]
        } else if (nums[i] - nums[i - 1] === 0) {
            up[i] = up[i - 1]
            down[i] = down[i - 1]
        } else {
            up[i] = down[i - 1] + 1
            down[i] = down[i - 1]
        }
    }

    return Math.max(up[nums.length-1], down[nums.length-1])

};
