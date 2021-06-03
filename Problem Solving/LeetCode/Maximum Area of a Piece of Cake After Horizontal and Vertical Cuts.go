package leetcode

import (
	"sort"
)

func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
    sort.Ints(horizontalCuts)
    sort.Ints(verticalCuts)
    hlen := len(horizontalCuts)
    vlen := len(verticalCuts)
    maxh := max(horizontalCuts[0], h - horizontalCuts[hlen-1])
    maxv := max(verticalCuts[0], w - verticalCuts[vlen-1])
    
    for i := 1; i < hlen; i++ {
        maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1])
    }
    for i := 1; i < vlen; i++ {
        maxv = max(maxv, verticalCuts[i] - verticalCuts[i-1])
    }
    
    return (maxh * maxv) % 1000000007
}

func max(a, b int) int{
    if a > b {
        return a
    }
    return b
}