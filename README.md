# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록 후 [정적 웹페이지](https://lee20h.github.io/TIL/)에 정리
* Github Action으로 배포
* markdown으로 작성
* 문제 풀고 [Problem Solving](https://github.com/lee20h/TIL/tree/master/Problem%20Solving) 폴더에 모으기

---  

# 2020년

| [5월](./month/5월) | [6월](./month/6월) | [7월](./month/7월) | [8월](./month/8월) | [9월](./month/9월) | [10월](./month/10월) | [11월](./month/11월) |
|----|-----|-----|---|---|---|---|

---

- 1日

# Code Review: Experience

- 참고자료: 코드 리뷰 소개 및 경험
    - [카카오스토리 웹팀의 코드리뷰 경험, 안오균 (2016)](https://www.slideshare.net/OhgyunAhn/ss-61189141)
    - [JavaScript 코드 리뷰 - 코드 리뷰 문화 (2016)](https://cimfalab.github.io/deepscan/2016/08/code-review-1)
    - [코드 리뷰: 다음커뮤니케이션 (2013 DevOn)](https://www.slideshare.net/pioneerhjlee/code-review-devon2013)

## 코드 리뷰는 문화다

### 카카오스토리

- 서비스: 카카오스토리 웹
    - 프로트엔드 + 웹서버
    - JavaScript 95%, nginx, Bash
    - Backbone 기반 자체 프레임워크
- 코드 리뷰 도입부터 안정화까지
    - 도입: 3명, Github PR 활용, 모든 코드 리뷰 (2013.10 ~)
    - 2년간 사용하며 꾸준히 개선
        - 강제 리뷰 후 머지
        - 리뷰 규칙 구체화: 2단계 리뷰, 리뷰 데이, PR 및 커밋 규칙
        - 오프라인 + 온라인 병행
        - 브랜치 미리보기 서버 구성
        - 코드 리뷰 팀 구분, 리뷰 마스터 설정

### 경험 1: PR 이용 시 실수

- 예외 상황
    - Develop 브랜치에 바로 푸시
        - 실수로, 혹은 간단해서

- 해결 방법
    - Pre-push Git Hook 활용
        - Push 이벤트에 대해 자동 스크립트를 추가해 바로 머지가 되지 않도록
        - [Pro Git](https://git-scm.com/book/ko/v1/Git%EB%A7%9E%EC%B6%A4-Git-%ED%9B%85)

- Pre-push 깃훅의 효과
    - 모든 피쳐가 Pull Request를 통해서 머지됨
    - 초기 리뷰 문화 정착에 도움
    - 이 단계부터 **리뷰는 필수**라는 인식이 자리잡음

### 경험 2: 코드 컨벤션에 대한 리뷰

- 코드 스타일에 대한 리뷰가 대부분
    - 탭, 공백, 들여쓰기, 캐멀케이스, 언더스코어
    - 스타일 가이드 + 에디터 포맷터는 존재
    - 하지만 잘 지켜지지 않음

- 사실 코드 스타일 리뷰는 피곤함
    - 코드 스타일을 통일하면 참 좋겠지만
    - 남기는 사람도 보는 사람도 불편함
    - 도구로 해결할 수 없을까?

- 해결방법: pre-commit 깃훅에서 린트 수행
    - Code linting
        - 정적 코드 분석 및 테스트를 통해 잠재적 에러 및 성능 분석을 하는 것
        - 사용자 정의 방식으로, 코드 컨벤션 검사를 위해 활용할 수 있음
        - 도구: jshint, ESLint, Lint in Android studio 등
        - 참고: [Coding-Convention](https://subicura.com/2016/07/11/coding-convention.html)
    - 해당 커밋에서 변경한 파일 대상
    - 린트 실패 시 커밋할 수 없음

- 효과: pree-commit 훅의 린트는 성공적
    - 코드 스타일에 대한 리뷰가 크게 감소함
    - 수정하는 파일만 대상이므로 거부감이 적었음
    - 대상 파일의 나머지 코드도 수정해야 함
    - 수 개월 후 프로젝트 린트 오류 0%

### 경험 2: 코드 컨벤션에 대한 회고

- 코드 스타일은 꼭 맞춰야할까?
    - 한 사람이 짠 것 같은 코드: 읽고 수정하기 편하고 리뷰 속도도 빨라짐
    - 결국 팀의 속도가 빨라짐
- 코드 스타일에 대한 리뷰는 필요했을까?
    - 코드 스타일 리뷰는 모두의 스트레스였음
    - 특히 규칙이 정해져 있지 않았을 때 더했음
    - 시간이 아깝다고 느껴지기도 했음
- 코드 스타일은 도구로 해결하자
    - 상세한 단위까지 포맷터를 적용
    - 도구가 준비되지 않았다면 생략해도 좋을 듯
- 그래도 해야 하는 부분이 있더라
    - 주석 처리된 코드, 쓰이지 않는데 나중을 위해 아껴둔 코드

### 경험 3: 초기 단계에서 PR 규모 문제

- PR 규모가 커서 리뷰하기 어려움
    - 프로젝트 초기, 기초 구조를 잡던 때
    - 코드량이 많고 커밋의 단위도 커 리뷰하기 어려움
    - 전체 흐름을 파악하기도 어려움
- 해결방법: 온/오프라인 리뷰 병행, PR/커밋 단위 합의
    - 오프라인 리뷰에서 전반적인 의도를 설명, 회의 종료 후 온라인 리뷰
    - 개발 정기 미팅 때 단위 합의
        - PR은 피처 단위로
        - 커밋은 의미있는 작업 단위로

### 경험 4: 리뷰로 인한 병목 현상

- 리뷰를 포함한 개발 프로세스
    - 피처 작업 -> 리뷰 -> develop 머지 -> 알파 배포 -> 테스트
    - 알파 빌드&테스트 서버는 develop 브랜치를 사용
- 리뷰 병목 현상
    - 바쁠수록 리뷰를 미루게 됨
        - 피처 작업하기 바쁘니 리뷰를 미루게 됨 (> 10 PRs in review queue)
    - 리뷰시간이 예상보다 오래 걸림
        - 큰 피처인 경우 1시간 이상, 많으면 하루를 다 쓰는 경우도 있음
        - 태스크 관리 도구에 `개발 리뷰 중` 단계를 추가
    - 피처 작업은 완료해도 리뷰 대기 중
    - **리뷰가 되지 않아 develop 으로 머지하지 못함**
    - **대상 피처가 알파 서버에 배포되지 못함**

- 리뷰 병목으로 피해
    - 기획/디자인 직군의 불만
        - 타직군은 알파 서버에서 피처 확인 가능
        - 개발은 완료됐다고 하는데, 리뷰가 안돼서 확인할 수 없다!
    - 결국, 통합 테스트 때 스펙 변경이 발생함
        - 타직군은 구현된 기능을 통합 테스트 때나 보고 피드백
        - 버그 뿐 아니라 스펙과 디자인 변경이 다수 발생
    - 서로에 대한 불만
        - 개발: 내일 모레가 배포인데 스펙 변경?
        - 기획/디자인: 개발 다 됐다면서 이제 첨 보여줌?
    - **이 시점이 피로도가 가장 컸음**
    - **야근이 많아지고 의욕도 떨어짐**

- 해결방안 1: 미리보기 서버
    - 우선 기획/디자인팀과의 협업부터 해결
    - 브랜치 미리보기 서버를 구성함
        - 각 피처 브랜치의 스냅샷을 배포
    - 미리보기 서버는 매우 성공적
        - develop 머지 전(리뷰 전) 피처 공유 가능
        - 기획/디자인의 피드백을 미리 받고, 통합 테스트 때 스펙 변경이 크게 감소
        - 아이디어 프로토타입 공유 용도로 활발히 사용

- 해결방안 2: 리뷰팀과 리뷰데이, 리뷰 마스터
    - 리뷰 자체를 효율적으로 수행
    - 1차 시도: 리뷰 팀을 두 개로, 별도 리뷰어도 지정
        - 각 팀별로 리뷰 분담
        - 결과: 해결 안됨. 계속 업무는 바빠짐. 본인 피처 작업을 우선해야 하므로, 통합 테스트 날짜 직전에나 리뷰 수행
    - 2차 시도: 리뷰 데이 도입
        - 매주 정해진 요일에 최우선 PR 작업 리뷰
        - 결과: 여전히 비슷한 문제가 발생. 리뷰는 계속해서 우선순위가 떨어짐.
    - 3차 시도: 리뷰 마스터 도입
        - Merge 담당 역할, 개인 판단으로 merge 수행 및 주기적으로 리뷰 독려
        - 결과: 개인 책임 하에 수행되어 잘 동작됨. 애매한 경우, 결정권을 행사하여 의사 결정이 빠름

- 리뷰가 왜 병목이 됐을까?
    - 동료의 리뷰와 동의가 있어야 머지 가능한데, 늦게 함
- 모든 동료의 동의, 효과 있었을까?
    - 서로 어떤 작업을 하는지 알게 되고, 어렴풋하지만 대부분의 코드를 알게 됨
    - 효과는 좋음. 인원이 많아지며 병목의 원인이 됨
- 몇 명의 팀일 때 리뷰가 가장 잘 될까?
    - 2명: 피드백 빠르지만 논의 상대 부족
    - 3~5명: 전체 동의 조건으로 효과적이었음
    - 6명~: 의견/논의도 많음. 결과 대비 비효율적
- 시간이 갈수록 리뷰속도가 빨라짐
    - 일관성 있는 코드 스타일이 도움이 됨
    - 각자 중요하다고 생각하는 포인트 위주로 리뷰
    - 배포 주기가 짧아 쉽게 수정 배포 가능한 환경

### 경험 5: 새로운 팀 멤버 영입

- 프로젝트 멤버가 늘어남
    - 최대 8명까지 늘어남
    - 대부분 리뷰 문화가 거의 없던 팀에서 온 멤버
- 해결방안: 문화로 정착시킴. “우리 팀은 코드 리뷰를 하는 팀!”
    - `리뷰는 당연하다`는 문화는 정착된 상태
    - 영입 전부터 코드 리뷰 문화에 대해 강하게 언급
    - 첫 PR부터 폭풍 리뷰
- 새 멤버들의 공통된 리뷰 후기
    - 초기의 리뷰는 스트레스였다 (특히 코드 스타일)
    - 코드 학습 효과가 좋았다
    - 시간이 지나니 코드 스타일에 익숙해지더라

### 경험 6: 여러 사람이 담당하는 피처의 리뷰

- 여러 사람이 담당하는 피처의 리뷰
    - 한 피처를 여러 명이 함께 작업하는 경우
    - 작업 범위가 겹쳐 develop으로 PR 애매함
    - 피처 단위가 커서 한 번에 리뷰하기엔 부담스러움
- 해결방법: 메인 피처 브랜치로 PR하도록 함
    - 피처의 메인 브랜치인 feature/A를 따고
    - 하위 피처를 feature/A-1, feature/A-2로 작업
    - 작업 후, feature/A-1 > feature/A 로 PR

- 2번에 걸쳐 리뷰함
    - 상위 피처 브랜치로의 1차 리뷰는 담당자끼리만
    - 1차 리뷰는 큼직한 구조나 로직에 대해 러프하게
    - develop 브랜치로의 2차 리뷰는 모두가 참여
- 2차 리뷰의 효과
    - 구조 변경에 대한 피드백이 1차 리뷰에서 가능
    - 테스트 직전에 큰 변경이 적어짐
    - 두 번째 리뷰부턴 확실히 속도가 빠름

### 정리

![image](https://user-images.githubusercontent.com/59367782/100709522-a13a0080-33f1-11eb-8ba4-9cbf8d47a875.png)

### 회고 1. 리뷰는 서로에게 도움이 되었을까?

- 팀원들 후기
    - 새로운 스타일 또는 접근 방법을 알게 됨
    - “배울 게 많았다”
        - 다른 사람의 코드를 읽는 시간이 많아졌다
    - 논의 과정에서 서로 성장하는 느낌
        - `왜 이렇게 했을까` 생각하고, `왜 이렇게 했는지` 설명하는 시간이 많아짐
    - 이제는 안하면 뭔가 불안함
- 직접적 효과
    - 긴급 핫픽스 코드에서 버그 발견!
    - 코드 파악: 내가 짠 것 같은데 알고 보니 다른 사람이 짰음
    - 인수인계 할 게 거의 없음

### 회고 2. 리뷰의 유익함, 무익함

- 유익하다고 느꼈던 리뷰
    - 미리 발견하는 버그
    - 경험의 공유 (삽질 회피, 기존 코드 히스토리)
    - 더 나은 제안 (로직, 변수명)
- 조금은 불필요한 논쟁이라고 생각한 리뷰
    - 취향의 차이 (if vs switch)
    - 애매한 수준의 제안 (변수명, 미미한 성능 개선)
    - 너무 먼 미래에 대한 방어 코드

- 리뷰에 대해 공통적으로 느꼈던 스트레스
    - 코드 스타일의 사소한 부분까지 강요당했을 때
    - 피처도 작업하랴, 리뷰하랴, 피드백하랴
    - 내일이 마감인데, 전체 구조를 변경하는 리뷰
    - 내일이 테스트인데, 쌓인 리뷰가 수십 개
- 근본적으로 해결하기 어려운 문제들
    - 여전히 리뷰가 병목이 될 수 있다
    - 리뷰 문화 정착까지의 비용이 크다
    - 가끔은 리뷰가 생산 의욕을 꺾을 때도 있다

### 회고 3. 어떻게 리뷰를 유지할 수 있었을까?

- 우리가 리뷰를 유지할 수 있었던 이유
    - 초기부터 모두의 동의 하에 자율적으로 도입
    - 코드 리뷰는 당연하다라는 문화의 정착
    - 문제의 인식과 지속적인 개선 노력
    - 정기적인 개발 미팅: 특히 좋았음
        - 매주 정해진 시간에 자유 주제로 논의
        - 이터레이션 테스트 종료 후 회고
        - 리뷰 정책 / 개선에 대한 논의할 수 있는 기회
    - 도구: 엔터프라이즈 깃헙
    - 모두 같은 언어로 같은 서비스를 담당
    - 지속적으로 한 서비스를 담당
    - 수평적 문화 (영어 이름)

- 반면, 예전 좋지 않았던 리뷰 경험
    - 팀 내에서 코드 리뷰 진행
    - 자바스크립트 개발자가 모여있는 기능 조직
    - 각자 다른 프로젝트에 투입
    - 자율적으로 만들어진 분위기가 아니었음

### 코드 리뷰가 좋지 않을 수 있는 이유 및 환경

- 오프라인 코드 리뷰만 수행
    - 리뷰 미팅에서 프로젝터로 공유
    - 리뷰 미팅은 분위기 영향을 많이 받음
    - 과열된 논쟁이나 귀차니즘의 전파
- 도구의 부실함
    - SVN + 마땅한 리뷰 도구 없었음
    - 메모장이나 에디터에 주석으로 달아 전달
    - 별도 리뷰 도구를 도입했지만 잘 연동되지 않음
- 서로 다른 업무
    - 개발하는 언어는 같았지만
    - 담당하는 서비스가 모두 다름
    - 리뷰 범위의 한계 (스타일이나 일반적인 로직)

- 주니어-시니어 간의 코드 리뷰
    - 시니어가 주니어의 코드를 고쳐주는 일방향 리뷰
    - 시니어들에겐 큰 도움이 되지 않음
- 자리잡지 못한 문화
    - 코드 리뷰가 잘 워킹하지 않는 걸 모두 알고 있음
    - `뭘 코드리뷰를 해~`라는 분위기
    - `팀별로 코드리뷰를 하라`는 상위 조직의 강제성

### 리뷰 도입을 위한 제언

- 새로 시작하는 조직에 리뷰를 도입한다면
    - 모든 멤버의 자율적 동의로 시작하고,
    - 최대한 강제성을 적용한 규칙으로 시작
    - 규칙은 도구를 사용해 제한
- 시작할 때는 이렇게 해보면 어떨까?
    - develop,master push 제한 / 모두 PR로
    - 모든 멤버의 동의
    - 코드 스타일 체크는 자동화 (깃훅 등)
- 기존 조직에 리뷰를 도입한다면
    - 나와 마음이 맞는 동료를 찾아 소규모로 시작
    - 도구를 적극적으로 활용
    - 기존에 일하던 방식에 자연스럽게 적용될 수 있게
    - 다른 멤버가 거부감을 갖지 않도록 천천히 도입

- 근데 좀 해보려고 하면,
    - 다른 멤버는 시큰둥하다. 나만 하고 싶나…
    - 자꾸 하자고 하려니 귀찮고 미안하다…
    - 그냥도 이미 바쁜데 오바 아닌가…
- 코드리뷰는 문화
    - 기존의 습관을 단번에 바꾸기 어려움
    - 억지로 바꾸려고 하면 더 어려움
    - 여유와 시간을 갖고 천천히
    - 정답은 없음. 우리 팀에 맞는 방식으로.

- 작은 경험의 반복으로 익숙해지도록
    - 내 코드를 먼저 리뷰하도록 시도
    - 처음엔 리뷰하기 쉽도록 PR은 가능한 작게
    - Pull Request - 리뷰 - 머지의 경험 반복
    - (선택) 리뷰어를 지정해서 부탁
- 리뷰에 어떻게 반응하면 좋을까?
    - 피드백! 피드백!
    - 반영 여부는 본인이 결정하는 것이 좋은 듯
    - 코드는 내가 아니고, 그저 내가 작성한 코드일 뿐

- 어떻게 리뷰하면 좋을까?
    - 부드럽고 젠틀하게
    - 궁금한 건 의도를 물어보는 식으로 접근
    - 이견이 있다면 구체적인 방법을 제시
    - 마음이 불편하더라도 적극적으로 리뷰
- 리뷰 문화를 잘 유지하려면
    - 적극적으로 리뷰하고 잘 피드백하자
    - 코드 스타일 리뷰는 말 대신 도구로 처리하자
    - 서비스와 코드, 리뷰에 대해 자주 이야기하고
    - 리뷰가 병목이 되지 않게 개선하자

### 비자아적 프로그래밍

- 당신이 실수하리라는 것을 받아들여라.
- 당신이 만든 코드는 당신이 아니다.
- 당신이 얼마나 많이 알고 있다고 해도, 항상 누군가는 더 많은 것을 알고 있다.
- 권위는 지위가 아니라 지식으로부터 나온다.
- 자신보다 많이 알지 못하는 사람이라 해도 존경과 인내로 대하라.
- 사람이 아니라 코드 그 자체를 비판하라.

## 코드 리뷰: 도구들

### 코드 리뷰 도구

- 상용
    - Crucible, Collaborator
    - Pre-review, IDE 연동 등 많은 편의 기능 제공
- 공개
    - Gerrit, Phabricator, Review board
    - 오픈 소스 도구. 필수적 기능 및 기타 부가 기능도 상당수 제공
- GitHub PR 연동 서비스
    - reviewable.io, Review Ninja

## Gerrit 소개

### Gerrit code review system

- Gerrit
    - Git 기반의 코드 리뷰 시스템
        - Git 기반의 코드 개발 과정에 쉽게 적용 가능
    - 구글 안드로이드 프로젝트에서 파생
        - AOSP (Android Open Source Project)
        - 자체 서비스를 사용하다가, 오픈 소스 프로젝트로 발전시킴
        - 네덜란드 개발자가 네덜란드의 디자이너이자 건축가인 Gerrit Rietveld의 이름을 따서 Rietveld 시스템을 만들었고, 이를 토대로 Gerrit 으로 발전함
    - 이후 JAVA로 새롭게 작성됨
- 웹을 통해 서비스
    - 자체 서버를 구축해야 함

- [Gerrit Code Review](https://www.gerritcodereview.com/)

### Gerrit 특징

- 리뷰 통과 조건 설정
    - 다른 리뷰어로부터 일정 점수 이상을 얻어야 merge 가능
    - 점수와 의견을 통해 코드 품질 향상을 도움

- 사용자 권한 관리
    - 사용자 별로 접근 권한 관리
- 연동
    - Jenkins와 같은 외부 CI 도구와 쉽게 연동 가능
    - Eclipse 와 같은 IDE 와 연동 가능 (Mylyn 플러그인 사용)
- 다양한 인증 수단 지원
    - HTTP, LDAP, OpenID 와 같은 외부 인증 수단과 연계하여 사용 가능함

### 기존 Git repository 사용 방식

![image](https://user-images.githubusercontent.com/59367782/100710164-a8add980-33f2-11eb-8a03-c5d63764ec3a.png)

### Gerrit 을 이용한 방법

![image](https://user-images.githubusercontent.com/59367782/100710211-bb281300-33f2-11eb-8975-74e1edbd22ec.png)

### Gerrit 을 사용한 개발 흐름

![image](https://user-images.githubusercontent.com/59367782/100710252-caa75c00-33f2-11eb-82fb-7dda2352c235.png)

---

# Auto Scaling

- Scale in-out 을 자동으로 수행해주는 서비스
    - 유동적으로 변동하는 애플리케이션의 로드를 처리할 수 있는 정확한 수의 Amazon EC2 인스턴스를 보유하도록 보장
    - 내결함성 향상
        - 비정상 인스턴스를 검출하고, 대체 인스턴스 시작
        - 복수의 가용 영역을 사용하도록 구성 가능
    - 가용성 향상
        - 현재의 트래픽 요구를 처리할 수 있는 적절한 용량을 항상 갖출 수 있음
    - 비용 관리 개선
- 기타
    - EC2 Console 에서 제어
    - 비용: 무료
    - 참고: [AWS Auto Scaling Documentation](https://docs.aws.amazon.com/ko_kr/autoscaling/ec2/userguide/what-is-amazon-ec2-auto-scaling.html)

### Auto Scaling 구성 요소

![image](https://user-images.githubusercontent.com/59367782/100739748-ecb4d480-341a-11eb-9092-4d1ae375b914.png)

### 시작 구성, 시작 템플릿 및 AS 그룹

- 시작 구성
    - EC2 인스턴스를 시작하는 데 사용하는 템플릿
- 시작 템플릿
    - 시작 구성의 Renewal: 새로운 기능들에 대한 지원
    - 스팟 인스턴스를 자동으로 선택해 구성해주는 기능이 추가됨
- AS 그룹
    - 유사한 특성을 공유하고, 인스턴스 조정 및 관리 목적의 논리적 그룹으로 취급되는, EC2 인스턴스들의 모음
    - 조정 정책: 인스턴스의 수를 자동으로 조절하는데 사용되는 정책
- 특징
    - 한 시작 구성 혹은 템플릿은 여러 AS 그룹에서 사용될 수 있음
    - 한 AS 그룹은 하나의 시작 구성 혹은 템플릿만 사용할 수 있음

### AS 그룹

- Auto scaling 그룹의 제어 파라미터
    - 최소 인스턴스 수: 그룹의 크기가 이 값 아래로 내려가지 않음
    - 목표 인스턴스 수: 확보하는 것이 언제나 보장되는 인스턴스 수
        - 실제 콘솔에서는 현재 Auto scaling 그룹이 정책에 따라 유지하려는 숫자가 표시
    - 최대 인스턴스 수: 그룹의 크기가 이 값을 넘지 않음

![image](https://user-images.githubusercontent.com/59367782/100739822-0d7d2a00-341b-11eb-87b8-a6ec5a22fef4.png)

- 구성 시, 미리 필요한 정보
    - 서버 시작 및 구성에 걸린 시간 (생성 시작부터 사이트 접속 가능까지)
    - 애플리케이션의 성능과 가장 연관성이 높은 지표 (예. 홈페이지 반응 속도)
    - Auto Scaling 그룹에 포함하려는 가용 영역 수
    - Auto Scaling에서 수행하려는 역할
        - Auto Scaling의 조정 기능을 사용하여 용량을 늘리거나 줄일지, 그저 일정한 서버 수가 항상 실행되도록 하는 데만 Auto Scaling을 사용할지 여부 (Auto Scaling은 두 기능을 동시에 수행할 수 있음)
    - 사용할 수 있는 기존 리소스 (예: EC2 인스턴스 또는 AMI)

## 오토 스케일링을 통한 인스턴스 숫자 관리

### 인스턴스 조정 (AS 그룹)

- 항상 현재 인스턴스 수준 유지
    - Elastic scalability 지원이 아닌, fault tolerance 목적으로만 운영
- 수동 조정
    - 원하는 용량을 수정해 인스턴스를 확장/축소 가능
- 예약된 조정
    - 일정을 기반으로 인스턴스 수 조정. 예) 주말에 확장하고 평일에는 축소
- 동적 조정 (on demand dynamic scaling)
    - 수요 변화를 추적하는 지표를 설정하고, 해당 지표에 대해 설정된 확장/축소 정책에 따라 인스턴스를 조정
    - 축소 시, 참고사항: 어떤 인스턴스를 종료할 것인가?
        - 가용 영역 간 인스턴스 수의 균형을 맞추려고 함
        - 시작한지 오래된 인스턴스부터 종료

### AS의 조정 정책의 커스터마이징

1. 최대 서비스 용량 측정: 인스턴스 3개 일 때, 얼마나 높은 성능을 낼 수 있는지, 요청에 대한 응답시간을 지표로 사용해 측정
2. CloudWatch 경보 설정: 원하는 응답 시간 범위에 대한 경보 설정
3. CW 경보에 따른 조정 정책 설정: 인스턴스 증감 정책 수립
4. 테스트 및 경보, 정책 수정 반복

### CloudWatch 경보 설정: 감소 정책 경보

- 증가/감소 경보에 대해 고려할 사항
    - 증가시켜야 하는 경우: 서비스의 품질이 나쁜 상황
        - 인스턴스가 증가하면, 비용이 증가하고, 서비스 품질이 좋아짐
    - 감소시켜야 하는 경우: 서비스의 품질이 불필요하게 너무 좋은 상황
        - 인스턴스가 감소하면, 서비스 품질이 나빠지지만, 비용이 절약됨
- **좋은 서비스 품질을 유지하려면?**
    - 품질이 나쁠 때는 즉각, 인스턴스도 여러 개 증가시키고,
    - 품질이 너무 좋다고 판단될 때에는 최대한 천천히, 하나 씩 감소시켜야 함
- 비용을 최대한 절약하려면?
    - 품질이 나쁠 때에도 최대한 천천히, 인스턴스도 하나씩 증가시키고,
    - 품질이 너무 좋다고 판단될 때에는 즉각, 여러 개씩 감소시킴

### 결과



- 실제 서비스 환경은 훨씬 복잡함
    - 동시 접속 사용자 수의 변화가 훨씬 급격하거나, 완만할 수 있음
        - 예) 점심 시간에 갑자기 사람들이 몰림. 심야 시간에는 수요가 완만하게 감소함
    - 각 사용자들의 요청도 동작에 따라 그 부하가 서로 다름
        - 예) 단순히 상품을 둘러보는 동작 vs. 상품을 결제하고 주문을 수행하는 동작
- 따라서 다양한 테스트를 통해 지속적으로 정책을 수정, 보완하여야 함

---

- 2日

# PS

자물쇠와 열쇠
```cpp
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int key_size, lock_size,allsize;

vector<pair<int,int>> print_v(vector<vector<int>> &temp){
    vector<pair<int,int>> v;
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[i].size(); j++){
            if(temp[i][j]==1){
                v.push_back(make_pair(i,j));
            }
        }
    }
    return v;
}

vector<vector<int>> turn(vector<vector<int>> &key){
    int key_size= key.size();
    vector<vector<int> > temp(key_size, vector<int>(key_size));

    for(int x=0; x<key_size; x++){
        for(int y=0; y<key_size; y++){
            temp[y][(key_size-1) - x] = key[x][y];
        }
    }
    return temp;
}

bool check(vector<vector<int>> &map){
    for(int i= key_size ; i<key_size+lock_size; i++){
        for(int j= key_size; j<key_size+lock_size; j++){
            if(map[i][j]!=1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    key_size = key.size();
    lock_size = lock.size();
    allsize = 2*key_size+ lock_size;
    vector< vector<int>> map(allsize, vector<int>(allsize));
    for(int i= 0; i<lock_size; i++){
        for(int j = 0; j<lock_size; j++){
            map[i+key_size][j+key_size] = lock[i][j];
        }   
    }
    vector<vector<pair<int,int>>> keys;

    keys.push_back(print_v(key));
    for(int i=0; i<3; i++){
        key = turn(key);
        keys.push_back(print_v(key));
    }
    for(int k=0; k<keys.size(); k++){
        for(int i=0; i<=key_size+lock_size; i++){
            for(int j=0; j<=key_size+lock_size; j++){
                for(int g=0; g<keys[k].size(); g++){
                    pair<int,int> p = keys[k][g];
                    int x = p.first + i;
                    int y = p.second + j;
                    if(map[x][y]==0){
                        map[x][y] =1;
                    }else{
                        map[x][y] =2;
                    }
                }
                if(check(map)) return true;
                for(int g=0; g<keys[k].size(); g++){
                    pair<int,int> p = keys[k][g];
                    int x = p.first + i;
                    int y = p.second + j;
                    if(map[x][y]==2){
                        map[x][y] = 1;
                    }else if(map[x][y] == 1){
                        map[x][y] = 0;
                    }
                }
            }
        }
    }
    return answer;
}
```

문제를 이해하는데 제일 오래 걸렸다. key와 lock 크기가 같다고 생각해서 짰던 것이 틀렸다. 그래서 생각하기 어려워서 포스팅을 기반으로 공부를 했다. 먼저 lock과 key*2 크기의 이차원 벡터를 선언하고 중앙에 lock 벡터를 넣었다. 이후에는 key에서 열쇠부분의 좌표를 keys벡터에 집어 넣은 뒤 keys 벡터를 기반으로 값들을 전부 더해주고 check() 함수에서 체킹한 뒤 거짓이라면 더해준 값을 다시 원복귀 시키는 반복을 한다.

이 문제는 생각보다 이해하기도 어려웠고 다른 사람의 코드를 보고도 이해하기 어려웠던 문제인거 같다. 따로 다시 생각해본 결과 시간복잡도는 두 벡터의 크기가 20이하 이므로 생각을 안해도 되었고, 크기를 붙여서 생각하지 못했던게 큰거 같다.

---

- 3日

- [C언어 바이너리 파일 전송 예제](https://www.enqdeq.net/125)

---

# PS

풍선 터뜨리기
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int left[1000001], right[1000001];

int solution(vector<int> a) {
    int answer = 0;
    left[0] = a[0];
    right[a.size()-1] = a[a.size()-1];
    for(int i=1; i<a.size(); i++)
        left[i] = min(left[i-1],a[i]);
    for(int j=a.size()-2; j>=0; j--)
        right[j] = min(right[j+1],a[j]);
        
    if(a.size()<3)
		answer = a.size();
    else {
        answer = 2;
        for(int i=1; i<a.size()-1; i++)
            if(!(a[i]>left[i-1] && a[i]>right[i+1]))
				answer++;
    }
    return answer;
}
```

```cpp
#include <string>
#include <vector>
#include <stack>

using namespace std;
int solution(vector<int> a) {
    int answer = a.size();
    stack<int> stack;
    for(int comp : a){
        while(!stack.empty() && comp < stack.top()){
            stack.pop();
            if(!stack.empty())
                answer--;
        }
        stack.push(comp);
    }
    return answer;
}
```

```
임의의 인접한 두 풍선을 고른 뒤, 두 풍선 중 하나를 터트립니다.
터진 풍선으로 인해 풍선들 사이에 빈 공간이 생겼다면, 빈 공간이 없도록 풍선들을 중앙으로 밀착시킵니다.
여기서 조건이 있습니다. 인접한 두 풍선 중에서 번호가 더 작은 풍선을 터트리는 행위는 최대 1번만 할 수 있습니다. 즉, 어떤 시점에서 인접한 두 풍선 중 번호가 더 작은 풍선을 터트렸다면, 그 이후에는 인접한 두 풍선을 고른 뒤 번호가 더 큰 풍선만을 터트릴 수 있습니다.
```

DP를 이용해서 해결한 부분과 다른 사람이 해결한 코드 중에서 가장 이해하기 쉽고 명료한 코드를 기록하려한다. DP는 먼저 왼쪽 기준과 오른쪽 기준으로 저장 한 뒤 조건을 둬서 해결한 반면에 스택은 O(n)으로 해결할 수 있었다. 스택이 비어 있으면 push하고 스택이 비어있지 않다면 현재 인덱스와 stack의 top과 비교하여 작으면 전부 비우는 식으로 진행하였다.

---

- 4日

# Mocha.js

- [참고 블로그 : A to Z님](https://a-tothe-z.tistory.com/13)

Mocha.js는 JavaScript에서 사용할 수 있는 테스트 프레임워크로 Simple, Flexible, Fun이라는 특성을 내세운다. 소프트웨어공학이라는 수업을 들으면서 TDD. 즉 테스트 주도 개발을 알게되면서 처음으로 사용하기 수월한 것을 찾다가 공부하게 되었다.

먼저 설치가 필요한데 npm으로 global 혹은 dependency로 설치하면 된다.

## 설치

```
$ npm install mocha --global
```

```
$ npm install mocha --save-dev
```

추가적으로 Mocha를 실행할려면 Node.js 버전 4 이상, 설치에는 npm이 2.14.2 이상이여 한다.

## 시작

package.json에 스크립트를 추가하면 조금 더 편리하게 사용할 수 있다. 이러한 스크립트는 파일들에 대해 감시 옵션인 `-w`를 추가해서 실행하는 것이다. 파일이 변경할 때마다 자동으로 테스트 러너가 실행된다ㅏ.

```json
"scripts": {
  "test": "node_modules/.bin/mocha $(find ./ -name '*.js') --recursive -w"
},
```

프로젝트 내에서 테스트를 하기 위한 디렉토리를 생성한 후 테스트코드는 `.spec.js` 파일로 작성한다.

### assert

assert를 통해서 assertion 함수를 쉽게 사용할 수 있다.

```js
const assert = require("assert");
```

### describe

`describe()`으로 테스트 suite을 만들고 그 안에 `it()`으로 테스트 코드를 작성한다. `descirbe()`은 중첩해서 사용할 수 있다.

```js
describe('테스트 이름', function() {

})
```

### it

it으로 테스트 코드를 작성할 수 있다. 이때 it의 첫번째 인수는 테스트 케이스 이름을 넣어주면 된다.

그리고 두번째 파라미터로는 Mocha가 done 객체를 전달해줄 테스트케이스의 함수를 넣어준다. 여기서 done객체는 테스트케이스가 종료되었을 때 호출된다. 따라서 이를 이용해 비동기 처리를 할 수 있다.

```js
describe('Test suite', function () {
  it('Test', function () {
    assert.equal(true, false)
  })
})
```

위와 같은 테스트는 실패를 받을 수 있다.

## 실행

터미널에서 다음과 같이 입력하면 실행할 수 있다.

```
$ mocha
```

그러면 describe를 한 덩어리로 보고 밑에 it을 각각을 나눠서 테스트를 한 뒤 보여주게 된다.

여기에서 더 나아가면 `describe()`안에 또 다른 `describe()`를 추가할 수 있다. 그렇게 한다면 세부 카테고리화를 하여 조금 더 체계를 갖출 수 있게 된다.

## 추가적으로

### 비동기 코드 예제

위에서 언급한 것처럼 done 객체를 반환하게 되면 비동기 처리를 할 수 있다.

```js
describe('User 테스트', function () {
    describe('저장 테스트', function () {
        it('저장 에러 여부', function (done) {
            var user = new User('YoungHun');
            user.save(done);
        })
    })
})
```

이와 같이 쉽게 테스트 해볼 수 있다.

### Hooks

BDD. 행위주도개발 스타일의 인터페이스를 위해서 hooks 들은 `before()`, `after()`, `beforeEach()`, `afterEach()` 등을 제공한다. 전제조건으로 설정한 뒤 테스트하게 되면 테스트를 정리해준다.

```js
describe('hooks 테스트', function () {
    before(function () {
        //모든 테스트가 실행되기 전에 이 블럭이 실행됩니다.
    });

    after(function () {
        //모든 테스트 실행 후에 이 블럭이 실행됩니다.
    });

    beforeEach(function () {
        //각각의 테스트 실행 전에 이 블럭이 실행됩니다.
    });

    afterEach(function () {
        //각각의 테스트 실행 후에 이 블럭이 실행됩니다.
    })

    //테스트 케이스 작성
})
```

테스트 코드 전/후로 hooker를 실행할 수 있다. 테스트 suite 전/후로 before과 after가 실행된다. beforeEach와 afterEach는 테스트 suite 안에 정의한 모든 테스트 코드 실행 전/후마다 실행이 된다. 예를 들어서 테스트에 필요한 자료를 데이터베이스에 삽입하거나 삭제하는 등의 일련의 작업을 코드 실행 전/후로 실행할 때 사용된다.

### Exclusive 테스트

특정 suite나 테스트케이스만 테스트하고 싶으면 `.only()`를 함수에 추가하면 된다.

```js
describe("...", function () {
  // 오직 이 테스트만 수행됨
  describe.only("해당 suite만 실행", function () {
    it("...", function () {})
  })

  describe("...", function () {
    it("...", function () {})

    it("...", function () {})
  })
})
```

### Inclusive 테스트

Exclusive와는 정반대로 `.skip()`을 함수에 추가하게 되면 해당 케이스나 suite를 무시하고 진행된다.

```js
describe('...', function () {
  // 이 테스트는 스킵됨
  describe.skip('해당 suite 무시', function () {
    it('...', function () {})
  })

  describe('해당 suite는 실행', function () {
    it('...', function () {})

    it('...', function () {})
  })
})
```

### Pending 테스트

콜백이 없는 케이스로, 테스트 케이스를 비워놓고 누군가가 작성해야하는 부분을 의미한다.

```js
var assert = require('assert'); 

describe('테스트', function () {
    describe('Pending 테스트', function() {
       it('누군가 이 케이스를 작성해야 합니다.')
    });
})
```

---

- 5日

# PS

정수 삼각형
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    dp[0][0] = triangle[0][0];
    for (int i=1; i<size; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    for (int i=2; i<size; i++) {
        for (int j=1; j<i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    for (int i=0; i<size; i++) {
        answer = max(dp[size-1][i], answer);
    }
    return answer;
}
```
```
    ●
   ● ●
  ● ● ●
 ● ● ● ●
● ● ● ● ●
```
이러한 삼각형이 만들어 질 때 위에서 아래로 내려가면서 덧셈을 한 경우 최댓값을 구하는 문제이다. 보자마자 DP가 생각났으며 구현하는 부분에서 분할해서 생각하였다. 삼각형의 밑변을 제외한 변들은 무조건 위에 있는 부분을 덧셈을 해야한다. 따라서 dp 배열에서 직각삼각형 꼴로 만들되 정삼각형에서 두 변 부분은 위의 값을 그대로 더해야하기 때문에 첫 포문을 통해서 채워주고 시작하였다. 이후에는 중간 부분을 이중 포문으로 왼쪽 이나 오른쪽 위의 값 중 큰 것을 택하도록 반복하게 되면 밑변에 다 더한 값들이 남게 된다. 그러므로 밑변 중 가장 큰 값이 답이 된다.

---

# 소프트웨어공학 프로젝트

프로젝트를 계획, 요구사항 분석, 설계, 구현, 테스트하는 절차를 직접 문서에 적어보는 작업을 해보았다. 결론부터 말하자면 상당히 어려웠다. 프로젝트를 기획하고 어떻게 작동할지 생각하는 것은 쉬웠지만 문서로 적는 것은 쉽지 않았다. 계획은 일정을 잡고 콘티를 짜보고 기술 스택을 적어보았다. 요구사항 분석에서는 요구사항을 먼저 정리하고 모델링을 진행하였다. 기능, 정보, 동적 모델링을 통해 구체적인 틀을 잡아가고 마지막으로는 요구사항 명세서를 써서 구체적으로 어떤 기능들이 만들어질지 구상했다.

설계는 데이터, 구조, 프로시져, 사용자 인터페이스 설계 이 순서대로 하게 되었는데 데이터는 먼저 정보 모델링해서 나온 결과물을 토대로 데이터베이스나 자료구조를 작성하였고, 구조는 기능과 동적 모델링에서 나온 결과를 어떤 기능과 상태가 변하는지 명시하였다. 프로시져에서는 모듈로 나눠서 모듈을 어떻게 설계할지 적었다. 마지막으로 인터페이스 같은 경우에는 계획 때 사용한 콘티에서 수정을 가하는 방향으로 적었다.

구현은 직접 만든 코드를 기능마다 구현 방식을 설명을 하였고 테스트는 단위 테스트와 통합 테스트를 프레임워크와 라이브러리의 힘을 빌려서 마무리 지었다. 처음으로 한 TDD 프로젝트였기 때문에 많이 어색하고 접하는 것이 많았다.

---

- 6日

# PS

N으로 표현
```cpp
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int N, int number) {
    int answer = 0; 
    if(N == number) {
        return 1;
    }
    vector<set<int>> arr(8);
    for(int i=0; i<8; i++){
        int n = N;
        int cnt = i;
        while(cnt > 0){
            cnt--;
            n *= 10;
			n += N;
        }
        arr[i].insert(n);
    }
    
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            for(auto x : arr[j]){
                for(auto y : arr[i-j-1]){
                    arr[i].insert(x+y);
                    arr[i].insert(x*y);
                    arr[i].insert(x-y);
                    if(y)
                        arr[i].insert(x/y);
                }
            }
        }
        if(arr[i].find(number) != arr[i].end()){
            return i+1;
        }
    }
    return -1;
}
```

N으로 표현 가능한 1~8자리 수 중에서 사칙연산을 통해 number를 나타낼 수 있는가를 찾는 문제이다. 먼저 8개의 벡터에 N, NN, NNN ... 쭉 넣은 뒤 그 값들끼리 사칙연산을 한 뒤 결과를 같은 set에 집어넣어서 중복을 제거한 뒤 find를 통해 찾도록 하였다. 이러한 방법 외에도 깊이가 8까지 밖에 안되므로 DFS를 통해서 풀어도 충분히 풀릴거 같다.

---