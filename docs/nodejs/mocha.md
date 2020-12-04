# Mocha.js

- [참고 블로그 : A to Z님](https://a-tothe-z.tistory.com/13)

Mocha.js는 JavaScript에서 사용할 수 있는 테스트 프레임워크로 Simple, Flexible, Fun이라는 특성을 내세운다. 소프트웨어공학이라는 수업을 들으면서 TDD. 즉 테스트 주도 개발을 알게되면서 처음으로 사용하기 수월한 것을 찾다가 공부하게 되었다.

먼저 설치가 필요한데 npm으로 global 혹은 dependency로 설치하면 된다.

## 설치

```
$ npm install mocha --global
```

```
$ npm install mocha --save-dev
```

추가적으로 Mocha를 실행할려면 Node.js 버전 4 이상, 설치에는 npm이 2.14.2 이상이여 한다.

## 시작

package.json에 스크립트를 추가하면 조금 더 편리하게 사용할 수 있다. 이러한 스크립트는 파일들에 대해 감시 옵션인 `-w`를 추가해서 실행하는 것이다. 파일이 변경할 때마다 자동으로 테스트 러너가 실행된다ㅏ.

```json
"scripts": {
  "test": "node_modules/.bin/mocha $(find ./ -name '*.js') --recursive -w"
},
```

프로젝트 내에서 테스트를 하기 위한 디렉토리를 생성한 후 테스트코드는 `.spec.js` 파일로 작성한다.

### assert

assert를 통해서 assertion 함수를 쉽게 사용할 수 있다.

```js
const assert = require("assert");
```

### describe

`describe()`으로 테스트 suite을 만들고 그 안에 `it()`으로 테스트 코드를 작성한다. `descirbe()`은 중첩해서 사용할 수 있다.

```js
describe('테스트 이름', function() {

})
```

### it

it으로 테스트 코드를 작성할 수 있다. 이때 it의 첫번째 인수는 테스트 케이스 이름을 넣어주면 된다.

그리고 두번째 파라미터로는 Mocha가 done 객체를 전달해줄 테스트케이스의 함수를 넣어준다. 여기서 done객체는 테스트케이스가 종료되었을 때 호출된다. 따라서 이를 이용해 비동기 처리를 할 수 있다.

```js
describe('Test suite', function () {
  it('Test', function () {
    assert.equal(true, false)
  })
})
```

위와 같은 테스트는 실패를 받을 수 있다.

## 실행

터미널에서 다음과 같이 입력하면 실행할 수 있다.

```
$ mocha
```

그러면 describe를 한 덩어리로 보고 밑에 it을 각각을 나눠서 테스트를 한 뒤 보여주게 된다.

여기에서 더 나아가면 `describe()`안에 또 다른 `describe()`를 추가할 수 있다. 그렇게 한다면 세부 카테고리화를 하여 조금 더 체계를 갖출 수 있게 된다.

## 추가적으로

### 비동기 코드 예제

위에서 언급한 것처럼 done 객체를 반환하게 되면 비동기 처리를 할 수 있다.

```js
describe('User 테스트', function () {
    describe('저장 테스트', function () {
        it('저장 에러 여부', function (done) {
            var user = new User('YoungHun');
            user.save(done);
        })
    })
})
```

이와 같이 쉽게 테스트 해볼 수 있다.

### Hooks

BDD. 행위주도개발 스타일의 인터페이스를 위해서 hooks 들은 `before()`, `after()`, `beforeEach()`, `afterEach()` 등을 제공한다. 전제조건으로 설정한 뒤 테스트하게 되면 테스트를 정리해준다.

```js
describe('hooks 테스트', function () {
    before(function () {
        //모든 테스트가 실행되기 전에 이 블럭이 실행됩니다.
    });

    after(function () {
        //모든 테스트 실행 후에 이 블럭이 실행됩니다.
    });

    beforeEach(function () {
        //각각의 테스트 실행 전에 이 블럭이 실행됩니다.
    });

    afterEach(function () {
        //각각의 테스트 실행 후에 이 블럭이 실행됩니다.
    })

    //테스트 케이스 작성
})
```

테스트 코드 전/후로 hooker를 실행할 수 있다. 테스트 suite 전/후로 before과 after가 실행된다. beforeEach와 afterEach는 테스트 suite 안에 정의한 모든 테스트 코드 실행 전/후마다 실행이 된다. 예를 들어서 테스트에 필요한 자료를 데이터베이스에 삽입하거나 삭제하는 등의 일련의 작업을 코드 실행 전/후로 실행할 때 사용된다.

### Exclusive 테스트

특정 suite나 테스트케이스만 테스트하고 싶으면 `.only()`를 함수에 추가하면 된다.

```js
describe("...", function () {
  // 오직 이 테스트만 수행됨
  describe.only("해당 suite만 실행", function () {
    it("...", function () {})
  })

  describe("...", function () {
    it("...", function () {})

    it("...", function () {})
  })
})
```

### Inclusive 테스트

Exclusive와는 정반대로 `.skip()`을 함수에 추가하게 되면 해당 케이스나 suite를 무시하고 진행된다.

```js
describe('...', function () {
  // 이 테스트는 스킵됨
  describe.skip('해당 suite 무시', function () {
    it('...', function () {})
  })

  describe('해당 suite는 실행', function () {
    it('...', function () {})

    it('...', function () {})
  })
})
```

### Pending 테스트

콜백이 없는 케이스로, 테스트 케이스를 비워놓고 누군가가 작성해야하는 부분을 의미한다.

```js
var assert = require('assert'); 

describe('테스트', function () {
    describe('Pending 테스트', function() {
       it('누군가 이 케이스를 작성해야 합니다.')
    });
})
```