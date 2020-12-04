  
 
  
# Template Engine
HTML code를 최소화시키도록 도와주는 도구로, 정적인 파일과 동적인 파일의 장단점을 결합시켰다. 따라서 정적인 파일만을 서비스한다면 사용할 필요가 없다. 동적인 결과를 정적인 파일에 담기 위해 사용한다. 즉, 자바스크립트 코드로 연산된 결과를 변수에 넣은 뒤 뷰 파일에서 사용하도록 한다.  

클라이언트 요청에 따라 웹 문서에 들어가는 내용이 달라질 수 있으므로 정적인 부분과 동적인 부분을 나누기 위해서 사용한다. 이 때 `app.js` 내 HTML 코드를 쓰지 않아도 되며 뷰 파일과 자바스크립트 코드를 따로 사용할 수 있다.

클라이언트 측 브라우저는 HTML 템플릿, JSON / XML 데이터 및 템플릿 엔진 라이브러리를 서버에서 로드합니다.   

템플릿 엔진은 클라이언트의 브라우저에서 템플릿과 데이터를 사용하여 최종 HTML을 생성합니다. 그러나 일부 HTML 템플릿은 데이터를 처리하고 서버 측에서 최종 HTML 페이지를 생성합니다.  

## 종류
크게 두 가지로 나눈다.  
1. pug(jade)
2. ejs

차이점을 보면 ejs는 기본 html 문법을 그대로 사용하며, 협업할 때 ejs, 개인이 개발을 할 때는 pug을 추천한다. 두 템플릿엔진 둘 다 엔진을 통해서 html 문법으로 변환 시켜준다.  

여기서는 pug을 주로 볼려고 한다.

## pug의 장점

- HTML을 간단히 표현. 가독성이 좋다
- 마크업 문법보다 코드량이 적어 생산량이 좋다
- JS 연산 결과를 쉽게 보여줌
- 정적인 부분과 동적인 부분 나눌 수 있다

## pug의 특징

- 마크업과 달리 닫는 태그가 없다
- 들여쓰기로 종속성 구별
- 태그 선언시 태그 이름만 쓴다
- ID와 CLASS 선언시 CSS 선택자 사용
- 태그 없이 ID나 CLASS 선언시 자동으로 div 태그 사용
- 태그에 속성 줄 땐 괄호 사용
- 여러줄 사용시에 `|` 사용
- script나 CSS로 태그 사용시 끝에 `.` 입력
- 템플릿 속에서 Javascript 사용시 앞에 `-` 입력

## 설치

`npm install pug --save`  

터미널에서 해당 명령어 입력 시 `package.json`에 dependencies에 추가된다.  

## 예시

```
var express = require('express');
var app = express();

app.set('view engine', 'pug'); // 사용할 템플릿 엔진 설정
app.set('views', './views'); // 템플릿이 있는 폴더 지정 (지정 안한 경우 default로 views가 설정된다)
app.use(express.static('public')) //정적 경로 지정
app.get('/주소' function(req, res) => {
	res.render('pug파일 이름');
})
```

## 문법
### **기본 문법**

```
html
	head
	body
		h1 Hello Pug
```

```
idx.pug:
html
	head
		title= title
	body
		h1= message

app.js:
app.get('/', function (req,res) => {
	res.render('idx', { title: 'Hey', message: 'Hello there!'});
});
```
들여쓰기로 상위태그 안에 종속하게 할 수 있다.
```
<html>
	<head></head>
	<body>
		<h1>Hello Pug</h1>
	</body>
</html>
```

조금 더 심화해서 변수를 이용해보자
```
idx.pug:
html
	head
		title #{_title}
	body
		h1 Hello Pug
		ul
			-for(let i=0; i<5; i++)
				li Hello
		div #{time}

app.js:
app.get('/', (req,res) => {
	res.render('idx', {time:Date(), _title:'Pug'});
})
```

### 문법 요약
HTML5
```
doctype html   		→   <!DOCTYPE html>
```
**Block 생성**
```
p foo 		  		 →   <p>foo</p>
```
**속성**
- 단일 속성
```
a (href='	') Google  →  <a href="	">Google</a>
```
- 다중 속성
```
input(
	type='checkbox'
	name='agreement'
	checked
)
```
```
<input type="checkbox" name="agreement" checked="checked">
```

조건문
- **if문**
```
- var user = { description: 'foo bar baz' }
- var authorised = false
#user
	if user.description
		h2.green Description
		p.description= user.description
	else if authrised
		h2.blue Description
		p.description.
			User has no description,
			why not add one...
	else
		h2.red Description
		p.description
```
```
<div id="user">
	<h2 class="green">Description</h2>
	<p class="description>foo bar baz</p>
</div>
```
- **unless문**
if와 반대로 실행
```
unless user.isAnonymous
	p You're logged in as #{user.name}
```
```
if !user.isAnonymous
	p You're logged in as #{user.name}
```
둘 다 같은 html로 변환되게 된다.  

**Case 조건문**  
```
- var friends = 10   // JS코드는 - 입력
case friends
	when 0
		p you have no friends
	when 1
		p you have a friend
	default
		p you have #{friends} friends
```
```
<p>you have 10 friends</p>
```

**OR문과 Break**  
- OR문은 `when` 밑줄에 다시 `when` 조건
- Break는 `- Break` 입력

```
- var friends = 0
case friends
	when 0
	when 1
		p you have very few friends
		- break
	default
		p you have #{friends} friends
```
```
<p>you have very few friends</p>
```

**Element 조건문**
```
- var friends = 1
case friends
	when 0: p you have no friends
	when 1: p you have a friend
	deafult: p you have #{friends} friends
```
```
<p>you have a friends</p>
```

**반복문**
- for문
```
- for (let x=0; x<3; x++)
	li item
```
```
<li>item</li>
<li>item</li>
<li>item</li>
```
- each문
```
-
	var list = ["one", "two", "three", "four"]
each item in list
	li= item
```
```
<li>one</li>
<li>two</li>
<li>three</li>
<li>four</li>
```

*마크업 코드를 내용물 그대로 표시*  
예시
```
p
	= 'This code is <escaped>!'
```
```
<p>This code is &lit;escaped&gt;!</p>
```
이 때는 `=` -> `!=`으로 고치면 마크업 코드 그대로 사용가능하다.  

```
p
	!= 'This code is <strong>not</strong> escaped!'
```
```
<p>This code is <strong>not</strong> escaped!</p>
```

**Mixin 변수**  
템플릿 단위로 재사용 가능한 변수로, 규칙은 `+{변수 이름}`
```
// 선언
mixin list
	ul
		li foo
		li bar
		li baz

// 사용
+list
+list
```
```
<ul>
	<li>foo</li>
	<li>bar</li>
	<li>baz</li>
</ul>
<ul>
	<li>foo</li>
	<li>bar</li>
	<li>baz</li>
</ul>
```

**includes(템플릿 파일 포함)**  
규칙 : include{파일 경로}
```
html
	include includes/head.pug
	body
		h1 My Site
```

예시
```
doctype html
html
	title My Blog
	body
		include includes/header.pug // 헤더
		p#main Welcome to my blog. // 헤더와 푸터 사이 내용
		include includes/footer.pug // 푸터
```

[예시 참고](https://iseongho.github.io/posts/node-template-engine-pug/)  