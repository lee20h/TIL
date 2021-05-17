package leetcode

func longestStrChain(words []string) int {
	index := make([][]int, 17)
	count := make([]int, len(words))

	for i, v := range words {
		length := len(v)
		index[length] = append(index[length], i)
		count[i] = 1
	}

	for length := 1; length < 16; length++ {
		for _, i := range index[length] {
			for _, j := range index[length+1] {
				if count[j] > count[i] {
					continue
				}
				if isPredecessor(words[i], words[j]) {
					count[j] = count[i] + 1
				}
			}
		}
	}

	ret := 0
	for _, v := range count {
		ret = max(ret, v)
	}
	return ret
}

func isPredecessor(a, b string) bool {
	i, j := 0, 0
	diff := 0
	for i < len(a) && diff <= 1 {
		if a[i] != b[j] {
			diff++
		} else {
			i++
		}
		j++
	}
	return i == j || diff <= 1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}