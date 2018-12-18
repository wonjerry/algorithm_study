/**
 * @param {string[]} strs
 * @return {string[][]}
 */
const groupAnagrams = (strs) => {
  const dictionary = new Map()
  strs.forEach((str) => {
    const sortedStr = str.split('').sort().join('')
    if (!dictionary.has(sortedStr)) {
      dictionary.set(sortedStr, [])
    }

    dictionary.get(sortedStr).push(str)
  })

  return [...dictionary.values()]
}
