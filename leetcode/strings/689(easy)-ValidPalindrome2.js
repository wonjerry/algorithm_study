// 요건 약간 재귀 개념으로 해결
// 계속 palindrome 연산을 하다가 틀린부분이 나오면 그 위치를 포함한 string에서
// 현재 위치, 현재위치와 대칭되는점 두개를 각각 뺀 경우에 나머지경우가 palindrome이면 통과

function checkPalindrome(s) {
	const halfLength = Math.floor(s.length / 2)
	for(let i = 0; i < halfLength; i++) {
		if (s[i] !== s[s.length - 1 - i]) {
			return false
		}
	}
	return true
}
function validPalindrome(s) {
	const halfLength = Math.floor(s.length / 2)
	for(let i = 0; i < halfLength; i++) {
		if (s[i] !== s[s.length - 1 - i]) {
			return checkPalindrome(s.substring(i + 1, s.length - i)) || checkPalindrome(s.substring(i, s.length - 1 - i))
		}
	}
	return true
}
