---
sidebar: auto
---

# Travis CI

CI란? 지속적 통합(Continuous Integration, CI)은 지속적으로 퀄리티 컨트롤을 적용하는 프로세스를 실행하는 것이다. - 작은 단위의 작업, 빈번한 적용. 지속적인 통합은 모든 개발을 완료한 뒤에 퀄리티 컨트롤을 적용하는 고전적인 방법을 대체하는 방법으로서 소프트웨어의 질적 향상과 소프트웨어를 배포하는데 걸리는 시간을 줄이는데 초점이 맞추어져 있다. 대표적인 CI 툴에는 젠킨스(Jenkins)가 있다. (출처: 위키백과)  

즉, 팀 내에서 작업한 결과물들을 정기적으로 통합하는 것이라고 볼 수 있다. 개발자들이 각각 작업한 결과물들을 따로 합치게되면 버그가 생길 수 있으므로 주기적으로 통합하면서 컴파일, 테스트, 빌드 등을 하여 검증해준다.

그 중 Travis CI는 Github에서 진행되는 오픈소스 프로젝트를 위한 지속적인 통합 서비스로, Github repository에 있는 프로젝트를 특정 이벤트에 따라 자동으로 테스트, 빌드하거나 배포 할 수 있다.  

## 흐름

로컬 Git -> Github -> Travis CI -> AWS  

1. 로컬 Git에 있는 소스를 Github 저장소에 Push
2. Github master 저장소에 소스가 Push되면 Travis CI에게 소스가 Push가 되었다고 알림
3. Travis CI는 업데이트된 소스를 Github에서 가져옴
4. 가져온 소스 테스트 코드 실행
5. 테스트 코드 실행 후 테스트 성공시 호스팅한다.

## Github과 연결 순서

1. [Travis CI 사이트](http://https://travis-ci.org) 이동
2. github 연결하여 sign up
3. 해당 레포지토리 활성화
4. 이후 push시 자동으로 연동

## 설정

Docker의 경우에는 `docker-compose.yml`에 했던거와 같이 Travis CI는 `.travis.yml`파일에 설정을 할 수 있다.  

1. 도커환경에서 해당 앱을 실행하고 있으니 Travis CI에서도 도커환경 구성한다.

2. 구성된 도커 환경에서 `Dockerfile.dev`를 이용해서 도커 이미지 생성

3. Test 수행할 방법을 설정

4. 호스팅을 어떻게 할 것인지 설정

`.travis.yml`
```yml
sudo: required

language: generic

services:
	- docker

before_install:
	- echo "start Creating an Image with dockerfile"
	- docker build -t lee20h/docker-react-app -f Dockerfile.dev .

script:
	- docker run -e CI=true lee20h/docker-react-app npm run test -- --coverage

after_success:
	- echo "Test Success"
```

- sudo : 관리자 권한 갖기
- language : 언어(플랫폼) 선택
- services : 환경 구성
- before_install : 스크립트 실행 할 수 있는 환경 구성
- script : 실행할 스크립트(테스트 실행)
- after_success : 테스트 성공 후 할일

해당 파일을 작성하면서 문제가 있었다. 그것은 바로 VSCode를 이용하면서 yml파일을 작성하였는데 자동으로 들여쓰기 해주는 부분이였다.  

예를 들어 `services:`를 친뒤 개행하고 `- docker`같은 속성들을 넣어줄 때 자동으로 탭으로 들여쓰기를 해주는데 이 부분이 github에서는 문제로 작용이 되었다. push는 되지만 travis가 감지를 못하는 문제가 있었다.  

따라서 .travis.yml 작성 시에는 꼭 들여쓰기를 유의해야한다.  