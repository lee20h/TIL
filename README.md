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
