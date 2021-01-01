# Pug

Pug는 express의 view engine으로 html의 태그를 그대로 사용하는 특징이 있다. pug로 작성된 파일을 html로 변환시켜서 그대로 보여주게 되기 때문에 라우팅된 url마다 다르게 render해서 보여줄 수 있다.

사용법은

```
$ npm install pug
```

이후 express 애플리케이션에 `app.set("view engine", "pug")`와 같이 설정하면 끝난다. 이후에는 views 폴더에 pug 파일을 작성하고 애플리케이션에서 작성된 파일의 이름을 render하게 되면 화면에 표시된다.

pug 파일의 문법은 html에서 사용하는 태그와 같지만 `<p>content</p>`와는 다르게 `p content` 공백을 이용해서 태그를 나눈다. 그리고 들여쓰기를 통해서 태그의 포함을 표현한다.

하나의 template를 생성한 뒤 `extends template.pug`로 연결하게 되면 다음과 같이 사용할 수 있다.

- template.pug

```pug
doctype html
html
    head
        title Title
    body
        header
            h1 Title
        main
            block content
        footer
            span &copy; lee20h
```

- home.pug

```pug
extends layout/main

block content
    p Hello!!
```

이렇게 사용하게 되면 template.pug가 기반으로 block 태그만 직접 입력할 수 있게 템플릿을 직접 작성할 수 있다.

html을 직접 사용하는 것보다 훨씬 편하고 빠른 view 작성이 될 수 있다.

또한 추가적으로 기능을 살펴보면 pug에서 `#{}`을 통해서 자바스크립트를 사용할 수 있으며, Express에서 미들웨어를 이용하여 `res.locals.변수명`을 사용하여 변수를 등록하게 되면 pug에서도 해당 값을 사용할 수 있다.

## Mixin

Mixin은 Pug의 함수로, 반복되는 html 덩어리들을 함수 형태로 만들 수 있는 기능을 제공한다.

다음과 같이 정의한다.

```pug
mixin func(args)
```

그 이후엔 일련의 정의를 해줘야한다. 예를 들어,

```pug
mixin list
    ul
        li list1
        li list2
        li list3
        li list4
```

와 같은 덩어리를 만든 다음 mixins/list.pug로 저장을 한다.

```pug
include mixins/list

+list
+list
+list
```

이렇게 다른 pug파일에서 사용할 수 있다. 사용된 mixin과 함께 pug파일이 html파일로 변환되면 다음과 같다.

```html
<ul>
    <li>list1</li>
    <li>list2</li>
    <li>list3</li>
    <li>list4</li>
</ul>
<ul>
    <li>list1</li>
    <li>list2</li>
    <li>list3</li>
    <li>list4</li>
</ul>
<ul>
    <li>list1</li>
    <li>list2</li>
    <li>list3</li>
    <li>list4</li>
</ul>
```

즉, mixin을 만든 뒤 다른 파일에서 include 해서 사용할 수 있게 된다. 이 때 사용은 `+mixin명`으로 사용하면 된다.

만약 인자가 존재한다면 어떨지 예시로 봐보자.

```pug
mixin country(name)
    li.country=name
```

```pug
include mixins/country

ul
    +country('Korea')
    +country('USA')
    +country('Germany')
```

```html
<ul>
    <li class="country">Korea</li>
    <li class="country">USA</li>
    <li class="country">Germany</li>
</ul>
```

인자로 객체를 받는 경우도 있다. 만약 render 과정에서 넘어온 객체를 받아 화면에 뿌려줘야하는 경우도 있다. 예시로 확인해보자.

```pug
mixin countryBlock(country={})
    .countryBlock
        h2.country__name=country.name
        h4.country__language=country.language
        h4.country__flower=country.flower
```

```pug
include mixins/countryBlock

.countries
    each item in country
        +countryBlock({
            name:item.name
            language:item.language
            flower:item.flower
        })
```

이렇게 사용하게 되면 country라는 객체를 받은 pug 파일이 mixin의 인자로 객체를 전달하여 반복적으로 화면에 뿌려주는 역할을 할 수 있다.