---
sidebar: auto
---

# Vuepress [공식사이트](https://vuepress.vuejs.org/guide/)

현재 TIL도 Vuepress를 통해서 만들어져있다. Vuepress란 Vue.js로 개발된 정적 사이트 생성기라고 생각하면 된다. 기본 테마를 제공하여 더 쉽게 개발을 할 수 있게 도와주며, Plugin API를 제공하여 Plugin을 제작하고 적용할 수 있다.  

또한, 테마도 Vue.js를 이용해 제작하거나 다른 개발자가 만든 테마를 입혀서 자기 입맛대로 바꾸기 수월하다.  

## Quick Start
`yarn create vuepress [directoryName]`을 통해서 해당 원하는 디렉토리에서 vuepress을 생성한다.  

## Manual Setup
1) 새 디렉토리를 만들어서 그곳으로 이동한다.
`mkdir vuepress-starter && cd vuepress-starter`

2) 패키지 매니저를 초기화한다.
`yarn init # npm init`

3) VuePress을 설치한다.
`yarn add -D vuepress # npm install -D vuepress`

4) docs 경로를 만든 다음 README.md 마크다운을 만들어서 입력한다.
`mkdir docs && echo '# Hello VuePress'` > `docs/README.md`

5) package.json에 Script에 아래와 같이 입력하여 yarn으로 VuePress을 빌드하고 개발을 위해 로컬로 킬 수 있게 한다.
```
{
  "scripts": {
    "docs:dev": "vuepress dev docs",
    "docs:build": "vuepress build docs"
  }
}
```

6) 로컬 서버로 열어 개발을 한다.
`yarn docs:dev # npm run docs:dev`

그 이후로는 정적 페이지를 만들 수 있게 되었다.  

`.vuepress/config.js`에서 자바스크립트 외부로 모듈을 export 할 수 있다. 따라서 아래와 같이 기입하게 되면 build을 할 때 해당 내용이 html으로 변환되어 build 폴더에 생기게 된다. 그 값이 index.html으로 남게 된다.
```
module.exports = {
  title: 'Hello VuePress',
  description: 'Just playing around'
}
```
이 외에도 `base`로 base url을 지정하거나 `themeConfig`을 통해서 `sidebar`와 `nav`을 만들어서 ui를 구축할 수 있다. 먼저 `nav`는 맨 위 상단 바에 유지되는 내용이고, `sidebar`의 경우에는 왼쪽에 메뉴로 값들을 유지할 수 있다.  
나의 경우에는 `.vuepress/components`에 Home.vue로 index.html을 바꾸게 했으며 그렇기 위해서 루트 디렉토리의 Readme.md를 home.vue으로 잡아줬다. 이후에는 `.vuepress/` 경로에 폴더로 나눠서 마크다운 형식의 파일로 모두 표기하며  
```
---
sidebar : auto
---
```
을 통해서 자동으로 `#, ##, ###`을 h1, h2, h3으로 자동으로 매칭해주며, 왼쪽 사이드바에 나오게 된다.  