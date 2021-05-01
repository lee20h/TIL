package LeetCode

import "strings"


type WordFilter struct {
	input []string
}

func Constructor(words []string) WordFilter {
	return WordFilter{input: words}
}

func (this *WordFilter) F(prefix string, suffix string) int {
	for i := len(this.input) - 1; i >= 0; i-- {
		if strings.HasPrefix(this.input[i], prefix) && strings.HasSuffix(this.input[i], suffix) {
			return i
		}
	}
	return -1
}