# Passport Strategy

## passport-Github

흔히들 사용하는 서비스 중에서 Github 아이디를 통해서 가입하거나 로그인하여 해당 서비스를 진행하는 것을 보았을 것이다. 그 부분을 도와주는 서드파티로, Passport 전략 중 Gtihub을 선택해서 사용할 때 매우 편한 기능을 가진 서드파티이다.

- [가이드라인](http://www.passportjs.org/packages/passport-github/)

### 설치

```
$ npm install passport-github
```

### 사용

먼저 Github에서 [Github Developer Applications 등록](https://github.com/settings/applications/new)하고 진행해야 한다.

```js
var GitHubStrategy = require("passport-github").Strategy;

passport.use(
  new GitHubStrategy(
    {
      clientID: GITHUB_CLIENT_ID,
      clientSecret: GITHUB_CLIENT_SECRET,
      callbackURL: "http://127.0.0.1:3000/auth/github/callback",
    },
    function (accessToken, refreshToken, profile, cb) {
      User.findOrCreate({ githubId: profile.id }, function (err, user) {
        return cb(err, user);
      });
    }
  )
);
```

가이드라인에서는 위와 같이 안내하고 있는데 JS 버전에 맞춰서 변화를 줄 수 있다. clientID와 Secret의 경우에는 Github Oauth application setting에서 값을 확인할 수 있다. 이후에는 .env 파일을 통해서 접근하게 되면 보안에 용이하다. CallbackURL도 애플리케이션 등록할 때 정한 CallbackURL을 적으면 된다.

그 뒤 함수를 통해서 유저를 찾거나 생성할 수 있는데, 이 함수는 바꿔서 사용해도 좋다. 먼저 유저를 찾은 뒤 이메일 등을 비교하여 같다면, Github ID를 추가하는 식으로 진행하고 없다면 새로운 유저를 생성하는 식으로 진행해도 좋다. 또한 profile에는 id, email, name, avatar_URL 등 여러 가지 사용자 정보를 제공하므로, 자신의 데이터베이스 모델에 맞는 정보를 사용하면 된다.

cb의 경우에는 에러와 찾은 유저 혹은 생성한 유저를 파라미터로 넘기면 된다. 에러를 캐치하는 경우에는 `cb(error)` 등 에러만 넘기면 되며, 성공적으로 이뤄졌다면 찾은 유저 혹은 생성한 유저의 객체를 넣어주면 된다.

이 부분을 Express의 Route를 적용하여 Callback과 passport-github을 분리하고 사용하는 콜백함수도 분리하여서 모듈로 가져다가 사용할 수 있다. 추가적으로 로그아웃은 `req.logout()`함수를 사용하면 passport에서 알아서 쿠키와 로그인 정보를 없애고 로그아웃을 가능하게 한다.

## passport-facebook

passport로 facebook 아이디를 이용해서 인증을 할 수 있게 해주는 서드파티이다. 다른 서비스에 비해서 페이스북은 상당히 깐깐하다. 따라서 진행하면서 생긴 시행착오에 대해서 메모하려한다.

- [가이드라인](http://www.passportjs.org/packages/passport-facebook/)

### 설치

```
$ npm install passport-facebook
```

### 사용

먼저 [페이스북 개발자](https://developers.facebook.com/)에 등록한 뒤 애플리케이션을 생성해야한다. 그 이후에 다른 passport 서드파티와 마찬가지로 클라이언트 ID와 Secret을 받아서 애플리케이션에 기입해준다. 이후에 콜백함수까지 passport의 템플릿에 맞춰서 작성하는 것까지 동일하다.

```js
passport.use(
  new FacebookStrategy(
    {
      clientID: FACEBOOK_APP_ID,
      clientSecret: FACEBOOK_APP_SECRET,
      callbackURL: "http://localhost:3000/auth/facebook/callback",
    },
    function (accessToken, refreshToken, profile, cb) {
      User.findOrCreate({ facebookId: profile.id }, function (err, user) {
        return cb(err, user);
      });
    }
  )
);
```

따라서 여기까진 이전에 github에서 작성한 내용을 참고하여 사용하면 된다. 페이스북이 다른 서비스와 다른 점은 바로 https 보안 연결만 받아준다는 것이다. 따라서 콜백함수에서 리다이렉트되는 URL이 https여야한다는 것이다. 이말은 즉, 개발한 앱 자체가 보안 연결로 이뤄져야 한다는 말이다.

테스트를 위해서 `localtunnel` 서드파티를 받아서 임시로 보안 연결 URL을 생성하여 페이스북 개발 앱 설정에 등록하였으나, 임시로 생성한 URL이라 그런건지 아니면 다른 이유인지는 확실치 않으나 악의가 있는 URL이라고 거절 당했다. 이외에도 애플리케이션을 라이브 모드로 바꿀려면 여러 URL을 기입해야하는데, 전부 https를 지원해야한다. 테스트를 위한 앱 외에 정식으로 출시한 후 보안 연결을 취득한 뒤 사용해야할 것 같다.

다른 서드파티와 마찬가지로 passport가 원하는 설정 값을 다 기입했으나, 이러한 문제로 성공적으로 완료하지 못했다. 허나, 다른 카카오나 네이버, 구글과 같은 서비스와의 연결은 깃허브를 사용한 연결과 매우 흡사하므로 가이드라인을 참고하여서 진행하면 된다.

- [passport-kakao](http://www.passportjs.org/packages/passport-kakao/)
- [passport-naver](http://www.passportjs.org/packages/passport-naver/)
- [passport-google](http://www.passportjs.org/packages/passport-google/)

추가적으로 passport에서 다른 서비스와 연결하여 인증하는 부분은 OAuth 2.0을 모두 이용하는 것 같다.

## Passport-local-mongoose를 이용한 ChangePassword

- [Passport-local-mongoose 레포지토리](https://github.com/saintedlama/passport-local-mongoose)

Passport-local-mongoose 서드파티를 이용하여 MongoDB에 등록된 사용자의 패스워드를 변경할 때 사용하는 함수에 대해 알아보자. 이미 서드파티에서 개발자가 편리하게 이용하게 함수로 구현되어 제공된다. 다음과 같은 설명을 통해 함수를 이해할 수 있다.

> changePassword(oldPassword, newPassword, [cb])
>
> > Changes a user's password hash and salt, resets the user's number of failed password attempts and saves the user object (everything only if oldPassword is correct). If no callback cb is provided a Promise is returned. If oldPassword does not match the user's old password, an IncorrectPasswordError is passed to cb or the Promise is rejected.

### 비밀번호 변경

사용자의 비밀번호를 변경하기 위해서는 먼저 현재 비밀번호와 새 비밀번호, 새 비밀번호 확인까지 3개의 필드에 값이 적힌다. 비밀번호는 저장될 때 Plain Text가 적히는게 아니라 Salt와 Hash에 의해 암호화된 텍스트로 변환된 값이 저장이 된다. 따라서 먼저, 현재 비밀번호를 받아 같은 Salt와 Hash에 의해서 암호화 시킨 뒤 비교를 하고 맞다면 변경을 하는 식으로 구현되어 있다. 만약 틀린다면 콜백함수에 의해서 처리되거나 콜백함수를 명시하지 않더라도 에러로 중단된다.

따라서 개발자가 해결해야 하는 부분은 3가지 필드에서 넘어온 값 중 새 비밀번호와 새 비밀번호 확인 필드의 값들을 먼저 같은지 체크하고 그 값을 `changePassword(oldPassword, newPassword, [cb])`에 넣어줘야 한다. 현재 비밀번호 필드의 값과 MongoDB의 저장된 값을 비교하는 것은 함수에서 구현되어 있으므로 훨씬 편하게 비밀번호 변경을 구현할 수 있다.

이 부분은 Passport 전략 중 local을 선택하여 MongoDB ODM 중 Mongoose를 사용할 때 편의를 주는 passport-local-mongoose 서드파티를 이용할 때로, passport의 다른 전략을 사용한다면 맞는 서드파티를 찾아서 API를 적용해야 한다.
