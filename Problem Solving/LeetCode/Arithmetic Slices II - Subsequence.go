package leetcode

func numberOfArithmeticSlices(a []int) int {
	n := len(a)
	if n < 3 {
		return 0
	}

	min, max := -1<<31, 1<<31-1
	dp := make([]map[int]int, n)

	res := 0
	for i := 1; i < n; i++ {
		dp[i] = make(map[int]int)
		for j := 0; j < i; j++ {
			d := a[i] - a[j]

			if d <= min || max <= d {
				continue
			}

			dp[i][d] += dp[j][d] + 1
			res += dp[j][d]
		}
	}

	return res
}