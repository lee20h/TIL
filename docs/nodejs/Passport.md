  
 
  

# Passport

Node.js 인증 미들웨어인 Passport.js는 Node.js의 프레임워크인 express를 기반으로 한다. 인증 방식은 엄청 다양하다. 로컬에서의 아이디와 비밀번호를 이용한 로그인 부터 공신력있는 애플리케이션의 회원이라면 그의 정보로 인증하는 방법까지 다채롭다. 예를 들어 facebook, google, twitter 등 아이디가 있다면 따로 회원가입을 하지 않아도 그 정보로 인증을 할 수 있다는 것이다.  

그러한 기능을 구현 원리를 숨기고 동일한 코드로 구현할 수 있게되어, 시간과 노력이 단축해주는 미들웨어이다.  

```shell
$ npm install passport
```

passport를 사용할 때는 반드시 필요한 미들웨어들을 import후 사용해야한다.  


- express : passport.js는 express를 기반으로 작동하기 때문에 반드시 필요
- body-parser : 브라우저에서 입력받은 정보에 접근
- cookie-parser, express-session : passport는 인증이 실행된 뒤 유저의 정보를 express-session을 이용하여 저장
- passport, passport-local : strategy는 알맞게 불러오시면 됩니다.
- 자신이 사용하는 데이터베이스 모듈

```js
const express = require('express');
const router = express.Router();
const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const passport = require('passport')
  , LocalStrategy = require('passport-local').Strategy;
```

import 이후에는 사용할 준비가 필요하다. 그러한 작업들을 아래에 명시했다. 이 때 순서가 중요하다는 것을 기억해야한다.  

```js
router.use(bodyParser.json());
router.use(bodyParser.urlencoded({ extended: false }));
router.use(cookieParser('keyboard cat'));
router.use(session({secret: 'keyboard cat'}));
router.use(passport.initialize());
router.use(passport.session());
```

세션을 사용하게 된다면 세션을 먼저 사용한 뒤 passport의 초기화와 세션을 잡아줘야한다.  

이런 준비가 끝나면 이제 passport을 사용할 수 있게 되었다.  

## Strategy

passport는 Strategy라는 것을 사용한다. 모든 passport의 플러그인들을 사용하려면 전략을 짜 주어야 한다. 위에서 말했던 여러 공신력 있는 애플리케이션들의 가입 정보로 인증 받는 것 또한 전략 중 하나이다. 각각 애플리케이션 별로 전략들이 정의되어 있고 많이 사용하는 것이 `LocalStrategy`다. 
 
해당 전략의 경우에는 우리들이 애플리케이션이나 웹을 만들거나 사용할 때 많이 사용하는 로그인 방법이다. ID와 Password를 이용한 전통적인 로그인 방법으로 밑에서 소개할 토이 프로젝트 코드에서도 해당 전략을 짜서 이용하였다.

## 코드

진행중인 토이 프로젝트에서는 해당 passport 미들웨어를 가지고 로그인시 JWT를 서버단에서 클라이언트단으로 넘겨줘서 사용하게 하였다.  

다음의 코드와 같이 사용했다.

`auth.js`
```js
const passport = require("passport");
const passportJWT = require("passport-jwt");
const admin = require("../models").admin;
const cfg = require("../config/jwt_config");
const ExtractJwt = passportJWT.ExtractJwt;
const Strategy = passportJWT.Strategy;
const params = {
  secretOrKey: cfg.jwtSecret,
  // 클라이언트에서 서버로 토큰을 전달하는 방식  (header, querystring, body 등이 있다.)
  // header 의 경우 다음과 같이 써야 한다 { key: 'Authorization', value: 'JWT' + 토큰
  jwtFromRequest: ExtractJwt.fromAuthHeaderWithScheme("jwt")
};

module.exports = function () {
  const strategy = new Strategy(params, function (payload, done) {
    const check = admin.find(function (input) {
      return input.id === payload.id;
    });
    if (check) {
      return done(null, {
        id: check.id,
      });
    } else {
      return done(new Error("User not found"), null);
    }
  });
  passport.use(strategy);
  return {
    initialize: function () {
      return passport.initialize();
    },
    authenticate: function () {
      return passport.authenticate("jwt", cfg.jwtSession);
    },
  };
};
```


`admin.js` 
```js
var express = require("express");
var router = express.Router();
var jwt = require("jsonwebtoken");
var admin = require("../models").admin;
var cfg = require("../config/jwt_config");

router.post('/login', async (req, res) => {
    if(req.body.id && req.body.password) {
        const id = req.body.id;
        const password = req.body.password;
        var idDb, pwdDb;
        await admin.findOne({
            where : {id : id}
        })
        .then(adminDb => {
            idDb = adminDb.dataValues.id;
            pwdDb = adminDb.dataValues.password;
        })
        .catch(err => {
            console.error(err);
        });
        const check = (idDb == id) && (pwdDb == password);
        if (check) {
            const payload = {
                id: idDb
            };
            const token = jwt.encode(payload, cfg.jwtSecret);
            res.json({
                token: token
            });
        }
        else {
            res.sendStatus(401);
        }
    }
    else {
        res.sendStatus(401);
    }
});

router.get('/adminCheck', (req, res) => {
    const token = req.headers['x-access-token'] || req.query.token;

    if(!token) {
        return res.status(403).json({
            suceess: false,
            message: 'not logged in'
        });
    }
    
    /* 토큰 유효성 검사 */
    const vaild = new Promise((resolve, reject) => {
        jwt.verify(token, cfg.jwtSecret, (err, decoded) => {
            if (err) reject(err);
            else resolve(decoded);
        })
    });
    /* 유효하지 않은 토큰으로 403 에러 처리 */
    const onError = (error) => {
        res.status(403).json({
            success: false,
            message: error.message
        })
    };

    vaild.then((decoded) => {
        res.json(decoded);
    }).catch(onError);
});

module.exports = router;
```

admin에서 id와 password를 클라이언트단에서 넘겨받아 디비와 비교 한 뒤 jwt을 인코딩하여 다시 보내주는 코드이다.  

auth의 경우에는 passport의 전략을 잡아주고 jwt의 유효성을 확인하기 위해 클라이언트단에서 넘어왔을 때 체크해주기 위한 함수로 작성이 되어있다.  