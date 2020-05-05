/**
 * @param {string} s
 * @return {string[]}
 */
function printVertically(str) {
  const splitedString = str.split(' ')
  const verticalPrintResult = []
  while (!splitedString.every(word => word.length === 0)) {
    let verticalWord = ''
    for (let i = 0; i < splitedString.length; i++) {
      if (splitedString[i] === '') {
        verticalWord += ' '
        continue
      }
      const firstCharacter = splitedString[i].substring(0, 1)
      const leftCharacters = splitedString[i].substring(1)
      verticalWord += firstCharacter
      splitedString[i] = leftCharacters
    }
    verticalPrintResult.push(verticalWord.trimEnd())
  }
  return verticalPrintResult
}
