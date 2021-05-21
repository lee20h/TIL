package Leetcode

func findAndReplacePattern(words []string, pattern string) []string {
	res := make([]string, 0, len(words))

	m := matchPattern(pattern)
	for _, s := range words {
		if matchPattern(s) == m {
			res = append(res, s)
		}
	}

	return res
}

func matchPattern(s string) int64 {
	var p, i int64
	match := make(map[rune]int64)

	for _, v := range s {
		if match[v] == 0 {
			i++
			match[v] = i
		}

		p = p*10 + match[v]
	}

	return p
}