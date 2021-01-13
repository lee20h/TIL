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
