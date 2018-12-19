const htmlStr = '<body><p>Hehe</p><div>wonjerry</div><div>mel</div></body>'

function TreeNode() {
  this.tagName
  this.content = ''
  this.children = []
}

const parseHTMLtextToTree = (str) => {
  const length = str.length
  const result = []
  for (let i = 0; i < length; i++) {
    if (str[i] === '<') {
      const node = new TreeNode()

      let tagName = ''
      let openTagIndex = i + 1
      while (str[openTagIndex] !== '>') {
        tagName += str[openTagIndex++]
      }
      node.tagName = tagName

      let endTagIndex = openTagIndex + 1
      let openCount = 1
      while (openCount && endTagIndex < length) {
        if (str[endTagIndex] === '<') {
          if (str[endTagIndex + 1] === '/') {
            openCount--
          } else {
            openCount++
          }
        }
        endTagIndex++
      }
      endTagIndex--
      i = endTagIndex + `</${tagName}>`.length - 1

      if (str[openTagIndex + 1] !== '<') {
        node.content = str.slice(openTagIndex + 1, endTagIndex)
      } else {
        node.children = parseHTMLtextToTree(str.slice(openTagIndex + 1, endTagIndex))
      }
      result.push(node)
    }
  }

  return result
}

const reverseTree = (root) => {
  if (root.content !== '') {
    root.content = root.content.split('').reverse().join('')
  } else {
    const children = root.children
    root.children = children.reverse().map((node) => reverseTree(node))
  }
  return root
}

const generateHTML = (root) => {
  return `<${root.tagName}>${root.content || root.children.map((node) => generateHTML(node)).join('')}</${root.tagName}>`
}

const reverseHTML = (str) => {
  const HTMLtree = parseHTMLtextToTree(str)
  const root = HTMLtree[0]
  const reversedTree = reverseTree(root)
  return generateHTML(reversedTree)
}

console.log(reverseHTML(htmlStr))
