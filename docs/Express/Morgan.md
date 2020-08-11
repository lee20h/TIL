---
sidebar: auto
---
# Logger API : Morgan
## 설치

```js
$ npm install morgan
```

## 사용

```js
var logger = require('morgan');
...
app.use(logger(":remote-addr"), function(req, res, next){
  next();
});
 
app.use(logger(":method"), function(req, res, next){
  next();
});
 
app.use(logger(":url"), function(req, res, next){
  next();
});
 
app.use(logger(":date"), function(req, res, next){
  next();
});
 
app.use(logger(":status"), function(req, res, next){
  next();
});
...
```

## 토큰
| Token | Content |
|---|---|
| :req[header] | request의 특정 HTTP |
| :res[header] |	response의 특정 HTTP |
| :http-version | HTTP version |
| :response-time | 응답시간 |
| :remote-addr | 사용자의 IP |주소
 :date | request 날짜/시간| 
| :method | request에 대한  HTTP method |
| :url | 요청된 URL |
| :referrer | 현재 URL을 참고하는 URL |
|:user-agent | User-agent 서명 |
| :status | HTTP 상태 |

## 로그 파일로 저장
'default', 'short', 'tiny', 'dev' 4가지 포맷을 지원한다.
```js
...
var fs = require('fs');
...
app.use(logger({
  format: 'dev',
  stream: fs.createWriteStream('app.log', {'flags': 'w'})
}));
...
```
이 때 `app.log`는 이름일뿐 수정 가능하며 저장 위치는 Express 앱의 root이다.