(window.webpackJsonp=window.webpackJsonp||[]).push([[59],{427:function(e,t,v){"use strict";v.r(t);var _=v(25),s=Object(_.a)({},(function(){var e=this,t=e.$createElement,v=e._self._c||t;return v("ContentSlotsDistributor",{attrs:{"slot-key":e.$parent.slotKey}},[v("h1",{attrs:{id:"도커-이미지"}},[v("a",{staticClass:"header-anchor",attrs:{href:"#도커-이미지"}},[e._v("#")]),e._v(" 도커 이미지")]),e._v(" "),v("p",[e._v("도커 이미지는 컨테이너를 만들기 위해 필요한 설정이나 종속성들을 갖고 있는 소프트웨어 패키지로, 지금까지 사용한것 처럼 도커 이미지는 Dockerhub에 이미 다른 사람들이 만들어 놓은 것을 이용 할 수도 있으며, 직접 도커 이미지를 만등러서 사용할수도 있고 직접 만든 것을 Dockerhub에 업로드 할 수도 있다.")]),e._v(" "),v("p",[e._v("생성 명령어 "),v("code",[e._v("docker create <이미지 이름>")])]),e._v(" "),v("p",[e._v("도커 이미지 생성 순서")]),e._v(" "),v("ol",[v("li",[e._v("Docker file 작성\n"),v("ul",[v("li",[e._v("Docker File : Docker Image를 만들기 위한 설정 파일로, 컨테이너가 어떻게 행동할지 설정을 정의")])])]),e._v(" "),v("li",[e._v("도커 클라이언트\n"),v("ul",[v("li",[e._v("도커 파일에 입력된 것들이 도커 클라이언트에 전달되어야함")])])]),e._v(" "),v("li",[e._v("도커 서버\n"),v("ul",[v("li",[e._v("도커 클라이언트에 전달된 모든 중요한 작업들을 하는 곳")])])]),e._v(" "),v("li",[e._v("이미지 생성")])]),e._v(" "),v("h2",{attrs:{id:"도커-파일-만드는-순서"}},[v("a",{staticClass:"header-anchor",attrs:{href:"#도커-파일-만드는-순서"}},[e._v("#")]),e._v(" 도커 파일 만드는 순서")]),e._v(" "),v("p",[e._v("도커 이미지가 필요한 것이 무엇인지 생각")]),e._v(" "),v("ol",[v("li",[v("p",[e._v("베이스 이미지 명시(파일 스냅샷에 해당)")])]),e._v(" "),v("li",[v("p",[e._v("추가적으로 필요한 파일을 다운 받기 위한 몇 가지 명령어를 명시 (파일 스냅샷에 해당)")])]),e._v(" "),v("li",[v("p",[e._v("컨테이너 시작시 실행 될 명령어를 명시 (싲가시 실행 될 명령어에 해당)")])])]),e._v(" "),v("p",[e._v("베이스 이미지란?")]),e._v(" "),v("ul",[v("li",[e._v("도커 이미지는 여러 개의 레이어로 되어 있는데 그 중 베이스 이미지는 이미지의 기반이 되는 부분이다. 따라서 레이어의 중간 단계의 이미지, 예를 들어 OS라고 생각할 수 있다.")])]),e._v(" "),v("h2",{attrs:{id:"hello-문구-출력하는-도커-만들기"}},[v("a",{staticClass:"header-anchor",attrs:{href:"#hello-문구-출력하는-도커-만들기"}},[e._v("#")]),e._v(" Hello 문구 출력하는 도커 만들기")]),e._v(" "),v("p",[e._v("순서")]),e._v(" "),v("ol",[v("li",[e._v("도커 파일을 만들 폴더 만들기")]),e._v(" "),v("li",[e._v("방금 생성한 도커 폴더를 에디터를 이용해서 실행 (vs code)")]),e._v(" "),v("li",[e._v("파일 하나를 생성, 이름은 Dockerfile")]),e._v(" "),v("li",[e._v("그 안에 기본적인 토대 명시")])]),e._v(" "),v("div",{staticClass:"language-dockerfile extra-class"},[v("pre",{pre:!0,attrs:{class:"language-dockerfile"}},[v("code",[v("span",{pre:!0,attrs:{class:"token comment"}},[e._v("# 베이스 이미지 명시")]),e._v("\n"),v("span",{pre:!0,attrs:{class:"token instruction"}},[v("span",{pre:!0,attrs:{class:"token keyword"}},[e._v("FROM")]),e._v(" baseImage")]),e._v("\n\n"),v("span",{pre:!0,attrs:{class:"token comment"}},[e._v("# 추가적으로 필요한 파일 다운로드")]),e._v("\n"),v("span",{pre:!0,attrs:{class:"token instruction"}},[v("span",{pre:!0,attrs:{class:"token keyword"}},[e._v("RUN")]),e._v(" command")]),e._v("\n\n"),v("span",{pre:!0,attrs:{class:"token comment"}},[e._v("# 컨테이너 시작시 실행 될 명령어 명시")]),e._v("\n"),v("span",{pre:!0,attrs:{class:"token instruction"}},[v("span",{pre:!0,attrs:{class:"token keyword"}},[e._v("CMD")]),e._v(" [ "),v("span",{pre:!0,attrs:{class:"token string"}},[e._v('"excutable"')]),e._v("]")]),e._v("\n\n\n"),v("span",{pre:!0,attrs:{class:"token comment"}},[e._v("# FROM : 이미지 생성시 기반이 되는 이미지 레이어로, <이미지 이름> <태그> 형식으로 작성 태그를 안 붙이면 가장 최신것으로 다운 받음")]),e._v("\n\n"),v("span",{pre:!0,attrs:{class:"token comment"}},[e._v("# RUN : 도커이미지가 생성되기 전에 수행할 쉘 명령어")]),e._v("\n\n"),v("span",{pre:!0,attrs:{class:"token comment"}},[e._v("# CMD : 컨테이너가 시작되었을 때 실행할 실행 파일 또는 쉘 스크립트로, 해당 명령어는 DockerFile내 1회만 쓸 수 있다.")]),e._v("\n\n")])])]),v("ol",{attrs:{start:"5"}},[v("li",[v("p",[e._v("베이스 이미지로부터 실제 값 추가")])]),e._v(" "),v("li",[v("p",[e._v('베이스 이미지는 ubuntu 나 centOS 등 원하는 것을 사용해도 되지만, "Hello"를 출력하기 때문에 가장 작은 alpine 베이스 이미지 사용')])]),e._v(" "),v("li",[v("p",[e._v("Hello 문자 출력하기 위해 echo 사용해야하는데, alpine 안에 echo 사용 가능한 파일이 존재하므로 RUN 부분 생략")])]),e._v(" "),v("li",[v("p",[e._v("마지막으로 컨테이너 시작시 실행 될 명령어 echo hello 찍어준다.")])])]),e._v(" "),v("div",{staticClass:"language-dockerfile extra-class"},[v("pre",{pre:!0,attrs:{class:"language-dockerfile"}},[v("code",[v("span",{pre:!0,attrs:{class:"token instruction"}},[v("span",{pre:!0,attrs:{class:"token keyword"}},[e._v("FROM")]),e._v(" alpine")]),e._v("\n\n"),v("span",{pre:!0,attrs:{class:"token comment"}},[e._v("#RUN command")]),e._v("\n\n"),v("span",{pre:!0,attrs:{class:"token instruction"}},[v("span",{pre:!0,attrs:{class:"token keyword"}},[e._v("CMD")]),e._v(" [ "),v("span",{pre:!0,attrs:{class:"token string"}},[e._v('"echo"')]),e._v(", "),v("span",{pre:!0,attrs:{class:"token string"}},[e._v('"Hello"')]),e._v("]")]),e._v("\n")])])]),v("h2",{attrs:{id:"완성된-도커-파일에서-이미지-생성하기"}},[v("a",{staticClass:"header-anchor",attrs:{href:"#완성된-도커-파일에서-이미지-생성하기"}},[e._v("#")]),e._v(" 완성된 도커 파일에서 이미지 생성하기")]),e._v(" "),v("p",[v("code",[e._v("Dockerfile -> 도커 클라이언트 -> 도커 서버 -> 이미지")]),e._v("\n도커 파일에 입력된 것들이 도커 클라이언트에 전달되어 도커 서버가 인식되어야한다. 그렇게 하기 위해서는 "),v("code",[e._v("docker build ./ 또는 docker build .")]),e._v("을 사용해야한다.")]),e._v(" "),v("p",[e._v("이때 Build 명령어는 해당 디렉토리 내에서 dockerfile라는 파일을 찾아서 도커 클라이언트에 전달 시켜준다.")]),e._v(" "),v("p",[e._v("docker build 뒤에 "),v("code",[e._v(".")]),e._v(" 이나 "),v("code",[e._v("./")]),e._v("을 사용하면 되는데 "),v("code",[e._v("./")]),e._v("이 권장 된다.")]),e._v(" "),v("h3",{attrs:{id:"build-과정-설명"}},[v("a",{staticClass:"header-anchor",attrs:{href:"#build-과정-설명"}},[e._v("#")]),e._v(" Build 과정 설명")]),e._v(" "),v("p",[e._v("Step 1/2")]),e._v(" "),v("ul",[v("li",[e._v("alpine 이미지 가져오기 "),v("code",[e._v("a24bb4013296")]),e._v("은 alpine 이미지 아이디")])]),e._v(" "),v("p",[e._v("Step 2/2")]),e._v(" "),v("ul",[v("li",[e._v("임시 컨테이너 생성 후 그 컨테이너에 시작시 사용할 명령어 포함시킨다.")]),e._v(" "),v("li",[e._v("방금 생성한 임시 컨테이너를 지우고 새로운 이미지 만들기")])]),e._v(" "),v("p",[v("strong",[e._v("세부 설명")])]),e._v(" "),v("ol",[v("li",[v("p",[e._v("Alpine 이미지에 시작시 실행 될 명령어와 파일 스냅샷 (etc, dev, bin...) 이 들어 있다.")])]),e._v(" "),v("li",[v("p",[e._v("임시 컨테이너 생성 (시작시 실행할 명령어는 아직 없다) 후 하드 디스크에 파일 시스템 스냅샷 추가")])]),e._v(" "),v("li",[v("p",[e._v("임시 컨테이너에 시작시 실행할 명령어 추가")])]),e._v(" "),v("li",[v("p",[e._v("임시 컨테이너로 Alpine 이미지(1번과 다른 Alpine 이미지) (시작시 실행 될 명령어 삽입) 생성")])]),e._v(" "),v("li",[v("p",[e._v("임시 컨테이너 삭제")])])]),e._v(" "),v("p",[e._v("따라서, 베이스 이미지에서 다른 종속성이나 새로운 커맨드를 추가 할때는 임시 컨테이너를 만든 후 그 컨테이너를 토대로 새로운 이미지를 만든다. 이후 임시 컨테이너는 삭제해준다.")]),e._v(" "),v("h2",{attrs:{id:"도커-이미지에-이름-주는-방법"}},[v("a",{staticClass:"header-anchor",attrs:{href:"#도커-이미지에-이름-주는-방법"}},[e._v("#")]),e._v(" 도커 이미지에 이름 주는 방법")]),e._v(" "),v("p",[e._v("원래의 build 방법은 "),v("code",[e._v("docker build ./")]),e._v("이다. 여기서 이미지에 이름을 주는 명령어가 있다.")]),e._v(" "),v("p",[e._v("바로 "),v("code",[e._v("docker build -t 나의 도커아이디 / 저장소/프로젝트이름 : 버전 ./")]),e._v("이다. 여기서 나온 도커아이디/저장소:버전은 docker hub에 각각 나온 이름들과 동일하므로 확인해보면 된다.")]),e._v(" "),v("p",[v("code",[e._v("docekr build -t lee20h/hello:latest ./")]),e._v(" 명령어를 치면 이러한 내용이 나온다.")]),e._v(" "),v("p",[e._v("Successfully built 385d35d8da0f\nSuccessfully tagged lee20h/hello:latest")]),e._v(" "),v("p",[e._v("따라서 도커 이미지가 생성이 되고 해당 이미지에 이름을 붙일 수 있다. 그리고 사용할 때는 "),v("code",[e._v("docker run -it lee20h/hello")]),e._v("와 같이 사용하게되면 도커 이미지를 실행시킬 수 있게 된다.")])])}),[],!1,null,null,null);t.default=s.exports}}]);