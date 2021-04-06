package LeetCode

func minOperations(n int) int {
	ans := 0
	if n%2 == 0 {
		for i := 0; i < n/2; i++ {
			ans += (i * 2) + 1
		}
	} else {
		for i := 0; i < n/2; i++ {
			ans += ((n-1)/2)*2 + 1
			ans -= ((i * 2) + 1)
		}
	}
	return ans
}