---
sidebar: auto
---
# Sequelize
node.js를 이용해 웹 서버를 구축할 때 데이터베이스를 사용하게 된다. 이 때 쿼리문을 다 직접 작성하지 않고 간편하게 다룰 수 있게 해주는 것이 `ORM`이라고 한다. `ORM`은 객체와 관계형 데이터베이스의 관계를 매핑 해주는 도구로 자바스크립트만을 이용해서 쿼리를 데이터베이스에게 보내 줄 수 있다.  

그 중 sequelize라는 라이브러리를 보게 될 것이다.  
## 설치
```js
npm install sequelize // 시퀄라이즈 설치
npm install mysql2 // mysql2 설치
npm install -g sequelize-cli // sequelize-cli를 전역으로 설치한다.
```

## 모델
### 1. 직접 작성
```
sequelize init
```
해당 명령어를 통해 models 폴더 속 `index.js`가 만들어진다.
```js
// index.js 파일
"use strict";

const fs = require("fs");
const path = require("path");
const Sequelize = require("sequelize");
const basename = path.basename(__filename);
const env = process.env.NODE_ENV || "development";
const config = require(__dirname + "/../config/config.json")[env];
const db = {};

let sequelize;
if (config.use_env_variable) {
  sequelize = new Sequelize(process.env[config.use_env_variable], config);
} else {
  sequelize = new Sequelize(
    config.database,
    config.username,
    config.password,
    config
  );
}

fs.readdirSync(__dirname)
  .filter(file => {
    return (
      file.indexOf(".") !== 0 &&
      file !== basename &&
      file.slice(-3) === ".js"
    );
  })
  .forEach(file => {
    const model = sequelize["import"](path.join(__dirname, file));
    db[model.name] = model;
  });

Object.keys(db).forEach(modelName => {
  if (db[modelName].associate) {
    db[modelName].associate(db);
  }
});

db.sequelize = sequelize;
db.Sequelize = Sequelize;
```

`index.js` 파일에서 반복문을 돌면서 models 폴더 속 파일을 읽어가며 모델로 정의한다. 원하는 테이블 이름을 파일의 이름으로 js 파일로 만들어 준 뒤 모델을 정의하게되면 해당 테이블이 만들어진다.  

모델을 정의하는 메소드는 `define()`이다.
```js
sequelize.define('객체 이름', 스키마 정의, 테이블 설정)
```
과 같이 사용하면 된다.  

```js
module.exports = (sequelize, DataTypes) => {
  return sequelize.define(
    "messages", // 테이블 이름
    {
      // 스키마 정의
      messageContent: {
        // column 이름
        type: DataTypes.STRING(500), // 데이터 타입 설정
        allowNull: false // null 허용 설정
      },
      userId: {
        type: DataTypes.INTEGER,
        allowNull: false
      },
      roomId: {
        type: DataTypes.INTEGER,
        allowNull: false
      }
    },
    {
      // 테이블 옵션
      timestamps: true,
      underscored: true,
      paranoid: true
    }
  );
};
```
해당 코드와 같이 `define()` 메소드를 이용해 테이블을 생성해 주고 있다. 테스트 시엔 `sequelizae.sync()`을 작성하고 코드 실행 후 mysql에 접속하여 테이블을 확인하면 된다. 전에 설명과 같이 models에 js파일들을 원하는 이름으로 생성하여 테이블 생성하면 그대로 얻어 낼 수 있다.

### 2.CLI로 정의
models 폴더에 직접 작성하지 않고 터미널 창에서 명령어를 통해 테이블을 정의하는 방법이다. 이때의 sequelize-cli라는 것은 `sequelize command line interface`의 준말이다. 따라서 터미널에서 명령어를 통해 데이터베이스 작업을 할 수 있게 만들어준다.
기본 문법
```js
sequelize model:create --name TABLE_NAME  --attributes "COLUMN1:type, COLUMN2:type, COLUMN3:type"
```

유저의 모델
```js
sequelize model:create --name user --attributes nickName: string, passWord: string
```

이 때 migrations 폴더에는 현재 시간을 이름으로 갖는 migration 파일이 생성된다. 그리고 models 폴더에는 `user.js` 파일이 생성된다. 이 `user.js` 파일은 위에서 직접 작성한 파일과 비슷하게 된다. 다른 점은 테이블의 이름이 복수형으로 저장된다는 점이다.  
```js
"use strict";
module.exports = (sequelize, DataTypes) => {
  const user2 = sequelize.define(
    "user2",
    {
      user_id: DataTypes.STRING,
      password: DataTypes.STRING
    },
    {}
  );
  user2.associate = function(models) {
    // associations can be defined here
  };
  return user2;
};
```
이후 옵션 설정은 `user.js` 파일에서 직접 설정해야한다. 이후 설정 적용시에는 user table을 drop 후 `sequelize.sync()`을 실행시켜 새로 생성한다. 이때 옵션을 수정했다면 migrations 폴더에 있는 user/migrations 파일 또한 수정해주어야한다. 이후 마지막으로 명령어를 통해 migrate할 수 있다.
```
sequelize db:migrate
```