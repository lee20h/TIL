package LeetCode

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if len(obstacleGrid) == 0 {
		return 0
	}
	n := len(obstacleGrid)
	m := len(obstacleGrid[0])
	paths := make([][]int, n+1)
	for i := range paths {
		paths[i] = make([]int, m+1)
	}
	if obstacleGrid[0][0] == 1 {
		return 0
	}
	paths[1][1] = 1

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if (i == 1 && j == 1) || obstacleGrid[i-1][j-1] == 1 {
				continue
			} else {
				paths[i][j] = paths[i-1][j] + paths[i][j-1]
			}
		}
	}
	return paths[n][m]
}