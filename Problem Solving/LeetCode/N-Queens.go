package Leetcode

func solveNQueens(n int) [][]string {
	res := make([][]string, 0)
	sol := initialSolution(n)

	backtrack(&res, sol, 0, n)
	return res
}

func backtrack(res *[][]string, sol [][]byte, col int, n int) {
	if col == n {
		collectSolution(res, sol)
		return
	}
	for i := 0; i < n; i++ {
		if isValid(sol, i, col, n) {
			sol[i][col] = 'Q'
			backtrack(res, sol, col+1, n)
			sol[i][col] = '.'
		}
	}
}

func initialSolution(n int) [][]byte {
	res := make([][]byte, 0)
	for i := 0; i < n; i++ {
		tmp := make([]byte, n)
		for j := range tmp {
			tmp[j] = '.'
		}
		res = append(res, tmp)
	}
	return res
}

func collectSolution(res *[][]string, sol [][]byte) {
	tmp := make([]string, 0)
	for i := range sol {
		tmp = append(tmp, string(sol[i]))
	}
	*res = append(*res, tmp)
}

func isValid(tmp [][]byte, row, col, n int) bool {
	for i := 0; i < col; i++ {
		if tmp[row][i] == 'Q' {
			return false
		}
	}
	for i, j := row, col; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if tmp[i][j] == 'Q' {
			return false
		}
	}
	for i, j := row, col; i < n && j >= 0; i, j = i+1, j-1 {
		if tmp[i][j] == 'Q' {
			return false
		}
	}
	return true
}