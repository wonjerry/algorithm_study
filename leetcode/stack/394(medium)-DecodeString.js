function isNumberCharacter(character) {
  return '0' <= character && character <= '9'
}

/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function (s) {
  let resultString = ''
  // s의 모든 character를 확인한다.
  for (let i = 0; i < s.length; i++) {
    // 현재 character가 숫자인지 확인
    if (isNumberCharacter(s[i])) {
      let num = s[i++]
      while(isNumberCharacter(s[i])) {
        num += s[i++]
      }
      let index = i
      const subStack = [s[index++]]
      let subString = ''
      while(subStack.length !== 0) {
        if (s[index] === '[') {
          subStack.push(s[index])
        } else if (s[index] === ']') {
          subStack.pop()
        }
        if (subStack.length !== 0) {
          subString += s[index]
          index++
        }
      }
      resultString += decodeString(subString).repeat(Number(num))
      i = index
      continue
    } else {
      resultString += s[i]
    }
  }

  return resultString
};


console.log(decodeString('100[a]'))