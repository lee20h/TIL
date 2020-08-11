---
sidebar: auto
---
# Path Module
Path 모듈은 파일과 Directory 경로 작업을 위한 Utility를 제공한다.

## **Path 모듈의 주요 메소드들**

### **1.path.normalize**

normalize에 Path를 넣으면 알아서 경로를 normalize해서 return 해준다.

```jsx
const path = require("path");
let myPath = path.normalize("/this/is//a//my/.././path/normalize");
console.log(myPath); // /this/is/a/path/normalize
```

위의 경우 ../는 상위 디렉토리로 가기 때문에 my가 생략된 것을 볼 수 있다.

### **2. path.join([...paths])**

path.join은 String을 주게 되면 플랫폼별(windows냐 mac이냐) 구분자를 사용해서 경로를 정규화해서 리턴해준다.

```jsx
const path = require("path");
myPath = path.join("/this", "is", "a", "////path//", "join");
console.log(myPath); // /this/is/a/path/join
```

플랫폼에 따라 구분자는 달라지므로 윈도우라면 백슬래시(**\**)가 들어갈 것이다.

### **3.path.resolve([...paths])**

path.resolve는 path.join과 path.normalize를 합친 것 같은 효과이다.

이것은 주어진 문자열을 cd를 해서 최종 마지막 폴더까지 간 후 pwd(Print Working Directory)를 한 것과 동일하다. 그리고 문서에 따르면 절대 경로가 만들어질 때까지 prepend된다.

그리고 만약 주어진 path를 모두 사용했음에도 절대 경로를 못만들었다면, cwd(Current working Directory)를 사용한다.

```jsx
const path = require("path");
myPath = path.resolve("/this", "is/a", "../.", "path", "resolve");
console.log(myPath); // /this/is/path/resolve
myPath = path.resolve("wwwroot", "static_files/png/", "../gif/image.gif");
console.log(myPath); // /Users/yohan/Desktop/MyTest/wwwroot/static_files/gif/image.gif
/*
이 경우에는 주어진 값만으로는 절대경로를 만들 수 없으므로 cwd를 사용한다.
*/
```

### **4. path.dirname(path), path.basename(path[, ext])**

path.dirname은 현재 작업하고 있는 디렉토리의 이름을 출력한다.반면 path.basename은 파일이름을 출력한다.만약 basename에 옵션값을 주게 되면 뒤의 확장자를 제거할 수도 있다.

```jsx
const path = require("path");
myPath = path.dirname("/foo/bar/baz/asdf/image.png");
console.log(myPath); ///foo/bar/baz/asdf
myPath = path.basename("/foo/bar/baz/asdf/image.png");
console.log(myPath); //image.png
myPath = path.basename("/foo/bar/baz/asdf/image.png", ".png");
console.log(myPath); //image
```

### **5.path.parse(path)**

path.parse는 path를 말 그대로 파싱해준다.

```jsx
const path = require("path");
myPath = path.parse("/home/user/dir/file.txt");
console.log(myPath);
// { root: '/',
// dir: '/home/user/dir',
// base: 'file.txt',
// ext: '.txt',
// name: 'file' }
```

이러한 메소드가 있지만 magicsora에서는 path 모듈과 `__dirname` 을 사용해서 현재의 경로를 사용하여 정적 경로와 접근했다.