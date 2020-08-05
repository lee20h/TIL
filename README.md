# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록
* 쓸데없는 Commit 지양
* markdown으로 작성
* 1일 1문제(PS, SQL) 해결

---  

| [5월](./month/5월) | [6월](./month/6월) | [7월](./month/7월) |
|----|-----|-----|

---  

- 1日  

### Ajax HTTP 요청 헤더

**HTTP 헤더**  
클라이언트와 서버 사이에 이루어지는 HTTP 요청과 응답은 HTTP 헤더를 사용하여 수행됩니다. HTTP 헤더는 클라이언트와 서버와 서로에게 전달해야 할 다양한 종류의 데이터 포함한다.  

```
Accept: */*
Referer: http://codingsam.com/examples/tryit/tryhtml.php?filename=ajax_header_request_01
Accept-Language: ko-KR
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko
Host: codingsam.com
DNT: 1
Connection: Keep-Alive
```

- 헤더 이름, 콜론, 공백, 헤더 값의 순서로 구성
- 일부 헤더는 요청 헤더와 응답 헤더에 모두 사용되나, 일부 헤더는 둘 중 하나에서만 사용
- 요청 헤더는 원래 웹 브라우저가 자동으로 설정해서 보내므로, 사용자가 직접 설정 불가하나, Ajax를 이용하여 직접 설정하거나 확인 가능

HTTP 요청 헤더  
Ajax에서는 요청을 보내기 전에 setRequestHeader() 메소드를 사용하여 HTTP 요청 헤더를 작성 가능하다. 해당 메소드는 아래와 같다.
```
XMLHttpRequest인스턴스.setRequestHeader(헤더이름, 헤더값);
```
예제로는,
```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        document.getElementById("text").innerHTML = httpRequest.responseText;
    }
};
httpRequest.open("GET", "/examples/media/ajax_request_header.php", true);
httpRequest.setRequestHeader("testheader", "123");
httpRequest.send();
```

HTTP 응답 헤더  
- getAllResponseHeaders() 메소드 :  HTTP 응답 헤더의 모든 헤더를 문자열로 반환
- getResponseHeader() 메소드 :  HTTP 응답 헤더 중 인수로 전달받은 이름과 일치하는 헤더의 값을 문자열로 반환

```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        document.getElementById("text").innerHTML = httpRequest.responseText;
        document.getElementById("header").innerHTML = httpRequest.getAllResponseHeaders();
        document.getElementById("user").innerHTML =
            "testheader: " + httpRequest.getResponseHeader("testheader");
    }
};
httpRequest.open("GET", "/examples/media/ajax_response_header.php", true);
httpRequest.send();
```

Content-Type 헤더  
Content-Type 헤더의 값을 직접 설정하지 않으면, HTML 문서의 MIME 타입인 "text/html"로 자동 설정되며 Ajax 응용 프로그램에서 다루게 되는 XML은 일반적인 파일 형태의 XML 문서가 아니다. Ajax 요청을 받은 후 서버에서 실행되어 동적으로 생성되는 XML 형태의 데이터이므로 확장자가 `.xml`이 아니다. 따라서 header() 함수를 사용하여 응답 데이터의 MIME 타입이 `text/xml`이라고 명시해야한다.

```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        document.getElementById("text").value = httpRequest.responseText;
        document.getElementById("header").innerHTML = httpRequest.getAllResponseHeaders();
        document.getElementById("user").innerHTML =
            "testheader: " + httpRequest.getResponseHeader("tes
    }
};
httpRequest.open("GET", "/examples/media/ajax_response_header_xml.php", true);
httpRequest.send();
```

### Ajax 고급
다양한 Ajax 요청  

주기적으로 Ajax 요청하기  
Ajax는 클라이언트가 서버에 데이터를 요청하는 클라이언트 풀링 방식을 사용하므로, 서버 푸시 방식의 실시간 서비스를 만들 수 없다. 이 땐 주기적으로 Ajax 요청을 보내도록 설정하여, 실시간 서비스와 비슷한 동작을 하도록 만든다.  

0.5초마다 주기적으로 Ajax 요청을 보내 현재 서버 시간 출력하는 예제
```
function sendRequest() {
    var httpRequest = new XMLHttpRequest();
    httpRequest.onreadystatechange = function() {
        if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
            document.getElementById("text").innerHTML = httpRequest.responseText;
        }
    };
    httpRequest.open("GET", "/examples/media/ajax_periodic_request.php");
    httpRequest.send();
}
sendRequest();
window.setInterval("sendRequest()", 500); // 매 0.5초마다 Ajax 요청을 보냄.
```
0.5초마다 XMLHttpRequest 객체를 계속 초기화한다. 이때 서버에서의 응답이 0.5초 이상 걸리게 되면 화면에는 아무것도 표시되지 않을 수도 있다.

```
function sendRequest() {
    var httpRequest = new XMLHttpRequest();
    httpRequest.onreadystatechange = function() {
        if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
            document.getElementById("text").innerHTML = httpRequest.responseText;
            self.setTimeout("sendRequest()", 500); // 응답을 받은 후 0.5초 뒤에 다시 Ajax 요청을 보냄.
        }
    };
    httpRequest.open("GET", "/examples/media/ajax_periodic_request.php");
    httpRequest.send();
}
sendRequest();
```
해당 예제는 응답을 받고 나서 0.5초가 지난 후에 sendRequest() 함수를 다시 호출하는 예제다.  

데이터가 변경된 경우에만 Ajax 응답하기  
매번 요청하게 되면 네트워크와 서버의 자원을 많이 소모하게 된다. 따라서 웹 페이지의 내용이 변경된 경우 서버가 응답을 보내도록 설정하는 것이 자원을 절약할 수 있다. 이 방법은 Ajax 요청 헤더에 이전 요청 시간을 헤더로 포함해서 보내는 것으로 설정할 수 있다.  

Ajax 요청 취소
```
function abortRequest() {
    httpRequest.abort();
    document.getElementById("text").innerHTML = "Ajax 요청을 취소했습니다.";
}
```
`abort()`메소드를 사용하면 된다.  

### 문서 타입별 응답 처리
서버로부터의 응답 데이터 확인
- responseText 프로퍼티

서버에 요청하여 응답으로 받은 데이터를 문자열로 반환한다.
```
document.getElementById("text").innerHTML = xmlHttp.responseText;
```
텍스트 파일의 응답 처리
```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        // 텍스트 파일의 응답 처리는 responseText 프로퍼티를 사용해야 함.
        document.getElementById("text").innerHTML = httpRequest.responseText;
        // 텍스트 파일의 응답 처리에 responseXML 프로퍼티를 사용하면 null을 반환함.
        document.getElementById("xml").innerHTML = httpRequest.responseXML;
    }
};
httpRequest.open("GET", "/examples/media/ajax_doctype_text.php");
httpRequest.send();
```

- responseXML 프로퍼티

서버에 요청하여 응답으로 받은 데이터를 XML DOM 객체로 반환한다.
```
var httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        // XML 문서의 응답 처리에 responseText 프로퍼티를 사용하면 XML 코드를 문자열로 반환함.
        document.getElementById("text").innerHTML = httpRequest.responseText;
        // XML 문서의 응답 처리는 responseXML 프로퍼티를 사용해야 함.
        document.getElementById("xml").innerHTML = httpRequest.responseXML;
    }
};
httpRequest.open("GET", "/examples/media/ajax_doctype_xml.php");
httpRequest.send();
```

XML 데이터의 응답 처리
서버로부터 XML 데이터를 응답으로 받은 경우에는 responseXML 프로퍼티를 사용하여 받은 데이터를 처리할 수 있다.
먼저 responseXML 프로퍼티를 사용하여 XML DOM 객체를 반환한 후에 해당 객체를 가지고 작업하면 된다.
```
var httpRequest, xmlData, result, i;
httpRequest = new XMLHttpRequest();
httpRequest.onreadystatechange = function() {
    if (httpRequest.readyState == XMLHttpRequest.DONE && httpRequest.status == 200 ) {
        xmlData = httpRequest.responseXML;
        document.getElementById("text").innerHTML =
            xmlData.getElementsByTagName("b")[0].firstChild.nodeValue;
            // XML 데이터의 첫 번째 <b>태그의 텍스트 노드의 값을 반환함.
    }
};
httpRequest.open("GET", "/examples/media/ajax_doctype_xml.php");
httpRequest.send();
```

---

- 2日  

BOJ 별 찍기 - 11을 통해서 프랙탈 구조를 재귀 형태로 구현하는 방법을 공부하였다. 제일 먼저 예제를 통해서 들어오는 값만큼 높이를 가진다는 것만 파악하고 나머지를 작은 삼각형을 통해서 큰 삼각형을 만들려는 생각이 들었지만 앞으로 나아가지 못했다. 다른 블로그의 포스팅으로 구조를 공부해서 풀어보았다.
```
void star(int n, int y, int x) {
	if (n == 3) {
		arr[y][x] = '*';
		arr[y+1][x-1] = '*';
		arr[y+1][x+1] = '*';
		arr[y+2][x-2] = '*';
		arr[y+2][x-1] = '*';
		arr[y+2][x] = '*';
		arr[y+2][x+1] = '*';
		arr[y+2][x+2] = '*';
		return;
	}
	
	star(n/2,y,x);
	star(n/2,y+(n/2),x-(n/2));
	star(n/2,y+(n/2),x+(n/2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; 
	for (int i=0; i<n; i++) {
		for (int j=0; j<2*n; j++) {
			if (j == 2 * n - 1)
				arr[i][j] = '\0';
			else
				arr[i][j] = ' ';
		}
	}
	
	star(n, 0, n-1);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<2*n-1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}
```

큰 삼각형이 3개의 삼각형을 쪼개지고, 쪼개진 삼각형 안에 3개의 삼각형으로 쪼개지는 프랙탈 구조이므로 재귀함수를 이용해서 문제를 해결해야한다. 큰 삼각형 속에 윗 삼각형, 좌하단 삼각형, 우하단 삼각형 총 3개의 삼각형을 재귀적으로 호출해야한다.  
먼저 배열의 모든 값을 공백으로 하며, 행의 끝 부분만 null로 초기화한다. 별을 그릴 때는 삼각형 꼭대기부터 차례대로 그리기 때문에 star() 함수에 매개변수로 높이와 꼭대기 별의 좌표를 보내준다. 그리고 재귀 함수 속 기저조건으로는 높이가 3이 된 경우 별을 그리도록 한다.  
따라서 처음에는 높이를 n과 y,x 좌표로 (0,n-1)을 넘긴 다음 해당 삼각형을 그려주기 위해서  
```
  *
 * *
*****
```
별로 삼각형을 그려주며 위의 삼각형 높이와 맨 위 꼭대기 좌표로 재귀 1번, 좌하단의 삼각형의 높이와 맨 위 꼭대기 좌표로 재귀 1번, 우하단의 삼각형의 높이와 맨 위 곡대기 좌표로 재귀 1번. 총 3번의 재귀를 star() 함수에서 진행하며 해당 위치에서 높이가 3인 된 경우 출력을 한다.

---

- 3日  

## Vuepress [공식사이트](https://vuepress.vuejs.org/guide/)

### Quick Start
`yarn create vuepress [directoryName]`을 통해서 해당 원하는 디렉토리에서 vuepress을 생성한다.  

### Manual Setup
1) 새 디렉토리를 만들어서 그곳으로 이동한다.
`mkdir vuepress-starter && cd vuepress-starter`

2) 패키지 매니저를 초기화한다.
`yarn init # npm init`

3) VuePress을 설치한다.
`yarn add -D vuepress # npm install -D vuepress`

4) docs 경로를 만든 다음 README.md 마크다운을 만들어서 입력한다.
`mkdir docs && echo '# Hello VuePress' > docs/README.md`

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

---

- 4日  

이분탐색 알고리즘을 공부했다. 이분 탐색 알고리즘은 말 그대로 두 가지로 쪼개서 탐색한다는 것이다. 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘으로, 처음 중간의 값을 임의의 값으로 선택하여, 그 값과 찾고자 하는 값의 크고 작음을 비교하는 방식이다.  
이분 탐색 알고리즘을 얘기하면 같이 나오는 알고리즘이 있다. 바로 파라메트릭 탐색​이다.  

두 탐색의 공통점을 먼저 살펴보자  
- 정렬된 상태여야 한다
- 구간을 반절로 나누어 탐색

이분탐색
- 내가 찾고자 하는 답을 구함
- 답이 연속된 데이터에 들어있는지 확인 수단으로만 쓰임

파라메트릭 탐색
- 찾고자하는 답의 가능한 범위(min,Max)를 구함
- 어떤 조건을 적용해 최적화 문제를 결정 문제(참/거짓)로 바꾸어 푸는 알고리즘

파라메트릭 탐색 조건
- 최대값 M을 구하는 문제의 경우, M이 어떤 조건 c를 만족하면 M보다 작은 값도 모두 조건 c를 만족해야 함
- 최소값 m을 구하는 문제의 경우, m이 어떤 조건 c를 만족하면 m보다 큰 값도 모두 조건 c를 만족해야 함
- 이산적인 범위

문제는 대표적으로 2가지를 살펴볼 것이다.  

1. 합이 0인 네 정수 
배열 A B C D의 원소 합이 0이 되는 쌍의 개수 찾기
```
7453. 합이 0인 네 정수
for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			v.push_back(arr[2][i] + arr[3][j]);
		}
	}
	
	sort(v.begin(),v.end());
	
	
	long long ans = 0;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			long long ab = arr[0][i] + arr[1][j];
			
			long long first = lower_bound(v.begin(),v.end(), -ab) - v.begin();
			long long last = upper_bound(v.begin(),v.end(), -ab) - v.begin();
			
			if(v[first] == -ab) {
				ans += (last - first);
			}
		}
	}
```
O(n⁴)의 시간복잡도로 풀 수 없으니, 먼저 배열 4개를 2개로 줄인다. AB와 CD로 나누기 위해 벡터 하나를 가지고 CD을 합친다. 그 후 벡터를 정렬하고 AB배열의 합이 CD배열의 합의 음의 값과 같은 경우를 찾았다. 이 때, 같은 값을 가진 원소가 많을 수 있으므로 `lower_bound`와 `upper_bound`을 통해서 원소의 갯수를 다 찾았다.  

이 문제를 풀면서 가장 걸렸던 것은 시간이였다. 해당 문제의 제한 시간은 2초지만, 내가 알기로 산술연산이 1억번당 1초라고 알고 있었기 때문에 배열을 만들 때 쓰인 1600만번과 1600만 원소 정렬, lower_bound와 upper_bound로 인한 log₂(1600만) = 23.9xxx로 1억번당 1초로 계산하게되면 총 3.6초 정도 걸리게되므로 시간제한에 걸린다.  
하지만 해당 소스는 통과가 되므로 이 점이 가장 의아했다. 찾아본 결과 1억당 1초라는 얘기는 오래된 얘기이며, 해당 코드가 기계어 단위로 몇 개의 명령어로 환산되는지 알기 어렵고 캐시 미스 등 성능에 영향을 줄 수 있는 요소가 많다. 따라서 시간 복잡도는 점근적으로만 나타낼 뿐 정확한 연산의 개수를 구해주는 장치가 아니므로 참고사항일 뿐 정밀하게 시간을 계산할 수 없다. 라는 답변을 읽어볼 수 있었다.

2. 도토리 숨기기  
상자의 개수 N, 규칙의 개수 K, 도토리의 개수 D가 주어지고 규칙이 K만큼 주어지는데 규칙은 A상자 ~ B상자까지 C개 간격으로 도토리를 하나씩 넣는 규칙을 얘기한다.
```
15732. 도토리 숨기기
while (left <= right) {
		int mid = (left + right) / 2;
		
		long long sum = 0;
		for (int i=0; i<k; i++) {
			int high = min(v[i].first.second, mid);
			if(high >= v[i].first.first) {
				sum += ((high - v[i].first.first) / v[i].second) + 1;
			}
		}
		if(sum >= d) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
```
이 문제는 먼저 이분탐색이라는 것을 알 기 어려웠고, 조건을 무엇으로 할지가 가장 어려웠다. 왜냐하면 K개의 규칙 때문에 무엇을 잡아야하는지 상당히 혼동스러웠기 때문이다.  

상자번호를 기준으로 잡고 주어진 규칙의 B상자번호와 기준값을 비교해서 작은 값보다 A상자번호가 같거나 작은 경우에 해당 값과 A상자번호 값을 뺀 후 C개로 나누어준 뒤 0번째도 도토리를 넣으므로 1을 더해주게 된다. 이렇게 하면 해당 기준 값일 때의 i번째 규칙의 도토리 갯수를 셀 수 있게된다. 해당 도토리 갯수를 전부 다 더한 다음 주어진 도토리 갯수를 조건으로 둬서 이분탐색을 하면 된다.  

---

- 5日  

PS을 하면서 막힌 부분과 기억해야 하는 부분을 기록해볼 것이다.  

18119. 단어 암기  
처음에 모든 알파벳을 기억하고 있되, 밑의 연산에 따라서 잊거나 기억할 수 있다. 이 때의 주어진 단어를 몇 개 기억하는지 출력하라.
```
vector<bitset<26>> check;
vector<bitset<26>> copy_check;
if(cmd == 1) {
	for (int j=0; j<n; j++) {
		if(copy_check[j][x - 'a'] == true)
			check[j][x - 'a'] = false;
	}
}
	
else {
	for (int j=0; j<n; j++) {
		if(copy_check[j][x - 'a'] == true)
			check[j][x - 'a'] = true;
	}
}
	
for (int j=0; j<n; j++) {
	if(copy_check[j] == check[j]) cnt++;
}
cout << cnt << '\n';
```
bitset을 알파벳 수인 26개로 잡아놓고 문자열마다 해당 알파벳 부분을 true로 잡아놓은다. 그리고 그 bitset벡터를 복사한 뒤 연산에서 해당 알파벳이 나온다면 복사된 벡터에 존재한다면 그 알파벳을 true 혹은 false로 조정해준다. 이렇게 하여 bitset을 전체 비교해서 같은 카운트를 세준다.  

10830. 행렬 제곱  
최대 5x5 행렬을 최대 천억만큼 거듭 제곱한 결과를 구해야한다.  
```
vector<vector<ll>> power(vector<vector<ll>> mat, ll num) {
	vector<vector<ll>> ret(n, vector<ll>(n));
	for (int i=0; i<n; i++) {
		ret[i][i] = 1;
	} 
	
	while(num > 0) {
		if (num % 2) {
			ret = mul(ret, mat);
		}
		num /= 2;
		mat = mul(mat, mat);
	}
	return ret;
}
```
핵심 함수는 다음과 같다. 분할 정복의 거듭 제곱과 비슷하게 하되, 그것을 행렬로 하면 된다는 생각을 하였다. 따라서 단위행렬을 만들고 횟수가 홀수, 짝수를 나눠서 시도하되, 행렬의 곱을 만들어주기 위해 함수로 구현을 하였다. 행렬의 곱셈도 함수로 구현하여 답을 구했다.

---