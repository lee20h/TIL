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
