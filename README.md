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
