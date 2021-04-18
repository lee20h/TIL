package Leetcode

//  Definition for singly-linked list.
type ListNode struct {
    Val int
    Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    first, second := head, head
	for i := 0; i < n; i++ {
		first = first.Next
	}
    
    var prev *ListNode
    
    for first != nil {
		first = first.Next
		prev = second
		second = second.Next
	}
	if prev == nil {
		t := head.Next
		head.Next = nil
		head = t
	} else {
		prev.Next = second.Next
		second.Next = nil
	}
	return head
}