---
sidabar: auto
---
# body-parser

post로 요청된 body를 쉽게 추출할 수 있는 모듈이다. 추출된 결과는 request객체(IncomingMessage 타입)에 body 속성으로 저장된다. Magicsora에서는 URL-encoded form body parser만 사용한다.

## 내장모듈와 다른점

http모듈로만 post body를 파싱하려면,

```jsx
req.on('data', function(chunk) { body += chunk; }); 
```

와 같이 이벤트를 등록해야한다. 그다음에 인코딩처리를 해줘야한다.

body-parser를 쓰면 좀 더 수월하다는 것을 볼 수 있다.

```jsx
bodyParser.urlencoded()
```

자동으로 req에 body속성이 추가되고 저장된다. 만약 urls에 접근하고싶다면, req.body.urls이다. 인코딩도 default로 UTF-8로 해준다.

## urlencoded()의 옵션

만약 아무 옵션을 주지 않는다면, body-parser deprecated undefined extended: provide extended option 같은 문구가 뜬다.

```jsx
.use(bodyParser.urlencoded({ extended: true or false })); 
```

extended 는 중첩된 객체표현을 허용할지 말지를 정하는 것이다. 객체 안에 객체를 파싱할 수 있게하려면 true.

### extended 옵션에 대해

- 참조문서 : [https://stackoverflow.com/questions/29960764/what-does-extended-mean-in-express-4-0/45690436#45690436](https://stackoverflow.com/questions/29960764/what-does-extended-mean-in-express-4-0/45690436#45690436)

내부적으로 true 를 하면 qs 모듈을 사용하고, false 면 query-string 모듈을 사용한다. 이 두 모듈간의 차이에서 중첩객체 파싱여부가 갈린다. 예제는 참조문서의 stackoverflow 에 잘 나와있다.

### req.body.hasOwnProperty is not a function 이슈

- 참조문서 : [https://github.com/expressjs/express/issues/3264](https://github.com/expressjs/express/issues/3264)

express generator 등오로 express 프로젝트를 세팅하면, app.js 에서 `app.use(express.urlencoded({extended: false}));` 가 보인다.

위에서 언급했듯이, false면 querystring모듈을 사용하는데, querystring.parse는 object를 상속받지 않는다. 따라서 아래와 같은 이슈가 있을 수 있다.

### 실제 예시 코드

최근 프로젝트에서 사용한 body-parser 모듈은 `db.js` 에서 ajax 통신 post 방식으로 FE에서 책을 등록할 때 해당 책의 정보를 넘겨줄 때 사용한다. BE에서 ajax 통신을 받을 때 이러한 방식으로 사용했다. JSON형식으로 넘겨온 데이터를 조금 더 파싱하기 편한 형태로 만들기 위해서 body-parser 모듈을 사용했다. 요청 파라미터인 `req`에 `body` 로 쉽게 접근한다.

```jsx
router.post("/upload", upload.single('file'), (req, res) => {
    //res.json({ file: req.file });
    const name = req.body.name;
    const auth = req.body.auth;
    const pub = req.body.pub;
    const price = req.body.price;
    const image = req.file.filename;
    book.create({
        name: name,
        auth: auth,
        pub: pub,
        price: price,
        image: image
    }).then(book => {
        console.log("generated BOOK", book.name);
    });
    res.header("Access-Control-Allow-Origin", "*");
});
```