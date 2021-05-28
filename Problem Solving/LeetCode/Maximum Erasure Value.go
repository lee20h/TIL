package leetcode

func maximumUniqueSubarray(nums []int) int {
	res := 0
	acc := 0
	set := map[int]bool{}
	l := -1
	for _, value := range nums {
		for set[value] {
			l++
			acc -= nums[l]
			delete(set, nums[l])
		}
		acc += value
		set[value] = true
		res = max(res, acc)
	}

	return res
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}