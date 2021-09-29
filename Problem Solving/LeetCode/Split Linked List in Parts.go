package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func splitListToParts(root *ListNode, k int) []*ListNode {
	res := make([]*ListNode, 0)
	if root == nil {
		for i := 0; i < k; i++ {
			res = append(res, nil)
		}
		return res
	}
	length := getLength(root)
	splitNum := length / k
	lengNum := length % k
	cur, head := root, root
	var pre *ListNode
	if splitNum == 0 {
		for i := 0; i < k; i++ {
			if cur != nil {
				pre = cur.Next
				cur.Next = nil
				res = append(res, cur)
				cur = pre
			} else {
				res = append(res, nil)
			}
		}
		return res
	}
	for i := 0; i < lengNum; i++ {
		for j := 0; j < splitNum; j++ {
			cur = cur.Next
		}
		pre = cur.Next
		cur.Next = nil
		res = append(res, head)
		head = pre
		cur = pre
	}
	for i := 0; i < k-lengNum; i++ {
		for j := 0; j < splitNum-1; j++ {
			cur = cur.Next
		}
		pre = cur.Next
		cur.Next = nil
		res = append(res, head)
		head = pre
		cur = pre
	}
	return res
}

func getLength(l *ListNode) int {
	count := 0
	cur := l
	for cur != nil {
		count++
		cur = cur.Next
	}
	return count
}