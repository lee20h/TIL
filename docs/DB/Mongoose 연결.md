# Mongoose 연결

Mongoose를 Node.js 프로젝트에서 사용할 때 연결과 설정에 대해서 알아보았다.

## 설치

`$ npm install mongoose`를 사용하여 원하는 프로젝트에 mongoose를 설치해준다.

## 연결 설정

```js
import mongoose from "mongoose";

mongoose.connect(
  "mongodb://localhost:27017",
  {
    useNewUrlParser: true,
    useFindAndModify: false
  }
);

const db = mongoose.connection;

const handleOpen = () => console.log("✅ Connected to DB");
const handleError = error => console.log(`❌ Error on DB Connection: ${error}`);

db.once("open", handleOpen);
db.on("error", handleError);
```

db를 담당하는 자바스크립트 파일에 먼저 mongoose를 import한 뒤 `connect()`를 해준다.

이후에는 `once()`를 통해서 연결을 해주고 에러처리를 위해서 다음과 같이 `on()`를 사용한다.

이 때 연결에 들어가는 인자는 새로운 버전의 mongoose를 받을 때 에러를 막기 위해서 넣어주는 부분이다.

그리고 url이 그대로 노출되는 걸 막기 위해서 dotenv를 사용한다.

## dotenv

.env 파일에 다음과 같이 추가해준다.

```
MONGO_URL="mongodb://localhost:27017"
```

```js
import dotenv from "dotenv";
dotenv.config();

mongoose.connect(
  process.env.MONGO_URL,
  {
    useNewUrlParser: true,
    useFindAndModify: false
  }
);
```

process.env.변수명으로 사용할 수 있다.

이런식으로 설정한 뒤 .gitignore에 추가한다면, 우리의 연결 정보를 비밀로 유지할 수 있다.