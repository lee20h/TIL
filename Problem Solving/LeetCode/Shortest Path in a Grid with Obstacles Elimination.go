package leetcode

func shortestPath(grid [][]int, k int) int {
	queue := [][]int{{0, 0}, nil}

	m, n := len(grid), len(grid[0])
	leftK := make([][]int, m)
	for i := range leftK {
		leftK[i] = make([]int, n)
		for j := range leftK[i] {
			leftK[i][j] = -1
		}
	}

	leftK[0][0] = k
	var step int
	for len(queue) > 0 {
		q := queue[0]
		queue = queue[1:]
		if q == nil {
			step++
			if len(queue) != 0 {
				queue = append(queue, nil)
			}
			continue
		}

		x, y := q[0], q[1]
		if x == m-1 && y == n-1 {
			return step
		}

		currK := leftK[x][y]
		for _, d := range [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}} {
			qn := update(grid, leftK, x+d[0], y+d[1], currK)
			if qn != nil {
				queue = append(queue, qn)
			}
		}
	}

	return -1
}

func update(grid, leftK [][]int, x, y, k int) []int {
	if x >= len(grid) || y >= len(grid[0]) || x < 0 || y < 0 {
		return nil
	}

	if grid[x][y] == 1 {
		k--
	}

	if k < 0 {
		return nil
	}

	if leftK[x][y] == -1 { // means not visited yet
		leftK[x][y] = k
		return []int{x, y}
	} else if leftK[x][y] < k { // means visited
		leftK[x][y] = k
		return []int{x, y} // add to the queue since we update the route for it.
	}

	return nil
}
