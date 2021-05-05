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
