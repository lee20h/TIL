package leetcode

func tribonacci(n int) int {
	if n < 2 {
		return n
	}
	cur, prev, prev2 := 1, 1, 0
	for n > 2 {
		cur, prev, prev2 = cur+prev+prev2, cur, prev
		n--
	}
	return cur
}