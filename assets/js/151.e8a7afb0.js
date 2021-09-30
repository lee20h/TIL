(window.webpackJsonp=window.webpackJsonp||[]).push([[151],{482:function(t,e,a){"use strict";a.r(e);var s=a(25),n=Object(s.a)({},(function(){var t=this,e=t.$createElement,a=t._self._c||e;return a("ContentSlotsDistributor",{attrs:{"slot-key":t.$parent.slotKey}},[a("h1",{attrs:{id:"template-engine"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#template-engine"}},[t._v("#")]),t._v(" Template Engine")]),t._v(" "),a("p",[t._v("HTML code를 최소화시키도록 도와주는 도구로, 정적인 파일과 동적인 파일의 장단점을 결합시켰다. 따라서 정적인 파일만을 서비스한다면 사용할 필요가 없다. 동적인 결과를 정적인 파일에 담기 위해 사용한다. 즉, 자바스크립트 코드로 연산된 결과를 변수에 넣은 뒤 뷰 파일에서 사용하도록 한다.")]),t._v(" "),a("p",[t._v("클라이언트 요청에 따라 웹 문서에 들어가는 내용이 달라질 수 있으므로 정적인 부분과 동적인 부분을 나누기 위해서 사용한다. 이 때 "),a("code",[t._v("app.js")]),t._v(" 내 HTML 코드를 쓰지 않아도 되며 뷰 파일과 자바스크립트 코드를 따로 사용할 수 있다.")]),t._v(" "),a("p",[t._v("클라이언트 측 브라우저는 HTML 템플릿, JSON / XML 데이터 및 템플릿 엔진 라이브러리를 서버에서 로드합니다.")]),t._v(" "),a("p",[t._v("템플릿 엔진은 클라이언트의 브라우저에서 템플릿과 데이터를 사용하여 최종 HTML을 생성합니다. 그러나 일부 HTML 템플릿은 데이터를 처리하고 서버 측에서 최종 HTML 페이지를 생성합니다.")]),t._v(" "),a("h2",{attrs:{id:"종류"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#종류"}},[t._v("#")]),t._v(" 종류")]),t._v(" "),a("p",[t._v("크게 두 가지로 나눈다.")]),t._v(" "),a("ol",[a("li",[t._v("pug(jade)")]),t._v(" "),a("li",[t._v("ejs")])]),t._v(" "),a("p",[t._v("차이점을 보면 ejs는 기본 html 문법을 그대로 사용하며, 협업할 때 ejs, 개인이 개발을 할 때는 pug을 추천한다. 두 템플릿엔진 둘 다 엔진을 통해서 html 문법으로 변환 시켜준다.")]),t._v(" "),a("p",[t._v("여기서는 pug을 주로 볼려고 한다.")]),t._v(" "),a("h2",{attrs:{id:"pug의-장점"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#pug의-장점"}},[t._v("#")]),t._v(" pug의 장점")]),t._v(" "),a("ul",[a("li",[t._v("HTML을 간단히 표현. 가독성이 좋다")]),t._v(" "),a("li",[t._v("마크업 문법보다 코드량이 적어 생산량이 좋다")]),t._v(" "),a("li",[t._v("JS 연산 결과를 쉽게 보여줌")]),t._v(" "),a("li",[t._v("정적인 부분과 동적인 부분 나눌 수 있다")])]),t._v(" "),a("h2",{attrs:{id:"pug의-특징"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#pug의-특징"}},[t._v("#")]),t._v(" pug의 특징")]),t._v(" "),a("ul",[a("li",[t._v("마크업과 달리 닫는 태그가 없다")]),t._v(" "),a("li",[t._v("들여쓰기로 종속성 구별")]),t._v(" "),a("li",[t._v("태그 선언시 태그 이름만 쓴다")]),t._v(" "),a("li",[t._v("ID와 CLASS 선언시 CSS 선택자 사용")]),t._v(" "),a("li",[t._v("태그 없이 ID나 CLASS 선언시 자동으로 div 태그 사용")]),t._v(" "),a("li",[t._v("태그에 속성 줄 땐 괄호 사용")]),t._v(" "),a("li",[t._v("여러줄 사용시에 "),a("code",[t._v("|")]),t._v(" 사용")]),t._v(" "),a("li",[t._v("script나 CSS로 태그 사용시 끝에 "),a("code",[t._v(".")]),t._v(" 입력")]),t._v(" "),a("li",[t._v("템플릿 속에서 Javascript 사용시 앞에 "),a("code",[t._v("-")]),t._v(" 입력")])]),t._v(" "),a("h2",{attrs:{id:"설치"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#설치"}},[t._v("#")]),t._v(" 설치")]),t._v(" "),a("p",[a("code",[t._v("npm install pug --save")])]),t._v(" "),a("p",[t._v("터미널에서 해당 명령어 입력 시 "),a("code",[t._v("package.json")]),t._v("에 dependencies에 추가된다.")]),t._v(" "),a("h2",{attrs:{id:"예시"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#예시"}},[t._v("#")]),t._v(" 예시")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("var express = require('express');\nvar app = express();\n\napp.set('view engine', 'pug'); // 사용할 템플릿 엔진 설정\napp.set('views', './views'); // 템플릿이 있는 폴더 지정 (지정 안한 경우 default로 views가 설정된다)\napp.use(express.static('public')) //정적 경로 지정\napp.get('/주소' function(req, res) => {\n\tres.render('pug파일 이름');\n})\n")])])]),a("h2",{attrs:{id:"문법"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#문법"}},[t._v("#")]),t._v(" 문법")]),t._v(" "),a("h3",{attrs:{id:"기본-문법"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#기본-문법"}},[t._v("#")]),t._v(" "),a("strong",[t._v("기본 문법")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("html\n\thead\n\tbody\n\t\th1 Hello Pug\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("idx.pug:\nhtml\n\thead\n\t\ttitle= title\n\tbody\n\t\th1= message\n\napp.js:\napp.get('/', function (req,res) => {\n\tres.render('idx', { title: 'Hey', message: 'Hello there!'});\n});\n")])])]),a("p",[t._v("들여쓰기로 상위태그 안에 종속하게 할 수 있다.")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<html>\n\t<head></head>\n\t<body>\n\t\t<h1>Hello Pug</h1>\n\t</body>\n</html>\n")])])]),a("p",[t._v("조금 더 심화해서 변수를 이용해보자")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("idx.pug:\nhtml\n\thead\n\t\ttitle #{_title}\n\tbody\n\t\th1 Hello Pug\n\t\tul\n\t\t\t-for(let i=0; i<5; i++)\n\t\t\t\tli Hello\n\t\tdiv #{time}\n\napp.js:\napp.get('/', (req,res) => {\n\tres.render('idx', {time:Date(), _title:'Pug'});\n})\n")])])]),a("h3",{attrs:{id:"문법-요약"}},[a("a",{staticClass:"header-anchor",attrs:{href:"#문법-요약"}},[t._v("#")]),t._v(" 문법 요약")]),t._v(" "),a("p",[t._v("HTML5")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("doctype html   \t\t→   <!DOCTYPE html>\n")])])]),a("p",[a("strong",[t._v("Block 생성")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("p foo \t\t  \t\t →   <p>foo</p>\n")])])]),a("p",[a("strong",[t._v("속성")])]),t._v(" "),a("ul",[a("li",[t._v("단일 속성")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("a (href='\t') Google  →  <a href=\"\t\">Google</a>\n")])])]),a("ul",[a("li",[t._v("다중 속성")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("input(\n\ttype='checkbox'\n\tname='agreement'\n\tchecked\n)\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v('<input type="checkbox" name="agreement" checked="checked">\n')])])]),a("p",[t._v("조건문")]),t._v(" "),a("ul",[a("li",[a("strong",[t._v("if문")])])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("- var user = { description: 'foo bar baz' }\n- var authorised = false\n#user\n\tif user.description\n\t\th2.green Description\n\t\tp.description= user.description\n\telse if authrised\n\t\th2.blue Description\n\t\tp.description.\n\t\t\tUser has no description,\n\t\t\twhy not add one...\n\telse\n\t\th2.red Description\n\t\tp.description\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v('<div id="user">\n\t<h2 class="green">Description</h2>\n\t<p class="description>foo bar baz</p>\n</div>\n')])])]),a("ul",[a("li",[a("strong",[t._v("unless문")]),t._v("\nif와 반대로 실행")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("unless user.isAnonymous\n\tp You're logged in as #{user.name}\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("if !user.isAnonymous\n\tp You're logged in as #{user.name}\n")])])]),a("p",[t._v("둘 다 같은 html로 변환되게 된다.")]),t._v(" "),a("p",[a("strong",[t._v("Case 조건문")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("- var friends = 10   // JS코드는 - 입력\ncase friends\n\twhen 0\n\t\tp you have no friends\n\twhen 1\n\t\tp you have a friend\n\tdefault\n\t\tp you have #{friends} friends\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<p>you have 10 friends</p>\n")])])]),a("p",[a("strong",[t._v("OR문과 Break")])]),t._v(" "),a("ul",[a("li",[t._v("OR문은 "),a("code",[t._v("when")]),t._v(" 밑줄에 다시 "),a("code",[t._v("when")]),t._v(" 조건")]),t._v(" "),a("li",[t._v("Break는 "),a("code",[t._v("- Break")]),t._v(" 입력")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("- var friends = 0\ncase friends\n\twhen 0\n\twhen 1\n\t\tp you have very few friends\n\t\t- break\n\tdefault\n\t\tp you have #{friends} friends\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<p>you have very few friends</p>\n")])])]),a("p",[a("strong",[t._v("Element 조건문")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("- var friends = 1\ncase friends\n\twhen 0: p you have no friends\n\twhen 1: p you have a friend\n\tdeafult: p you have #{friends} friends\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<p>you have a friends</p>\n")])])]),a("p",[a("strong",[t._v("반복문")])]),t._v(" "),a("ul",[a("li",[t._v("for문")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("- for (let x=0; x<3; x++)\n\tli item\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<li>item</li>\n<li>item</li>\n<li>item</li>\n")])])]),a("ul",[a("li",[t._v("each문")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v('-\n\tvar list = ["one", "two", "three", "four"]\neach item in list\n\tli= item\n')])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<li>one</li>\n<li>two</li>\n<li>three</li>\n<li>four</li>\n")])])]),a("p",[a("em",[t._v("마크업 코드를 내용물 그대로 표시")]),a("br"),t._v("\n예시")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("p\n\t= 'This code is <escaped>!'\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<p>This code is &lit;escaped&gt;!</p>\n")])])]),a("p",[t._v("이 때는 "),a("code",[t._v("=")]),t._v(" -> "),a("code",[t._v("!=")]),t._v("으로 고치면 마크업 코드 그대로 사용가능하다.")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("p\n\t!= 'This code is <strong>not</strong> escaped!'\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<p>This code is <strong>not</strong> escaped!</p>\n")])])]),a("p",[a("strong",[t._v("Mixin 변수")]),a("br"),t._v("\n템플릿 단위로 재사용 가능한 변수로, 규칙은 "),a("code",[t._v("+{변수 이름}")])]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("// 선언\nmixin list\n\tul\n\t\tli foo\n\t\tli bar\n\t\tli baz\n\n// 사용\n+list\n+list\n")])])]),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("<ul>\n\t<li>foo</li>\n\t<li>bar</li>\n\t<li>baz</li>\n</ul>\n<ul>\n\t<li>foo</li>\n\t<li>bar</li>\n\t<li>baz</li>\n</ul>\n")])])]),a("p",{attrs:{"파일":"","경로":""}},[a("strong",[t._v("includes(템플릿 파일 포함)")]),a("br"),t._v("\n규칙 : include")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("html\n\tinclude includes/head.pug\n\tbody\n\t\th1 My Site\n")])])]),a("p",[t._v("예시")]),t._v(" "),a("div",{staticClass:"language- extra-class"},[a("pre",{pre:!0,attrs:{class:"language-text"}},[a("code",[t._v("doctype html\nhtml\n\ttitle My Blog\n\tbody\n\t\tinclude includes/header.pug // 헤더\n\t\tp#main Welcome to my blog. // 헤더와 푸터 사이 내용\n\t\tinclude includes/footer.pug // 푸터\n")])])]),a("p",[a("a",{attrs:{href:"https://iseongho.github.io/posts/node-template-engine-pug/",target:"_blank",rel:"noopener noreferrer"}},[t._v("예시 참고"),a("OutboundLink")],1)])])}),[],!1,null,null,null);e.default=n.exports}}]);