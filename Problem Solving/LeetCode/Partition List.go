package LeetCode

//   Definition for singly-linked list.
  type ListNode struct {
      Val int
      Next *ListNode
  }

func partition(head *ListNode, x int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var newHead, newTail, oldHead, oldTail *ListNode
	for cur := head; cur != nil; cur = cur.Next {
		if cur.Val >= x {
			if oldHead == nil {
				oldHead = cur
			}
			oldTail = cur
		} else {
			if newHead == nil {
				newHead, newTail = cur, cur
			} else {
				newTail.Next = cur
				newTail = cur
			}
			if oldTail != nil {
				oldTail.Next = cur.Next
			}
		}
	}
	if newHead == nil {
		return head
	}
	newTail.Next = oldHead
	return newHead
}