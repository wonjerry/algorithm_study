// 중요한건 인덱스!! 내가 구한 halfLength는 길이 이고 index로 쓰려면 1을 빼는게 맞다.

function isValidCharacter(character) {
	return ('a' <= character &&  character <= 'z') || ('A' <= character &&  character <= 'Z') || ('0' <= character &&  character <= '9')
}

function isPalindrome(s) {
	// 알파벳만 추출해서 모두 소문자로 만든다.
	let sanitizedString = ''
	for (const character of s) {
		if (isValidCharacter(character)) {
			sanitizedString += character.toLowerCase()
		}
	}
	// 알파벳의 절반 인덱스를 순회하면서 대칭되는 index가 동일한지 확인한다.
	const halfLength = Math.floor(sanitizedString.length / 2)
	for(let i = 0; i < halfLength; i++) {
		if (sanitizedString[i] !== sanitizedString[sanitizedString.length -1 - i]) {
			return false
		}
	}
	return true
}
