package leetcode

import "sort"

func canPartitionKSubsets(nums []int, k int) bool {
    if k == 1 { return true }
    sum := 0
    max := 0
    for _, v := range nums {
        sum += v
        if v > max { max = v }
    }
    if sum % k != 0 || max > sum / k { return false }
    sort.Slice(nums, func(i, j int) bool { return nums[i] > nums[j] })
    seen := make([]bool, len(nums))
    return dfs(nums, seen, 0, 0, k, sum / k)
}

func dfs(nums []int, seen []bool, start, sum, k, target int) bool {
    if k == 1 { return true }
    if sum == target { return dfs(nums, seen, 0, 0, k - 1, target) }
    for i := start; i < len(nums); i++ {
        if !seen[i] && sum + nums[i] <= target {
            seen[i] = true
            if dfs(nums, seen, i + 1, nums[i] + sum, k, target) { return true }
            seen[i] = false
        }
    }
    return false
}