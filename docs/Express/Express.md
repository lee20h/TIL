---
sidebar: auto
---
# Express

## 설치
Node.js를 위한 빠르고 개방적인 간결한 웹 프레임워크

```js
$ npm install express-generator -g
```

해당 명령어를 통해 express을 설치할 수 있다. 이 때의 node.js가 설치되어 있다고 가정하고 진행하는 것이다.

```js
$ express --view=pug 디렉토리 이름
```

express 앱을 원하는 디렉토리로 작성한다.

```js
npm install
> set DEBUG=디렉토리 이름:* & npm start
```

해당 디렉토리로 이동 후 npm을 설치하고 Debug 설정 후 npm start을 통해서 localhost:3000에 앱에 액세스할 수 있게 된다.

## 라우팅  

라우팅이라는 개념이 등장하는데 이것은 URI 및 특정한 HTTP 요청 메소드인 특정 엔드포인트에 대한 클라이언트 요청에 애플리케이션이 응답하는 방법을 결정하는 것이다. 이 때 각 라우트는 하나 이상의 핸들러 함수를 가질 수 있으며, 라우트 경로가 일치할 때 실행이 된다. 라우트 경로는 문자열, 문자열 패턴 또는 정규식일 수 있다.

### 라우트의 구조  

```js
app.METHOD(PATH, HANDLER)
```

- app : express의 인스턴스
- METHOD : HTTP 요청 메소드 (대표적으로 GET, POST, PUT, DELETE 등. 과 모든 요청 메소드를 뜻하는 `all`)
- PATH : 서버의 경로
- HANDLER : 라우트가 일치될 때 실행하는 함수

예시를 통해 이해해보자.
```js
app.get('/', function (req, res) {
	res.send('Hello Wolrd!');
});
```
이 예시는 홈페이지에서 Hello World!로 응답하는 코드이다.  

이어서 봐보면
```js
app.post('/', function(req, res) {
	res.send('Got a POST request');
});
```
애플리케이션의 루트 라우트(`'/'`)에서 POST 요청에 응답하는 코드이다.  

```js
app.put('/user', function(req, res) {
	res.send('Got a PUT request at /user');
});
```
마찬 가지로 /user 라우트에 대한 PUT 요청의 응답이다.

```js
app.delete('/user', fucntion (req, res) {
	res.send('Got a DELETE request at /user');
});
```
마지막으로 같은 예제로 /user 라우트에 대한 DELETE 요청에 응답하는 코드이다.  

### 라우트 핸들러  

라우트 경로가 일치될 때 실행되는 함수로 미들웨어와 비슷하게 작동하는 여러 콜백 함수를 제공하여 요청을 처리할 수 있다. 차이점은 `next('route')`을 호출하여 나머지 라우트 콜백을 우회할 수 있다. 이것은 라우트에 대한 조건을 지정 후, 현재의 라우트를 계속할 필요 없을 경우 후속 라우트에 제어를 전달할 수 있다.  

예시와 함께 설명을 보자.  
```js
app.get('/example/a, function(req, res) {
	res.send('Hello from A!');
});
```
하나의 콜백 함수는 하나의 라우트를 처리할 수 있다.  

```js
app.get('/example/b', function (req, res, next) {
  console.log('the response will be sent by the next function ...');
  next();
}, function (req, res) {
  res.send('Hello from B!');
});
```
2개 이상의 콜백 함수도 하나의 라우트로 처리할 수 있다. 이 때 무조건 `next` 오브젝트를 지정해주어야 한다.

```js
var cb0 = function (req, res, next) {
  console.log('CB0');
  next();
}

var cb1 = function (req, res, next) {
  console.log('CB1');
  next();
}

var cb2 = function (req, res) {
  res.send('Hello from C!');
}

app.get('/example/c', [cb0, cb1, cb2]);
```

하나의 콜백 함수 배열은 하나의 라우트를 처리할 수 있다. 따라서 경로를 지정해준 뒤 배열로 핸들러를 지정해줄 수 있다.

```js
var cb0 = function (req, res, next) {
  console.log('CB0');
  next();
}

var cb1 = function (req, res, next) {
  console.log('CB1');
  next();
}

app.get('/example/d', [cb0, cb1], function (req, res, next) {
  console.log('the response will be sent by the next function ...');
  next();
}, function (req, res) {
  res.send('Hello from D!');
});
```
위에서 이야기한 내용들을 섞어서도 가능하다. 무슨 말이냐면, 독립적인 함수와 함수 배열의 조합으로 하나의 라우트를 처리할 수 있다.

### 응답 메소드
응답 오브젝트(`res`)에 대한 메소드는 응답을 클라이언트로 전송하고 요청-응답 주기를 종료할 수 있다. 따라서 라우트 핸들러에서 해당 메소드 중 하나도 호출되지 않는다면 클아이언트 요청은 정지된채로 방치되게 된다.
| 메소드 | 설명 |
|-------|-------|
| res.download() | 파일이 다운로드 되도록 프롬프트 |
| res.end() | 응답 프로세스를 종료 |
| res.json() | JSON 응답을 전송 |
| res.jsonp() | JSNOP 지원을 통해 JSON 응답 전송 |
| res.redirect() | 요청의 경로를 재지정 |
| res.render() | 보기 템플릿을 렌더링 |
| res.send() | 다양한 유형의 응답 전송 |
| res.sendFile | 파일을 옥텟 스트림의 형태로 전송 |
| res.sendStatus() | 응답 상태 코드를 설정 후 해당 코드를 문자열로 표현한 내용을 응답 본문 전송 |

**app.route()**  

라우트 경로에 대하여 체인 가능한 라우트 핸들러를 작성할 수 있다. 경로가 같으므로 모듈식 라우틀르 작성하면 가독성이 증가하며 편리하게 코딩을 할 수 있다.
```js
app.route('/book')
	.get(function(req, res) {
		res.send('Get a random book');
	})
	.post(function(req, res) {
		res.send('Add a book');
	})
	.put(function(req, res) {
		res.send('Update the book');
	});
```

**express.Router**

`app.route()`와 비슷하게 `express.Router` 클래스를 사용하여 모듈식 마운팅 가능한 핸들러를 작성할 수 있다. Router 인스턴스는 완전한 미들웨어이자, 라우팅 시스템으로 미니 앱(mini-app)이라고 불리기도 한다.  

```js
// bird.js

var express = require('express');
var router = express.Router();

// middleware that is specific to this router
router.use(function timeLog(req, res, next) {
  console.log('Time: ', Date.now());
  next();
});

// define the home page route
router.get('/', function(req, res) {
  res.send('Birds home page');
});

// define the about route
router.get('/about', function(req, res) {
  res.send('About birds');
});

module.exports = router;

// app.js
var birds = require('./birds');
...
app.use('/birds', birds);
```
이러하게 라우터를 모듈로 작성하고, 미들웨어 함수를 로드하고 다른 라우트들을 정의한 뒤 기본 앱의 한 경로에 라우터 모듈을 마운트한다. 그 뒤 앱 내에서 라우터 모듈을 로드 하게 되면 라우터에서 정의해놓은 라우트들의 요청을 처리할 수 있으며, 미들웨어 함수를 호출할 수 있게 된다.  



## 정적 파일 이용

이미지나, CSS 파일 및 JavaScript와 같은 정적 파일을 제공하려면 Express의 기본 제공 미들웨어 함수인 `express static`을 이용하여야 한다.  

정적 자산이 포함된 디렉토리의 이름을 `express.static` 미들웨어 함수에 전닳하면 파일의 직접적인 제공이 가능하다.  

```js
app.use(express.static('public'));
```
위와 같은 코드를 이용하면 public 디렉토리에 있는 정적 파일을 제공할 수 있다.  
따라서 다음과 같이 접근을 하게되면 해당 정적 파일을 그대로 접근할 수 있게 된다.
```js
localhost:3000/img/cat.jpg
localhost:3000/css/style.css
localhost:3000/js/app.js
localhost:3000/index.html
```

여러 개의 디렉토리를 정적 파일이 있는 디렉토리로 등록을 할 수 있는데 해당 문법을 그대로 사용하면 된다.
```js
app.use(express.static('public'))
app.use(express.static('files'))
```

이렇게 사용하면 되나, `express.static`을 설정한 순서대로 파일을 검색한다. 따라서 같은 이름의 파일이 존재한다면 먼저 설정한 파일을 찾는다는 말이 된다.  

또, 정적 파일을 접근 시에 가상 경로를 만들어서 파일에 접근하게 하고 싶다면 아래와 같은 문법을 사용하면 된다.  
```js
app.use('/static', express.static('public'));
```

```js
localhost:3000/static/img/cat.jpg
localhost:3000/static/css/style.css
localhost:3000/static/js/app.js
localhost:3000/static/index.html
```

`express.static` 함수에 제공되는 경로는 node 프로세스가 실행되는 디렉토리에 상대적이므로 다른 디렉토리에서 express 앱을 실행하는 경우에는 절대 경로로 주어지는 것이 안정성을 높일 수 있다.

## 미들웨어  

미들웨어함수는 요청 오브젝트(`req`), 응답 오브젝트(`res`), 그리고 애플레키에션의 요청-응답 주기 중 그 다음의 미들웨어 함수에 대한 액세스 권한을 갖는 함수이다. 미들웨어 함수는 일반적으로 `next`라는 이름의 변수로 표시된다.  

- 모든 코드를 실행
- 요청 및 응답 오브젝트에 대한 변경을 실행
- 요청-응답 주기를 종료
- 스택 내의 그 다음 미들웨어를 호출

미들웨어 함수는 이러한 작업을 수행할 수 있다.

현재의 미들웨어 함수가 요청-응답 주기를 종료하지 않았다면 `next()`을 호출하여 그 다음 미들웨어 함수에 제어를 전달해야한다. 그렇지 않으면 해당 요청은 정지된 채 방치된다.  

![Express 폼](https://expressjs.com/images/express-mw.png)  
express 공식홈페이지의 사진 설명  

사진을 통해서 미들웨어 함수 호출의 요소에 대해 알아 볼 수 있다.
- `get` : HTTP 메소드
- `'/'` : 라우트
- `function` : 함수
- `req` : HTTP 요청 인수
- `res` : HTTP 응답 인수
- `next` : 콜백 인수

예시로 두 개의 미들함수를 정의한 간단한 코드를 살펴보자.
```js
var express = require('express');
var app = express();

app.get('/', function (req, res) {
  res.send('Hello World!');
});

app.listen(3000);
```
루트 경로의 GET 요청을 받고 응답을 `Hello World!`로 보내는 함수를 정의했다.  

미들웨어함수를 정의하고 사용하는 방법을 짧게 예제를 통해 봐보자

```js
var express = require('express');
var app = express();

var myLogger = function (req, res, next) {
  console.log('LOGGED');
  next();
};

app.use(myLogger);

app.get('/', function (req, res) {
  res.send('Hello World!');
});

app.listen(3000);
```
이렇게 짜게되면 앱이 요청을 수신할 때마다 "LOGGED"라는 메세지를 터미널에 출력하게 된다. 이때의 미들웨어의 로드 순서는 중요하며, 먼저 로드된 순서대로 실행이 되게된다. 만약 루트 경로에 대한 라우팅 이후에 `MyLogger`가 로드되면, 루트 경로의 라우트 핸들러가 요청-응답 주기를 종료하므로 `MyLogger`에 닿지 못해서 실행이 될 일이 없게 된다.  
그와 달리 `MyLogger` 미들웨어 함수는 메시지를 출력 후 `next()` 함수를 호출하여 스택 내의 그 다음 미들웨어 함수에게 요청을 전달한다. 따라서 루트 경로에 라우팅을 할 수 있게 된다.  

그러므로 라우트를 정의하고 사용할 때에 순서를 유념하고 사용해야 원하는 개발을 할 수 있을 것이다.

마지막으로 여러 유형의 미들웨어를 살펴본다.

- 애플리케이션 레벨 미들웨어
- 라우터 레벨 미들웨어
- 오류 처리 미들웨어
- 기본 제공 미들웨어
- 써드파티 미들웨어

이러한 종류가 존재하나, 위의 3가지 미들웨어를 살펴볼 것이다. 개발할 때 직접적으로 사용했던 미들웨어이였기 때문이다.  

### 애플리케이션 레벨 미들웨어  

`app.use()`나 `app.METHOD()` 함수를 이용할 수 있는 애플리케이션 레벨에 존재하는 미들웨어를 뜻하며, 이 미들웨어 함수는 일련의 미들웨어 함수를 함께 로드 할 수 있으며, 하나의 마운트 위치에 미들웨어 시스템의 하위 스택을 작성할 수 있다.  

예제로 살펴보자.  
```js
var app = express();

app.use(function (req, res, next) {
  console.log('Time:', Date.now());
  next();
});
```
지금까지 자주 보았던 미들웨어로, 마운트 경로가 없는 미들웨어 함수이다. 이 함수는 앱이 요청을 수신할 때마다 실행하게 된다.  

```js
app.use('/user/:id', function (req, res, next) {
  console.log('Request Type:', req.method);
  next();
});
```
이 예시는 `/user/:id` 경로에 마운트 되는 미들웨어 함수이다. 이 함수는 모든 유형의 HTTP 요청에 대해 실행이 된다.

```js
app.get('/user/:id', function (req, res, next) {
  res.send('USER');
});
```
라우트 및 해당 라우트의 핸들러 함수로, `/user/:id`경로의 GET 요청을 처리한다.

```js
app.use('/user/:id', function(req, res, next) {
  console.log('Request URL:', req.originalUrl);
  next();
}, function (req, res, next) {
  console.log('Request Type:', req.method);
  next();
});
```
라우터 핸들러를 이용하면 하나의 경로에 대해 여러 라우트를 정의할 수 있다. 해당 /user/:id 경로에 대한 GET 요청에 대해 2개의 라우트를 정의하나, 첫 번째 라우트가 요청-응답 주기를 종료시키므로 두 번째 라우트는 호출되지 않는다.

```js
app.get('/user/:id', function (req, res, next) {
  console.log('ID:', req.params.id);
  next();
}, function (req, res, next) {
  res.send('User Info');
});

// handler for the /user/:id path, which prints the user ID
app.get('/user/:id', function (req, res, next) {
  res.end(req.params.id);
});
```
경로에 대한 GET 요청을 처리하는 미들웨어 하위 스택을 표시하는 예제로, 라우터 미들웨어 스택의 나머지 미들웨어 함수들을 건너뛰려면 `next('route')`을 호출하여 제어를 그 다음 라우트로 전달해야한다. 이 때 `next('route')`는 app.METHOD()나 router.METHOD() 함수를 이용해 로드된 미들웨어 함수에서만 작동된다.  

```js
app.get('/user/:id', function (req, res, next) {
  // if the user ID is 0, skip to the next route
  if (req.params.id == 0) next('route');
  // otherwise pass the control to the next middleware function in this stack
  else next(); //
}, function (req, res, next) {
  // render a regular page
  res.render('regular');
});

// handler for the /user/:id path, which renders a special page
app.get('/user/:id', function (req, res, next) {
  res.render('special');
});
```
마지막으로 미들웨어 하위 스택으로 넘어가는 예제를 보여주며 이러한 코딩도 가능하다는 것을 보여준다.

### 라우터 레벨 미들웨어
라우터 레벨 미들웨어는 `express.Router()` 인스턴스에 바인드된다는 점을 제외하면 애플레키에션 레벨 미들웨어와 동일한 방식으로 작동한다.
```js
var app = express();
var router = express.Router();

// a middleware function with no mount path. This code is executed for every request to the router
router.use(function (req, res, next) {
  console.log('Time:', Date.now());
  next();
});

// a middleware sub-stack shows request info for any type of HTTP request to the /user/:id path
router.use('/user/:id', function(req, res, next) {
  console.log('Request URL:', req.originalUrl);
  next();
}, function (req, res, next) {
  console.log('Request Type:', req.method);
  next();
});

// a middleware sub-stack that handles GET requests to the /user/:id path
router.get('/user/:id', function (req, res, next) {
  // if the user ID is 0, skip to the next router
  if (req.params.id == 0) next('route');
  // otherwise pass control to the next middleware function in this stack
  else next(); //
}, function (req, res, next) {
  // render a regular page
  res.render('regular');
});

// handler for the /user/:id path, which renders a special page
router.get('/user/:id', function (req, res, next) {
  console.log(req.params.id);
  res.render('special');
});

// mount the router on the app
app.use('/', router);
```
지금까지의 애플리케이션 레벨 미들웨어에서 사용된 함수들을 router 레벨에서 돌릴 수 있게 변경한 예제이다. 그리고 마지막에 app이 존재하는 app.js와 같은 파일에서 `app.use('path', router)`을 명시해서 마운트를 해줘야한다.  

### 오류 처리 미들웨어
다른 미들웨어 함수와 동일한 방법으로 정의할 수 있지만 오류 처리 함수는 인수를 3개가 아닌 4개(err, req, res, next)를 가지므로 분류가 새롭게 된다고 생각하면 된다.
```js
app.use(function(err, req, res, next) {
  console.error(err.stack);
  res.status(500).send('Something broke!');
});
```

## Express DB사용

- MySQL
```js
npm install mysql
```
```js
var mysql      = require('mysql');
var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'dbuser',
  password : 's3kreee7'
});

connection.connect();

connection.query('SELECT 1 + 1 AS solution', function(err, rows, fields) {
  if (err) throw err;
  console.log('The solution is: ', rows[0].solution);
});

connection.end();
```
- MongoDB
```js
npm install mongodb
```
```js
var MongoClient = require('mongodb').MongoClient;

MongoClient.connect('mongodb://localhost:27017/animals', function(err, db) {
  if (err) {
    throw err;
  }
  db.collection('mammals').find().toArray(function(err, result) {
    if (err) {
      throw err;
    }
    console.log(result);
  });
});
```
- PostgreSQL
```js
npm install pg-promise
```
```js
var pgp = require("pg-promise")(/*options*/);
var db = pgp("postgres://username:password@host:port/database");

db.one("SELECT $1 AS value", 123)
    .then(function (data) {
        console.log("DATA:", data.value);
    })
    .catch(function (error) {
        console.log("ERROR:", error);
    });
```
- SQLite
```js
npm install sqlite3
```
```js
var sqlite3 = require('sqlite3').verbose();
var db = new sqlite3.Database(':memory:');

db.serialize(function() {

  db.run('CREATE TABLE lorem (info TEXT)');
  var stmt = db.prepare('INSERT INTO lorem VALUES (?)');

  for (var i = 0; i < 10; i++) {
    stmt.run('Ipsum ' + i);
  }

  stmt.finalize();

  db.each('SELECT rowid AS id, info FROM lorem', function(err, row) {
    console.log(row.id + ': ' + row.info);
  });
});

db.close();
```