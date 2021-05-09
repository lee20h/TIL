package LeetCode

import (
	"container/heap"
)
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	x := old[0]
	*h = old[1 : ]
	return x
}

type MaxHeap struct {
    IntHeap
}

func (h MaxHeap) Less(i, j int) bool { return h.IntHeap[i] > h.IntHeap[j] }

func isPossible(target []int) bool {
    h := &MaxHeap{}
    size := len(target)
    sum := 0
    for i:=0; i<size; i++ {
        sum += target[i]
        heap.Push(h,target[i])
    }
    heap.Init(h)

    for (*h).IntHeap[0] != 1 {
        top := (*h).IntHeap[0]
        h.Pop()
        sum -= top
        if top <= sum || sum < 1 {
            return false
        }
        top %= sum
        sum += top
        h.Push(top)
        heap.Init(h)
    }
    return true;
}