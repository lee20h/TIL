package LeetCode

func leastBricks(wall [][]int) int {
	m := make(map[int]int)
	maxend := 0
	for i := 0; i < len(wall); i++ {
		sum := 0
		for j := 0; j+1 < len(wall[i]); j++ {
			sum += wall[i][j]
			if v, ok := m[sum]; ok {
				m[sum] = v + 1
			} else {
				m[sum] = 1
			}
			maxend = max(maxend, m[sum])
		}
	}
	return len(wall) - maxend
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}