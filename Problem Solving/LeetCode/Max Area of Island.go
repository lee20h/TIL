package leetcode

func maxAreaOfIsland(grid [][]int) int {
	maxArea := 0
	for y := 0; y < len(grid); y++ {
		for x := 0; x < len(grid[y]); x++ {
			if grid[y][x] > 0 {
				if sum := sumIslandArea(grid, y, x); sum > maxArea {
					maxArea = sum
				}
			}
		}
	}
	return maxArea
}

func sumIslandArea(grid [][]int, y int, x int) int {
	sum := 1
	grid[y][x] = 0

	if y > 0 && grid[y-1][x] > 0 {
		sum += sumIslandArea(grid, y-1, x)
	}
	if x < len(grid[y])-1 && grid[y][x+1] > 0 {
		sum += sumIslandArea(grid, y, x+1)
	}
	if y < len(grid)-1 && grid[y+1][x] > 0 {
		sum += sumIslandArea(grid, y+1, x)
	}
	if x > 0 && grid[y][x-1] > 0 {
		sum += sumIslandArea(grid, y, x-1)
	}
	return sum
}