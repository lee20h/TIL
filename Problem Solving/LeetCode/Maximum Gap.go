package leetcode

import (
	"sort"
)

func maximumGap(nums []int) int {
    res := 0
    sort.Ints(nums)
    prev := nums[0]
    for _, val := range nums {
        res = max(val - prev, res)
        prev = val
    }
    return res
}

func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}