package leetcode

func orderOfLargestPlusSign(N int, mines [][]int) int {
	grid := make([][]int, N)
	res := 0
	for i := range grid {
		grid[i] = make([]int, N)
	}
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			grid[i][j] = 1
		}
	}
	for _, v := range mines {
		grid[v[0]][v[1]] = 0
	}
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if grid[i][j] == 1 {
				max := 1
				dir := 1
				for j-dir >= 0 && j+dir < N && i-dir >= 0 && i+dir < N &&
					grid[i-dir][j] == 1 && grid[i+dir][j] == 1 &&
					grid[i][j-dir] == 1 && grid[i][j+dir] == 1 {
					dir++
					max++
				}
				if max > res {
					res = max
				}
			}
		}
	}
	return res
}