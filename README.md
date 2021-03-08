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

| [1월](./years/2021/1월.md) | [2월](./years/2021/2월.md) |
| -------------------------- | -------------------------- |

---

- 1 日

# PS

- Distribute Candies

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for(int i=0; i<candyType.size(); i++) {
            s.insert(candyType[i]);
        }
        return min(s.size(), candyType.size()/2);
    }
};
```

앨리스가 먹을 사탕 종류를 나누는 문제이다.

사탕 종류가 같은 것들이 들어있을 수도 있으므로 종류만 체크하기 위해서 set을 사용하였다.

set의 크기 즉, 사탕의 종류와 사탕의 갯수의 절반 중 작은 숫자를 반환해주면 되는 문제이다.

---

- 2 日

# 도커와 쿠버네티스

## 도커

도커는 컨테이너 기반의 오픈소스 가상화 플랫폼이라고 한다. 여기서 컨테이너에 대해 먼저 알아보자.

### 컨테이너

리눅스 커널 기술을 이용해서 프로세스가 사용하는 자원을 격리하는 것을 컨테이너라고 한다.

컨테이너를 기존의 가상화 기술과 차이를 비교해보면 더욱 더 이해하기 좋다.

![image](https://user-images.githubusercontent.com/59367782/109613214-32954c00-7b74-11eb-82f7-e0ce005e9940.png)

[출처](https://kubernetes.io/docs/concepts/overview/what-is-kubernetes/)

- 전통적인 배포 방식: 한 OS에 여러 어플리케이션을 올려서 가동한다.
- 가상화 배포 방식: 호스트 OS에 하이퍼바이저를 구동시켜 그 속 가상 머신에 게스트 OS를 각각 올리고 어플리케이션을 가동하는 방식이다.
- 컨테이너 배포 방식: 호스트 OS에 컨테이너 실행 환경을 구성하고 그 위에 컨테이너들을 두고 어플리케이션을 가동하는 방식이다.

장점

- 가벼움: 호스트 OS에서 돌아가기 때문에 게스트 OS를 추가할 필요가 없기 때문에 용량이 가볍다.
- 탄력성: 어느 환경에서나 구동할 수 있기 때문에 개발과 배포가 편리하다.
- 유지 관리 효율: 호스트 OS 커널 하나만 존재하기 때문에 업데이트나 패치 적용을 한번만 수행해도 모든 컨테이너에 적용이 된다.

### 흐름

도커파일 -> build -> 도커이미지 -> run -> 도커 컨테이너 생성

## 쿠버네티스

서비스를 컨테이너 실행 환경으로 구축한 뒤 운영하게 될 때, 만약 많은 양의 부하로 인해 오토 스케일링을 이용하여 스케일 아웃한다고 가정하면 확장된 서버에 컨테이너를 다른 서버와 마찬가지로 운영해야한다.

이러한 부분을 해결해주기 위해 오케스트레이션이라는 개념이 나오게 되었다.

- [레퍼런스](https://dailyheumsi.tistory.com/208)
- [레퍼런스](https://subicura.com/2019/05/19/kubernetes-basic-1.html)

### 오케스트레이션

- 정의

  - 복잡한 컨테이너 환경을 효과적으로 관리하기 위한 도구
  - 서버 관리자의 역할을 대신 할 프로그램을 만드는 도구

- 특징
  - 클러스터
  - 상태 관리
  - 배포 관리
  - 배포 버전관리
  - 서비스 등록 및 조회
  - 볼륨 스토리지

여러 오케스트레이션 도구들이 있지만 그 중 쿠버네티스가 `de facto standard`가 되었다.

### 구조와 오브젝트

- 클러스터 구조
  - 마스터 / 워커 노드
  - 하나의 마스터 노드와 여러개의 워커 노드로 구성
- 쿠버네티스 오브젝트
  - 오브젝트와 컨트롤러로 구성
    - 오브젝트: yaml이나 json으로 정의된 스펙에 따라 만들어지는 객체

`kubectl create -f pod.yaml`로 오브젝트 생성

### 기본 오브젝트 종류

- Pod
  - 가장 기본적인 배포 단위
  - 컨테이너들을 포함
  - yaml 포맷으로 정의
  - Pod 내 컨테이너들은 같은 IP 를 가지고, Port 를 공유한다.
  - Pod 내 컨테이너들끼리는 Volume 을 공유할 수 있다.

```yaml
# pod.yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx
spec:
  containers:
    - name: nginx
      image: nginx:1.7.9
      ports:
        - containerPort: 8090
```

- Volume
  - 컨테이너의 외부 디스크
  - 컨테이너가 재실행시 Volume 사용하면 파일 유지
  - Pod에 종속된 디스크로, Pod 내 여러 컨테이너들 공유 가능
  - 임시 디스크 (Pod 단위 공유)
    - emptyDir
      - Pod 이 생성되고 삭제될 때, 같이 생성되고 삭제되는 임시 디스크
      - 생성 당시에는 아무 것도 없는 빈 상태
      - 물리 디스크(노드), 메모리에 저장
  - 로컬 디스크 (노드 단위 공유)
    - hostPath
      - emptyDir 와 같은 컨셉이지만, 공유 범위가 노드라는 점만 다름
  - 네트워크 디스크
    - gitRepo (지금은 deprecated 라고 한다.)
      - 생성시에 지정된 git repo 를 clone 한 후, 디스크 생성
      - emptyDir -> git clone 이라보면 됨
    - 그 외 클라우드 서비스 별로 더 있음.

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: shared-volumes
spec:
  containers:
    - name: redis
      image: redis
      volumeMounts:
        - name: shared-storage
          mountPath: /data/shared
    - name: nginx
      image: nginx
      volumeMounts:
        - name: shared-storage
          mountPath: /data/shared
  volumes:
    - name: shared-storage
      emptyDir: {}
```

- Service

  - 여러 개의 Pod들을 서비스할 때, 현재 요청이 어느 Pod 으로 갈지 선택하는 오브젝트
  - 부하가 많을 때 이를 분산시키는 로드밸런서 역할
  - 동적으로 생성되는 Pod들의 동적 IP와 달리 Service는 지정된 IP 로 생성가능

  - 기능
    - 멀티 포트 지원
      - 예를 들어 80 -> 8080 으로, 443 -> 8082 로 가도록 한번에 설정할 수 있다.
    - 로드 밸런싱
      - 부하(트래픽)를 여러 Pod 으로 분산한다.
      - Pod 은 기본적으로 랜덤하게 선택된다.
    - IP 주소 할당 방식과 연동 서비스에 따른 Type
      - Cluster IP
        - 디폴트 값
        - 서비스에 클러스터 내부 IP 를 할당
        - 즉 클러스터 내부 접근 O, 외부 접근 X
      - Load Balancer
        - 외부 IP 를 가지고 있는 로드밸런서를 할당
        - 즉 외부 접근 O
      - NodePort
        - 클러스터 내 노드의 ip:port 로도 접근가능하게 함
        - ex. curl 10.146.0.10:30036
        - 10.146.0.10 는 노드의 ip 고, 30036 는 NodePort 로 설정한 포트임
      - ExternalName
        - 외부 서비스를 쿠네터네스 내부에서 호출하고자 할 때 사용
        - 모든 Pod 들은 Cluster IP 를 가지고 있기 때문에, 외부에서도 접근이 가능함.
        - 요청 -> (외부 서비스) -> 클러스터 내 쿠버네티스. 일종의 프록시 역할
    - headless 서비스
      - 서비스 디스커버리 솔루션을 제공하는 경우, 서비스의 IP 가 필요 없음
      - clusterIP: None 으로 주면 된다.
    - External IP
      - 서비스에 별도의 외부 IP 를 지정해줄 수 있음

- Controller
  - yaml 포맷으로 정의
  - 여러 개의 Pod 배포를 적절하게 관리하는 오브젝트
    - Pod들을 생성, 삭제함.
      - Replication Controller
        - 지정된 숫자로 Pod 을 기동 시키고 관리한다.
        - selector, replicas, template 을 기본적으로 정의해야 한다.
        - selector : label 기준으로 어떤 Pod 들을 관리할지 정의한다.
        - replicas : 선택된 Pod 들을 몇 개의 인스턴스로 띄울지 정의한다.
        - template : Pod 을 추가로 기동할 때, 어떤 Pod 을 만들지 정의한다.
      - Replication Set
        - ReplicationController 는 Equailty 기반 Selector를 사용
        - ReplicaSet 는 Set 기반 Selector 를 사용한다.
    - Deployment
      - ReplicationController 와 ReplicaSet 을 좀더 추상화한 개념
      - 실제 배포할 때는 이 컨트롤러를 주로 사용
    - DaemonSet
      - Pod 이 각각의 노드에서 하나씩만 돌게 한다. (균등하게 배포)
      - 보통 서버 모니터링이나 로그 수집 용도
      - 모든 노드가 아닌 특정 노드들만 선택할 수도 있다.
    - Job
      - 한번 실행되고 끝나는 Pod 을 관리한다.
      - Job 컨트롤러가 종료되면 Pod 도 같이 종료한다.
      - 컨테이너에서 Job 을 수행하기 위한 별도의 command 를 준다.
      - Job command 의 성공 여부를 받아 재실행 또는 종료여부를 결정한다.
    - CronJob
      - 주기적으로 돌아야하는(배치) Pod 을 관리한다.
      - 별도의 schedule 을 정의해아 한다.
    - Stateful
      - DB와 같이 상태를 가지는 Pod 을 관리한다.

```yaml
apiVersion: v1
kind: ReplicationController
metadata:
  name: nginx
spec:
  replicas: 3
  selector:
    app: nginx
  template:
    metadata:
      name: nginx
      labels:
        app: nginx
      spec:
        containers:
          - name: nginx
            image: nginx
            ports:
              - containerPort: 80
```

- Ingress

  - api 게이트 웨이. **url 기반 라우팅** 역할로 Service 앞에 붙음
  - Service 앞에 달 경우 Service는 `NodePort`타입으로 선언

- 네임 스페이스

  - 한 클러스터 내에 논리적인 분리 단위
  - 예를 들면 `namespace:billing` 과 `namespace:commerce` 는 같은 클러스터 내에 있지만 논리적으로 분리됨한 클러스터 자원을 가지고 개발 / 운영 / 테스트 식으로 나눌 수 있음.

- 라벨
  - 리소스를 선택하는데 사용됨
  - 예를 들면 Pod 안에 다음과 같이 라벨을 달 수 있음.

```yaml
kind: Pod
    ...
    metadata:
        labels:
            app: myapp
```

```yaml
kind: Service
    ...
    spec:
        selector:
            app: myapp
```

### 아키텍처

- 마스터

  - API 서버
    - 모든 명령과 통신을 REST API 로 제공
  - Etcd
    - 분산형 키-밸류 스토어로, 쿠버네티스 클러스터 상태나 설정 정보 저장
  - 스케쥴러
    - Pod, Service 등 각 리소스를 적절한 노드에 할당
  - 컨트롤러 매니저
    - 컨트롤러들을 생산, 배포 등 관리
  - DNS
    - 동적으로 생성되는 Pod, Service 등의 IP 를 담는 DNS

- 노드
  - Kubelet
    - 마스터 API 서버와 통신하는 노드 에이전트
  - Kube-proxy
    - 노드로 오는 네트워크 트래픽을 적절한 컨테이너로 라우팅
    - 네트워크 트래픽 프록시 등 노드-마스터간 네트워크 통신 관리
  - Container runtime
    - 컨테이너를 실행 (ex. dcoker)
  - cAdvisor
    - 각 노드 내 모니터링 에이전트
    - 노드 내 컨테이너들의 상태, 성능 수집하여 마스터 API서버에 전달

### 기능

- 서비스 디스커버리와 로드 밸런싱
- 스토리지 오케스트레이션
- 자동화된 롤아웃과 롤백
- 자동화된 빈 패킹
- 자동화된 복구
- 시크릿과 구성 관리

---

# PS

- Set Mismatch

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(2);
        int n = nums.size();
        long long int dif = accumulate(nums.begin(), nums.end(), 0);
        long long int sum = (n * (n+1)) / 2;
        set<int> s;
        for(int i=0; i<n; i++) {
            if(s.find(nums[i]) != s.end()) {
                v[0] = nums[i];
                break;
            }
            s.insert(nums[i]);
        }

        v[1] = v[0] - (dif - sum);
        return v;
    }
};
```

1부터 n까지의 숫자가 있을 때 오류가 나서 한 숫자가 두번 반복되고 한 숫자가 누락된 문제이다. 따라서 1~n까지의 합과 현재 주어진 배열의 합을 accumulate()를 이용해서 구한다.

set을 이용해서 중복된 값을 찾고 배열의 합과 1~n의 합을 이용해서 차이 값을 구해준다.

---

- 3 日

# PS

- Missing Number

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int diff = accumulate(nums.begin(), nums.end(), 0);
        long long int sum = (nums.size() * (nums.size()+1)) / 2;
        return sum - diff;
    }
};
```

벡터 중 빠진 숫자를 찾는 문제이다. 0 ~ n-1까지의 숫자가 주어지고 빠진 숫자를 찾으면 된다.

따라서 벡터의 크기만큼의 합을 구하고 주어진 벡터들의 합을 구해서 그 차이를 반환하면 된다.

---

- 4 日

- Intersection of Two Linked Lists

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        if(!ptr1 || !ptr2)
            return nullptr;
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr1 == ptr2)
                return ptr1;
            if (ptr1 == NULL)
                ptr1 = headB;
            if (ptr2 == NULL)
                ptr2 = headA;
        }
        return ptr1;
    }
};
```

연결리스트 두 개가 있을 때 두 리스트가 겹쳐질 때를 찾는 문제이다. 따라서 리스트들을 끝까지 보낸 다음 마지막에 null이라면 다른 리스트의 헤드를 붙여서 두 리스트가 같도록 한 뒤, 끝까지 간 경우에는 두 리스트의 크기가 같아지므로 마지막에는 null이 나오게 된다. 이 때 같이 null이라면 해당 null을 리턴하면 된다. 이외에는 이미 겹쳐졌으므로 현재 구조체를 바로 리턴해주면 된다.

---

- 5 日

# PS

- Average of Levels in Binary Tree

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<pair<long,long>> v;
public:
    void level(TreeNode* node, int cnt) {
        if(node == NULL)
            return;
        if(v.size() <= cnt) {
            v.push_back({node->val, 1});
        } else {
            v[cnt].first += node->val;
            v[cnt].second++;
        }
        level(node->left, cnt+1);
        level(node->right, cnt+1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        level(root, 0);
        vector<double> ans;
        for(int i=0; i<v.size(); i++) {
            ans.push_back(double(v[i].first) / v[i].second);
        }
        return ans;
    }
};
```

이진 트리가 주어졌을 때 트리의 레벨에 값들의 평균을 구하는 문제이다. 따라서 재귀 함수를 이용하여 자식 노드들을 찾아갔으며, 벡터에 레벨에 맞춰서 해당 값을 다 더해준 뒤 평균을 구하도록 하였다.

ICT 인턴십을 시작하여 거의 PS 위주로만 진행이 될 것 같다.

---

- 6 日

# Short Encoding of Words

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        for (string word : words)
            if (s.find(word) != s.end())
                for (int i = 1; i < word.length(); i++) {
                    s.erase(word.substr(i));
                }
        int ans = s.size();
        for (string word : s)
            ans += word.size();
        return ans;
    }
};
```

주어진 단어들 마다 뒤에 `#`을 붙여서 문자열을 만들었을 때의 길이를 구하는 문제이다.

단어 중 겹치는 단어가 있다면 그 중 큰 단어를 기준으로 하나만 체크하면 된다.

따라서 set에 단어들을 넣은 뒤 단어를 인덱스 1부터 끝까지의 부분 문자열을 구해서 set에 있는지 확인한다.

만약, 있다면 해당 단어를 set에서 지워준다. 그렇게하면 set의 크기는 `#`의 갯수이며, set의 남아있는 문자들은 문자열에 포함되는 문자들이다. 따라서 해당 문자 길이들을 잇는다면 답이 된다.

---

- 7 日

# PS

- Design HashMap

```cpp
class MyHashMap {
public:
    vector<pair<int, int>> v;

    MyHashMap() {
        v;
    }

    void put(int key, int value) {
        bool isExist = false;
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                isExist = true;
                v[i].second = value;
                break;
            }
        }
        if(!isExist) {
            v.push_back({key, value});
        }
    }

    int get(int key) {
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                return v[i].second;
            }
        }
        return -1;
    }

    void remove(int key) {
        for(int i=0; i<v.size(); i++) {
            if(v[i].first == key) {
                v.erase(v.begin() + i);
                break;
            }
        }
    }
};
```

hashMap을 구현하는 문제로, 문제에서 원하는 부분을 직관적으로 구현하였다.

---

# 정보처리기사 필기

이번에 2021 정기 기사 1회 정보처리기사 필기에 응시하였다.

전체적인 난이도는 낮았으며, 1-2 과목에 경우에는 과년도 문제와 매우 유사했다. 3-4 과목에 경우에는 대학에서 진행한 강의를 들었다면 매우 쉽게 풀 수 있었다. 그에 반해 5 과목은 들어본 내용도 있지만 헷갈리거나 처음 보는 내용이 꽤나 많았다.

기출문제만 여러번 풀어보고 시험을 응시했던 거에 비해 높은 점수를 받을 수 있었다. 5 과목도 크게 틀린 부분은 없었지만 기억하면 나쁠 건 없어보였다.

---

- 8 日

# PS

- Remove Palindromic Subsequences

```cpp
class Solution {
public:
    int removePalindromeSub(string s) {
         return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
    }
};
```

팰린드롬이라면 1을 빼고 문자열이 비어있으면 1을 또 빼주는 식으로 구현하였다.

---

# 쿠버네티스

- [레퍼런스](https://bcho.tistory.com/1255?category=731548)

조대협님 블로그를 기준으로 쿠버네티스 공부를 하고 있다. 정리가 매우 잘 되어 있어서 크게 도움이 된다.

Google Cloud Platform에서 쿠버네티스 사용하는 것과 bitbucket의 파이프라인을 이용한 CI/CD를 진행해보았다. CI/CD의 경우에는 다른 툴과 같이 yaml을 이용해서 정의한 뒤 사용하면 된다.

쿠버네티스는 kubectl을 이용한 여러 명령어를 사용해보았다. 쿠버네티스와 연결하는 부분, 내용을 고치고 쿠버네티스에 파일을 올리는 부분을 해보았다.

- `kubectl apply -f 경로`를 이용하면 파일을 직접 바로 올릴 수 있다.

당연한 이야기지만 어떤 명령어든 연결이 되어야 가능하다. 이 부분에선 GCP를 사용해서 연결했으므로, SDK 설치하고 쿠버네티스와 연동이 필요하였다.

- `kubectl proxy`를 이용하면 쿠버네티스 대시보드로 확인할 수 있다.

---
