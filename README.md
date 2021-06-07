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

- 10 日

# PS

- Count Primes

```go
func countPrimes(n int) int {
    isPrime := make([]bool, n)

    for i := 2; i * i < n; i++ {
        if isPrime[i] == true {
            continue
        }
        for j := i * i; j < n; j += i {
            isPrime[j] = true
        }
    }

    cnt := 0
    for i := 2; i < n; i++ {
        if isPrime[i] == false {
            cnt++
        }
    }
    return cnt
}
```

1 ~ n까지의 숫자 중 소수를 구하는 문제로 에라토스테네스의 체를 이용해서 해결하였다. 사용하는 방법에 따라서 시간복잡도가 크게 나뉘어져서 해당 알고리즘을 사용하여 해결하였다.

---

- Maximum Points You Can Obtain from Cards

```go
func maxScore(nums []int, k int) int {
    aux := make([]int, len(nums))
    aux[0] = nums[0]
    for i := 1; i < len(nums); i++ {
        aux[i] = aux[i-1] + nums[i]
    }
    if len(nums) == k {
        return aux[len(nums)-1]
    }
    max := aux[k-1]
    for i := 1; i < k; i++ {
        tmp := aux[k-i-1] + aux[len(nums)-1] - aux[len(nums)-1-i]
        if tmp > max {
            max = tmp
        }
    }

    if max < aux[len(nums)-1] - aux[len(nums)-k-1] {
        max = aux[len(nums)-1] - aux[len(nums)-k-1]
    }
    return max
}
```

해당 인덱스까지의 합을 보여주는 aux라는 배열을 통해서 k개 만큼의 갯수를 유지하면서 가장 큰 값을 구하는 문제이다.

슬라이딩 윈도우를 이용해서 해당 크기만큼만의 윈도우를 가지고 쭉 밀어가면서 가장 큰 값을 구하였다.

---

- 12 日

# PS

- Range Sum Query 2D - Immutable

```go
type NumMatrix struct {
	Data [][]int
	Sum  [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	d := NumMatrix{Data: matrix, Sum: make([][]int, len(matrix)+1)}
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return d
	}
    d.Sum[0]= make([]int, len(matrix[0])+1)
	for i := 1; i <= len(matrix); i++ {
		d.Sum[i] = make([]int, len(matrix[0])+1)
		for j := 1; j <= len(matrix[0]); j++ {
			d.Sum[i][j] = d.Sum[i-1][j] + d.Sum[i][j-1] - d.Sum[i-1][j-1] + d.Data[i-1][j-1]
		}
	}
	return d
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.Sum[row2+1][col2+1] - this.Sum[row1][col2+1] - this.Sum[row2+1][col1] + this.Sum[row1][col1]
}


/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
```

생성자를 통해 matrix를 넣고 호출 시에는 왼쪽 상단에서 오른쪽 하단까지의 좌표를 통해서 사각형을 받고 그 범위의 합을 모두 구해주는 식으로 진행하였다.

---

# Kubernetes HPA

- [Kubernetes horizontal-pod-autoscale](https://kubernetes.io/ko/docs/tasks/run-application/horizontal-pod-autoscale/)
- [Kubernetes. Pod AutoScaling - 이야기박스님](https://box0830.tistory.com/305)

레퍼런스 사이트를 통해서 공부한 부분을 정리해본다.

HPA(Horizontal Pod Autoscaler)는 CPU 사용량이나 사용자 정의 메트릭을 수집하여 메트릭들을 기준으로 조건을 둔 뒤 스케일업과 다운을 진행할 수 있게 한다.

StatefulSet, Deployment, ReplicaSet, ReplicationController만 HPA를 통해 스케일업과 다운이 가능하다. Daemon Set의 경우에는 불가능하다.

추가적으로 이야기박스님의 포스팅으로 조금 더 이해할 수 있는 사례를 통해서 이해도를 높여보았다.

---

- 17 日

# PS

- Longest String Chain

```go
func longestStrChain(words []string) int {
    index := make([][]int, 17)
    count := make([]int, len(words))

    for i,v := range words {
        length := len(v)
        index[length] = append(index[length], i)
        count[i] = 1
    }

    for length := 1; length < 16; length++ {
        for _, i := range index[length] {
            for _, j := range index[length+1] {
                if count[j] > count[i] {
                    continue
                }
                if isPredecessor(words[i], words[j]) {
                    count[j] = count[i]+1
                }
            }
        }
    }

    ret := 0
    for _, v := range count{
        ret = max(ret, v)
    }
    return ret
}

func isPredecessor(a, b string)bool {
    i, j := 0, 0
    diff := 0
    for i < len(a) && diff <= 1 {
        if a[i] != b[j]{
            diff++
        } else {
            i++
        }
        j++
    }
    return i == j || diff <= 1
}

func max(a,b int)int {
    if a > b{
        return a
    }
    return b
}
```

---

- 18 日

# PS

- Find Duplicate File in System

```go
import "strings"
func findDuplicate(paths []string) [][]string {
    cache := map[string][]string {}
    for _, path := range paths {
        splits := strings.Split(path, " ")
        base := splits[0]
        for _, split := range splits[1:] {
            i := strings.Index(split, "(")
            fileName := split[:i]
            contents := split[i+1:]
            cache[contents] = append(cache[contents], base + "/" + fileName)
        }
    }
    ret := make([][]string, 0)
    for _, v := range cache {
        if len(v) > 1 {
            ret = append(ret, v)
        }
    }
    return ret
}
```

파일 경로가 주어졌을 때 괄호에 주어진 짝에 맞게 묶는 문제이다.

파일 경로에 따라서 파일 이름과 컨텐츠를 나누고 map을 이용하여 컨텐츠에 맞는 부분을 쭉 잇는 식으로 진행하였다.

그 뒤에는 반환형에 맞게 넣어줘서 반환하면 된다.

---

# Istio와 RabbitMQ

이스티오가 적용된 MSA에서 데이터 파이프라인을 구축하는 부분을 Event Driven과 같은 방향으로 메세지 큐를 이용하였다.

이 때 쿠버네티스 Job을 이용해서 데이터를 주고 받기 위해 메세지 큐를 사용하는 부분에서 문제가 생겨서 남길려고 한다.

Job이 뜬 뒤 바로 RabbitMQ와의 연결을 시도하게 되는데 이스티오가 적용되어있으므로 사이드카를 연결하고 시타델에서 CA 인증을 통해서 TLS를 적용하게 된다.

하지만 Job에서는 사이드카와 연결된 뒤 바로 RabbitMQ에 연결을 시도해서 RabbitMQ에서는 보안 연결이 아니라 거부하게 되는 것 같다.

이러한 부분을 가설을 세우고 진행해보았는데 이스티오 사이드카 주입을 끈 상태로 같은 이미지로 진행하였을 때는 에러가 나오지 않고 주입 되었을 때만 에러가 나오는 것을 확인할 수 있었다.

로그 상에서도 메시지 큐와의 연결 에러가 뜬 직후 시타델에 관한 로그가 찍혀나와서 어느 정도 가설이 맞다고 할 수 있을 것 같다.

확실히 해결하기 위해서는 메시지 큐와의 연결을 시타델에서 인증을 부여한 후로 미루면 될 것 같은데 이 부분에 있어서는 좋은 방향이 떠오르지 않아서 일단은 잡에서는 서비스 메시를 주입하지 않는 방향으로 생각해보았다.

---

- 19 日

# PS

- Minimum Moves to Equal Array Elements II

```go
import (
    "math"
    "sort"
)

func minMoves2(nums []int) int {
    sort.Ints(nums)
    ans := 0
    avg := nums[len(nums)/2]

    for _, val := range nums {
        ans += int(math.Abs(float64(val - avg)))
    }
    return ans
}
```

배열의 모든 숫자가 같은 숫자로 될 때 최소의 숫자를 구하는 문제이다.

따라서 정렬을 한 뒤 가장 가운데 있는 숫자를 기준으로 모든 숫자의 차이를 구해서 더하는 식으로 진행하였다.

---

- 20 日

# PS

- Binary Tree Level Order Traversal

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	queue := []*TreeNode{}
	queue = append(queue, root)
	curNum, nextLevelNum, res, tmp := 1, 0, [][]int{}, []int{}
	for len(queue) != 0 {
		if curNum > 0 {
			node := queue[0]
			if node.Left != nil {
				queue = append(queue, node.Left)
				nextLevelNum++
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
				nextLevelNum++
			}
			curNum--
			tmp = append(tmp, node.Val)
			queue = queue[1:]
		}
		if curNum == 0 {
			res = append(res, tmp)
			curNum = nextLevelNum
			nextLevelNum = 0
			tmp = []int{}
		}
	}
	return res
}
```

이진트리에서 같은 레벨에 속한 노드들을 배열로 모은 뒤 이차원 배열로 반환해주는 문제이다.

따라서 BFS와 같이 레벨별로 구해서 배열에 넣어서 반환하는 배열에 넣어주는 식으로 진행한다.

---

- 21 日

# PS

- Find and Replace Pattern

```go
func findAndReplacePattern(words []string, pattern string) []string {
	res := make([]string, 0, len(words))

	m := matchPattern(pattern)
	for _, s := range words {
		if matchPattern(s) == m {
			res = append(res, s)
		}
	}

	return res
}

func matchPattern(s string) int64 {
	var p, i int64
	match := make(map[rune]int64)

	for _, v := range s {
		if match[v] == 0 {
			i++
			match[v] = i
		}

		p = p*10 + match[v]
	}

	return p
}
```

알파벳들이 주어지는 문자열의 패턴을 구해서 알파벳들을 바꾸었을 때 같은 모양이 될 수 있는 문자열들을 구하는 문제이다.

따라서 처음에 나온 알파벳들을 나온 순서대로 숫자로 매핑하여 바꿔주게 된다면 문자열의 패턴을 알 수 있다.

이 때 rune 자료형을 이용하여 utf-8을 표현하며 map으로 나온 순서를 유지하도록 하였다.

---

- 22 日

# PS

- N-Queens

```go
func solveNQueens(n int) [][]string {
	res := make([][]string, 0)
	sol := initialSolution(n)

	backtrack(&res, sol, 0, n)
	return res
}

func backtrack(res *[][]string, sol [][]byte, col int, n int) {
	if col == n {
		collectSolution(res, sol)
		return
	}
	for i := 0; i < n; i++ {
		if isValid(sol, i, col, n) {
			sol[i][col] = 'Q'
			backtrack(res, sol, col+1, n)
			sol[i][col] = '.'
		}
	}
}

func initialSolution(n int) [][]byte {
	res := make([][]byte, 0)
	for i := 0; i < n; i++ {
		tmp := make([]byte, n)
		for j := range tmp {
			tmp[j] = '.'
		}
		res = append(res, tmp)
	}
	return res
}

func collectSolution(res *[][]string, sol [][]byte) {
	tmp := make([]string, 0)
	for i := range sol {
		tmp = append(tmp, string(sol[i]))
	}
	*res = append(*res, tmp)
}

func isValid(tmp [][]byte, row, col, n int) bool {
	for i := 0; i < col; i++ {
		if tmp[row][i] == 'Q' {
			return false
		}
	}
	for i, j := row, col; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if tmp[i][j] == 'Q' {
			return false
		}
	}
	for i, j := row, col; i < n && j >= 0; i, j = i+1, j-1 {
		if tmp[i][j] == 'Q' {
			return false
		}
	}
	return true
}
```

전형적인 N-Queen 문제로 유효한 자리인지 체크해가면서 맞는 위치를 골라가는 식으로 진행하였다.

백트래킹을 진행하면서 세로를 기준으로 잡고 가로와 대각선에 퀸이 있는지 확인을 통해서 유효함을 체크한다.

---

- 23 日

# PS

- Find the Shortest Superstring

```go
func shortestSuperstring(A []string) string {
    n := len(A)
    // adjacent map
    // A[i] = "ab", A[j] = "abcde"
    // adj_map[i][j] = 3, it means that we can only add 3 char in A[j]
    // after A[i]
    adj_map := make([][]int, n)
    for i:=0; i<n; i++ {
        adj_map[i] = make([]int, n)
        for j:=0; j<n; j++ {
            aj, ai := []byte(A[j]), []byte(A[i])
            adj_map[i][j] = len(aj)
            for k:=1; k<=min(len(ai), len(aj)); k++ {
                if string(ai[len(ai)-k:]) == string(aj[:k]) {
                    adj_map[i][j] = len(aj) - k
                }
            }
        }
    }

    // dp[s][i] := min distance to visit nodes
    // (represented as a binary state s) once and only once
    // and the path ends with node i.
    dp := make([][]int, 1<<uint(n))
    // record the path
    parent := make([][]int, 1<<uint(n))
    // dp[7][1] is the min distance to visit nodes (0, 1, 2)
    // and ends with node 1, the possible paths could be
    // (0, 2, 1), (2, 0, 1). parent[7][1] could be 2 or 0

    // init dp and parent
    for i:=0; i<(1<<uint(n)); i++ {
        dp[i] = make([]int, n)
        parent[i] = make([]int, n)
        for j:=0; j<n; j++ {
            dp[i][j] = math.MaxInt32
            parent[i][j] = -1
        }
    }


    // Init
    for i:=0; i<n; i++ {
        dp[1<<uint(i)][i] = len([]byte(A[i]))
    }

    // Transition
    for s:=1; s<(1<<uint(n)); s++ {
        for j:=0; j<n; j++ {
        	// if node j is not in s, skip
            if s & (1<<uint(j)) == 0 { continue }
            // remove node j from s
            ps := s & ^(1<<uint(j))
            // test all the parent of j
            for i:=0; i<n; i++ {
            	// find out the i with min(dp[ps][i] + adj_map[i][j])
            	// record it in dp[s][j] and parent[s][j]
                if dp[ps][i] + adj_map[i][j] < dp[s][j] {
                    dp[s][j] = dp[ps][i] + adj_map[i][j]
                    parent[s][j] = i;
                }
            }
        }
    }

    // find out the last node in shortest path
    j, min := 0, math.MaxInt32
    for i:=0; i<n; i++ {
    	fmt.Println(dp[(1<<uint(n))-1][i], i)

        if dp[(1<<uint(n))-1][i] < min {
            min = dp[(1<<uint(n))-1][i]
            j = i
        }
    }

    // get the whole path by parent[s][j]
    // and build the Shortest Superstring
    s := (1<<uint(n)) -1
    ans := ""
    for s!=0 {
        i := parent[s][j]
        if i < 0 {
            ans = A[j] + ans
        } else {
            adj := []byte(A[j])
            ans = string(adj[len(adj)-adj_map[i][j]:]) + ans
        }
        s &= ^(1<<uint(j))
        j = i
    }
    return ans
}


func min(a, b int) int {
    if a < b { return a }
    return b
}
```

주어진 문자열을 전부 가지고 있는 문자열 중 가장 짧은 문자열을 반환하는 문제이다.

처음에 갈피를 못 잡고 DFS를 이용했으나 시간이 너무 오래걸리는 듯해서 다른 사람의 풀이를 보고 공부하였다.

DP를 이용하여 만드는 과정을 보여주고 있다.

---

- 24 日

# PS

- To Lower Case

```go
import (
    "strings"
)

func toLowerCase(s string) string {
    return strings.ToLower(s)
}
```

주어진 문자열을 모두 소문자로 바꾸는 문제이다. 다른 언어와 달리 golang에는 문자열 자체를 소문자로 바꿔주는 함수를 이용할 수 있다.

---

- 25 日

# PS

- Evaluate Reverse Polish Notation

```go
func evalRPN(tokens []string) int {
	if len(tokens) == 1 {
		i, _ := strconv.Atoi(tokens[0])
		return i
	}
	stack, top := []int{}, 0
	for _, v := range tokens {
		switch v {
		case "+": {
				sum := stack[top-2] + stack[top-1]
				stack = stack[:top-2]
				stack = append(stack, sum)
				top--
			}
		case "-": {
				sub := stack[top-2] - stack[top-1]
				stack = stack[:top-2]
				stack = append(stack, sub)
				top--
			}
		case "*": {
				mul := stack[top-2] * stack[top-1]
				stack = stack[:top-2]
				stack = append(stack, mul)
				top--
			}
		case "/": {
				div := stack[top-2] / stack[top-1]
				stack = stack[:top-2]
				stack = append(stack, div)
				top--
			}
		default: {
				i, _ := strconv.Atoi(v)
				stack = append(stack, i)
				top++
			}
		}
	}
	return stack[0]
}
```

후위연산을 하는 문제로 스택을 이용해서 해결할 수 있다.

---

- 26 日

# PS

- Partitioning Into Minimum Number Of Deci-Binary Number

```go
func minPartitions(n string) int {
    result := 0
    for _, num  := range n{
        m, _ := strconv.Atoi(string(num))
        if m > result{
            result = m
        }
    }
    return result
}
```

1과 0을 가지고 해당 문자열을 만들 수 있는지 찾는 문제이다.

결국에는 해당 자릿수들 중 가장 큰 숫자를 가진것이 결과가 된다고 말할 수 있다.

321 = 111 + 110 + 100와 같이 자릿수에서 가장 큰 숫자 만큼 반복하면 찾을 수 있다.

---

- 27 日

# PS

- Maximum Product of Word Lengths

```go
func maxProduct(words []string) int {
	wlen := len(words)
	wtables := make([]int32, wlen)

	for i := 0; i < wlen; i++ {
		wtables[i] = helper(words[i])
	}

	max := 0
	for i := 0; i < wlen; i++ {
		for j := i + 1; j < wlen; j++ {
			if wtables[i] & wtables[j] == 0 {
				if prod := len(words[i]) * len(words[j]); prod > max {
					max = prod
				}
			}
		}
	}
	return max
}

func helper(word string) int32 {
	var res int32
	for i := 0; i < len(word); i++ {
		res |= 1 << uint(26-(int(word[i])-int('a')))
	}
	return res
}
```

겹치지않는 두 문자열의 길이 곱 중 가장 큰 값을 구하는 문제이다.

겹치지 않는 경우를 찾아서 두 개의 곱이 가장 큰 값을 저장하여 반환하는 식으로 진행된다.

---

- 28 日

# PS

- Maximum Erasure Value

```go
func maximumUniqueSubarray(nums []int) int {
    res := 0
    acc := 0
    set := map[int]bool{}
    l := -1
    for _, value := range nums {
        for set[value] {
            l++
            acc -= nums[l]
            delete(set, nums[l])
        }
        acc += value
        set[value] = true
        res = max(res, acc)
    }

    return res
}

func max(a, b int) int {
    if a < b { return b }
    return a
}
```

중복되지 않은 숫자들의 부분 문자열의 합 중 가장 큰 값을 구하는 문제이다.

따라서 인덱스 처음부터 따라가되, 겹친 경우에는 빼면서 진행한다.

---

- 29 日

# PS

- N-Queens II

```go
func totalNQueens(n int) int {
    count := 0
    cols := make([]bool, n)
    for i := 0; i < len(cols); i++ {
        cols[i] = false
    }

    d1 := make([]bool, 2*n)
    d2 := make([]bool, 2*n)
    for i := 0; i < len(cols); i++ {
        d1[i] = false
        d2[i] = false
    }

    dfs(0, cols, d1, d2, n, &count)

    return count;
}

func dfs(row int, cols []bool, d1 []bool, d2 []bool, n int, count *int) {
    if(row == n) {
        *count++
    }
    for col := 0; col < n; col++ {
        id1 := col - row + n;
        id2 := col + row;
        if cols[col] || d1[id1] || d2[id2] {
            continue
        }
        cols[col] = true; d1[id1] = true; d2[id2] = true;
        dfs(row + 1, cols, d1, d2, n, count)
        cols[col] = false; d1[id1] = false; d2[id2] = false;
    }
}
```

N-Queen 문제에 이어서 가로세로 길이를 받아서 N-Queen의 가능한 수를 구하는 문제이다.

---

- 30 日

# PS

- Maximum Gap

```go
func maximumGap(nums []int) int {
    res := 0
    sort.Ints(nums)
    prev := nums[0]
    for _, val := range nums {
        res = max(val - prev, res)
        prev = val
    }
    return res
}

func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}
```

일차원 배열 중 인접한 숫자의 갭이 가장 큰 값을 반환하는 문제이다.

따라서 정렬한 뒤 이전 값과 현재의 값의 차이 중 가장 큰 값을 반환하도록 하였다.

---

- 31 日

# PS

- Search Suggestions System

```go
func suggestedProducts(products []string, searchWord string) [][]string {
	res := make([][]string, len(searchWord))
	sort.Strings(products)
	s := ""

	for i, val := range searchWord {
		s += string(val)
		counter := 0
		for _, product := range products {
			if counter == 3 {
				break
			}
			if strings.HasPrefix(product, s) {
				counter++
				res[i] = append(res[i], product)
			}
		}
	}
	return res
}
```

주어진 문자열의 각 인덱스만큼의 길이를 전치사로 갖는 문자 3개 이하를 배열로 만들어서 반환하는 문제이다.

생각을 그대로 golang으로 구현하면 위와 같이 될 수 있다.

---

- 1 日

# PS

- Max Area of Island

```go
func maxAreaOfIsland(grid [][]int) int {
    maxArea := 0
    for y := 0; y < len(grid); y++ {
        for x := 0; x < len(grid[y]); x++ {
            if grid[y][x] > 0 {
                if sum := sumIslandArea(grid, y, x); sum > maxArea {
                    maxArea = sum
                }
            }
        }
    }
    return maxArea
}

func sumIslandArea(grid [][]int, y int, x int) int {
    sum := 1
    grid[y][x] = 0

    if y > 0 && grid[y-1][x] > 0 {
        sum += sumIslandArea(grid, y-1, x)
    }
    if x <  len(grid[y])-1 && grid[y][x+1] > 0 {
        sum += sumIslandArea(grid, y, x+1)
    }
    if y < len(grid)-1 && grid[y+1][x] > 0 {
        sum += sumIslandArea(grid, y+1, x)
    }
    if x > 0 && grid[y][x-1] > 0 {
        sum += sumIslandArea(grid, y, x-1)
    }
    return sum
}
```

필드가 주어지고 가장 큰 넓이를 가진 섬의 크기를 반환하는 문제이다.

따라서 DFS, BFS 두 가지 방법을 통해서 구할 수 있다고 생각된다.

DFS로 가장 큰 값을 구하도록 진행하였다.

---

- 2 日

# PS

- Interleaving String

```go
func isInterleave(s1 string, s2 string, s3 string) bool {
	if len(s1)+len(s2) != len(s3) {
		return false
	}

	dp := make([][]bool, len(s1)+1)
	for i, _ := range dp {
		dp[i] = make([]bool, len(s2)+1)
	}
	dp[0][0] = true

	for i := 1; i <= len(s1); i++ {
		dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1]
	}
	for j := 1; j <= len(s2); j++ {
		dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1]
	}

	for i := 1; i <= len(s1); i++ {
		for j := 1; j <= len(s2); j++ {
			dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i-1+j]) ||
				(dp[i][j-1] && s2[j-1] == s3[j-1+i])
		}
	}

	return dp[len(s1)][len(s2)]
}
```

s1과 s2가 재조합되었을 때 s3가 될 수 있으면 true, 아니면 false를 반환하는 문제이다.

따라서 DP를 이용해서 s1과 s2가 가능한 경우를 골라서 true와 false를 밝혀가는 식으로 진행한다.

---

- 3 日

# PS

- Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

```go
func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
    sort.Ints(horizontalCuts)
    sort.Ints(verticalCuts)
    hlen := len(horizontalCuts)
    vlen := len(verticalCuts)
    maxh := max(horizontalCuts[0], h - horizontalCuts[hlen-1])
    maxv := max(verticalCuts[0], w - verticalCuts[vlen-1])

    for i := 1; i < hlen; i++ {
        maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1])
    }
    for i := 1; i < vlen; i++ {
        maxv = max(maxv, verticalCuts[i] - verticalCuts[i-1])
    }

    return (maxh * maxv) % 1000000007
}

func max(a, b int) int{
    if a > b {
        return a
    }
    return b
}
```

절단면이 가로와 세로가 주어졌을 때 절단된 부분 들 중 가장 넓이가 큰 값을 구하는 문제이다.

따라서 주어진 절단면들을 모두 정렬한 뒤 이전 값과 다음 값의 갭이 가장 큰 부분을 구한 뒤 넓이를 구하기 위해서 곱해주는 식으로 진행했다.

---

- 7 日

# PS

- Min Cost Climbing Stairs

```go
func minCostClimbingStairs(cost []int) int {
	for i := 2; i < len(cost); i++ {
		cost[i] += min(cost[i-1], cost[i-2])
	}
	return min(cost[len(cost)-1], cost[len(cost)-2])
}

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}
```

한 칸 혹은 두 칸씩 올라가면서 끝까지 올라갔을 때 가장 적은 비용으로 도착하는 비용은 무엇인가인 문제이다.

따라서 DP를 이용해서 1칸과 2칸 중 가장 cost가 낮은 값을 구해서 계속 끝까지 나아가는 식으로 진행한다.

---
