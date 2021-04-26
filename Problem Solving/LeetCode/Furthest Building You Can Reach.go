package Leetcode

import "container/heap"

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func furthestBuilding(heights []int, bricks int, ladders int) int {
	n := len(heights)

	h := &IntHeap{}
	heap.Init(h)

	for i := 1; i < n; i++ {
		if heights[i]-heights[i-1] > 0 {
			heap.Push(h, heights[i]-heights[i-1])
			if h.Len() > ladders {
				cost := heap.Pop(h).(int)
				if bricks < cost {
					return i - 1
				}
				bricks = bricks - cost
			}
		}
	}

	return n - 1
}