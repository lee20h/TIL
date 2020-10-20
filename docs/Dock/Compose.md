  
 
  

# 도커 컴포즈

Docker Compose란 다중 컨테이너 도커 애플리케이션을 정의하고 실행하기 위한 도구이다.  

간단한 예시 프로그램을 만들어서 이해를 해보자.  

## 예시 프로그램

express를 통해서 간단하게 페이지를 구현해본다. 다음의 소스로 구현하였다.  

`package.json`
```json
{
  "name": "docker-compose-app",
  "version": "1.0.0",
  "description": "",
  "main": "server.js",
  "scripts": {
    "start": "node server.js"
  },
  "dependencies": {
    "express": "4.17.1",
    "redis": "3.0.2"
  },
  "author": "",
  "license": "ISC"
}

```
`server.js`
```js
const express = require("express");
const redis = require("redis");

//레디스 클라이언트 생성

const client = redis.createClient({
    host: "redis-server",
    port: 6379
});

const app = express();

//숫자는 0 부터 시작하여 증가
client.set("number", 0);

app.get('/', (req, res) => {
    client.get("number", (err, number) => {
        // 현재 숫자 증가
        client.set("number", parseInt(number) + 1);
        res.send(`숫자가 1씩 증가합니다. 숫자: ${number}`);
    })
})

app.listen(8080);
console.log('Server is Running');
```

지금까지 만들어온 Dockerfile과 같이 만들면 된다.  
`dockerfile`
```dockerfile
FROM node:10

WORKDIR /usr/src/app

COPY ./ ./

RUN npm install

CMD ["node", "server.js"]
```

여기까지는 이전에 했던 부분과 비슷하다. 해당 소스를 도커를 통해 실행을 하게 되면 다음과 같다.  

두 개의 컨테이너로 나눠져, 레디스가 들어있는 컨테이너와 node 앱과 레디스 클라이언트가 들어있는 컨테이너가 존재하게 된다.  

두 개의 컨테이너를 따로따로 실행하게 되면 컨테이너 사이에 아무런 설정 없이 접근이 불가능하다. 따라서 node.js 앱이 레디스 서버에 접근을 할 수 없게 되어 에러가 일어나게 된다.  

## docker compose 파일 구조와 작성

여기서 컨테이너 사이에 통신을 하게 해주기 위해서 Docker Compose를 이용하게 된다.  

해당 프로젝트에 `docker-compose.yml` 파일이 추가된다.  

먼저 docker-compose 파일 구조를 보게 되면 docker-compose 속에 다중의 컨테이너들을 넣어주게 된다. 여기서는 컨테이너들을 services라고 명한다. 해당 컨테이너에서 해줘야하는 역할들을 적어줘서 묶어서 실행하게 된다.  

- version : docker compose 버전
- services : 이곳에 실행하려는 컨테이너들을 정의
	- redis-server : 컨테이너 이름
		- image : 컨테이너에서 사용하는 이미지
	- node-app : 컨테이너 이름
		- build : 현 디렉토리에 있는 Dockerfile
		- ports : 포트 맵핑 로컬 포트 : 컨테이너 포트

```yml
version: "3"
services: 
    redis-server:
        image: "redis"
    node-app:
        build: .
        ports:
            - "5000:8080"
```

이후에 도커를 실행할 때의 명령어는 `docker-compose up`으로 사용하면 된다. 이때 유의해야할 점은 프로젝트 디렉토리에 위치한 상태에서 명령어를 사용해야한다.  

## docker compose 명령어 옵션

docker compose 명령어에서 --build 옵션을 줄 수 있다. 해당 옵션이 있고 없고의 차이를 보자.  

먼저 docker-compose up의 경우에는 이미지가 없을 때 이미지를 빌드하고 컨테이너를 실행시키는 반면에, docker-compose up --build는 이미지가 있든 없든 이미지를 빌드하고 컨테이너를 실행한다.  

따라서 이미지가 수정이 된 경우에는 --build 옵션을 명시해서 이미지를 새로 빌드해야 해당 수정사항이 반영된다는 것을 알 수 있다.  

추가적으로 여러 개의 터미널로 실행하지 않고 하나의 터미널로 docker compose로 컨테이너를 실행하고자 한다면 다음과 같은 옵션을 사용하면 된다.  

`docker compose -d up` -d 옵션은 detached 모드로써 앱을 백그라운드에 실행한다. 따라서 앱에서 나오는 output을 출력하지 않고 백그라운드에서 계속 실행하게 된다.  

이후에 docker compose를 중지 시키고 싶다면 `docker-compose down` 명령어를 통해서 작동된 앱을 중지 시킬 수 있다.  