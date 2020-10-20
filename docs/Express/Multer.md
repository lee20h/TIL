  
 
  
# Multer Module
보통 JSON 형식으로 된 데이터는 AJAX로든 폼 태그로든 쉽게 업로드할 수 있습니다. 이미지 업로드를 도와주는 multer 모듈이 있다.

## 설치

```jsx
npm install multer
```

## 예제

```jsx
const multer = require('multer');
// 기타 express 코드
const upload = multer({ dest: 'uploads/', limits: { fileSize: 5 * 1024 * 1024 } });
app.post('/up', upload.single('img'), (req, res) => {
  console.log(req.file); 
});
```

이제 폼데이터나 폼 태그를 통해 업로드한 이미지를 올리면 `req.file`로 정보가 들어오고, **dest** 속성에 지정해둔 경로에 이미지가 저장된다. **limits** 속성은 선택 사항인데 여러 가지 제한을 걸 수 있다. 위에서는 파일 사이즈를 5MB로 제한했다. `upload.single('img')` 미들웨어를 라우터 콜백함수 전에 끼워넣은 것은 폼데이터의 속성명이 img이거나 폼 태그 인풋의 name이 img인 파일 **하나만** 받겠다라는 뜻이다. 이미지가 아닌 나머지 데이터는 그대로 `req.body`에 들어옵니다.

만약 이미지를 하나가 아닌 여러 개를 받고 싶다 하면 `upload.array('키', 최대파일개수)` 하면 된다. `req.file` 대신 `req.files`에 정보가 담긴다.

최종적으로 사용하는 코드는 대부분 아래의 예제와 같다.

```jsx
const path = require('path');
const upload = multer({ 
	storage: multer.diskStorage({ 
		destination: function (req, file, cb) { 
			cb(null, 'uploads/');
	 },
		filename: function (req, file, cb) { 
			cb(null, new Date().valueOf() + path.extname(file.originalname));
		}
	}),
});
```

진행 중인 프로젝트에서는 이런 식으로 구현했다.
```jsx
const storage = multer.diskStorage({
    destination: (req, file, cb) => {
        cb(null, './uploads/');
    },
    filename: (req, file, cb) => {
        const originalFileName = file.originalname.split('.');
        let fileName = 'none';
        if (originalFileName.length > 0) {
            fileName = `${originalFileName[0]}-${Date.now()}.${originalFileName[1]}`;
        }
        cb(null, fileName)
    }
});
const upload = multer({
    storage: storage,
})
```