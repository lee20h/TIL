package LeetCode

// Definition for a Node.
  type Node struct {
      Val int
      Children []*Node
  }


func preorder(root *Node) []int {
    res := []int{}
    if root == nil {
        return res
    }

    stack := []*Node{root}
    for len(stack) > 0 {
        r := stack[len(stack)-1]
        stack = stack[:len(stack)-1]

        res = append(res, r.Val)

        tmp := []*Node{}
        for _, v := range r.Children {
            tmp = append([]*Node{v}, tmp...)
        }
        stack = append(stack, tmp...)
    }
    return res
}