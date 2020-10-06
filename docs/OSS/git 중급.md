---
sidebar: auto
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