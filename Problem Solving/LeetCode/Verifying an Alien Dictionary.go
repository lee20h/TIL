package LeetCode

func isAlienSorted(words []string, order string) bool {
	if len(words) < 2 {
		return true
	}
	dict := createDict(order)
	prev := words[0]
	for _, w := range words {
		if compare(dict, prev, w) > 0 {
			return false
		}
		prev = w
	}
	return true
}
func createDict(s string) map[byte]int {
	res := make(map[byte]int)
	for i, c := range s {
		res[byte(c)] = i
	}
	return res
}
func compare(dict map[byte]int, a, b string) int {
	al, bl, com := len(a), len(b), 0
	for i := 0; i < al && i < bl && com == 0; i++ {
		com = dict[a[i]] - dict[b[i]]
	}
	if com == 0 {
		return al - bl
	}
	return com
}