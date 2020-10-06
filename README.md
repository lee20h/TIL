# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록 후 [정적 웹페이지](https://lee20h.github.io/TIL/)에 정리
* 쓸데없는 Commit 지양
* markdown으로 작성
* 문제 풀고 [Problem Solving](https://github.com/lee20h/TIL/tree/master/Problem%20Solving) 폴더에 모으기

---  

# 2020년

| [5월](./month/5월) | [6월](./month/6월) | [7월](./month/7월) | [8월](./month/8월) | [9월](./month/9월)
|----|-----|-----|---|---|

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