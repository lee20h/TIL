package Leetcode

import (
	"math"
	"sort"
)

func minMoves2(nums []int) int {
    sort.Ints(nums)
    ans := 0
    avg := nums[len(nums)/2]
    
    for _, val := range nums {
        ans += int(math.Abs(float64(val - avg)))
    }
    return ans
}