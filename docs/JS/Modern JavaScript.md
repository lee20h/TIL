

# Modern JavaScript

## 블록 영역
변수를 저장하기 위한 `var`외에 `let`과 `const`가 추가 되었다. `var`와 다르게 `let`은 선언 이전에 접근 할 수 없다. (`var`의 경우 선언, 초기화 과정이 동시에 이루어짐.)  

`let`은 블록 유효 범위를 갖는 지역 변수를 선언하며, `const`선언은 읽기 전용 참조를 생성한다. 이것은 담긴 값의 불변이 아니라, 변수 식별자가 다른 데이터로 재 할당이 불가능 하다는 뜻이다.  

## 문자  
Template Literal을 사용하면 명시적인 문자열 이스케이프를 사용하지 않아도 특수문자를 포함한 문자열을 구축 할 수 있다. 예를 들어 \`\`이러한 백틱을 이용하면 특수문자를 쉽게 사용할 수 있으며 문자열을 접합 시킬 때도 `+`연산이 아닌 `${표현식}`을 통해서 가독성을 높일 수 있다. 또한, 템플릿 코드 작성에 있어 ES6는 개행이 보존되어 더 깔끔하게 코드 작성이 가능하다.  

## 함수
### `Arrow Function`  

화살표 함수 식은 `function` 표현에 비해 구문이 짧고 자신의 `this`, `arguments`, `super` 또는 `new.target`을 바인딩 하지 않아서 항상 `익명함수`이다. 이 함수 표현은 메소드 함수가 아닌 곳에 적합하고, 생성자로는 적합하지 않다. 따라서 `this`의 컨텍스트를 보존해야할 경우 화살표 함수를 사용해야한다.  

```js
function Person(name) {
  this.name = name;
}

Person.prototype.prefixName = function (arr) {
  return arr.map(character => {
    // this 컨텍스트는 Person 객체입니다.
    return this.name + character;
  });
};
```
익명 함수를 사용하듯이 간단한 값을 리턴하는 함수나 함수 표현식이 필요할 때 사용하면 간결해진다.  
```js
const arr = [1,2,3,4,5];
const squares = arr.map(function (x) return { return x * x});
-->
const squares = arr.map(x => { return x * x});  
or
const squares = arr.map(x => x * x);
```
따라서 ES6+ 일때 가능하면 사용하는게 간결하며 가독성을 증가시킬 수 있다.  

### Default Parameter  

기본 매개 변수를 자바스크립트에서 처리하는 방법은 C++에서 처리했던 방법과 같이 ES6부턴 바뀌었다.  
```js
function add(x=0, y=0) {
	return x + y;
}
```

### Rest Parameter  

나머지 매개 변수에 대해서  
```js
function logArguments(...args) {
	args.forEach(arg => console.log(arg))
}
```

배열 구조 분해 할당을 통해서 이름이 있는 매개변수을 손쉽게 구현할 수 있다. 하지만 함수의 인자를 전달하지 않으면 `null`이 전달되어 오류가 발생하기 때문에 기본 매개 변수를 설정하면 해결할 수 있다.
```js
function initializeCanvas({ height=720, width=480, lineStroke='#122122'}) {
  console.log(`height = ${height}`);
  console.log(`width = ${width}`);
  console.log(`lineStroke = ${lineStroke}`);
}

initializeCanvas({
  lineStroke: '#786e51'
});
```

### Spread Operator 
 
전개 연산자를 사용할 수 있는데 이 연산자는 `...`을 통해서 매개변수로 배열을 보내거나, 배열을 합치거나, 객체 리터럴을 합칠 수 있다. 하지만 중첩된 데이터를 포함한 객체를 복사할 때는 전개 연산자가 아닌 JSON 객체의 `stringify`나 `parse`을 사용 해야한다. 만약 중첩된 데이터를 포함한 객체를 복사할 때 전개 연산자를 사용하게 되면 값 복사가 아닌 값 참조가 일어나서 심각한 오류를 발생 시킬 수 있다.  

## 객체  
### Shorthand Properties  
객체는 `new Object()`, `Object.create()` 또는 리터럴 표기법으로 초기화 할 수 있다. 자바스크립트에서는 속기형 속성 작성법을 통해서 객체의 속성 정의를 편리하게 `[]`와 `{}`을 통해 배열과 객체 속성을 정의할 수 있다. 여기에 추가적으로 객체의 속성과 값의 이름이 동일한 경우에는 다음과 같이 작성하면 간결하다.  
```js
const favorites = { animations, movies, music};
```  

### Object Enhancements

간추린 메소드 표기법과 계산된 속성 이름 동적 설정을 통해 향상된 객체 표기법을 사용한다. 먼저 간추린 메소드 표기법은 아래와 같다.  
```js
let name  = 'SM7',
    maker = 'Samsung',
    boost = 'powerUp';

const car = {
  // 간추린 메서드 표기법
  go() {},
  stop() {},
  boost() {}
};

console.dir(car);
// Object
//  ↳ go: ƒ go()
//  ↳ stop: ƒ stop()
//  ↳ boost: ƒ boost()
//  ↳ __proto__: Object
```  
이런 식으로 메소드들을 function을 명시하지 않고 표기할 수 있다. 계산된 속성 이름 동적 설정은 변수나 자바스크립트 식에 의해 계산된 속성 이름을 동적으로 설정할 수 있다.
```js
let name  = 'SM7',
    maker = 'Samsung',
    boost = 'powerUp',
    dynamicMethod = 'Satisfactory';

const car = {
  go() {},
  ['stop']() {},
  [boost]() {}, // 변수를 받아 계산된 속성 이름 적용 가능
  [`${dynamicMethod.replace(/s/ig, 'S')}`]() {} // JavaScript 식을 계산하여 동적으로 속성 이름 적용 가능
};

console.dir(car);
// Object
//  ↳ go: ƒ go()
//  ↳ powerUp: ƒ [boost]()
//  ↳ stop: ƒ ['stop']()
//  ↳ SatiSfactory: ƒ [`${dynamicMethod.replace(/s/ig, 'S')}`]()
//  ↳ __proto__: Object
```

또 `getter/setter`을 사용할 수 있어서 `get`과 `set`을 사용하여 접근할 수 있다. 자바스크립트에서는 비공개(private) 접근 제어자를 제공하지 않아서 관습적으로 `_`을 이름 앞에 붙여 사용하지만 접근은 가능하다. 비공개 접근 제어자 대신에 외부와 단절된 블록 영역과 `Symbol`을 사용한 고유 식별자로 접근 불가능한 속성을 사용할 수 있다.
```js
{

  // 심볼(Symbol) 등록
  // - 고유하고 수정 불가능한 데이터 타입이며
  // 주로 객체 속성(object property)들의 식별자로 사용된다.
  let _wheel = Symbol('wheel');

  global.car = {
    // 등록된 심볼을 계산된 속성으로 사용
    [_wheel]: 4,
    get wheel() {
      return this[_wheel]; // 심볼 반환
    },
    set wheel(new_wheel) {
      if ( typeof new_wheel !== 'number' ) {
        throw new Error('전달 인자 유형은 숫자여야 합니다.');
      }
      // 계산된 값을 심볼에 할당
      this[_wheel] = new_wheel > 4 ? new_wheel : 4;
    }
  };

}
```

### Destructuring Assignment

구조 분해 할당은 위에서 한번 언급했으므로 가볍게 적어본다. ES5에서는 객체 선언 후 객체 속성 하나하나를 직접 할당하는 표현식을 짰어야했으나, ES6+부터는 객체를 구조 분해하여 각 변수에 속성이나 멤버들을 직접 바로 할당할 수 있다.  

## 심볼
Symbol 데이터 타입은 고유한 기본 값으로 수정이 불가능하며 클래스나 객체 내부에서만 접근할 수 있는 비공개 키로 사용된다.  
```js
{
  // 블록 스코프 내에서만 접근 가능한 심볼
  const _privateKey = Symbol();

  // 글로벌에 공개된 클래스
  window.FileReader = class {
    constructor() {
      this[_privateKey]();
    }
    [_privateKey]() {
      console.log('비공개 멤버로 클래스 FileReader 만 접근하여 사용 가능');
    }
  }
}

const fileReader = new FileReader(); // '비공개 멤버로 클래스 FileReader 만 접근하여 사용 가능'

fileReader[_privateKey](); // Uncaught ReferenceError: _privateKey is not defined
```

### Symbol()  

`Symbol()` 또는 `Symbol([description])`이 실행되어 반환되는 모든 심볼 값은 고유하여 심볼 값이 객체 속성에 대한 식별자로 사용될 수 있다. 그리고 new Symbol()이 제공되지 않는다.  

## 배열  
### Array Additions  
배열 객체에 추가된 클래스나, 스태틱, 인스턴스 메소드  
`Array.from()`  
유사 배열을 배열화할 수 있다.  
```js
// DOM 객체 수집(Collection) = NodeList
// lis 변수에 참조된 값은 length 속성을 가진 유사 배열 객체
var lis = document.querySelectorAll('ul.demo li');

// Array.from() 네이티브 Array 메서드를 사용하여 lis 유사 배열을 배열로 변경
Array.from(lis).forEach(li => console.log(li)); // <li> 순환
```
전개 연산자를 사용하여 유사 배열 객체를 배열화 할 수 있다.  
```js
const lisHTML = [...lis].map(li => li.innerHTML);
```

`Array.of()`  
Array 객체를 생성할 때 new 키워드를 사용하여 만들며, 숫자를 배열의 인자로 전달하는 경우 애매모호한 문법으로 배열의 크기가 선언된다. 이러한 문제를 마주치지 않기 위해 배열 리터럴을 선언하며 할당을 해주었다. Array.of()구문을 사용하면 첫번째 인자가 숫자라도 애매모호한 문법을 해결할 수 있다.  

`Array.prototype.keys()`  
for문과 foreach문을 넘어서 `for .. of`문을 통해서 데이터를 순환 처리할 수 있다. 여기에서 데이터 값이 아닌 인덱스 키를 출력하고자하면 객체의 `.key()`메소드를 사용하게 되면 인덱스 키를 추출할 수 있다. 마찬가지로 `.value()`로 데이터를 추출하며, 둘 다 필요한 경우에는 `.entry()`를 사용하면 된다. 추가적으로 `find()`와 `findIndex()`을 통해서 원하는 값과 인덱스를 찾을 수 있다.

배열 객체를 사용할 때 쓰면 유용한 메소드는 `Array.isArray()`와 `Array.foreach`(for문과 for..of문도 가능), `Array.map()`, `Array.filter()`, `Array.sort()`  
map의 경우에는 새로운 배열로 반환한다는 점을 기억해야한다.  

## 클래스
C++와 같이 클래스를 선언하고 사용할 수 있으나 생성자의 경우 직접 명시해서 사용해줘야한다.  
```js
class Person {
  constructor(name, age, gender) {
    this.name   = name;
    this.age    = age;
    this.gender = gender;
  }
  incrementAge() {
    this.age += 1;
  }
}
```  
그리고 상속도 존재하는데 상속은 `extend` 키워드로 상속을 하면 된다.  

## 모듈  
`import` `export`를 사용하여 외부 모듈이나 다른 스크립트로 보내고 받아서 사용할 수 있다.  
간단하게 `export` 키워드를 가지고 내보내기가 쉽게 가능하다. 또한 객체를 이용한 리스트 내보내기도 가능하다.  
```js
function sumTwo(a,b) {
	return a + b;
}
function sumThree(a,b,c) {
	return a + b + c;
}
let api = {
	sumTwo,
	sumThree
};
export default api;
```
모듈을 내보낼 때 이렇게 사용하며 항상 `export default` 메소드는 모듈 코드의 마지막에 위치해야 한다.  
`import`또한 키워드를 통해서 쉽게 받아올 수 있다. 하지만 전체를 불러오면 그 파일의 모든 코드가 실행되므로 파이썬과 유사하게 지정 불러오기를 사용할 수 있다. 다음과 같이 사용한다.  
```js
import { sumTwo, sumThree} from 'math/addition';
or
import {
	sumTwo as addTwoNumbers,
	sumThree as sumThreeNumbers
} from 'math/addition';
```

디폴트 모듈에 경우에는 다음과 같다.
```js
import api from 'math/addition';
or
import { default as api} from 'math/addition';
```
추가적으로 react에 경우는 이렇게 사용한다.
```js
import React from 'react';
const { Component, PropTypes } = React;
or
impor React, { Component, PropTypes } from 'react';
```

import되는 값은 참조되서 사용하는게 아니라 바인딩되서 사용하므로 값이 모듈 외부에서 바뀔 일은 없다.  

## 비동기 프로그래밍  
### Promise  

`Promise`는 비동기 조작의 최종 완료 또는 실패를 나타내는 객체이다. 또한 `Fetch API`를 이용하여 요청, 응답과 같은 HTTP의 파이프라인 요소를 조작하는 것이 가능하다.  

```js
func1(function (value1) {
  func2(value1, function (value2) {
    func3(value2, function (value3) {
      func4(value3, function (value4) {
        func5(value4, function (value5) {
          // ...
        });
      });
    });
  });
});
```
--->
```js
func1(value1)
  .then(func2)
  .then(func3)
  .then(func4)
  .then(func5, value5 => {
    // ...
  });
```

프로미스를 사용하는 예제
```js
const promise = new Promise((resolve, reject) => {
  if ( true ) {
    resolve();
  } else {
    reject();
  }
});

promise
  .then(() => {
    // ...
  })
  .catch(error => {
    console.error(error.message);
  })
```
Promise의 추가적인 메소드를 살펴보면 먼저 `.all()`을 사용하게 되면 비동기 처리가 요구되는 API배열에서 Promise를 병렬 처리 할 수 있다. `.race()`을 사용하면 여러 Promise중 가장 먼저 도착된 것을 실행한다.  

### Async/Await  

Async 함수는 function 키워드 앞에 Async를 붙이면 된다. 이 함수는 암묵적으로 Promise를 반환하므로 `.then()` 또는 `.catch()` 메솓르르 사용해 실행이나 거절을 처리할 수 있다.  

### Await  

Await 키워드는 데이터가 응답 반환 될때까지 실행흐름을 중단 시킨다.  
```js
const getData = () => {
  let timeout = Math.floor(Math.random() * 2000);
  return new Promise(resolve => {
    window.setTimeout(() => resolve(['지연', '된', '데이', '터', '전송']), timeout);
  });
};

async function asyncFn() {
  const data = await getData(); // 데이터 응답까지 대기
  console.log(data); // 응답 받은 후 데이터 출력
}
```
getdata가 돌아올 때까지 실행 흐름을 멈춰놓고 돌아오면 진행된다.  
`await`키워드는 Async 함수 내부에서만 사용이 가능하다.  

Async/Await 코드르 사용하면 Promise 코드를 조금 더 간결하게 표현할 수 있다.  

```js
Promise 코드
const api = 'https://jsonplaceholder.typicode.com';

function asyncCallDatas() {
  let todo, photo;
  Promise.all([
    fetch(`${api}/todos/9`)
      .then(response => response.json())
      .then(data => todo = data),
    fetch(`${api}/photos/7`)
      .then(response => response.json())
      .then(data => photo = data)
  ])
  .then(results => console.log(todo, photo));
}

asyncCallDatas();
```
Async/Await 코드
```js
const api = 'https://jsonplaceholder.typicode.com';

async function asyncCallDatas() {
  let todo = await (await fetch(`${api}/todos/9`)).json();
  let photo = await (await fetch(`${api}/photos/7`)).json();
  console.log(todo, photo);
}

asyncCallDatas();

해당 코드를 Promise.all()와 구조 분해 할당으로 더 간결하게 처리할 수 있다.
async function asyncCallDatas() {
  let [ todo, photo ] = await Promise.all([
    (await fetch(`${api}/todos/9`)).json(),
    (await fetch(`${api}/photos/7`)).json()
  ]);
  console.log(todo, photo);
}
```  

## 이터레이션  
### for.. of  

for ..of 문은 반복 가능한 객체(Array, Map, Set, String, TypedArray, arguments 객체 등을 포함)에서 반복하고 각 개별 속성 값에 대해 실행되는 문이 있는 사용자 정의 반복 후크를 호출하는 루프를 생성한다.  

배열 순환
```js
const iterable = [9, 19, 109];

for (let item of iterable) {
  console.log(item);
  // 9
  // 19
  // 109
}

for (let [index, item] of iterable.entries()) {
  console.log(index, item);
  // 0, 9
  // 1. 19
  // 2. 109
}
```

문자 순환
```js
const iterable = 'yamoo9';

for (let char of iterable) {
  console.log(char);
  // 'y'
  // 'a'
  // 'm'
  // 'o'
  // 'o'
  // '9'
}
```

Set 순환
```js
const iterable = new Set([9, 19, 109, 19, 9]);

for (let number of iterable) {
  console.log(number);
  // 9
  // 19
  // 109
}
```

Map 순환
```js
const iterable = new Map([['name', 'yamoo9'], ['job', '강사']]);

for (let info of iterable) {
  console.log(info);
  // ['name', 'yamoo9']
  // ['job', '강사']
}

for (let [key, value] of iterable) {
  console.log(`key => ${key}`);
  console.log(`value => ${value}`);
  // key => name
  // value => yamoo9
  // key => job
  // value => 강사
}
```

NodeList 순환
```js
const buttons = document.querySelectorAll('button');

for (let button of [...buttons]) {
  button.classList.add('button');
}
```

Generator 순환
```js
function* fibonacci() {
  let [prev, curr] = [1, 1];
  while (true) {
    [prev, curr] = [curr, prev + curr];
    yield curr;
  }
}

for (let n of fibonacci()) {
  console.log(n);
  if (n >= 1000) { break; }
}
```  

### `for..in문`과 `for..of문`의 차이점  
for..in문은 객체의 열거 가능한(enumerable) 모든 속성을 순환한다.  
for...of문은 컬렉션 전용이며, [Symbol.iterator] 속성이 있는 모든 컬렉션을 순환한다.  

```js
// Object, Array 프로토타입 확장
Object.prototype.addCustom = function () {};
Array.prototype.createCustom = function () {};

// 배열 객체를 정의하고, 임의의 속성을 추가
let iterable = ['스트레칭', '다이어트'];
iterable.interval = '항상';

// for..in문 순환
for (let key in iterable) {
  let value = iterable[key];
  console.log(value);
  // '스트레칭'
  // '다이어트'
  // '항상'
  // function () {}
  // function () {}
}

for (let value of iterable) {
  console.log(value);
  // '스트레칭'
  // '다이어트'
}
```  

### Iterable 프로토콜  

조건 : [Symbol.iterator] 메서드를 소유해야 한다.  
Iterator 프로토콜에 준하는 객체를 반환해야 한다.  

```js
const star4 = {
  [Symbol.iterator]() {
    let _star = Symbol('_star');
    return {
      [_star]: '',
      next() {
        if ( this[_star].length < 4 ) {
          this[_star] += '*';
          return {
            value: this[_star],
            done: false
          };
        } else {
          return { done: true };
        }
      }
    }
  }
};

/* -----------------------------------
// 검토
------------------------------------ */

star4[Symbol.iterator]();
// 출력: {next: ƒ, Symbol(_star): ""}

[...star4];
// 출력: ["*", "**", "***", "****"]

for (let star of star4) {
  console.log(star);
}
// 출력:
// *
// **
// ***
// ****
```

### Iterator 프로토콜  

조건 : 인자를 받지 않는 next() 메서드를 소유해야 한다.  
next() 메서드의 반환 값은 객체로 value, done 속성을 소유해야 한다.  
done은 반복이 종료될 경우 true, 종료되지 않을 경우 false 여야 한다.  
value는 JavaScript의 모든 데이터 타입 설정이 가능하다.  

```js
function iteratorMaker(array) {
  let index = 0;
  return {
    next() {
      if (index < array.length) {
        return { done: false, value: array[index++] };
      } else {
        return { done: true };
      }
    }
  }
}

/* -----------------------------------
// 검토
------------------------------------ */

const protocols = iteratorMaker(['iteration', 'iterable', 'iterator']);
// 출력: {next: ƒ}

protocols.next(); // {done: false, value: 'iteration'}
protocols.next(); // {done: false, value: 'iterable'}
protocols.next(); // {done: false, value: 'iterator'}
protocols.next(); // {done: true, value: undefined}
```

### Iteration Object  

객체를 순환 처리하는 경우 `for..in문`외에도 `for..of`문을 사용할 수 있다.  

Object.keys() : 객체의 속성을 배열 객체로 반환
```js
const picture_keys = Object.keys(picture);
// 출력: ['large', 'medium', 'thumbnail']

for (let key of picture_keys) {
  console.log(key);
}
```

Object.values() : 객체의 값을 Iterable 프로토콜에 준하는 객체로 반환
```js
const picture_values = Object.values(picture);
// 출력: ['https://...', 'https://...', 'https://...']

for (let value of picture_values) {
  console.log(value);
}
```

Object.entires() : 객체의 속성, 값을 쌍으로 하는 배열을 묶은 배열을 반환  
```js
const picture_entries = Object.entries(picture);
// 출력:  
// [
//   ['large', 'https://...' ],
//   ['medium', 'https://...'],
//   ['thumbnail', 'https://...']
// ]

for (let [key, value] of picture_entries) {
  console.log(key, value);
}
```

추가적으로 배열 객체 메소드를 사용하여 순환하는 것도 가능하다.  
```js
// 속성 순환
Object.keys(picture).forEach(key => console.log(key));

// 값 순환
Object.values(picture).forEach(value => console.log(value));

// 속성, 값 순환
Object.entries(picture).forEach(entry => {
  const [key, value] = entry;
  console.log(key, value);
});
```

## 제너레이터  
Generator 객체는 제너레이터 함수 `function* () {}`로부터 반환된 값이며, 이터레이션 프로토콜을 준수한다.  

피보나치
```js
function* fibonacci(n=1) {
  let [ current, next ] = [1, 1];
  while(n--) {
    yield current;
    [ current, next ] = [ next, current + next ];
  }
}

let fibo10 = fibonacci(10);

[...fibo10]; // [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
```

간단한 ID 생성
```js
function* idMaker(id=10000, prefix="id") {
  while(true) {
    yield `${prefix}-${Math.floor(Math.random() * id)}`;
  }
}

const ids = idMaker();

ids.next().value; // "id-743"
ids.next().value; // "id-985"
ids.next().value; // "id-5198"
```

고유키 생성
```js
function* uniqueIdMaker(count=5, limit=10) {
  const keys = 'abcdefghijklmnopqrstuvwxyz!@#1234567890'.split('');
  function _uid(count){
    let randomKey = '';
    while(count--) {
      randomKey += keys[Math.floor(Math.random() * keys.length)];
    }
    return randomKey;
  }
  while(limit--) {
    yield _uid(count);
  }
}

const uid = uniqueIdMaker(10, 3);

console.log([...uid]); // ["1rk#8p57ji", "#qwhk6wuwx", "wg5fc06i0e"]
```

## 컬렉션
### set  

C++ STL의 set과 동일하게 사용할 수 있다. 배열과 같이 사용하되, 중복을 허용하지 않으며 메소드로는 `.size`, `.add()`, `.has()`, `.delete()`, `.clear()`가 있따. 또, Set 객체를 순환하는 메소드는 `forEach()`, `.entries()`, `.values()`, `.keys()`
이 있다. 위에서 이미 살펴본 메소드들 이므로, 예제는 생략한다.  

합집합, 교집합, 차집합, 부분집합을 처리할 수 있는데 정의 방법을 살펴보자.
```js
class y9Set extends Set {

  // 합집합
  union(x){ return new Set([...this, ...x]) }

  // 교집합
  intersect(x){return new Set([...this].filter(y => x.has(y)))}

  // 차집합
  diff(x){return new Set([...this].filter(y => !x.has(y)))}

  // 상위 집합 유무 확인
  isSuperset(x){
    for (let y of x) {
      if (!this.has(y)) { return false; }
    }
    return true;
  }
```

### map  

map 또한 C++ STL의 map과 동일하며 key/value를 가지는 자료구조이다. 메소드는 `get`, `set`, `has` 등을 제공한다. 키 값을 문자열만 사용하지 않아도 되며, 어떤 타입을 전달해도 문자열로 형변환 하지 않는다. 마지막으로 `.entires()`을 사용하면 쉽게 순환 시킬 수 있다.  

### WeakSet  

WeakSet은 Set과 유사하다. set과 달리 객체만 수집할 수 있으며, 약한 참조가 이루어져 메모리 누수를 예방할 수 있다.  
특징으로는 size 속성을 가지지 않으며, 객체 타입만 `.add()`하거나 `.delete()`할 수 있다. 또한 `forEach`문과 `for..in`문으로 순환 할 수 없다. 마지막으로는 약한 참조로 메모리 누수 관리에 효과적이다.  

### Set과 WeakSet의 차이
```js
// 데이터(객체)
let arr = [1, 3, 5, 7],
    obj = {key: 'value'};

// Set 객체 생성
let set = new Set();

// WeakSet 객체 생성
let wset = new WeakSet();

// 아이템 추가
set.add(arr).add(obj);
wset.add(arr).add(obj);

// 아이템 사이즈
console.log(set.size);  // 2
console.log(wset.size); // undefined

// 객체가 아닌 데이터 추가
set.add(true);
wset.add(true); // 오류 발생: Invalid value used in weak set

// 아이템 소유 여부 확인
set.has(obj);  // true
wset.has(obj); // true

// 아이템 제거
set.delete(arr);  // true
wset.delete(arr); // true

// 세트 순환
set.forEach(item => console.log(item));  // 참조된 데이터에 접근 및 사용 가능
wset.forEach(item => console.log(item)); // 오류 발생: wset.forEach is not a function

// 메모리 참조
let set  = new Set();
let wset = new WeakSet();

(() => {

  let o1 = {a: 1}; // 메모리
  let o2 = {a: 2}; // 가비지 컬렉터에 의해 메모리 삭제

  set.add(o1);
  wset.add(o2);

});
```

추천 사용법은  
```js
// WeakSet 객체 생성
let ownClass = new WeakSet();

// 클래스 OffCanvasMenu 정의
class OffCanvasMenu {

  constructor() {
    // 클래스 자신을 ownClass에 추가
    ownClass.add(this);
    // ...
  }

  toggle() {
    // OffCanvasMenu 객체가 아닌,
    // 다른 객체가 toggle() 메서드를 사용하려 할 경우 오류 출력
    if ( !ownClass.has(this) ) {
      throw new TypeError('toggle() 메서드는 OffCanvasMenu 객체만 사용 가능합니다!');
    }
  }
}
```

- WeakMap  

WeakMap은 WeakSet과 동일하게 Map과 달리 객체만 수집하며, 약한 참조로 메모리 누수를 예방한다.  

```js
let _age = new WeakMap();

class Person {
  constructor(age) {
    _age.set(this, age);
  }
  incrementAge() {
    let age = _age.get(this) + 1;
    _age.set(this, age);
    if (age > 50) {
      console.log('반 백년을 살았구나!~');
    }
  }
}
```
이런식으로 사용하는데 비공개 데이터를 저장하기 위해서 사용하게 되면 `Reflect.ownKeys()`을 통해서도 멤버 이름이 드러나지 않는다는 점이 특징이다. 따라서 DOM요소 자체를 훼손시키지 않고 DOM 요소에 연관 데이터를 저장하게 되면 가비지 컬렉션에 의해 제거된 DOM 객체에 약한 참조된 WeakMap이 자동으로 제거되어 메모리 관리가 수월해진다. 예시는 다음과 같다.  
```js
let map = new WeakMap();

let someEl = document.querySelector('#some');

// 요소에 대한 약한 참조(weak reference)를 저장
map.set(el, '참조');

// 요소의 값에 접근
let value = map.get(el); // '참조'

// DOM 요소 제거 시, 자동으로 map 참조 제거
el.parentNode.removeChild(el);
el = null;

value = map.get(el); // undefined
```


---

[참고자료](https://yamoo9.github.io/next-javascript/) 