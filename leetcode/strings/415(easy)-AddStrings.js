/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
function addStrings(num1, num2) {
  // num1, num2
  // 둘 중 짧은것을 기준
  // 두 자릿수를 더해줌
  // 만약 10보다 크다면 다음에 1을 더해줌
  // 위의 작업 반복
  // 제일 마지막의 것이 10보다 크고, index가 아직 0이 안되었다면 계속 더한다. (긴것에)
  // 마지막까지 1이 남으면은, 1 + string

  const longerString = num1.length < num2.length ? num2 : num1
  const shorterString = num1.length < num2.length ? num1 : num2

  let longerIndex = longerString.length - 1
  let shorterIndex = shorterString.length - 1
  let isLargerThanNine = false
  let resultString = ''
  while (shorterIndex >= 0) {
    const plusResultValue = (longerString[longerIndex--] - '0') + (shorterString[shorterIndex--] - '0') + (isLargerThanNine ? 1 : 0)
    isLargerThanNine = plusResultValue > 9
    resultString = (isLargerThanNine ? plusResultValue % 10 : plusResultValue) + resultString
  }

  while (longerIndex >= 0) {
    const plusResultValue = (longerString[longerIndex--] - '0') + (isLargerThanNine ? 1 : 0)
    isLargerThanNine = plusResultValue > 9
    resultString = (isLargerThanNine ? plusResultValue % 10 : plusResultValue) + resultString
  }
  if (isLargerThanNine) {
    resultString = 1 + resultString
  }
  return resultString
}
