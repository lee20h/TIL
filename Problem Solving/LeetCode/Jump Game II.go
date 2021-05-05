package LeetCode

func jump(nums []int) int {
	size := len(nums) - 1
	max, cur, ans := 0, 0, 0

	for i := 0; i < size; i++ {
		if i+nums[i] > max {
			max = i + nums[i]
		}
		if i == cur {
			ans++
			cur = max
		}
	}
	return ans
}