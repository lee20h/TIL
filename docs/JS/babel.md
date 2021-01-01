# Babel

Babel은 자바스크립트 컴파일러로, 최신 버전의 자바스크립트의 경우 브라우저가 이해하지 못하는 경우가 많다. 이 때 브라우저가 이해할 수 있는 자바스크립트로 변환해주는 컴파일러로 ES6, ES7 등의 최신 문법을 변환시켜 준다.

그 예시로 ES6의 arrow function, classes, enhanced object literals, template strings, destructuring 등 유용한 기능이 많다. 이러한 내용들을 바로 사용하기 위해서는 babel의 도움 없이는 브라우저에 이해 시키기 어려울 수 있다.

## babel-polyfill

babel로 모든 최신의 자바스크립트 문법을 컴파일할 수 있는 것은 아니다. 바로 브라우저 마다 지원하는 함수가 다 다르기 때문이다. 따라서 polyfill을 통해서 처음 시작할 때 브라우저가 지원하지 않는 함수를 검사해서 각 object의 prototype을 붙여준다. 이 때 bable은 컴파일 타임에 실행되고 babel-polyfill은 런타임에 실행된다.

## .babelrc

`.babelrc` 파일을 프로젝트 root 폴더에 생성하자. plugins와 presets 속성이 중요하다. 위에서 설명했던 각 문법이 하나의 plugin이라고 생각하면 된다. 그리고 preset은 plugin 여러 개가 묶여있는 개념이다. 대표적으로 ES6 문법을 모아놓은 es2015 preset과 react 문법을 모아놓은 react preset이 있다. 사용할 preset을 presets에 추가하고 presets에 속해있는 plugin 외에 추가로 사용하고 싶은 plugin은 plugins에 넣자.