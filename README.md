# 📙 Today I Learned

## 규칙

- 기억에 남는 내용 기록 후 [정적 웹페이지](https://lee20h.github.io/TIL/)에 정리
- Github Action으로 배포
- markdown으로 작성
- 문제 풀고 [Problem Solving](https://github.com/lee20h/TIL/tree/master/Problem%20Solving) 폴더에 모으기

---

# 2020년

| [5월](./years/2020/5월.md) | [6월](./years/2020/6월.md) | [7월](./years/2020/7월.md) | [8월](./years/2020/8월.md) | [9월](./years/2020/9월.md) | [10월](./years/2020/10월.md) | [11월](./years/2020/11월.md) | [12월](./years/2020/12월.md) |
| -------------------------- | -------------------------- | -------------------------- | -------------------------- | -------------------------- | ---------------------------- | ---------------------------- | ---------------------------- |

---

# 2021년

| [1월](./years/2021/1월.md) | [2월](./years/2021/2월.md) | [3월](./years/2021/3월.md) | [4월](./years/2021/4월.md) |
| -------------------------- | -------------------------- | -------------------------- | -------------------------- |

---

- 1 日

# PS

- Prefix and Suffix Search

```go
type WordFilter struct {
	input []string
}

func Constructor(words []string) WordFilter {
	return WordFilter{input: words}
}

func (this *WordFilter) F(prefix string, suffix string) int {
	for i := len(this.input) - 1; i >= 0; i-- {
		if strings.HasPrefix(this.input[i], prefix) && strings.HasSuffix(this.input[i], suffix) {
			return i
		}
	}
	return -1
}
```

prefix와 suffix가 주어졌을 때 인덱스를 구하는 문제로, strings에서 사용할 수 있는 HasPrefix와 HasSuffix를 이용해서 해당 접두사와 접미사가 존재하는지 true, false로 받아서 해결할 수 있다.

strings를 이용하면 map을 사용하는거보단 속도가 느리지만 조금 더 편하게 사용할 수 있다.

---

- 2 日

# PS

- Course Schedule III

```go
func scheduleCourse(courses [][]int) int {
	taken := new(maxPQ)
	heap.Init(taken)

	myCs := cs(courses)
	sort.Sort(myCs)

	var date int
	for _, c := range myCs {
		heap.Push(taken, c[0])
		date += c[0]
		for date > c[1] {
			date -= heap.Pop(taken).(int)
		}
	}

	return taken.Len()
}

type maxPQ []int

func (q maxPQ) Len() int {
	return len(q)
}

func (q maxPQ) Less(i, j int) bool {
	return q[i] > q[j]
}

func (q maxPQ) Swap(i, j int) {
	q[i], q[j] = q[j], q[i]
}

func (q *maxPQ) Push(x interface{}) {
	*q = append(*q, x.(int))
}

func (q *maxPQ) Pop() interface{} {
	res := (*q)[len(*q)-1]
	*q = (*q)[:len(*q)-1]
	return res
}

type cs [][]int

func (c cs) Len() int {
	return len(c)
}

func (c cs) Less(i, j int) bool {
	if c[i][1] == c[j][1] {
		return c[i][0] < c[j][0]
	}
	return c[i][1] < c[j][1]
}

func (c cs) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}
```

스케쥴 문제로 우선순위 큐로 생각해보다 막혀서 다른 사람의 코드를 인용해왔다.

이 문제를 통해서 알게 된 점은 Golang에서 container/heap과 sort를 사용할 때는 커스텀하게 사용할 수 있게 Len, Less, Swap을 선언해야하고 heap의 경우에는 push, pop까지 정의해주고 사용해야한다.

자료형도 자신이 원하는 내용으로 사용할 수 있으므로 어떻게보면 다른 언어보단 번거롭지만 더 유틸리티 있게 사용할 수 있다고 생각이 된다.

따라서 sort와 heap에 원하는 방향에 맞게 설계한 후 스케쥴에 맞게 진행하는 방식으로 구현되어 있다.

이 때 heap은 최대힙으로 우선순위 큐로 설계한 뒤 sort는 주어진 배열을 정렬을 위해 사용되었다.

---

- 3 日

# PS

- Running Sum of 1d Array

```go
func runningSum(nums []int) []int {
    size := len(nums)
    sum := 0
    for i := 0; i<size; i++ {
        sum += nums[i];
        nums[i] = sum
    }
    return nums
}
```

이전 값들을 모두 더해서 현재 인덱스에 넣어주는 문제로 매우 쉽게 풀 수 있다.

문제들을 생각할 때 golang으로 해결할 수 있으며 여러가지 방향으로 생각할 수 있게 노력하고 있다.

다른 공부로는 이스티오를 위주로 많이 알아가고 있으며 아직 많이 부족하다는 걸 느낀다.

따라서 Istio Up & Running 책을 다 읽는다면 쿠버네티스를 리마인드하는 느낌으로 다시 복기해보려 한다.

---

- 4 日

# PS

- Non-decreasing Array

```go
func checkPossibility(nums []int) bool {
    flag := false
    size := len(nums)
    for i:=1; i<size; i++ {
        if(nums[i-1] > nums[i]) {
            if(flag) {
                return false
            } else {
                if(i>1 && nums[i-2] > nums[i]) {
                    nums[i] = nums[i-1]
                }

                flag = true
            }
        }
    }
    return true
}
```

주어진 배열에서 숫자 하나만 바꿨을 때 오름차순이 되는지 확인하는 문제이다. 그래서 O(n)으로 배열을 전부 탐색하면서 이전 값이 다음 값보다 큰 경우가 두 번 이상 있는지 확인한다.

원래 생각한 부분은 스택을 이용해서 하나하나 푸쉬하면서 현재 값과 스택의 top값을 비교한다. 그러면서 스택 top값보다 현재 값이 작은 경우에는 한번 스택을 pop해주면서 boolean 변수로 체크한다.

한번 더 같은 상황이 발생하면 false를 끝까지 간다면 true를 반환해주면서 마무리한다.

---

- 5 日

# PS

- Jump Game II

```go
func jump(nums []int) int {
    size := len(nums)-1
    max, cur, ans := 0, 0, 0

    for i:=0; i<size; i++ {
        if i+nums[i] > max {
            max = i+nums[i]
        }
        if i == cur {
            ans++
            cur = max
        }
    }
    return ans
}
```

점프할 수 있는 최대의 숫자를 나열한 배열이 있을 때 끝의 인덱스까지 점프할 수 있는 최소의 횟수를 반환해주는 문제이다.

따라서 계속 이동하면서 MAX의 값을 갱신해줘서 가는 동안 가장 높은 인덱스까지 이동한 경우 앞으로 가야할 위치와 리턴할 값을 올리면서 반복한다. 약간의 BFS와 비슷하게 진행된다고 생각된다.

---

- 6 日

# PS

- Convert Sorted List to Binary Search Tree

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	if head != nil && head.Next == nil {
		return &TreeNode{Val: head.Val, Left: nil, Right: nil}
	}
	middleNode, preNode := middleNodeAndPreNode(head)
	if middleNode == nil {
		return nil
	}
	if preNode != nil {
		preNode.Next = nil
	}
	if middleNode == head {
		head = nil
	}
	return &TreeNode{Val: middleNode.Val, Left: sortedListToBST(head), Right: sortedListToBST(middleNode.Next)}
}

func middleNodeAndPreNode(head *ListNode) (middle *ListNode, pre *ListNode) {
	if head == nil || head.Next == nil {
		return nil, head
	}
	p1 := head
	p2 := head
	for p2.Next != nil && p2.Next.Next != nil {
		pre = p1
		p1 = p1.Next
		p2 = p2.Next.Next
	}
	return p1, pre
}
```

정렬된 배열이 주어졌을 때 BST 이진 검색 트리로 변환하는 문제로, 생각하는데 Golang으로 만들기 아직 벅찬 부분이 있다. 다른 분의 소스를 참조하여 진행했다.

결국에는 흐름을 찾아서 이해하듯이 공부하였다. 이 부분에 있어서는 더 공부가 필요하다.

---

# Istio Proxy Injection

Istio Proxy (Envoy)를 Istio Service mesh에 주입하는 방법은 여러가지가 있다. 그 중 가장 편하다고 생각하는 Label을 붙여서 올라가는 Pod에 Istio-proxy를 삽입하는 방법을 사용했다.

`kubectl label namespace {ns} istion-injection enabled`와 같이 사용하게 되면 Label을 적용하여 해당 namespace에 올라온 pod에 대해 istio-proxy를 컨테이너에 추가한다.

여기서 겪었던 문제는 서비스 메시를 구성할 때 모든 서비스나 인프라에 대해서 적용하면 좋겠지만 모든 배포에 대해서 Proxy를 붙이다보니 드는 오버헤드가 생각보다 높다. 그래서 줄이는 방법을 구상한 것이 서비스 메시에 안 들어가도 되는 인프라가 있는 경우 빼주는 쪽으로 진행했다.

올릴 때 namespace에 label을 disabled 시켜서 진행하였다. 하지만 며칠 못 가서 K8s 업데이트로 인해 인프라가 재시작되는 이슈가 생겼다. 이 때 재시작으로 인해 같은 네임스페이스에 들어있어서 istio-proxy가 붙게되고 그만큼의 오버헤드가 또 발생하였다.

이러한 문제를 해결하기 위해서 helm을 통해서 필요한 서비스를 설치할 때 annotations에 `sidecar.istio.io/inject: "false"`를 등록하였다. helm을 통한 설치는 편하게 진행되지만 manifest에 대해서 모두 알지 못한 상태에서 진행되기 때문에 대부분의 설정 값을 알려면 values를 직접 찾아봐야한다.

따라서 annotations을 붙이는 부분에서 상당한 시간이 필요했다. 모든 서비스가 같은 템플릿을 이용해서 annotations을 정리하지 않고 또한 한 차트에서도 여러 Deployment나 statefulset을 이용하기 때문에 하나하나 모두 annotations을 달아줘야했다.

Istio가 분명 도움을 주는 부분도 많고 서비스를 구성하는데에 있어서 많은 역할을 하지만 그 만큼의 트레이드오프는 오버헤드라던지 공부같은 부분으로 나타나는 것 같다.

---

- 7 日

# PS

- Delete Operation for Two Strings

```go
func minDistance(word1 string, word2 string) int {
	m, n := len(word1), len(word2)
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	for i := range word1 {
		for j := range word2 {
			if word1[i] == word2[j] {
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1)
			} else {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
			}
		}
	}
	return m + n - 2*dp[m][n]
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
```

두 문자열에 겹치는 길이를 구하는 문제로 쉽게 dp를 이용해서 진행하였다.

---

- 8 日

# 2021 카카오 채용연계형 인턴십 for Tech Developers 코딩테스트

2021 카카오 채용연계형 인턴십 for Tech Developers에 지원하여 코딩테스트를 치뤘다. 지금까지 했던 문제들 중 까다로운 문제를 모아놓은 듯한 기분이였다.

생각보다 구현이 될 듯 했지만 테스트케이스 한 두개와 효율성 문제로 5문제 중 2.5솔일거라고 추측이 된다.

시간은 생각보다 넉넉했다고 생각되었지만 문제를 그대로 구현하였지만 테스트 케이스에서 틀린 부분이 많아서 상당한 허점이 있었다.

---

# PS

- Super Palindromes

```go
import (
    "sort"
    "strconv"
    "fmt"
)

var palindromes = []int{
	1, 2, 3,
	11, 22,
	101, 111, 121, 202, 212,
	1001, 1111, 2002,
	10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102,
	100001, 101101, 110011, 111111, 200002,
	1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002,
	10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 20000002,
	100000001, 100010001, 100020001, 100101001, 100111001, 100121001, 101000101, 101010101, 101020101, 101101101, 101111101, 110000011, 110010011, 110020011, 110101011, 110111011, 111000111, 111010111, 111101111, 111111111, 200000002, 200010002,
}

func superpalindromesInRange(L, R string) int {
	l, _ := strconv.Atoi(L)
	r, _ := strconv.Atoi(R)

	li := sort.Search(len(palindromes), func(i int) bool {
		return l <= palindromes[i]*palindromes[i]
	})

	ri := sort.Search(len(palindromes), func(i int) bool {
		return r <= palindromes[i]*palindromes[i]
	})

	return ri - li
}
```

Left ~ Right 값 중에 제곱근과 자기 자신이 펠린드롬인 값을 찾아서 갯수를 세어주는 문제이다.

하지만 golang에서 사용하는 math dependency에서는 모두 float64를 가지고 이용하다보니 생각보다 형변환에 대해서 엄격한 것을 알게 되었다. 소수점을 다 버리고 integer로 변환하는 과정에서 모든 다른 한 자리 숫자도 같다고 판명하여 계속 돌아가는 상황이 발생했다.

결국에는 직접 다 기입한 뒤 sort.Search를 이용하여 속하는 부분을 Upperbound와 Lowerbound를 구해서 가장자리에서 빼주는 식으로 했다.

이런 식의 하드코딩보다 직접 구할 수 있어야하는데 많이 미숙한 부분이 많다고 느꼈다.

---

- 9 日

# PS

- Construct Target Array With Multiple Sums

```go
import (
	"container/heap"
)
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	x := old[0]
	*h = old[1 : ]
	return x
}

type MaxHeap struct {
    IntHeap
}

func (h MaxHeap) Less(i, j int) bool { return h.IntHeap[i] > h.IntHeap[j] }

func isPossible(target []int) bool {
    h := &MaxHeap{}
    size := len(target)
    sum := 0
    for i:=0; i<size; i++ {
        sum += target[i]
        heap.Push(h,target[i])
    }
    heap.Init(h)

    for (*h).IntHeap[0] != 1 {
        top := (*h).IntHeap[0]
        h.Pop()
        sum -= top
        if top <= sum || sum < 1 {
            return false
        }
        top %= sum
        sum += top
        h.Push(top)
        heap.Init(h)
    }
    return true;
}
```

이번 문제는 문제풀이보다도 Golang에 맞는 priority queue를 구현하는 것을 공부하는 부분이 매우 많았다.

문제를 이해하는 것보다 우선순위 큐에 맞게 최소 힙이나 최대 힙을 구하려는게 쉽지 않았다.

container/heap 패키지에서 type을 정의하고 interface로 Len, Less, Swap을 정의하여 MinHeap을 정의하고 사용할 Push와 Pop 함수를 정의했다. 현재는 최소힙을 구현한 상황이다.

이제 최대힙으로 변경하여 사용하기 위해서 구조체를 사용하여 Less 함수를 만들어진 최소힙의 원소 중 큰 원소를 앞으로 가지고 오도록 바꿔서 사용하였다.

그 와중에 Peek를 구현하지 않고 Pop을 첫 인덱스를 제거하고 첫 인덱스를 사용하여 Peek를 대신하여 이용했다.

---
