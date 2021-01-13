# MongoDB ObjectId

NoSQL 데이터베이스인 MongoDB를 사용하다보면 관계형 데이터베이스의 Join 연산과 같이 다른 컬렉션의 특정 데이터를 참조할 필요가 생긴다. 이렇게 참조할 수 있는 자료형이 바로 ObjectId이며, Join과 같은 연산 기능을 가진 것이 populate라고 한다.

## ObjectId

ObjectId는 하나의 document 내에서 유일함이 보장되는 12 byte binary data로, MongoDB 자체에서 자동으로 기입되는 고유 값으로 다른 컬렉션에 있는 데이터를 참조할 수 있다.

MongoDB ODM인 Mongoose를 사용하여 스키마 중 ObjectId를 정의하는 코드를 예시로 보자

### 예시

비디오와 유저, 코멘트를 컬렉션을 가지고 스키마를 각각 정의할 때 유저는 비디오와 코멘트를 배열로 참조하여 가져야한다. 비디오는 코멘트를 배열로 갖고, 게시자로 유저 하나만 가질 수 있다. 코멘트는 게시자로 유저 하나만 가질 수 있다.

따라서 다음과 같이 스키마를 정의할 수 있다.

- Comment

```js
const CommentSchema = new mongoose.Schema({
  text: String,
  createdAt: {
    type: Date,
    default: Date.now,
  },
  creator: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User",
  },
});
```

- Video

```js
const VideoSchema = new mongoose.Schema({
  fileUrl: String,
  title: String,
  description: String,
  views: {
    type: Number,
    default: 0,
  },
  createdAt: {
    type: Date,
    default: Date.now,
  },
  comments: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Comment",
    },
  ],
  creator: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User",
  },
});
```

- User

```js
const UserSchema = new mongoose.Schema({
  name: String,
  email: String,
  comments: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Comment",
    },
  ],
  videos: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "Video",
    },
  ],
});
```

## Populate

- [Mongoose Populate DOCS](https://mongoosejs.com/docs/populate.html)

위에서 MongoDB에서 ObejctId에 경우에는 고유의 값을 적는다고 하였다. 이 고유의 값을 통해서 참조를 하게 된다. 참조 값 또한 고유의 값 ID가 그대로 적혀있으며 구체적인 스키마를 알 수가 없다. 이 부분을 해결해주는 것이 populate이다.

특징이라고 하면 populate의 경우에는 스키마로 이루어진 모델의 메소드이므로 인스턴스를 가지고 사용할 수는 없다. 바로 예시를 봐보자.

### 예시

```js
const {
    user: { id },
  } = req;
  try {
    const userVideo = await User.findById(id).populate("videos");
  } catch(error)
  ...
```

위에서 본 컬렉션들의 스키마를 그대로 가져와서 보면 유저는 자신이 올린 일련의 비디오들을 가지고 있다. 하지만 이 비디오들은 Video 컬렉션에서 참조한 ID만 저장되어서 보여준다.

여기서 `populate("videos")`를 함으로써 User 모델 중 id에 맞는 데이터를 찾은 뒤 그 중 videos 속성의 내용을 실제 객체로 치환해준다. 이후에 userVideo를 호출하면 가지고 있는 videos 속성의 내용을 실제로 확인할 수 있다.

### 성능 문제

populate는 $oid로 모두 조회를 해서 자바스크립트 단에서 합쳐주는 것이지 Join처럼 데이터베이스 자체에서 합쳐주는 것이 아니다. 따라서 성능이 그렇게 좋지 않다. 특히 populate가 중첩되면 성능 문제가 생길 확률이 커지므로 적재적소에 쓰여야한다.
