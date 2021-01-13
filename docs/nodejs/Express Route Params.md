# Express Route Params

라우팅에 있어서 새롭게 알게 된 내용이 있어서 정리하려고 한다. 그 내용은 라우팅할 때 만약 ID와 같이 변동하는 숫자가 있다면 어떻게 할까라는 내용이다.

```js
const HOME = "/";
const JOIN = "/join";
const LOGIN = "/login";
const LOGOUT = "/logout";
```

보통 이런 식으로 라우팅하게 되는데 이 때 만약 유저의 ID를 구별해야 할 경우에는 막막하다. 보통 그 숫자는 가변형이고 어떤 형태로 들어올지 모른다. 숫자일수도 있고, 일련의 알파벳과 숫자의 조합일 수도 있다.

이런 부분을 해결하기 위해서 알아야하는 것은 바로 이것이다.

```js
const USERS = "/users";
const USER_DETAIL = "/:id";
```

user를 라우터에 연결하고 `user/id`와 같은 형태를 사용할 때 `/:id`와 같이 라우팅을 하면 된다. `/:`뒤에 들어오는 값은 req.params에 들어가는 값으로 http request를 받는 메소드에서 사용할 수 있다.

예를 들어서 `/users/:id`로 연결된 라우팅을 받는 메소드가 다음과 같이 있다

```js
userRouter.get("/:id", userController);
```

userRouter가 `/user`에 연결이 되어있다면 해당 get 요청은 `/user/:id`로 연결되게 된다. 이 때 id는 어떤 값이든 올 수 있고, express에서는 `콜론(:)`뒤에 들어오는 값을 신경쓰지 않는다. 그리고 id의 경우에는 `userController`라고 명시한 컨트롤러에 해당하는 함수에서 `req.params.id`와 같은 값으로 접근이 가능하다. 따라서 url에 들어간 id를 가지고 메소드에서 처리를 할 수 있다는 것을 알 수 있다.
