package leetcode

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

func maxTurbulenceSize(A []int) int {
	if len(A) == 1 {
		return 1
	}

	res, left, right, flag, lastNum := 0, 0, 0, A[1]-A[0], A[0]
	for left < len(A) {
		if right < len(A)-1 && ((A[right+1] > lastNum && flag > 0) || (A[right+1] < lastNum && flag < 0) || (right == left)) {
			right++
			flag = lastNum - A[right]
			lastNum = A[right]
		} else {
			if right != left && flag != 0 {
				res = max(res, right-left+1)
			}
			left++
		}
	}
	return max(res, 1)
}