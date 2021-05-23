package leetcode

import (
	"fmt"
	"math"
)

func shortestSuperstring(A []string) string {
	n := len(A)
	// adjacent map
	// A[i] = "ab", A[j] = "abcde"
	// adj_map[i][j] = 3, it means that we can only add 3 char in A[j]
	// after A[i]
	adj_map := make([][]int, n)
	for i := 0; i < n; i++ {
		adj_map[i] = make([]int, n)
		for j := 0; j < n; j++ {
			aj, ai := []byte(A[j]), []byte(A[i])
			adj_map[i][j] = len(aj)
			for k := 1; k <= min(len(ai), len(aj)); k++ {
				if string(ai[len(ai)-k:]) == string(aj[:k]) {
					adj_map[i][j] = len(aj) - k
				}
			}
		}
	}

	// dp[s][i] := min distance to visit nodes
	// (represented as a binary state s) once and only once
	// and the path ends with node i.
	dp := make([][]int, 1<<uint(n))
	// record the path
	parent := make([][]int, 1<<uint(n))
	// dp[7][1] is the min distance to visit nodes (0, 1, 2)
	// and ends with node 1, the possible paths could be
	// (0, 2, 1), (2, 0, 1). parent[7][1] could be 2 or 0

	// init dp and parent
	for i := 0; i < (1 << uint(n)); i++ {
		dp[i] = make([]int, n)
		parent[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = math.MaxInt32
			parent[i][j] = -1
		}
	}

	// Init
	for i := 0; i < n; i++ {
		dp[1<<uint(i)][i] = len([]byte(A[i]))
	}

	// Transition
	for s := 1; s < (1 << uint(n)); s++ {
		for j := 0; j < n; j++ {
			// if node j is not in s, skip
			if s&(1<<uint(j)) == 0 {
				continue
			}
			// remove node j from s
			ps := s & ^(1 << uint(j))
			// test all the parent of j
			for i := 0; i < n; i++ {
				// find out the i with min(dp[ps][i] + adj_map[i][j])
				// record it in dp[s][j] and parent[s][j]
				if dp[ps][i]+adj_map[i][j] < dp[s][j] {
					dp[s][j] = dp[ps][i] + adj_map[i][j]
					parent[s][j] = i
				}
			}
		}
	}

	// find out the last node in shortest path
	j, min := 0, math.MaxInt32
	for i := 0; i < n; i++ {
		fmt.Println(dp[(1<<uint(n))-1][i], i)

		if dp[(1<<uint(n))-1][i] < min {
			min = dp[(1<<uint(n))-1][i]
			j = i
		}
	}

	// get the whole path by parent[s][j]
	// and build the Shortest Superstring
	s := (1 << uint(n)) - 1
	ans := ""
	for s != 0 {
		i := parent[s][j]
		if i < 0 {
			ans = A[j] + ans
		} else {
			adj := []byte(A[j])
			ans = string(adj[len(adj)-adj_map[i][j]:]) + ans
		}
		s &= ^(1 << uint(j))
		j = i
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}