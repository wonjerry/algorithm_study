/**
 * @param {string} str
 * @return {string}
 */
const toLowerCase = (str) => {
  return str.split('').map((character) => {
    const lowerCharacterCode = 'A' <= character && character <= 'Z' ? character.charCodeAt(0) + 32 : character.charCodeAt(0)
    return String.fromCharCode(lowerCharacterCode)
  }).join('')
}