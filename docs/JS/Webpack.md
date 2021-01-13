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
