# 📙 Today I Learned

## 규칙

- 기억에 남는 내용 기록 후 [정적 웹페이지](https://lee20h.github.io/TIL/)에 정리
- Github Action으로 배포
- markdown으로 작성
- 문제 풀고 [Problem Solving](https://github.com/lee20h/TIL/tree/master/Problem%20Solving) 폴더에 모으기

---

# 2020년

| [5월](./month/5월) | [6월](./month/6월) | [7월](./month/7월) | [8월](./month/8월) | [9월](./month/9월) | [10월](./month/10월) | [11월](./month/11월) | [12월](./month/12월) |
| ------------------ | ------------------ | ------------------ | ------------------ | ------------------ | -------------------- | -------------------- | -------------------- |

---

- 1 日

# 2020년 회고

2020년에는 정말 많은 일이 있었다.

1. 자바스크립트 접함
2. 프로젝트 진행 경험 (Nodejs, 해커톤)
3. 현장실습
4. SQLD
5. 코딩테스트 경험, PS
6. 학부생 3학년 마무리

2020년에는 전염병으로 인해 언택트로 진행되는 일들이 많았고, 온라인으로도 많은 경험을 할 수 있었다. 이러한 시대에 맞춰서 도움이 되는 애플리케이션을 만드는 개발자들이 대단해보였다. 많은 것들이 제한되고 위축된 것이 많으나, 여전히 해야할 일은 많고 세상은 돌아간다.

## 자바스크립트

자바스크립트를 올해 초에 접하게 되어 Vue.js 인강을 통해서 자바스크립트를 접한 뒤 Node.js를 프로젝트를 해보면서 공부를 시작하였다. 프로젝트를 진행하면서 느낀 점은 무엇이든 **기초가 제일 중요하다**라는 생각이다. 자바스크립트에 대해 기초를 확실하게 다지지 않고 프레임워크를 통해 결과물만 얻을려고 하고 여러 포스팅을 보면서 원리를 이해하지 않은 채 굴러가기만 하면 된다는 생각이 지배적이였다. 이후 다른 간단한 애플리케이션을 만들려는 시도도 안해보고 시간이 흐른 뒤에 접한 자바스크립트는 매우 어려웠다. 그래서 올해 중순에 처음부터 자바스크립트에 대해 공부를 시작하였고 지금도 완벽하진 않지만 조금은 이해하는 수준이 된 것 같다.

## 프로젝트

프로젝트의 경우에는 Node.js로 Express 프레임워크를 사용한 MVC패턴을 적용한 대학교 중고책방 사이트와 전북 해커톤 대회에서 만든 손주 프로그램이다. 중고책방의 경우에는 Model은 MySQL + Sequeilze, View는 Vue.js로 잡고 서버단을 코딩하였다. 서버단에서 REST API의 개념을 잡고 API를 만들거나 DB 공부를 겸하면서 코딩을 하였다. 이 때의 경험이 꽤 큰 역할을 해주었다. 하지만 코로나로 인해 제대로 서비스는 해보지 못하고 마무리가 되었다.

손주 프로그램의 경우에는 전북 해커톤에서 기획자로 참여하여 만들게 되었는데, 저시력자들을 위해서 읽어주는 기기를 목표로 제작하였다. 이 때 사용한 것은 라즈베리파이와 카메라, 스크린을 단 뒤 파이썬으로 코딩하여 ORM과 TTS를 불러들여서 사용하였다. 코딩에는 큰 관여를 하지 않았지만 기획하는 입장에서 꽤 신경 쓸 것이 많고 여러가지 관점에서 봐야한다는 것을 배울 수 있었다. 우수상으로 마무리할 수 있었다.

## 현장실습

여름방학에 진행한 현장실습은 크게 변화를 준 것이 없었다. 그 당시에 기업 자체가 바빠서 크게 관심을 써주지 못해 대부분이 공부하는 식으로 흘러가게 되었다. 현재 학교에서 서비스하는 사이트에 기능을 추가하면서 공부를 할 수 있을거라 생각했으나, 전혀 다른 점에서 깨달은 것이 있다. 바로, 리팩터링의 중요성이다. 개발이 된지 꽤 시간이 흐른 서비스라 코드들이 엄청 쌓여있고 소스마다 사용하는 컨벤션이나 라이브러리가 전부 달라서 통일이 되지 않은 것을 느꼈다. 그리고 이 부분에서 인수인계가 전혀 없어서 소스와 기능을 이해할려면 직접 소스들을 만져보면서 파악해야했다. 시간이 너무 많이 걸렸고 어떤 부분은 선임 개발자도 코딩이 왜 그렇게 했는지도 모르는 부분이 있었다. 소프트웨어공학에 대해서 배우기 전이였지만 리팩터링의 중요성을 직접 몸으로 부딪혀서 알게 된 계기였다. 이후에 클린 코드 책을 접하게 되기도 하였다.

## 데이터베이스

이번에 데이터베이스를 공부를 많이 한 해이기도 하다. SQLD를 취득하고 싶어서 SQL에 대해 공부를 하여 취득하고, 다른 프로젝트들이나 강의를 통해서 NoSQL인 MongoDB를 사용하기 위해서 여러 자료를 통해서 공부도 하고 ORM인 Mongoose와 Sequelize를 사용해보기도 했다. 학교에서 진행하는 강의보다도 직접 찾아보고 사용해보고 설계 해본 것이 가장 좋은 경험이였다.

## 알고리즘

알고리즘을 열심히 한 해이기도 한데, 그 중 ACM ICPC 참여와 코딩테스트 참여한 것이 가장 기억에 남는다. ACM ICPC 교내 은상도 받고 참여한 것에 큰 의의를 두지만 대회와 코딩테스트에서 원하는 알고리즘은 다른 것을 알게 되었다. 코딩테스트는 카카오 공채와 추천팀 인턴, 우아한테크코스 등에 참여했다. 전부 합격을 받진 못했지만 참여함으로써 2021년도에 지원할 때 도움이 될 것 같다.

## 3학년 마무리

2019년보다 더 길게 느껴진 2020년이였다. 학부생 3학년으로 전공 수업도 상당히 많고, 수강신청도 전공 위주로 신청하여 전공만 계속 공부한 한 해였다. 배운 것을 모두 기억에 남기고 사용할 수 있는 지식이 되었으면 좋겠다. 여름방학 이후에 공부량이 확 늘어서 2학기 수업에 해당하는 부분을 이미 공부하여 2학기에는 수업에 크게 집중을 하지 못했다. 대부분을 공부를 하고 다시 수업으로써 접하게 되어 PS와 Node, DB 공부를 주로 하게 된거 같다.

---

- 2 日

# Express Route Params

라우팅에 있어서 새롭게 알게 된 내용이 있어서 정리하려고 한다. 그 내용은 라우팅할 때 만약 ID와 같이 변동하는 숫자가 있다면 어떻게 할까라는 내용이다.

```js
const HOME = "/";
const JOIN = "/join";
const LOGIN = "/login";
const LOGOUT = "/logout";
```

보통 이런 식으로 라우팅하게 되는데 이 때 만약 유저의 ID를 구별해야 할 경우에는 막막하다. 보통 그 숫자는 가변형이고 어떤 형태로 들어올지 모른다. 숫자일수도 있고, 일련의 알파벳과 숫자의 조합일 수도 있다.

이런 부분을 해결하기 위해서 알아야하는 것은 바로 이것이다.

```js
const USERS = "/users";
const USER_DETAIL = "/:id";
```

user를 라우터에 연결하고 `user/id`와 같은 형태를 사용할 때 `/:id`와 같이 라우팅을 하면 된다. `/:`뒤에 들어오는 값은 req.params에 들어가는 값으로 http request를 받는 메소드에서 사용할 수 있다.

예를 들어서 `/users/:id`로 연결된 라우팅을 받는 메소드가 다음과 같이 있다

```js
userRouter.get("/:id", userController);
```

userRouter가 `/user`에 연결이 되어있다면 해당 get 요청은 `/user/:id`로 연결되게 된다. 이 때 id는 어떤 값이든 올 수 있고, express에서는 `콜론(:)`뒤에 들어오는 값을 신경쓰지 않는다. 그리고 id의 경우에는 `userController`라고 명시한 컨트롤러에 해당하는 함수에서 `req.params.id`와 같은 값으로 접근이 가능하다. 따라서 url에 들어간 id를 가지고 메소드에서 처리를 할 수 있다는 것을 알 수 있다.

---

- 3 日

# ESLint

ESLint란 ECMA에서 만든 Lint로, Lint란 소스 코드를 분석하여 프로그램, 문법 에러 혹은 코딩 스타일에 대해 에러를 표시해주는 가이드라인과 같다. ESLint는 자바스크립트 문법에 대해서 에러를 표시해준다.

즉, 협업시에 Lint를 통해서 코딩 컨벤션을 정한다면 마치 한 사람이 코딩한 것과 같이 일관적이게 코딩할 수 있다.

## Prettier

코드 정리 규칙을 세부적으로 설정해놓으면, 정해놓은 규칙에 맞게 자동으로 정렬해서 가독성을 높이고 코드 스타일을 통일할 수 있는 플러그인이다.

`ESLint`가 문법 오류를 체크해서 알려주는 역할이라면, `Prettier`은 문법과는 상관 없이 단순 코딩 스타일만을 체크해, 파일을 저장할 때마다 자동으로 정리해주는 역할이다.

## 적용하기

적용은 다음의 포스팅을 참고했다.

- [ESLint, Prettier 적용하기](https://velog.io/@recordboy/ESLint-Prettier-%EC%A0%81%EC%9A%A9%ED%95%98%EA%B8%B0)

```
$ npm init -y
$ npm i -D eslint
$ node_modules/.bin/eslint --init
```

eslint init 과정에서 나오는 질문은 프로젝트에서 사용할 lint를 설정하는 과정이므로 읽어보고 정하면 된다.

- `.eslintrc.js`

```js
module.exports = {
  env: {
    browser: true,
    es2020: true,
  },
  extends: "eslint:recommended",
  parserOptions: {
    ecmaVersion: 11,
    sourceType: "module",
  },
  rules: {},
};
```

각각의 설정 값을 알아보자.

- 환경(env): 프로젝트의 사용 환경을 설정한다.
- 확장(extends): 다른 ESLint 설정을 확장해서 사용할때 설정한다. 위 파일에서는 ESLint가 추천하는 규칙을 적용하라는 설정이며, 실제 프로젝트에서는 위에서 언급한 airbnb나 prettier 등을 확장해서 사용한다.
- 파서 옵션(parserOptions): ESLint 사용을 위해 지원하려는 Javascript 언어 옵션을 설정할 수 있다.
- 규칙(rules): 프로젝트에서 자체적으로 덮어쓰고 싶은 규칙을 정의할 때 사용한다. [규칙 문서](https://eslint.org/docs/rules/)

이후엔 prettier를 적용해보자.

```
$ npm i prettier eslint-plugin-prettier eslint-config-prettier -D
```

- eslint-config-prettier: ESLint의 formatting 관련 설정 중 Prettier와 충돌하는 부분을 비활성화 한다.
- eslint-plugin-prettier: Prettier를 ESLint 플러그인으로 추가한다. 즉, Prettier에서 인식하는 코드상의 포맷 오류를 ESLint 오류로 출력해준다.

- `.eslintrc.json`

```json
{
  "plugins": ["prettier"],
  "extends": ["eslint:recommended", "plugin:prettier/recommended"],
  "rules": {
    "prettier/prettier": "error"
  }
}
```

위의 파일을 생성하여 내용을 추가해주면 사용할 수 있다. 이 때 VSCode를 사용한다면 확장프로그램도 같이 설치해주자.

---

- 4 日

# Webpack

## Module

- 프로그램을 구성하는 구성 요소의 일부
- 관련된 데이터와 함수들이 묶여서 모듈을 형성하고 파일 단위로 나뉘는 것이 일반적이다.
- 모듈화 프로그래밍은 기능별로 파일을 나눠가며 프로그래밍을 하는 것으로 유지보수가 쉽다는 장점이 있다.

## Bundler

- 번들러는 지정한 단위로 파일들을 하나로 만들어서 요청에 대한 응답으로 전달할 수 있는 환경을 만들어주는 역할을 한다.
- 번들러를 사용하면 소스 코드를 모듈별로 작성할 수 있고 모듈간 또는 외부 라이브러리의 의존성도 쉽게 관리할 수 있다.

## Webpack

- 웹팩(Webpack)은 자바스크립트 정적 모듈 번들러(Static Module Bundler)이다
- 웹팩에서 모든 것은 모듈이다. 자바스크립트, 스타일시트, 이미지 등 모든 것을 자바스크립트 모듈로 로딩해서 사용한다.
- 웹팩의 주요 네 가지 개념으로 Entry, Output, Loader, Plugin이 있다.

1. Entry:

   - 의존성 그래프의 시작점을 웹팩에서는 엔트리(Entry)라고 한다.
   - 웹팩은 엔트리를 통해서 필요한 모듈을 로딩하고 하나의 파일로 묶는다.
   - 여러개의 엔트리가 존재할 수 있다.

2. Output:

   - 엔트리에 설정한 자바스크립트 파일을 시작으로 하나로 묶는다. 그후 번들된 결과물을 처리할 위치를 output에 기록한다.

3. Loader

   - 웹팩은 오직 JavaScript와 Json만 이해할 수 있다.
   - 로더는 다른 Type의 파일(img, font, stylesheet 등)을 웹팩이 이해하고 처리 가능한 모듈로 변환 시키는 작업을 한다.

4. Plugin

   - 로더가 파일단위로 처리하는 반면 플러그인은 번들된 결과물을 처리한다.
   - 로더가 변환하는 동안 플러그인은 bundle optimization, asset management and injection of environment과 같은 일을 진행할 수 있다.

## 레퍼런스

- [Webpack 기초](https://velog.io/@hih0327/Webpack-%EA%B8%B0%EC%B4%88)
- [Webpack이란?](https://nesoy.github.io/articles/2019-02/Webpack)

---

- 5 日

# Webpack

## SCSS 예제

```js
const path = require("path");

const MiniCssExtractPlugin = require("mini-css-extract-plugin");

const MODE = process.env.WEBPACK_ENV;
const ENTRY_FILE = path.resolve(__dirname, "assets", "js", "main.js");
const OUTPUT_DIR = path.join(__dirname, "static");

const config = {
  entry: ENTRY_FILE,
  mode: MODE,
  module: {
    rules: [
      {
        test: /\.(scss)$/,
        use: [
          {
            loader: MiniCssExtractPlugin.loader,
          },
          {
            loader: "css-loader",
          },
          {
            loader: "postcss-loader",
            options: {
              postcssOptions: {
                plugins: [
                  [
                    "autoprefixer",
                    {
                      browsers: "cover 99.5%",
                    },
                  ],
                ],
              },
            },
          },
          {
            loader: "sass-loader",
          },
        ],
      },
    ],
  },
  output: {
    path: OUTPUT_DIR,
    filename: "[name].js",
  },
  plugins: [
    new MiniCssExtractPlugin({
      // Options similar to the same options in webpackOptions.output
      // both options are optional
      filename: "[name].css",
    }),
  ],
};

module.exports = config;
```

`assets/js/main.js`를 Entry로 Static 폴더에 결과물을 작성한다. 이 때 main.js는 `import "../scss/style.scss";` 한 줄을 넣고 테스트를 해본다.

entry, mode, module, output, plugin을 설정하고 webpack을 실행하면 해당 부분이 static 폴더에 생성된다. 명령어는

```json
"dev:assets": "cross-env WEBPACK_ENV=development webpack",
"build:assets": "cross-env WEBPACK_ENV=production webpack"
```

이렇게 지정하였다. WEBPACK_ENV는 `webpack.config.js`의 MODE에 넣어준 문자열이고, cross-env는 문자열을 찾기 위해 도와주기 위해 설치한 패키지이다.

module에서 rule은 밑에서부터 위로 실행이 된다. 따라서 SCSS를 sass -> postcss -> css 순서로 해석하여 output PATH에 넣어준다.

---

# PS

- 머리 톡톡

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, size = 0;
	cin >> n;
	vector<int> v(n), num, ans(n);
	for (int i=0; i<n; i++) {
		cin >> v[i];
		size = max(size, v[i]);
	}
	num.resize(size+1);
	for (int i=0; i<n; i++)
		num[v[i]]++;

	for (int i=0; i<n; i++) {
		for (int j=1; j*j<=v[i]; j++) {
			if(v[i] % j == 0) {
				if(v[i] / j != j)
					ans[i] += num[v[i]/j];
				ans[i] += num[j];
			}
		}
	}
	for (int i=0; i<n; i++)
		cout << ans[i]-1 << '\n';
}
```

1번부터 N번 학생까지 한 명씩 차례대로 일어나 원을 돌면서 자신이 쓴 숫자가 다른 사람이 쓴 숫자의 배수이면 그 학생의 머리를 "톡톡" 친다. 자기가 총 몇 명의 학생의 머리를 치는지 구하는 문제이다.

배수를 구하기보다는 약수를 구해서 해결하는 방식을 택했다. 또한, 완전탐색의 경우 적어도 1,000,000 \* 500,000으로 제한시간인 2초를 넘을 것이므로, 약수를 구하는 알고리즘을 통해 약수 A, B의 곱은 v[i]를 만들 수 있으나 제곱수의 경우에는 그의 짝이 없으므로 해당 값만 더해준다. 따라서 다른 값들은 그의 짝도 더해준다.

이후 출력에는 자기 자신도 포함이 되므로 1을 제하여 출력해준다.

---

- 7 日

# Nodejs & MongoDB 로그인 구현

Nodejs로 구현된 애플리케이션에서 MongoDB를 사용한 유저 로그인 구현으로, Mongoose ODM과 Passport, connect-mongo, express-session과 같은 서드파티를 사용하여 구현하였다.

## 설정

### DB 설정 파일

```js
import mongoose from "mongoose";
import dotenv from "dotenv";

dotenv.config();

mongoose.connect(process.env.MONGO_URL, {
  useNewUrlParser: true,
  useFindAndModify: false,
});

const db = mongoose.connection;

const handleOpen = () => console.log("✅ Connected to DB");
const handleError = (error) =>
  console.log(`❌ Error on DB Connection: ${error}`);

db.once("open", handleOpen);
db.on("error", handleError);
```

### app 설정

```js
app.use(
  session({
    secret: process.env.COOKIE_SECRET,
    resave: true,
    saveUninitialized: false,
    store: new CookieStore({ mongooseConnection: mongoose.connection }),
  })
);
app.use(passport.initialize());
app.use(passport.session());
```

express-session을 이용하여 session을 정의하고 store 옵션의 경우에는 connect-mongo를 이용하여 서버가 재시작되더라도 쿠키 값을 저장할 수 있는 저장소로 마련했다. passport를 초기화하고 세션을 설정하여 로그인이 되면 쿠키 값을 브라우저에 저장할 수 있게 하였다.

### Model 구현

- User Model 구현

```js
import mongoose from "mongoose";
import passportLocalMongoose from "passport-local-mongoose";

const UserSchema = new mongoose.Schema({
  name: String,
  email: String,
  avatarUrl: String,
  facebookId: Number,
  githubId: Number,
});

UserSchema.plugin(passportLocalMongoose, { usernameField: "email" });

const model = mongoose.model("User", UserSchema);

export default model;
```

mongoose를 이용하여 MongoDB 유저 스키마를 정의한 후 사용하게 되는데 이 때 플러그인으로 passport-local-mongoose를 사용하여 passport 서드파티 중 local 전략을 mongoose와 함께 사용하기 용이하게 하고, 유저를 구분하는 필드를 email로 지정해준다.

### Passport 설정

```js
import passport from "passport";
import User from "./models/User";

passport.use(User.createStrategy());

passport.serializeUser(User.serializeUser());
passport.deserializeUser(User.deserializeUser());
```

passport를 간단하게 사용하기 위해서 스키마의 전략을 자동으로 생성하게 한 후 serializeUser와 deserializeUser는 이미 정의된 스키마의 함수를 이용하여 간단하게 정의했다. 정의는 간단하지만 해당 부분을 설정함으로써 매우 편하게 유저 인증 과정을 진행할 수 있다.

## 회원가입

- 회원가입: post로 회원가입 요청이 온 경우 처리 하는 컨트롤러

```js
export const join = async (req, res, next) => {
  const {
    body: { name, email, password, password2 },
  } = req;

  if (password !== password2) {
    res.status(400);
    res.render("join", { pageTitle: "Join" });
  } else {
    try {
      const user = await User({
        name,
        email,
      });
      await User.register(user, password);
      next();
    } catch (error) {
      console.log(error);
      res.redirect(routes.home);
    }
  }
};
```

user 객체를 만든 뒤 User 스키마에 `register()`를 이용하여 한번에 유저를 생성할 수 있다.

## 로그인

- 로그인: 회원가입 후 post로 로그인 요청시 처리하는 컨트롤러

```js
export const login = passport.authenticate("local", {
  failureRedirect: routes.login,
  successRedirect: routes.home,
});
```

passport 중 local 전략으로 인증을 하는 부분으로 성공시에는 홈, 실패시에는 로그인 화면으로 리다이렉트 하도록 컨트롤러를 짰다.

## 결과

서드파티들을 이용하여 이미 정의된 함수로 설정을 하게 되면, 훨씬 편하게 MongoDB를 이용하여 유저 로그인과 회원가입을 구현할 수 있다. 서드파티의 갯수가 많지만 여러 가지 기능을 기억하면 도움이 된다.

그 중 가장 도움이 된 것은 역시 passport와 express-session일 것 같다. session을 설정하려면 필요한 express-session과 인증 과정을 편하게 해주는 passport는 다른 DBMS를 사용하더라도 필요할 것 같다.

---

- 8 日

# PS

- `1038. 감소하는 수`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<long long> v;
	int n;
	cin >> n;

	for (int i=1; i<=1023; i++) {
		long long num = 0;
		int temp = i;
		for (int idx=9; idx>=0; idx--) {
			if(temp&1)
				num = 10*num + idx;
			temp /= 2;
		}
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	if(n > 1022)
		cout << "-1";
	else
		cout << v[n];
}
```

0부터 백만까지의 자연수 중 자릿수가 거듭될 수록 작아지는 수를 감소하는 수라고 칭하고 주어진 값만큼의 순서의 감소하는 수를 구하는 문제이다. 이 문제에서는 백만까지라 했으나, 정확히는 2^10-1개인 1023개의 감소하는 수가 존재한다. 9876543210이 최댓값이므로 그렇다고 볼 수 있다. 따라서 해당하는 값을 모두 벡터에 집어 넣고 정렬한 뒤 원하는 순서의 숫자를 꺼내면 된다.

- `1747. 소수&팰린드롬`

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6*2;

bool isPrime[MAX];

bool is_palindrome(string a, string b) {
	return a == b;
}

void primeInit() {
	for (int i=2; i*i<=MAX; i++) {
		if(!isPrime[i])
			for(int j=i*i; j<=MAX; j+=i)
				isPrime[j] = true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	isPrime[1] = true;
	primeInit();

	while(1) {
		string s, r;

		s = to_string(n);
		r = to_string(n);
		reverse(r.begin(), r.end());
		if(is_palindrome(s, r)) {
			if(!isPrime[n])
				break;
		}
		n++;
	}
	cout << n;
}
```

이 문제는 팰린드롬이면서 소수인 수를 찾는 문제로, 주어진 수보다 크거나 같은 소수이면서 팰린드롬인 숫자를 찾으면 된다. 따라서 주어진 숫자부터 팰린드롬을 체크한 뒤 소수를 체크해서 조건에 부합하는 숫자를 출력하면 된다. 이 때 팰린드롬은 reverse 함수를 이용해서 뒤집은 값이 같은 숫자를 찾았고, 소수는 에라토스테네스의 체를 이용해서 찾았다.

---

# passport-Github

흔히들 사용하는 서비스 중에서 Github 아이디를 통해서 가입하거나 로그인하여 해당 서비스를 진행하는 것을 보았을 것이다. 그 부분을 도와주는 서드파티로, Passport 전략 중 Gtihub을 선택해서 사용할 때 매우 편한 기능을 가진 서드파티이다.

- [가이드라인](http://www.passportjs.org/packages/passport-github/)

## 설치

```
$ npm install passport-github
```

## 사용

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

---

- 9 日

# passport-facebook

passport로 facebook 아이디를 이용해서 인증을 할 수 있게 해주는 서드파티이다. 다른 서비스에 비해서 페이스북은 상당히 깐깐하다. 따라서 진행하면서 생긴 시행착오에 대해서 메모하려한다.

- [가이드라인](http://www.passportjs.org/packages/passport-facebook/)

## 설치

```
$ npm install passport-facebook
```

## 사용

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

---

- 10 日

# Passport-local-mongoose를 이용한 ChangePassword

- [Passport-local-mongoose 레포지토리](https://github.com/saintedlama/passport-local-mongoose)

Passport-local-mongoose 서드파티를 이용하여 MongoDB에 등록된 사용자의 패스워드를 변경할 때 사용하는 함수에 대해 알아보자. 이미 서드파티에서 개발자가 편리하게 이용하게 함수로 구현되어 제공된다. 다음과 같은 설명을 통해 함수를 이해할 수 있다.

> changePassword(oldPassword, newPassword, [cb])
>
> > Changes a user's password hash and salt, resets the user's number of failed password attempts and saves the user object (everything only if oldPassword is correct). If no callback cb is provided a Promise is returned. If oldPassword does not match the user's old password, an IncorrectPasswordError is passed to cb or the Promise is rejected.

## 비밀번호 변경

사용자의 비밀번호를 변경하기 위해서는 먼저 현재 비밀번호와 새 비밀번호, 새 비밀번호 확인까지 3개의 필드에 값이 적힌다. 비밀번호는 저장될 때 Plain Text가 적히는게 아니라 Salt와 Hash에 의해 암호화된 텍스트로 변환된 값이 저장이 된다. 따라서 먼저, 현재 비밀번호를 받아 같은 Salt와 Hash에 의해서 암호화 시킨 뒤 비교를 하고 맞다면 변경을 하는 식으로 구현되어 있다. 만약 틀린다면 콜백함수에 의해서 처리되거나 콜백함수를 명시하지 않더라도 에러로 중단된다.

따라서 개발자가 해결해야 하는 부분은 3가지 필드에서 넘어온 값 중 새 비밀번호와 새 비밀번호 확인 필드의 값들을 먼저 같은지 체크하고 그 값을 `changePassword(oldPassword, newPassword, [cb])`에 넣어줘야 한다. 현재 비밀번호 필드의 값과 MongoDB의 저장된 값을 비교하는 것은 함수에서 구현되어 있으므로 훨씬 편하게 비밀번호 변경을 구현할 수 있다.

이 부분은 Passport 전략 중 local을 선택하여 MongoDB ODM 중 Mongoose를 사용할 때 편의를 주는 passport-local-mongoose 서드파티를 이용할 때로, passport의 다른 전략을 사용한다면 맞는 서드파티를 찾아서 API를 적용해야 한다.

---

- 11 日

# MongoDB ObjectId

NoSQL 데이터베이스인 MongoDB를 사용하다보면 관계형 데이터베이스의 Join 연산과 같이 다른 컬렉션의 특정 데이터를 참조할 필요가 생긴다. 이렇게 참조할 수 있는 자료형이 바로 ObjectId이며, Join과 같은 연산 기능을 가진 것이 populate라고 한다.

## ObjectId

ObjectId는 하나의 document 내에서 유일함이 보장되는 12 byte binary data로, MongoDB 자체에서 자동으로 기입되는 고유 값으로 다른 컬렉션에 있는 데이터를 참조할 수 있다.

MongoDB ODM인 Mongoose를 사용하여 스키마 중 ObjectId를 정의하는 코드를 예시로 보자

### 예시

비디오와 유저, 코멘트를 컬렉션을 가지고 스키마를 각각 정의할 때 유저는 비디오와 코멘트를 배열로 참조하여 가져야한다. 비디오는 코멘트를 배열로 갖고, 게시자로 유저 하나만 가질 수 있다. 코멘트는 게시자로 유저 하나만 가질 수 있다.

따라서 다음과 같이 스키마를 정의할 수 있다.

- Comment

```js
const CommentSchema = new mongoose.Schema({
  text: String,
  createdAt: {
    type: Date,
    default: Date.now,
  },
  creator: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User",
  },
});
```

- Video

```js
const VideoSchema = new mongoose.Schema({
  fileUrl: String,
  title: String,
  description: String,
  views: {
    type: Number,
    default: 0,
  },
  createdAt: {
    type: Date,
    default: Date.now,
  },
  comments: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Comment",
    },
  ],
  creator: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User",
  },
});
```

- User

```js
const UserSchema = new mongoose.Schema({
  name: String,
  email: String,
  comments: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Comment",
    },
  ],
  videos: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Video",
    },
  ],
});
```

## Populate

- [Mongoose Populate DOCS](https://mongoosejs.com/docs/populate.html)

위에서 MongoDB에서 ObejctId에 경우에는 고유의 값을 적는다고 하였다. 이 고유의 값을 통해서 참조를 하게 된다. 참조 값 또한 고유의 값 ID가 그대로 적혀있으며 구체적인 스키마를 알 수가 없다. 이 부분을 해결해주는 것이 populate이다.

특징이라고 하면 populate의 경우에는 스키마로 이루어진 모델의 메소드이므로 인스턴스를 가지고 사용할 수는 없다. 바로 예시를 봐보자.

### 예시

```js
const {
    user: { id },
  } = req;
  try {
    const userVideo = await User.findById(id).populate("videos");
  } catch(error)
  ...
```

위에서 본 컬렉션들의 스키마를 그대로 가져와서 보면 유저는 자신이 올린 일련의 비디오들을 가지고 있다. 하지만 이 비디오들은 Video 컬렉션에서 참조한 ID만 저장되어서 보여준다.

여기서 `populate("videos")`를 함으로써 User 모델 중 id에 맞는 데이터를 찾은 뒤 그 중 videos 속성의 내용을 실제 객체로 치환해준다. 이후에 userVideo를 호출하면 가지고 있는 videos 속성의 내용을 실제로 확인할 수 있다.

### 성능 문제

populate는 $oid로 모두 조회를 해서 자바스크립트 단에서 합쳐주는 것이지 Join처럼 데이터베이스 자체에서 합쳐주는 것이 아니다. 따라서 성능이 그렇게 좋지 않다. 특히 populate가 중첩되면 성능 문제가 생길 확률이 커지므로 적재적소에 쓰여야한다.

---

# Chrome CSP

자바스크립트를 사용하여 간단한 프로젝트를 진행하다가 웹팩을 사용하면서 자바스크립트를 script로 불러들일 때 생긴 에러를 해결하기 위해서 찾은 포스팅과 함께 정리하려고 한다.

- [크롬 익스텐션의 컨텐트 보안 정책 (CSP)](https://ohgyun.com/542)

크롬에서 XXS 공격을 막기 위해서 Content Security Policy라는 보안정책을 가지고 있다. 이러한 정책은 manifest.json 파일에 정의될 수 있는데, 정의가 안되어있다면 기본값으로 다음을 갖는다.

> script-src 'self'; object-src 'self'

인라인 스크립트는 절대 허용하지 않으며, 외부의 스크립트의 경우에는 화이트 리스트 방식으로 소스의 오리진을 추가하여 처리할 수 있다. 하지만 여기서도 SSL이 적용되지 않은 HTTP 리소스는 허용되지 않는다.

나는 프로젝트 진행 중에 이 부분에 막혀서 진행이 되지 않았다. 웹팩으로 다른 디렉토리에 정의한 js파일을 script로 불러옴으로써 `eval()` 함수가 실행이 되야하는데 크롬에서는 CSP 정책에 의해 막혔었다.

> `eval()`이나 `setTimeout(String)`, `new Function(String)`과 같은 자바스크립트를 실행하도록 한다면,
> `unsafe-eval`을 추가하는 방법으로 허용할 수 있다.

따라서 다음과 같은 정책을 적어 실행이 가능하도록 하였다.

`"content_security_policy": "script-src 'self’ ‘unsafe-eval'; object-src 'self'"`

하지만 이러한 방법은 XSS 공격에 취약하므로 설정 시에는 취약한 곳이 없는지 잘 찾아봐야한다. manifest.json 파일을 이용하지 않고 node.js 프로젝트로, express 프레임워크를 사용했기 때문에 다음과 같이 미들웨어로 헤더를 설정하여 개발을 계속 이어나갔다.

```js
export const SetCSP = (req, res, next) => {
  res.setHeader(
    "Content-Security-Policy",
    "script-src 'self' 'unsafe-eval'; object-src 'self'"
  );
  return next();
};
```

---

- 12 日

# PS

- `1477. 휴게소 세우기`

```cpp
#include <bits/stdc++.h>
using namespace std;

int getMinDistance(vector<int> &v, int dist) {
	int cnt = 0;
	for (int i=1; i<v.size(); i++) {
		cnt += (v[i] - v[i-1] - 1) / dist;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> v = {0, l};

	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int right = l;
	int left = 0;
	int mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if(getMinDistance(v, mid) > m)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left;
}
```

n개의 휴게소가 주어지고 m개의 휴게소가 더 건설되어야 할 때 휴게소 사이의 거리의 최댓값을 최소로 하는 거리를 구해야 한다. 그래서 거리를 이분탐색으로 구할 변수로 두고 적합한 값을 찾았다. 이 때 휴게소의 갯수가 m개와 같아야 하므로 만약 많으면 거리를 늘리고 적으면 거리를 줄이는 식으로 하였다. 한 휴게소와 한 휴게소의 거리에 예측하는 거리를 나누게 되면 휴게소들 사이의 휴게소의 갯수를 알 수 있다. 이 부분을 사용하여 휴게소 사이의 거리를 일정하게 하였을 때 얻을 수 있는 휴게소의 갯수를 가지고 이분탐색의 조건으로 사용했다.

- `3020. 개똥벌레`

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, h, ans = MAX, cnt;
	cin >> n >> h;
	vector<int> top(n/2), bot(n/2);
	for (int i=0; i<n/2; i++) {
		cin >> bot[i] >> top[i];
	}
	sort(top.begin(), top.end());
	sort(bot.begin(), bot.end());

	for (int i=1; i<=h; i++) {
		int obstacle = bot.size() - (lower_bound(bot.begin(), bot.end(), i) - bot.begin());
		obstacle += top.size() - (upper_bound(top.begin(), top.end(), h - i) - top.begin());
		if(ans > obstacle) {
			ans = obstacle;
			cnt = 1;
		}
		else if (ans == obstacle)
			cnt++;
	}

	cout << ans << ' ' << cnt;
}
```

개똥벌레가 석주와 석순을 피해서 최소의 갯수를 깨고 도착하는 장애물 갯수와 루트가 몇 가지가 있는 지 찾는 문제이다. 이 문제도 이분탐색으로 해결할 수 있다. 조금 더 빠른 풀이를 위해서 이분탐색으로 만들어진 함수인 lower_bound와 upper_bound를 이용하여 해결하였다.

lower_bound 함수는 범위와 정수를 기입해야한다. 범위는 함수가 적용되는 벡터 컨테이너의 인덱스 범위이고 정수는 해당 범위에서 정수에 해당하는 값을 찾는 것이다. 이 때 해당하는 값이 만약 없다면 정수보다 큰 수 중 가장 작은 값의 iterator를 리턴해준다. 따라서 begin()과 같은 iterator와 뺄셈 연산을 하여 해당 값보다 작은 장애물들을 모두 구한 뒤 전체 장애물 갯수에서 제하여 준다. 즉, 개똥벌레가 지나가면서 부딪히는 석주들을 구한 것이다.

종유석 또한 마찬가지로 진행되지만 종유석은 위에서 자라나기 때문에 높이에서 현재 높이를 빼서 upper_bound로 같은 연산을 적용해주었다.

---

- 13 日

# Ajax

최초 웹의 목적은 정적 문서를 띄우는 것이었다. 따라서 내용이 변경된다면 새로고침을 통해서 정보를 받아야지 화면에 표시할 수 있었다. 이러한 내용은 당연했지만 Ajax의 개념이 도입되고 나서 모든 것이 바뀌었다.

Ajax는 **Asynchronous JavaScript and XML**의 약자다. 한국어로는 비동기적 자바스크립트와 XML 정도로 직역할 수 있는데 자바스크립트를 이용해서 비동기적으로 서버와 브라우저가 데이터를 주고 받는 방식을 의미한다. 이 때 사용하는 API가 XMLHttpRequest이며, JSON과 XML을 사용하여 통신한다.

또한 비동기적으로 서버와 브라우저가 데이터를 주고 받은 뒤 변경된 결과를 웹페이지에 프로그래밍적으로 반영하게 되어 웹페이지의 로딩 없이 변경된 내용을 받을 수 있다.

예를 들어 포털 서비스에서 제공하는 이메일 시스템을 보면 이메일이 오게 되면 새로고침이 필요 없이 바로 받은 메일함에 **1** 표시가 뜨고, 만약 메일함을 켜놨다면 방금 온 메일이 리스트 중 맨 위에 뜨는 것을 볼 수 있다. 다른 예시로는 유튜브에서 동영상을 시청하던 와중 동영상에 코멘트를 달아도 동영상이 끊기지 않고 댓글이 달리는 모습을 볼 수 있다. 이러한 서비스들에서 사용하는 기술이라고 할 수 있다.

## 장단점

- 장점

  - 페이지 이동없이 고속으로 화면을 전환할 수 있다.
  - 서버 처리를 기다리지 않고, 비동기 요청이 가능하다.
  - 수신하는 데이터 양을 줄일 수 있고, 클라이언트에게 처리를 위임할 수도 있다.
  - 플러그인 없이도 인터렉티브한 웹페이지 구현할 수 있다.

- 단점

  - Ajax를 쓸 수 없는 브라우저에 대한 문제가 있다.
  - HTTP 클라이언트의 기능이 한정되어 있다.
  - 페이지 이동없는 통신으로 인한 보안상의 문제
  - 지원하는 Charset이 한정되어 있다.
  - 스크립트로 작성되므로 디버깅이 용이하지 않다.
  - 요청을 남발하면 역으로 서버 부하가 늘 수 있음.
  - 동일-출처 정책으로 인해 다른 도메인과는 통신이 불가능하다.

(출처: 위키백과)

## Node js 예시

- script js파일

```js
$(document).ready(function(){

  $('#getMethod').click(function() {

      var get = 'GET METHOD CALL';

      //Ajax GET Method TEST
      $.ajax({
            url: '/api/get',
            dataType: 'json',
            type: 'GET',
            data: {data:get},
            success: function(result) {
                if (result) {
                  $('#get_output').html(result.result);
                }
            }
        });
  })
};
```

- node js

```js
app.get("/api/get", (req, res) => {
  var data = req.query.data;
  console.log("GET Parameter = " + data);

  var result = data + " Succese";
  console.log(result);
  res.send({ result: result });
});
```

---

- 14 日

# Javascript Iterator

ES6이 도입되면서 많은 개념들이 추가가 되었다. 그 중 다른 언어에서도 많이 사용되는 Iterator(반복자)에 대해 알아보자.

- 레퍼런스
  - [Javascript Iterator](https://medium.com/@la.place/javascript-iterator-b16ca3c51af2)
  - [Javascript와 Iterator](https://pks2974.medium.com/javascript%EC%99%80-iterator-cdee90b11c0f)

## for-of

자바스크립트는 원래 for-in을 통해 object를 순회하였다. 하지만 배열을 순회할 때는 불편한 점이 있고 forEach의 경우에도 프로그래머가 의도한 바로 사용하기 어렵다. 이러한 문제를 보완하기 위해서 ES6에서는 for-of를 도입했다.

for-of의 장점은 밑에서 이야기할 Iterable한 객체. 즉, 열거가능한 객체라면 모두 사용할 수 있다.

## Iterable

Iterable은 객체의 멤버를 반복할 수 있는 객체로, 반복할 object에 [@@iterator] 메소드가 있다면 사용할 수 있다.

다음과 같은 프로퍼티를 사용하면 된다.

`object[Symbol.iterator]`

위에서 이야기한 for-of가 바로 이 프로퍼티를 이용하여 순회하는 것이다.

### Iterable 가진 객체

- Array
- TypedArray
- String
- Map
- Set

### Spread 문법

Spread를 이용하면 iterable 객체를 쉽게 해체할 수 있다.

```js
let txt = "wow";
console.log([...txt]); // ['w', 'o', 'w']
```

## Iterator

Iterator는 객체를 `next()` 메소드로 순환 할 수 있다. 이 메소드의 반환자는 **{done: boolean, value: any}**를 포함해야 한다. 마지막 순서에서는 done을 true로 반환하게 된다.

### 응용

크기가 100이고 값이 모두 0인 초기화된 배열이 필요하다고 할 때, Iterator와 Spread를 이용해보자.

```js
const arr = [];
for (let i = 0; i < 100; i++) {
  arr.push(0);
}
console.log(arr);
```

```js
const arr = [...Array(100).keys()].map((i) => 0);
console.log(arr);
```

---

- 15 日

## JavaScript Generator

제너레이터는 코루틴(Co-Routine)과 유사하다. 코루틴은 다른 언어에서 접할 수 있는데, A와 B의 코루틴이 존재한다면 서로는 서로의 서브루틴이며, 발동될 때마다 이전에 자신의 마지막 실행지점에서 이어서 실행할 수 있다.

제너레이터도 마찬가지로, 함수 실행 중 멈췄다가 멈춘 위치에서 다시 시작할 수 있다. 또한 위에서 이야기한 Iterator를 가장 쉽게 구현할 수 있는 방법이 바로 제너레이터 객체를 이용하는 것이다.

### 사용

제너레이터는 `function*()` 키워드를 가지고 생성할 수 있으며, 호출시에는 함수가 실행된 뒤 반환값이 반환되는 것이 아니라, Iterator 객체가 반환이 된다. 따라서 `next()`메소드를 가지고 호출하게 되면 제너레이터가 실행이 되고, `yield`를 만나게 되면 해당 값을 `{value, done}` 중 value 프로퍼티에 저장을 하게 된다. 이후엔 제너레이터가 멈추고 현재까지의 컨텍스트는 저장되게 된다.

```js
function* increseNumber() {
  let number = 1;
  while (number <= 100) {
    yield number++;
  }
}

const generator = increseNumber();

console.log(generator.next().value); // 1
console.log(generator.next().value); // 2
console.log(generator.next().value); // 3
console.log(generator.next().value); // 4
console.log(generator.next().value); // 5
// ...
console.log(generator.next().value); // 99
console.log(generator.next().value); // 100
console.log(generator.next().value); // undefined
```

조금 더 응용하자면 컨텍스트를 저장하는 것을 이용하여 다이나믹 프로그래밍을 쉽게 할 수 있다. 다음은 피보나치 수열을 제너레이터를 가지고 만든 예제이다.

```js
function* fibonacci() {
  let [prev, curr] = [1, 1];
  while (true) {
    [prev, curr] = [curr, prev + curr];
    yield curr;
  }
}

for (let n of fibonacci()) {
  console.log(n);

  if (n >= 1000) {
    break;
  }
}
```

다들 제너레이터를 사용하는 진면목은 비동기에서의 사용이라고 한다. 자바스크립트를 이용하여 코딩을 진행하다가 겪을 수 있는 콜백지옥을 프로미스와 제너레이터를 이용하면 수월하게 해결할 수 있다고 한다. 그러한 개념을 접목시킨 것이 바로 `async-await`이다. 자주 사용하게 되는 `async-await`은 별 다른 내용없이 명시만 한다면 비동기 프로그래밍을 매우 쉽게 만들어준다. 하지만 개념을 알 필요가 있다고 생각되기 때문에 밑의 링크를 참고하여 숙지하는 것이 좋아보인다.

- [ES6의 제너레이터를 사용한 비동기 프로그래밍](https://meetup.toast.com/posts/73)

---

- 16 日

# 2019 카카오 블라인드 공채 2차 오프라인 코딩 테스트

- [문제 및 서버 레포지토리](https://github.com/kakao-recruit/2019-blind-2nd-elevator)

엘리베이터 문제로, 빌딩마다 다른 승객 트래픽 모델링을 짠 뒤 승객을 전부 원하는 곳으로 보낼 때까지의 Timestamp를 측정하는 문제이다.

REST API로 엘리베이터의 정보와 승객의 정보를 받고 마지막으로 엘리베이터 객체에 정보를 넣어서 작동하게 하여 웹으로 결과를 볼 수 있는 문제이다.

Nodejs로 받아서 해볼 생각인데, 현재로썬 C++이 아닌 다른 언어를 가지고 문제를 해결해본 적이 없어 꽤 긴 시간이 걸릴거라고 예상된다.

이번 기회에 다른 언어로 풀이를 할 수 있을만큼 공부를 해봐도 좋을 것 같다.
