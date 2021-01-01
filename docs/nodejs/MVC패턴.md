# MVC 패턴

node.js와 express를 이용하여 서버를 구축할 때 많이 사용하는 패턴인 MVC 패턴에 대해 알아 봤다.

MVC 패턴은 Model, View, Controller로 이루어져있다.

- Model : data
- View : how does the data look
- Controller : function that looks for the data

Model: Database, View: Template, Controller: Function 이라 생각하면 좋다.

MVC패턴의 핵심은 Model에 해당하는 데이터, View에 해당하는 보여지는 부분, Controller에 해당하는 함수와 같은 기능들을 전부 소스단에서 분리를 하는 것이다.

## Model

Model은 데이터베이스에 정의된 데이터들을 정의한 부분이라고 할 수 있다. MongoDB와 Mongoose를 사용하게 되면 모델의 스키마들을 정의하고 모델들을 연결한다.

따라서 Model을 View와 Controller를 분리해서 스키마만 정의해놔서 수정이 필요할 때 편리하게 수정할 수 있다.

## View

View를 담당하는 부분은 말 그대로 보여지는 부분이다.

이로써 유지보수에 있어서 디버깅도 쉽고 문제 찾기에 큰 도움이 되며 여러 장점이 생긴다.

여기서 해본 것은 express에서 view engine인 pug를 이용하여 view를 구성하는 것이다. template을 구성하고 template에서 필요한 부분을 고쳐가는 식으로 만들어보았다.


## Controller

Controller에는 express에서의 Rotuer가 각각 들어간다고 생각하면 좋다. 예를 들어 userRouter가 존재한다면 userController가 있듯이 하나의 라우터에 맞게 컨트롤러를 형성한다.

이 때 Router를 구성할 때 routes.js 파일을 하나 구축하여 해당 파일에 다른 사람들이 URL을 몰라도 정해진 상수를 통해서 접근할 수 있게 파일을 정의하면 좋다.

```js
// Global

const HOME = "/";
const JOIN = "/join";
const LOGIN = "/login";
const LOGOUT = "/logout";
const SEARCH = "/search";

// Users

const USERS = "/users";
const USER_DETAIL = "/:id";
const EDIT_PROFILE = "/edit-profile";
const CHANGE_PASSWORD = "/change-password"

// Videos

const VIDEOS = "/videos";
const UPLOAD = "/upload";
const VIDEO_DETAIL = "/:id";
const EDIT_VIDEO = "/:id/edit";
const DELETE_VIDEO = "/:id/delete";

const routes = {
    home: HOME,
    join: JOIN,
    login: LOGIN,
    logout: LOGOUT,
    search: SEARCH,
    users: USERS,
    userDetail: USER_DETAIL,
    editProfile: EDIT_PROFILE,
    changePassword: CHANGE_PASSWORD,
    videos: VIDEOS,
    upload: UPLOAD,
    videoDetail: VIDEO_DETAIL,
    editVideo: EDIT_VIDEO,
    deleteVideo: DELETE_VIDEO
};

export default routes;
```

다른 Router나 초기에 Routing할 때 해당 설정 값을 통해서 정의할 수 있다.

이제 컨트롤러를 정의해보자. 컨트롤러는 크게 함수로 보면 되는데, express에서 url과 함수를 같이 쓰는 get 예로 보자.

위의 routes를 예시로 함께 사용하면,

```js
export const videoHome = (req, res) => res.send("Home");
```

해당 함수를 export하는 videoController이다.

```js
import { videoHome } from "../controllers/videoController";
globalRouter.get(routes.home, videoHome);
```

이런 식으로 Controller와 View를 분리할 수 있다. Controller는 Model 마다 하나씩 존재해야한다. Model의 경우 데이터베이스에서 정의하는 모델로, 각각 모델마다 컨트롤러를 따로 정의하여 사용한다.

