# Chrome CSP 정책

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
