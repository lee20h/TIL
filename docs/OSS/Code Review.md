# Code Review

## 코드 리뷰 개요

- 코드 리뷰
    - 협업 과정 중에 각자 수정한 코드를 서로 확인하는 과정
    - 목적: 협력을 통한 품질 향상
        - 오류 검출 뿐 아니라 코드 가독성도 높이고, 팀원들의 전체 코드에 대한 이해를 높여, 보다 품질 좋은 코드를 작성하기 위함
- 다양한 방식으로 수행
    - 회의를 열고 line by line 으로 세밀하게 체크
    - Merge, release 이후에 필요한 시점에 필요한 코드만 서로 확인

### 코드 리뷰 효과

- 버그 개수 감소
- 팀원의 트레이닝 도구로 활용
- 코드 가독성 증가 및 품질 상승
- 코드 세부 구현사항에 대한 기록 보존
- 팀 역량 상향평준화
- 디버깅 시간 및 프로젝트 수행 기간 단축

![image](https://user-images.githubusercontent.com/59367782/99927333-559bad00-2d88-11eb-89a1-0289511182b9.png)


### 코드 리뷰

- Experience from Naver Development team
    - 개발 전체 단계에서 코드 품질을 높이기 위한 노력
        - 표준 코드 스타일 제정
        - 단위 테스트, 코드 리뷰 회의
        - 자동화된 코드 품질 측정: Jenkins CI 도구의 plugin 사용
- 기존 코드 리뷰 방법
    - 개발 이후, 브랜치 병합 이후에 정례/비정례 코드 리뷰 회의
        - 회의 시간이 길어짐: 작성자의 코드 설명
        - 배포 이후라, 코드 리뷰를 생략하게 되고, 하더라도 오류를 뒤늦게 발견
- 코드 리뷰를 배포 이전에 강제할 필요가 있음
    - Gerrit을 코드 리뷰 시스템으로 선정하고, 개발 과정에 포함

### Githb 기반의 코드 리뷰

- Pull request 를 이용한 리뷰 운영 방법
    - 항상 Pull request를 이용해서 commit을 업로드함
        - 각 개발자는 fork해서, 혹은 개별 branch 에서 작업함
    - 리뷰 규칙을 정함
        - 예) Review master가 리뷰 여부 및 리뷰어 설정,
        - 리뷰 규칙: 1일 이내에 수정 요청, 코멘트 혹은 approve 여부 작성
            - 모든 response는 1일 이내에 할 것
    - 리뷰가 완료되면 review master가 merge (혹은 merge 담당에게 요청)
- 역할
    - Maintainer: repository 관리자 (merge 권한)
    - Reviewer: repository collaborator
    - Contributor: 외부 기여자ㄱ