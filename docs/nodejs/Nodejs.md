# Node js

Node.js란 브라우저 밖으로 Javascript를 꺼내서 활용할 수 있다. 즉, 브라우저와는 별도로 작동하는 걸 만들 수 있다. Javascript는 브라우저에 종속되어 브라우저에 맞춰진 언어였다. 하지만 Node.js로 인하여 컴퓨터의 콘솔에서 Javascript를 사용할 수도 있게 되었다.

## Node.js Use Case

1. 프론트엔드와 백엔드 언어 통일
2. 아무것도 없는 상태에서 시작하며 필요시 추가
3. 실시간, 많은 데이터를 움직일 때 좋은 성능 (CRUD)
4. Javascript는 메모리나 램 같은 하드웨어에 접근할 수 없음

## What is a Server

물리적으로는 항상 켜져있는 컴퓨터이며, 소프트웨어적으로 서버란 인터넷에 연결된 한 덩어리의 코드이다. URL에 응답하고 접속을 허락하는 일을 하며, Public Network가 아니여도 된다. 즉, Private Network여도 된다. 이게 기본적으로 서버를 의미한다. 

## What is a Express

Express.js는 프레임워크로, Node.js로 하고자 하는 원하는 목표를 쉽고 빠르게 할 수 있게 도와준다. Node.js로 서버를 구축할 때 크게 도움을 준다. 다른 언어로 치면 Python의 Django, Ruby의 Rails와 같은 것들이다. 또한 Express의 경우에는 최근에는 커밋이 되지 않고 있다. 그 말은 바로 거의 완성되었고 고칠게 딱히 없는 프레임워크라는 것이다.

## NPM

Node Package Manager의 준말로, 중앙 집중화 개념으로 각자의 패키지를 넣어놓는다. Node.js와 관련된 백엔드, 프론트엔드를 만드는 개발자들의 패키지를 담아놓는 역할을 한다. 이 NPM을 통해서 패키지들을 다운로드하고 업데이트도 가능하다. 물론 Express.js 또한 NPM을 통해서 다운로드할 수 있고 업데이트할 수 있다.