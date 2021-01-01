# Mongoose Model

Mongoose를 이용한 MongoDB에서 Schema를 작성하고 model로 사용하는 방법

## Schema

NoSQL이 그렇듯 도큐먼트에 무엇을 넣든 에러가 나지 않는다. 또한 MongoDB는 JSON 형태로 객체들을 전부 저장하게 된다. 에러가 나지 않으므로 실수로 인한 데이터 또한 저장이 된다.

이러한 부분을 막기 위해서 Mongoose는 Schema를 도입했다. 사용자가 작성한 스키마를 이용하여 데이터를 DB에 넣기 전에 검사하는 역할을 한다. 이 부분은 SQL의 테이블의 역할과도 비슷하다고 볼 수 있다.

따라서 Mongoose를 이용하여 MongoDB를 사용할려면 먼저 스키마를 정의해야한다.

### Schema 정의

`mongoose.Schema()`를 통하여 스키마를 정의할 수 있다. SQL 테이블과 비슷하게 인덱스나 기본 값을 정의할 수 있고 여러가지 옵션으로 편하게 기능을 구현할 수 있다.

스키마를 정의한 후 각각을 모델로 정의하여 MongoDB에서 사용할 수 있게 모듈로써 제공하면 더욱 MVC패턴으로 사용할 수 있다.

추가적으로 스키마끼리 관계를 정의할 때 사용하는 방법이 여러가지 있다. 먼저, 비디오와 댓글의 관계를 보면 비디오 한 개당 여러 개의 댓글을 가질 수 있다. 이 때, 비디오 스키마에 댓글 ID를 배열로 갖거나, 댓글 스키마에 비디오 ID를 가지게하여 관계를 갖게 할 수 있다.

```js
type: mongoose.Schema.Types.ObjectId,
ref: "model명"
```

## 예시

```js
import mongoose from "mongoose";

const StudentSchema = new mongoose.Schema({
    name: {
        type: String,
        required: "Name is required"
    },
    age:  {
        type: Number,
        required: "Age is required"
    },
    sex: String,
    Birthday: Date
});

const model = mongoose.model("Student", StudentSchema);
export default model;
```