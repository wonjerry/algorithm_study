/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
const numJewelsInStones = (J, S) => {
  let count = 0
  S.split('').forEach((character) => {
    if (J.includes(character)) {
      count++
    }
  })

  return count
}
