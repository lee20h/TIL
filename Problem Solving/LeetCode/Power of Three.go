package LeetCode

func isPowerOfThree(n int) bool {
	if n == 0 {
		return false
	}
	for true {
		if n%3 == 0 {
			n = n / 3
		} else {
			if n == 1 {
				return true
			}
			break
		}
	}
	return false
}