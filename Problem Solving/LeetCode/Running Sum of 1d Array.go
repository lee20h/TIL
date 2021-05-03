package LeetCode

func runningSum(nums []int) []int {
	size := len(nums)
	sum := 0
	for i := 0; i < size; i++ {
		sum += nums[i]
		nums[i] = sum
	}
	return nums
}