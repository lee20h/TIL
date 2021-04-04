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
