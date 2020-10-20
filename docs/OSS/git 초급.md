  
 
  

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