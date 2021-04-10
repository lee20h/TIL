package Leetcode

var dir = [][]int{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
}

func longestIncreasingPath(matrix [][]int) int {
	cache, res := make([][]int, len(matrix)), 0
	for i := 0; i < len(cache); i++ {
		cache[i] = make([]int, len(matrix[0]))
	}
	for i, v := range matrix {
		for j := range v {
			searchPath(matrix, cache, 0, i, j)
			res = max(res, cache[i][j])
		}
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func isInIntBoard(board [][]int, x, y int) bool {
	return x >= 0 && x < len(board[0]) && y >= 0 && y < len(board)
}

func searchPath(board, cache [][]int, lastNum, y, x int) int {
	if board[y][x] <= lastNum {
		return 0
	}
	if cache[y][x] > 0 {
		return cache[y][x]
	}
	count := 1
	for i := 0; i < 4; i++ {
		nx := x + dir[i][0]
		ny := y + dir[i][1]
		if isInIntBoard(board, nx, ny) {
			count = max(count, searchPath(board, cache, board[y][x], ny, nx)+1)
		}
	}
	cache[y][x] = count
	return count
}