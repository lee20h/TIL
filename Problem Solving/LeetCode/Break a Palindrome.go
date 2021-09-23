package leetcode

func breakPalindrome(palindrome string) string {
	if len(palindrome) <= 1 {
		return ""
	}
	index := midPoint(palindrome)
	for i, v := range palindrome {
		if i != index && v != 'a' {
			return palindrome[0:i] + "a" + palindrome[i+1:]
		}
	}
	return palindrome[:len(palindrome)-1] + "b"
}

func midPoint(s string) int {
	if len(s)%2 == 0 {
		return -1
	}
	return len(s) / 2
}