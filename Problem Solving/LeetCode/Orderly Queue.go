package Leetcode

import (
	"sort"
)

func orderlyQueue(s string, k int) string {
	if k == 1 {
		return minRotated(s)
	}
	return sorted(s)
}

func minRotated(s string) string {
	min := s
	bytes := []byte(s)
	bytes = append(bytes, bytes...)
	size := len(s)
	for i := 1; i < size; i++ {
		rs := string(bytes[i : i+size])
		if min > rs {
			min = rs
		}
	}
	return min
}

func sorted(s string) string {
	bytes := []byte(s)
	sort.Slice(bytes, func(i int, j int) bool {
		return bytes[i] < bytes[j]
	})
	return string(bytes)
}