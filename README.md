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

