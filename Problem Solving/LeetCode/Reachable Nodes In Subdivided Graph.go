package leetcode

import "container/heap"

func reachableNodes(edges [][]int, M int, N int) int {
	nodes := make(map[int]int, len(edges))
	nextTo := make([][]int, N)
	for i := range nextTo {
		nextTo[i] = make([]int, 0, 16)
	}
	for _, e := range edges {
		i, j, n := e[0], e[1], e[2]
		nodes[encode(i, j)] = n
		nextTo[i] = append(nextTo[i], j)
		nextTo[j] = append(nextTo[j], i)
	}

	pq := make(PQ, 1, N*2)
	pq[0] = []int{M, 0}

	seen := make([]bool, N)
	maxRemainMoves := make([]int, N)

	res := 0
	for len(pq) > 0 {
		m := pq[0][0]
		i := pq[0][1]
		heap.Pop(&pq)

		if seen[i] {
			continue
		}

		seen[i] = true
		maxRemainMoves[i] = m
		res++ 

		for _, j := range nextTo[i] {
			if seen[j] {
				continue
			}
			n := nodes[encode(i, j)]
			jRemainMoves := m - n - 1
			if jRemainMoves >= 0 {
				heap.Push(&pq, []int{jRemainMoves, j})
			}
		}
	}

	for _, e := range edges {
		i, j, n := e[0], e[1], e[2]
		mi := maxRemainMoves[i]
		mj := maxRemainMoves[j] 
		res += min(mi+mj, n)
	}

	return res
}

func encode(i, j int) int {
	if i > j {
		i, j = j, i
	}
	return i<<16 | j
}

type PQ [][]int

func (pq PQ) Len() int { return len(pq) }

func (pq PQ) Less(i, j int) bool {
	return pq[i][0] > pq[j][0]
}

func (pq PQ) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PQ) Push(x interface{}) {
	temp := x.([]int)
	*pq = append(*pq, temp)
}

func (pq *PQ) Pop() interface{} {
	temp := (*pq)[len(*pq)-1]
	*pq = (*pq)[0 : len(*pq)-1]
	return temp
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}