package LeetCode

func constructArray(n int, k int) []int {
	arr := make([]int, 0, n)
	i, j := 1, n
	for i <= j {
		if k%2 == 0 {
			arr = append(arr, i)
			i++
		} else {
			arr = append(arr, j)
			j--
		}

		if k > 1 {
			k--
		}
	}
	return arr
}