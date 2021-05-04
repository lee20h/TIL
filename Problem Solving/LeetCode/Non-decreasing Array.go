package LeetCode

func checkPossibility(nums []int) bool {
	flag := false
	size := len(nums)
	for i := 1; i < size; i++ {
		if nums[i-1] > nums[i] {
			if flag {
				return false
			} else {
				if i > 1 && nums[i-2] > nums[i] {
					nums[i] = nums[i-1]
				}

				flag = true
			}
		}
	}
	return true
}