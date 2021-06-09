package leetcode

func maxResult(nums []int, k int) int {
	n := len(nums)
	dp := make([]int, n) //dp[i] : the max score at index i
	dp[0] = nums[0]

	deque := make([]int, 0)
	deque = append(deque, 0)

	for i := 1; i < n; i++ {
		for len(deque) > 0 && deque[0] < i-k {
			deque = deque[1:]
		}

		dp[i] = dp[deque[0]] + nums[i]

		for len(deque) > 0 && dp[deque[len(deque)-1]] < dp[i] {
			deque = deque[:len(deque)-1]
		}
		deque = append(deque, i) // be noted append the index into the queue
	}
	return dp[n-1]
}