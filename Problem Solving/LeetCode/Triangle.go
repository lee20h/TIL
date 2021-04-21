package Leetcode

func minimumTotal(triangle [][]int) int {
	for i := 1; i < len(triangle); i++ {
		triangle[i][0] += triangle[i-1][0]
		triangle[i][len(triangle[i])-1] += triangle[i-1][len(triangle[i-1])-1]
	}
	for i := 2; i < len(triangle); i++ {
		for j := 1; j < len(triangle[i])-1; j++ {
			triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
		}
	}
	temp := triangle[len(triangle)-1][0]
	for _, v := range triangle[len(triangle)-1] {
		if v < temp {
			temp = v
		}
	}
	return temp
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}