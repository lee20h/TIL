package leetcode

func shiftingLetters(S string, shifts []int) string {
	currentShift, result := 0, make([]int32, len(S))
	for i := len(shifts) - 1; i >= 0; i-- {
		currentShift = (currentShift + shifts[i]) % 26
		result[i] = (((int32(S[i]) - 'a') + int32(currentShift)) % 26) + 'a'
	}
	return string(result)
}