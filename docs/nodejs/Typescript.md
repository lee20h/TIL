# typeScript

## 설치

```
$ npm i -g typescript
```
app.ts
```ts
const name:string = "younghun";
const age:number = 24;
```

## 컴파일

```
$ tsc app.ts
```

컴파일이 완료되면 ts파일이 js파일로 변환  

## express 환경 구축

```
$ tsc --init
```

tsconfig.json 파일이 생성된다. 해당 파일에서 
```json
{
 "compilerOptions": {
   "target":"es6",
   "module":"commonjs",
   "outDir":"./dist",
   "rootDir":"./src",
   "strict": true,
   "moduleResolution":"node",
   "esModuleInterop":true
  }
}
```

주석을 지워주고 이러한 부분만 유지한다.

- target : 컴파일 ECMAscript 대상
- module : 모듈 코드 생성
- outDir : 컴파일 경로
- rootDir : 컴파일 대상의 root 디렉토리
- strict : typescript 엄격한 유형 검사 활성화
- moduleResolution : node 또는 classic 모듈 분석

등으로, [docs](https://www.typescriptlang.org/docs/handbook/tsconfig-json.html)을 참고하는게 제일 빠르다.  



```
$ npm init -y
$ npm i -D express typescript ts-node nodemon @types/node @types/express
```

express 환경을 구성 한 뒤 package.json을 고쳐준다.

```json
"script": {
  "start": "node dist/app.js",
  "dev": "nodemon src/app.ts",
  "build": "tsc -p ."
}
```

- start : 컴파일 한 app.js를 node 명령어로 실행
- dev : nodemon으로 typescript 파일 개발환경으로 실행
- build : 실제로 컴파일 후 javascript 파일 생성

## ts 파일 작성

여타 js로 작성하는 express와 달리 소스 맨 위에 이 부분을 적어줘야한다.

```ts
import express, {Request, Response, NextFunction} from 'express';
```

콜백 함수 작성시에 이렇게 사용할 수 있다.  

```ts
app.get('/', (req:Request, res:Response, next:NextFunction) => {
    // content
})
```

자바스크립트를 사용한 express와의 차이는 타입스크립트로 자료형 명시와 콜백에서의 명시 이외에는 없는거 같다.