---
sidebar: auto
---
# http-errors

## 설치

```jsx
npm install http-errors
```

## 예시

```jsx
var createError = require('http-errors')
var express = require('express')
var app = express()

app.use(function (req, res, next) {
  if (!req.user) return next(createError(401, 'Please login to view this page.'))
  next()
})
```

error을 캐치하고 해당 에러를 에러코드에 맞춰서 에러를 처리할 수 있다.

## 실제 예시 코드

```jsx
// catch 404(not found) and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});
```

프로젝트에서는 app이 404 에러코드(존재하지 않은 페이지)를 받으면 해당 에러를 처리해주고 next()을 통해서 다음 미들웨어 함수로 넘겨준다. 밑에 error handler 또한 에러가 있다면 메시지와 에러를 `res`객체에 담아서 보낸다.