# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록
* 쓸데없는 Commit 지양
* markdown으로 작성
* 1일 1문제(PS, SQL) 해결

---  

| [5월](./month/5월) | [6월](./month/6월) | [7월](./month/7월) |
|----|-----|-----|

---  

- 1日  

### Ajax HTTP 요청 헤더

**HTTP 헤더**  
클라이언트와 서버 사이에 이루어지는 HTTP 요청과 응답은 HTTP 헤더를 사용하여 수행됩니다. HTTP 헤더는 클라이언트와 서버와 서로에게 전달해야 할 다양한 종류의 데이터 포함한다.  

```
Accept: */*
Referer: http://codingsam.com/examples/tryit/tryhtml.php?filename=ajax_header_request_01
Accept-Language: ko-KR
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko
Host: codingsam.com
DNT: 1
Connection: Keep-Alive
```

- 헤더 이름, 콜론, 공백, 헤더 값의 순서로 구성
- 일부 헤더는 요청 헤더와 응답 헤더에 모두 사용되나, 일부 헤더는 둘 중 하나에서만 사용
- 요청 헤더는 원래 웹 브라우저가 자동으로 설정해서 보내므로, 사용자가 직접 설정 불가하나, Ajax를 이용하여 직접 설정하거나 확인 가능

HTTP 요청 헤더  
Ajax에서는 요청을 보내기 전에 setRequestHeader() 메소드를 사용하여 HTTP 요청 헤더를 작성 가능하다. 해당 메소드는 아래와 같다.
```
XMLHttpRequest인스턴스.setRequestHeader(헤더이름, 헤더값);
```
예제로는,
```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        document.getElementById("text").innerHTML = httpRequest.responseText;
    }
};
httpRequest.open("GET", "/examples/media/ajax_request_header.php", true);
httpRequest.setRequestHeader("testheader", "123");
httpRequest.send();
```

HTTP 응답 헤더  
- getAllResponseHeaders() 메소드 :  HTTP 응답 헤더의 모든 헤더를 문자열로 반환
- getResponseHeader() 메소드 :  HTTP 응답 헤더 중 인수로 전달받은 이름과 일치하는 헤더의 값을 문자열로 반환

```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        document.getElementById("text").innerHTML = httpRequest.responseText;
        document.getElementById("header").innerHTML = httpRequest.getAllResponseHeaders();
        document.getElementById("user").innerHTML =
            "testheader: " + httpRequest.getResponseHeader("testheader");
    }
};
httpRequest.open("GET", "/examples/media/ajax_response_header.php", true);
httpRequest.send();
```

Content-Type 헤더  
Content-Type 헤더의 값을 직접 설정하지 않으면, HTML 문서의 MIME 타입인 "text/html"로 자동 설정되며 Ajax 응용 프로그램에서 다루게 되는 XML은 일반적인 파일 형태의 XML 문서가 아니다. Ajax 요청을 받은 후 서버에서 실행되어 동적으로 생성되는 XML 형태의 데이터이므로 확장자가 `.xml`이 아니다. 따라서 header() 함수를 사용하여 응답 데이터의 MIME 타입이 `text/xml`이라고 명시해야한다.

```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        document.getElementById("text").value = httpRequest.responseText;
        document.getElementById("header").innerHTML = httpRequest.getAllResponseHeaders();
        document.getElementById("user").innerHTML =
            "testheader: " + httpRequest.getResponseHeader("tes
    }
};
httpRequest.open("GET", "/examples/media/ajax_response_header_xml.php", true);
httpRequest.send();
```

### Ajax 고급
다양한 Ajax 요청  

주기적으로 Ajax 요청하기  
Ajax는 클라이언트가 서버에 데이터를 요청하는 클라이언트 풀링 방식을 사용하므로, 서버 푸시 방식의 실시간 서비스를 만들 수 없다. 이 땐 주기적으로 Ajax 요청을 보내도록 설정하여, 실시간 서비스와 비슷한 동작을 하도록 만든다.  

0.5초마다 주기적으로 Ajax 요청을 보내 현재 서버 시간 출력하는 예제
```
function sendRequest() {
    var httpRequest = new XMLHttpRequest();
    httpRequest.onreadystatechange = function() {
        if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
            document.getElementById("text").innerHTML = httpRequest.responseText;
        }
    };
    httpRequest.open("GET", "/examples/media/ajax_periodic_request.php");
    httpRequest.send();
}
sendRequest();
window.setInterval("sendRequest()", 500); // 매 0.5초마다 Ajax 요청을 보냄.
```
0.5초마다 XMLHttpRequest 객체를 계속 초기화한다. 이때 서버에서의 응답이 0.5초 이상 걸리게 되면 화면에는 아무것도 표시되지 않을 수도 있다.

```
function sendRequest() {
    var httpRequest = new XMLHttpRequest();
    httpRequest.onreadystatechange = function() {
        if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
            document.getElementById("text").innerHTML = httpRequest.responseText;
            self.setTimeout("sendRequest()", 500); // 응답을 받은 후 0.5초 뒤에 다시 Ajax 요청을 보냄.
        }
    };
    httpRequest.open("GET", "/examples/media/ajax_periodic_request.php");
    httpRequest.send();
}
sendRequest();
```
해당 예제는 응답을 받고 나서 0.5초가 지난 후에 sendRequest() 함수를 다시 호출하는 예제다.  

데이터가 변경된 경우에만 Ajax 응답하기  
매번 요청하게 되면 네트워크와 서버의 자원을 많이 소모하게 된다. 따라서 웹 페이지의 내용이 변경된 경우 서버가 응답을 보내도록 설정하는 것이 자원을 절약할 수 있다. 이 방법은 Ajax 요청 헤더에 이전 요청 시간을 헤더로 포함해서 보내는 것으로 설정할 수 있다.  

Ajax 요청 취소
```
function abortRequest() {
    httpRequest.abort();
    document.getElementById("text").innerHTML = "Ajax 요청을 취소했습니다.";
}
```
`abort()`메소드를 사용하면 된다.  

### 문서 타입별 응답 처리
서버로부터의 응답 데이터 확인
- responseText 프로퍼티

서버에 요청하여 응답으로 받은 데이터를 문자열로 반환한다.
```
document.getElementById("text").innerHTML = xmlHttp.responseText;
```
텍스트 파일의 응답 처리
```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        // 텍스트 파일의 응답 처리는 responseText 프로퍼티를 사용해야 함.
        document.getElementById("text").innerHTML = httpRequest.responseText;
        // 텍스트 파일의 응답 처리에 responseXML 프로퍼티를 사용하면 null을 반환함.
        document.getElementById("xml").innerHTML = httpRequest.responseXML;
    }
};
httpRequest.open("GET", "/examples/media/ajax_doctype_text.php");
httpRequest.send();
```

- responseXML 프로퍼티

서버에 요청하여 응답으로 받은 데이터를 XML DOM 객체로 반환한다.
```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        // XML 문서의 응답 처리에 responseText 프로퍼티를 사용하면 XML 코드를 문자열로 반환함.
        document.getElementById("text").innerHTML = httpRequest.responseText;
        // XML 문서의 응답 처리는 responseXML 프로퍼티를 사용해야 함.
        document.getElementById("xml").innerHTML = httpRequest.responseXML;
    }
};
httpRequest.open("GET", "/examples/media/ajax_doctype_xml.php");
httpRequest.send();
```

XML 데이터의 응답 처리
서버로부터 XML 데이터를 응답으로 받은 경우에는 responseXML 프로퍼티를 사용하여 받은 데이터를 처리할 수 있다.
먼저 responseXML 프로퍼티를 사용하여 XML DOM 객체를 반환한 후에 해당 객체를 가지고 작업하면 된다.
```
var httpRequest, xmlData, result, i;
httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        xmlData = httpRequest.responseXML;
        document.getElementById("text").innerHTML =
            xmlData.getElementsByTagName("b")[0].firstChild.nodeValue;
            // XML 데이터의 첫 번째 <b>태그의 텍스트 노드의 값을 반환함.
    }
};
httpRequest.open("GET", "/examples/media/ajax_doctype_xml.php");
httpRequest.send();
```

---