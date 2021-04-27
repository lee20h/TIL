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

| [1월](./years/2021/1월.md) | [2월](./years/2021/2월.md) | [3월](./years/2021/3월.md) |
| -------------------------- | -------------------------- | -------------------------- |

---

- 1 日

# 카카오게임즈 Devops 엔지니어 기술 면접

카카오게임즈 DevOps 엔지니어 기술 면접을 봤다. 알파돔타워에 있는 카카오게임즈에 가서 면접을 보게되었는데, 면접관님들이 전체적으로 경청해주는 모습을 보여주셔서 좋았다.

질문 내용도 확실히 자기소개서와 이력서에 쓰인 부분에서 질문이 많았고 따로 직무에 대한 경험이나 이유를 물어보는 것이 많았다.

끝으로 갈수록 가정하고 아키텍쳐를 그리거나 상황에 대해서 일어나는 일에 대해서 다 서술하는 기술 질문이 이어졌다. 이 부분에 있어서 대단히 공부할 수 있었다. 처음 보는 내용도 많았으며 이번에 경험을 하길 잘했다는 생각이 들었다.

인터뷰 질문 내용은 정리해서 다시 나중에 한번씩 꺼내보고 나중에는 다 깔끔하게 대답할 수 있게 준비해야겠다.

---

# PS

- Palindrome Linked List

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null)
            return true;

        ListNode p = head;
        ListNode prev = new ListNode(head.val);

        while(p.next != null){
            ListNode temp = new ListNode(p.next.val);
            temp.next = prev;
            prev = temp;
            p = p.next;
        }

        ListNode p1 = head;
        ListNode p2 = prev;

        while(p1!=null){
            if(p1.val != p2.val)
                return false;

            p1 = p1.next;
            p2 = p2.next;
        }

        return true;
    }
}
```

연결리스트가 있을 때 이 연결리스트가 펠린드롬인지 아닌지 반환하는 메서드를 만드는 문제이다. 단순하게 연결리스트 두 개를 통해서 같은지 비교해서 풀었다. 하지만 공간과 시간 복잡도가 O(n)으로 나오게 되는데 힌트에 보면 공간 복잡도를 O(1)로 가능한 풀이가 있다고 하여 찾아봐서 밑에 정리하였다.

```java
public boolean isPalindrome(ListNode head) {

    if(head == null || head.next==null)
        return true;

    //find list center
    ListNode fast = head;
    ListNode slow = head;

    while(fast.next!=null && fast.next.next!=null){
        fast = fast.next.next;
        slow = slow.next;
    }

    ListNode secondHead = slow.next;
    slow.next = null;

    //reverse second part of the list
    ListNode p1 = secondHead;
    ListNode p2 = p1.next;

    while(p1!=null && p2!=null){
        ListNode temp = p2.next;
        p2.next = p1;
        p1 = p2;
        p2 = temp;
    }

    secondHead.next = null;

    //compare two sublists now
    ListNode p = (p2==null?p1:p2);
    ListNode q = head;
    while(p!=null){
        if(p.val != q.val)
            return false;

        p = p.next;
        q = q.next;

    }

    return true;
}
```

사실 아직도 왜 공간복잡도가 O(1)인지 모르겠다.......

ListNode가 두개로 비교하는건 같지 않나 생각해본다.

---

# PS

- Ones and Zeroes

```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m+1][n+1];
        for (int s = strs.length-1; s>=0;s--) {
            int[] count = count(strs[s]);
            for (int i=m;i>=0;i--)
                for (int j=n;j>=0;j--)
                    if (i >= count[0] && j >= count[1])
                       dp[i][j] = Math.max(1 + dp[i-count[0]][j-count[1]], dp[i][j]);
        }
        return dp[m][n];
    }

    public int[] count(String str) {
        int[] res = new int[2];
        Arrays.fill(res, 0);
        for (int i=0;i<str.length();i++) {
            if (str.charAt(i) == '0') res[0]++;
            else res[1]++;
        }
        return res;
     }
}
```

1과 0의 갯수가 정해졌을 때 문자열의 배열 중에서 1과 0의 갯수가 맞는 부분집합을 찾되, 가장 많은 배열의 원소가 선택되어야한다.

따라서 해당 문자열의 0과 1의 갯수를 세어준 다음 dp를 통해서 0과 1의 갯수를 빼주면서 최대 갯수를 찾아준다.

---

# Kubernetes RBAC

RBAC란 Role Based Access Control의 약자로 역할 기반으로 접근을 통제하는 것이다.

- 레퍼런스
  - [API연결로 확인하는 RBAC](https://bryan.wiki/291)
  - [쿠버네티스 권한관리](https://arisu1000.tistory.com/27848)

Rule들을 Role이나 ClusterRole에 정의하고 Service Account와 연결하는 RoleBinding 이나 ClusterRoleBinding을 통해서 RBAC를 이용한다.

이 때 Role과 ClusterRole의 차이는 Role의 경우에는 한 Namespace에만 종속되지만 ClusterRole은 클러스터 어디서든 사용할 수 있다는 것이 차이점이다.

Kubernetes의 API Server에 직접 REST API로 요청하는 모듈을 만들고 있는데 이 때 사용하는데 필요한 부분이라 공부를 진행하였다.

API-Server에 직접적으로 REST API를 요청할 때 해당 Service Account의 Token이 필요하다. 토큰을 얻고 헤더에 넣어서 인증을 처리해주며, 원하는 API를 요청하는 식으로 모듈을 만들어가고 있다.

이 때 API는 Job을 지우는 방법은 하나씩 지우거나, Namespace의 모든 JOb을 지우는 방법 2가지로 나뉘어진다. 또한 Job을 지운다고 Pod도 같이 지워지는 것이 아니라 직접 두번 API를 호출해야했다.

또한 원하는 Job을 지우기 위해서는 먼저 get을 통해 Namespaec의 모든 Job을 받아온 뒤 거기서 원하는 이름의 Job을 정규표현식을 통해서 원하는 이름만 뽑아내서 지우는 API를 요청하는 식으로 진행한다면 조금 더 유틸리티가 올라가는 것을 볼 수 있다.

API 레퍼런스에도 상당히 많고 이 부분에 있어서 많은 종류의 내용이 있으며 번역이 안된 부분이 많아 공부하는데 많은 시간이 필요했다.

---

- 3 日

# 2021 카카오메이커스 신입 백엔드 개발자 코딩테스트

4월 3일 13시 ~ 15시동안 진행한 코딩테스트로, JAVA언어만 지원 가능하다.

문제는 총 3문제로 난이도는 백준 실버1 수준인 것 같다. 언어에 조금 더 익숙했더라면 더 빨리 풀 수 있었지 않을까 생각이 든다.

문제 풀이는 한 시간 정도 걸렸고 cpp로만 공부를 진행했어서 바로 Java로 투영시키는게 오래 걸렸다.

구현과 DFS를 이용해서 풀이를 진행했다.

---

# 2021 Dev-Matching: 웹 백엔드 개발자(상반기)

프로그래머스에서 진행한 채용 프로그램으로 카카오 엔터프라이즈와 당근 마켓 두 회사에 지원을 했다.

원래 사용하던 CPP을 사용하지 못하니 JavaScript로 진행하였는데 이게 문제가 있었다. 레퍼런스를 읽는 시간과 생각한 내용을 그대로 언어로 옮기지 못해서 220점을 맞았다. 두 문제 모두 전체적으로 풀이를 생각해냈는데 아쉽게도 매끄러운 코딩을 하지 못해서 좋지 않았던 것 같다.

너무 아쉬운 진행이라 코테를 넘기지 못할 것 같다.

---

# PS

- Longest Valid Parentheses

```java
class Solution {
    public int longestValidParentheses(String str){
        int n = str.length();
        Stack<Integer> st = new Stack<>();
        st.push(-1);

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == '(')
                st.push(i);

            else {
                if(!st.empty())
                    st.pop();
                if (!st.empty())
                    result = Math.max(result, i - st.peek());
                else
                    st.push(i);
            }
        }
        return result;
    }
}
```

유효한 부분문자열의 길이를 구하는 문제이다. 괄호의 갯수가 아닌 연속적인 유효한 부분문자열의 길이이므로 O(n)으로 쭉 훑으면서 가장 긴 길이를 반환해준다.

---

- 4 日

# PS

- Design Circular Queue

```java
class MyCircularQueue {
    final int[] a;
    int front, rear = -1, len = 0;

    public MyCircularQueue(int k) { a = new int[k];}

    public boolean enQueue(int val) {
        if (!isFull()) {
            rear = (rear + 1) % a.length;
            a[rear] = val;
            len++;
            return true;
        }
        return false;
    }

    public boolean deQueue() {
        if (!isEmpty()) {
            front = (front + 1) % a.length;
            len--;
            return true;
        }
        return false;
    }

    public int Front() { return isEmpty() ? -1 : a[front];}

    public int Rear() {return isEmpty() ? -1 : a[rear];}

    public boolean isEmpty() { return len == 0;}

    public boolean isFull() { return len == a.length;}
}
```

원형 큐를 구현하는 문제로 클래스만 구현하면 되는 문제이다. 따라서 배열로 가볍게 구현하였다. 물론 덱이나 다른 자료구조를 사용해도 좋을 것 같다.

---

- 5 日

# PS

- Global and Local Inversions

```java
class Solution {
    public boolean isIdealPermutation(int[] A) {
        int max = -1;
        for (int i = 2; i < A.length; i++) {
            max = Math.max(max, A[i - 2]);
            if (max > A[i])
                return false;
        }
        return true;
    }
}
```

0 ~ n-1 까지의 순열이 주어질 때 다음 두 조건을 모두 충족시키는지 확인하는 문제이다.

```
The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].
```

따라서 인덱스 2 차이나는 숫자를 비교하여 지금까지 나온 숫자보다 지금 나오는 숫자가 작다면 충족하지 않으므로 false를 반환한다.

---

# 카카오게임즈 및 2021 상반기 백엔드 데브매칭 회고

카카오게임즈는 Devops 엔지니어 면접을 보고 데브매칭은 여러 회사의 클라우드쪽이나 플랫폼 개발 직무에 대해 지원했었다. 오늘 불합격을 통보받았다.

두 경험 모두 너무 좋은 경험이였다. 기술면접을 처음 보면서 긴장도 되고 제대로 대답하지 못한 부분도 많았다. 주로 CS지식과 아키텍쳐에 관해서 많이 질문을 하셨다. 다음에도 이런 기회가 있다면 그 때는 꼭 붙잡을 수 있게 공부를 정진해야겠다.

또한 데브매칭을 통해 코딩테스트를 진행하였는데 주로 문제를 풀 때 사용하던 언어인 CPP를 사용하지못해 생각보다 제약이 많았다. 모든 문제의 해결하는 방법을 생각하였지만 코드로 옮기는 작업에서 많이 미숙한 것이 이유이다.

계속 공부를 해서 그런지 코딩테스트 난이도가 낮게 나온건지 잘 모르겠지만 풀이가 쉽게 되었던 것이 뿌듯했지만 언어의 장벽을 넘지 못하여서 급하게 자바스크립트를 통해서 풀이를 했다.

나중에는 자바 언어를 계속 공부하여 쉽게 도전했으면 좋겠다. 여담으로는 Golang에 대해서 관심이 커져가는 나날이다.

---

- 6 日

# PS

- Minimum Operations to Make Array Equal

```java
class Solution {
    public int minOperations(int n) {
        int ans = 0;
        int sum = 0;
        int arr[] = new int[n+1];
        for(int i=1; i<=n; i++) {
            arr[i] += 2 * i + 1;
            sum += arr[i];
        }
        int target = sum / n;

        for(int i=1; i<=n/2; i++) {
            ans += target - arr[i];
        }

        return ans;
    }
}
```

```go
func minOperations(n int) int {
    ans := 0;
    if n % 2 == 0 {
        for i := 0; i < n/2; i++ {
            ans += (i*2)+1;
        }
    } else {
        for i := 0; i < n/2; i++ {
            ans += ((n-1)/2)*2+1;
            ans -= ((i*2)+1);
        }
    }
    return ans;
}
```

(2\*i)+1 의 값을 가진 배열이 주어질 때 모든 배열이 같은 값이 될 때 까지 중앙 값보다 큰 값은 -1 작은 값은 +1이 이뤄질 때 횟수를 세는 문제이다.

먼저 Java로 생각한 내용을 그대로 서술해서 풀이해보았다. sum과 배열을 구한 뒤 n으로 나눠 target 값을 구한 뒤 배열 처음부터 중앙까지 target에서 빼준 값을 answer 변수에 더해주어 반환해주었다.

이러한 방식이 되는 이유는 인덱스에 해당하는 부분과 반대 부분은 같이 변하기 때문에 한 쪽만 세어주어도 된다.

이후 Golang으로 다시 풀이해보았다.

이번에는 배열의 사이즈를 구한 뒤 짝수라면 배열의 원소 값을 인덱스 중앙까지 그대로 더해주고 홀수라면 target 값을 더한 뒤 현재 인덱스 값을 빼주었다. golang에 경우에는 아직 미숙한 부분이 많다.

---

# NPM 패키지 만들기

쿠버네티스틀 활용하면서 여러 가지 업무를 하다보니 불편한 점이 있었다. 바로 Job의 결과가 쿠버네티스 콘솔에 남아 있다는 것이다. Job이 생성한 Pod은 완료된 후 사라지지만 Job은 남아있어서 CronJob이나 쿠버네티스 오브젝트 코드레벨에서 API나 함수로써 호출하여 만든 Job은 남아있다는게 문제였다.

이러한 문제를 TTL을 사용하면 된다는 쿠버네티스의 레퍼런스가 있지만 이 기능은 알파레벨로 갑자기 사라질 수도 있고 기술적 지원이 제대로 되지 않는 버전이라는 점이 매우 걸렸다. 그리고 해당 기능을 활성화시킬려면 API-server에 직접 접근해서 활성화해야한다는 점도 있었다.

따라서 다른 사람들이 만든 npm을 이용하여 완료된 Job만 지우는 모듈을 만들려고 했다. 하지만 이 부분에서도 글도 많이 없으며 패키지에서는 Job은 지워지지만 Pod은 남는 현상이 일어났다. 결국에는 직접 만들기로 마음 먹었다.

## 모듈 제작

먼저 쿠버네티스 API에 대해서 레퍼런스를 읽으면서 이해를 하였다. 그 다음에는 JS를 이용하여 클래스를 만들어가며 쿠버네티스 Pod에 올라가서 설정 파일에 접근하여 원하는 namespace, token을 취득하여 이용하였다. 그 과정에 있어 디버깅이나 결과물을 볼려면 무조건 컨테이너 이미지를 빌드하여 쿠버네티스에 올려야한다는 불편함이 있었다. 계속 이미지를 빌드하고 GCP Container Registry에 푸쉬한 뒤 해당 이미지를 띄워서 로그를 읽어보는 식으로 진행했다.

`kubectl proxy`를 이용해서도 api-server에 접근할 수 있으나 필요한 토큰과 설정 정보에 대해 제대로 접근할 수 있는가에 대해 자신이 없어서 이러한 방식으로 진행하였다.

## 결과물

- [npmjs job-clean](https://www.npmjs.com/package/job-clean)

결국 직접 배포까지 하는 경험을 할 수 있었다. 하지만 Readme를 잘 쓰지 못해 아쉽긴 하지만 쿠버네티스의 아키텍쳐와 전반적인 부분에 대해서 공부를 할 수 있어 좋은 경험을 했다고 생각이 든다. 자바스크립트 상에서 파일에 접근하는 부분과 rest api에 인증과 http관련 지식도 얻을 수 있었다.

---

- 7 日

# 2021 상반기 백엔드 데브매칭

결론적으로는 불합격이였다. 빠르게 해결한 뒤 제출했지만 아직 부족한 부분이 많아 체크하지 못한 부분이 수두룩 한듯 보였다. 아쉽지만 다음에는 더 잘할 수 있게 시도해보아야겠다.

---

# PS

- Determine if String Halves Are Alike

```java
class Solution {
    String vowels = "aeiouAEIOU";

    public boolean halvesAreAlike(String S) {
        int mid = S.length() / 2, ans = 0;
        for (int i = 0, j = mid; i < mid; i++, j++) {
            if (vowels.indexOf(S.charAt(i)) >= 0) ans++;
            if (vowels.indexOf(S.charAt(j)) >= 0) ans--;
        }
        return ans == 0;
    }
}
```

모음이 시작하는 인덱스부터 다음 모음이나 문자열 끝까지의 갯수가 같은지 확인하는 문제이다. 같으면 true 틀리면 false를 반환하면 된다.

따라서 모음이 있는지 확인한 뒤 절반만큼 확인하여 문제가 있는지 확인한ㄷ.

---

- 8 日

# PS

- Letter Combinations of a Phone Number

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> ret = new LinkedList<String>();
        if(digits.isEmpty()) return ret;
        String[] mapping = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ret.add("");
        while(ret.peek().length()!=digits.length()){
            String remove = ret.remove();
            String map = mapping[digits.charAt(remove.length())-'0'];
            for(char c: map.toCharArray()){
              ret.addLast(remove+c);
            }
        }
        return ret;
    }
}
```

```go
func letterCombinations(digits string) []string {
	table := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	ret := []string{};
	if len(digits) > 0 {
		help(&ret, digits, "", 0, table);
	}
	return ret
}

func help(ret *[]string, digits string, cur string, index int, table []string) {
	if index == len(digits) {
		*ret = append(*ret, cur);
		return
	}
	tmp := table[digits[index]-'0'];
	for _, t := range tmp {
		help(ret, digits, cur+string(t), index+1, table);
	}
}
```

- [golang](https://www.codingnuri.com/golang-book/6.html)

핸드폰 키패드와 같이 숫자가 주어질 때 가능한 알파벳들의 조합을 모두 반환하는 문제이다.

여기서는 java로 큐 형태로 해결하였고 Golang은 재귀를 이용해서 해결하였다.

Golang의 for문 문법중에 언더스코어를 이용한 문법을 찾아보게 되어서 링크를 같이 남긴다.

---

# Prometheus

- [프로메테우스란? - FINDA 기술블로그](https://medium.com/finda-tech/prometheus%EB%9E%80-cf52c9a8785f)
- [프로메테우스 - 조대협님 블로그](https://bcho.tistory.com/1372)

Prometheus와 Grafana에 대해서 공부할 수있는 시간을 가졌다.

프로메테우스는 대상 시스템으로 부터 메트릭이라하는 각종 모니터링 지표를 수집하여 저장하고 검색할 수 있는 시스템이다.

구조가 간단해서 운영이 쉽고, 강력한 쿼리 기능을 가지고 있으며, 그라파나(Grafana) 를 통한 시각화를 지원한다.

ELK스택의 키바나와 비교를 하자면 프로메테우스는 풀링을 통해 주기적으로 Exporter로부터 메트릭을 읽어오는 방식인 반면에 키바나는 푸쉬를 통해서 진행된다. 차이점은 푸쉬에 경우에는 서비스가 오토스케일링에 의해서 가변적일 때 유리하다. 풀링의 경우에는 가변적이라면 서비스의 주소를 받아오는 문제가 있다.

이러한 부분을 해결해주는 것이 서비스 디스커버리라고 한다. 쿠버네티스상에서는 인그레스를 등록하고 DNS를 등록하게 되면 DNS로 접근 후 인그레스에서 서비스에 IP들에 접근을 할 수 있게 하는 식으로 해결한다.

프로메테우스에는 두 가지 문제점이 있는데, 클러스터링 구조가 불가능해서 확장성과 가용성이 문제가 된다. 디스크를 키우는 하드웨어적인 부분으로 해결하려고하면 프로메테우스 인스턴스 하나 가지고는 여러 대상을 상대로 모니터링하기는 어렵다.

프로메테우스가 수집한 매트릭에 대하여 2시간 동안 메모리에 상주시켜놓은 뒤 지나면 하드디스크로 옮기게 되는데 이 하드디스크에 점점 쌓이게되면 예전 기록은 사라지게 된다. 이러한 문제점으로 인해 타노스를 이용한다.

타노스로 여러 프로메테우스 인스턴스들이 모으는 메트릭을 스케일이 가능한 스토리지에 저장해서 특정 인스턴스가 다운되어도 해당 메트릭을 볼 수 있게하거나 한 가지 타겟에 대하여 인스턴스를 갯수를 늘려서 HA 방식으로 관리할 수도 있다.

그라파나는 여러 대상에 대하여 시각화하는 도구이다. 그 중 프로메테우스를 자주 사용하며 연결하면 그래프가 아닌 커스텀해서 사용자가 원하는 모양으로 시각화할 수 있다.

그라파나의 경우에는 구조나 내용이 어렵지 않게 이해할 수 있다.

---

- 9 日

# PS

- Verifying an Alien Dictionary

```go
func isAlienSorted(words []string, order string) bool {
	if len(words) < 2 {
		return true
	}
	dict := createDict(order)
	prev := words[0]
	for _, w := range words {
		if compare(dict, prev, w) > 0 {
			return false
		}
		prev = w
	}
	return true
}
func createDict(s string) map[byte]int {
	res := make(map[byte]int)
	for i, c := range s {
		res[byte(c)] = i
	}
	return res
}
func compare(dict map[byte]int, a, b string) int {
	al, bl, com := len(a), len(b), 0
	for i := 0; i < al && i < bl && com == 0; i++ {
		com = dict[a[i]] - dict[b[i]]
	}
	if com == 0 {
		return al - bl
	}
	return com
}
```

외계인식 알파벳 순서를 주었을 때 해당 순서에 맞게 words 문자열이 정렬 되어있는지 확인하는 문제이다.

order에 맞게 map을 이용해서 순서를 적어논 다음 word 끼리 비교해서 같은 길이까지의 우선순위를 구한 뒤 잘못된 순서면 음수가 반환되도록 구현하였다.

---

# Thanos

- [타노스란 조대협님 블로그](https://bcho.tistory.com/1375)

Prometheus를 스케일링하기 위한 오픈소스로, Prometheus는 가용성과 확장성이 좋지 않아 Federation을 사용해서 matric을 다 받아주는 가장 상위의 Prometheus 인스턴스를 두거나 Thanos를 이용해서 Prometheus를 관리해줘야한다. 같은 타겟을 상대로 Prometheus 인스턴스가 2개 있을 때 Thanos가 위에 존재한다면 두 인스턴스가 풀링하는 matric 중 중복되는 것을 Thanos가 다 제거해주고 보여줄 수 있다.

이런 식으로 인스턴스의 스케일업과 스케일아웃을 조금 더 유틸리티있게 지원해주는 소프트웨어이다.

아키텍쳐를 둘러보고 공부를 진행한 뒤 Thanos에 Prometheus를 연결한 뒤 수집한 matric을 grafana로 시각화시키는 부분을 쿠버네티스 상에서 구현해야한다. 이 때 여러가지 helm 차트나 github의 소스들을 적용해봤다.

하지만 Prometheus와 grafana를 연결하였으나 Prometheus와 Thanos 연결하는 부분이 쉽지 않아서 난항을 겪고 있다. Object Storage도 AWS S3나 GCS를 이용해서 진행할 수 있어서 사람들이 구현해놓은 부분을 이용하려했으나 업데이트가 매우 빠르고 국내 자료가 많지 않아 많은 시간이 걸릴 것이라고 생각된다.

---

- 10 日

# PS

- Longest Increasing Path in a Matrix

```go
package Leetcode

var dir = [][]int{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
}

func longestIncreasingPath(matrix [][]int) int {
	cache, res := make([][]int, len(matrix)), 0
	for i := 0; i < len(cache); i++ {
		cache[i] = make([]int, len(matrix[0]))
	}
	for i, v := range matrix {
		for j := range v {
			searchPath(matrix, cache, 0, i, j)
			res = max(res, cache[i][j])
		}
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func isInIntBoard(board [][]int, x, y int) bool {
	return x >= 0 && x < len(board[0]) && y >= 0 && y < len(board)
}

func searchPath(board, cache [][]int, lastNum, y, x int) int {
	if board[y][x] <= lastNum {
		return 0
	}
	if cache[y][x] > 0 {
		return cache[y][x]
	}
	count := 1
	for i := 0; i < 4; i++ {
		nx := x + dir[i][0]
		ny := y + dir[i][1]
		if isInIntBoard(board, nx, ny) {
			count = max(count, searchPath(board, cache, board[y][x], ny, nx)+1)
		}
	}
	cache[y][x] = count
	return count
}
```

전형적인 BFS문제로 Golang을 이용해서 풀이를 해보았다.

좌표에서 이어지는 값이 오름차순으로 이어지는 값들의 길이를 구하는 문제이다.

---

- 11 日

# PS

- Deepest Leaves Sum

```go
package Leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deepestLeavesSum(root *TreeNode) int {
	maxLevel, sum := 0, 0
	dfsDeepestLeavesSum(root, 0, &maxLevel, &sum)
	return sum
}

func dfsDeepestLeavesSum(root *TreeNode, level int, maxLevel, sum *int) {
	if root == nil {
		return
	}
	if level > *maxLevel {
		*maxLevel, *sum = level, root.Val
	} else if level == *maxLevel {
		*sum += root.Val
	}
	dfsDeepestLeavesSum(root.Left, level+1, maxLevel, sum)
	dfsDeepestLeavesSum(root.Right, level+1, maxLevel, sum)
}
```

가장 레벨이 높은 노드들의 합을 더한 값을 반환하는 문제이다. C언어와 같이 주소를 넘겨 깊이를 판단하고 합계를 더하는 연산을 진행하였다.

---

- 12 日

# PS

- Beautiful Arrangement II

```go
func constructArray(n int, k int) []int {
    arr:= make([]int, 0, n)
    i, j := 1, n;
    for i <= j {
        if k % 2 == 0 {
            arr = append(arr, i)
            i++
        } else {
            arr = append(arr, j)
            j--;
        }

        if k > 1 {
            k--
        }
    }
    return arr
}
```

배열을 정렬하되 인접한 원소들의 차의 값이 k로 일정한 배열을 구해야한다. 따라서 k의 홀짝을 주기로 1~n 사이의 값을 출력해주는 방향으로 갔다.

투 포인터 느낌으로 돌아가면서 배열에 쌓아갔다.

---

# K8s Ingress

RabbitMQ나 Grafana와 같은 소프트웨어는 TCP 기반으로 통신하기 때문에 쿠버네티스 상에서 http(s)만 연결이 가능한 Ingress로는 연결할 수 없다.

대체적으로 load balancer를 이용해서 연결하지만 Ingress로 도메인 기반으로 연결하는 부분의 장점이 있다.

하지만 공식 문서에서는 tcp나 udp 기반은 연결을 지원하지 않는다고 하며 nginx를 이용한 ingress controller에서 지원해주는 부분을 찾아서 구현하여 보았다.

ingress nginx 공식 레퍼런스보다 [digitalocean](https://www.digitalocean.com/community/questions/how-to-expose-tcp-port-of-kubernetes-nginx-ingress-in-digitalocean-managed-kubernetes-2)에서 찾은 질문을 통해서 구현하였다.

공식 레퍼런스를 보고 진행했을 때 안되었던 이유도 알 수 있고 무엇이 누락되었는지 알려주는 답변이라 보고 구현할 수 있었다.

configmap을 이용하여 해당 tcp port를 http로 노출시키는 작업을 통해서 ingress로 tcp 연결을 할 수 있게 하였다. 이때 ingress ip에 port를 붙여서 접근하면 접속할 수 있었다.

현재는 Rabbitmq만 열어봤으며 다음에는 다른 tcp로 통신하는 소프트웨어에 port를 통한 통신을 해봐야겠다.

---

- 13 日

# PS

- Flatten Nested List Iterator

```go
type NestedIterator struct {
    stack *list.List
}

type listIndex struct {
    nestedList []*NestedInteger
    index int
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
    stack := list.New()
    stack.PushBack(&listIndex{nestedList, 0})
    return &NestedIterator{stack}
}

func (this *NestedIterator) Next() int {
    if !this.HasNext() {
        return -1
    }
    last := this.stack.Back().Value.(*listIndex)
    nestedList, i := last.nestedList, last.index
    val := nestedList[i].GetInteger()
    last.index++
    return val
}

func (this *NestedIterator) HasNext() bool {
    stack := this.stack
    for stack.Len() > 0 {
        last := stack.Back().Value.(*listIndex)
        nestedList, i := last.nestedList, last.index
        if i >= len(nestedList) {
            stack.Remove(stack.Back())
        } else {
            val := nestedList[i]
            if val.IsInteger() {
                return true
            }
            last.index++
            stack.PushBack(&listIndex{val.GetList(), 0})
        }
    }
    return false
}
```

배열로 감싸져있을 수도 있고 아닐 수도 있는 원소들이 주어졌을 때 순서를 제대로 구하는 문제이다.

C++로는 바로 어느 정도 틀이 생겼지만 golang으로는 상당히 시간이 오래걸렸다. 다른 사람들의 풀이를 참고해서 해결한 풀이로 주어진 클래스의 함수를 이용하지 않았던 것이 문제였다.

저런 부분을 볼 때는 문제를 다시 제대로 한번 읽고 풀어가야겠다.

---

# Thanos 아키텍쳐

- Metric sources

```
┌────────────┬─────────┐         ┌────────────┬─────────┐     ┌─────────┐
│ Prometheus │ Sidecar │   ...   │ Prometheus │ Sidecar │     │   Rule  │
└────────────┴────┬────┘         └────────────┴────┬────┘     └┬────────┘
                  │                                │           │
                Blocks                           Blocks      Blocks
                  │                                │           │
                  v                                v           v
              ┌──────────────────────────────────────────────────┐
              │                   Object Storage                 │
              └──────────────────────────────────────────────────┘
```

프로메테우스의 사이드카로 타노스와 통신하며 모은 메트릭을 블록형태로 스토리지에 전달한다.

- Stores & Data Sources - It's all the same

```
┌──────────────────────┐  ┌────────────┬─────────┐   ┌────────────┐
│ Google Cloud Storage │  │ Prometheus │ Sidecar │   │    Rule    │
└─────────────────┬────┘  └────────────┴────┬────┘   └─┬──────────┘
                  │                         │          │
         Block File Ranges                  │          │
                  │                     Store API      │
                  v                         │          │
                ┌──────────────┐            │          │
                │     Store    │            │      Store API
                └────────┬─────┘            │          │
                         │                  │          │
                     Store API              │          │
                         │                  │          │
                         v                  v          v
                       ┌──────────────────────────────────┐
                       │              Client              │
                       └──────────────────────────────────┘
```

Store API를 통해서 Store뿐 아니라 프로메테우스의 사이드카와 Rule에게로부터 데이터를 받게 된다.

- Query Layer

```
┌──────────────────┐  ┌────────────┬─────────┐   ┌────────────┐
│    Store Node    │  │ Prometheus │ Sidecar │   │    Rule    │
└─────────────┬────┘  └────────────┴────┬────┘   └─┬──────────┘
              │                         │          │
              │                         │          │
              │                         │          │
              v                         v          v
        ┌─────────────────────────────────────────────────────┐
        │                      Query layer                    │
        └─────────────────────────────────────────────────────┘
                ^                  ^                  ^
                │                  │                  │
       ┌────────┴────────┐  ┌──────┴─────┐       ┌────┴───┐
       │ Alert Component │  │ Dashboards │  ...  │ Web UI │
       └─────────────────┘  └────────────┘       └────────┘
```

Query Layer에 그라파나를 달아서 타노스 오브젝트들이 보내주는 데이터들을 대시보드형식으로 보여주게 되고 어떤 조건에 부합되게 하면 Alert을 통해서 알림을 주는 식으로 이루어져있다.

여러 yaml파일을 가지고 이용해도 좋지만 helm의 차트 중에 bitnami의 prometheus-operator와 thanos를 통해 연결할 수 있으며 grafana로 thanos의 query에 연결하여 직접 시각화하여 볼 수 있다.

- [thanos.io/design](https://github.com/thanos-io/thanos/blob/main/docs/design.md)
- [bitnami/thanos docs](https://docs.bitnami.com/kubernetes/infrastructure/thanos/administration/enable-metrics/)

---

- 14 日

# PS

- Partition List

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

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
```

기준이 된 정수보다 크거나 같은 숫자들은 작은 숫자보다 인덱스를 뒤로 물려야하는 문제이다.

따라서 뒤로 쭉 미뤄 둔채로 연결하는 식으로 진행했다.

---

# Thanos & Prometheus alertmanager

타노스와 alertmanager를 연결하고 slack으로 알림을 보내는 식을 구현하였다.

여기서 [google groups](https://groups.google.com/g/prometheus-users/c/vWJb3gx9CUQ?pli=1)를 통해 첫번째 사진의 아키텍처를 보고 감을 잡은 뒤 진행하였다.

타노스의 thanos-rules와 프로메테우스의 prometheus-alertmanager이 연결되어있으므로 thanos-rules에 직접 alert rule을 정의하고 alertmanager에서 slack으로 조건에 따라 매트릭이 충족하게 된다면 알림을 보내는 식으로 구현하였다.

이때는 [awesome-prometheus-alert](https://awesome-prometheus-alerts.grep.to/)를 통해서 직접 구현하는 것보다 promQL을 보고 인용하는 식으로 진행하였다. 잘 구현된 부분이 많아서 가져다 쓰면서 Thanos-rules에 맞게 변형시켜서 적용했다.

---

- 15 日

# PS

- Fibonacci Number

```go
func fib(n int) int {
    if n > 1 {
        return fib(n-2) + fib(n-1);
    } else if n == 1 {
        return 1;
    } else {
        return 0;
    }
}
```

단순한 피보나치 숫자를 구하는 문제이다.

---

# Grafana Loki

Grafana Labs에서 나온 Loki라는 오픈소스 소프트웨어에 대해서 설명해보려고 한다.

Loki는 Prometheus와 같은 방식으로 작동하며 다른 점은 Prometheu에서 Exporter로 수집하는 매트릭과는 달리 Loki는 Promtail에게서 로그를 받아온다.

로그를 받아와서 Grafana에서 Dashboard 형태로 보여주며 K8s에서 Loki-stack을 이용해 Deployment와 같은 오브젝트에 등록된 Label을 이용해서 로그를 받아올 수 있다.

Prometheus에 대한 개념을 확실히 한 뒤에 생각하면 역할이 확실히보여서 쉽게 이해할 수 있다. 또한 매트릭을 로그로 바꿔서 생각하면 Grafana를 통해서 쉽게 Dashboard로 표현할 수 있어서 괜찮은 소프트웨어라고 생각된다.

---

- 16 日

# PS

- Remove All Adjacent Duplicates in String II

```java
class Solution {
    public String removeDuplicates(String s, int k) {
        int cnt = 1;
        for(int i=0; i<s.length()-1; i++) {
            if(s.charAt(i) == s.charAt(i+1))
                cnt++;
            else
                cnt = 1;
            if(cnt == k)
                s = removeDuplicates(s.substring(0, i - k + 2) + s.substring(i + 2), k);
        }
        return s;
    }
}
```

문자열이 주어지고 인접한 글자들이 k개 만큼 있으면 1개 빼고 다 지우는 문제이다.

Golang으로 진행하는데 string과 byte를 아직 자유자재로 다루지 못해서 java를 이용해서 진행했다.

좋은 효율을 내기 위해서 부분문자열을 재귀하는 식으로 구현하였다.

---

# Grafana explore

Grafana에서 Loki를 이용해서 Dashboard를 구성할 필요가 있어서 사람들이 만든 Dashboard나 여러가지 찾아보았다.

하지만 K8s 상에서 Deployment 하나하나를 쳐다보면서 로그를 가져오는 Dashboard는 찾기 어려웠다. 그러한 부분을 해주는 것이 Explore에서 직접 label이 달린 pod에 대하여 로그를 가져오는 것이었다. 그래프도 한번에 알아보기 좋게 만들어주었고, Explore을 가지고 Dashboard를 각 deployment마다 만들어줄 것을 생각하였다.

생각과는 달리 Explore의 내용은 Dashboard로 이용할 수 없었다. 따라서 따로 Dashboard를 만드지는 못하고 해당 쿼리를 저장해서 그때 마다 찾아보도록 진행해야할 것 같다.

또한 프로메테우스에서 node나 kube-state에 대한 exporter가 아닌 redis-exporter를 사용하는 부분도 공부를 진행하려고 한다.

---

- 17 日

# PS

- Number of Submatrices That Sum to Target

```go
func numSubmatrixSumTarget(matrix [][]int, target int) int {
	m, n, res, sum := len(matrix), len(matrix[0]), 0, 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			counterMap := map[int]int{}
            counterMap[0] = 1
			sum = 0
			for row := 0; row < m; row++ {
				for k := i; k <= j; k++ {
					sum += matrix[row][k]
				}
				res += counterMap[sum-target]
				counterMap[sum]++
			}
		}
	}
	return res
}
```

테이블이 주어졌을 때 부분 배열의 합이 target과 같아지는 갯수를 구해주는 문제이다.

O(n^4)로 테이블의 범위를 잡고 그 범위에서 부분을 더했을 때 target이 나오는 경우를 찾아주고 있다.

---

- 18 日

# PS

- Remove Nth Node From End of List

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
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
		temp := head.Next
		head.Next = nil
		head = tmp
	} else {
		prev.Next = second.Next
		second.Next = nil
	}
	return head
}
```

주어진 연결리스트에서 뒤에서 n번째를 제거한 연결리스트를 반환하는 문제이다.

따라서 head의 주소를 가진 변수 두개를 가지고 순서를 찾은 뒤 해당 순서만 빼고 반환하는 방식으로 구현했다.

---

- 19 日

# PS

- Combination Sum IV

```go
func combinationSum4(nums []int, target int) int {
	dp := make([]int, target+1)
	dp[0] = 1
	for i := 1; i <= target; i++ {
		for _, v := range nums {
			if v <= i {
				dp[i] += dp[i-v]
			}
		}
	}
	return dp[target]
}
```

주어진 nums라는 배열의 원소를 가지고 몇개든지 더해서 target과 같은 숫자를 만드는 방법의 수를 구하는 문제이다.

따라서 조합을 통해서 갯수를 구하면 되는데 다이나믹 프로그래밍을 이용할 수 있다.

갯수에 상관없이 숫자를 사용하면 되므로 숫자의 종류를 가지고 이용하면 된다.

---

# Redis NPM

로컬 환경에 따른 설정과 배포 환경에 따른 설정을 나눠서 유지할 수 있다. 이 때 원격에 설정을 저장해놓고 가져다가 쓸 수 있다는 것을 생각해보자

MSA에서 어떠한 마이크로 서비스든지 모두 접근할 수 있으며 코드 레벨에서 가져다가 사용할 수 있는 환경 변수처럼 쓸 수 있는 원격 설정을 구현해보았다.

Redis에 Hash Table을 이용하며 이미 만들어진 node-redis를 사용하지만 다른 설정을 몰라도 조금 더 용이하게 사용할 수 있게 묶어보았다.

Redis를 여러 용도로 사용할 수 있지만 remote-config을 위한 모듈을 작성하고 배포해보았다.

- [npmjs](https://www.npmjs.com/package/dtx-remote-config)

---

# K8s Deployment

kubectl을 이용해서 deployment를 업데이트하거나 추가하는 내용을 공부해보았다.

- kubectl set env deployment name
- kubectl set image deployment name image
- kubectl rollout history/undo deployment name

deployment에 환경변수를 설정하는 명령어, 도커 이미지를 변경하는 명령어, 업데이트 내역을 보거나 롤백을 하는 명령어이다.

deployment는 롤링 업데이트를 지원하여 pod이 여러 개인 경우 이전 버전의 replica 갯수를 천천히 줄여가며 새로운 버전의 replica를 늘려가는 방식으로 업데이르를 진행한다.

쉽게 말해서 replica를 직접 이용하면 힘든 부분이 많아 이 부분을 자동화해서 추상화한 것이 바로 deployment라고 생각하면 된다.

따라서 스케일업과 업데이트 등 여러 변화가 있을 때 시스템을 무장애로 유지할 수 있는 장점을 가진 오브젝트이다.

---

- 20 日

# PS

- N-ary Tree Preorder Traversal

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

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
```

전위순회 방식으로 트리를 순회했을 때의 순서를 반환하는 문제이다.

전위 순회를 반복문을 통해서 구하는 방법이다.

---

- 21 日

# PS

- Triangle

```go
func minimumTotal(triangle [][]int) int {
    for i := 1; i < len(triangle); i++ {
        triangle[i][0] += triangle[i-1][0]
        triangle[i][len(triangle[i])-1] += triangle[i-1][len(triangle[i-1])-1]
    }
    for i := 2; i < len(triangle); i++ {
        for j := 1; j < len(triangle[i])-1; j++ {
            triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
        }
    }
    temp := triangle[len(triangle)-1][0]
    for _, v := range triangle[len(triangle)-1] {
        if v < temp {
            temp = v
        }
    }
    return temp
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

단순한 DP 문제로 행마다 값을 더했을 때 가장 적은 값을 구하기 위해서 DP로 선택지 중 작은 값을 선택했을 때로 제일 하단에 값을 구하고 그 중 가장 작은 값을 반환하면 되는 문제이다.

---

# OpenTracing

Jaeger에 대해 알아보다가 목적인 OpenTracing에 대해서 알아보았다.

MSA 형태의 서버가 늘어나면서 오류를 추적하는데에 있어서 어려움을 겪는다. 로그를 다 뒤져본다해도 어떤 부분에서 일어났는지 알기는 어려운 상황이 많으므로 그럴 때 설정되어 있다면 큰 도움을 주는 것이 OpenTracing이다

로그를 뒤져보는 것이 아닌 Tracing ID를 통해서 한번에 문제가 되는 곳을 찾아볼 수 있고 순서와 응답과 호출 시간도 알 수 있어서 명료한 부분이 많다.

하지만 설정하는 부분과 새로 알아야하는 부분이 많아서 그 부분이 tradeoff로 작용하는 것 같다.

로그를 보는 부분과 에러를 추적하는 부분은 엄연히 다르다고 생각되어 OpenTracing도 분명 도움이 되는 것이라고 생각이 된다.

- [OpenTracing? OpenTracing!](https://www.nurinamu.com/dev/2020/02/26/opentracing/)
- [LINE 광고 플랫폼의 MSA 환경에서 Zipkin을 활용해 로그 트레이싱하기](https://engineering.linecorp.com/ko/blog/line-ads-msa-opentracing-zipkin/)

---

- 22 日

# PS

- Brick Wall

```go
func leastBricks(wall [][]int) int {
	m := make(map[int]int)
	maxend := 0
	for i := 0; i < len(wall); i++ {
		sum := 0
		for j := 0; j+1 < len(wall[i]); j++ {
			sum += wall[i][j]
			if v, ok := m[sum]; ok {
				m[sum] = v + 1
			} else {
				m[sum] = 1
			}
			maxend = max(maxend, m[sum])
		}
	}
	return len(wall) - maxend
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
```

이어지는 벽돌이 있을 때 가장 작은 부분을 찾는 문제이다. 경계선인 끝부분을 찾아서 그 부분의 갯수를 더해서 최대 만큼 겹치는 부분을 찾은 뒤 전체에서 빼주게 되면 값을 구할 수 있다.

이러한 부분에서 map을 이용해서 직접 다 쌓은 뒤 가장 큰 값을 전체에서 제한 뒤 반환해주었다.

---

- 23 日

# PS

- Count Binary Substrings

```go
func countBinarySubstrings(s string) int {
	count, countZero, countOne := 0, 0, 0
	prev := rune(s[0])

	for _, r := range s {
		if prev == r {
			if r == '0' {
				countZero++
			} else {
				countOne++
			}
		} else {
			count += min(countZero, countOne)
			if r == '0' {
				countZero = 1
			} else {
				countOne = 1
			}
		}
		prev = r
	}

	return count + min(countZero, countOne)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```

부분문자열 중 0과 1의 갯수가 동일하게 있는 갯수를 세어주면 되는 문제이다.

---

- 24 日

# PS

- Critical Connections in a Network

```cpp
class Solution {
public:
    vector<vector<int>> edge;
    vector<int> num;
    vector<int> low;
    vector<vector<int>> ans;

    int t = 1;
    int tarjan(int now, int before) {
        int& ret = low[now];
        num[now] = t++;
        for (int i = 0; i<edge[now].size(); i++) {
            int next = edge[now][i];

            if (next == before) continue;
            if (num[next] == -1) { // not visit yet
                ret = min(ret, tarjan(next, now));

                if (low[next] > num[now]) {
                    ans.push_back({ now, next });
                }
            } else {
                ret = min(ret, num[next]);
            }
        }
        return ret;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        edge = vector<vector<int>>(n);
        num = vector<int>(n, -1);
        low = vector<int>(n, n);

		for (int i = 0; i<connections.size(); i++) {
          int a = connections[i][0];
          int b = connections[i][1];
          edge[a].push_back(b);
          edge[b].push_back(a);
        }

        tarjan(0, -1);

        return ans;
    }
};
```

강한 결합을 찾고 강한 결합이 아닌 부분을 찾아서 반환하는 문제이다. golang으로 하기에는 아직 익숙치 않아서 cpp로 진행하였다.

dfs는 시간초과로 타잔 알고리즘이라는 것을 이용했다.

- [타잔 알고리즘](https://taesung1993.tistory.com/53)

---

# 네이버 2021 공채 코딩테스트

프로그래머스에서 진행하는 2021 네이버 공채 코딩테스트에 참여하였다. 총 4문제로 2시간 동안 진행되었다.

현재 거주하는데서 진행하였는데 인터넷이 불안정하여 자꾸 꺼져서 아쉬웠다.

전체적으로 시간이 아쉬웠고 테스트케이스 한개와 효율성에서 부족했던 것 같아서 원하는 결과를 내지 못하였다.

3솔 이하로 나와서 아쉬움이 남았다.

---

# PS

- Rotate Image

```go
func rotate(m [][]int)  {
    N := len(m)
    for i := 0; i < (N) / 2; i ++ {
        for j := 0; j < (N+1)/2 ; j++{
             m[j][N-i-1], m[N-i-1][N-j-1], m[N-j-1][i], m[i][j] = m[i][j], m[j][N-i-1], m[N-i-1][N-j-1], m[N-j-1][i]
        }
    }
}
```

주어진 테이블을 시계방향으로 90도 돌리는 문제이다.

다른 언어와 다르게 golang에서는 한줄로 독립적으로 실행할 수 있다는 특징이 있다. 따라서 옮기는 작업을 한 줄에 나열하여 한번에 진행하게 되면 서로의 값을 이전 상태 기준으로 바꿀 수 있다.

만약에 쭉 밑으로 나열하게되면 이전 값을 찾지 못하고 바뀐 값이 들어가게 되어 섞이게 된다.

---

# 정보처리기사 실기

신청해놓고 잊고 있다가 공부를 짧게 하고 시험을 봐서 모르는게 매우 많았다. 카페에 올라온 정답과 비교를 해보는데 딱 턱걸이 점수거나 한 문제 모자라는 결과가 나올 것 같다.

요행을 바랬지만 결과는 딱 말해주는 것을 알게 되었다.

---

- 26 日

# PS

- Furthest Building You Can Reach

```go
type IntHeap []int
func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func furthestBuilding(heights []int, bricks int, ladders int) int {
    n := len(heights)

    h := &IntHeap{}
    heap.Init(h)

    for i:=1; i<n; i++ {
        if heights[i] - heights[i-1] > 0 {
            heap.Push(h,heights[i] - heights[i-1])
            if h.Len() > ladders {
                cost := heap.Pop(h).(int)
                if bricks < cost {
                    return i-1
                }
                bricks = bricks - cost
            }
        }
    }

    return n-1
}
```

min heap을 이용해서 해결하였다. 벽돌과 사다리가 주어진 부분만 조건으로 두고 나머지는 min heap을 이용하여서 진행하였다.

---

- 27 日

# PS

- Power of Three

```go
func isPowerOfThree(n int) bool {
    if n == 0 {
        return false
    }
    for true {
        if n % 3 == 0 {
            n = n / 3
        } else {
            if n == 1 {
                return true
            }
            break;
        }
    }
    return false
}
```

3의 제곱수 인지 아닌지 체크하는 문제로 무조건 반복하면서 3을 소인수로 가지고 있나 체크한 뒤 아닌 경우엔 false를 리턴하며 몫이 1이 되는 경우는 바로 3의 제곱수이므로 true를 리턴하였다.

---

# Istio

이스티오에 관련된 문헌과 포스팅들을 읽으면서 알아가고 있다.

현재는 이스티오를 설치해보고 관련 애드온들 (kiali, prometheus, grafana, jaeger) 등을 활용하는 방법을 찾아보고 있으며, 기존의 k8s에서 적용했던 ingress들을 istio ingress gateway를 통과하여 gateway, virtual service를 통해서 로드밸런싱과 라우팅까지 하는 방향으로 바꾸는 것을 생각하고 있다.

[Istio: Up and Running](http://www.kyobobook.co.kr/product/detailViewEng.laf?mallGb=ENG&ejkGb=ENG&barcode=9789352139125)이라는 책을 읽으면서 인터넷으로 여러 포스팅과 도큐멘트에서 놓친 것들을 다시 복기할 수 있도록 공부하고 있다.

나중에 조금 더 지식이 단단해지면 쿠버네티스와 함께 같이 글로 정리해볼 것이다.

---
