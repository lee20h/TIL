# 10월

| 날짜 | 공부 내용 |
|------|----------|
| 1일 | PS |
| 2일 | PS |
| 3일 | Git 초급 |
| 4일 | PS |
| 5일 | 유닉스 Utilities, Git 중급 |
| 6일 | AWS Computing Services, Load test for Web services |
| 7일 | TypeScript 설정 |
| 8일 | React JSX 문법 |
| 9일 | PS |
| 10일 | ACM ICPC, MongoDB |
| 11일 | MongoDB, node.js bcrypt, JWT |
| 12일 | React Router Dom, 소프트웨어공학 분석의 문제점, 기능 모델링 |
| 13일 | C Programming on Linux, AWS Storage Services 1: EBS, EFS |
| 14일 | CleanCode |
| 15일 | 2020 공개SW 온라인 체험캠프 |
| 16일 | 2020 공개SW 온라인 체험캠프 |
| 17일 | node Concurrently, Redux, React Hooks | 
| 18일 | react & node cookie 저장 |
| 19일 | AWS Storage Services 2 : S3, Linux System Call, File: Low-level I/O |
| 20일 | fetch와 axios의 차이 |
| 21일 | 컴퓨터네트워크 중간고사 준비, SQL 복습 |
| 22일 | PS |
| 23일 | 컴퓨터네트워크 중간고사 |
| 24일 | PS |
| 25일 | PS |
| 26일 | PS |
| 27일 | PS |
| 28일 | 컴퓨터네트워크 : Congestion Control and Quality of Service |
| 29일 | 소프트웨어공학 동적 모델링 |
| 30일 | 소프트웨어공학 정보 모델링 |
| 31일 | 소프트웨어공학 객체지향 분석기법 |

---

- 1日  

기능개발
```cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; 
    queue <int> q;
    
    int bound, rest, day, i, cnt = 0;
    
    for (i = 0; i < progresses.size(); i++) {
        rest = 100 - progresses[i];
        if (rest % speeds[i] == 0) day = rest/speeds[i];
        else day = rest/speeds[i] + 1;
        q.push(day);
    }
    
    bound = q.front();
    
    while(!q.empty()) {
        if (q.front() <= bound) {
            cnt++;
            q.pop();
        }
        else {
            bound = q.front();
            answer.push_back(cnt);
            cnt = 0;
        }
    }
    answer.push_back(cnt);
    return answer;
}
```
여러가지 풀이 방법 중 가장 직관적이고 좋은 방법을 찾아서 적어본다. 배포가 하루에 한번만 가능하고 앞에 있는 기능이 되야 뒤에 기능이 배포된다. 따라서 그 부분을 큐로 구현하면 큐의 front가 bound로 정하고 bound 초과하지 않으면 큐에서 기다리는 든 기능을 배포하면 된다. 그 과정을 반복하면 된다.  

---

- 2日  

다리를 지나는 트럭
```cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q, bridge;
    int total_weight = 0;
    while(1) {
        int size = bridge.size();
        for (int i=0; i<size; i++) {
            int len = bridge.front();
            bridge.pop();
            len--;
            if(len == 0) {
                total_weight -= q.front();
                q.pop();
                continue;
            }
            bridge.push(len);
        }
        
        if(truck_weights.size() && total_weight + truck_weights[0] <= weight) {
            total_weight += truck_weights[0];
            bridge.push(bridge_length);
            q.push(truck_weights[0]);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if(!truck_weights.size() && !q.size())
            break;
    }
    return answer;
}
```

3986. 좋은 단어
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		stack<char> st;
		string s;
		cin >> s;
		for (int j=0; j<s.length(); j++) {
			if(!st.empty() && st.top() == s[j]) {
				st.pop();
			}
			else st.push(s[j]);
		}
		if(st.empty())
			ans++;
	}
	cout << ans;
} 
```

프로그래머스에서 다리를 지나는 트럭 문제로, 전형적인 큐 문제이다. 큐를 하나만 사용하는게 아니라 다리 무게 큐, 시간 큐를 통해 시간 초를 세주었다. 백준 온라인 저지에서 좋은 단어라는 문제로, 이 문제 또한 전형적인 스택 문제이다. 괄호 검사와 같이 스택에 넣고 스택의 탑과 비교하여 해당 문자가 같으면 팝해주는 식으로 진행한다. 다 끝난 뒤 스택이 비어있는 문장을 세어주면 된다.  

요즘에 긴 연휴와 해커톤으로 인해 감이 많이 죽은 듯하다. 이젠 문제 풀이를 많이 해볼 생각이다. 코드포스와 프로그래머스 풀이를 많이 하고, 코드챌린지와 icpc 지역 예선을 하며 공부의 필요를 많이 느낀다.

---

- 3日

# Git 초급

[참고](https://backlog.com/git-tutorial/kr/)  

Git은 버전 관리 시스템의 일종이다.  

## 버전 관리 시스템 (Version Control System)

동일한 정보에 대한 여러 버전을 관리하는 것으로 파일의 변화를 시간에 따라 기록하여 과거 특정 시점의 버전을 다시 불러올 수 있는 시스템이다.  

백업과 버전관리를 위한 시스템으로, 프로젝트 진행 중 과거의 시점으로 돌아가거나, 변경 사항 추적, 특정 부분에 대하여 의미 추적을 위해서 사용한다.  

### 사용하는 이유

협업 도구로, 여러 사람이 같은 프로젝트에 참여할 경우 각자가 수정한 부분을 팀원 전체가 동기화하는 과정을 자동화를 하기 위한 이유가 크다. 그 외에는 소스 코드에서 수정자를 추적하기 위함이나, 대규모 수정 작업을 더욱 안전하게 진행하기 위해서이다.  

두번째 이유는 개발 편의성으로, Branch로 프로젝트에 영향을 최소화하면서 새로운 부분을 개발하기 위함과 Merge로 검증이 끝난 후 새로이 개발된 부분을 trunk에 합치기 위해서이다.  

이러한 이유와 많은 오픈 소스 프로젝트에서 어떠한 형태로든 버전 관리를 사용하고 있기 때문에 Git에 대해 공부할 필요가 있다.  

## 로컬 vs 중앙집중형  

- 로컬 : 1인 개발 시 사용, 팀 단위 사용 시 부적합

- 중앙 집중형 : 간단한 구조, Single Point of Failure (SPOF). 여러 로컬에서 한 중앙 서버로 연결하여 사용  

- 유사 시스템
    - 소스 코드 관리 (Source Code Management, SCM)
    - SW 버전 관리 (Software Version Management)
    - SW 형상 관리 (Software Configuration Management)
    - 리비전 관리 시스템 (Revision Control System)

- 널리 쓰이는 SW
    - SVN
    - Mercurial
    - Git

## Git: the stupid content tracker

- 분산 버전 관리 시스템, DVCS : 여러 사람이 협업하는 문서변경사항을 관리하는 시스템
    - 중앙 서버에 있는 코드를 각자의 local 컴퓨터에 복사한 후, 복사된 프로젝트를 가지고 서버에 업로드를 할 수 있다.

특징

- Free and Open soruce
- Easy to learn
- Tiny footprint (less memory, storage)
- Lighting fast performance

### brief history

2005년 리눅스 개발 커뮤니티에 의해 개발되었다. 기존 방식은 단순 압축(스냅샷)과 패치를 통해 버전 관리하였지만 이후에 Bitkeeper를 사용하다가 유료 전환되며 Git을 개발하였다.  

설계 목표 (vs Bitkeeper)

- 빠른 속도
- 단순한 구조
- 비선형적인 개발(수천 개의 동시 다발적인 브랜치)
- 완벽한 분산
- 리눅스 커널 같은 대형 프로젝트에도 유용할 것 (속도나 데이터 크기 면)

### 특징

- 단순성 : 변화된 부분만을 기록하는 것이 아니라, 전체를 버전 별로 보존.  
    - 델타 방식 vs 스냅샷 방식
    - git은 스냅샷 방식으로 언제나 데이터를 추가해나가는 방식

- 빠른 속도 : 로컬에서 명령 실행  
    - 분산된 형태로 관리되기 때문

- 무결성 : 변화된 파일에 대한 체크섬 관리
    - 파일, 디렉토리에 대한 SHA-1 Checksum을 이용해 분산 구조에서 무결성을 보장
    - Git은 모든 데이터를 checksum hash 형태로 관리

## Git의 3가지 영역

- 작업 폴더 (Working Directory)
    - 사용자가 변경하는 실제 파일이 들어가는 폴더

- 스테이지 (Stage, Index)
    - 변경사항을 관리할 파일들의 리스트
    - 작업 폴더 중에서 커밋할 파일만을 모아둘 수 있음

- 변경이력 (History, Git directory, repository)
    - 커밋이라 불리는 변경사항 묶음과 커밋들의 연결관계

## 로컬저장소와 원격저장소

저장소 (repository) : History를 저장하는 공간  

협업을 위해서는 원격저장소가 필수적이며, 로컬저장소와 원격저장소 간에 이력을 주고 받을 수 있다. 따라서 동기화 문제가 존재한다. 원격저장소가 여러 개를 둘 수도 있다.  

로컬저장소와 원격저장소는 인터넷을 통해서 연결하게 되는데 로컬저장소와 원격저장소의 내용이 다르면 동기화문제가 생길 수 있으므로, 최신화를 항상 체크해야한다.  

## 로컬 - 원격 저장소 간의 이동

로컬 - 원격 저장소  
Working Directory -> (git add) Staging Area -> (git commit) Local Repository -> (git push) Remote Repository  

원격 - 로컬 저장소  
Remote Repository -> (git fetch) Local Repository -> (git checkout or git merge) Working Directory

---

- 4日

프로그래머스 멀쩡한 사각형
```cpp
#include <cmath>

long long solution(int w, int h) {
    long long answer = 0;
    for(int i = 1; i <= w; i++){
        double pos = ceil((long long)h / (double)w * i);
        int block = h - pos;
        answer += block;
    }
    
    answer = answer * 2;
    return answer;
}
```

해당 문제는 상당히 골치아팠다. 대칭을 생각해서 한쪽만 구한 뒤 2배를 한다는 생각으로 진행하였다. 그 중 y = (h/w)x 함수로 생각해보았다. 따라서 높이에서 그래프가 속한 정사각형의 제일 높은 위치를 빼주었다. 거기서 필요한 부분은 방정식의 x값이 늘어나면서 바뀌는 y의 값을 천장함수로 지정하여 정사각형의 높은 위치를 얻어야한다. 그래프로 생각하면 빨리 풀 수 있었던 문제로 보인다.  

---

- 5日  

# 유닉스 Utilities

## find & grep

### find

`find 디렉토리 [-옵션]` : 옵션의 검색 조건에 따라 지정된 디렉터리 아래에서 해당되는 파일들을 모두 찾아 출력한다.  

ex) `$ find ~ -name *.c -print`, `$ find /usr -name "*.c" -print` print는 기본옵션으로 생략 가능하다.  

여러 검색 옵션이 있는데 그 중 파일의 접근권한 검색 (-perm), 파일의 접근 시간(-atime), 수정 시간(-mtime)으로 검색이 가능하다. 이때 atime과 mtime에 n을 적어 +|-로 기준 시간 이전, 이내로 검색이 가능하다.

또한, 파일의 소유자, 소유그룹, 크기, 종류로도 검색이 가능하며, 이러한 조건들을 조합하여 사용도 가능하다.  

마지막으로 검색된 파일을 처리할 수 있다. -exec 옵션으로 통해서 검색한 모든 파일을 대상으로 동일한 작업(명령어)을 수행한다.  

### grep

`grep 패턴 파일*` : 파링들을 대사응로 지정된 패턴의 문자열을 검색하고, 해당 문자열을 포함하는 줄들을 출력한다.  

옵션은 다음과 같다.  

**-i** 대소문자를 무시하고 검색한다.
**-n** 각 줄의 줄번호도 함께 출력한다.
**-l** 해당 패턴이 들어있는 파일 이름을 출력한다.
-v 명시된 패턴을 포함하지 않는 줄을 출력한다.
-c 패턴과 일치하는 줄 수를 출력한다.
-w 패턴이 하나의 단어로 된 것만 검색한다.
**-R** 하위 디렉토리의 파일들을 recursive 하게 검색한다.  

grep도 옵션들을 조합하여 여러가지 옵션을 중복해서 사용할 수 있다.  

### 정규식 (regular expression)

- `?` : 한 글자 혹은 없음을 의미한다. ex) ‘ab?’는 ab 혹은 ab 다음에 한 글자가 오는 문자열
- `.` : 임의의 한 문자를 의미한다. ex) ‘a...b’는 a로 시작해서 b로 끝나는 5글자 문자열
- `*` : 바로 앞의 것을 0번 이상의 반복 ex) ‘a*b’는 b, ab, aab, aaab, ... 등의 문자열
- `[ ]` : [과 ] 사이의 문자 중 하나를 의미. –기호: 문자의 범위를 지정. ex) ‘[abc]d’는 ad, bd, cd를 뜻한다. [a-z]는 a부터 z까지 중 하나
- `[^...]` : [^ 과 ] 사이의 문자를 제외한 나머지 문자 중 하나를 의미한다. ex) ‘[^abc]d’는 ad, bd, cd는 포함하지 않고 ed, fd 등은 포함. [^a-z]는 소문자가 아닌 모든 문자
- `^, $` :  각각 줄의 시작과 끝을 의미한다. ex) ‘^문자열’은 문자열로 시작하는 줄을 나타낸다. ‘문자열$’은 문자열로 끝나는 줄을 나타낸다.  

## 압축 : tar and compressions

### Tar Archive

- Archive
    - 백업 또는 다른 장소로의 이동을 위해 여러 파일들을 하나로 묶어놓은 묶음
    - 아카이브를 만들거나 푸는데 tar(tape archive) 사용
    - Tar: 이름에서 알 수 있듯, 전통적으로 Archive를 만드는데 사용.
        - Tar 로 생성된 archive 는 .tar 확장자를 가지며, tar file 혹은 tarball 이라고 표현하기도 함
- tar의 동작
    - 단순히 여러 파일의 데이터를 하나의 파일로 묶고,
    - 다시 여러 파일로 복원할 수 있도록 함
    - 파일의 용량은 원본보다 더 큼 (복원을 위해 기존 파일들의 이름, 크기, 권한 등 필요한 정보를 포함하기 때문)
    - 기본적으로 압축 (Compression)을 수행하지 않음. Archive 와 compression 은 별개

- 명령어
    - 옵션: c(create), v(verbose), x(extract), t(table of contents), f(file)
    - `$ tar -cvf 타르파일 파일+` : 여러 파일들을 하나의 타르파일로 묶는다. 확장자 .tar 사용
    - `$ tar -xvf 타르파일` : 하나의 타르파일을 풀어서 원래 파일들을 복원한다.
    - `$ tar -tvf 타르파일` : 타르파일의 내용을 확인한다.

### gzip

- 리눅스 환경에서 많이 사용하는 압축 프로그램
- 속도가 빠르고 적당한 수준의 압축률을 제공함
- 명령어 : `gzip [옵션] 파일*` : 파일들을 압축하여 .gz 파일로 만든다.

옵션
-d : 압축을 해제한다. (decompress)
-l : 압축파일 안에 있는 파일 정보(압축된 크기, 압축률) 출력한다.
-r : 하위 디렉터리까지 모두 압축한다.
-v : 압축하거나 풀 때 압축률, 파일명을 출력한다.

외에 bzip2, xz도 유사하게 사용하면 된다. bzip2와 xz가 압축률이 높으나, 그만큼 속도가 느리다.  

### Tar file 생성시 gzip 사용

- Tar의 Compression options
    - Tar 파일을 생성하거나 해제할 시, 동시에 압축 또는 복원을 수행함
    - -z : gzip 이용
    - -j : bzip2 이용 (소문자 j)
    - -J : xz 이용 (대문자 J)
- ex) 압축
    - $ tar -czvf textfiles.tar.gz *.txt
    - $ tar -cJf textfiles.tar.xz *.txt
- ex) 복원
    - $ tar -xzvf textfiles.tar.gz
    - $ tar -xJf textfiles.tar.xz

## 기타

### 파일 비교

- cmp 명령어 : 
    - `$ cmp 파일1 파일2` : 파일1과 파일2가 같은지 비교한다. 
    - 두 파일이 같으면 아무 것도 출력하지 않음.
    - 두 파일이 서로 다르면 서로 달라지는 위치 출력

- diff 명령어 :
    - `$ diff [-i] 파일1 파일2` : 파일1과 파일2를 줄 단위로 비교하여 그 차이점을 출력한다. -i 옵션은 대소문자 무시
    - 첫 번째 파일을 두 번째 파일 내용과 같도록 바꿀 수 있는 편집 명령어 형태
    - 추가(a) : 첫 번째 파일의 줄 n1 이후에 두 번째 파일의 n3부터 n4까지의 줄들을 추가하면 두 파일은 서로 같다. 
    - 삭제(d) : 첫 번째 파일의 n1부터 n2까지의 줄들을 삭제하면 두 번째 파일의 줄 n3 이후와 서로 같다
    - 변경(c) : 첫 번째 파일의 n1 부터 n2까지의 줄들을 두 번째 파일의 n3 부터 n4까지의 줄들로 대치하면 두 파일은 서로 같다.  
        - n1, n2 c n3, n4
        ```
        < 첫 번째 파일의 대치될 줄들
            --
        > 두 번째 파일의 대치할 줄들
        ```
    
### 패키지 설치

리눅스에서 추가 프로그램을 설치하는 세 가지 방법  

- 소스 코드를 다운로드 받아 직접 컴파일하고 설치함
    - 장점: 필요한 경우, 직접 수정하여 사용 가능
    - 단점: 빌드 환경을 구성해야 하는 등, 과정이 복잡함
- 패키지를 다운로드 받아 설치함
    - 장점: 컴파일 완료된 패키지 파일을 다운받아 설치함
    - 단점: 다른 패키지와의 의존성 문제를 직접 해결해야 함 (ex A 설치를 위해, B가 필요한데, B는 설치되어 있지 않음)
- **패키지 관리 프로그램 사용**
    - 패키지 명을 지정하면, 자동으로 패키지를 검색해 다운받고, 설치함
    - 장점: 패키지 다운로드도 의존성 문제 등을 자동으로 해결해줌
    - 단점: Customizing , 버전 관리 등이 다소 불편함

    - 여러 배포본에 따라 서로 다른 패키지 관리 프로그램을 제공
        - Debian 계열 (Ubuntu, Debian, : apt (or apt-get)
            - 패키지 형태: dpkg
        - Redhat 계열 (CentOS, Fedora,RHEL): yum
            - 패키지 형태: rpm
    - apt
        - 기존 apt-get 보다 사용자 편의적인 high-level package management system
        - 사용법: # apt [command] [package name]
        - Commands
            - install: 패키지 설치
            - autoremove: 패키지 자동 제거
            - update: 패키지 정보를 최신으로 업데이트함.
            - upgrade: 최신 버전으로 업데이트 가능한 모든 패키지를 설치함
            - search: 패키지 정보 검색
            - list: 사용 가능한 패키지 리스트 출력. 이미 설치된 경우, [installed] 로 표시됨.

### 디스크 사용

- df 명령어 : 파일 시스템에 대한 정보를 출력한다.
    - `$ df 파일시스템*` : 파일 시스템의 사용중이거나 사용 가능한 디스크 공간에 대한 정보를 보여준다.  

- du 명령어 : 
    - `$ du [-s] 파일*` : 파일이나 디렉토리가 사용하는 디스크 사용량(블록 수)을 알려준다.
    - 파일을 명시하지 않으면 현재 디렉터리의 사용 공간을 보여준다.
    - 기본으로 `-ahd 1` 모든 파일, 단위 포함, 한 레벨 아래 하위 디렉토리 

### IP주소

- `$ ip addr` : 사용중인 시스템의 IP 주소를 출력한다.
- `$ ifconfig` : Network Interface 에 대한 configuration 을 수행함
    - 단순히 ip addr 과 같이 네트워크 정보를 확인하기 위해서도 많이 사용함

### 별명

- alias 명령어 :
    - `$ alias 이름=문자열` : 문자열이 나타내는 기존 명령에 대해 새로운 이름을 별명으로 정의

### 히스토리

- history : 
    - `$ history [-rh] [번호]` : 입력된 명령들을 기억하는 기능
    - `$ HISTSIZE=100` : 기억할 히스토리 사이즈
    - `$ HISTFIESIZE=100` : 로그아웃 후에도 히스토리가 저장되도록 설정

### 재실행

- `!!` : 바로 전 명령 재실행
- `!n` : 이벤트 번호가 n인 명령 재실행
- `!` : 시작스트링 시작스트링으로 시작하는 최후 명령 재실행
- `!?` : 서브스트링 서브스트링을 포함하는 최후 명령 재실행

---

# Git 중급

## Branch

- VCS의 한계
    - 충돌이 나는 파일은 수동으로 해결할 수 밖에 없음
    - 따라서 최대한 분리하여 작업하도록 구성
        - 단위: 함수, 클래스, 파일, 폴더, 기능 등
    - 그러나 협업 구조에서 동시 작업의 필요성은 여전히 존재
        - 기능 추가 팀, 버그 수정 팀이 동시에 작업
- Branch
    - 같은 코드를 공유하되, 작업을 독립적으로 분리해서 수행할 수 있음
        - 독립적인 개발 및 테스팅, 커밋 이력 관리, 저장소 관리
        - Git은 가볍고 빠른 브랜치 동작 제공
    - 분리는 쉽다, 나중에 다시 합칠 때는?
        - Merge 담당 전문가, 테스트 과정 필요

### Branch 생성 및 Head 이동

- `$ git branch testing`
    - 새로운 브랜치 생성
    - HEAD의 위치는 변경되지 않음
- `$ git checkout testing`
    - HEAD의 위치를 변경
    - 작업 브랜치가 변경됨. 이후 커밋은 해당 브랜치에 추가됨

### Branch: Merge

- Fast-forward merge
    - 충돌없어서 충돌 관리 X
    - 따라서 해당 브랜치 내용이 main과 같다.
    - non fast-forward 병합 옵션으로 브랜치 내용을 따로 유지하면서 병합이 가능하다.

- Three-way merge
    - 3개 commit(브랜치와 또다른 브랜치, HEAD)에 대해 서로 다른 부분을 검사해야함

### Branch: Rebase

Rebase: 여러 commit 을 하나로 merge  

- merge
    - 변경 내용의 이력이 모두 그대로 남아 있기 때문에 이력이 복잡해짐.
- rebase
    - 이력은 단순해지지만, 원래의 커밋 이력이 변경됨. 정확한 이력을 남겨야 할 필요가 있을 경우에는 사용하면 안됨.
    - Local repository 에서 브랜치를 만들어 작업하다 push 해야 하는 경우, 굳이 브랜치의 흔적을 남길 필요가 없는 경우가 많음
- `$ git rebase -i HEAD~3`
    - HEAD에서 부터 최근 3개의 커밋을 표시하며, (HEAD 포함) vi 를 기반으로 interactive 하게 commit을 수정, 통합함
        - Vi 대신 다른 에디터를 사용하고 싶으면 기본 에디터 변경
        - (예. 메모장으로 변경) $ git config --global core.editor notepad
    - Squash (s)를 입력하면 Git은 해당 커밋과 바로 이전 커밋을 합치고
커밋 메시지도 Merge 한다.
    - 저장하고 나서 편집기를 종료하면 Git은 3개의 커밋 메시지를
Merge 할 수 있도록 에디터를 바로 실행해준다.
    - 만약 rebase 하다가 실수하면?
        - `$ git rebase --edit-todo`
            - 계속해서 중단된 작업 수행
        - `$ git rebase --abort`
            - Rebase 중단 및 원복

### 기타

- `$ git branch --d “branch name”`
    - Delete: 작업 중인 branch는 삭제 불가. 먼저 다른 branch로 HEAD를 옮기고 (checkout), 수행
- `$ git branch`
    - 현재 브랜치 확인
- `$ git show-branch`
    - 브랜치 확인
- `$ git log --graph --pretty=oneline --abbrev-commit`

## Branch 관리전략

성공적인 Branch Model

- 메인 브랜치(Main branch): Master, develop
- 피처 브랜치(Feature branch) 또는 토픽 브랜치(Topic branch)
- 릴리스 브랜치(Release branch)
- 핫픽스 브랜치(Hotfix branch)

### Main Branch

- 'master' 브랜치와 'develop' 브랜치, 이 두 종류의 브랜치를 보통 메인 브랜치로 사용합니다.
    - master : 'master' 브랜치에서는, 배포 가능한 상태만을 관리합니다.
커밋할 때에는 태그를 사용하여 배포 번호를 기록합니다.
    - develop : 'develop' 브랜치는 앞서 설명한 통합 브랜치의 역할을 하며, 평소에는 이 브랜치를 기반으로 개발을 진행합니다.

### Feature Branch

- Topic branch
- 새로운 기능 개발 및 버그 수정이 필요할 때
    - 'develop' 브랜치로부터 분기
    - 각 개발자에게 작업 분배 시 활용
    - 일반적으로 공유할 필요가 없기 때문에, 원격으로 관리하지 않음
    - 개발이 완료되면 'develop' 브랜치로 병합하여 다른 사람들과 공유

### Release Branch

- Master 브랜치로 병합하기 이전에, 병합 및 테스트 수행을 위
한 브랜치
    - 해당 릴리즈를 위한 최종적인 버그 수정 등의 개발 수행
        - 버그를 수정하거나 새로운 기능을 포함한 상태로 모든 기능이 정상적으로 동작하는지 확인
        - 모든 준비를 마치고 배포 가능한 상태가 되면 'master' 브랜치로 병합
        - 릴리즈 번호 태그로 구분
    - 기타 사항
        - 관례적으로 브랜치 이름 앞에 ＇release-＇ 를 붙임
        - 다음 릴리즈를 위한 개발 작업은 'develop' 에서 따로 계속 진행
        - 릴리즈 브랜치에서 기능을 점검하며 발견한 버그 수정 사항은 'develop' 브랜치에도 적용
        - 배포 완료 후 'develop' 브랜치에 대해서도 병합 작업을 수행

### Hotfix Branch

- 배포한 버전에 긴급하게 수정을 해야 할 필요가 있을 경우, 'master' 브랜치에서 분기하는 브랜치
    - 이미 작업 중인 develop 에서 수정하기는 어려우므로, 기존 배포 버전을 기반으로 hotfix 수행
    - 일반적으로 ‘hotfix-###’ 식으로 명명
    - 이후 develop 에도 병합하여 수정 사항 반영

텐서플로우가 대표적으로 Branch를 잘 이용하는 것을 보여준다. 그에 반해 리눅스의 경우에는 Branch를 하나만 가지고 잘 이용하는 모습도 보여준다.

---

- 6日

# AWS Computing Services

AWS에서는 배포 단위를 나눠서 여러 서비스를 제공한다.  

배포 단위
- 가상 프라이빗 서버 : Amazon Lightsail
- 가상 머신 : Amazon EC2
- 컨테이너 : Amazon ECS
- 서버리스 컨테이너 : AWS Fargate
- 코드 : AWS Lambda

## Amazon Lightsail

- 작은 규모의 서비스 구축을 위한 정액 요금제 서비스

## Amazon EC2

- 가상 서버 서비스
- 다양한 운영체제 사용 가능
- 다양한 과금 옵션 (온디맨드/예약/스팟)
- CPU/메모리/네트워크 등에 따라 다양한 인스턴스 타입 제공

### 프로비저닝 및 수명주기

- 생성 -> 시작 -> 중지 -> 종료
- 콘솔에서 수동관리
- API로 자동관리
- 디맨드 기반의 자동화 (수요 곡선)

### 가격

- On-demand price
    - 사용한 시간 단위 & 데이터 송수신 양으로 요금 책정
    - 일반적으로 운영체제 라이선스 비용이 포함되어 있으나,일부 SW는 사용자가 라이선스 관리를 해야 함
    - Linux, Windows, RHEL, SLES 등 (Redhat and Suse Enterprises)
    - Region 에 따라 가격이 다름

- Reserved Instance
    - 1년, 3년 단위로 미리 예약을 해서 사용하는 EC2 요금 정책
        - 비용 절감 및 유연성 유지
            - RI는 온디맨드 인스턴스 요금과 비교하여 상당한 할인 혜택(최대 75%)을 제공
        - 용량 예약 시작할 수 있다는 확신을 가질 수 있음
            - RI는 용량 예약을 제공하므로 사용자가 필요할 때 예약해 놓은 수의 인스턴스를 시작할 수 있다는 확신을 가질 수 있음

- Spot instance
    - AWS 내 유휴 자원을 경매를 통해 낮은 가격으로 짧은 시간 동안 이용할 수 있는 가격 정책
        - 크게 할인된 가격으로 이용 가능 (일반적으로 50% 이하)
        - 일시적이고 단기간동안 서비스를 사용해야 할 때 매우 유용함
    - 스팟 인스턴스의 요청
        - Bid: 지불하고자 하는 최고 스팟 가격을 지정
        - Start: 스팟 인스턴스는 스팟 가격이 지정한 가격보다 낮을 때 시작되고,
        - End: 이를 종료하도록 선택하거나,스팟 가격이 지정한 최고 가격을 초과할
때까지 계속해서 실행됨
        - 사용 시간을 설정할 수 있음: 1시간~6시간
            - 스팟 가격이 좀더 상승함

- Dedicated Hosting/Instance
    - 고객 전용의 EC2 인스턴스 용량을 갖춘 물리적 서버
        - 기존 서버에 한정된 소프트웨어 라이선스를 사용 가능
        - 물리 서버이므로 예측 가능한 성능 제공
    - 전용 호스팅 서버
        - 고객 전용으로 사용되는 물리 서버를 프로비저닝
    - 전용 인스턴스
        - 전용 호스팅 서버보다 물리적으로 제한적인 서비스
        - 특정 전용 서버에 배치할 수 없음, 용량 추가 불가 등

## EC2 Build

AWS Management Console에서 진행하며 과정은 이러하다.

1. AMI 선택
2. 인스턴스 유형 선태
3. 인스턴스 구성
4. 스토리지 추가
5. 태그 추가
6. 보안 그룹 구성
7. 검토

### AMI 선택

- “Free tier 사용 가능” 이란, Free tier 가 적용되는 인스턴스 타입(t2.micro)에서
수행 가능하고, 추가적인 라이선스 비용을 지불하지 않는다는 의미임.
- 다른 인스턴스 타입에서도 무료라는 의미가 아님
- Datacenter Edition
    - 1. 가상화된 환경에 대해 OS 커널이 최적화
    - 2. 데이터센터의 스토리지, 네트워크 환경에 최적화
    - 최근 다양한 OS가 데이터센터, 클라우드 에디션으로 배포되고, 비중이 급격히 높아지고 있음. 또한 비용 및 라이선스 정책도 상이함

### 스토리지 추가

- Windows server 요구량에 따라 자동으로 30GB 설정됨
- 리눅스 기본은 10GB
- Free tier의 EBS 허용량은 한달 30GB 이므로, Windows 하나를 사용하면 끝
- IOPS: I/O per Seconds
    - 스토리지 성능 단위. 높을수록 빠르고, 비싸다
    - SSD의 경우, 용량이 적을수록 성능 낮음

### Key Pair

- Key pair : 암호 파일
    - Build 이후, VM에 접근하기 위한 열쇠(private key)를 생성하는 것
    - 본인 컴퓨터에 열쇠 파일을 다운로드 하고, 이후 접근할 때 해당 파일을 사용해야 함
    - 분실 시, AWS에서 새로 발급받을 수 없음
    - 타인이 습득 시, 내 VM에 접근할 수 있음
        - 내 신용카드가 등록되어 있는데?
        - 상용 서비스를 하고 있다면? 고객 정보는?
- 다운로드를 하면 pem 확장자 파일이 나옴
    - 개인 이메일 계정으로 전송하고, 공용 컴퓨터에서는 완전히 삭제할 것
        - Shift + del

### Console

- Alarm status
    - 특정 조건을 설정하여, 여러가지 방식으로 관리자에게 알려줌
    - 예) CPU 사용률이 10분간 80% 를 넘으면, 우선 VM을 정지하고, 관리자에게 메일로 알려줌
- Public DNS and IP (IPv4)
    - 외부에서 접속 가능한 DNS 및 IP 주소
    - IPv6 는 따로 설정하여야 함
- Security Group
    - 접근 권한에 대한 설정을 그룹으로 관리할 수 있음

## AMI

- AMI
    - Amazon 머신 이미지(AMI)는 인스턴스를 시작하는 데 필요한 정보를 제공합니다. (Operating Systems + @)
    - 인스턴스를 시작할 때 AMI를 지정해야 합니다.
    - 동일한 구성의 인스턴스가 여러 개 필요할 때는 한 AMI에서 여러 인스턴스를 시작할 수 있습니다.
    - 서로 다른 구성의 인스턴스가 필요할 때는 다양한 AMI를 사용하여 인스턴스를 시작하면 됩니다.

### AMI 종류

- My AMI
    - 직접 생성한 AMI
    - 기존 AMI를 기반으로 자신만 사용할 수 있는 AMI를 작성 가능
    - 스토리지 (EBS) 사용 요금을 지불해야 함
- AWS Marketplace
    - 회사 또는 개인이 유용한 AMI를 작성하여 판매하는 것
    - AMI 사용료로 시간 당 별도 과금이 이루어짐 (ec2 와 별개). 무료 상품도 존재함.
    - 모든 종류의 SW 포함
    - 예) VPN 서버, Machine Learning, Block chain 등등
- Community AMI
    - 커뮤니티에 공개해 공유하는 AMI로, Marketplace AMI 와 유사하지만 무료임
    - Marketplace AMI의 old version 이거나 test 용 버전이 많음
    - 기술 지원 등을 기대하기 어려움

---

# Load test for Web services

## 부하 테스트

소프트웨어 시스템에 요청을 보내서 응답을 측정하는 절차

- 웹서비스의 품질을 파악하기 위한 테스트
    - 현재 서비스 구성의 제한(limit)을 찾기 위함
    - 원하는 부하를 수용할 수 있게끔 구성되었는지 확인하기 위함
    - 병목 지점을 찾고 병목 현상을 제거하기 위함
- 우리가 만든 웹서비스의 성능을 테스트하기 위해 사용
    - 얼마나 많은 요청을 처리할 수 있을까? (현재의 HA 구성에서)
    - 많은 요청 수에 대해 자동으로 처리 성능을 조절할 수 있을까?
    - 차후 Auto Scaling 의 동작 및 성능 확인에 사용

## 스트레스 테스트

시스템의 안정성을 결정하기 위해서 수행되는 의도적인 심한 테스트로, 일반적인 운영 용량을 넘은 테스트를 수행하여 결과를 관찰한다.

## AB

- 아파치 웹서버 성능검사 도구
    - Apache HTTP Server 의 간단한 성능 벤치마킹 도구
        - 정적 컨텐츠, REST API 등
    - 아파치 서버 패키지에 포함
    - 특히 아파치가 현재 초당 몇개의 요청을 서비스하는지 알려줌
- 유의할 점
    - AB는 서버의 응답에 걸리는 시간만 측정
        - Server-side centric benchmark
    - 사용자가 실제로 느끼는 체감 성능은?
        - HTML translation, image file loading, and etc.
        - Request 간의 delay를 줄 수 없기 때문에, 실제 요청 패턴과 차이가 있음

### Usage

Usage: `ab [options] [http[s]://]hostname[:port]/path`

### options

- `-n` : 성능을 검사하기위해 보내는 요청수. 기본값으로 요청을 한번만 보내기 때문에 일반적인 성능검사 결과를 얻을 수 없다.
- `-c` : 동시에 요청하는 요청수. 기본적으로 한번에 한 요청만 보낸다.
- `-g` : 측정한 모든 ㄱ밧을 'gnuplot' 혹은 TSV (Tab separate values, 탭으로 구분한 값) 파일에 기록한다. 라벨은 output 파일의 첫번째 라인을 참고한다.
- `-t` : 성능을 검사하는 최대 초단위 시간. 내부적으로 `-n 50000`을 가정한다. 정해진 시간동안 서버 성능을 검사할때 사용한다. 기본적으로 시간제한 없이 검사한다.
- `-v` : 출력 수준을 지정한다. 4 이상이면 헤더에 대한 정보, 3 이상이면 응답코드, 2 이상이면 경고와 정보를 출력한다.
- `-A` : 프록시를 통해 BASIC Authentication 정보를 제공한다. :로 구분한 사용자명과 암호를 base64 인코딩하여 전송한다.
- `-X` : proxy[:port] 프록시 서버를 사용하여 요청한다.

### example

- `ab -c 50 -t 10`
    - 서버가 10초동안 동시에 50개의 요청을 지속적으로 처리
    - 즉, 서버에 50개의 요청 부하가 지속적으로 몰려있는 상황
        - 50명의 사용자가 아니라, n명의 사용자가 무작위로 요청을 보내는데,
        - 서버 입장에서 볼 때, 언제나 50개의 요청이 대기 큐에 쌓여있는 것
    - 성능이 좋을수록, 총 처리된 요청 개수가 많아질 것.
- `ab -n 500 -c 10`
    - 서버가 10개의 동시 요청을 총 500개 처리하는 시나리오
    - 대기큐에 10개의 요청이 항상 쌓여있는데, 총 요청 수는 500개
    - 성능이 좋을수록, 총 수행 시간이 짧아질 것.

### Result

`-c 500 -t 10`

- Concurrency evel : 500
- Time taken for tests : 10001 seconds
- Complete requests : 2447
- Failed requests : 0
- Total transferred : 34507594 bytes
- HTML transferred : 33479854 bytes
- Requests per second : 244.67 [#/sec] (mean)
- Time per request : 2043.556 [ms] (mean)
- Time per request : 4.087 [ms] (mean, across all concureent requests)
- Transfer rate : 3369.47 [Kbytes/sec] received

- Percentage of the requests served within a certain time (ms)
    - 50% : 1905
    - 66% : 2022
    - 75% : 2103
    - 80% : 2175
    - 90% : 2333
    - 95% : 2495
    - 98% : 2660
    - 99% : 2726
    - 100% : 3137 (longest request)

50%와 100% 사이에 오차가 적어야 좋은 시스템을 의미한다.

### Result Analysis

- Failed requests
    - Fail 이 있을 경우, reliability 의 훼손
        - 즉, 서버가 제공할 수 있는 범위를 벗어남
            - 벤치마킹 중간에 정지될 수 있음
        - Length 제외: 첫 요청에 대한 응답과 다른 길이의 응답이 오는 경우를 측정함. 동적인 컨텐츠의 경우, 지속적으로 발생할 수 있음
- Response time
    - 요청 처리 시간의 표준 편차가 너무 크거나,
    - 요청 처리 시간 백분위에서 tail 이 길게 형성이 되거나,
    - 요청 처리 시간 자체가 너무 긴 경우,
    - 서비스의 품질이 사용자 요구사항에 크게 미달할 수 있음

### Long tail of Response time

`$ab -n 100 -c 10 -g result.plot http://www.google.com/index.html`

[참고사이트](https://blog.hkwon.me/ab-apache-http-server-benchmarking-tool/)

- 약 10% 의 요청이 800ms 이내에 처리되었음.
즉, 나머지 90%의 요청은 800ms 이상 소요되었음
- -c 10 옵션을 주었으므로 10개의 요청이 쌓일 때까지
이전 9개 까지는 빠르게 처리되다가, 10개 이후부터는
서버에 부하가 쌓이며 점차 느려지는 양상을 볼 수 있음
- 실제 서버의 부하는 상당 시간 서비스가 지속된 상태,
즉, 평균 사용자 수로 상당 시간 유지된 상태의
평균 요청 처리 수를 보아야
실제 사용자가 느끼는 서비스 수준을 파악할 수 있음

---

- 7日

# typeScript

## 설치

```
$ npm i -g typescript
```
app.ts
```ts
const name:string = "younghun";
const age:number = 24;
```

## 컴파일

```
$ tsc app.ts
```

컴파일이 완료되면 ts파일이 js파일로 변환  

## express 환경 구축

```
$ tsc --init
```

tsconfig.json 파일이 생성된다. 해당 파일에서 
```json
{
 "compilerOptions": {
   "target":"es6",
   "module":"commonjs",
   "outDir":"./dist",
   "rootDir":"./src",
   "strict": true,
   "moduleResolution":"node",
   "esModuleInterop":true
  }
}
```

주석을 지워주고 이러한 부분만 유지한다.

- target : 컴파일 ECMAscript 대상
- module : 모듈 코드 생성
- outDir : 컴파일 경로
- rootDir : 컴파일 대상의 root 디렉토리
- strict : typescript 엄격한 유형 검사 활성화
- moduleResolution : node 또는 classic 모듈 분석

등으로, [docs](https://www.typescriptlang.org/docs/handbook/tsconfig-json.html)을 참고하는게 제일 빠르다.  



```
$ npm init -y
$ npm i -D express typescript ts-node nodemon @types/node @types/express
```

express 환경을 구성 한 뒤 package.json을 고쳐준다.

```json
"script": {
  "start": "node dist/app.js",
  "dev": "nodemon src/app.ts",
  "build": "tsc -p ."
}
```

- start : 컴파일 한 app.js를 node 명령어로 실행
- dev : nodemon으로 typescript 파일 개발환경으로 실행
- build : 실제로 컴파일 후 javascript 파일 생성

## ts 파일 작성

여타 js로 작성하는 express와 달리 소스 맨 위에 이 부분을 적어줘야한다.

```ts
import express, {Request, Response, NextFunction} from 'express';
```

콜백 함수 작성시에 이렇게 사용할 수 있다.  

```ts
app.get('/', (req:Request, res:Response, next:NextFunction) => {
    // content
})
```

자바스크립트를 사용한 express와의 차이는 타입스크립트로 자료형 명시와 콜백에서의 명시 이외에는 없는거 같다. 하지만 코드 작성 방식에 따라서 module로 사용하거나, 클래스를 사용하게 되면 전혀 다른 언어와 같이 보인다는 점이 있다. 그러한 방법은 낯설게만 느껴졌다.

---

- 8日

# React

Velopert님의 강의를 듣고 정리하였습니다.

## JSX

1. Nested Element

```jsx
    /* 변경 필요 */
render() {
    return (
        <h1>HI</h1>
        <h2>I am Error</h2>
    )
}

render() {
    return (
        <div>
            <h1>Hi</h1>
            <h2>Error is gone.</h2>
        </div>
    )
}
```

2. JavaScript Expression

```jsx
/* Javascript 표현식은 {} 으로 감싸야한다. */
render() {
    let text = "hello React!";
    return (
        <div> {text} </div>
    );
}

/* 추가적으로 If Else 문 JSX 사용 */
render() {
    return (
        <p> { 1 == 1 ? 'True' : 'False'} </p>
    )
}
```

3. Inline Style

```jsx
/* JSX 안에서 style을 설정시 string 형식이 아닌 key가 camelCase인 객체 사용 */
render() {
    let style = {
        color : 'aqua',
        backgroundColor: 'back'
    };

    return (
        <div> {style}React</div>
    );
}

/* 클래스 사용 시 'className=' 사용 */
render() {
    return (
        <div className='box'>React</div>
    );
}
```

4. Comments

```jsx
/* JSX에서 주석 사용시 {}으로 감싸줘야한다 */

render() {
    return (
        <div>
            {/* This is How You Comment */}
            {/* Multi-line
                Testing*/}
                React
        </div>
    )
}
```

## props

- 컴포넌트 내부의 Immutable Data
- JSX 내부에 { this.props.propsName }
- 컴포넌트를 사용할 때, <> 괄호 안에 propsName="value"
- this.props.children은 기본적으로 갖고 있는 props로, <component> -해당 값이 들어감- </component>

1. 기본 값 설정

- Compoent.defaultProps = { ... }

```jsx
class App extends React.Component {
    render() {
        return (
            <div> {this.props.value} </div>
        );
    }
};
App.defaultProps = {
    value: 0
};
```

2. Type 검증

- Component.propTypes = { ... }

```jsx
Class App extends React.Component {
    render() {
        retrun(
            <div>
                {this.props.value}
                {this.props.secondValue}
                {this.props.thirdValue}
            </div>
        );
    }
};
App.propTypes = {
    value: React.PropTypes.string,
    secondValue: React.PropTypes.number,
    thirdValue: React.PropTypes.any.isRequired
};
```

## state

- 유동적인 데이터
- JSX 내부에 `{ this.state.stateName }`
- 초기값 설정이 필수, 생성자(constructor)에서 `this.state = {}` 으로 설정
- 값을 수정할 때에는 `this.setState({...})`, 렌더링 된 다음엔 `this.state =` 절대 사용하지 말 것

### 예시

```jsx
class Counter extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      value: 0
    };
    this.handleClick = this.handleClick.bind(this);
  }
  
  handleClick() {
    this.setState({
      value: this.state.value + 1
    });
  }
  
  render() {
    return (
      <div>
        <h2> {this.state.value} </h2>
        <button onClick = {this.handleClick}> Press me </button>
      </div>
    );
  }
}

class App extends React.Component {
  render() {
    return (
      <Counter/>
    );
  }
};

ReactDOM.render(
  <App></App>,
  document.getElementById("root")
);
```

1. 

```jsx
handleClick() {
    this.setState({
        value: this.state.value + 1
    });
}
```

2. 

```jsx
handleClick() {
    this.state.value = this.state.value + 1;
    this.forceUpdate();
}
```

1과 2는 같은 기능을 하지만, 2번 코드의 경우에는 렌더링 된 후 stat.value를 대입하여 바꾸므로 사용을 지양해야한다.  


## Component Mapping

- Javascript Map : 파라미터로 전달 된 함수를 통하여 배열 내의 각 요소를 처리해서 그 결과로 새로운 배열을 생성한다.
    - `arr.map(callback, [thisArg])`
        - callback : 새로운 배열의 요소를 생성하는 함수로서, 다음 세가지 인수를 가진다.
            - currentValue : 현재 처리되고 있는 요소
            - index : 현재 처리되고 있는 요소의 index 값
            - array : 메소드가 불러진 배열
        - thisArg (선택항목) : callback 함수 내부에서 사용할 this 값을 설정

```js
var numbers = [1,2,3,4,5];
var processed = numbers.map(function(num) {
    return num*num;
})

||

var processed = numbers.map((num) => {
    return num*num;
})
```

### 예제

```jsx
class ContactInfo extends React.Component {
  render() {
    return (
      <div> {this.props.contact.name} {this.props.contact.phone} </div>
    )
  }
}

class Contact extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      contactData: [
        {name: 'A', phone: '010-0000-0002'},
        {name: 'B', phone: '010-0000-0003'},
        {name: 'C', phone: '010-0000-0004'},
        {name: 'D', phone: '010-0000-0005'}
      ]
    }
  }
  
  render() {
    const mapToComponent = (data) => {
      return data.map((contact, i) => {
        return (<ContactInfo contact={contact} key={i}/>);
      });
    }
    
    return (
      <div>
        {mapToComponent(this.state.contactData) }
      </div>
    );
  }
}

class App extends React.Component {
  render() {
    return (
      <Contact/>
    );
  }
};

ReactDOM.render(
  <App></App>,
  document.getElementById("root")
);
```

---

- 9日

삼각 달팽이
```cpp
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int table[1002][1002];

vector<int> solution(int n) {
	vector<int> answer;
    memset(table, -1, sizeof(table));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			table[i][j] = 0;
		}
	}
	int cnt = 1;
	int y = 1, x = 1;
	while(1) {
		bool flag = true;
		while(1) {
			if(table[y][x] != 0)
				break;
			table[y++][x] = cnt++;
			flag = false;
		}
		y--;
		x++;
		while(1) {
			if(table[y][x] != 0)
				break;
			table[y][x++] = cnt++;
			flag = false;
		}
		x-=2;
		y--;
		while(1) {
			if(table[y][x] != 0)
				break;
			table[y--][x--] = cnt++;
			flag = false;
		}
		x++;
		y+=2;
		if(flag)
			break;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
            if(table[i][j] == -1 || !table[i][j])
                continue;
			answer.push_back(table[i][j]);
		}
	}
    return answer;
}

```

배열을 먼저 -1로 초기화 한 뒤 정수 n 만큼 배열을 0으로 초기화 했다. 따라서 -1인 부분은 경계선이며 0이 변경 가능한 지역이다. 따라서 아래, 오른쪽, 좌상 대각선 반복을 하되, 0이 아닌 곳을 만나게 되면 멈추도록 설계했다. 전체 큰 반복문은 내부 반복문의 조건에 한번도 맞지 않으면 탈출하도록 하여 해결했다.  

해당 문제를 조금 깔끔하게 코딩하지 못한거 같다. 노력이 필요한 부분이다.  

2 x n 타일링
```cpp
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

int solution(int n) {
    int prev = 1;
    int cur = 1;
    for (int i=0; i<n-1; i++) {
        int temp = (prev + cur) % MOD;
        prev = cur;
        cur = temp;
    }
    return cur;
}
```

다이나믹 프로그래밍에서 대표적인 문제로, 2x1 타일과 1x2 타일로 구성한 가로길이가 주어지면 사용하는 경우의 수를 구하는 문제이다. 나는 바로 캐치하지 못하고 여러가지 경우의 수를 생각해보았다. 따라서 길이가 1, 2, 3 ... 인 예시를  쭉 생각해보았다. 그러자 피보나치와 같은 패턴을 보이는 것을 알 수 있었다. 그렇게 하여 해결할 수 있었다.  

이 부분을 점화식으로 접근해보면, `P(n) = P(n-1) + p(n-2)`와 같이 나온다. 왜냐하면 n번째는 n-1번째에서 가능한 경우의 수는 세로 타일을 하나 넣는 경우다. 그리고 n-2번째에서 가능한 경우는 세로 타일 혹은 가로 타일을 얘기할 수 있다. n-2번째에서 가능한 세로타일을 넣는 경우는 n-1번째에서 이야기한 경우가 포함된 경우다. 따라서 n을 구하고자 할 때는 n-1인 부분과 n-2인 부분을 더해줘야 구할 수 있다고 볼 수 있다.  

따라서 피보나치와 같은 점화식이 구해진다. 해당 점화식을 적용하게 되면 경우의 수를 하나하나 찾아 규칙을 찾은 것과 같다. 이제는 점화식을 먼저 찾아내서 코딩하는 습관을 들여야겠다.

---

- 10日

2020 한국 대학생 프로그래밍 대회 예선을 치뤘다. 3인 1팀으로 각 학교에서 치뤄지는데 전체 101등 학교 3등으로 마치게되었다. 하지만 많은 문제를 빠르게 풀지 못해서 아쉬움이 크다. 오히려 팀원들이 잘 풀어서 그 정도 결과가 나온 것 같다.  

# MongoDB

- Model : Schema를 감싸주는 역할  
- Schema : 정보들을 집약해주는 역할
- mongoose : Mongo DB ODM (Object Domcument Mapping) 중 하나로 가장 많이 사용한다.
- ODM : 객체와 문서를 1:1로 매칭한다는 뜻으로 문서를 DB에서 조회할 때 자바스크립트 객체로 바꿔주는 역할을 한다.

```js
const mongoose = require('mongoose');
mongoose.connect('', {
    useNewUrlParser: true, useUnifiedTopology: true, useCreateIndex: true, useFindAndModify: false
}).then(() => {
    console.log(`Mongoose Conected`);
}).catch(err => {
    console.log(err)
})
```

mongoose를 이용하여 등록하는 코드인데, 사실 이 코드를 이용할려면 먼저 mongoDB에서 선 작업이 필요하다. 해당 connect 구문에서의 뒤에 주소를 가져오는 작업이다.  

이후 모델과 스키마를 만들어주는 코드이다.  

```js
const mongoose = require('mongoose');

const userSchema = mongoose.Schema({
    name: {
        type: String,
        maxlength: 50
    },
    email: {
        type: String,
        trim: true,
        unique: 1
    },
    password: {
        type: String,
        minlength: 3
    },
    lastname: {
        type: String,
        maxlength: 50
    },
    role: {
        type: Number,
        default: 0
    },
    image: String,
    token: {
        type: String
    },
    tokenExp: {
        type: Number
    }
});

const User = mongoose.model('User', userSchema);

module.exports = { User }
```

이와 같이 먼저 Schema를 정의 한 뒤 모델을 그 Schema를 감싸서 모듈화시켜서 내보내게되면 다른 js파일에서 해당 모델을 사용할 수 있다.  

## 회원가입

body-parser 미들웨어와 postman이나 insomnia와 같이 rest api를 보낼 수 있는 툴로 클라이언트가 없는 상태에서 통신할 수 있게 하여 회원가입을 구현하고자 한다.

### body-parser

```js
const bodyParser = require('body-parser);
// application/x-www-form-urlencode
app.use(bodyParser.urlencoded({extended: true}));
// application/json
app.use(bodyParser.json());
```
body-parser를 사용하게 되면 json형식으로 rest api를 이용하게 될 때 `req.body`와 같은 문법으로 받아서 쉽게 파싱할 수 있다.

### rest api

```js
app.post('/register', (req, res) => {
    const user = new User(req.body);
    user.save((err, userInfo) => {
        if(err)
            return res.json({ success: false, err})
        return res.status(200).json({
            success: true
        })

    })
})
```

body-parser 미들웨어를 사용하여 바로 User라는 모델에 post로 넘어오는 정보를 등록하는 모습이다. 성공하면 success를 true로 반환하고 실패했다면 success를 false로 반환한 뒤 에러를 출력한다.  

---

- 11日

# Mongo DB

## MongoURI 숨기기

Mongoose를 사용할 때 MongoDb와 연결하기 위해서 MongoDB의 아이디와 비밀번호 그리고 클러스터와 데이터베이스 이름까지 다 노출되기 때문에 다른 파일로 관리를 하게 된다.  

이때 node.js는 로컬과 배포시의 환경변수가 다른 점을 이용해서 URI를 다르게 잡아줄려고 한다.  

`key.js`, `dev.js`, `prod.js` 3가지로 봐보자.

key.js
```js
if(process.env.NODE_ENV == 'production') {
    module.exports = require('./prod');
} else {
    module.exports = require('./dev');
}
```
`process.env.NODE_ENV` 환경변수의 경우 로컬환경과 배포환경의 값이 다르다 따라서 `production`인 경우는 배포 하는 mongoURL을 달아주고, 아닌 경우에는 개발환경의 mongoURL을 달아줘서 사용하면 된다.  

## node.js bcrypt 미들웨어

[npm 패키지 사이트](https://www.npmjs.com/package/bcrypt)

### 설치

```
npm install bcrypt
```
npm을 이용하여 미들웨어를 설치해준다.

### 사용법

설정
```js
const bcrypt = require('bcrypt');
const saltRounds = 10;
```

비밀번호 암호화
```js
bcrypt.genSalt(saltRounds, function(err, salt) {
    bcrypt.hash(, salt, function(err, hash) {
        // DB에 비밀번호 속성 Hash값 저장
    })
})
```

### MongoDB와 사용

통신이 오면 해당 모델로 저장을 하게 된다.
```js
app.post('/register', (req, res) => {
    const user = new User(req.body);
    user.save((err, userInfo) => {
        if(err) return res.json({ success: false, err})
        return res.status(200).json({
            success: true
        })

    })
})
```

스키마와 모델이 정의된 코드에서 bcrypt를 설정해준 뒤 mongoose에서 사용가능한 `pre()` 메소드를 통해서 통신이 왔을 때 save 직전에 비밀번호가 바뀌었다면, 해당 값을 암호화하여 저장하도록 하는 코드이다.
```js
const mongoose = require('mongoose');
const bcrypt = require('bcrypt');
const saltRounds = 10;

const userSchema = mongoose.Schema({
    name: {
        type: String,
        maxlength: 50
    },
    email: {
        type: String,
        trim: true,
        unique: 1
    },
    password: {
        type: String,
        minlength: 3
    },
    lastname: {
        type: String,
        maxlength: 50
    },
    role: {
        type: Number,
        default: 0
    },
    image: String,
    token: {
        type: String
    },
    tokenExp: {
        type: Number
    }
});

userSchema.pre('save', function(next) {
    let user = this;

    if(user.isModified('password')) {
        // 비밀번호 암호화
        bcrypt.genSalt(saltRounds, function(err, salt) {
            if(err) return next(err);
    
            bcrypt.hash(user.password, salt, function(err, hash) {
                if(err) return next(err);
                
                user.password = hash;
                next();
            })
        })
    } else {
        next();
    }
})

const User = mongoose.model('User', userSchema);

module.exports = { User }
```

또한, 비밀번호를 DB에 생성한 뒤 나중에 로그인하기 위해서 비밀번호를 비교하게 된다. 이때는 DB에 저장된 암호화시킨 비밀번호가 아닌 비교하기 위해 들어오는 비밀번호를 암호화시켜서 저장된 비밀번호와 비교하게 된다.  

bcrypt에서의 솔트는 해쉬를 강화한다는 장치로 이해하면 좋다.  

## JWT를 이용한 로그인

JsonWebToken로, node에서 다음과 같이 설치한다.

```
npm install jsonwebtoken --save
```

그리고 JWT는 저번에 공부한 것과 같이 cookie, localstroage, session에 저장이 가능하다. 이번에는 cookie에 저장하는 방법으로 할 것이다.

비밀번호 비교
```js
userSchema.methods.comparePassword = function(plainPassword, cb) {
    // plainPassowrd와 encoded password 비교
    bcrypt.compare(plainPassword, this.password, function(err, isMatch) {
        if(err) return cb(err);
        cb(null, isMatch);
    })
}
```

토큰 생성
```js
userSchema.methods.generateToken = function(cb) {
    // jwt를 이용한 token 생성
    const user = this;
    const token = jwt.sign(user._id.toHexString(), 'secretToken');
    user.token = token;
    user.save(function(err, user) {
        if(err) return cb(err);
        cb(null, user);
    })
}
```

post를 통해서 요청을 받아서 `이메일 체크 -> 비밀번호 체크 -> 토큰 생성 후 쿠키 저장` 방식으로 진행한다.

```js
app.post('/login', (req, res) => {
    // 이메일이 DB에 있나 체크
    User.findOne({ email: req.body.email }, (err, user) => {
        if(!user) {
            return res.json({
                loginSuccess: false,
                message: "제공된 이메일에 해당하는 유저가 없습니다."
            })
        }
        // 있다면 비밀번호가 맞나 체크
        
        user.comparePassword(req.body.password, (err, isMatch) => {
            if(!isMatch) return res.json({loginSuccess: false, message: "비밀번호가 틀렸습니다."});
            
            // 맞으면 Token 생성
            user.generateToken((err, user) => {
                if(err) return res.status(400).send(err);
    
                // 토큰을 저장한다. 쿠키, 로컬스토리지, 세션
                // 쿠키 저장
                res.cookie("x_auth", user.token)
                .status(200)
                .json({ loginSuccess: true, userId: user._id});
            })
        })
    })
})
```

이 부분을 통해 알 수 있던 부분은 스키마에 메소드를 생성할 때 매개변수를 맞춰줘야하는데 이 부분을 콜백함수로 잡아주는 부분이 새로웠다.  

그리고 쿠키에 경우에는 마지막에 `res.cookie("x_aut", user.token)` 부분을 통해서 쿠키를 저장할 수 있다는 것이다. 로컬 스토리지의 경우에는 클라이언트단에서 dom에 접근하여 저장하는 것만 사용해봐서 더욱 간단했다.  

## Auth

클라이언트의 토큰을 복호화했을 때 서버의 토큰과 같다면 인증이 통과하고 해당 토큰을 복호화해서 나온 id의 값이 같다면 해당 정보를 제공하는 것을 인증한다.

```js
app.get('/api/users/auth', auth, (req,res) => {
    
    // 미들웨어를 통과해 여기까지 온다면 인증은 통과됨

    res.status(200).json({
        _id: req.user._id,
        isAdmin: req.user.role === 0 ? false : true,
        isAuth: true,
        email: req.user.email,
        name: req.user.name,
        lastname: req.user.lastname,
        role: req.user.role,
        image: req.user.image
    })
})
```

`./middleware/auth.js`
```js
const { User } = require('../models/User');

let auth = (req, res, next) => {
    // 인증 처리
    
    // 1. client cookie token 받기
    const token = req.cookies.x_auth;
    // 2. Token decode, 유저 찾기
    User.findByToken(token, (err, user) => {
        if (err) throw err;
        if (!user) return res.json({ isAuth: false, error: true });
        
        // 요청시에 사용할 수 있게 요청값에 넣어준다.
        req.token = token;
        req.user = user;
        next();
    })
    // 3. 유저 있으면 인증 o, 없으면 인증 x
    
}
module.exports = { auth }
```

순서는 클라이언트 쿠키에 있는 토큰을 받은 뒤 해당 토큰을 복호화하여 유저를 찾아준다. 이후 찾게 된다면 통신에서 사용할 수 있게 요청값에 토큰과 유저를 넣어준다. `next()`를 통해서 미들웨어가 끝난 뒤 넘어갈 수 있게 해준다.  

마지막으로 module로 auth를 만들어서 사용할 수 있게 한다. 

mongoDB model User
```js
userSchema.statics.findByToken = function(token, cb) {
    let user = this;

    // token decode
    jwt.verify(token, 'secretToken', function(err, decoded) {
        // 유저 아이디로 찾은 뒤
        // 클라이언트에서 가져온 token과 db의 token 비교
        user.findOne({
            "_id" : decoded,
            "token": token
        }, function(err, user) {
            if(err) return cb(err);
            cb(null, user);
        })
    })
}
```
해당 메소드는 유저 스키마가 token을 복호화시킨 경우 유저아이디가 일치하는 것을 찾은 뒤 token을 비교한 뒤 맞다면 user 스키마를 콜백으로 보내주는 메소드이다.  

## logout

auth를 이용한 로그인 이후에는 로그아웃은 쉽다. 왜냐하면 로그인의 경우는 auth 미들웨어를 만들어서 token을 복호화하여 클라이언트 token과 db의 token을 비교하는 과정을 거치게 된다. token이 같아야 auth를 통과하고 그 이후의 내용을 진행한다.  

로그인의 경우는 db에 저장된 token을 통해서 로그인 유무를 알 수 있었다. 따라서 로그아웃은 db의 해당 유저의 token을 초기화시키게 되면 로그아웃 상태로 체크할 수 있다.  

따라서 다음 코드와 같이 만들게 되면 token을 초기화시킬 수 있다.

```js
app.get('/api/users/logout', auth, (req,res) => {
    User.findOneAndUpdate({ _id: req.user._id},{ token: "" }, (err, user) => {
        if (err) return res.json({success: false, err});
        return res.status(200).send({
            success: true
        })
    })
})
```

auth 미들웨어를 먼저 거치기 때문에 로그인이 되어있어야 auth를 거쳐서 콜백함수를 진행할 수 있다. `findOneAndUpdate` 함수를 통해서 id를 찾고 token을 초기화 시킨다. 이 부분을 Insomnia를 통해서 통신을 해보니 확실히 알 수 있었다.  

---

# react 

## Virtual DOM vs Real DOM

- Real DOM : 여러 요소 중 하나의 요소를 업데이트한 경우 전체 요소를 모두 Reload해야 하는 Super Expensive한 작업

- Virtual DOM : 여러 요소 중 하나의 요소를 업데이트한 경우 해당 요소만 DOM에서 Reload하는 작업

### Virtual DOM

1. JSX을 렌더링. 그러면 Virtual DOM이 Update

2. Virtual DOM이 이전 virtual DOM에서 찍어둔 Snapshot과 비교를 해서 바뀐 부분 찾기 (diffing)

3. 바뀐 부분만 Real DOM에서 바꿈

## Creat React App

예전엔 리액트 앱을 처음 실행하기 위해서 webpack이나 babel같은 것을 설정하기 위해서 많은 시간이 걸렸다. 하지만 이제는 `create-react-app`을 통해 바로 시작할 수 있다.

### Babel

최신 자바스크립트 문법을 지원하지 않는 브라우저들을 위해서 최신 자바스크립트 문법을 ES5 자바스크립트 문법로 변환하여  구형 브라우저에서도 실행 가능하게 함

### Webpack

많은 모듈들을 번들화시켜 간단하게 만들어주는 것으로, 상당히 복잡한 내용을 가지고 있으므로 여기서는 이 정도만 알아두자

### 설치

```
npx create-react-app .
```

이전에는 `npm install -g create-react-app`를 사용하여 global 디렉토리에 다운로드 받았었다. 이제는 npx를 이용하여 다운 받지 않고 사용이 가능하다. 이 부분을 살펴보자

## npx

### npm

npm (node package manager)는

1. 레지스트리와 같은 저장소 역할을 한다.

2. 어플리케이션을 실행하거나 빌드할 때 사용한다.

package.json에 npm에 대한 정의가 있으므로 살펴보면 좋다.  

npm을 통해서 install하는 경우 `-g` 옵션을 주지 않는다면 local로 다운로드 하게 된다. 이때는 `node_modules`라는 폴더에 쌓이게 된다.  

`-g`옵션을 주게 되면 프로젝트를 넘어 컴퓨터에 저장을 하는 것이다. 예를 들어 리눅스의 경우 `/usr/local/bin`에 저장이 된다.  

### npx

원래는 create-react-app을 설치할 때는 `npm install -g create-react-app`을 다운을 받았으나, 이제는 npx를 이용하여 다운로드를 받지 않고 npm registry에 있는 것을 받아와서 설치할 수 있다.  

이러한 방법의 장점은 disk storage를 낭비하지 않을 수 있으며, 항상 최신버전을 이용할 수 있다.  

---

- 12日

# react

## React Router Dom

[공식사이트](http://www.reacttraining.com/react-router/web/example/basic)  
React에서 페이지를 이동할 때는 React Router Dom을 사용한다.

### 기본 예시

```js
import React from 'react'

import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from "react-router-dom";

export default function App() {
  return (
        <Router>
      <div>
        <ul>
          <li>
            <Link to="/">Home</Link>
          </li>
          <li>
            <Link to="/about">About</Link>
          </li>
          <li>
            <Link to="/dashboard">Dashboard</Link>
          </li>
        </ul>

        <hr />

        {/*
          A <Switch> looks through all its children <Route>
          elements and renders the first one whose path
          matches the current URL. Use a <Switch> any time
          you have multiple routes, but you want only one
          of them to render at a time
        */}
        <Switch>
          <Route exact path="/">
            <Home />
          </Route>
          <Route path="/about">
            <About />
          </Route>
          <Route path="/dashboard">
            <Dashboard />
          </Route>
        </Switch>
      </div>
    </Router>
  );
}


function Home() {
  return (
    <div>
      <h2>Home</h2>
    </div>
  );
}

function About() {
  return (
    <div>
      <h2>About</h2>
    </div>
  );
}

function Dashboard() {
  return (
    <div>
      <h2>Dashboard</h2>
    </div>
  );
}
```

와 같이 사용하게 되면 home, about, dashboard로 나눠서 이동을 볼 수 있다. 또, Switch 부분을 축약할 수 있다.

```js
<Switch>
    <Route exact path="/">
        <Home />
    </Route>
    <Route path="/about">
        <About />
    </Route>
    <Route path="/dashboard">
        <Dashboard />
    </Route>
</Switch>
```
와 같은 부분을 다음과 같이 바꿀 수 있다.

```js
import home from './src/home'
import about from './src/about'
import dashboard from './src/dashboard'
<Switch>
    <Route exact path="/" component={home} />
    <Route exact path="/about" component={about} />
    <Route path="/dashboard" component={dashboard} />
</Switch>
```

---

# 소프트웨어공학

# 분석의 문제점

- 의사 소통의 문제
- 요구사항의 계속적 변화
- 분석도구의 미비
- 문서화의 어려움
- 정치적인 문제
- 일 할당 문제

### 의사 소통의 문제

사용자와 개발자 사이에 동의된 것도 시간이 지나고 나면 완전히 다른 모습으로 나타날 때가 많으므로 정확한 의사소통과 목표에 대한 기대를 명확하게 하기위해 문서화가 반드시 필요하다.  

분석단계에서 사용자와 개발자의 **의사소통**을 위하여 그림으로 생각을 표현하는 도구들이 개발되어 활용되고 있다. 대표적인 도구가 ER-다이어그램이다.

### 요구사항의 계속적 변화

사용자의 시스템에 대한 이해도가 증가하며 요구사항은 계속하여 변한다. 따라서 요구사항 명세서는 수정하기 쉽게 쓰여져야한다.  

개발에 들어가기 전, 요구사항을 동결하는 것은 프로젝트 관리상 필요하다. 요구사항의 계속적 변화고정된 요구사항 명세서를 시스템개발의 **기준선문서**라 하며, 이후에 요구되는 명세서의 변경은 프로젝트에 관계된 개발자 및 사용자의 동의를 필요로 한다.  

### 분석도구의 미비

요구사항 명세서가 논리적으로 요구사항을 잘 반영하였는지 평가하는 것은 쉬운 일이 아니다. 즉, 추상적인 단계인 분석과정의 결과물을 평가한다는 것은 어려운일이다. 개발 전 CASE 도구를 이용하여 요구사항 명세서를 시뮬레이션하여 검증하는 것은 프로젝트 초기에 오류를 잡안래 수 있도록 도움을 준다.  

### 문서화의 어려움

문서화는 업무지식에 대한 기록보관과 노하우의 손실을 막기위해 필요하다. 시스템이 커지면 커질수록 분석은 더욱 복잡해진다. 이때의 분석의 복잡도를 해결하기 위해 사용하는 효과적인 방법은 **분할하여 정복**하는 것이다.

### 정치적인 문제

분석은 정치적인 문제에 속하며, 이를 피할 수 없는 경우도 많다. 또한, 분석에서의 정치는 필요악으로 구분된다.  

요구사항 분석시 방법론을 도입하여 접근하면 분석과정을 더욱 체계적이고 공식적인 과정으로 만들 수 있으며 정치적인 영향력을 최소화할 수 있다. 이러한 정치적인 영향력이 기술을 압도하여 혼란을 주면 안된다.

### 일 할당 문제

시스템의 규모가 커지면 여러 명의 분석가가 일을 분할하여 진행한다. 일의 분할은 분야별로 나눠 하는 것이 이상적이며 분석의 초기 단계에 정확한 분할이 일워지지 않으면 분석을 진행하며 추후에 일을 분할하는 것은 더욱 어렵다. 그리고 일의 진행 중간에 인력을 더 투입하면 개발 기간이 더 소요될 가능성이 높다.

### 공식 기술 검토회

시스템 개발에 있어서도 한 개인의 결정보다는 참여자들의 지혜를 모아 최선의 길을 선택하는 것이 바람직하다. 여러 사람들이 의견을 제시할 수 있는 기회가 부여되어야 하고 공정 과정의 산출물에 대한 **공식적인 검토과정**이 필요하다. 특히, 개발 이전에 이루어지는 요구사항 명세서에 대한 공식적인 평가는 필수적이다.  

요구사항 명세서에 대한 **공식기술검토회**에는 고객, 분석가, 개발자, 시험자 등이 참여하여 결정을 내려야 한다. 공식검토회를 갖기 전 참여자들에게 요구사항 명세서가 배달되어 충분한 사전 검토를 할 수 있도록 하여야 한다. 이후 검토회를 통해 목표에 대한 최종 합의점을 한다. 이러한 합의점이 도달되면 사용자측과 개발팀이 서명한다. 이 후의 수정은 서명한 모든 사람들의 서명이 필요하다.  

## 요구사항 분석 방법의 공통점

- 분석 방법들은 시스템의 계층적이며 구조적인 표현을 가능하게 함
- 분석 방법들은 외부와의 인터페이스는 물론 시스템 내부 구성 요소들 사이의 인터페이스에 대한 세심한 주의 필요
- 분석 방법들은 분석 이후 단계인 설게와 구현단계에 필요로 하는 기본틀 제공
- 정형 명세 언어 외의 어느 분석 방법들은 제약조건이나 검증 기준의 표현에 많은 관심을 두지 않음

- 각 분석 방법들은 다음과 같은 공통적인 특성에 의하여 평가될 수 있다.

    1. 정보 영역 분석을 위한 메카니즘
    2. 기능과 동작을 표현하는 방법
    3. 인터페이스에 대한 정의
    4. 문제의 분할을 위한 방법
    5. 추상화 지원
    6. 본질적인 면(what)과 구현 관점(how to)의 표현

## 정보 수집 및 사용자와의 대화 방법

고객의 현재 가지고 있는 문제점이 무엇인지 볼 수 있어야 하며 고객이 원하는 시스템이 어떤 것인가를 파악하여야 한다. 이를 위해 고객과 대화하여 그들의 정보를 뽑아내야하고 이를 모아 통합할 수 있어야 한다. 이때의 고객과의 직접적인 대화는 인터뷰를 통하여 이뤄진다. 또한 고객과 직접 대화할 수 없을 때 **질문사항**을 만들어 우편이나 인터넷 등의 통신망으로 보내거나 **설문지**를 전달하여 간접적으로 정보를 모으는 방법도 있다.

## 사용자와의 관계

- 사용자와의 관계는 어렵지만 중요
- 사용자의 참여를 개발 초기에 증가시키고, 사용자와 개발자 사이의 문제점과 분쟁을 최소화시킬 수 있는 방법들
    1. 사용자와 개발자가 회의를 하면 회의록을 작성하여 서로 서명하는 것이 바람직
    2. 시제품을 빨리 만들어 사용자에게 보여줘야함
    3. 고객과의 대화 도구를 확립하여 사용자에게 요구사항 분석이나 설계기법에서 사용하는 모델링 기법을 설명하여 주고 이를 공통의 대화 언어로 사용
    4. 주고객이 누구인지 찾기
    5. 시스템을 블랙바스로 봐라. 사용자가 무엇을 얻을 것인가를 확립한 후, 이를 실현시키기 위해 시스템의 내부에 대한 분석이 이뤄져야한다.
    6. 고객과의 좋은 인간관계를 유지

## 모델링

- 모델링 : 개발대상 시스템의 성능분석이나 동작과정 등을 알아보기 위하여 간단한 물리적 모형, 도해를 만들거나 또는 그 시스템의 특징을 수학적으로 표현하는 과정. 즉, 어떤 것을 만들기 전에 그것을 이해하기 위한 목적으로 **추상화**하는 작업

- 모델 : 우리의 관심 분야에 맞추어 실세계의 존재를 의도적으로 불완전하게 표현한 추상적인 것  

모델링의 결과는 우리의 관심 분야가 아니거나 필수적이 아닌 세부적인 것은 생략하기 때문에 다루기가 쉽고 필수적인 것만을 표현해준다.  

### 추상화 작업

추상화의 결과는 항상 불완전하고 부정확하지만 그것이 추상화의 필요성과 유용성을 감소시키지는 않는다. 왜냐하면 좋은 모델은 어떤 문제의 중요한 핵심만을 포함하고 나머지 것들을 생략하기 때문이다.  

### 모델의 활용

- 용도에 따라 실제의 모습을 여러가지로 나타냄
- 모델은 단순하고 이해하기 쉬워야 하며 모호성이 없어야 함
- 모델링의 결과는 요구사항 명세서의 핵심 부분이 되며 프로젝트의 다음 단계로 옮겨가는데 필요한 정보 제공
- 모델링은 도표를 사용하여 시스템을 논리적으로 분할할 수 있게 해줌
- 모델링의 결과는 사용자와 개발자 사이의 **대화의 도구**로 사용
- 프로젝트의 초기 단계에서 필요한 요구사항을 뽑아내는 데 많은 도움을 줌
- 개발 단계(설계, 구현, 시험 포함)에 필요한 시스템의 윤곽과 골격 제공

### 모델링의 기본 요소

- 표현(Representation) : 텍스트가 아닌 시각적 표현(도표)

- 규약(Convention) : 시각적인 표현에 대한 설명

- 상술(Specification) : 
    - 시각적인 표현을 텍스트로 확증하는 과정으로 모델링 과정에서 나타난 **도표의 구체적인 정의**
    - 이 구체적인 설명은 모델의 일부분
    - 상술된 자료는 미니 명세서, 자료사전 등에 저장하여 관리

## 소프트웨어 시스템의 3가지 관점

한 모델은 한 관점을 정확히 표현하여 유용하게 사용되면 족하며 한 모델을 통해 여러 관점을 나타내기는 어렵다. 시스템은 바라보는 **관점**에 따라 모습이 달라지고 용도도 달라진다. 어느 한 관점도 완벽하게 나타내지는 못하지만 각 관점은 그를 나타내는 중요한 핵심을 포함하기 때문에 각 관점의 필요성과 유용성을 감소시키지 않는다.

- 기능 관점 : 기능 모델링
- 동적 관점 : 동적 모델링
- 정보(객체) 관점 : 정보(객체) 모델링

### 기능 관점

- 기능 모델은 시스템이 어떠한 **기능**을 수행하는가의 관점에서 시스템 기술
- 데이터에 대하여 수행되는 계산에 초점
- 시스템의 계산에 관한 논리와 현상을 보여주지만 계산이 일어나는 순서와 데이터 생성, 도착 순서 등에 대해서는 기술하지 않음
- 자료흐름도 : 데이터에 수행되는 계산에 근거하여 시스템을 쪼개나간다. 구성요소는 프로세스와 자료 흐름
- 기능 모델링에 사용되는 대표적인 분석기법을 **구조적 분석**이라 하며 자료흐름도와 자료사전에 의해 그 결과를 나타냄
- 구조적 분석기법 : 정보의 흐름과 정보의 변환을 나타내는 방법으로, 요구사항 분석 도구로 가장 많이 사용

### 동적 관점

- 시스템에 변화에 따른 시스템의 동작에 제어에 초점을 맞춰 시스템의 상태와 상태를 변하게 하는 원인들을 묘사
- 시스템의 시간과 변화에 대한 것을 포함함
- 시스템은 시간의 변화에 따라 한 상태에서 다른 상태로 변화게 되므로 이러한 변화는 동적인 면을 가지게 되고, 그로 인한 모델을 **동적 모델**이라 부름
- 동적 모델링의 주요 구성 요소는 상태와 사건으로, 많이 사용되는 동적 모델링 도구는 상태변화도와 사건추적도 외에는 State Chart, SDL(Specification and Description Language), 페트리네트 등
- 외부와의 상호작용이 많은 실시간 시스템들은 동적 관점에서 시스템이 기술되어야 함

### 정보 관점

- 정보 모델은 시스템에 필요한 정보를 보여줌으로써 시스템의 정적인 정보 구조를 포착하는 데 사용
- 시스템에 사용되는 정보 객체를 찾아내고, 이들 객체의 특성, 객체들 사이의 관계와 연관성을 규명
- 정보 모델은 다른 두 관점보다 실세계를 정확히 묘사할 수 있는 장점 보유
- 정보 모델에 나타나는 객체들은 다른 모델에서 나타나는 결과와는 달리, 변하지 않고 안정감이 있어 시스템 개발에 있어 튼튼한 기초 제공
- 정보 모델은 시스템의 기능이나 동적인 면을 고려하지 않고 오직 정적인 것에만 초점을 맞춤
- 특히 시스템의 데이터베이스를 분석하는 데 많이 사용 (ER 모델, EER 모델)
- **객체지향 시스템 개발 방법론**도 정보 모델링을 기초로 하여 시스템을 분석하고 개발하는 접근 방법
- 객체지향 모델은 객체의 정적인 정보에 객체의 동적인 면과 기능 관점을 추가하여 완벽한 객체를 구현하는 게 그 목적

### 세 관점의 통합

세 가지 모델은 시스템의 각기 다른 면을 나타내며 어느 하나도 시스템 전체를 완벽히 설명하지 못한다. 따라서 세 가지 관점을 모아지고 통합되어야 시스템의 요구사항이 완벽히 표현될 수 있다.  

개발하는 응용 분야에 따라서는 한 관점이 시스템의 필요한 모든 모습을 거의 다 설명하여줄 수도 있을 것이며, 이런 경우 다른 관점은 간략하게 묘사되거나 생략될 수 있다.  

ex)
- 컴파일러 시스템 : 기능 모델링
- 데이터베이스 시스템 : 정보 모델링
- 통신 시스템 : 동적 관점과 기능 관점에서의 모델링

## 요약

- 요구사항 분석은 시스템의 목표를 확립하는 과정이며 개발에 들어가기전 문제에 대한 연구를 하는 것
- 목표가 정확해야 프로젝트가 성공적으로 이뤄질 수 있으며 목표는 구체적이어야 함
- 요구사항 분석의 결과물인 요구샇아 명세서는 사용자와 개발자 모두에게 공통의 목표를 제시하는 것
- 요구사항 명세서는 시스템 개발 전과정에 걸쳐 기준이 되는 중요한 문서
- 요구사항을 완벽하게 이해하는 것은 소프트웨어 개발이 성공적으로 되기 위한 필수조건
- 요구사항 명세서는 사용자와 개발자 모두에게 대화의 도구로서 사용되며 설계 및 프로그래밍 단계에서 필요로 하는 중요한 정보를 포함하고 시스템의 윤곽과 골격을 제공

---

# 기능 모델링

## 기능 관점

- 소프트웨어 시스템은 받아들인 정보를 새로운 정보로 변환시켜 내보내 주는 것
- 구조적 분석기법 : 시스템을 기능 관점에서 바라보고 시스템에서 요구되는 정보의 흐름과 정보의 변환을 나타내 주는 대표적인 기능 모델으로, 현재 요구사항 분석에서 가장 많이 활용되고 있는 기법

## 구조적 분석기법

구조적 분석기법의 뿌리는 구조적 프로그래밍으로, 안정감 있는 시스템을 만들기 위해 설계의 원칙들을 필요로 했다. 이 부분을 해결한 것이 **구조적 설계기법**이다.  

하지만 설계의 원칙만 가지고는 시스템의 기능들을 다 표시하지 못하므로 요구사항 분석의 필요성이 대두되어 나타난 기법이 **구조적 분석기법**이다.  

구조적 분석기법에서 시스템은 받아들인 정보를 가공처리하는 하나의 큰 프로세스이며, 이 프로세스는 쪼개져 세부기능을 수행하는 작은 프로세스들로 나눠진다. 즉, 하향식으로 높은 차원의 기능을 작은 단위로 분할한다.

시스템이 반복적으로 분할되는 것을 자료흐름의 상세화라 한다.

### 계층화(leveliing)

**계층화** 또는 **일반화** : 일반화으로 큰 시스템을 상세화하면서 계층적인 배열을 두어 서로의 종속관계를 표시하는 것  

- 하향식 기법인 구조적 분석기법은 표현의 정도를 구분하고 읽기 쉽게 하기 위해서
- 큰 시스템을 분석하기 위해 분할의 개념은 필수적이므로

이러한 이유로 레벨화가 필요하다.  

자료흐름도는 하향식 방식으로 시스템을 분할하여 그림을 통해 나타낸다. 말단 프로세스들의 기능을 설명하는 **프로세스 명세서**, 자료흐름도에 사용되는 데이터의 정의 등을 기록하여 놓는 **자료사전**으로 구성된다.  

## 자료흐름도 (Data Flow Diagram)

자료흐름도 : 정보가 입력되어 적용되는 변화와 그 결과를 그림으로 묘사해주는 도식적 기법  

다음의 4가지 기호를 사용하여 표기

![image](https://user-images.githubusercontent.com/59367782/95723324-fd18c080-0caf-11eb-8c9e-d86e8c7b1902.png)

- 외부객체 : 시스템의 외부에서 시스템과 정보를 주고 받는 사용자 등의 외부객체
- 프로세스 : 시스템 안에서 정보를 처리하고 변환시키는 변환기이며 버블이라고도 부름
- 데이터 항목 : 정보의 흐름을 표시하는 자료항목 또는 데이터 단위이며 화살표는 데이터의 흐름을 표시
- 자료 저장소 : 오랫동안 보관되는 데이터를 저장하여 놓는 파일이나 데이터베이스 시스템

### 프로세스의 분할

프로세스들은 세부적으로 묘사하기 위해 분할될 수 있다. 한 프로세스를 루트로 하는 트리 구조로, 세부적으로 표시할 수 있다. 배경도나 중간 과정의 프로세스들은 모두 쪼개지지 않는 원시 프로세스들로 대체 될 수 있다.  

## 배경도

배경도 : 최상위의 하나로 된 프로세스를 그린 그림. 이는 시스템이 분할되기 전의 프로세스이다.  

배경도는 우리가 개발해야 할 시스템의 영역을 기술하고, 시스템과 외부 환경과의 경계를 결정, 외부와의 인터페이스를 제시하여 시스템의 입출력 데이터를 보여준다. 따라서 시스템과 외부 환경과의 인터페이스에 초점을 맞춘다.

배경도가 완성되어 사용자가 얻는 것을 확립한 후, 실현하기 위해 시스템의 내부에 대한 분석이 이뤄져야한다.  

배경도는 데이터와 시스템이 반응해야 하는 행위, 사건 등에서 시스템과 외부 객체사이에 오가는 정보를 추출하여 만들어지며, 시스템의 외부에서 바라본 시스템의 모습을 기술

### 자료흐름도 프로세스 번호

각 프로세스와 프로세스를 구체적으로 묘사하는 자료흐름도는 번호를 갖게되며, 각 자료흐름도는 상위 레벨의 부모 자료흐름도와 연관된 프로세스로부터 번호를 부여받는다.  

배경도의 프로세스는 최상위 프로세스로 번호 0을 갖으며, **분할되어 자료흐름도로 표시**된다. 이때 이 자료흐름도는 0의 번호가 붙는다.  

각 **프로세스의 번호**는 그 프로세스를 분할하여 표시하는 **자료흐름도의 번호**와 일치한다. 따라서 배경도의 프로세스 0은 프로세스 1, 2, 3, 4를 자녀 프로세스로 갖고, 반대로 프로세스 0은 프로세스 1, 2, 3, 4의 부모 프로세스이다.  

### 원시 프로세스

원시 프로세스 : 
- 프로세스들 중 더 이상 그 아래로 쪼개지지 않는 하위 프로세스이다.
- 상세한 설명은 **미니 명세서(프로세스 명세서)** 에 기록한다. 따라서 프로세스에 미니 명세서가 있다면 해당 프로세스가 원시 프로세스라는 것을 의미한다.  
- 미니 명세서의 번호는 그 프로세스의 번호와 동일. 따라서 미니 명세서의 수는 원시 프로세스의 개수와 일치

일반적으로 하나의 프로세스가 하나의 기능을 수행할 정도로 충분히 작게 쪼개는 것이 이상적이다. 또한 미니 명세서의 크기는 한 페이지에 요약될 정도가 적당하다.  

### 자료흐름도의 균형

자료흐름도의 균형 : 부모 자료흐름도의 정보 입출력은 자녀 자료흐름도의 입출력과 같아야함. 이는 정보흐름의 연속성을 유지하기 위해 필요하다.  

상위 레벨에서 많은 데이터를 묶어 하나로 표시하고 하위 레벨로 내려가면서 쪼개어 표시하는 것은 읽기 쉽다는 장점이 있다.  

균형에 대한 정보는 자료사전에 정의하여 놓는다.  

### 자료사전

자료사전 : 
- 자료흐름도에 나타난 데이터에 관한 정보(시각적인 정보)를 한 곳에 모아 놓음으로써 개발자나 사용자들이 편리하게 사용할 수 있게 해 준다.

- 메타데이터. 즉 데이터에 대한 데이터를 모아 놓는 저장소이며, 데이터 항목, 데이터 흐름 등에 관한 정의가 포함되어 있다.

### 구조적 분석기법과 기능 분할

시스템의 중요 요소나 기능을 찾아내어 분할 해나가는 것은 분석가의 임무이며 쉬운 일이 아니며, 완벽한 가이드라인이 없다. 따라서 구조적 분석기법은 이들 기능을 분할하는 일반적인 방법을 제시하여 준다.  

- 사건 분할 방식 : 모던 구조적 분석기법 제안

여기서는 Use Case[JAC92]를 적용하여 분석한다.

### 분할

분석 : 
- 문제를 **쪼개서 정복**하는 과정
- 어떤 것을 그 기본요소들로 분해하는 것과 관련되어 있고 그에 요구되는 개념이 **세분화** 또는 **분할**

세분화, 분할 :
- 우리의 지식을 체계적으로 정돈하기 위해 필요하며 추상화와 공통적 특성을 이용하여 더 작고 단순한 것들로 나눔
- 분할에 정도는 없으며 분할되어 나타나는 프로세스나 객체들을 쉽게 찾아낼 수 있는 간단한 해결 방법은 없다.
- 기존의 분할에 사용할 수 있는 정보가 있는 경우 이를 활용할 수도 있다.

일반적으로 시스템 분할에서 추구하는 중요한 목표는 요소들이 **독립성**을 가지며 요수 내부의 결합도가 높고 외부와의 결합은 최소화 되도록 시스템을 설계하는 것이다.

## 문제설명서

- 일반적으로 프로젝트 계획학허나 계약할 시기에 추상적인 시스템의 목적만을 나열한 **문제설명서** 또는 **제안서**로 일이 시작되는 경우가 많음
- 문제기술은 고객의 관점에서 고객이 사용하는 용어로 기술
- 문제기술에 모든 구체적인 요구사항이 정의되기는 어령무
- **제안서**(proposal)와 **제안요청서**(RFP: request for proposal)

### 문제 기술의 내용

- 해결하려는 문제점에 대해 명확환 기술해야 한다. 현재의 상황, 배경, 시스템 개발의 필요성, 문제 제약 조건, 달성하려는 목표에 대한 기술이 포함
- 자동화하는 데 요구되는 추진전략 및 방법을 기술한다. 적용하고자 하는 개발 방법론 및 접근 방법 등이 구체적으로 기술
- 제공되어야 할 기능, 만들어질 시스템의 제약 조건, 요구되는 하드웨어, 연관된 소프트웨어, 일의 범위 등을 기술
- 시스템 차원의 목표, 개발 과정에서 요구되는 사항, 결과물 등이 기술
- 추상적인 차원에서 합격 판정 검증 기준을 확립하여 기술
- 시스템이 개발되었을 때 예상되는 기대 효과 및 활용 방안을 기술

### 제안서의 양식

1. 연구개발의 필요성
    - 국내외 기술 개발 현황
    - 연구개발하려는 기술의 수준
    - 문제점
    - 앞으로의 전망
    - 연구개발의 중요성
2. 연구개발목표
3. 연구개발 내용 및 범위
4. 연구 결과물
5. 추진전략 및 방법
6. 지금까지의 연구개발 실적
7. 기대성과 및 활용방안
8. 인원 편성표
9. 연구개발 기자재 현황
10. 연구추진일정 계획
11. 소요예산명세
12. 참고 문헌

### 문제기술의 한계

문제기술은 프로젝트 계획단계에서 쓰인다. 따라서 문제기술은 문제를 이해하기 위한 출발점이며 완벽한 문서일 수 없다. 일반적으로 완벽하거나 구체적이지 못하며 이를 사용해 시스템을 검증하는 일은 쉽지 않다.  

계획이 끝나거나 계약이 이뤄진 후 구체적인 요구사항을 분석하여 요구사항 명세서를 만든다.

### Use Case를 이용한 구조적 분석기법

1. 문제기술 준비
2. 시스템을 사용하는 행위자가 누구인지 규명한다. 이 때 시스템의 주 고객인 주행위자와 시스템이 사용되도록 지원하여 주는 부행위자 규명
3. 각 행위자에 대하여 use case를 찾아내고 목록을 만든다. 이때 정보를 만들거나 사용하는 use case만 고려
4. 각 use case에 대하여 기본적인 활동만 구체적으로 기술
5. 각 use case에 대하여 예외적인 경우와 선택적인 경우를 찾아내어 구체적으로 기술한다. 이 경우 기본적인 활동과 상당히 다른 경우만을 조사

## 요약

- 구조적 분석기법은 정보의 흐름과 정보의 변환을 그래프로 나타내주는 기능 모델
- 구조적 분석기법은 시스템과 외부와의 정보흐름에서 시작하여 하향식으로 시스템의 기능을 분할
- 구조적 분석기법에서 나온 결과는 다음 단계인 설계 단계에서 필요로 하는 시스템의 골격을 제공
- 자료흐름도의 프로세스는 분석의 결과이며 프로그램의 모듈과는 다르다.
- 자료흐름도의 각 프로세스는 설계에서 필요로 하는 모듈로 변환될 가능성이 높으며 이 경우 각 정보흐름은 모듈들 사이의 매개 변수로 나타난다.
- 구조적 설계는 응용분야의 관점에서 컴퓨터 관점으로 이동하여 구조적 분서의 결과에 살을 붙여가는 과정

---

- 13日

# C Programming on Linux

## Vi

### 라인 복사 및 삭제

- 모든 명령어는 insert mode 에서 esc 키를 눌러 일반 모드로 나온 후, 수행
- 라인 복사 명령 : yy
    - 앞에 숫자를 입력하면, 현재 커서가 위치한 라인을 포함한
아래의 다수 라인을 한번에 “레지스터”로 복사함
- 라인 삭제 명령 : dd
    - 앞에 숫자를 입력하면, 현재 커서가 위치한 라인을 포함한
아래의 다수 라인을 한번에 “레지스터” 로 복사하고, 제거함
- 레지스터의 붙여넣기 : p
    - 현재 커서가 있는 곳에서부터 레지스터의 내용을 삽입함
- VI Register
    - VI에서 복사한 내용이 임시로 보관되는 공간.
    - VI 프로그램 간에 공유됨.
        - 따라서 VI가 종료되어도, 다시 VI를 수행하면 레지스터의 내용을 이용할 수 있음
        - 이 기능은 한 파일의 내용을 복사해서 다른 파일에 붙여넣을 때 유용함

### 라인 이동 및 관련 명령

- 라인 이동
    - 사용법 1: “:” 입력 후, 이동할 라인 숫자 입력
    - 사용법 2: 라인 숫자를 입력하고 Shift + g
- 관련 명령
    - 라인의 맨 앞으로 이동하기: 0 (숫자 영)
    - 맨 위로 이동하기: gg
    - 맨 밑으로 이동하기: “:$” or “(입력없이) shift + g”
    - 줄 번호 표시 하기 : “: set number”

### 문자열 찾기 / 바꾸기

- 문자열 찾기
    - “/”를 입력하고 찾을 문자열 입력
    - Enter 입력 후, 다음 단어, 이전 단어 검색
        - 소문자 n: 다음 단어
        - 대문자 N: 이전 단어
    - 이전에 찾아본 문자열 불러오기
        - “/”를 입력한 상태에서 위 아래 화살표 사용
- 문자열 바꾸기
    - :[범위]s/찾을문자열/바꿀문자열/[option]
    - 범위: comma 를 이용해 범위 표현. % 는 전체 영역
        - 예) 1,10: 첫 번째부터 10번째 라인 내에서 수행.
    - 찾을 문자열에는 정규 표현식 사용 가능 (regular expression 으로 검색)
    - Options
        - g: 범위 내에서 바꾸기 수행
        - c: 한 항목씩 물어보면서 수행
        - i: 대소문자 무시
    - 예) :%s/Protocol/protocol/gc

### 기타

- Undo/Redo (취소하기, 되돌리기)
    - u: undo
    - ^r: Redo (CTRL + r)
- 세로 및 가로 블록 선택, 편집
    - ^v: Visual block mode (CTRL + v)
    - 모드 진입 후, 화살표로 선택 후, 편집 명령
    - 예) 여러 라인에 있는 주석을 한번에 제거
        - 세로 모드로 여러 주석 문자를 선택 후 delete
    - 예) 여러 라인에 주석 한번에 넣기
        - 세로 모드로 영역 선택 후, shift + i 로 입력 모드 진입
        - 텍스트 입력 후, esc 를 두 번 누름
- Read-only 파일의 저장
    - :w 혹은 :wq 뒤에 ! 를 붙임 (force)
- 외부 텍스트 붙여넣기 모드
    - :set paste

## nano

- nano - Nano's ANOther editor, inspired by Pico
    - 전통적으로 메일 클라이언트에서 사용하던 Pico 라는 편집기를 기반으로,
    - Vi와 같이 여러 리눅스 배포판에서 기본 프로그램으로 사용함
    - Vi와 비교: “사용하기 쉽다.”
        - 대부분 단축키가 아래에 나열되어 있어 모르는 기능도 빠르게 활용할 수 있다.
        - “검색하여 교체하기” (replace) 기능이 보다 편리하게 사용 가능 하다.
        - 자동 들여쓰기 기능이 더 편리하다.
- Comments
    - Vi, nano 모두 기본 에디터이므로 간단한 사용 방법은 익혀두는 것이 좋다.
    - Vi, nano 모두 간단한 편집 기능은 큰 차이 없으므로, 익숙한 도구를 쓰면 된다.
    - 초심자가 처음 배운다면?
        - Nano: 접근성이 높다
        - Vi: 처음 배울 때 어려울 수 있지만, 보다 다양하고 강력한 기능들을 제공한다.
    - (!) 결국 다양하고 많은 편집을 필요로 할 때는 윈도우 환경이 훨씬 편리함.
        - 실제 파일은 리눅스에, 편집은 윈도우(or Mac)에서 수행하는 환경을 구축하는 것이 일반적

## GCC: GNU Compiler Collection

- GNU
    - 유닉스 환경에서 필수적인 다양한 시스템 소프트웨어를 공개 SW 형태로 제작, 배포하는 그룹
    - 1983년 부터 활동하며 다수의 SW를 배포하였고, 대다수 SW가 유닉스 환경에서 de facto standard 로 활용되고 있음
        - De facto standard: 사실상의 표준. 관습, 관례, 제품이나 체계가 시장이나 일반 대중에게 독점적 지위를 가진 것
    - GNU 패키지 목록
        - 일상적으로 사용하는 다양한 명령어들이 포함되어 있음 (bash, grep, gzip, tar, …)

- GCC: GNU Compiler Collection
    - GNU SW 중 가장 유명한 SW의 하나로, 다양한 Architecture (CPU) 환경에서 다양한 언어를 지원함
    - C, C++, Objective-C, Fortran, Ada, Go, and D
    - 위 언어를 위한 라이브러리도 포함
    - 상용 컴파일러와 비교해 성능이 낮다는 인식이 있었으나, 최근에는 많은 상용 레벨 SW를 위한 컴파일러로 널리 활용하고 있음
        - Linux, MySQL, Apache 등등
    - https://gcc.gnu.org/
    - Git repository: official, github
    - 설치 방법 (j-cloud 인스턴스에서는 수행할 필요 없음)
        - 패키지 업데이트 후, SW 빌드를 위한 필수 패키지 설치. 개발을 위한 manpage 추가
        - $ sudo apt update && sudo apt install    build-essential
        - $ sudo apt-get install manpages-dev

### 컴파일 환경

- 컴파일이란
    - 텍스트로 작성한 프로그램을 시스템이 이해할 수 있는 기계어로 변환하는 과정
    - 보통 컴파일 과정과 라이브러리 링크 과정을 묶어서 수행하는 것을 의미

### 사용 방법

- $ gcc <source file>
    - Output: 컴파일 성공 시, “a.out” executable file (실행 파일) 생성
- Options
    - “-o” : 생성된 실행 파일의 이름을 지정
    - “-Wall” : 모든 레벨의 warning messages 출력
    - “-O” : optimization 수행. “-O1”, “-O2”, “-O3” 와 같이 최적화 레벨을 지정할 수 있음
        - https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
    - “-l” : (소문자 L) 라이브러리 링크. Math, pthread 와 같이 명시적 링크가 필요한 경우
        - 적절한 library 를 –l 옵션을 이용해 링크해주어야 함
            - 예) math (-lm) , pthread (-lpthread)

```
$ gcc test.c
$ ls
a.out test.c
```
기본 실행파일명은 a.out

```
$ gcc -o test test.c
$ ls
test test.c
```
실행파일명 지정은 -o 옵션

## Standard Input and Output

### stdout and stderr

- fprintf()
    - printf() 와 유사하게 형식이 지정된 문자열 (formatted string)을 출력하되,
    - 맨 앞의 인자로 출력 방향을 지정할 수 있음
        - printf()는 fprintf()의 simple version. 실제로 fprintf(stdout, …) 으로 구현됨

### stdin

- Pipe 를 이용한 stdin 입력
    - Scanf()는 본래 stdin 으로 부터 입력을 받는 함수
    - Stdin 은 기본으로 console 을 통한 키보드 입력으로 연결되어 있음
    - Pipe를 이용해 cat 의 수행 결과를 stdin 으로 입력받은 것
- Stdin, stdout, stderr 의 redirection 을 이용해,
여러 프로그램 간의 편리한 연동이 가능함

## 명령행 인자

- 명령행 : 사용자가 명령을 입력하는 행 (command line)
- 명령행 인자 : 명령을 입력할 때 함께 지정한 인자(옵션, 옵션인자, 매개변수 등)
    - 명령행 인자는 main 함수로 전달됨.
    - Main 함수의 첫 번째 인자: 인자의 개수 (보통 int argc 로 선언함. Argument count)
    - Main 함수의 두 번째 인자: 문자열로 된 인자들이 저장된 포인터 배열
        - 보통 char *argv[] 또는 char **argv 로 선언함. Argument vector
        - 명령어는 항상 첫 번째 인자
        
예) `int main(int argc, char *argv[])`

- 포인터 배열?
    - 다양한 길이의 문자열이 임의의 개수만큼 저장되는 경우,
    - 포인터 배열로 다루는 것이 적합함

---

# AWS Storage Services 1: EBS, EFS

| 요구 사항: | 추천 제품: | 
|---|---|
|Amazon EC2, 관계형 및 NoSQL 데이터베이스, 데이터 웨어하우징, 엔터프라이즈 애플리케이션, 빅 데이터 처리 또는 백업 및 복구를 위한 영구 로컬 스토리지|Amazon elastic Block Store(Amazon EBS)|
|Linux 기반의 워크로드를 AWS 클라우드 서비스와 온프레미스 리소스에서 사용할 수 있도록 지원하는 간단하고 확장 가능하며 탄력적인 파일 시스템입니다. 이 제품은 애플리케이션을 중단하지 않고 온디맨드 방식으로 페타바이트 규모까지 확장하도록 구축되어 파일을 추가하고 제거할 때 자동으로 확장되고 축소되므로, 애플리케이션은 필요할 때 필요한 만큼 스토리지를 사용할 수 있습니다.|Amazon ElasticFile System(Amazon EFS)|
|사용자 생성 콘텐츠, 활성 아카이브, 서버리스 컴퓨팅, 빅 데이터 스토리지 또는 백업 및 복구를 위해 인터넷 위치에서 데이터에 액세스할 수 있도록 지원하는 확장 가능하고 안정적인 플랫폼입니다.|Amazon Simple Storage Service(Amazon S3)|
|아카이브 및 규제 준수를 위해 테이프를 대체할 수 있는 매우 저렴한 장기 스토리지 클래스| Amazon Glacier 및 Amazon S3 Glacier Deep Archive|
|고성능 컴퓨팅, 기계 학습 및 미디어 데이터 처리 워크플로우와 같이 컴퓨팅 집약적 워크로드에 최적화된 완전관리형 파일 시스템으로, Amazon S3에 완벽하게 통합되어 있습니다.|Amazon FSx for Lustre|
|Windows Server를 기반으로 구축된 완전관리형 네이티브 Microsoft Windows 파일 시스템으로, 이 제품을 사용하면 SMB 프로토콜 및 Windows NTFS, AD(ActiveDirectory) 통합, DFS(분산 파일 시스템)에 대한 전체 지원을 비롯하여, 파일 스토리지가 필요한 Windows 기반 애플리케이션을 AWS로 쉽게 이전할 수 있습니다. |Amazon FSx for Windows File Server|
|버스팅, 계층화 또는 마이그레이션을 위해 Amazon 클라우드 스토리지로 온프레미스 환경을 보강해주는 하이브리드 스토리지 클라우드입니다.| AWS Storage Gateway|
|유형 및 크기에 상관없이 모든 데이터를 AWS 클라우드로, 혹은 AWS 클라우드에서 이동하는 작업을 간소화 및 가속화할 수 있도록 지원하는 서비스 포트폴리오입니다.| 클라우드 데이터 마이그레이션 서비스|
|클라우드뿐 아니라 온프레미스에서도 AWS Storage Gateway를 사용해 AWS 서비스 전체에서 데이터 백업을 손쉽게 중앙화하고 자동화할 수 있는 완전관리형 백업 서비스입니다.|AWS Backup|


![image](https://user-images.githubusercontent.com/59367782/95824899-0adf4c00-0d6b-11eb-8136-7dcbe70d52ce.png)  

## EBS와 EFS

- EBS (Elastic Block Storage)
    - Amazon EC2 인스턴스에 연결된 영구 볼륨에 블록 데이터를 저장하고 이를 처리
    - 일반 HDD, SSD와 같은 블록 기반의 입출력을 지원하는 스토리지
    - EC2 VM의 OS, 데이터를 저장하기 위한 저장장치로 사용됨
    - 연간 고장률 AFR: 0.1%~0.2% (일반 HDD: 4%)
- EFS (Elastic File System)
    - 간편하고 확장 가능한 파일 시스템에 데이터를 저장 및 공유
    - Ext4, NTFS와 같이 파일 시스템 access semantics 에 따른 FS 인터페이스를 제공하는 서비스
    - 자체 고가용성, 내구성을 제공하도록 설계
    - 용량 자동 확장 및 축소

### EBS Pricing

- Amazon EBS 범용 SSD(gp2) 볼륨
    - $0.114 프로비저닝된 스토리지의 월별 GB당
    - 예) 30GB 한달 쓰면? $3.342 = 약 4천원
- Amazon EBS 프로비저닝된 IOPS SSD(io1) 볼륨
    - $0.128 프로비저닝된 스토리지의 월별 GB당
    - $0.067 프로비저닝된 월별 IOPS당
- Amazon EBS 처리량 최적화 HDD(st1) 볼륨
    - $0.051 프로비저닝된 스토리지의 월별 GB당
- Amazon EBS 콜드 HDD(sc1) 볼륨
    - $0.029 프로비저닝된 스토리지의 월별 GB당
- Amazon S3에 대한 Amazon EBS 스냅샷
    - $0.05 저장된 데이터의 월별 GB당

### EFS Pricing

- 표준 스토리지
    - $0.33 월별 GB당
- Infrequent Access 스토리지
    - $0.0272 월별 GB당
    - $0.011 전송량 기준
- 프로비저닝된 처리량 유형
    - $6.60 월별 MB/s
    
- 예) 30GB 한달: $9.9 (약 12,000원)
- EBS보다 약 3배 가량 비쌈.
    - EFS는 보다 고급의 기능을 제공하기 때문
    - IA는 약 1/12 수준 (다만 계층 간 전송에 대해 요금 부과) 

![image](https://user-images.githubusercontent.com/59367782/95834620-2866e280-0d78-11eb-9907-ba964f192c3c.png)

## Block storage and File system

- Block storage
    - 512B 단위로 분할된, (sector)
    - 0부터 시작하는 선형 주소 공간 (linear address space)에,
    - 데이터를 읽거나 쓸 수 있는 스토리지 장치
- File system
    - 하나의 파일 시스템 내에서 각기 unique name 을 갖는,
    - File 이라는 독립적인 개체에,
    - 1B 단위로 분할된,
    - 0부터 시작하는 선형 주소 공간 (linear address space)에,
    - 데이터를 읽거나 쓸 수 있는 스토리지 시스템
    - 일반적으로 블록 스토리지 장치의 상단에 위치함
        - 실제 데이터는 블록 스토리지에 저장됨

![image](https://user-images.githubusercontent.com/59367782/95825908-85f53200-0d6c-11eb-8002-2e3bd5ecf047.png)

- Block storage (left)
    - 데이터를 기록하기 위해 블록 스토리지 상의 주소를 직접 사용해야함
- File system (right)
    - 파일 시스템이 제공해주는 파일 이라는 추상적 개체를 이용
    - 모든 데이터는 0부터 시작하는 독립된 주소 공간에 기록할 수 있음
    - 실제 데이터가 기록되는 공간은 블록 스토리지이며,
    - 파일의 주소 공간과 블록 스토리지 주소 공간 사이의 mapping 을 파일 시스템이 관리
        - 이때 이 **매핑 정보** 또한 블록 스토리지에 저장되어야 함

- Block storage 장단점
    - (장점) 중간 계층을 거치지 않으므로 액세스가 빠르다.
    - (단점) 같은 주소 공간을 다수가 공유하므로, 데이터 관리가 어려움
        - 예) A와 B가 동시에 서로 다른 데이터를 0번 주소에 기록하려하면?
- File system 장단점
    - (장점) 파일마다 서로 주소 공간이 분리되어 있기 때문에, 서로 분리되어야 할 데이터를 쉽게 관리할 수 있음
        - 예) 위의 예에서, A와 B는 서로 다른 파일의 주소 공간에 각각 접근하므로 문제가 없음
    - (단점) 성능 저하
        - 파일의 데이터가 실제 블록 스토리지 어느 주소에 위치하는지 변환이 필요 (mapping)
        - 그러나 mapping 정보와 데이터의 메모리 캐싱을 통해 많은 부분 해소됨

## 그외

- S3 (Simple Storage Service)
    - AWS의 가장 기본적인 Object based storage
    - 일반적인 클라우드 스토리지와 동일함 (예. 네이버/다음 클라우드)
    - 내구성: 99.999 999 999% (11-9)
- Glacier (뜻: 빙하)
    - 데이터 보관 및 백업을 위한 안전하고 내구성있는 스토리지
    - 싸고 성능이 느림
    - 연평균 99.999 999 999%의 내구성

- AWS Storage Gateway
    - 사용자가 기존에 사용하던 스토리지 인프라 및 데이터를 포함한, 모든 스토리지 서비스를 AWS 클라우드와 통합할 수 있도록 지원
    - 파일, 볼륨, 테이프 인터페이스 지원
    - NFS, iSCSI 인터페이스 지원

- AWS Backup
    - 완전관리형 백업 서비스
    - 중앙 관리 및 자동화
        - AWS Storage Gateway를 사용해 AWS 서비스 전체에서 데이터 백업을 손쉽게 중앙집중화하고 자동화
        - AWS Backup 콘솔에서 클릭 몇 번이면 백업 일정과 보존 관리를 자동화하는 백업 정책을 생성할 수 있음


---

- 14日

# CleanCode

로버트 C. 마틴 저자의 클린코드를 읽기 시작하였다. 3장 함수까지 읽었는데 느낀 점이 많다. 아직 실무를 해보지 않은 학생으로서 커다란 프로젝트도 해보지 못했다. 그래서 가끔 PS를 하면서 만든 코드를 친구들과 이야기해볼 뿐 프로젝트 코드를 가독성 좋게 타인이 제대로 이해하게 코딩한다고 자신할 수 없다. 아직 많이 읽지는 않았지만 이 정도만 읽고도 책에서 읽은 내용을 하나도 지키지 않고 있어 충격이 컸다.

1장에서 클린 코드의 중요성을 이야기하고, 2장에서는 변수, 함수, 클래스 등 이름을 강조했다. 3장에서는 그 중 함수에 대해서 주로 서술하였다.  

책을 다 읽어보지 않았지만 이 책은 Java로 예시를 들며, 실제로 겪었던 일들을 토대로 글을 서술해간다. 그러한 일들을 나도 겪을 수 있다고 생각하면 이후에 도움이 될 수 있다고 생각된다. 시간이 흘러도 개발자들이 직접 개발하는 한 깔끔하고 가독성있는 코드는 항상 경쟁력을 가질 것이라고 생각한다. 따라서 이 책이 절대적인 규칙을 제공하지는 않지만 나의 코드에 조금이라도 보탬이 될 수 있게 배울 점이 있다고 본다. 다른 공부를 하다가 지치거나 여유있을 때 계속 읽어가면서 느낀 점을 적어볼려한다.  

지금까지 읽은 부분에서는 3장이 제일 기억에 남는다. 핵심 내용은 `함수는 한 가지 기능만 하면 된다` 이다. 이 내용으로 추상화, switch, 예외처리, 반복, 구조적 프로그래밍 등 여러가지를 설명한다. 다양한 내용이 나와도 결국엔 다른 사람들이 함수의 이름만 봐도 함수가 무슨 기능을 하는지 한번에 알고 사용할 수 있도록 만들어야한다는 것이다.  

메인과 분리하거나 재귀, 재사용을 위해서 함수를 만들어 사용하던 나에게는 새로운 이야기가 아닐 수 없다. 이러한 점에서 나는 아직 배울게 많고 코딩할 때 신경써야하는 점이 많다는 것을 단번에 깨달았다. 하지만 아직까지도 이름을 짓는데는 쉽지 않다. 그러한 예로 깃에 커밋 메시지를 적거나, 변수 이름을 짓기 위해 영어 단어를 생각하는 시간이 상당히 길다. 또한 함수도 같은 맥락이다. 함수의 기능을 한 가지로 축약하기 위해선 이름도 중요하다고 생각되는데, 이 부분이 부족하다.  

책을 읽어나가면서 도움이 되는 부분을 받아들여서 누군가에게 코드를 보여줘도 부끄럽지 않은 개발자가 되도록 노력해야겠다.

---

- 15日

# 2020 공개SW 온라인 체험캠프

오픈소스 소프트웨어 개발 수업을 [2020 공개SW 온라인 체험캠프]에 참여하는 것으로 대체하였다. 해당 캠프에서 공개SW에 대한 정의 등을 설명해주셨는데 연구원의 입장에서의 공개Sw와 실무자의 입장에서의 공개SW로 나뉘어서 받아들여졌다.  

오전에는 그러한 시간을 가지고 오후에는 두 개의 섹션으로 나뉘었는데 Keras와 Javascript 튜토리얼 한글화 두 가지로 나뉘었다. 나는 그 중 github를 활용한 자바스크립트 튜토리얼 한글화을 선택하여 실습을 하게 되었다. 자바스크립트 튜토리얼 한글화하는 프로젝트의 오너분이 오셔서 직접 상세하게 git을 학생입장에서 상세히 설명해주시고 오픈소스 생태계를 직접 이해할 수 있는 시간을 가졌다. 그리고 직접 컨트리뷰션하는 시간을 가졌는데 어렵지 않게 영어로 된 부분을 번역해서 Pull request를 던지고 직접 merge하는 모습도 보여주셨다.  

오늘은 짧으면서도 긴 시간을 캠프 참여하는데 시간을 보냈는데, 이 시간을 통해서 알던 내용도 다시 되짚어보고 실습을 통해서 제대로 Pull Request를 할 수 있게 배워갈 수 있었다. 내일도 이어서 하므로 더 배워갈 수 있었으면 좋겠다.

---

- 16日

# 2020 공개SW 온라인 체험캠프

[Javascript tutorial.ko](https://github.com/javascript-tutorial/ko.javascript.info)에 Pull request를 날려 merge하는 작업,  
[git tutorial](http://try.github.io/) 중 [git branch](https://learngitbranching.js.org/?locale=ko)을 통해서 git branch에 대해서 공부할 수 있었다. 그 중 git branch 명령어 중 git rebase와 git merge에 대해 집중적으로 설명해주었다. branch를 나누고 합치는 과정을 보여주며, 직접 learngitbranching에서 해가면서 배울 수 있었다.  

오후에는 git에 대해 집중적으로 배울 수 있었던 반면에 오전에는 실무에서 필요하거나 앞으로 개발 공부하는데에 있어서 도움이 되는 사이트와 조언들을 해주셨다. 그 중 읽어보고 괜찮았던 사이트는 [프레임워크 공부를 멈춰라](https://medium.com/@jongyoungpark/%ED%94%84%EB%A0%88%EC%9E%84%EC%9B%8C%ED%81%AC-%EA%B3%B5%EB%B6%80%EB%A5%BC-%EB%A9%88%EC%B6%B0%EB%9D%BC-1afa37644474)라는 사이트로, 여러 프레임워크를 공부하기 보다는 본질에 대해 공부를 하는 것이 좋다고 하는 포스팅이였다. 거기서 추천해준 도서가 여러가지 있었는데 그 중 들어본 도서도 있지만 아예 처음 들어보는 도서도 있어서 새로웠다. 전에 쓴 내용처럼 클린 코드를 아직 다 읽지는 못했지만 읽으면서 느낀 점이 매우 많았었다. 따라서 다른 도서 또한 그 만큼 새로운 정보와 알아야하는 부분을 이야기 해줄 것이라 생각이 된다.  

해당 프로그램은 오픈소스 소프트웨어 개발 수업에서 이어진 전북대학교 2020 공개SW 온라인 체험캠프로, 상당히 많은 것을 알 수 있었다. 실무에서 사용하는 내용과 알면 좋은 내용, git에 대해 겉핥기식으로 알던 지식을 조금 더 늘릴 수 있었다.

---

- 17日

# Concurrently

웹을 개발하다보면 서버와 클라이언트를 한 환경에서 실행하는 경우가 있는데 이 때, 터미널 하나당 하나를 구동하게 되면 번거로울 때가 있다. 이 부분을 해결하기 위한 것이 Concurrently이다.  

사용하기 위해선 먼저 설치가 필요하다.

## 설치

```
$ npm install concurrently express --save
```
express를 제해도 상관 없는걸로 보인다.

## 사용법

루트 디렉토리에 들어있는 `package.json`을 수정해주면 된다. 다음과 같은 규칙을 적용하면 사용할 수 있다.

```json
"start" : "concurrently \"command1 arg\" \"command2 arg\" "
```

실제로 직접 프로젝트를 만들 때 사용한 부분을 봐보자. server와 client를 나눠서 유지하고 있었다. 이 때 루트 디렉토리에 server, client로 나뉘어진다. 이전까지는 루트 디렉토리에서 server를 실행하고 client 디렉토리로 접근하여 client를 실행하였다. 그 부분을 다음과 같이 변경하였다.

```json
"scripts": {
    "start": "node ./server/index.js",
    "backend": "nodemon ./server/index.js",
    "dev": "concurrently \"npm run backend\" \"npm run start --prefix client\" "
  }
```

server의 경우 다른 폴더에 있는 것을 상대경로로 명시하여 실행하였고, client의 경우에는 위에서 정의한 start와 겹치므로 `--prefix`를 통해 client 폴더를 정의해주고 해당 폴더에서 실행할 수 있게 마련했다.  

이 외에도 폴더가 다른 경우 상대경로를 이용해 이동한 뒤 `&&` 연산을 둬서 이동한 뒤 해당 명령어를 사용할 수 있게 할 수 있다.  

---

# Redux

Redux is a predictable state container for Javascript apps 즉. 상태 관리 라이브러리다.  

컴포넌트간의 통신을 할 때 여러 다른 컴포넌트를 거쳐서 보내는 것이 아닌 다른 별도의 공간에 두고 그 공간을 통해서 통신하는 개념이다.

## Props vs. State

### Props

1. Properties의 줄임말
2. 컴포넌트간의 통신하는 방식
3. 통신은 부모 컴포넌트에서 자식 컴포넌트 방향으로만
4. 부모 컴포넌트에서 자식 컴포넌트로 넘어간 데이터는 바뀔 수 없다. 바꿀려면 새로 통신 되어야한다.

```js
<ChatMessages
    messages={messages}
    currentMember={member}
/>
```

### State

1. 부모 컴포넌트에서 자식 컴포넌트로 데이터를 보내는 방식이 아닌 컴포넌트 안에서 데이터를 전달하는 방식 (ex: 검색 창에서 글을 입력할 때 글이 변하는 것은 state를 바꾸는 것)
2. State는 변할 수 있다.
3. State가 변한 경우 re-render 된다.

```js
state = {
    message: '',
    attachFile: undefined,
    openMenu: false,
};
```

## Redux Data Flow

strict unidirectional data flow로, 한 방향으로만 흐른다.  

![image](https://user-images.githubusercontent.com/59367782/96329031-0923ca00-1084-11eb-8ce8-6f2266ea2988.png)
(John Ahn님 자료)

### Action

객체 형식으로 일어난 일을 설명

```js
{ type: 'LIKE_ARTICLE', articleID: 42 }
{ type: 'FETCH_USER_SUCCESS', response: { id: 3, name: 'Mary'} }
{ type: 'ADD_TODO', text: 'Read the Redux docs.' }
```

### Reducer

Action으로 인한 State가 변하는 것을 설명

```js
(previousState, action) => nextState
```
-> 이전 State과 action object를 받은 후 next state를 리턴한다.

### Store

애플리케이션의 State를 감싸주는 역할로, 여러 메소드가 존재한다. 이러한 메소드를 통해 State를 관리할 수 있다.

## 설치

1. redux
2. react-redux
3. redux-promise
4. redux-thunk

```
$ npm install redux react-redux redux-promise redux-thunk --save
```

redux-thunk : dispatch에게 Function을 받는 방법을 알려줌  
redux-promise : dispatch에게 Promise가 온 경우 대처할 방법을 알려줌  

```js
import { Provider } from 'react-redux';
import { applyMiddleware, createStore } from 'redux';
import promiseMiddleware from 'redux-promise';
import ReduxThunk from 'redux-thunk';
import Reducer from './_reducers';

const createStoreWithMiddleware = applyMiddleware(promiseMiddleware, ReduxThunk)(createStore);

ReactDOM.render(
  <Provider
    store={createStoreWithMiddleware(Reducer, 
        window.__REDUX_DEVTOOLS_EXTENSION &&
        window.__REDUX_DEVTOOLS_EXTENSION()
      )}
  >

    <App />
  </Provider>
  
  , document.getElementById('root')
);
```

다음과 같이 사용하여서 redux를 설정해준다. 크롬에서 확장프로그램인 Redux Devtools를 다운로드 받고 `window.__REDUX_DEVTOOLS_EXTENSION`을 사용해준다.

---

# React Hooks

## React Component

### Class Component

- Provide more features
- More Code
- More Complex Code
- Slower Performance

```js
import React, { Component } from 'react'

export default class Hello extends Component {
    render() {
        return (
            <div>
                hello world
            </div>
        )
    }
}
```

### Functional Component

- Provide less features
- Less Code
- Simpler Code
- Faster Performance

```js
import React from 'react';

export default function Hello() {
    return (
        <div>
            hello world
        </div>
    )
}
```

![image](https://user-images.githubusercontent.com/59367782/96329768-ddf0a900-108a-11eb-843f-8f16477a8cb4.png)
[출처](https://projects.wojtekmaj.pl/react-lifecycle-methods-diagram/)

1. Constructor에서 State를 초기화
2. Render에서 html dom에 알맞게 배치해줌 (jsx) 
3. ComponentDidMount or Update를 통해 데이터를 가져오거나 설정하는 등 기능을 함

Functional Component에서는 이러한 lifecycle을 모두 사용할 수 없다. 이러한 문제를 해결하기 위해 Hook이 개발되었다.  

Class, Functional Component로 같은 기능을 하는 것을 hook를 사용하는 예를 보자.  

Class Component
```js
import React, { Component } from 'react'
import Axios from 'axios'

export default class Hello extends Component {
    constructor(props) {
        super(props);
        this.state = { name: "" };
    }

    componentDidMount() {
        Axios.get('/api/user/name')
            .then(res => {
                this.setState({ name: res.data.name })
            })
    }

    render() {
        return (
            <div>
                My name is {this.state.name}
            </div>
        )
    }
}
```

Funtional Component
```js
import React, { useEffect, useState } from 'react'
import Axios from 'axios'

export default function Hello() {
    const [Name setName] = useState("") // constructor
    useEffect(() => { // Mount
        Axios.get('/api/user/name)
            .then(res => {
                setName(res.data.name)
            })
    }, [])

    return ( // render
        <div>
            My name is {Name}
        </div>
    )
}
```

---

- 18日

# react & node cookie 저장

react & node로 회원가입 boiler-plate를 만드는 과정에서 로그인할 때 브라우저에 cookie 저장하는 부분이 있다. 이 부분에 있어 cors만 해결하면 된다고 생각했지만, 제대로 해결할 수 없었다.  

어떤 부분이 문제인지 확인하기 위해 추적해보니 cookie 저장하는 부분이 작동하지 않는 것을 보았다. insomnia와 네트워크 탭에서의 헤더부분에서는 cookie가 제대로 설정되지만 브라우저에는 저장이 되지 않았다.  

[참고 사이트](https://ssungkang.tistory.com/entry/React-axios-%EC%9D%98-withCredentials)을 통해서 react에서 axios로 통신을 할 때 `withCredentials` 이 속성을 true로 설정해주면 된다하여 다음과 같이 코드를 고쳤다.  

```js
export function loginUser(dataTosubmit) {
    const request = axios.post('http://localhost:5000/login', dataTosubmit, { withCredentials: true })
    .then(res => res.data)

    return {
        type: LOGIN_USER,
        payload: request
    }
}
```

redux에서 action 부분의 코드인데 여기서 withCredentials를 true로 바꿔주면 브라우저에 쿠키가 저장된 것을 볼 수 있었다.  

![image](https://user-images.githubusercontent.com/59367782/96366543-31462280-1183-11eb-81e9-840a4bc29d8f.png)

```js
const onClickHandler = () => {
    axios.get('http://localhost:5000/logout', { withCredentials: true })
        .then(res => {
            console.log(res.data);
            if(res.data.success) {
                props.history.push('/login')
            } else {
                alert('로그아웃 실패')
            }
        })
}
```

로그아웃 버튼을 누르게 되면 브라우저의 쿠키에 접근하여 jwt를 받아오고, db의 token과 비교하여 같으면 브라우저상의 쿠키 token과 db의 token을 지우는 방식으로 하였는데, 이 부분에서도 withCredentials 속성이 꺼져있어 브라우저로부터 쿠키를 받지 못하는 상황이 발생하였다. 이 부분도 속성을 켜주니 바로 해결이 가능했다.  

처음에는 node에서 저장이 안되는 것 같아서 여러가지 시도를 해보면서 검색을 해보았지만 전혀 진전이 없었고, react에서는 무엇이 잘못된지 몰라서 검색을 통해 알 수 있었다. 아무래도 node에서 요청을 받아 처리를 하지만 대부분의 값들이 react에 저장되어 서로 통신을 막혔던 것 같다. 이 boiler-plate를 만들면서 cors에 대해서 조금 더 공부할 수 있었다.  

---

# react Auth

react에서 auth를 위해 HOC를 사용해보고 공부한 점을 적어본다. HigherOrderComponent는 function로, Velopert님의 [블로그](https://velopert.com/3537)를 통해서 이해할 수 있었다.  

이후 인증을 위해서 사용하는 HOC는 

1. Auth라는 HOC을 만든 뒤 만든 컴포넌트를 다 넣는다.
2. Auth가 Backend에 Request를 보낸다.
3. Backend로부터 Auth에 속한 상태 정보를 가져온다.

이런 식으로 각 컴포넌트마다 2~3번을 반복하며, 상태를 확인해 각 컴포넌트에 접근을 통제한다.  

예를 들어 로그인한 유저는 로그인 페이지와 회원가입 페이지에 접근 할려하면 접근을 막는 방식이다.  

```js
<Switch>
    <Route exact path="/" component={Auth(LandingPage, null) } />
    <Route exact path="/login" component={Auth(LoginPage, false) } />
    <Route exact path="/register" component={Auth(RegisterPage, false) } />
</Switch>
```
HOC로 만든 Auth라는 컴포넌트안에 모든 페이지를 넣고 관리하는 식으로 만들었다.  

Auth.js
```js
import React, { useEffect } from 'react';
import { useDispatch } from 'react-redux';
import { auth } from '../_actions/user_action'

export default function (SpecificComponent, option, adminRoute = null) {
    // SpecificComponent : 컴포넌트 자체

    // option : null => 아무나 출입 가능
    // true => 로그인 유저만 출입가능
    // false => 로그인 유저 출입불가

    // adminRoute : 관리자만 출입

    function AuthenticationCheck(props) {
        const dispatch = useDispatch();

        useEffect(() => {
            dispatch(auth())
                .then(res => {
                    console.log(res);
                    // 로그인 안한 상태
                    if(!res.payload.isAuth) {
                        if(option) {
                            props.history.push('/login');
                        }
                    } else {
                        // 로그인 한 상태
                        if(adminRoute && !res.payload.isAdmin) {
                            props.history.push('/');
                        } else {
                            if(!option) { // 로그인 한 경우 접근 불가
                                props.history.push('/');
                            }
                        }
                    }
                });
            
        }, [])

        return (
            <SpecificComponent />
        )
    }
    return AuthenticationCheck;
}
```

backend에서 auth라는 요청이 날라오면 현재 클라이언트의 권한을 보내준다. 그 권한을 통해서 option에 3가지 조건을 둬서 컴포넌트의 접근을 통제하는 식으로 코딩을 하였다. HOC을 제대로 이해하지는 못했지만 인증을 위해서 하는 기능은 이해했으므로 이렇게 적어본다.

---

- 19日

# AWS Storage Services 2 : S3

## S3 : Simple Storage Service and Glacier

Amazon S3 : 어디서나 원하는 양의 데이터를 저장하고 검색할 수 있도록 구축된 객체 스토리지

### 장점

Amazon에서 말하는 장점

- 업계 최고의 성능, 확장성, 가용성, 내구성
- 광범위한 비용 효율적 스토리지 클래스
- 타의 추종을 불허하는 보안, 규정 준수, 감사 기능
- 세부적인 데이터 제어를 위한 관리 도구
- 분석을 위한 쿼리 인 플레이스 서비스
- 지원성이 가장 높은 클라우드 스토리지 서비스

### 특징

- 2006년에 출시된 최초 AWS 서비스
- 객체 기반의 무제한 파일 저장 스토리지
- URL을 통해 손쉽게 파일 공유 가능
- 99.999999999% 내구성
- 정적 웹 사이트 호스팅 서비스 가능

### Object Storage

- Object = file + metadata + unique ID
    - Metadata: 파일에 관한 추가적인 정보
        - 이름, 크기, 날짜, 권한 등 기본적인 정보 외에도 사진이라면 해상도, 찍은 위치, 시간, 누가 포함되어있는지, 영화라면 러닝타임 등 다양한 정보를 포함함
    - Unique ID
        - 특정 domain에서 구분할 수 있는 ID 제공
- Object에 대해 제공되는 서비스
    - 내부: 가용성, 내구성의 강화, 중복방지(deduplication)와 계층적 스토리지 구성 등을 통한 저장장치의 효율적 사용
    - 외부: 웹 기반의 API 제공, 버전 관리, 암호화, 모니터링, 백업

### S3 Bucket

- 파일들을 적재하는 단위
    - 내부에 폴더를 생성 가능 (일반 스토리지 장치에서 파일 시스템과 유사)
    - DNS 주소에 포함될 수 있는 형태의 이름을 가지며 변경 불가
- OLD: 하나의 Region 내에서 unique name 을 갖고 구분함
    - 예) Seoul region 의 hcpark1 bucket
        - Seoul region 내에서는 같은 이름을 가질 수 없음
        - 다른 region 에서는 가능
- NEW: Global unique name
    - Region 단위의 name space를 global로 확장
    - 그러나 데이터가 실제 저장되는 리전은 설정해야 함

[버킷 규제 및 제한](https://docs.aws.amazon.com/ko_kr/AmazonS3/latest/dev/BucketRestrictions.html)

### S3 스토리지 옵션

- Amazon S3 - 무제한 스토리지
    - 99.99% 가용성 / 99.999999999% 내구성
    - EBS에 대비 20%까지 가격이 저렴

- Amazon S3 - Infrequent Access Storage
    - S3와 같은 내구성 및 성능 / 99.9% 가용성
    - 기존 S3 대비 58% 가격 절감 가능 / 최근 백업에 사용 가능

- Amazon Glacier - 데이터 백업
    - S3와 같은 내구성, 성능 및 가용성 / 3~5시간 내 데이터 꺼내기
    - S3 표준 ㄷ내비 최고 77% 가격이 절며
    - 아케이빙, 장기간 백업 및 오래된 로그 데이터

밑으로 갈수록 사용하지 않고 보관하는 데이터를 넣는다.

### New Storage Classes

- Amazon S3 One Zone-Infrequent Access(S3 One Zone-IA)
    - 단일 AZ에 데이터를 저장하며 비용이 S3 Standard-IA보다 20% 낮음
    - 다른 S3 class는 최소 3개의 AZ에 저장하여 가용성, 복원력 높음
- Amazon S3 Intelligent-Tiering(S3 Intelligent-Tiering)
    - 성능 영향 또는 운영 오버헤드 없이 가장 비용 효과적인 액세스 계층으로 데이터를 자동으로 이동하여 비용을 최적화함
    - 자주 접근하는 데이터에 대한 IA, Glacier로의 이동은 비용을 증대
        - 따라서 액세스 패턴의 모니터링에 AI를 적용, 보다 최적의 관리 제공
- Amazon S3 Glacier Deep Archive(S3 Glacier Deep Archive)
    - 가장 저렴한 비용의 스토리지 클래스이며 1년에 한두 번 정도 액세스할 수 있는 데이터의 장기 보관 및 디지털 보존을 지원
    - 규제 규정 준수 요건을 충족하기 위해 7-10년 이상 데이터 세트를 보관하는 고객(금융 서비스, 의료, 공공 부문) 대상

### 수명 주기를 통한 비용 관리

- 일반적인 수명 주기 시나리오의 설정
    - 데이터는 우선 S3 standard 에 저장됨
    - 30일 간 접근하지 않은 데이터는 자동으로 IA로 이전
    - 90일 간 접근하지 않은 데이터는 자동으로 Glacier 로 이전
- 문제점
    - 일반적인 액세스 패턴은 소수의 데이터에 액세스가 집중되는 형태
        - 80-20 Pareto 법칙: 80%의 액세스는 20%의 데이터에 집중됨
        - 그렇다면, 20%의 데이터만 S3 standard에 상주하고, 나머지는 IA, Glacier에 저장되면서 비용이 절약될 수 있음
- 그런데, 일반적이지 않다면?
    - IA, Glacier로 이전된 데이터에 대한 액세스가 발생하면, 비싼 접근 요금을 물게되고, 이전으로 인한 비용도 요구되므로 비용 절약에 실패함
    - 이러한 경우를 위해 Intelligent tiering 을 제공함. 추가 관리 비용을 지불해야 함

### 비용

![image](https://user-images.githubusercontent.com/59367782/96404600-41f3a880-1216-11eb-9aec-514092ab3bc8.png)

비용이 쓴 만큼 나오지만, 특정한 서비스의 경우에는 여러가지 제약이 걸리며, 검색 요금도 생길 수 있다.  

- 요청 요금
    - S3 standard Select
        - 간단한 SQL 식을 사용하여, 애플리케이션이 객체에서 일부 데이터만 가져올 수 있도록 하는 서비스
    - S3 standard IA (Infrequent Access)
        - IA는 저장 요금이 싼 대신, access 를 할 때는 비싼 요금을 지불해야 함
    - S3 Glacier
        - 백업용 서비스로 저렴함
        - Deep archive는 20% 정도 더 저렴함

- 데이터 전송 요금
    - 퍼블릭 인터넷을 통해 수신 및 송신되는 데이터를 기준으로 네트워크 요금이 부과
    - 인터넷 -> Amazon S3 데이터 수신은 무료
    - Amazon S3 -> 인터넷 데이터 송신은 요금 부과
    - 다른 모든 리전으로의 데이터 송신도 요금 부과

- 가격 계산
    - 전체 60 TB 데이터를 S3에 저장하면?
        - 서울: 50 * 0.025 * 1024 + 10 * 0.024 * 1024 = 1280 + 245.76 = $1525.76 = 1,747,238.25원/월
    - 저장된 파일 1,000,000개(60TB)를 전부 다운로드 받는다면?
        - 요청 요금: GET 1,000,000회 x 0.00035/1000 = $0.35 = 394원
        - Outbound traffic 60 TB
            - ~10TB: 0.126 * 10,240 = $1290.24
            - ~50TB: 0.122 * 40,960 = $4997.12
            - ~100TB: 0.117 * 10,240 = $1198.8
            - Total: $7485.44 = 857.5만원
        - 실제 60TB의 트래픽이 발생하는 것은 대단히 큰 규모의 서비스
        - **스토리지 보다는 네트워크 사용료가 훨씬 주의해야 할 요소**

### 모니터링 및 리전간 복제

- 모니터링
    - CloudWatch: 지정 기간 동안 특정 S3 관련 지표를 관찰하고, 이벤트를 생성해 전달함
    - CloudTrail: S3 에 수행된 API 호출이나 버킷 수준의 작업을 로그로 기록하는 서비스
- 리전 간 복제
    - 서로 다른 AWS 리전의 버킷 간 객체를 자동 비동기식으로 복사하는 버킷 수준 기능
    - 필요성: 데이터의 지리적 분산, 지역에 따른 지연 시간 최소화 등
    - 기능: 모든 객체 또는 특정 키 이름의 접두사를 가진 객체의 하위 집합 복제
    - 동일 리전으로의 백업 생성도 가능

---

# Linux System Call

## 시스템 프로그래밍

- System Call: OS가 제공하는 기능들을 사용하는 것
    - 하드웨어를 제어하거나,
    - 다른 프로세스와의 통신을 수행하거나,
    - 시스템 정보에 접근, 수정하거나,
    - 시스템을 제어하는 기능 등
- 대표적인 시스템 콜
    - 화면 출력: printf() <- C 라이브러리. 내부에서 write() system call 사용
    - 파일 제어: open(), close(), read(), write()
    - 동적 메모리 할당: malloc() <- C 라이브러리. 내부에서 brk(), mmap() 사용
    - 네트워크 통신: socket(), send(), receive()

## System Call vs. Library function

- 시스템 호출
    - OS Kernel이 제공하는 서비스를 이용해 프로그램을 작성할 수 있도록 제공되는 프로그래밍 인터페이스
    - 기본적인 형태는 C 언어의 함수 형태로 제공
        - `리턴값 = 시스템호출명(인자, …);`
    - C Library 가 이러한 형태로 편리하게 이용할 수 있게 제공해주는 것
- 라이브러리 함수
    - 라이브러리 : 미리 컴파일된 함수들을 묶어서 제공하는 특수한 형태의 파일
        - `/lib`, `/usr/lib`에 위치하며 `lib*.a` 또는 `lib*.so` (static object) 형태로 제공
    - 자주 사용하는 기능을 독립적으로 분리하여 구현해둠으로써 프로그램의 개발과 디버깅을 쉽게하고 컴파일을 좀 더 빠르게 할 수 있다
    - OS 커널과 무관하게 단순한 C 코드를 수행
        - 예) strcpy() : 문자열 복사를 위한 연산을 수행. 편의를 위한 라이브러리 함수
- 두 가지 시스템 콜 호출 방법
    - 직접 시스템콜 호출: 본래 시스템콜은 특수한 방식(trap)을 통해 호출하여야 함
        - 이유1: 시스템콜의 코드가 일반 사용자가 접근할 수 없는 OS 커널 영역에 존재하기 때문
        - 이유2: 시스템콜은 다수 존재하고, 번호로 구분하기 때문에 직관적이지 않음
        - 굳이 하려면? : syscall() 함수 이용
    - **라이브러리 함수 사용**
        - C 라이브러리는 시스템콜을 간편히 사용할 수 있게 도와주는 여러 함수 제공
        - 예) printf() : 화면 출력을 위해서는 본래 write() 시스템 콜을 사용해야 함
        - **일반적으로 거의 모든 경우에 라이브러리 함수를 통해 시스템콜을 이용함**

![image](https://user-images.githubusercontent.com/59367782/96449848-666c7680-1250-11eb-9968-46781fa0c72e.png)


### syscall()의 사용

```c
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdio.h>

int main() {
        printf("My pid: %d\n", getpid());
        printf("My pid: %d by syscall()\n", (int)syscall(39));
        sleep(1);
        return 0;
}
```

- getpid()
    - 현재 프로세스의 PID를 반환
    - C 라이브러리 함수
    - 이 정보는 OS가 관리하기 때문에, 시스템콜을 통해 수행됨
    - 이때 sys_getpid 라는 이름의 시스템콜을 이용하며, 해당 시스템콜 번호는 39

### man page에서의 섹션 구분

![image](https://user-images.githubusercontent.com/59367782/96450868-bc8de980-1251-11eb-9e3d-f3746a2ee180.png)

printf의 경우 section이 1과 3으로 나뉘어지므로 `$ man printf`와 `$ man 3 printf`로 나눠서 볼 수 있다.

## Error handling

### 시스템 호출의 오류 처리방법

- **결과값: 성공하면 0을 리턴, 실패하면 -1을 리턴**
- 실패 시, 전역변수 errno에 오류 코드 저장
    - Extern 을 이용해 C 라이브러리와 사용자 프로그램이 전역 변수를 공유할 수 있음
    - Extern: 해당 소스 파일의 외부에서 선언한 변수를 인용해서 사용하는 것
- 오류 코드의 확인: errno 유틸리티 사용 <- `moreutils` 설치 후  `$ errno -l`
- 예시
```c
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

extern int errno;

int main() {
        if (access("unix.txt", F_OK == -1) {
                printf("errno=%d\n", errno);
        }       
        return 0;
}  
```

### 라이브러리 함수의 오류 처리방법

- 오류가 발생하면 NULL을 리턴, 함수의 리턴값이 int 형이면 -1 리턴
- errno 변수에 오류 코드 저장
- 예시
```c
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

extern int errno;

int main() {
        FILE *fp;
        if((fp = fopen("unix.txt", "r")) == NULL) {
                printf("errno=%d\n", errno);
                return 1;
        }
        fclose(fp);

        return 0;
}
```


- fopen()
    - File stream 을 여는 C 라이브러리 함수
    - 해당 파일이 없으면 에러가 나고, NULL 을 리턴

### 보다 편리한 오류 처리

- 오류 메시지 출력 : perror(3)
- Errno 에 따라 에러 메시지를 출력함
- 예시
```c
#include <unistd.h>
#include <stdio.h>

int main() {
        if (access("unix.txt", F_OK) == -1) {
                perror("my message");
                return 1;
        }
        return 0;
}
```

---

# File: Low-level I/O

## File

### Volatile and Non-volatile storage devices

- Primary storage: Main memory
    - 주기억장치로 사용하는 DRAM 등의 휘발성 저장 장치
    - 성능이 높지만, 적은 저장 공간 제공
        - 프로그램 내의 변수와 같이 용량은 적지만 자주 접근하는 자료를 저장
- Secondary storage: Storage devices
    - 보조기억장치로 사용하는 HDD, SSD 등은 비휘발성 저장 장치
    - 느리지만, 많은 저장 공간을 제공
        - 시스템 종료 시에도 보관하여야 할 데이터를 적재하고, 시스템 재기동 시 다시 로드
    - **일반적으로 파일(file)의 형태로 데이터를 저장함**

### 파일과 파일 속성

- 파일: 보조기억장치의 정보저장 단위로 자료의 집합
    - **Collection of data**
    - 0부터 시작하는 주소 공간에 1B 단위로 데이터를 저장하고, 접근할 수 있음
- 파일의 속성 (attribute)
    - 파일은 Data 와 Metadata 로 구성됨
        - Data: 사용자가 저장하고자 하는 데이터
        - **Metadata: 데이터의 속성이나 특징 등, 저장된 데이터를 설명하기 위한 추가적인 데이터**
        - Metadata 를 주로 file attribute 라고 지칭함
    - 대표적인 Metadata
        - Name, Size, Creation time, Last modified time, Last access time, access control
    - 추가적인 Metadata
        - 사진: 찍은 날짜, 위치, 포함된 사람들 등등
        - 영화: Runtime, 제목, 첫 상영 날짜, 출연 배우 등등
    - 보다 다양한 정보가 요구됨에 따라 파일의 metadata 저장 방식도 발전하고 있음

### File Operations

- 파일에 대해 수행할 수 있는, OS가 제공하는 기본 동작
    - Basic: **open, close, read, write**
        - 파일을 사용하기 위해서는 우선 열어야 하고, (open)
        - 사용을 완료한 후에는 닫아야 한다. (close)
        - 이외의 데이터 접근 방법은 없음!
            - Insert? Modification?
            - 모두 Read and Write 로 구현하여야 함
- Control
    - Seek: 파일의 현재 위치 설정
    - Truncate: 파일의 내용 삭제
    - Delete (or remove, unlink, release): 파일 삭제
    - Flush (or sync): 파일의 내용을 즉각 저장 장치에 기록
    - 기타: mmap, poll, lock 등 공유 및 동기화를 위한 제어 방법들


### Low- & High-level File I/O (Input and Output)

- Low-level File I/O
    - 파일을 다루기 위해 OS에서 제공하는 시스템콜들을 직접 사용
    - 특수한 파일 (장치 파일 등)을 제어할 때 주로 사용함
    - Open(), close(), read(), write(), lseek() 등
- High-level File I/O
    - C 라이브러리 등에서 제공하는 보다 편리한 파일 입출력 서비스
    - Low-level file I/O 는 시스템콜 그 자체라면,
    - High-level 은 시스템콜을 다양한 형태로 가공하여 편의성을 높인 것
    - 예) fprintf() : 파일에 바로 원하는 형태의 문자열을 출력할 수 있음
        - Low-level 에서는 우선 문자열을 원하는 형태로 가공한 후, write()를 사용해 문자열의 길이 등을 함께 전달하여 기록해야 함
    - fopen(), fclose() 등, 이름이 유사하나 앞에 `f` 가 붙는 경우가 많음
    - 라이브러리 내에서 성능 등의 이유로 버퍼를 이용하므로, 버퍼 기반 입출력 이라고 부르기도 함

## Low-level File I/O

### 파일 기술자

- 파일 기술자
    - 현재 프로세스를 통해 열려 있는 파일을 구분하는 정수값.
        - OS가 해당 프로세스의 열린 파일들을 관리하기 위해 사용하는 테이블의 Index
    - 저수준 파일 입출력에서 열린 파일을 참조하는데 사용
    - 기본으로 지정된 파일 기술자들
        - 0번 : 표준 입력, 1번 : 표준 출력, 2번 : 표준 오류

![image](https://user-images.githubusercontent.com/59367782/96454638-1b099680-1257-11eb-940d-b4b760dd64c0.png)

### 파일 생성과 열고 닫기

- 파일 열기: open(2)
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```
- Pathname 에 지정한 파일을 flags에 지정한 플래그 값에 따라 연다.
    - Pathname 은 상대 주소, 절대 주소 모두 가능
    - 만약 지정한 파일이 없고, flag 에 O_CREAT 가 설정된 경우 새로운 파일 생성
- Return value
    - **The new file descriptor (파일 기술자)**
    - -1 on error


- Flags: 파일을 어떤 모드로 열지 선택
    - OR 연산(|)을 이용해 복합하여 사용 가능
        - 예) O_RDWR|O_CREAT : 읽기/쓰기 모두 가능한 모드로 열고, 파일이 없는 경우 새로 생성함
|종류| 기능|
|---|---|
|O_RDONLY| 파일을 읽기 전용으로 연다.|
|O_WRONLY| 파일을 쓰기 전용으로 연다.|
|O_RDWR| 파일을 읽기와 쓰기가 가능하게 연다.|
|O_CREAT| 파일이 없으면 파일을 생성한다|
|O_EXCL O_CREAT| 옵션과 함께 사용할 경우 기존에 없는 파일이면 파일을 생성하지만, 파일이 이미 있으면 파일을 생성하지 않고 오류 메시지를 출력한다.|
|O_TRUNC| 파일을 생성할 때 이미 있는 파일이고 쓰기 옵션으로 열었으면 내용을 모두 지우고 파일의 길이를 0으로 변경한다.|
|O_APPEND| 파일의 맨 끝에 내용을 추가하는 모드. (position 이 EOF: End-of-File 로 설정됨)|
|O_NONBLOCK/O_NDELAY| 비블로킹(Non-blocking) 입출력|
|O_SYNC/O_DSYNC| 저장장치에 쓰기가 끝나야 쓰기 동작을 완료|

- mode : 옵션으로, 파일 접근권한을 지정할 수 있음
    - 0644같이 숫자나 플래그 값으로 지정 가능 (앞에 0을 넣어 Octet 임을 표시)
        - 예) `Mode = S_IRUSR | S_IWUSR; = 0600 소유자 RW`

| 플래그 | 모드 | 설명 |
|---|---|---|
|S_IRWXU|0700|소유자 읽기/쓰기/실행 권한|
|S_IWUSR|0400|소유자 읽기 권한|
|S_IRUSR|0200|소유자 쓰기 권한|
|S_IXUSR|0100|소유자 실행 권한|
|S_IRWXG|0070|그룹 읽기/쓰기/실행 권한|
|S_IRGRP|0040|그룹 읽기 권한|
|S_IWGRP|0020|그룹 쓰기 권한|
|S_IXGRP|0010|그룹 실행 권한|
|S_IRWXO|0007|기타 사용자 읽기/쓰기/실행 권한|
|S_IROTH|0004|기타 사용자 읽기 권한|
|S_IWOTH|0002|기타 사용자 쓰기 권한|
|S_IXOTH|0001|기타 사용자 실행 권한|


- 파일 닫기: close(2)
    - 파일의 사용이 끝나면 close()를 호출하여 파일을 명시적으로 닫아야 함
        - 프로세스에서 열 수 있는 파일 개수가 제한되어 있으므로 이를 확보하기 위함
        - 파일의 사용이 끝났음을 알려, 다른 프로세스가 파일을 수정하거나 제어할 수 있도록 함
    - 주의! Close()를 수행한다고 해서 모든 데이터가 저장 장치에 기록이 완료된 것은 아님
        - 데이터가 메모리 상에 남아있고, 저장 장치에는 기록이 되지 않은 상태일 수 있음
- Return value
    - Close() returns zero on success.
    - On error, -1 is returned, and errno is set appropriately.
        - 일반적으로 close()는 에러 체크를 하지 않음.
        - Open() 시 에러 체크를 통해, 파일이 열려있다고 확신을 한 상태에서 작업하기 때문
        - 하지만, 드물게 write()가 실패한 경우, close()에서 에러가 발생하여 이를 알릴 수 있으므로 close()에서도 에러 체크를 하는 것이 좋음

- 예)
```c
#include <unistd.h>
int close(int fd);
```

- 파일 생성 : creat(2)
    - A call to creat() is equivalent to calling open() with flags equal to O_CREAT|O_WRONLY|O_TRUNC
    - open 함수와 달리 옵션을 지정하는 부분이 없다.
    - Creat() 함수로 파일을 생성하면 파일 기술자를 리턴하므로 별도로 open할 필요 없음
- **이런건 배우지 말자. Open() 만 알면 된다!**
    - Open() 에 파일 생성 flag이 없던 구버전 유닉스에서 사용

- 예)
```c
#include <sys/stat.h>
#include <fcntl.h>
int creat(const char *path, mode_t mode);
```


### File Read and Write: Sequential Access

- 파일은 기본적으로 데이터를 sequential 하게 접근하는 것을 가정
    - Sequential access: 처음부터 순서대로 데이터를 읽음
        - 예) 음악이나 영화 파일의 재생
    - Random access: 임의의 위치에 저장된 데이터를 순서에 무관하게 접근
        - 예) 성적 리스트에서 학번을 찾아 해당하는 성적을 확인하는 것
- File access position
    - OS는 파일에 대한 현재 읽고 쓰기 위한 위치 (position or offset)을 관리함
        - 위치는 Byte 단위로 표현
        - 이 정보는 OS가 관리하므로, 프로그램은 직접 수정할 수 없음 (system call 사용)
- 파일을 열면 (open), position 은 0으로 설정됨
- 이때, 파일을 읽거나 쓰면, 0번 주소부터 데이터를 읽거나 씀
- 그리고 이때 읽거나 쓴 데이터의 양만큼 position 은 자동으로 이동함
    - 예) 만약 80 B의 데이터를 읽은 다음에는 position 은 80 으로 변경됨
- 이후 읽거나 쓰게 되면, 이동한 위치에서부터 다시 데이터를 접근함

### 파일 읽기와 쓰기

- 파일 읽기 : read(2)
    - fd가 가리키는 파일에서,
    - nbytes로 지정한 크기만큼 바이트를 읽어서,
    - buf에 저장
- Return value
    - 실제로 읽어온 바이트 개수를 리턴
    - 리턴값이 0이면 파일의 끝에 도달했음을 의미
- 파일의 종류에 상관없이 무조건 바이트 단위로 읽어온다.
- 예)
```cpp
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t nbytes);
```

- 파일 쓰기 : write(2)
    - fd가 지정하는 파일에,
    - buf가 가리키는 메모리로부터,
    - nbytes로 지정한 크기만큼 쓰기
- Return value
    - 실제로 쓰기를 수행한 바이트 수를 리턴

- 예)
```cpp
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t nbytes);
```

### 파일 오프셋 지정

- 파일 오프셋 위치 지정 : lseek(2)
    - offset으로 지정한 크기만큼 오프셋을 이동시킨다.
    - offset의 값은 whence값을 기준으로 해석한다.
![image](https://user-images.githubusercontent.com/59367782/96456850-0b3f8180-125a-11eb-9b21-1e027f7f51ca.png)
    - 파일 오프셋의 현재 위치를 알려면?
        - `cur_offset = lseek(fd, 0, SEEK_CUR);`

- 예)
```cpp
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
```

### 예시

1. 새 파일 열고 닫기
```cpp
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
        int fd;
        char name[] = "unix.txt";
        mode_t mode;

        mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        fd = open(name, O_CREAT, mode);
        if (fd == -1) {
                perror("Creat");
                exit(1);
        }

        printf("%s is opened! fd = %d\n", name, fd);
        close(fd);

        return 0;
} 
```

2. O_EXCL 플래그 사용하기
```cpp
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
        int fd;
        char name[] = "unix.txt";
        mode_t mode;

        mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

        fd = open(name, O_CREAT|O_EXCL, mode);
        if (fd == -1) {
                perror("Creat");
                exit(1);
        }

        printf("%s is opened! fd = %d\n", name, fd);
        close(fd);

        return 0;
}
```

3. 파일 읽기
```cpp
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        int fd, count;
        char buf[80];

        if(argc != 2) {
                printf("< Usage: ./file3 filename >\n");
                return 1;
        }
        fd = open(argv[1], O_RDWR);
        if (fd == -1) {
                perror("Open");
                exit(1);
        }

        printf("%s is opened! fd = %d\n", argv[1], fd);

        while((count = read(fd, buf, 80)) > 0 ) {
                printf("%d: %s\n", count, buf);
        }
        close(fd);
        return 0;
}
```

4. 파일 읽고 쓰기
```cpp
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        int rfd, wfd, count;
        char buf[80];

        if(argc != 3) {
                printf("< Usage: ./file4 file_for_read file_for_write >\n");
                return 1;
        }
        rfd = open(argv[1], O_RDONLY);
        if (rfd == -1) {
                perror("Open file for read");
                exit(1);
        }
        wfd = open(argv[2], O_RDWR|O_CREAT|O_EXCL, 0644);
        if (wfd == -1) {
                perror("Open file for write");
                exit(1);
        }
        printf("%s and %s are opened! rfd = %d wfd = %d\n", argv[1], argv[2], rfd, wfd);

        while((count = read(rfd, buf, 10)) > 0 ) {
                write(wfd, buf, count);
        }
        close(rfd);
        close(wfd);
        return 0;
}
```

5. 파일 오프셋 사용
```cpp
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
        if ((count = read(fd, buf, 5)) <= 0) {
                perror("Read Error");
                exit(1);
        }
}       

int main(int argc, char* argv[]) {
        if(argc != 2) {
                printf ("< Usage: ./file5 filename >\n");
                return 1;
        }

        fd = open(argv[1], O_RDWR);
        if (fd == -1) {
                perror("Open");
                exit(1);
        }
        printf("%s is opened! fd = %d\n", argv[1], fd);
        read_five_bytes();
        printf("\n%d: %s\n", count, buf);
        printf("Current position: %ld\n", lseek(fd, 0, SEEK_CUR));
 
        lseek(fd, 1, SEEK_SET);
        read_five_bytes();
        printf("\n%d: %s\n", count, buf);
        printf("Current position: %ld\n", lseek(fd, 0, SEEK_CUR));

        lseek(fd, 2, SEEK_SET);
        read_five_bytes();
        printf("\n%d: %s\n", count, buf);
        printf("Current position: %ld\n", lseek(fd, 0, SEEK_CUR));

        close(fd);

        return 0;
}
```

---

- 20日

# fetch와 axios의 차이

## fetch
![image](https://user-images.githubusercontent.com/59367782/96558187-468f8e00-12f6-11eb-8b56-be66440cf490.png)

## axios
![image](https://user-images.githubusercontent.com/59367782/96558250-5a3af480-12f6-11eb-9871-0f7e45e3cbc6.png)

(사진 출처: John Ahn님)

## 결론

둘 다 데이터를 가져오게 되는데, fetch의 경우 json형태로 볼려면 `.json()`메소드를 통해서 변환을 한 뒤 이용해야한다. 따라서 에러 핸들링 하는 부분도 달라진다.  

axios의 경우는 가져올 때 json형태로 가져오기 때문에 한 단계를 더 생략할 수 있어서 편의성에 있어서 axios가 더 편하다.

&&

컴퓨터 네트워크 시험 공부 (Network Layer, Layer Protocol, Unicast & Multicast, Transport Layer)  

---

- 21日

# 컴퓨터 네트워크 시험 공부 (Network Layer, Layer Protocol, Unicast & Multicast, Transport Layer)  
- [웹 참고](https://lee20h.github.io/TIL/Network/Roadmap.html#%EC%9D%B8%ED%84%B0%EB%84%B7%EC%9D%B4%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80)  

# 데이터베이스 SQL 복습

외래키 제약조건 중 CASCADE부분을 학교 강의 과제로써 수행했다. ERR 관계도와 테이블과 튜플을 다 주어준 뒤 ERR 관계도 중 가장 큰 집합에 속하는 테이블의 튜플을 지울 경우 해당하는 튜플이 속한 테이블에서 지워지는 것을 보여야 했다. 따라서 트리거링이 아닌 외래키 제약조건 중 On Delete 부분을 CASCADE로 설정함으로써 해결하였다.  

---

- 22日

PS를 주로 하면 보냈으나 대부분 쉬운 문제를 해결하였다. 그 중 막힌 문제를 보자.  

소수찾기
```cpp
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 1e7;
bool isprime[MAX];


int solution(string numbers) {
    int answer = 0;
    isprime[0] = isprime[1] = true;
    for (int i=2; i<=10000; i++) {
        for (int j=2; i*j<=MAX; j++)
            isprime[i*j] = true;
    }
    sort(numbers.begin(),numbers.end());
    
    set<int> s;
    do {
    	int idx = 1;
    	while(idx <= numbers.size()) {
    		string str;
    		for (int i=0; i<idx; i++) {
    			str += numbers[i];
			}
    		s.insert(stoi(str));
            idx++;
		}	
	}while(next_permutation(numbers.begin(), numbers.end()));
	
    set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
        if(!isprime[*it])
            answer++;
    }
	
    return answer;
}

```

소수 찾기 문제는 주어진 숫자들을 가지고 만들 수 있는 값들 중 소수를 찾는 문제로, 완전 탐색으로 볼 수 있다. 에라토스테네스의 체와 next_permutation을 사용하여 해결하였다. 하지만 next_permutation을 생각했으나 오해한 점이 하나 있다. 정해진 범위를 가지고 전부 순열을 구하는 부분이 아니라, 범위에서 주어진 값을 전부 내림차순으로 바꾸게 되면 끝나느 것이였다.  

따라서 내 논리대로 할려면 처음에 정렬을 한 뒤 next_permutation을 시행했어야했다. 이 부분에 대해 알고 있지 않아서 답을 구하지 못했다.  

큰 수 만들기
```cpp
#include <iostream>
#include <string>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";
    for (int i = 0, index = -1; i < number.length() - k; i++) {
        char max = 0;
        for (int j = index + 1; j <= k + i; j++) {
            if (max < number[j]) {
                index = j;
                max = number[j];
            }
        }
        answer += max;
    }
    return answer;
}
```
주어진 숫자를 순서를 유지한 채로 몇 개의 숫자를 뺐을 때 가장 큰 수를 구하는 문제로, 머리로는 되나 코드로 구현하지 못해 블로그의 도움을 받았다.  

먼저 해당 자릿수를 구한 뒤 그 만큼의 값 중 가장 큰 값을 먼저 찾고 그다음 뒷 값 중 큰 값을 찾아서 하나하나 넣어주었다.  

가장 큰 수
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    int Sum = 0;
    for (int i=0; i<numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
        Sum += numbers[i];
    }
    if(!Sum)
        return "0";
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i=0; i<v.size(); i++)
        answer += v[i];
    return answer;
}
```
문자열에서 어떻게 더하냐에 따라 값이 달라지는 특성을 이용하여 가장 큰 값을 찾는 문제인데, 금방 코딩했으나 cmp()의 조건을 잡는데 잘못 디뎌서 오래 걸렸다. 하지만 생각해보니 그냥 기준을 바꿔서 앞뒤로 더한 값을 서로 비교하면 되는 것이였다.  

---

- 23日

컴퓨터 네트워크 시험을 치뤘다. 대부분 시험이 저녁시간에 있어 시험에 집중하기 위해서 다른 공부를 하지 않고 시험 준비를 하였다.  

시험에 있어 깜빡한 부분이 있어서 틀려서 다시 적어볼려고 한다.  

네이버와 같이 큰 사이트에서 분산을 부담을 나누기위해서 사용하는 방법은 바로 **Overlay Network**이다. 가상으로 망을 잡아서 2의 거듭제곱으로 갯수가 늘어난다. 이 부분을 잊어버려서 틀려서 아쉬웠다.

---

- 24日

# PS

- 쿼드압축 후 세기
```cpp
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

void div(int size, int y, int x, vector<int> &answer) {
	bool zero = true, one = true;
	for (int i=y; i<y+size; i++) {
		for (int j=x; j<x+size; j++) {
			if(v[i][j])
				zero = false;
			else if(!v[i][j])
				one = false;
		}
	}
	if(zero) {
		answer[0]++;
		return;
	}
	if(one) {
		answer[1]++;
		return;
	}
	
	div(size/2, y, x, answer);
	div(size/2, y+size/2, x, answer);
	div(size/2, y, x+size/2, answer);
	div(size/2, y+size/2, x+size/2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    v = arr;
    div(arr.size(), 0, 0, answer);
    return answer;
}
```

분할 정복을 이용하여 푸는 문제로 백준의 색종이 접기 문제와 유사하다. 평소에는 분할정복을 해결할 때 가로 세로 시작과 끝을 전부 매개변수로 던져서 해결하였는데, 다른 사람의 풀이를 참고하여 풀어보았다. 이 분은 매개변수 size를 가지고 훨씬 적은 매개변수로 해결하였다. 시작 점을 먼저 저장하고 그 다음에 이중 포문에서 만난 점이 시작 점과 끝까지 동일하다면 그 범위는 전부 해당 값과 같다고 진행하는 식으로 하였으나, 이번에는 나오고나서 1과 0의 boolean으로 해보았다.  

두 풀이 모두 괜찮으나, 분할정복의 함수 매개변수는 현재 것이 조금 더 코드가 간결해보이며, 내부의 내용은 시작점을 가지고 하는 것이 더 한 눈에 이해가 되는 코드인 것 같다.

- 카펫
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;
    vector<int> divisor;
    for (int i=1; i<size; i++) {
        if(size%i == 0) {
            divisor.push_back(i);
        }
    }
    
    int w, h;
    for (int i=divisor.size()-1; i>0; i--) {
        bool flag = false;
        w = divisor[i];
        for (int j=divisor.size()-1; j>0; j--) {
            h = divisor[j];
            if(w*h == size) {
                int temp = w*2 + (h-2)*2;
                if(brown != temp)
                    continue;
                flag = true;
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
        if(flag)
            break;
    }
    return answer;
}
```

먼저 약수를 구한 뒤 약수들의 조합을 하되, 약수끼리 곱했을 때 갈색과 노란색 카펫의 합이 나와야하며, 갈색의 경우 테두리이기 때문에 테두리를 구하는 공식에 넣었을 때 동일한 값만 answer에 넣어주었다.

- H-index
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size();
    sort(citations.begin(), citations.end());
    int size = citations.size();
    for (int i=0; i<size; i++) {
        if(citations[i] >= answer)
            break;
        answer--;
    }
    return answer;
}
```
해당 문제는 말을 이해하지 못해서 생각보다 오래걸렸다. 갯수의 최대가 아닌 논문 인용의 수의 최대를 생각하여 생각이 길어진 문제로, 오름차순으로 정렬된 논문 인용된 횟수가 적힌 배열과 논문의 갯수를 비교하여 answer의 값을 구하는 식으로 하였다.

---

- 25日

# PS

어제에 이어서 PS 공부했다.

- 가장 큰 정사각형
```cpp
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for (int i=0; i<board.size(); i++) {
        answer = max(answer, board[i][0]);
    }
    for (int i=0; i<board[0].size(); i++) {
        answer = max(answer, board[0][i]);
    }
    for (int i=1; i<board.size(); i++) {
        for (int j=1; j<board[i].size(); j++) {
            if(board[i][j]) {
                board[i][j] = min(min(board[i][j-1], board[i-1][j]), board[i-1][j-1]) + 1;
                answer = max(board[i][j], answer);
            }
        }
    }
    return pow(answer,2);
}
```

이차원 배열 board에 0 혹은 1의 값이 들어 있을 때 1로 이루어진 정사각형의 넓이를 구하는 문제이다. 접근을 LCS를 풀이하듯이 접근하였다. 보드가 주어지면 그 보드의 인덱스의 y방향으로 -1, x방향으로 -1, xy방향으로 -1 세 가지의 인덱스 중 가장 작은 값을 해당 인덱스에 넣는 방식으로 하였다. 이때 0부터 시작하게되면 배열의 범위를 넘어서기 때문에 (1,1)부터 시작하며, 0번째 행과 열은 따로 해준 뒤 answer 값의 제곱을 반환해주었다.  

- 단체사진 찍기
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int pos[26];

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> kf = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    do{
        for(int i=0; i<kf.size(); i++)
            pos[kf[i] - 'A'] = i;
        bool flag = true;
        
        for (int i=0; i<data.size(); i++) {
            int first = data[i][0] - 'A';
            int last = data[i][2] - 'A';
            char oper = data[i][3];
            int diff = data[i][4] - '0';
            int cmp = abs(pos[first] - pos[last]) - 1;
            
            switch(oper) {
                case '=' : 
                    if(cmp != diff)
                        flag = false;
                    break;
                case '<' :
                    if(cmp >= diff)
                        flag = false;
                    break;
                case '>' :
                    if(cmp <= diff)
                        flag = false;
                    break;
            }
            if(!flag)
                break;
        }
        if(flag)
            answer++;
    }while(next_permutation(kf.begin(),kf.end()));
    
    return answer;
}
```

언뜻 보면 떠오르지 않는 풀이의 문제였다. 카카오프렌즈들이 단체 사진을 찍고자하는데 누군가가 내민 조건들을 다 수합한 상태에서 찍을 수 있는 경우의 수를 구하는 문제이다. 이 때 카카오프렌즈들의 순서는 `next_permutation()`을 통해서 모든 경우의 수를 체크하였다. 이후 조건을 확인하기 위해서 pos배열로 알파벳들의 순서를 잡아준 뒤, 조건에 따라서 조건 제시자와 상대 사이의 카카오프렌즈가 몇 명 있는지 확인하여 조건과 맞나 비교하여주었다.  

조건에 부합하지 않는다면 다음 순열로 넘어가고, 조건에 부합한다면 answer를 1씩 늘려주는 식으로 진행하였다.  

- 땅따먹기
```cpp
#include <iostream>
#include <vector>
using namespace std;

int dp[2][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for (int i=0; i<4; i++)
        dp[0][i] = land[0][i];
    
    for (int i=1; i<land.size(); i++) {
        dp[i%2][0] = max(max(dp[(i-1)%2][1] + land[i][0], dp[(i-1)%2][2] + land[i][0]),dp[(i-1)%2][3] + land[i][0]);
        dp[i%2][1] = max(max(dp[(i-1)%2][0] + land[i][1], dp[(i-1)%2][2] + land[i][1]),dp[(i-1)%2][3] + land[i][1]);
        dp[i%2][2] = max(max(dp[(i-1)%2][1] + land[i][2], dp[(i-1)%2][0] + land[i][2]),dp[(i-1)%2][3] + land[i][2]);
        dp[i%2][3] = max(max(dp[(i-1)%2][1] + land[i][3], dp[(i-1)%2][2] + land[i][3]),dp[(i-1)%2][0] + land[i][3]);
    }
    
    for (int i=0; i<4; i++) {
        answer = max(answer, dp[(land.size()-1) % 2][i]);
    }
    return answer;
}
```

이차원 배열 land가 주어지고 열은 항상 4개로 고정되어 있다. 모든 행을 거치되, 이전의 행에서 밟은 열은 못 밟는다. 그때 총 밟은 숫자들의 합이 최대가 되게 해야하는 문제이다. 보면 매 행에서 이전 열을 제외하고 가장 큰 숫자를 넣으면 될 것 같지만 반례가 존재한다. 따라서 모든 부분을 체크해주면서 이전 값을 사용하기 위해서 DP로 구현하였다.  

문제의 조건을 보면 이전 행만 조건에 쓰이기 때문에 dp를 작게 정의해 메모리를 아꼈다. 현재 인덱스의 값과 지금까지 더해온 값들과 더해주되, 자기자신의 열은 제외해서 그 값들 중 최대를 취한다. 이후에 다 진행이 되면 dp배열에 최댓값들이 남게 되는데 해당 배열에서 가장 큰 값을 리턴해주면 된다.  

- 행렬의 곱셈
```cpp
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i=0; i<arr1.size(); i++) {
        vector<int> v;
        for (int j=0; j<arr2[0].size(); j++) {
            int sum = 0;
            for (int k=0; k<arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}
```

행렬의 곱셈을 단순하게 코드로 표현하면 된다. 이 문제를 적은 이유는 운영체제 강의에서 듣기로는 이차원 배열에서 column-major인 연산을 하게 되면 cpu에서 캐싱을 하지 못해서 느려진다고 들었다. 따라서 조금 더 빠른 방법을 생각해보자해서 적어본다. 이차원 배열은 메모리가 row끼리 붙어있는데 arr2와 같이 접근하게 되면 locality가 떨어지게 된다.  

```cpp
for (int k=0; k<arr2.size(); k++) {
    for (int i=0; i<arr1.size(); i++) {
        for (int j=0; j<arr2[0].size(); j++) {
            matrix[i][j] += arr1[i][k] * arr2[k][j];
        }
    }
}
```
이러한 소스를 해당 문제에 적용을 하게 되면,

```cpp
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(), 0));

    for (int k=0; k<arr2.size(); k++) {
        for (int i=0; i<arr1.size(); i++) {
            for (int j=0; j<arr2[0].size(); j++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}
```
속도도 빨라지고 한층 짧아진 것을 알 수 있다. 앞으로도 이차원 배열에 적용할 때 잘 생각해야겠다.

[참고사이트](https://sosal.kr/878)

---

- 26日

# PS

- N개의 최소공배수
```cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int solution(vector<int> arr) {
    int answer = 0;
    int mul = 1;
    priority_queue<int> q;
    for (int i=0; i<arr.size(); i++) {
        mul *= arr[i];
        q.push(arr[i]);
    }
    while(q.size() != 1) {
        int num1 = q.top();
        q.pop();
        int num2 = q.top();
        q.pop();
        q.push(num1*num2/gcd(num1,num2));
    }
    answer = q.top();
    return answer;
}
```

각각의 최대공약수를 가지고 하는 것이 아닌 2개의 숫자를 가지고 최소공배수를 구하고 그 다음 수와 또 최소공배수를 구하는 식으로 반복하였다. 처음에는 전부를 가지고 하려하자 답이 안 나와서 시간을 많이 보냈었다.

- 점프와 순간 이동
```cpp
#include <bitset>
using namespace std;

int solution(int n)
{
    int ans = 0;
    bitset<30> bit = n;
    for (int i=0; i<30; i++) {
        if(bit[i])
            ans++;
    }
    return ans;
}
```
이 문제는 순간이동은 건전지가 안 들지만 점프는 움직인 거리만큼 건전지가 다는 문제로, 거리가 주어질 때 최소의 건전지를 들여서 가야한다. 생각해보면 순간이동으로 두 배를 간다는 것은 비트로 보면 비트 쉬프트 왼쪽으로 1한 것과 같다. 따라서 점프는 비트를 0에서 1로 바꾸는 행위이므로, 거리를 바이너리화 한 뒤 1의 숫자를 세주었다.

- 예상 대진표
```cpp
int solution(int n, int a, int b)
{
    int answer = 1;
    if(a<b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while(a-b > 1) {
        a&1 ? a= a/2+1 : a= a/2;
        b&1 ? b= b/2+1 : b= b/2;
        answer++;
    }
    
    return answer;
}
```
이 문제 또한 상기시키기 위해 적어본다. 전혀 어렵지 않았지만 바로 떠오르지 못했기 때문에 적어볼려고 한다. 문제는 토너먼트에서 a와 b가 주어지면 a와 b가 주어질려면 몇 경기가 치뤄져야하나는 문제이다. 쉽게 생각하면 한번 경기할 때마다 1/2씩 줄어들고 둘이 만나기 전까진 다 이겨야하므로, 홀수면 2로 나눈 뒤 1을 더하고 짝수면 2로 나누기를 반복하면 된다.

이외에도 많이 풀이를 했으나, 확실히 몇 주간 PS보단 전공과 웹 공부를 주로 하다보니 감을 잃은게 확실하다. 시험 중간중간에 자꾸 PS를 풀어줘서 리마인드하도록 해야겠다.

---

- 27日

# PS

- 뉴스 클러스터링

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v;
    vector<string> v2;
    for (int i=0; i<str1.length(); i++)
        str1[i] = tolower(str1[i]);
    for (int i=0; i<str2.length(); i++)
        str2[i] = tolower(str2[i]);
    
    for (int i=1; i<str1.length(); i++) {
        string temp;
        if(('a' <= str1[i-1] && str1[i-1] <= 'z') && ('a' <= str1[i] && str1[i] <= 'z')) {
            temp = str1.substr(i-1, 2);
            v.push_back(temp);    
        }
    }
    
    for (int i=1; i<str2.length(); i++) {
        string temp;
        if(('a' <= str2[i-1] && str2[i-1] <= 'z') && ('a' <= str2[i] && str2[i] <= 'z')) {
            temp = str2.substr(i-1, 2);
            v2.push_back(temp);    
        }
    }
    
    if(v.empty() && v2.empty()) {
        return 65536;
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    
    vector<string> uni(v.size() + v2.size());
    auto it = set_union(v.begin(),v.end(),v2.begin(),v2.end(),uni.begin());
    uni.erase(it,uni.end());
    vector<string> intersect(v.size() + v2.size());
    it = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), intersect.begin());
    intersect.erase(it, intersect.end());
    
    double temp = (double)intersect.size() / (double)uni.size();
    answer = temp * 65536;
    return answer;
}
```
자카드 유사도를 구하기 위해서 교집합 / 합집합의 값을 구하는 문제이다. 그러기 위해 문자열을 조작하여 2개씩 나눠서 같은 값들을 체크해서 교집합과 합집합의 숫자를 찾아서 나눠주었다.

```cpp
#include <bits/stdc++.h>
using namespace std;
short a, b, C[676], D[676];
int solution(string A, string B) {
    for(int i=1; i<A.size(); i++)
        if(isalpha(A[i-1]) && isalpha(A[i]))
            C[(A[i-1]&31)*26+(A[i]&31)]++;
    for(int i=1; i<B.size(); i++)
        if(isalpha(B[i-1]) && isalpha(B[i]))
            D[(B[i-1]&31)*26+(B[i]&31)]++;
    for(int i=0; i<676; i++) a+=min(C[i], D[i]), b+=max(C[i], D[i]);
    return b ? a*65536/b : 65536;
}
```

이후 다른 사람의 풀이로 `&31`을 통해서 대소문자 구별을 지운 다음 정적 배열로 해당하는 값들을 증가시켜줘서 교집합과 합집합의 카운트를 해준 뒤 연산을 하고 반환해주었다. 매우 참신했고 생각도 못한 방법으로, 전혀 생각하지 못한 방법이었다.

---

- 28日

# 컴퓨터 네트워크

# Congestion Control and Quality of Service

- 혼잡제어는 라우터의 버퍼가 넘치는 경우를 제어해서 없도록 하는 것이다.  
- QOS는 프로토콜 상에선 존재하지 않지만 라우터가 적용할려고 노력한다. 필요하기 때문이다.

## Data Traffic

- 네트워크 혼잡(Congestion)과 품질(QoS)은 사용자로부터 들어오는 데이터 트래픽 양을 조절하거나 서비스 양을 달리하는 것
- 양을 조절하려면 얼마나 어떤 식으로 들어오는 지 정량화 필요
- 가장 간단한 정량화 방법은 평균을 구하는 것이다.
    - `Average data rate = amount of data / time`
    - 문제점 : 평균은 단위 시간에 들어오는 양이 일정할 때 유용하지만 실제 인터넷 트래픽은 그렇지 않다.
    - 인터넷 트래픽은 bursty하다고 할 수 있다.

![image](https://user-images.githubusercontent.com/59367782/97305648-bb3b6d00-18a0-11eb-8138-5a18dd263ae9.png)

### 데이터 트래픽 기술 방법

- 평균의 경우
    - 기준이 되는 시간은 경우에 따라 알맞게 사용한다
        - 과금이 목적 : 시간은 1달
        - TCP 성능 측정이 목적 : 시간은 RTT 시간

- 데이터 트래픽을 기술하는 일반적인 방법
    - 시간 구간에 대해 최대량을 기술
    - Amount = f(t)
        - 함수 f는 non-decreasing function

![image](https://user-images.githubusercontent.com/59367782/97305848-f89ffa80-18a0-11eb-8401-403116e9203a.png)


- 트래픽을 라우터가 쉽게 측정하기 위해서는 간단한 non-decreasing 함수만 사용
    - 가장 널리 쓰이는 형태
        - `Amount = max(line A, line B)`

![image](https://user-images.githubusercontent.com/59367782/97305958-1f5e3100-18a1-11eb-941d-76c5978d7d34.png)

데이터 트래픽 기술 방법은 이해하면 좋다.

### CBR(Constant-bit-rate) traffic

- 90년대에는 네트워크의 망에 맞춰서 비디오 품질을 낮췄다.
- 예전에는 비디오 데이터를 주로 사용했다. 압축하게 되면 매 프레임마다 데이터량이 일정하지 않음
- 억지로 일정하게 하므로 퀄리티가 좋았다가 나빴다가 반복하게 된다.

![image](https://user-images.githubusercontent.com/59367782/97306250-9398d480-18a1-11eb-8f11-af6b5fe7cc65.png)

### VBR(Variable-bit-rate) traffic

- 필요시에 데이터량이 증가했다가 감소한다.
- 비디오 데이터를 VBR traffic으로 그대로 전송하는게 일반적이다.

![image](https://user-images.githubusercontent.com/59367782/97306516-ed999a00-18a1-11eb-8624-335591d12d9e.png)

### Bursty traffic

- 인터넷 트래픽은 이러한 양상을 띔

![image](https://user-images.githubusercontent.com/59367782/97306764-40735180-18a2-11eb-86fa-9ccb2c6dafad.png)

## Congestion

- 혼잡은 네트워크에 걸리는 로드가 네트워크 용량을 초과하면 발생할 수 있음
- 혼잡 제어는 네트워크 용량이 초과될 때 네트워크 처리 용량 한계 이하로 낮추는 매커니즘
    - 네트워크 용량이 초과되는 것을 인지 (타이머를 통해 패킷이 손실된 경우)
    - 진입을 막음
- 혼잡이 발생하는 이유는 고속도로에 많은 차가 진입하면 교통체증을 겪는 것과 동일한 이유
- 라우터 버퍼는 일시적인 혼잡을 해결하기 위한 것
    - 전체적인 입력 데이터 양이 네트워크 처리 용량을 초과하지 않지만 순간적으로 많은 양이 들어오는 것을 처리
    - 따라서 라우터 버퍼는 일시적인 bursty 데이터를 저장할 크기 정도가 적당함

- 패킷의 지연과 네트워크 로드

![image](https://user-images.githubusercontent.com/59367782/97308516-4a964f80-18a4-11eb-884e-fdd58592fb8e.png)

- 입력에 대한 출력 양상

![image](https://user-images.githubusercontent.com/59367782/97308695-80d3cf00-18a4-11eb-878d-ebf74a1cd154.png)

## Congestion Control in TCP

- end-end control로 네트워크의 도움 없이 일어남
- 혼잡제어에 쓰이는 슬라이딩 윈도우는 동적이며 receiver 윈도우보다 작다.
- **sender가 혼잡을 인지하는 방법**
    - packet loss event = TCP의 timeout or 3 duplicate acks (같은 ack가 3번 날라온 경우)
- 혼잡제어 방법
     - **AIMD** (Additive Increase Multiplicative Decrease)
     - **Slow Start**
     - Conservative after timeout events

### TCP AIMD

- Additive Increase : ACK가 잘 돌아오면 혼잡 윈도우 사이즈를 MSS(Maximum Segment Size)씩 증가시킨다.
- Multiplicative Decrease : `packet loss event`가 일어나게 되면 혼잡 윈도우 사이즈를 절반으로 줄인다.
    - 라우터 버퍼가 혼잡이 발생한 시점과 TCP Sender 측에서 혼잡이 인지한 시점의 차이가 있으므로 그 시차간 혼잡의 정도를 상쇄시키기 위해서 절반으로 줄인다.

![image](https://user-images.githubusercontent.com/59367782/97310094-318e9e00-18a6-11eb-8a56-209d537b1e32.png)

### TCP Slow Start

- 처음에는 TCP 연결이 시작하면 혼잡 윈도우 사이즈를 `1`부터 네트워크 최대량까지 눈에 띄게 증가한다. (2의 거듭제곱만큼)
- 이후 loss event가 일어나게 되면 절반을 줄인 뒤 그 다음은 위에서 설명한 양상과 같다.
- 이러한 부분을 설명하기 위해선 FTP로 여러 파일을 전송하는 경우 한 파일을 전송이 끝나고 다음 파일을 전송할 때 TCP 연결이 끊겼다 다시 연결되므로 느리지만, 여러 파일을 압축을 한 뒤 보내면 속도가 일정하게 빠른 것을 알 수 있다.

### 무선환경에서의 TCP 혼잡제어의 문제점

- 유선환경에서는 TCP가 거의 완벽하게 동작
- 무선(wireless) 환경(WiFi, 4G, 5G)에서는 문제가 생김
    - 무선환경은 패킷 전송 오류가 빈번하게 발생
    - TCP Sender는 단순한 패킷 전송 오류를 `혼잡`으로 착각
        - 쓸데없이 전송율을 절반으로 줄임
        - 예) 무선랜 12 Mbps에서 혼자 사용하지만 5 Mbps만 나오는 경우
- 대응 방법
    - 무선환경에 적응하는 Wireless TCP 프로토콜 개발
        - 호환성의 문제점 존재
    - 무선환경 자체에 패킷 전송 오류를 보완하는 방법
        - 패킷 오류가 일어나지 않게 만듬
        1. 프레임에 Forward Error Correction 넣기 : 비트가 깨지면 복원
        2. Transmission Schedule를 통해 기지국에서 오류가 발생한 것을 확인하여 재전송하여 오류를 일어나지 않게 조절함

![image](https://user-images.githubusercontent.com/59367782/97313186-afa07400-18a9-11eb-9f63-55cb456cf4ad.png)

---

- 29일

# 소프트웨어 공학

# 동적 모델링

- 많은 시스템들은 외부와의 반응이 요구되는 시간안에 이루어져야 하기 때문에 시간에 종속적
- 시간과 변호하의 관점에서 시스템을 묘사하는 것
- 동적 모델링에서는 시스템의 제어 흐름, 상호 작용, 동작의 순서를 다루게 되는데, 제어는 외부의 자극에 시스템이 어떠한 동작을 수행하는 지를 나타내는 것

![image](https://user-images.githubusercontent.com/59367782/97529375-21d0a000-19f3-11eb-92cd-0460703fbb60.png)

## 실시간 시스템

- 실시간 시스템은 제한된 시간내에 외부에서 주어진 사건에 응답해야하고 자료를 처리해야 한다.
- 실시간 시스템의 중요성은 빠른 속도로 증가하고 있으며 다양한 분야에서 복잡도가 증가
- **신뢰성**을 가진 실시간 시스템의 개발에 많은 연구와 개발이 이뤄짐
- 특성상 다른 소프트웨어보다 어렵고 복잡하여 다른 시스템에서 요구하지 않는 특수항 분석, 설계, 시험 기법들 필요
- 특징으로는 여러 프로세스를 동시에 병행으로 수행하거나 프로세스의 처리에 우선 순위를 가지며 자원에 대한 동시 접근 및 할당을 하게되고 이를 제어하는 기능이 주어진다
- 대표적인 실시간 시스템은 통신 시스템, 비행기 운행 관리 시스템, 원자력 발전소의 원자로 제어장치, 군사용 미사일 시스템 등

## 상태변화도

상태변화도(STD)란 시스템의 제어 흐름, 동작의 순서를 다룬다. 상태와 사건에 의해 시스템의 제어를 나타내는 **유한 오토마타**를 확장하여 도식적으로 표현한 것이다.  
사건들에 의해 변화하는 시스템의 동작을 나타낸다.

중요한 개념 :
- **상태**
- **사건**

### 전화 시스템의 상태변화도

![image](https://user-images.githubusercontent.com/59367782/97529824-1631a900-19f4-11eb-91f2-95a5b91446c7.png)

시간 상에 따라서 Idle -> Dial tone -> Dialing -> Connecting -> Ringing -> Connected -> Disconnected

## 상태, 사건, 동작

- 상태는 시스템이 가지고 있는 속성값에 의해 결정되며 사건은 외부에서 주어진 자극에 의해 일어난다.
- 사건은 시스템을 어떤 한 상태에서 다른 상태로 이동하게 하여 시스템의 상태를 바꾸게 할 수도 있고 그 외에도 또 다른 사건을 유발시킬 수 있다.
- 사건에 대한 반응은 그 사건을 받아들이는 시스템의 상태에 따라 다르다.
- 시스템의 상태, 사건, 상태의 변화 등이 상태변화도를 통해 구체적으로 나타난다.

**상태**와 **사건** 외에 상태변화도의 개념은 동작이라고 한다.
동작이란 사건과 관련된 것으로, 사건이 시스템의 특정한 상태에서 반응하는 것이다.

### 상태변화도 표기법

- 상태 추상화

![image](https://user-images.githubusercontent.com/59367782/97573387-04b8c300-1a2d-11eb-9094-c084935cb83b.png)

자동차 변속기에 대한 상태변화도로 중립, 후진, 전진 상태로 나뉘어지면 전진은 일단, 이단, 삼단을 묶어서 얘기한다. 해당 버튼을 통해서 상태는 언제나 변화할 수 있다. 일단, 이단, 삼단은 전부 OR 연산으로 이어져있다.

- 동시 수행

![image](https://user-images.githubusercontent.com/59367782/97573429-1ac68380-1a2d-11eb-81eb-eff409e08b67.png)

현금자동 교환기의 상태변화도 중 일부로, 점선을 통해서 카드와 원하는 현금을 내놓는 것을 동시에 수행한다는 것을 표현하였다. 또한 AND 연산으로 이어져있다.

- 조건 표시

![image](https://user-images.githubusercontent.com/59367782/97574124-1f3f6c00-1a2e-11eb-9bbe-916c57b69dbf.png)

온도 조절기의 상태변화도로 여러 조건에 의해서 상태가 온풍, off, 냉방으로 나뉘어질 수 있다.

- 상태의 변이와 동작

![image](https://user-images.githubusercontent.com/59367782/97574211-39794a00-1a2e-11eb-99f1-683381a1f417.png)

차고문의 상태변화도로, 상태에서 변이가 일어날 때 동작에 의해 다른 상태로도 변이할 수 있다.

- 상태와 사건의 일반적인 표기법

    - 동작은 시간이 걸리지 않고 일어나는 작용
    - 활동은 시간을 두고 일어나는 작용

![image](https://user-images.githubusercontent.com/59367782/97574439-95dc6980-1a2e-11eb-9501-064e08689ca7.png)

사건이 일어날 조건과 사건을 `/`을 통해서 묶었다.

## 전화 시스템 동적 모델링

- 쉽고 논리적인 상태변화도를 작성하기 위하여 시나리오 작성과 사건추적 과정을 이용
- 시나리오 : 시스템이 작동하며 일어나느 사건들의 순서. 보통 시나리오의 기술은 일반적인 경우와 예외적인 경우로 나뉘어짐
- 한 시나리오가 시스템의 모든 사건을 포함할 수도 있고 특정한 경우에 나타나는 사건만을 포함할 수도 있다. 따라서 일어날 수 있는 시나리오는 다양함

일반적으로 전화를 거는 경우와 존재하지 않는 번호에 전화를 거는 경우 두 가지로 일반적인 경우와 예외적인 경우를 나눠서 볼 수 있다.  

### 사건추적도

시나리오 작성 후 이것에 대한 사건추적을 하게 되는데 이러한 사건의 순서와 사건을 주고 받는 객체나 시스템을 보여주는 것이 사건추적도이다.  
객체나 시스템은 수직선, 사건은 수평, 사건을 보내는 객체에서 받는 객체로의 흐름은 화살표로 표시한다.  

가장 먼저 할 일은 사건추적에 참가할 객체를 선정하는 것이다. 이때 객체는 시나리오로부터 찾아낼 수 있다. 외부객체도 뽑아낸 뒤 이것들 사이의 사건 흐름을 찾아낸다. 이러한 흐름은 시나리오로부터 찾을 수 있다. 일반적으로 시나리오 하나마다 사건추적이 이뤄진다.  

### 상태변화도 작성

사건추적이 끝난 후 상태들과 사건들을 종합하여 상태변화도를 작성한다. 사건추적에 나타난 사건흐름이 그대로 상태변화도에서 상태변이를 일으키는 사건으로 이용되는 경우가 많다.  
객체에서 주고받는 사건과 사건의 사이가 그 객체의 상태가 되며, 동작과 활동을 추가한다.  

전이에서 나타나는 동작은 동작을 일으키는 사건 뒤에 빗금을 쳐서 표시한다. 위에서 말하였지만 동작은 순식간에 일어나는 작동이며 활동은 시간을 가지며 일어나는 작용이다. 또한 활동은 연속적인 작용을 포함하며 활동의 이름 앞에 `do:`를 표시한다.  

## 구조적 분석기법의 확장

구조적 분석기법은 많은 시스템들은 시간에 종속적이며 데이터는 물론 제어에 관한 정보를 포함하고 있다. 데이터와 이들의 처리 및 그 결과를 돌려주는 환경을 제어할 수 있도록 시스템을 기술한 것이다. 시스템의 상태변화와 프로세스들의 활성화를 나타내고자 할 때 사용한다.  

구조적 분석기법의 확장은 앞의 기능 모델과 동적 모델을 결합시킨 복합 모델로서 한 모델로 두 가지의 다른 면을 표시한다. 이는 한 모델로 한 관점만을 표시하는 단순함에서 탈피하여 한 모델로 두 관점을 합하여 표시함으로써, 두 관점의 연관성을 잘 보여주며 시스템 설계시 통합하기 쉽다는 장점이 있다.

### 복합 분석 모델

![image](https://user-images.githubusercontent.com/59367782/97576307-56fbe300-1a31-11eb-9573-05ea71030251.png)

### 실시간 확장 모델 표시 기호

구조적 분석기법 사용할 때 실시간 확장 모델 표시를 위한 기호표이다.

![image](https://user-images.githubusercontent.com/59367782/97576461-8dd1f900-1a31-11eb-87f6-c08cb5b29db1.png)

- 프로세스 : 시스템 안에서 정보를 처리하고 변환시키는 변환기
- 데이터 흐름 : 정보의 흐름을 표시하는 자료 항목 또는 데이터 단위
- 자료 저장소 : 오랫동안 보관되는 데이터를 저장하는 파일이나 데이터베이스 시스템
- 외부 객체 : 시스템의 외부에서 시스템과 정보를 주고 받는 사용자 등의 외부 객체
- 제어흐름 : 제어 흐름을 표시하는 제어 항목이며 화살표는 제어 흐름의 방향을 표시한다.
- 제어 명세 : 제어 신호를 처리하고 변환시키는 제어 명세서이다.

### 제어 명세서(Control Specification)

제어 명세서는 프로세스 명세서가 초보기능을 수행하는 프로세스를 기술하는데 이용된다. 따라서 시스템의 행위를 기술하는데 사용된다. 이러한 제어 명세서는 다양한 제어 흐름에 어떠한 동작 시나리오가 발생되었는지 보여준다.  

제어 명세서는 시스템의 동작을 잘 나타내 주어, 시스템 개발 초기에 문제점과 개발 후 시스템의 동작에 결함이 있는지를 쉽게 파악, 확인할 수 있게 해준다. 자료흐름도에서는 수직선 기호로 표시되어 있다.

- **프로세스활성표** (PAT : Process Activation Table)
- **결정표** (DT: Decision Table)
- **상태변화도** (STD: State Transition Diagram)
- **상태사건표** (SEM : State Event Matrix)

### 정보 흐름

- 데이터는 계산에 사용되어 새로운 데이터를 생성하거나 이를 변형시킬 때 사용
- 제어는 계산에 직접 사용되지 않는 대신 계산의 순서나 조건을 나타냄

연속적인 신호는 일반적으로 데이터로 분류된다. 그리고 이산 신호의 경우 프로세스 안에서 계산에 쓰이면 데이터, 프로세스를 제어하는데 사용되면 제어로 간주된다. 어떠한 신호는 양쪽으로 모두 분류될 수 있으며, 분류가 확실치 않으면 데이터로 가정한 다음 모델링을 구체화시켜 가며 그 결과를 확인해 볼 수 있다.  

제어 논리는 **조합 논리**와 **순열 논리**로 나눠서 볼 수 있다.  

- 순서에 상관없이 원하는 결과가 나타나면 조합논리
- 순서가 중요시 되는 순열논리

### 프로세스 활성표

프로세스 활성표는 주어진 사건에 의해 특정 프로세스를 활성화시키는 동작을 기술하는데 사용된다. 자료흐름도에 나타난 프로세스를 활성화 또는 비활성화시키기 위해 어떠한 입력 제어흐름값이 주어져야 하는지를 **테이블 형태**로 표시한다.  

### 결정표

시스템 제어의 표시는 프로세스 활성표만으로 충분치 못한 경우가 많다. 입력 제어 흐름을 수용하여 시스템이 사용하기 쉬운 새로운 흐름을 만들어 내는 경우가 흔하다.  

결정표는 한 프로세스와 연관된 모든 동작을 표시하거나 프로세스 수행 중 요구된느 결정이나 조건을 기술하는데 사용한다. 입력 제어 조건들의 순서는 고려하지 않는 조합 논리를 나타내는데 적합하며 출력값을 갖기 위해 요구되는 입력값을 테이블 형태로 나타낸다.

예를 들어 신호등 시스템의 결정표를 보면 보행자의 요구와 자동차가 접근이 동시에 일어나면 보행자에게 우선순위를 줘서 보행자에게 초록불을 켜주는 식이다.  

### 상태변화도

상태변화도가 구조적 분석 확장 모델에서 사용되는 방법만 알아보고, 이 부분에서는 크게 다루지 않는다. 순열 논리를 나타내는데 적합하다.

### 상태사건표

상태사건표는 상태변화도에 표현되어 있는 정보를 테이블 형태로 표현한 것이다. 열은 사건들을 표시하고 행은 상태를 나타낸다. 주어진 상태에서 어떤 사건이 발생되면 동작을 취하게 되고 새로운 상태로 옮겨가는 모습을 보여준다.

### 복합 제어 명세

여러 제어 명세가 혼합되어 시스템의 제어 기능을 나타내야 되는 경우, 프로세스 활성표, 결정표, 상태변화도, 상태사건표가 복합적으로 한 자료흐름도에 표시 될 수 있다.

## 요약

- 실시간 시스템의 중요성이 빠른 속도로 증가하고 있으며 다양한 응용 분야에 확산
- 실시간 시스템 개발에 동적 모델링은 중요한 역할 담당
- 동적 모델링은 시스템의 제어 흐름, 상호 작용, 동작의 순서 등을 다룸
- 실시간 시스템은 특서상 다른 소프트웨어 시스템보다 복잡하며 다른 시스템에서 요구하지 않는 특수한 분석, 설계, 시험 기법 등 필요

상태변화도를 중심으로 동적 모델링을 살펴봤고 구조적 분석기법에 시스템의 동적인 면을 추가한 확장 모델을 이용한 실시간 시스템 분석기법을 알아보았다. 

---

- 30日

# 소프트웨어공학

# 정보 모델링

다수의 소프트웨어 시스템은 데이터베이스에 기초하고 있으며 많은 데이터를 처리하고 의사결정을 지원해주어야 한다.  
**정보 모델**은 시스템에 사용되는 정보 데이터를 중심으로 시스템의 정적인 정보구조를 나타내는 데 사용한다. 정보 모델링은 시스템에 필요한 **엔티티**들을 정의하고 이들 엔티티 사이의 연관성을 규명하는 작업이다. 이 모델은 시스템의 기능이나 동작에 초점을 맞추기보다는 시스템을 구성하고 있는 객체를 중심으로 객체의 특성을 정의한다.

## 개요

정보 모델링은 시스템에 사용되는 데이터 베이스의 구조를 알아내어 데이터를 개념적 차원에서 기술한다. 사용자의 관점에서는 시스템의 데이터가 저장되고 유지되는 것은 알 필요 없다. 개념적 차원에서의 기술이란 구현에 관한 세부 사항을 숨겨줌으로써 시스템의 데이터에 관한 요구사항만 기술한다.

따라서 정보 모델링은 데이터의 추상적인 면, 즉 사용자 관점만 표시한다. 구체적인 구현에 관한 세부 사항을 감춤으로써 복잡도를 관리할 수 있게 해야한다. 정보 모델링 중에서 가장 많이 사용되는 도구는 EER(Enhanced Entity-Relationship)모델이다.

## 엔티티, 속성, 엔티티 타입

- EER 모델은 시스템에 요구되는 기본적인 객체를 나타내는 엔티티와 객체들 사이의 연관성을 나타내는 관계로 구성되어 있다.  

- 엔티티는 독립적으로 존재하는 실세계의 사물, 객체를 나타낸다.

- 각 객체는 특정 속성의 모임에 의해 기술되며 속성값들에 의하여 다른 객체와 구별된다.

### 엔티티 타입

한 시스템 안에 같은 속성을 가지는 엔티티들의 집합을 엔티티 타입이라고 한다. 시스템에 요구되는 데이터의 특성을 규명할 경우에는 각각의 객체들을 기술하는 것보다 묶어진 엔티티 타입을 기술하는 것이 편리하다.  

- 분류화(classification) : 비슷한 엔티티를 묶는 작업으로, 분류화를 통해 묶여진 객체들은 같은 종류의 속성, 제약조건 및 동작의 유형을 공유
- 실례화(instantiation) : 분류화의 역작용으로 엔티티 타입에 속해있는 엔티티를 구별하여 참조하는 데 사용된다.

### 용어 비교

| 분야 | 예시 (대학교) | group |
|---|---|---|
| 정보 모델링, 데이터 베이스 | 엔티티 | 엔티티 타입 |
| 프로그래밍 언어 | 변수, 상수 | 데이터 타입 |
| 객체 지향 모델링 및 언어 | 객체(object) | 클래스 |
| 예(대학교) | 김철수, 이영희 | 학생 |

### 키(key) 개념

정보 모델링에 사용되는 중요한 개념 중의 하나로, 각각의 사람들이 구별되어야 하는 것 처럼 각각의 엔티티는 구별되어야 하며 각가의 엔티티를 구별할 수 있는 속성들의 모임이다.  

키의 값에 의해 각 엔티티는 유일하게 지정된다. 경우에 따라서 여러 속성이 모여서 키를 형성하는 경우도 있다. 이러한 경우 속성들의 집합이 키가 되어 각 엔티티를 유일하게 지정한다. 어떤 데이터 타입은 하나 이상의 키를 가질 수도 있다. 그 중 하나는 주 키(primary key)가 되며 나머지는 대체 키(alternate key)가 된다.

### EER 모델 표시법

사각형의 기호는 엔티티 타입, 타원형의 기호는 속성을 나타낸다. 선은 속성과 엔티티 타입을 연결하고 키 속성은 밑줄을 그어 구별한다. 또한 관계는 마름모로 표시한다.

일반적으로 데이터베이스에서 많이 사용하는 모델로 설계할 때 모델을 테이블이 아닌 이러한 모델로 표현을 많이 한다.

## 관계, 관계 타입, 제약조건

한 시스템이 여러 엔티티 타입을 갖는 것은 일반적이며 이들 사이에는 연관성이 존재한다.

- 관계 : 여러 엔티티 사이에 존재하는 연관성
- 관계 타입 : 같은 형태를 갖는 관계들의 집합

### 관계 타입

엔티티 타입과 맘찬가지로 고유의 속성들을 가질 수 있으며 참여하는 엔티티 타입의 키가 관계 타입의 키가 된다. 경우에 따라서는 참여하는 엔티티 타입의 키 이외에 다른 속성이 합쳐져 관계 타입의 키를 형성한다. EER 모델에서는 마름모 기호로 관계를 표시한다.

### 매핑 제약조건

EER 모델은 데이터들 사이에 지켜야할 제약조건을 지정할 수 있다. 매핑 제약조건은 하나의 관계 타입을 통하여 참여하는 데이터 타입에 속한 엔티티들 사이에 맺어질 수 있는 매핑 수를 제한한다.

- 일대일(one to one)
- 일대다(ont to many)
- 다대다(many to many)

### 참여 제약조건

한 엔티티가 관계에 참여하는 것이 필수인지 선택인지를 지정하여 주는 제약조건이다.

### 참조 무결성

두 엔티티 사이의 관계에 작용하는 제약조건으로 데이터의 일관성을 유지하기 위하여 필요하다. 관계에 속하는 데이터 중에서 참여 엔티티에서 오는 키의 속성값은 참여 엔티티에 있는 키의 속성값이어 함을 의미한다.

특히 관계형 데이터베이스에서 테이블 사이의 데이터 제약조건을 나타내는 것으로 중요한 의미를 가진다. 한 테이블에 있는 튜플은 다른 테이블에 있는 튜플을 참조하게 되고 이 때 다른 테이블에 존재하는 튜플만을 참조할 수 있음을 나타낸다.

### 관계 타입 차수

참여하는 엔티티 타입의 수로 일반적으로 3차 관계 타입은 2차 관계 타입들로 대치될 수 없다.  

- 2차 관계 타입 

![image](https://user-images.githubusercontent.com/59367782/97698128-65a6d080-1aeb-11eb-93e8-97d9b54b45d4.png)

- 3차 관계 타입

![image](https://user-images.githubusercontent.com/59367782/97698154-70f9fc00-1aeb-11eb-851e-dae2805a9a4a.png)

## 일반화 (Generalization)

엔티티 타입 사이에 유사성이 존재할 때 이 유사성을 모아 하나의 새로운 엔티티 타입을 정의내리는 것을 일반화라고 한다. 각 엔티티 타입은 고유의 속성을 가지고 있으며, 여러 엔티티 타입에 공통된 속성 또한 존재할 수 있다.  

- 상위 클래스 : 하위 클래스의 공통적인 속성을 갖는다.
- 하위 클래스 : 상위 클래스의 주 키와 하위 클래스 간의 공유되지 않는 정보를 갖는다.
- 상위 클래스에 있는 모든 속성은 하위 클래스에 상속
- 일반화의 관계는 `is_a` 또는 `kind_of` 관계

### 일반화와 특수화

클래스들 사이의 유사성을 표시하는 기법이 **일반화**로, 상위 클래스에 하위 클래스의 공통적인 속성을 표시하고 상위 클래스의 정보가 하위 클래스에 상속된다. 여기서 상속은 엔티티 타입의 정의를 단순화시키고, 기존에 정의되어 있는 엔티티 타입을 이용하여 새로운 클래스를 쉽게 정의할 수 있도록 해준다. 이러한 기법은 엔티티 타입의 공통점을 구체적으로 표시하는 기법이며 분석의 결과를 재사용할 수 있게 해준다.

**특수화**는 일반화의 역진행으로 한 엔티티 타입이 세분화된 하위 클래스로 나뉘어진다. 특수화를 통해 하위 클래스로 정의될 수 있는 경우는 하위 클래스가 고유의 속성을 가지고 있거나 하위 클래스가 다른 클래스들과 고유의 관계를 가지고 있을 때만 가능하다.

일반화를 통해 다계층 구조를 만들어갈 수 있으며 이 경우 한 하위 클래스는 구조상에 있는 모든 상위 클래스의 속성을 상속받는다.

### 중복성과 완전성

상위 클래스와 하위 클래스의 관계는 중복성과 완전성 제약조건에 의해 표시된다.
- 중복성 : 중복과 해체로 구분
- 완전성 : 전체와 일부로 구분

상위 클래스의 모든 엔티티가 하위 클래스에 꼭 존재하면 전체 관계에 있다고 하며 하위 클래스에 항상 있는 경우가 아니라면 일부 관계에 있다.

- 중복, 전체 특수화 `S+`
- 중복, 일부 특수화 `S`
- 해체, 전체 특수화 `SE+`
- 해체, 일부 특수화 `SE`

### 제약 조건과 설계

중복성 제약족건과 완전성 제약조건은 데이터베이스를 설계할 때 중요한 영향을 미친다. 객체지향 언어인 c++의 경우 전체 제약조건이 있는 경우 그 자체가 하위 클래스에 속하지 않는 독립적인 객체를 가지지 못함으로 이러한 상위 클래스를 추상 클래스라 부른다. 그리고 상위 클래스를 베이스 클래스(base class), 하위 클래스를 유도된 클래스(derived class)라고 부른다.

## 역할

클래스들 사이의 또다른 계층 구조를 나타내며 2개 또는 그 이상의 상위 클래스의 합집합으로 이뤄진 하위 클래스를 정의할 떄 사용한다. 역할이 사용되는 대부분의 경우 하위 클래스의 엔티티는 상위 클래스 중 오직 하나에 속한다. 따라서 선택적 상속이라고도 불린다.

### 역할과 일반화

역할 관계는 일반화와는 구별되는 개념이며 특수한 조건이 만족되면 일반화로 나타내어질 수 있다. 만약 역할 관계에 있는 모든 상위 클래스의 엔티티가 하위 클래스에 속하고 모든 상위 클래스가 같은 키 속성을 공유하면 역할 관계는 일반화의 관계로 나타낼 수 있다.  
결국 역할에 속한 하위 클래스를 정의할 때 상위 클래스의 키를 사용하기 어려워 새로운 키를 정의하게 되고 이를 대리 키라고 부른다.

## 정보 모델링의 예

대학교 데이터베이스에 포함되어야 하는 요구사항 : 

대학교에서는 학생들의 주민번호, 이름, 학번, 학년, 전공, 주소와 전화번호가 있다. 이 중 주민번호 이나 학번에 의해 각 학생들이 유일하게 구분된다.

각 과목은 과목 이름, 과목 번호, 학점수, 과목 수준을 가지며 과목 번호에 의해 유일하게 구분된다. 각 과목은 선수과목을 가진다.

각 교수는 주민번호, 이름, 주소, 전화번호, 전공분야가 필요하며 주민번호로 유일하게 구분된다. 그리고 각 학생들은 지도교수를 1명씩 갖는다.

각 섹션은 강의 교수, 학기, 연도, 섹션 번호, 과목 정보를 갖는다. 섹션 번호에 의해 각 섹션은 유일하게 구분된다. 학생들은 섹션을 수강하여 학점을 얻으며 각 섹션은 최소한 7~30명의 학생이 수강한다.

### 엔티티 타입 규명

엔티티 타입은 요구사항에서 명사로 표시되어 있으며 독립적으로 존재하고 우리가 추적해야할 필요가 있는 객체들의 모임이다. 필요로 하는 엔티티 타입을 요구사항에서 뽑아내야한다.

### 엔티티 가이드라인

엔티티 또는 엔티티 타입을 찾아내기 위해 앞에서와 같이 문제 기술을 읽거나 사용자와 인터뷰를 하는 것이 일반적이다. 또한 개인적인 지식이나 현재 보유하고 있는 파일, 업무진행 과정을 보여주는 도표도 활용될 수 있다.

*엔티티를 찾아내는 가이드라인*
1. 문제 기술에 명사가 있으면 엔티티로 고려
2. 만약 명사가 값을 가질 수 있으면 엔티티가 아니라 속성이 됨
3. 만약 분석가가 정보를 추적하고 싶으면 엔티티로 고려
4. 만약 엔티티인지 속성인지 구별이 가지 않는 경우 엔티티로 놓기.
5. 만약 데이터의 이름이 _id, _number, _code, _type 등으로 끝나면 엔티티 타입의 키가 될 가능성이 높음
6. 데이터에 관한 정의가 현재 있는 경우 그 데이터를 포함하고 있는 엔티티의 이름을 쉽게 찾을 수 있다.

또한 모델링을 하며 각 속성의 속성 값을 사용자에게 문의하여 가능한 값을 알아놓는 것이 바람직하다.

### 관계 가이드라인

관계 타입은 일반적으로 동사로 표시한다. 실제 관계 타입의 이름을 정할 경우 동사의 명사형을 쓰는 것이 바람직하다.

*관계(또는 관계 타입)를 찾아내는 가이드라인*
1. 문제 기술에 동사가 있으면 관계로 고려
2. 만약 불명확한 엔티티가 있으면 관게로 고려
3. 만약 데이터가 독립적인 두 엔티티를 기술하고 있으면 관계로 고려
4. 한 레코드가 둘 이상의 고유 번호(unique id)를 가지고 있으면 관계로 고려

이들 관계 타입의 매핑 제약조건과 참여 제약조건은 요구사항에 명시되어 있지 않은 경우가 많으므로 분석가는 이 시스템을 사용할 사용자들과 대화하여 구체적인 요구사항과 제약조건을 밝혀내야한다.

## 요약

- 현재 정보가 중요한 자산으로 인식되는 정보화 시대로 빠르게 옮겨가고 있으며 정보의 중요성은 나날이 증가
- 정보 모델링은 우리가 필요로 하는 정보를 체계적으로 구성할 수 있게 하여주며 다양한 역할을 수행하는 프로젝트 참여자들이 공통의 대화 수단으로 사용
- EER 모델은 가장 많이 사용되는 정보 모델링 도구이며 시스템에 요구되는 기본적인 객체를 나타내는 엔티티와 객체들 사이의 연관성을 보여준다.
- 각 객체는 특정 속성의 모임에 의해 기술되며 속성의 값에 의해 다른 객체와 구별
- 유사한 속성을 갖는 엔티티를 분류하여 엔티티 타입이 정의되고 엔티티 타입에 속한 엔티티들은 같은 종류의 속성, 제약조건 및 동작의 유형을 공유
- 정보 모델링의 결과는 물리적 데이터베이스(예: 관계형 데이터베이스)를 설계하는데 기본 골격을 제공
- 또한 정보 모델링은 여러 시스템의 데이터를 통합하는 시스템 통합 과정에서 필히 요구되는 도구

---

- 31日

# 소프트웨어 공학

# 객체지향 분석기법

## 객체지향 배경

객체지향 개발 방법론은 소프트웨어 위기를 극복하기 위한 개발 방법 중 가장 최근에 나타난 것으로, 현재까지 나타난 소프트웨어 개발의 문제점을 해결해줄 많은 장점을 보유하고 있다.

시스템은 요구사항 변경을 수용할 수 있어야 하며 이를 위해 유연성과 적응력을 갖도록 설계되어야만 한다. 그러나 현재 까지의 개발 방법으로는 시스템의 확장이나 변경이 용이하지 못해 많은 어려움을 겪고 있으며 이를 극복할 수 있는 매우 유용한 방법론이다.

객체지향 방법론은 데이터와 행위를 하나로 묶어 객체를 정의내리고 객체를 추상화시키는 작업이라고 할 수 있다. 객체지향 개발은 기존의 데이터와 행위가 분리되었던 개발 방법의 복잡성과 통합의 어려움을 극복하려는 데 있다.

### 객체지향 3관점

- 객체(정보) 관점
- 기능 관점
- 동적 관점

객체, 기능, 동적 모델링 각각 순서대로 적용되어 시스템에 요구되는 객체를 설명할 수 있다.

## 객체지향 분석방법 개요

객체지향 개발 방법은 우리가 태어나면서부터 배워온 객체 개념에 기초한다. 우리 인간은 자라면서 상대방을 인식하고 그의 속성을 찾아내고 그와의 관계를 알아낸다. 인간이 살아가는 과정은 자신과 다른 사람과의 관계를 넓혀 가는 객체지향 과정이다.

객체지향 개발 방법은 객체와 그의 속성과 동작, 유사한 객체의 집합으로 나누어진 클래스, 객체 사이의 관계 등을 기본 개념으로 한다. 객체지향 개발 방법은 객체지향 분석, 설계, 프로그래밍, 테스트로 이어져 소프트웨어 개발 전 과정에 걸쳐 동일한 방법론과 표현 기법이 적용될 수 있는 장점이 있다.

특히 객체지향 분석기법은 기존의 분석기법에 비해 실세계의 현상을 보다 정확히 모델링 할 수 있어 어려운 응용 분야들에 적용이 가능하다. 분석과 설계의 표현에 큰 차이점이 없어 시스템의 개발을 용이하게 해준다. 또한 분석, 설계, 프로그래밍의 결과가 큰 변화 없이 재사용될 수 있어 확장성이 용이하고 시스템 개발시 시제품이나 나선형 패러다임의 적용이 가능하다.

객체지향 개발 방법은 프로그래밍 기법만이 아니며 시스템 개발에 있어 근본적인 사고의 변환을 요구하는 새로운 기법이다. 객체지향 분석은 만들고자 하는 시스템을 객체 중심으로 기술하게 되며 이는 우리가 주로 해왔던 하향식방식과는 근본적으로 다르다.

객체지향 방법론은 객체 중심의 상향식 접근 방법이 도입되고, 기능 중심이 아니라 정보 중심, 데이터 중심으로 시스템의 개발이 이루어진다. 객체지향 개발 방법은 기존의 정보 모델링에 기초하고 있으며 여기서 나타난 객체의 정적인 정보에 객체의 동작을 추가시켜 **객체를 완벽하게 기술하고 구현하는 방법론**이다.

### 3가지 관점 통합

객체지향 방법론은 3가지 관점을 체계적으로 통합하여 유연성과 적응력을 가진 우수한 품질의 소프트웨어를 만들 수 있는 최적의 방법으로 여겨지고 있다.

객체지향 분석기법은 시스템의 요구사항을 분석하기 위해 앞에서 다룬 세 가지 모델링 기법을 단계별로 적용하여 그 결과를 통합한다.

`객체지향 분석기법(OMT) = 객체 모델 + 동적 모델 + 기능 모델`

### 객체지향 분석의 3 관점

1. 객체 모델링 : 정보 모델링이라고도 부르며 시스템에서 요구되는 객체를 찾아내어 객체들의 특성과 객체들 사이의 관계를 규명
2. 동적 모델링 : 객체 모델링에서 규명된 객체들의 행위와 객체들의 상태를 포함하는 라이프 사이클을 보여줌
3. 기능 모델링 : 각 객체의 형태 변화에서 새로운 상태로 들어갔을 때 수행되는 동작들을 기술하는데 사용

객체지향 개발 방법은 소프트웨거 공학에서 추구하는 많은 장점들을 제공한다. 객체지향 개발 방법을 제대로 활용하기 위해서는 기존의 기술과는 다른 높은 차원의 기술력을 분석가나 디자이너에게 요구한다. 소프트웨어 개발 과정에 대한 이해와 정보 모델, 동적 모델, 기능 모델에 대한 지식이 있어야 하며 모델들 사이의 연관성을 바탕으로 모델링의 결과를 통합할 수 있어야 한다.

## 객체 모델링

객체 모델링은 시스템에 요구되는 객체들을 보여줌으로써 주로 시스템의 정적인 구조를 포착하는 데 사용한다. 세 가지 모델링 중 객체지향 분석에서 가장 중요하며 선행되어야 할 모델링이다.

객체 모델링의 복잡도를 관리하기 위해 정보 모델링에서 언급된 **추상화**, **분류화**, **일반화**의 개념들이 사용된다. 또한 집단화 개념이 추가되어 다양한 객체들을 모아 더 높은 단계의 객체를 추출하는 작업이 이뤄진다.

객체 모델링은 시스템의 요구사항을 기술한 문제 기술로부터 시스템에 요구되는 객체들을 추출한다. 객체들이 발견된 다음 객체들 사이의 연관성을 찾아내고 객체들을 정의하기 위한 속성 추가한다.

### 객체지향의 용어

- 객체
- 클래스
- 속성
- 동작
- 일반화
- 특수화
- 집단화
- 상위클래스
- 하위클래스
- 상속
- 재사용

### 객체와 클래스

객체는 객체 모델링의 기본 단위이며 유사한 객체들의 모임이 클래스다. 앞에서 다룬 정보 모델링의 엔티티와 엔티티 타입에 해당한다. 객체는 가장자리가 다듬어진 사각형, 클래스는 사각형으로 표시한다.

### 클래스의 관계

클래스들 사이의 연관성은 관에 의해 표시되며 정보 모델링에서는 이름으로 표시된다. UML에서는 그 관계를 단순히 관계 이름만으로 표시할 수 있다. 만약 관계가 새로운 속성이나 동작을 가질 경우 클래스들 사이에 관계 속성을 표시하면 된다.

경우에 따라서 관계를 한 클래스로 모델링하는 것이 효과적인 경우가 있다. 이런 경우 관계는 하나의 클래스로 정의되어 속성과 동작을 가지게되며 다른 새로운 클래스와 연관을 맺을 수 있다.

### 매핑의 제약조건

기호는 클래스들 사이에 맺어질 수 있는 관계를 통해 객체들이 지켜야 하는 제약조건을 지정하는 것으로, 각 클래스의 객체들 사이에 맺어질 수 있는 매핑 제약조건과 참여 제약조건은 정보 모델링에서 다루어진 개념과 동일하다.

UML에서 표기하는 기호

- 1-1 : 일대일 (필수)
- 1-0..1 : 일대일 (선택)
- 1-* : 일대다 (0 or more)
- 1-1..* : 일대다 (필수)

### 일반화

유사한 클래스들 사이의 공유되는 속성과 동작을 묶어주며, 다른 한편 그들 사이의 다른 점을 보존할 수 있게 해주는 효과적인 추상화 기법이다. 일반화는 클래스들 사이의 특수한 관계로 볼 수 있으며 앞의 EER 모델에서도 이 개념이 소개된 바 있다.

**일반화**를 통해 클래스들 사이의 계층 구조가 만들어지며 각 하위 클래스는 상위 클래스의 속성, 동작, 그리고 다른 클래스와의 연관성을 상속받는다. 일반화를 통해 공통의 정보는 오직 한 번 정의 될 수 있어 분석의 결과를 재사용할 수 있게 해주며 데이터의 무결성을 향상시켜준다.

**특수화**는 일반화의 역작용으로, 특수화를 통해 하위 클래스로 정의되는 경우는 하위 클래스가 고유의 속성이나 동작을 가지고 있거나 하위 클래스가 다른 클래스들과 고유의 관계를 가지고 있을 때이다.

### 클래스의 일반화

일반화는 `is_a` 또는 `kind_of` 관계이며 각 하위 클래스의 인스턴스는 상위 클래스의 인스턴스가 된다. 일반화를 통해 다계층 구조를 만들어 나갈 수 있으며 이 경우 한 하위 클래스는 이 구조상에 있는 몯느 상위 클래스의 속성과 동작을 상속받는다.

### 다중 상속

하위 클래스는 두 개 이상의 상위 클래스에서 동시에 속성과 동작을 상속받는다. 이러한 현상을 다중 상속이라고 하며, 다중 상속으으로 인하여 분석 과정에서 모순이 발견될 수 있다. 모순이 속성이나 동작에서 감지되면 모호성을 없애기 위해 요구사항 명세서나 자료 사전에 이를 기록해야 한다.

### 집단화

클래스들 사이의 `부분-전체` 관계 또는 `부분` 관계로 설명되는 연관성을 나타낸다. 집단화는 여러 부속 객체들이 조립되어 하나의 객체가 구성되는 것을 의미한다.

집단화는 앞의 EER 모델에서는 구체적으로 나타내지 않던 개념이며 객체지향 기법에서는 활발히 사용되고 있다. 집단화 기호는 조그만 마름모 기호로 표시되며 매핑 제약조건과 참여 제약조건에 대한 기호는 일반화의 경우와 동일하다.

### 객체들 사이의 연관성

문제 기술에는 자세한 사항이 나와있지 않아 사용자와 상의하여 연관성과 구체적인 요구사항 규명해야 한다.

### 클래스의 속성

클래스와 클래스들 사이의 연관성이 밝혀진 다음 클래스의 특징을 밝혀주는 속성과 동작들이 밝혀져야 한다. 객체 모델링에서는 속성에 우선 초점을 맞추게 된다.

### 예시

현금 자동 지급기의 예시를 들면 
- ATM 시스템 문제 기술의 일부 : ATM은 은행 직원의 도움 없이 현금을 찾을 수 있게 해주는 장치이다. ATM은 현금카드를 받아들여 고객이 가지고 있는 구좌에서 현금을 지급하고 영수증을 출력한다. 은행은 고객의 구좌를 관리하며 ATM은 은행에 소속되어 있다.

- 문제 기술에서 요구되는 객체들
    - ATM
    - 현금 카드
    - 고객
    - 계좌
    - 은행

객체들 사이의 연관성을 사용자와 상의하여 연관성과 구체적인 요구 사항을 규명한다.

마지막으로 각 객체에 속성을 적게된다.

## 동적 모델링

객체 모델링을 통해 시스템에 요구되는 객체들의 구조와 객체들 사이의 관계 정립한다. 그 다음 시간의 흐름에 따른 객체들과 객체들 사이의 변화를 조사하게 되며 이를 **동적 모델링**이라고 한다.

동적 모델링은 객체들 사이의 제어 흐름, 상호 작용, 동작의 순서 등을 다룬다. 동적 모델의 중요한 개념은 상태, 사건, 동작 등이 있다.

객체지향 분석의 특징은 시스템에 요구되는 객체를 우선 구한 후 객체들의 동적인 면을 찾아내기 위해 동적 모델링을 적용한다는 점이다. 동적 모델은 다음에 나올 기능 모델과 관계가 있으며 시스템의 동작은 기능을 수행하기 위해 필요하다.

제안서로부터 객체 또는 시스템의 한 실행 과정을 사건들의 흐름으로 표시하는 시나리오를 만든다. 각 사건들은 객체 모델링에서 규명된 객체들 사이의 정보 흐름을 나타내게 되고 각 사건의 정보를 보내는 객체와 정보를 받는 객체가 밝혀진다.

사건의 순서와 사건을 주고받는 객체들이 사건추적도에 나타나게 되며 수직선은 객체를 표시하고 수평 화살표는 사건의 흐름을 나타낸다. 사건은 위에서 아래로의 순서에 의해 수행된다.

시나리오는 1~21번까지 쓰일 수 있고, 객체들과 사건의 흐름을 보여주는 시퀀스 다이어그램은 다음과 같다.

![image](https://user-images.githubusercontent.com/59367782/97780500-76794400-1bc8-11eb-8d3d-118de5bce3f7.png)


자동지급기의 상태변화도는 다음과 같다.

![image](https://user-images.githubusercontent.com/59367782/97780602-fa333080-1bc8-11eb-962c-a2f0384523f8.png)

계좌의 상태변화도는 다음과 같다.

![image](https://user-images.githubusercontent.com/59367782/97780669-50a06f00-1bc9-11eb-9055-97b88444819c.png)

## 기능 모델링

객체지향 분석기법에서 객체 모델링, 동적 모델링에 이어 시스템을 기술하는 세 번째 단계이다. 기능 모델은 입력값으로부터 계산을 거쳐 어떤 결과가 나타나는지를 보여주고, 이것이 어떻게 유도되었는지의 구현 방법은 고려하지 않는다. 또한 앞에서 다룬 기능 모델링과 마찬가지로 자료흐름도(DFD)를 사용할 수 있다.

DFD의 경우 입력 흐름은 프로세스를 통해 변환되어 출력 흐름으로 바뀌고, 다른 프로세스의 입력이나 외부로의 출력으로 작용한다.

기능 모델은 동적 모델링에서 나타난 동작 어떠한 기능으로 이루어져 있는지 보여주며 자료흐름도의 정보 흐름은 객체에 해당된다.

### 계좌 변경 동작의 기능

액티비티 다이어그램으로 표현할 수 있다.

![image](https://user-images.githubusercontent.com/59367782/97780768-f0f69380-1bc9-11eb-8efd-8187564d68a0.png)

## 객체지향 설계

분석 단계를 통해 앞으로 논의된 세 가지의 서로 다른 모델이 순서대로 개발된다. 세 모델을 하나로 통합하는 작업이 이뤄져야 하며, 이 단계는 일반적으로 **객체지향 설계단계**에 해당된다. 세 모델의 통합은 객체의 정적인 구조와 오퍼레이션을 함께 포함하여 객체를 정의하는 것을 의미한다. 이는 동적 모델의 사건, 동작 및 활동을 객체의 오퍼레이션에 매핑하고, 기능 모델의 프로세스를 객체 모델의 오퍼레이션에 통합시키는 것이다.

객체 수준의 **상태변화도**는 한 객체가 생명주기 동안 가질 수 있는 상태들을 기술 해준다. 상태의 변환은 객체의 오퍼레이션으로 매핑된다. 유사한 방법으로 객체에 주어진 사건은 다른 객체의 동작으로 나타내질 수 있다. 한 사건은 이전 사건에 의하여 초기화된 활동의 결과이며, 동작과 이에 반응하는 동작으로 매핑될 수 있다.

### 모델의 통합

자료흐름도는 다른 두 모델과 연관성을 가지고 있으며 상태 변환에 의하여 이루어진 동작은 기능 모델의 자료흐름도와 연관을 가질 수 있다. 이 경우 서로 연결되어 있는 프로세스의 집합들은 동작의 구체적인 목적을 표시해 준다. 

자료흐름도의 프로세스들은 상태변화도의 동작에 의하여 수행되는 하위 기능으로 나타내진다. 이들 동작의 일부는 자신에게 작용하는 동작일 수 있고 다른 객체에 보내지는 동작일 수도 있다.

대상객체는 오퍼레이션이 정의되고 속하여 있는 객체를 의미한다. 만약 프로세스가 입력흐름을 갖는다면 입력 흐름이 대상 객체가 될 수 있고 이 프로세스는 대상 객체의 오퍼레이션이 된다.

프로세스가 여러 입력 자료 흐름으로부터 하나의 출력값을 생성한다면 이 프로세스와 연관된 동작은 출력 클래스에 적용되는 동작으로 해석될 수 있다.

프로세스가 자료저장소나 외부 객체의 데이터를 읽거나 결과를 저장하는 경우, 자료저장소나 외부 객체가 이 오퍼레이션의 대상 객체가 된다. 이러한 가이드라인을 이용하여 객체 모델에 동적 모델과 기능 모델을 통합한다. 

그 결과는 객체에 속한 모든 가능한 정보, 객체들 사이의 관계, 객체의 오퍼레이션들을 나타낼 수 있게 되어 시스템에 대한 완벽한 기술이 이뤄진다. 객체들 사이의 관계는 상대 객체를 나타내는 포인터 변수를 객체의 속성으로 나타냄으로서 이뤄질 수 있다.

## 요약

- 객체지향 개발 방법은 시스템의 **확장**이나 변경을 쉽게 할 수 있는 뛰어난 기법으로 인식
- 객체지향 분석기법은 기존의 분석기법이 가지고 있는 한계점을 극복하고 시스템의 **3가지 관점을 체계적으로 통합**하여 기술하고, 확장성과 적응력이 뛰어난 시스템을 설계하는 것이 그 목적
- 객체지향 분석기법은 상향식 접근 방법이라 여겨질 수 있으며 이는 구조적 기법이 **순수 하향식**인 것과 대조
- 객체지향 개발 방법은 상향식 기법에서 발견되는 많은 장점 보유
- 객체지향 개발 방법은 우선 시스템에서 사용되는 데이터에 초점을 맞추기 때문에 변화에 잘 견디는 우수한 품질의 소프트웨어르 만들 수 있다.
- 객체지향 분석의 결과는 설계로 넘어가 큰 변화 없이 사용되며, 앞의 세 모델의 결과가 통합되어 완벽한 객체와 클래스의 구현이 가능하게 된다.

- 객체지향 개발 방법은 시스템의 **확장성이 용이**하고 엔지니어링의 결과를 **재사용**할 수 있어 원형 패러다임이나 나선형 패러다임을 적용한 시스템 개발에 많은 도움을 줄 수 이싿.
- 튼튼하고 견고한 시스템은 분석 과정에서 집중적으로 이뤄지는 철저한 검증 과정과 이에 따른 수정 없이는 불가능
- 기존의 구조적 기법 등 다른 접근 방법에서 객체지향으로의 변화에 요구되는 교육과 훈련이 필요
- 객체지향 개념과 설계 기법, 객체지향 언어를 배우는 데 비용이 요구
- 많은 프로그래머들이 객체 중심보다는 기능 중심에서 생각하여 시스템을 개발하여 왔으며 객체지향 사고로의 전환 및 문화의 변화를 필요로 한다.
- 깊은 클래스 계층 구조가 있는 경우와 시스템 작동 중 객체에 대한 동적 할당과 제거시 성능에 대한 문제가 제거될 수도 있다.
- 객체지향 개발 방법은 소프트웨어 공학의 목적인 *고품질의 소프트웨어를 얻을 수 있는 바른 기법*이며 **수정**, **이해**, **재사용**을 용이하여 많은 개발 분야에 확산
- *객체지향 설계는 응용분야의 관점*에서 컴퓨터 관점으로, *사용자 관점*에서 개발자 관점으로 이동하여 객체지향 분석 결과에 살을 붙여가는 과정
- 한편 객체지향 개발기법이 특히 적합한 응용분야들이 있다.
- 응용분야의 객체들이 논리적으로 잘 **분리**되며, 각 객체가 독립적인 자료구조와 오퍼레이션을 가지는 경우 효과적
- 그러나 객체지향 기법은 데이터보다는 성능을 중요시하며, 많은 계산을 요하는 시스템에서는 적합하지 않을 수 있다.