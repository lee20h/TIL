# Express Middleware

Middleware에 대해서 알아보았다. Middleware는 함수라 생각하면 좋은데, Express에서 route와 일련의 함수를 등록하게 된다. 해당 함수가 실행되기 전에 Middleware들이 중간에서 먼저 실행 된 뒤 다음 마지막으로 지정한 함수를 실행한다.

Middleware는 많은 양의 함수로 등록할 수도 있고 안할 수도 있다. 여러 함수를 등록할 때 다음 함수로 넘어가기 위해선 파라미터로 `next`를 가져야하며, `next()`를 명시함으로써 다음 함수로 넘어갈 수 있다. 따라서 마지막 함수에서만 반환이 이뤄진다.

```js
app.get("/", handleMiddleware, handlehome);
```
이렇게 한 route에 대해서만 사용할 수도 있다.

```js
app.use(handleMiddleware);
app.get("/", handlehome);
app.get("/profile", handleProfile);
```

위의 예시와 같이 `use()`를 사용하여 등록하게 된다면 그 밑으로는 전부 일괄적으로 middleware를 등록하게 된다. 따라서 다른 함수들을 실행하기 전 middleware들이 먼저 실행된 뒤 마지막에 함수를 실행하게 된다.

여기서도 하나 알아둬야하는 것이 있다. 만약 middleware에서 `res.send()`와 같이 응답을 보내게 되면 middleware에서도 응답을 보내고 연결이 중단될 수 있다. 즉, route에 등록된 함수를 실행하지 않고 중단될 수 있다.

## 예시

middleware는 매우 많지만 그 중에서 4가지를 뽑아서 설명하고자 한다.

- morgan
- helmet
- body-parser
- cookie-parser

morgan은 log를 해주는 middleware로 여러 옵션을 가지고 있다. GET 요청 등이 이뤄졌을 때 그러한 내용을 터미널에 띄워서 보여준다. 옵션마다 다르게 보여주므로 옵션들 중 자기가 원하는 것을 등록하면 된다.

helmet은 node.js의 보안 middleware로 해당 내용은 github 레포지토리를 참고하면 좋다. 기본적으로 제공되는 여러 보안 기능이 있으므로 어플리케이션을 더 단단하게 만들어준다.

body-parser는 클라이언트로부터 넘어오는 요청과 함께 여러 정보를 받을텐데 이 정보를 body로 추출해내는 역할을 한다. 옵션을 json이나 urlencoded와 같이 html 폼으로 넘어오는 것을 받게할 수 있다. 서버를 구축하다보면 크게 도움을 주는 middleware이다.

cookie-parser는 클라이언트측 브라우저에 저장하는 cookie를 조금 더 사용하기 편하게 도와주는 middleware이다.