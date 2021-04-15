package LeetCode

func fib(n int) int {
	if n > 1 {
		return fib(n-2) + fib(n-1)
	} else if n == 1 {
		return 1
	} else {
		return 0
	}
}