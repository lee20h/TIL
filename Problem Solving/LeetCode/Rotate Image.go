package LeetCode

func rotate(m [][]int) {
	N := len(m)
	for i := 0; i < (N)/2; i++ {
		for j := 0; j < (N+1)/2; j++ {
			m[j][N-i-1], m[N-i-1][N-j-1], m[N-j-1][i], m[i][j] = m[i][j], m[j][N-i-1], m[N-i-1][N-j-1], m[N-j-1][i]
		}
	}
}