package leetcode

import (
	"sort"
	"strings"
)

func suggestedProducts(products []string, searchWord string) [][]string {
	res := make([][]string, len(searchWord))
	sort.Strings(products)
	s := ""

	for i, val := range searchWord {
		s += string(val)
		counter := 0
		for _, product := range products {
			if counter == 3 {
				break
			}
			if strings.HasPrefix(product, s) {
				counter++
				res[i] = append(res[i], product)
			}
		}

	}

	return res
}