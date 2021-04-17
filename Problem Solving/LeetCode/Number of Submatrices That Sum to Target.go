package Leetcode

func numSubmatrixSumTarget(matrix [][]int, target int) int {
	m, n, res, sum := len(matrix), len(matrix[0]), 0, 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			counterMap := map[int]int{}
			counterMap[0] = 1
			sum = 0
			for row := 0; row < m; row++ {
				for k := i; k <= j; k++ {
					sum += matrix[row][k]
				}
				res += counterMap[sum-target]
				counterMap[sum]++
			}
		}
	}
	return res
}