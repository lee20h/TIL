---
sidebar: auto
---
# CORS (Cross Origin Resource Sharing)

## 이슈

이번 프로젝트를 예로 들면 FE단의 vue.js에서는 localhost:8080 즉, localhost의 8080의 포트를 사용하고 BE단의 express.js에서는 localhost:3000으로 3000 포트를 사용한다. 이 때  서로 다른 port를 listen 중에  FE단에서 BE단으로 ajax 요청을 보낼려고 하면 Cross Domain 이슈가 일어나게 된다.

CORS 사용하지 않은 상황에서 Cross Domain 오류 메시지

```js
XMLHttpRequest cannot load http://xx.xx.xx.xx/xxx.
Request header field Content-Type is not allowed by Access-Control-Allow-Headers. 
```

## 설치

```jsx
npm install cors
```

## 사용

**1. 모든 도메인 요청 활성화(모든 작업 CORS 허용 테스트용)**

```jsx
var express = require('express')
var app = express();
var cors = require('cors')

app.use(cors());
```

**2. 싱글 라우트에 대한 도메인 활성화(특정 작업에 대해서만 CORS허용)**

```jsx
var express = require('express');
var app = express();
var cors = require('cors');
// ***********  products/:id 에 대한 url 라우팅시에만  cors 를 허용 
app.get('/products/:id', cors(), function(req,res,next) {
res.json({msg:'This is CORS-enabled for a single Route'});
})
```

**3. CORS Config settings(setting 값을 수정하여서 CORS 허용 IP지정)**

```jsx
var express = require('express');
var app = express();
var corsOptions = {
	origin :'http://example.com',
	optionsSuccessStatus:200; // IE 11이나 여러 스마트 TV들에 대한 확인 
};

app.get('/products/:id',cors(corsOptions),function(req,res,next){
res.json({msg:' This is CORS-enabled for only example.com.'});
});
```

**4. CORS Dynamic Origin 동적으로 읽어서 사용**

whitelist 배열을 push 로 추가하여서 실시간으로 허용 및 제거 가능

```jsx
var express = require('express');
var app = express();
var whitelist = ['http://example1.com','http://example2.com']
var corsOptions = {
	origin: function(origin,callback)    {
		if(whitelist.indexOf(origin) !==-1){
			callback (null,true);
		} 
		else{
			callback (new Error('Not allowed by CORS'))
		}
	}
}
app.get('/products/:id', cors(corsOptions),function(req,res,next){
res.json({msg: 'This is CORS-enabled for a whitelisted domain.'})
});
```