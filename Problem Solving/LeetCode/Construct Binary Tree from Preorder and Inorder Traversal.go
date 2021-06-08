package leetcode

// Definition for a binary tree node.
type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}
 
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	index := search(preorder[0], inorder)
	node := &TreeNode{
		Val:   preorder[0],
		Left:  buildTree(preorder[1:1+index], inorder[:index]),
		Right: buildTree(preorder[1+index:], inorder[index+1:]),
	}

	return node
}

func search(val int, array []int) int {
	for i := 0; i < len(array); i++ {
		if val == array[i] {
			return i
		}
	}

	return 0
}