# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록 후 웹에 정리
* 쓸데없는 Commit 지양
* markdown으로 작성
* 1일 1문제(PS, SQL)이상 해결
* 문제 풀고 Problem Solving 폴더에 모으기

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

- 6日  

이분 탐색 정리  

이분 탐색은 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이다. 처음 중간의 값을 임의의 값으로 선택하여, 그 값과 찾고자 하는 값의 크고 작음을 비교하는 방식을 채택하고 있다. 처음 선택한 중앙값이 만약 찾는 값보다 크면 그 값은 새로운 최고값이 되며, 작으면 그 값은 새로운 최하값이 된다. 검색 원리상 정렬된 리스트에만 사용할 수 있다는 단점이 있지만, 검색이 반복될 때마다 목표값을 찾을 확률은 두 배가 되므로 속도가 빠르다는 장점이 있다. 이분 탐색은 분할 정복 알고리즘의 한 예이다.

이분 탐색의 과정

1. 배열의 중간을 먼저 탐색한다.
2. 중간값이 탐색값이면 중단.
3. 중간값이 탐색값이 아니라면 중간값과 탐색값의 크기를 비교한다.
4. 중간값 > 탐색값 - 중간값의 오른쪽 인덱스들은 제외
5. 중간값 < 탐색값 - 중간값의 왼쪽 인덱스들은 제외

데이터가 정렬되어 있으면 위의 과정을 반복해서 절반씩 나눠서 걸러낸다.

STL algorithm에서 `upper_bound`와 `lower_bound`함수를 살펴보면 이분탐색을 기반으로 한 탐색 방법이다. 이분탐색이므로, 배열이나 리스트가 정렬이 되어 있어야 한다. `lower_bound`의 결과는 key값이 없으면 key값보다 큰 가장 작은 정수 값을 찾는다. 같은 원소가 여러 개 있어도 상관 없으며, 항상 유일한 해를 구할 수 있다. 예를 들어 `[begin, end]` 배열이 있을 때, 중간위치의 인덱스를 mid라고 하면 `arr[mid] < key` 이면서 `arr[mid] >= key`인 최소의 m 값을 찾으면 된다. `upper_bound`는 반대로 생각하면 된다.  

반환형은 Iterator이므로 vector를 사용하게 되면 벡터의 begin()을 빼게 되면 인자의 순서를 구할 수 있고, 배열이라면 첫 번쨰 주소를 빼면 인자의 순서를 알 수 있다.  

시간 복잡도는 O(log(last - first))으로, 전체 원소 개수에 로그에 비례한다.  

LCS 알고리즘

LCS는 두 가지로 나뉘어진다. 

`최장 공통 부분 문자열(Longest Common Substring)`과 `최장 공통 부분 수열(Longest Common Subsequence)` 두 가지로 나뉘는데 비슷하나 차이점이 뚜렷하다. 그 차이점은 해당 부분의 연속 여부이다. 아래 예시를 봐보자.  

A**BCD**FEF  A**BCD**F**EF**  
**BCD**EF	 **BCDEF**  

해당 두 개의 문자열이 있다고 가정해보자. 먼저, 최장 공통 부분 문자열의 경우에는 `BCD` 3개를 갖고, 최장 공통 부분 수열의 경우에는 `BCDEF` 5개를 갖게 된다.  

최장 공통 부분 문자열  
![LCS](https://wikimedia.org/api/rest_v1/media/math/render/svg/83ccdb67e41ba0b5043a8eb2a67ca0d7a6908ad2)


```
for (int i=1; i<=A.length; i++) {
	for (int j=1; j<=B.length; j++) {
		if(A[i-1] == B[j-1]) {
			LCS[i][j] = LCS[i-1][j-1]+1
			if(ans < LCS[i][j])
				ans = LCS[i][j]
		}
	}
}
```

최장 공통 부분 수열  
![LCS2](https://wikimedia.org/api/rest_v1/media/math/render/svg/a40feb09ada8db5fb1fb6fe0c31b2ee25b7c9835)  
X와 Y는 비교할 각 문자열, i와 j는 문자열의 각 인덱스이다. 구현에 있어 3가지가 필요하다.

1. 처음엔 편의를 위해서 빈 수열로 채워준다.  
          
|   | 0 | A | G | C | A | T |
|---|---|---|---|---|---|---|
| 0 | Ø | Ø | Ø | Ø | Ø | Ø |
| G | Ø |   |   |   |   |   |
| A | Ø |   |   |   |   |   |
| C | Ø |   |   |   |   |   |

2. X와 Y의 문자가 같은 경우이다. 이때 예시를 보자.  
```
stirng a = "ABCD"
string b = "AEBD"
LCS("ABCD", "AEBD") = 1 + LCS("ABC", "AEB")
```
`(ABCD와 AEBD의 길이) = (ABC, AEB를 비교했을 때의 길이 + 1)`

3. X와 Y의 문자가 다를 경우
```
LCS("ABC", "AEB") = MAX(LCS("AB", "AEB"), LCS("ABC", "AE"))
```
(AB, AEB 길이)와 (ABC,AE 길이) 중 큰 값을 (ABC, AEB 길이)에 대입한다.  

이러한 3가지를 코드로 나타내면
```
for(int i=1;i<=A.length;i++) { 
	for(int j=1;j<=B.length;j++) { 
		if (A[i-1] == B[j-1]) { 
			LCS[i][j] = LCS[i-1][j-1] + 1; 
		} 
		else { 
			LCS[i][j] = Math.max(LCS[i][j-1], LCS[i-1][j]); 
		}
	}
}
```

두 문자열의 각 문자를 비교하지 않고 선행 문자를 끼고 문자열로써 비교를 하는 것이다. 따라서 LCS 배열 마지막에는 LCS의 길이를 볼 수 있게 된다.  

추가적으로, LCS에 해당하는 부분 수열을 알고 싶다면 표로 생각해보자. LCS에서 DP와 같이 전의 값을 이용해서 값을 찾아낸다. 이 때 값이 변하는 구간은 항상 대각선으로 변하게 된다. 따라서, 대각선인 시점을 체크해서 그 전까지는 같은 수열을 갖다가 대각선 이후로 수열이 바뀌는 것을 볼 수 있다. 이것을 코드로 봐보자.

```
for (int i = 1; i <= A.length; i++) {
    for (int j = 1; j <= B.length; j++) {
        if (A[i - 1] == B[j - 1]) {
            LCS[i][j] = LCS[i - 1][j - 1] + 1;
            solution[i][j] = "diagonal";
        }
		else {
            LCS[i][j] = Math.max(LCS[i][j - 1], LCS[i - 1][j]);

            if (LCS[i][j] == LCS[i - 1][j]) 
                solution[i][j] = "top";
            else 
                solution[i][j] = "left";
            
        }
    }
}

int a = A.length;
int b = B.length;

while(solution[a][b] != null) {
    if (solution[a][b] == "diagonal") {
        sb.append(A[a-1]);
        a--;
        b--;
	}
    else if (solution[a][b] == "top") 
        a--;
    else if (solution[a][b] == "left") 
        b--;
}
sb.reverse.toString(); // 최장 공통 부분 수열 리스트
```

여기서 여러 개의 문자열을 비교할려면 배열을 늘려주자.

---

- 7日  

어제 공부하고 정리한 LCS을 토대로 LCS 문제를 풀어보았다.  

5582. 공통 부분 문자열
```
for (int i=1; i<=asize; i++) {
	for (int j=1; j<=bsize; j++) {
		if(a[i-1] == b[j-1]) {
			dp[i][j] = dp[i-1][j-1] + 1;
		}
		ans = max(ans,dp[i][j]);
	}
}
```
문자 하나하나를 비교하며 같은 경우 dp의 이전 대각선 방향의 값을 1을 더하는 연산을 반복해서 공통 부분 문자열의 갯수를 세주었다.  

15482. 한글 LCS  
```
#include <bits/stdc++.h>
using namespace std;

char str1[3027];
char str2[3027];
int board[1005][1005];

bool check(int i, int j) {
	if (str1[i * 3] == str2[j * 3] && str1[i * 3 + 1] == str2[j * 3 + 1] && str1[i * 3 + 2] == str2[j * 3 + 2]) return true;
	return false;
}

int main() {
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1) / 3;
	int len2 = strlen(str2) / 3;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (check(i - 1, j - 1)) board[i][j] = board[i - 1][j - 1] + 1;
			else board[i][j] = max(board[i - 1][j], board[i][j - 1]);
		}
	}
	printf("%d", board[len1][len2]);
	return 0;
}
```
이 문제의 경우에는 전체 소스를 보아야한다. 왜냐 하면 다른 소스를 참고했기 때문이다. 먼저 영문을 사용하듯이 LCS을 사용했는데 내 컴파일러 환경에서는 한글을 2byte로 세서 크기가 2배 정도 늘어나 있었다. 따라서 알고리즘을 다 돌린 후 마지막에 2를 나눠서 구하면 테스트 케이스 값이 전부 정확히 나와서 제출을 했으나 계속 오답이였다. 따라서 계속 해보다가 질문을 찾아보니 BOJ상에서는 유니코드로 3byte를 차지한다는 것을 알게되어 같은 코드에서 3배로 했으나 답이 계속 안 나와서 해당 질문자의 코드를 조금 고쳐서 사용해보았다. C로 짠 코드와 C++로 짠 코드에서 한글의 byte 차이가 나는지 궁금하다.  

9252. LCS 2, 1958 LCS 3  
```
for (int i=1; i<=n; i++) {
	for (int j=1; j<=m; j++) {
		if(a[i-1] == b[j-1])  {
			dp[i][j] = dp[i-1][j-1] + 1;
			LCS[i][j] += LCS[i-1][j-1] + a[i-1];
		}
		else  {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(dp[i][j] == dp[i-1][j])
				LCS[i][j] = LCS[i-1][j];
			else
				LCS[i][j] = LCS[i][j-1];
		}
	}
}
-------------------------------------------
for (int i=1; i<=asize; i++) {
	for (int j=1; j<=bsize; j++) {
		for (int k=1; k<=csize; k++) {
			if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
				dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
			else {
				dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
			}
		}
	}
}
```
LCS 2의 경우에는 LCS의 수열을 보여주는 것이고 LCS 3의 경우에는 문자열이 늘어났을 경우이다. 이 때 LCS의 수열을 보여주는 것은 어제 공부 했던거와 같이 할려했으나 코드를 작성 중에 포문 속에 같이 찾게 되면 시간을 더 줄일 수 있을 거 같아서 만약 찾게 되면 똑같이 대각선의 수열을 뒤에 붙이지만 찾지 못한 경우 해당 내용에서 DP 배열의 값을 비교해서 더 큰 쪽이 LCS가 진행 중이므로 해당 좌표의 LCS을 현재 좌표에 넣어주었다.  

문자열이 늘어난 LCS3의 경우에는 똑같이 삼중포문을 써서 배열 하나를 늘려, 다 같은 경우와 아닌 경우를 나눠서 똑같이 LCS의 수를 구해주었다.  

---  

- 8日  

## Express  

Node.js를 위한 빠르고 개방적인 간결한 웹 프레임워크  

```
$ npm install express-generator -g
```

해당 명령어를 통해 express을 설치할 수 있다. 이 때의 node.js가 설치되어 있다고 가정하고 진행하는 것이다.  

```
$ express --view=pug 디렉토리 이름
```

express 앱을 원하는 디렉토리로 작성한다.

```
npm install
> set DEBUG=디렉토리 이름:* & npm start
```
해당 디렉토리로 이동 후 npm을 설치하고 Debug 설정 후 npm start을 통해서 localhost:3000에 앱에 액세스할 수 있게 된다.  

### 라우팅  

라우팅이라는 개념이 등장하는데 이것은 URI 및 특정한 HTTP 요청 메소드인 특정 엔드포인트에 대한 클라이언트 요청에 애플리케이션이 응답하는 방법을 결정하는 것이다. 이 때 각 라우트는 하나 이상의 핸들러 함수를 가질 수 있으며, 라우트 경로가 일치할 때 실행이 된다. 라우트 경로는 문자열, 문자열 패턴 또는 정규식일 수 있다.

라우트의 구조  

```
app.METHOD(PATH, HANDLER)
```

- app : express의 인스턴스
- METHOD : HTTP 요청 메소드 (대표적으로 GET, POST, PUT, DELETE 등. 과 모든 요청 메소드를 뜻하는 `all`)
- PATH : 서버의 경로
- HANDLER : 라우트가 일치될 때 실행하는 함수

예시를 통해 이해해보자.
```
app.get('/', function (req, res) {
	res.send('Hello Wolrd!');
});
```
이 예시는 홈페이지에서 Hello World!로 응답하는 코드이다.  

이어서 봐보면
```
app.post('/', function(req, res) {
	res.send('Got a POST request');
});
```
애플리케이션의 루트 라우트(`'/'`)에서 POST 요청에 응답하는 코드이다.  

```
app.put('/user', function(req, res) {
	res.send('Got a PUT request at /user');
});
```
마찬 가지로 /user 라우트에 대한 PUT 요청의 응답이다.

```
app.delete('/user', fucntion (req, res) {
	res.send('Got a DELETE request at /user');
});
```
마지막으로 같은 예제로 /user 라우트에 대한 DELETE 요청에 응답하는 코드이다.  

라우트 핸들러  

라우트 경로가 일치될 때 실행되는 함수로 미들웨어와 비슷하게 작동하는 여러 콜백 함수를 제공하여 요청을 처리할 수 있다. 차이점은 `next('route')`을 호출하여 나머지 라우트 콜백을 우회할 수 있다. 이것은 라우트에 대한 조건을 지정 후, 현재의 라우트를 계속할 필요 없을 경우 후속 라우트에 제어를 전달할 수 있다.  

예시와 함께 설명을 보자.  
```
app.get('/example/a, function(req, res) {
	res.send('Hello from A!');
});
```
하나의 콜백 함수는 하나의 라우트를 처리할 수 있다.  

```
app.get('/example/b', function (req, res, next) {
  console.log('the response will be sent by the next function ...');
  next();
}, function (req, res) {
  res.send('Hello from B!');
});
```
2개 이상의 콜백 함수도 하나의 라우트로 처리할 수 있다. 이 때 무조건 `next` 오브젝트를 지정해주어야 한다.

```
var cb0 = function (req, res, next) {
  console.log('CB0');
  next();
}

var cb1 = function (req, res, next) {
  console.log('CB1');
  next();
}

var cb2 = function (req, res) {
  res.send('Hello from C!');
}

app.get('/example/c', [cb0, cb1, cb2]);
```

하나의 콜백 함수 배열은 하나의 라우트를 처리할 수 있다. 따라서 경로를 지정해준 뒤 배열로 핸들러를 지정해줄 수 있다.

```
var cb0 = function (req, res, next) {
  console.log('CB0');
  next();
}

var cb1 = function (req, res, next) {
  console.log('CB1');
  next();
}

app.get('/example/d', [cb0, cb1], function (req, res, next) {
  console.log('the response will be sent by the next function ...');
  next();
}, function (req, res) {
  res.send('Hello from D!');
});
```
위에서 이야기한 내용들을 섞어서도 가능하다. 무슨 말이냐면, 독립적인 함수와 함수 배열의 조합으로 하나의 라우트를 처리할 수 있다.

응답 메소드
응답 오브젝트(`res`)에 대한 메소드는 응답을 클라이언트로 전송하고 요청-응답 주기를 종료할 수 있다. 따라서 라우트 핸들러에서 해당 메소드 중 하나도 호출되지 않는다면 클아이언트 요청은 정지된채로 방치되게 된다.
| 메소드 | 설명 |
|-------|-------|
| res.download() | 파일이 다운로드 되도록 프롬프트 |
| res.end() | 응답 프로세스를 종료 |
| res.json() | JSON 응답을 전송 |
| res.jsonp() | JSNOP 지원을 통해 JSON 응답 전송 |
| res.redirect() | 요청의 경로를 재지정 |
| res.render() | 보기 템플릿을 렌더링 |
| res.send() | 다양한 유형의 응답 전송 |
| res.sendFile | 파일을 옥텟 스트림의 형태로 전송 |
| res.sendStatus() | 응답 상태 코드를 설정 후 해당 코드를 문자열로 표현한 내용을 응답 본문 전송 |

**app.route()**  

라우트 경로에 대하여 체인 가능한 라우트 핸들러를 작성할 수 있다. 경로가 같으므로 모듈식 라우틀르 작성하면 가독성이 증가하며 편리하게 코딩을 할 수 있다.
```
app.route('/book')
	.get(function(req, res) {
		res.send('Get a random book');
	})
	.post(function(req, res) {
		res.send('Add a book');
	})
	.put(function(req, res) {
		res.send('Update the book');
	});
```

**express.Router**

`app.route()`와 비슷하게 `express.Router` 클래스를 사용하여 모듈식 마운팅 가능한 핸들러를 작성할 수 있다. Router 인스턴스는 완전한 미들웨어이자, 라우팅 시스템으로 미니 앱(mini-app)이라고 불리기도 한다.  

```
// bird.js

var express = require('express');
var router = express.Router();

// middleware that is specific to this router
router.use(function timeLog(req, res, next) {
  console.log('Time: ', Date.now());
  next();
});

// define the home page route
router.get('/', function(req, res) {
  res.send('Birds home page');
});

// define the about route
router.get('/about', function(req, res) {
  res.send('About birds');
});

module.exports = router;

// app.js
var birds = require('./birds');
...
app.use('/birds', birds);
```
이러하게 라우터를 모듈로 작성하고, 미들웨어 함수를 로드하고 다른 라우트들을 정의한 뒤 기본 앱의 한 경로에 라우터 모듈을 마운트한다. 그 뒤 앱 내에서 라우터 모듈을 로드 하게 되면 라우터에서 정의해놓은 라우트들의 요청을 처리할 수 있으며, 미들웨어 함수를 호출할 수 있게 된다.  



### 정적 파일 이용

이미지나, CSS 파일 및 JavaScript와 같은 정적 파일을 제공하려면 Express의 기본 제공 미들웨어 함수인 `express static`을 이용하여야 한다.  

정적 자산이 포함된 디렉토리의 이름을 `express.static` 미들웨어 함수에 전닳하면 파일의 직접적인 제공이 가능하다.  

```
app.use(express.static('public'));
```
위와 같은 코드를 이용하면 public 디렉토리에 있는 정적 파일을 제공할 수 있다.  
따라서 다음과 같이 접근을 하게되면 해당 정적 파일을 그대로 접근할 수 있게 된다.
```
localhost:3000/img/cat.jpg
localhost:3000/css/style.css
localhost:3000/js/app.js
localhost:3000/index.html
```

여러 개의 디렉토리를 정적 파일이 있는 디렉토리로 등록을 할 수 있는데 해당 문법을 그대로 사용하면 된다.
```
app.use(express.static('public'))
app.use(express.static('files'))
```

이렇게 사용하면 되나, `express.static`을 설정한 순서대로 파일을 검색한다. 따라서 같은 이름의 파일이 존재한다면 먼저 설정한 파일을 찾는다는 말이 된다.  

또, 정적 파일을 접근 시에 가상 경로를 만들어서 파일에 접근하게 하고 싶다면 위와 같은 문법을 사용하면 된다.  
```
app.use('/static', express.static('public'));
```

```
localhost:3000/static/img/cat.jpg
localhost:3000/static/css/style.css
localhost:3000/static/js/app.js
localhost:3000/static/index.html
```

`express.static` 함수에 제공되는 경로는 node 프로세스가 실행되는 디렉토리에 상대적이므로 다른 디렉토리에서 express 앱을 실행하는 경우에는 절대 경로로 주어지는 것이 안정성을 높일 수 있다.

### 미들웨어  

미들웨어함수는 요청 오브젝트(`req`), 응답 오브젝트(`res`), 그리고 애플레키에션의 요청-응답 주기 중 그 다음의 미들웨어 함수에 대한 액세스 권한을 갖는 함수이다. 미들웨어 함수는 일반적으로 `next`라는 이름의 변수로 표시된다.  

- 모든 코드를 실행
- 요청 및 응답 오브젝트에 대한 변경을 실행
- 요청-응답 주기를 종료
- 스택 내의 그 다음 미들웨어를 호출

미들웨어 함수는 이러한 작업을 수행할 수 있다.

현재의 미들웨어 함수가 요청-응답 주기를 종료하지 않았다면 `next()`을 호출하여 그 다음 미들웨어 함수에 제어를 전달해야한다. 그렇지 않으면 해당 요청은 정지된 채 방치된다.  

![Express 폼](https://expressjs.com/images/express-mw.png)  
express 공식홈페이지의 사진 설명  

사진을 통해서 미들웨어 함수 호출의 요소에 대해 알아 볼 수 있다.
- `get` : HTTP 메소드
- `'/'` : 라우트
- `function` : 함수
- `req` : HTTP 요청 인수
- `res` : HTTP 응답 인수
- `next` : 콜백 인수

예시로 두 개의 미들함수를 정의한 간단한 코드를 살펴보자.
```
var express = require('express');
var app = express();

app.get('/', function (req, res) {
  res.send('Hello World!');
});

app.listen(3000);
```
루트 경로의 GET 요청을 받고 응답을 `Hello World!`로 보내는 함수를 정의했다.  

미들웨어함수를 정의하고 사용하는 방법을 짧게 예제를 통해 봐보자

```
var express = require('express');
var app = express();

var myLogger = function (req, res, next) {
  console.log('LOGGED');
  next();
};

app.use(myLogger);

app.get('/', function (req, res) {
  res.send('Hello World!');
});

app.listen(3000);
```
이렇게 짜게되면 앱이 요청을 수신할 때마다 "LOGGED"라는 메세지를 터미널에 출력하게 된다. 이때의 미들웨어의 로드 순서는 중요하며, 먼저 로드된 순서대로 실행이 되게된다. 만약 루트 경로에 대한 라우팅 이후에 `MyLogger`가 로드되면, 루트 경로의 라우트 핸들러가 요청-응답 주기를 종료하므로 `MyLogger`에 닿지 못해서 실행이 될 일이 없게 된다.  
그와 달리 `MyLogger` 미들웨어 함수는 메시지를 출력 후 `next()` 함수를 호출하여 스택 내의 그 다음 미들웨어 함수에게 요청을 전달한다. 따라서 루트 경로에 라우팅을 할 수 있게 된다.  

그러므로 라우트를 정의하고 사용할 때에 순서를 유념하고 사용해야 원하는 개발을 할 수 있을 것이다.

마지막으로 여러 유형의 미들웨어를 살펴본다.

- 애플리케이션 레벨 미들웨어
- 라우터 레벨 미들웨어
- 오류 처리 미들웨어
- 기본 제공 미들웨어
- 써드파티 미들웨어

이러한 종류가 존재하나, 위의 3가지 미들웨어를 살펴볼 것이다. 개발할 때 직접적으로 사용했던 미들웨어이였기 때문이다.  

애플리케이션 레벨 미들웨어  

`app.use()`나 `app.METHOD()` 함수를 이용할 수 있는 애플리케이션 레벨에 존재하는 미들웨어를 뜻하며, 이 미들웨어 함수는 일련의 미들웨어 함수를 함께 로드 할 수 있으며, 하나의 마운트 위치에 미들웨어 시스템의 하위 스택을 작성할 수 있다.  

예제로 살펴보자.  
```
var app = express();

app.use(function (req, res, next) {
  console.log('Time:', Date.now());
  next();
});
```
지금까지 자주 보았던 미들웨어로, 마운트 경로가 없는 미들웨어 함수이다. 이 함수는 앱이 요청을 수신할 때마다 실행하게 된다.  

```
app.use('/user/:id', function (req, res, next) {
  console.log('Request Type:', req.method);
  next();
});
```
이 예시는 `/user/:id` 경로에 마운트 되는 미들웨어 함수이다. 이 함수는 모든 유형의 HTTP 요청에 대해 실행이 된다.

```
app.get('/user/:id', function (req, res, next) {
  res.send('USER');
});
```
라우트 및 해당 라우트의 핸들러 함수로, `/user/:id`경로의 GET 요청을 처리한다.

```
app.use('/user/:id', function(req, res, next) {
  console.log('Request URL:', req.originalUrl);
  next();
}, function (req, res, next) {
  console.log('Request Type:', req.method);
  next();
});
```
라우터 핸들러를 이용하면 하나의 경로에 대해 여러 라우트를 정의할 수 있다. 해당 /user/:id 경로에 대한 GET 요청에 대해 2개의 라우트를 정의하나, 첫 번째 라우트가 요청-응답 주기를 종료시키므로 두 번째 라우트는 호출되지 않는다.

```
app.get('/user/:id', function (req, res, next) {
  console.log('ID:', req.params.id);
  next();
}, function (req, res, next) {
  res.send('User Info');
});

// handler for the /user/:id path, which prints the user ID
app.get('/user/:id', function (req, res, next) {
  res.end(req.params.id);
});
```
경로에 대한 GET 요청을 처리하는 미들웨어 하위 스택을 표시하는 예제로, 라우터 미들웨어 스택의 나머지 미들웨어 함수들을 건너뛰려면 `next('route')`을 호출하여 제어를 그 다음 라우트로 전달해야한다. 이 때 `next('route')`는 app.METHOD()나 router.METHOD() 함수를 이용해 로드된 미들웨어 함수에서만 작동된다.  

```
app.get('/user/:id', function (req, res, next) {
  // if the user ID is 0, skip to the next route
  if (req.params.id == 0) next('route');
  // otherwise pass the control to the next middleware function in this stack
  else next(); //
}, function (req, res, next) {
  // render a regular page
  res.render('regular');
});

// handler for the /user/:id path, which renders a special page
app.get('/user/:id', function (req, res, next) {
  res.render('special');
});
```
마지막으로 미들웨어 하위 스택으로 넘어가는 예제를 보여주며 이러한 코딩도 가능하다는 것을 보여준다.

### 라우터 레벨 미들웨어
라우터 레벨 미들웨어는 `express.Router()` 인스턴스에 바인드된다는 점을 제외하면 애플레키에션 레벨 미들웨어와 동일한 방식으로 작동한다.
```
var app = express();
var router = express.Router();

// a middleware function with no mount path. This code is executed for every request to the router
router.use(function (req, res, next) {
  console.log('Time:', Date.now());
  next();
});

// a middleware sub-stack shows request info for any type of HTTP request to the /user/:id path
router.use('/user/:id', function(req, res, next) {
  console.log('Request URL:', req.originalUrl);
  next();
}, function (req, res, next) {
  console.log('Request Type:', req.method);
  next();
});

// a middleware sub-stack that handles GET requests to the /user/:id path
router.get('/user/:id', function (req, res, next) {
  // if the user ID is 0, skip to the next router
  if (req.params.id == 0) next('route');
  // otherwise pass control to the next middleware function in this stack
  else next(); //
}, function (req, res, next) {
  // render a regular page
  res.render('regular');
});

// handler for the /user/:id path, which renders a special page
router.get('/user/:id', function (req, res, next) {
  console.log(req.params.id);
  res.render('special');
});

// mount the router on the app
app.use('/', router);
```
지금까지의 애플리케이션 레벨 미들웨어에서 사용된 함수들을 router 레벨에서 돌릴 수 있게 변경한 예제이다. 그리고 마지막에 app이 존재하는 app.js와 같은 파일에서 `app.use('path', router)`을 명시해서 마운트를 해줘야한다.  

### 오류 처리 미들웨어
다른 미들웨어 함수와 동일한 방법으로 정의할 수 있지만 오류 처리 함수는 인수를 3개가 아닌 4개(err, req, res, next)를 가지므로 분류가 새롭게 된다고 생각하면 된다.
```
app.use(function(err, req, res, next) {
  console.error(err.stack);
  res.status(500).send('Something broke!');
});
```

---

- 9日  

## LIS
LIS(Longest Increasing Subsequence) : 최장 증가 부분 수열  

수열 하나가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구할 때 3가지 방법이 있다.

- 완전 탐색을 이용한 방법(O(2ⁿ))
- DP를 이용한 방법 (O(n²))
- 이진 탐색을 이용한 방법 (O(n logn))

### 완전탐색을 이용한 방법
완전 탐색의 경우에는 하나하나 다 비교해보면 되므로 모든 증가 부분수열을 고려한다. 배열을 받아서 원 배열에서 증가 부분 수열의 첫번째 수를 선택한 뒤, 다음 수의 조건(첫 수보다 원 배열에서 뒤에 있고 큰 후보)에 해당하는 값들의 배열을 꾸려 재귀를 해나가면 될 것 같다.  

어떤 수가 나올지는 상관없이 자신보다 작은 숫자인지 확인하고 이전 값에서 1을 계속 더해가면 해당 LCS의 길이를 구할 수 있다.

### DP를 이용한 방법
DP를 이용한 방법은 아래와 같이 알고리즘을 짜볼 수 있다.  
1. 수열의 길이와 같은 dp배열을 하나 선언한다. 

2. 수열을 처음부터 끝까지 순서대로 1개씩 탐색한다. ( 현재 위치 = i )
  	1. dp[i]에 넣을 값을 초기화해준다. (val)

  	2. 현재 위치(i)보다 이전에 있는 원소(j) 중에서 현재 원소보다 작은지 체크한다. (크거나 같으면 LIS 불가능)

  	3. 현재 원소보다 작다면, dp[j]가 val 보다 큰지 체크한다. 이 때 val보다 크다면 j번째 원소를 포함했을 때가, 지금까지 확인한 최장 증가 부분 수열보다 더 길다는 의미이므로 val에 dp[j]를 할당해준다. 

  	4. 현재 원소도 포함해주어야 하므로 최종적으로 dp[i]에 val + 1을 할당해준다.
3. dp배열의 원소 중에서 가장 큰 값을 출력한다.  

```
for(int i=1;i<N;i++) {
	for(int j=0;j<i;j++) { 
		if (array[i] > array[j] && dp[j] + 1 > dp[i])
			 dp[i] = dp[j] + 1; // 증가 수열
	}
	if (max < dp[i])
		max = dp[i]; 
	
}
```
처음에 dp 배열의 값들을 1로 초기화 해주어야하며, if문의 조건에 `dp[j] + 1 > dp[i]`가 들어간 이유는 예를 들어서 10 20 30 20 인 경우 값이 20을 만나게 되면 값이 줄어드는 것을 볼 수 있다. 이 부분을 보장해주기 위해 해당 조건을 추가한 것이다.  

### 이진 탐색을 이용한 방법

해당 부분은 잘 정리된 블로그 포스팅을 참고해서 썼다.

- 배열 마지막 요소보다 새로운 수가 크다면, 배열에 넣는다.
- 그렇지 않다면, 그 수가 들어갈 자리에 넣는다. (이분 탐색을 통해 들어갈 자리를 찾는다)

LIS의 갯수만 구할 때의 가장 이해하기 쉬운 코드를 찾아보았다.  
```
dp[0] = array[0];
int idx = 0;
for (int i = 1; i < n; i++) {
	if (dp[idx] < array[i]) { 
		dp[++idx] = array[i]; 
	}
	else {
		int ii = lower_bound(array.begin(), array.end(), idx);
		dp[ii] = array[i];
	} 
}
// ans => idx + 1
```

혹은 이런 방식으로 짧게 구현하는 방법도 있다
```
for (int i=0; i<n; i++) {
	vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), arr[i]);
	if(iter == dp.end()) dp.push_back(arr[i]);
	else *iter = arr[i];
}
cout << dp.size();
```
`lower_bound`을 통해서 못 찾으면 push_back, 찾으면 해당 값을 배열의 값으로 치환해준다.  

![LIS 이진탐색 그림](https://t1.daumcdn.net/cfile/tistory/993FE1405AADFAF70F)  

위 그림을 통해서 소스의 전체적인 느낌을 파악한 뒤 다른 문제에서 요하는 경로 추적 또한 코드로 보았다.  

```
dp[0] = array[0];
tracking[0] = new Pair(0, array[0]);
int idx = 0;
for (int i = 1; i < n; i++) { 
	if (dp[idx] < array[i]) { 
		dp[++idx] = array[i];
		tracking[i] = new Pair(idx, array[i]);
	}
	else { 
		int ii = lower_bound(idx, array[i]);
		dp[ii] = array[i];
		tracking[i] = new Pair(ii, array[i]);
	}
}
```
이후에는 스택에서 인덱스와 pair의 first을 비교하여 스택에 넣어준 다음 꺼내주게 되면 순서대로 출력할 수 있다.

```
lis.push_back(v[0]);
p.push_back({0, v[0]});

for (int i=1; i<n; i++) {
	int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
	if(idx >= lis.size())  {
		lis.push_back(v[i]);
	}
	else {
		lis[idx] = v[i];
	}
	p.push_back({idx, v[i]});
}
stack<int> st;
int len = lis.size();
cout << len << '\n';
for (int i=n-1; i>=0; i--) {
	if (p[i].first == len-1) {
		st.push(p[i].second);
		len--;
	}
}
while(!st.empty()) {
	cout << st.top() << ' ';
	st.pop();
}
```
나는 이런 식으로 만들어서 pair로 추적하는 아이디어를 집어 넣어서 구현하였다.

[그림 및 소스 출처](https://mygumi.tistory.com/303)  

---

- 10日  

Express  
## Template Engine  

HTML code를 최소화시키도록 도와주는 도구로, 정적인 파일과 동적인 파일의 장단점을 결합시켰다. 따라서 정적인 파일만을 서비스한다면 사용할 필요가 없다. 동적인 결과를 정적인 파일에 담기 위해 사용한다. 즉, 자바스크립트 코드로 연산된 결과를 변수에 넣은 뒤 뷰 파일에서 사용하도록 한다.  

클라이언트 요청에 따라 웹 문서에 들어가는 내용이 달라질 수 있으므로 정적인 부분과 동적인 부분을 나누기 위해서 사용한다. 이 때 `app.js` 내 HTML 코드를 쓰지 않아도 되며 뷰 파일과 자바스크립트 코드를 따로 사용할 수 있다.

클라이언트 측 브라우저는 HTML 템플릿, JSON / XML 데이터 및 템플릿 엔진 라이브러리를 서버에서 로드합니다.   

템플릿 엔진은 클라이언트의 브라우저에서 템플릿과 데이터를 사용하여 최종 HTML을 생성합니다. 그러나 일부 HTML 템플릿은 데이터를 처리하고 서버 측에서 최종 HTML 페이지를 생성합니다.  

## 종류
크게 두 가지로 나눈다.  
1. pug(jade)
2. ejs

차이점을 보면 ejs는 기본 html 문법을 그대로 사용하며, 협업할 때 ejs, 개인이 개발을 할 때는 pug을 추천한다. 두 템플릿엔진 둘 다 엔진을 통해서 html 문법으로 변환 시켜준다.  

여기서는 pug을 주로 볼려고 한다.

## pug의 장점

- HTML을 간단히 표현. 가독성이 좋다
- 마크업 문법보다 코드량이 적어 생산량이 좋다
- JS 연산 결과를 쉽게 보여줌
- 정적인 부분과 동적인 부분 나눌 수 있다

## pug의 특징

- 마크업과 달리 닫는 태그가 없다
- 들여쓰기로 종속성 구별
- 태그 선언시 태그 이름만 쓴다
- ID와 CLASS 선언시 CSS 선택자 사용
- 태그 없이 ID나 CLASS 선언시 자동으로 div 태그 사용
- 태그에 속성 줄 땐 괄호 사용
- 여러줄 사용시에 `|` 사용
- script나 CSS로 태그 사용시 끝에 `.` 입력
- 템플릿 속에서 Javascript 사용시 앞에 `-` 입력

## 설치

`npm install pug --save`  

터미널에서 해당 명령어 입력 시 `package.json`에 dependencies에 추가된다.  

## 예시

```
var express = require('express');
var app = express();

app.set('view engine', 'pug'); // 사용할 템플릿 엔진 설정
app.set('views', './views'); // 템플릿이 있는 폴더 지정 (지정 안한 경우 default로 views가 설정된다)
app.use(express.static('public')) //정적 경로 지정
app.get('/주소' function(req, res) => {
	res.render('pug파일 이름');
})
```

## 문법
### **기본 문법**

```
html
	head
	body
		h1 Hello Pug
```

```
idx.pug:
html
	head
		title= title
	body
		h1= message

app.js:
app.get('/', function (req,res) => {
	res.render('idx', { title: 'Hey', message: 'Hello there!'});
});
```
들여쓰기로 상위태그 안에 종속하게 할 수 있다.
```
<html>
	<head></head>
	<body>
		<h1>Hello Pug</h1>
	</body>
</html>
```

조금 더 심화해서 변수를 이용해보자
```
idx.pug:
html
	head
		title #{_title}
	body
		h1 Hello Pug
		ul
			-for(let i=0; i<5; i++)
				li Hello
		div #{time}

app.js:
app.get('/', (req,res) => {
	res.render('idx', {time:Date(), _title:'Pug'});
})
```

### 문법 요약
HTML5
```
doctype html   		→   <!DOCTYPE html>
```
**Block 생성**
```
p foo 		  		 →   <p>foo</p>
```
**속성**
- 단일 속성
```
a (href='	') Google  →  <a href="	">Google</a>
```
- 다중 속성
```
input(
	type='checkbox'
	name='agreement'
	checked
)
```
```
<input type="checkbox" name="agreement" checked="checked">
```

조건문
- **if문**
```
- var user = { description: 'foo bar baz' }
- var authorised = false
#user
	if user.description
		h2.green Description
		p.description= user.description
	else if authrised
		h2.blue Description
		p.description.
			User has no description,
			why not add one...
	else
		h2.red Description
		p.description
```
```
<div id="user">
	<h2 class="green">Description</h2>
	<p class="description>foo bar baz</p>
</div>
```
- **unless문**
if와 반대로 실행
```
unless user.isAnonymous
	p You're logged in as #{user.name}
```
```
if !user.isAnonymous
	p You're logged in as #{user.name}
```
둘 다 같은 html로 변환되게 된다.  

**Case 조건문**  
```
- var friends = 10   // JS코드는 - 입력
case friends
	when 0
		p you have no friends
	when 1
		p you have a friend
	default
		p you have #{friends} friends
```
```
<p>you have 10 friends</p>
```

**OR문과 Break**  
- OR문은 `when` 밑줄에 다시 `when` 조건
- Break는 `- Break` 입력

```
- var friends = 0
case friends
	when 0
	when 1
		p you have very few friends
		- break
	default
		p you have #{friends} friends
```
```
<p>you have very few friends</p>
```

**Element 조건문**
```
- var friends = 1
case friends
	when 0: p you have no friends
	when 1: p you have a friend
	deafult: p you have #{friends} friends
```
```
<p>you have a friends</p>
```

**반복문**
- for문
```
- for (let x=0; x<3; x++)
	li item
```
```
<li>item</li>
<li>item</li>
<li>item</li>
```
- each문
```
-
	var list = ["one", "two", "three", "four"]
each item in list
	li= item
```
```
<li>one</li>
<li>two</li>
<li>three</li>
<li>four</li>
```

*마크업 코드를 내용물 그대로 표시*  
예시
```
p
	= 'This code is <escaped>!'
```
```
<p>This code is &lit;escaped&gt;!</p>
```
이 때는 `=` -> `!=`으로 고치면 마크업 코드 그대로 사용가능하다.  

```
p
	!= 'This code is <strong>not</strong> escaped!'
```
```
<p>This code is <strong>not</strong> escaped!</p>
```

**Mixin 변수**  
템플릿 단위로 재사용 가능한 변수로, 규칙은 `+{변수 이름}`
```
// 선언
mixin list
	ul
		li foo
		li bar
		li baz

// 사용
+list
+list
```
```
<ul>
	<li>foo</li>
	<li>bar</li>
	<li>baz</li>
</ul>
<ul>
	<li>foo</li>
	<li>bar</li>
	<li>baz</li>
</ul>
```

**includes(템플릿 파일 포함)**  
규칙 : include{파일 경로}
```
html
	include includes/head.pug
	body
		h1 My Site
```

예시
```
doctype html
html
	title My Blog
	body
		include includes/header.pug // 헤더
		p#main Welcome to my blog. // 헤더와 푸터 사이 내용
		include includes/footer.pug // 푸터
```

[예시 참고](https://iseongho.github.io/posts/node-template-engine-pug/)  

---

- 11日  

# Express DB사용  

- MySQL
```js
npm install mysql
```
```js
var mysql      = require('mysql');
var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'dbuser',
  password : 's3kreee7'
});

connection.connect();

connection.query('SELECT 1 + 1 AS solution', function(err, rows, fields) {
  if (err) throw err;
  console.log('The solution is: ', rows[0].solution);
});

connection.end();
```
- MongoDB
```js
npm install mongodb
```
```js
var MongoClient = require('mongodb').MongoClient;

MongoClient.connect('mongodb://localhost:27017/animals', function(err, db) {
  if (err) {
    throw err;
  }
  db.collection('mammals').find().toArray(function(err, result) {
    if (err) {
      throw err;
    }
    console.log(result);
  });
});
```
- PostgreSQL
```js
npm install pg-promise
```
```js
var pgp = require("pg-promise")(/*options*/);
var db = pgp("postgres://username:password@host:port/database");

db.one("SELECT $1 AS value", 123)
    .then(function (data) {
        console.log("DATA:", data.value);
    })
    .catch(function (error) {
        console.log("ERROR:", error);
    });
```
- SQLite
```js
npm install sqlite3
```
```js
var sqlite3 = require('sqlite3').verbose();
var db = new sqlite3.Database(':memory:');

db.serialize(function() {

  db.run('CREATE TABLE lorem (info TEXT)');
  var stmt = db.prepare('INSERT INTO lorem VALUES (?)');

  for (var i = 0; i < 10; i++) {
    stmt.run('Ipsum ' + i);
  }

  stmt.finalize();

  db.each('SELECT rowid AS id, info FROM lorem', function(err, row) {
    console.log(row.id + ': ' + row.info);
  });
});

db.close();
```

# ORM (Sequelize)
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

# Logger API : Morgan
## 설치

```js
$ npm install morgan
```

## 사용

```js
var logger = require('morgan');
...
app.use(logger(":remote-addr"), function(req, res, next){
  next();
});
 
app.use(logger(":method"), function(req, res, next){
  next();
});
 
app.use(logger(":url"), function(req, res, next){
  next();
});
 
app.use(logger(":date"), function(req, res, next){
  next();
});
 
app.use(logger(":status"), function(req, res, next){
  next();
});
...
```

## 토큰
| Token | Content |
|---|---|
| :req[header] | request의 특정 HTTP |
| :res[header] |	response의 특정 HTTP |
| :http-version | HTTP version |
| :response-time | 응답시간 |
| :remote-addr | 사용자의 IP |주소
 :date | request 날짜/시간| 
| :method | request에 대한  HTTP method |
| :url | 요청된 URL |
| :referrer | 현재 URL을 참고하는 URL |
|:user-agent | User-agent 서명 |
| :status | HTTP 상태 |

## 로그 파일로 저장
'default', 'short', 'tiny', 'dev' 4가지 포맷을 지원한다.
```js
...
var fs = require('fs');
...
app.use(logger({
  format: 'dev',
  stream: fs.createWriteStream('app.log', {'flags': 'w'})
}));
...
```
이 때 `app.log`는 이름일뿐 수정 가능하며 저장 위치는 Express 앱의 root이다.

# CORS (Cross Origin Resource Sharing)

## 이슈

이번 프로젝트를 예로 들면 FE단의 vue.js에서는 localhost:8080 즉, localhost의 8080의 포트를 사용하고 BE단의 express.js에서는 localhost:3000으로 3000 포트를 사용한다. 이 때  서로 다른 port를 listen 중에  FE단에서 BE단으로 ajax 요청을 보낼려고 하면 Cross Domain 이슈가 일어나게 된다.

CORS 사용하지 않은 상황에서 Cross Domain 오류 메시지

```js
XMLHttpRequest cannot load http://xx.xx.xx.xx/xxx.
Request header field Content-Type is not allowed by Access-Control-Allow-Headers. 
```

## 설치

```jsx
npm install cors
```

## 사용

**1. 모든 도메인 요청 활성화(모든 작업 CORS 허용 테스트용)**

```jsx
var express = require('express')
var app = express();
var cors = require('cors')

app.use(cors());
```

**2. 싱글 라우트에 대한 도메인 활성화(특정 작업에 대해서만 CORS허용)**

```jsx
var express = require('express');
var app = express();
var cors = require('cors');
// ***********  products/:id 에 대한 url 라우팅시에만  cors 를 허용 
app.get('/products/:id', cors(), function(req,res,next) {
res.json({msg:'This is CORS-enabled for a single Route'});
})
```

**3. CORS Config settings(setting 값을 수정하여서 CORS 허용 IP지정)**

```jsx
var express = require('express');
var app = express();
var corsOptions = {
	origin :'http://example.com',
	optionsSuccessStatus:200; // IE 11이나 여러 스마트 TV들에 대한 확인 
};

app.get('/products/:id',cors(corsOptions),function(req,res,next){
res.json({msg:' This is CORS-enabled for only example.com.'});
});
```

**4. CORS Dynamic Origin 동적으로 읽어서 사용**

whitelist 배열을 push 로 추가하여서 실시간으로 허용 및 제거 가능

```jsx
var express = require('express');
var app = express();
var whitelist = ['http://example1.com','http://example2.com']
var corsOptions = {
	origin: function(origin,callback)    {
		if(whitelist.indexOf(origin) !==-1){
			callback (null,true);
		} 
		else{
			callback (new Error('Not allowed by CORS'))
		}
	}
}
app.get('/products/:id', cors(corsOptions),function(req,res,next){
res.json({msg: 'This is CORS-enabled for a whitelisted domain.'})
});
```

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

# body-parser

post로 요청된 body를 쉽게 추출할 수 있는 모듈이다. 추출된 결과는 request객체(IncomingMessage 타입)에 body 속성으로 저장된다. Magicsora에서는 URL-encoded form body parser만 사용한다.

## 내장모듈와 다른점

http모듈로만 post body를 파싱하려면,

```jsx
req.on('data', function(chunk) { body += chunk; }); 
```

와 같이 이벤트를 등록해야한다. 그다음에 인코딩처리를 해줘야한다.

body-parser를 쓰면 좀 더 수월하다는 것을 볼 수 있다.

```jsx
bodyParser.urlencoded()
```

자동으로 req에 body속성이 추가되고 저장된다. 만약 urls에 접근하고싶다면, req.body.urls이다. 인코딩도 default로 UTF-8로 해준다.

## urlencoded()의 옵션

만약 아무 옵션을 주지 않는다면, body-parser deprecated undefined extended: provide extended option 같은 문구가 뜬다.

```jsx
.use(bodyParser.urlencoded({ extended: true or false })); 
```

extended 는 중첩된 객체표현을 허용할지 말지를 정하는 것이다. 객체 안에 객체를 파싱할 수 있게하려면 true.

### extended 옵션에 대해

- 참조문서 : [https://stackoverflow.com/questions/29960764/what-does-extended-mean-in-express-4-0/45690436#45690436](https://stackoverflow.com/questions/29960764/what-does-extended-mean-in-express-4-0/45690436#45690436)

내부적으로 true 를 하면 qs 모듈을 사용하고, false 면 query-string 모듈을 사용한다. 이 두 모듈간의 차이에서 중첩객체 파싱여부가 갈린다. 예제는 참조문서의 stackoverflow 에 잘 나와있다.

### req.body.hasOwnProperty is not a function 이슈

- 참조문서 : [https://github.com/expressjs/express/issues/3264](https://github.com/expressjs/express/issues/3264)

express generator 등오로 express 프로젝트를 세팅하면, app.js 에서 `app.use(express.urlencoded({extended: false}));` 가 보인다.

위에서 언급했듯이, false면 querystring모듈을 사용하는데, querystring.parse는 object를 상속받지 않는다. 따라서 아래와 같은 이슈가 있을 수 있다.

### 실제 예시 코드

최근 프로젝트에서 사용한 body-parser 모듈은 `db.js` 에서 ajax 통신 post 방식으로 FE에서 책을 등록할 때 해당 책의 정보를 넘겨줄 때 사용한다. BE에서 ajax 통신을 받을 때 이러한 방식으로 사용했다. JSON형식으로 넘겨온 데이터를 조금 더 파싱하기 편한 형태로 만들기 위해서 body-parser 모듈을 사용했다. 요청 파라미터인 `req`에 `body` 로 쉽게 접근한다.

```jsx
router.post("/upload", upload.single('file'), (req, res) => {
    //res.json({ file: req.file });
    const name = req.body.name;
    const auth = req.body.auth;
    const pub = req.body.pub;
    const price = req.body.price;
    const image = req.file.filename;
    book.create({
        name: name,
        auth: auth,
        pub: pub,
        price: price,
        image: image
    }).then(book => {
        console.log("generated BOOK", book.name);
    });
    res.header("Access-Control-Allow-Origin", "*");
});
```

# http-errors

## 설치

```jsx
npm install http-errors
```

## 예시

```jsx
var createError = require('http-errors')
var express = require('express')
var app = express()

app.use(function (req, res, next) {
  if (!req.user) return next(createError(401, 'Please login to view this page.'))
  next()
})
```

error을 캐치하고 해당 에러를 에러코드에 맞춰서 에러를 처리할 수 있다.

## 실제 예시 코드

```jsx
// catch 404(not found) and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});
```

프로젝트에서는 app이 404 에러코드(존재하지 않은 페이지)를 받으면 해당 에러를 처리해주고 next()을 통해서 다음 미들웨어 함수로 넘겨준다. 밑에 error handler 또한 에러가 있다면 메시지와 에러를 `res`객체에 담아서 보낸다.

---

- 12日  

# 세그먼트 트리

문제를 예로 들어서 세그먼트 트리를 얘기해보자. [참고](https://www.acmicpc.net/blog/view/9)을 내가 이해한 방향으로 적어보았다.  

## 문제
배열 A가 있고, 여기서 다음과 같은 두 연산을 수행해야하는 문제를 생각해보자

1) 구간 l, r (l ≤ r)이 주어졌을 때, A[l] + A[l+1] + ... + A[r-1] + A[r]을 구해서 출력하기
2) i번째 수를 v로 바꾸기. A[i] = v
수행해야하는 연산은 최대 M번이다.  

세그먼트 트리나 다른 방법을 사용하지 않고 문제를 푼다면, 1번 연산을 수행하는데 O(N), 2번 연산을 수행하는데 O(1)이 걸리게 된다. 총 시간 복잡도는 O(NM) + O(M) = O(NM)이 나오게 된다.  

2번 연산이 없다고 생각해보자.  

수를 바꾸는 경우가 없기 때문에, 합도 변하지 않는다. 따라서, 앞에서부터 차례대로 합을 구해놓는 방식으로 문제를 풀 수 있다.  

S[i] = A[1] + ... + A[i] 라고 했을 때, i~j까지 합은 S[j] - S[i-1]이 된다.  

i~j까지 합은 A[i] + ... + A[j]인데, S[j] = A[1] + ... + A[j], S[i-1]= A[1] + ... + A[i-1] 이기 때문이다.  

```c++
S[0] = A[0];
for (int i=1; i<n; i++) {
    S[i] = S[i-1] + A[i];
}
```
여기서 2번 연산을 하려면, 수가 바뀔때마다 S를 변경해줘야 한다. 가장 앞에 있는 0번째 수가 바뀐 경우에는 모든 S 배열을 변경해야 하기 때문에, 시간복잡도는 O(N)이 걸리게 된다.  

따라서, M과 N이 매우 큰 경우에는 시간이 너무 오래걸리게 된다.  

이러한 부분을 해결하기 위해서 사용하는 자료구조가 `세그먼트 트리`이다.  


## 세그먼트 트리
세그먼트 트리를 이용하게되면 해당 1번 연산과 2번 연산 모두 O(logN)으로 수행할 수 있다.  

세그먼트 트리의 리프 노드와 리프 노드가 아닌 다른 노드의 의미는 다음과 같다.
- 리프 노드 : 배열 그 수 자체
- 다른 노드 : 왼쪽 자식과 오른쪽 자식의 합

따라서 노드의 번호가 `x`라면 왼쪽 자식의 번호는 `2*x`, 오른쪽 자식의 번호는 `2*x+1`가 되게 된다.  

리프 노드가 10개 인 경우를 그림으로 보면 다음과 같다.  
![세그먼트 트리](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg1.png)  

해당 노드에 적혀있는 숫자는 저장하고 있는 합의 범위를 나타낸 것이다. 노드의 번호의 경우에는 위에서 적은 것과 같이 왼쪽 자식의 번호는 해당 노드에 2를 곱한 값, 오른쪽 자식의 번호는 2를 곱한 뒤 1을 더한 값이 되게된다.  

### 트리 제작
만약 N이 2의 제곱꼴이라면 완전 이진 트리로 높이가 `logN`이다. 리프 노드가 N개인 완전 이진 트리는 필요한 노드의 갯수가 `2*N-1`개이다.  

2의 제곱꼴이 아니라면, 높이가 H = ⌈logn⌉ 이며, 총 세그먼트 트리를 만드는데 필요한 배열의 크기는 2^(H+1) -1개가 된다.  

따라서 다음 코드로 Segment Tree를 만들 수 있다.
```c++
// a: 배열 a
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
```
start == end 인 경우는 node가 리프 노드인 경우이다. 리프 노드는 배열의 그 원소를 가져야하기 때문에 `tree[node] = a[start]`가 된다.  
node의 왼쪽 자식은 `node*2`, 오른쪽 자식은 `node*2+1`이 된다. 이때, node가 담당하는 구간이 `[stard,end]`라면 왼쪽 자식은 `[start, (start+end)/2]`, 오른쪽 자식은 `[(start+end)/2 +1, end]`를 담당한다. 따라서 재귀 함수를 이용해서 왼쪽 오른쪽 자식 트리들을 만들어서 합을 저장한다.

### 합 찾기
구간이 `[left, right]`로 주어졌을 때, 합을 찾으려면 루트부터 트리를 순회하면서 각 노드가 담당하는 구간과 left, right 사이의 관계를 봐야한다.  

예를 들어서 [0,9]의 합을 구하는 경우에는 루트 노드 하나로 합을 알 수 있다.
[세그먼트 0,9](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg3.png)  
또, [3,9]의 합을 구하는 경우에는 다음과 같다.  
[세그먼트 3,9](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg6.png)  

node가 `[start, end]`을 담당하는 경우에 해당 구간의 합을 구해야한다. 이 때 4가지로 나뉘게 된다.

1) [left, right]와 [start,end]가 겹치지 않은 경우
2) [left, right]와 [start,end]를 완전히 포함하는 경우
3) [start, end]]와 [left, right]를 완전히 포함하는 경우
4) [left, right]와 [start,end]가 겹치져 있는 경우 (1,2,3 제외한 나머지 경우)  

`1번`의 경우엔 `if (left > end || right < start)`로 나타낼 수 있다. `left > end`는 `[start, end]` 뒤에 `[left, right]`가 있는 경우다. 이 경우엔 겹치지 않으므로 탐색을 이어갈 필요 없다. 따라서 0을 리턴하고 종료한다.

`2번`의 경우엔 `if (left <= start && end <= right)`로 나타낼 수 있다. 이 경우에도 탐색을 이어갈 필요가 없다. 왜냐하면, 구해야하는 합의 범위는 `[left, right]`인데, `[start, end]`는 그 범위에 모두 포함되고, 그 node의 자식도 포함되기 때문에 더 이상 호출할 필요가 없다. 따라서 tree[node]를 리턴하고 종료한다.

`3번`과 `4번`의 경우는 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리로 다시 탐색을 시작해야 한다.  
```c++
// node가 담당하는 구간이 start~end이고, 구해야하는 합의 범위는 left~right
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}
```

### 수 변경하기
중간에 어떤 수를 변경한다면, 그 숫자가 포함된 구간을 담당하는 노드를 모두 변경해야한다.  
3번째 수를 변경할 때, 변경해야하는 구간을 봐보자.
[세그먼트 수 변경](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg7.png)  
다음은 5를 변경할 때 변경해야하는 구간이다.  
[세그먼트 수 변경2](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/blog/seg8.png)  

index 번째 수를 val로 변경한다면, 그 수가 얼마만큼 변했는지 알아야한다. 해당 숫자를 `diff`라고 하면, `diff = val - a[index]`로 구할 수 있다.  

수 변경은 2가지 경우가 있다.
1) `[start, end]`에 index가 포함된 경우
2) `[start, end]`에 index가 포함되지 않은 경우

node의 구간에 포함되는 경우에는 `diff`만큼 증가시켜 합을 변경해 줄수 있다. `tree[node] = tree[node] + diff` 포함되지 않은 경우는 그 자식도 index가 포함되지 않으므로 탐색을 중단해야 한다.
```c++
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
```
리프 노드가 아닌 경우에는 자식도 변경해줘야 하기 때문에, `start != end`로 리프 노드인지 검사 해줘야 한다.

---

- 13日  

# 세그먼트 트리를 이용한 문제풀이  
[구간 합 구하기](https://www.acmicpc.net/problem/2042) ,[최솟값](https://www.acmicpc.net/problem/10868) ,[최솟값과 최댓값](https://www.acmicpc.net/problem/2357), [구간 곱 구하기](https://www.acmicpc.net/problem/11505)  

## 구간 합 구하기
```c++
const int MAX = 1000000 + 1;

long long arr[MAX];
long long tree[4*MAX];

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    } else {
        return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
    }
}
void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	m += k;
	
    for (int i=0; i<n; i++) 
    	cin >> arr[i];
    		
    init(1, 0, n-1);
    
    while (m--) {
        int t1;
        cin >> t1;
        
        if (t1 == 1) {
        	int t2;
        	long long t3;
            cin >> t2 >> t3;
            t2--;
            long long diff = t3 - arr[t2];
            arr[t2] = t3;
            update(1, 0, n-1, t2, diff);
        }
		else if (t1 == 2) {
            int t2, t3;
            cin >> t2 >> t3;
            cout << sum(1, 0, n-1, t2-1, t3-1) << '\n';
        }
    }
}
```
가장 기본적인 문제로 세그먼트 트리를 각 범위의 합을 노드의 값으로 가지게 만들어준다. 따라서 `init()` 함수를 통해서 세그먼트 트리를 만들어주고 이후의 `update()` 함수와 `sum()` 함수로 원하는 기능을 구현해주었다.  

`sum()` 함수의 경우에는 `init()` 함수와 비슷하되 그 범위의 값을 더해서 리턴하는 형식이며, `update()` 함수는 변경 값을 해당하는 배열 값을 빼서 두 값의 차이만큼을 diff 매개변수로 넘겨서 해당하는 범위에 값을 모두 diff만큼 더해준다. 리프 노드가 아닌 경우에는 자식도 변경해야하므로, `if(start != end)` 조건으로 리프 노드인지 체크 해주었다.  


## 최솟값
```c++
const int MAX = 100000 + 1;
const int INF = 1000000001;

int arr[MAX];
int tree[4 * MAX];

int init(int node, int start, int end) {
	if(start == end)
		return tree[node] = arr[start];
	else 
		return tree[node] = min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2 +1, end));
}

int select(int node, int start, int end, int left, int right) {
	if (left > end || right < start) 
		return INF;
	if (left <= start && end <= right)
		return tree[node];
	
	return min(select(node*2, start, (start+end)/2, left, right), select(node*2+1, (start+end)/2+1, end, left, right));
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	init(1, 0, n-1);
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		cout << select(1,0,n-1,a-1,b-1) << '\n';
	}
}
```
이전 문제인 구간 합 구하기와 비슷하게 세그먼트 트리 자료구조를 형성해서 푸는 문제로, 똑같이 하되, 최솟값을 구하기 위해서 `init()` 함수로 세그먼트 트리를 만들 때 최솟값을 리턴하게 하여 세그먼트 트리가 해당 범위의 최솟값을 노드 값으로 저장하게 했다. 또 `select()` 함수도 범위의 최솟값을 찾아서 리턴하게 만들었다.


## 최솟값과 최댓값
```c++
const int INF = 2e9 + 1;
const int MAX = 100000 + 1;

int arr[MAX];
int max_tree[4*MAX];
int min_tree[4*MAX];

int max_init(int node, int start, int end) {
	if(start == end)
		return max_tree[node] = arr[start];
	else 
		return max_tree[node] = max(max_init(node*2, start,(start+end)/2), max_init(node*2+1, (start+end)/2+1, end));
}

int min_init(int node, int start, int end) {
	if(start == end)
		return min_tree[node] = arr[start];
	else 
		return min_tree[node] = min(min_init(node*2, start,(start+end)/2), min_init(node*2+1, (start+end)/2+1, end));
}

int max_select(int node, int start, int end, int left, int right) {
	if(left > end || right < start)
		return 0;
	if(left <= start && end <= right)
		return max_tree[node];
	
	return max(max_select(node*2, start, (start+end)/2, left, right), max_select(node*2+1, (start+end)/2+1, end, left, right));
}

int min_select(int node, int start, int end, int left, int right) {
	if(left > end || right < start)
		return INF;
	if(left <= start && end <= right)
		return min_tree[node];
	
	return min(min_select(node*2, start, (start+end)/2, left, right), min_select(node*2+1, (start+end)/2+1, end, left, right));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	max_init(1,0,n-1);
	min_init(1,0,n-1);
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		cout << min_select(1,0,n-1,a-1,b-1) << ' ' << max_select(1,0,n-1,a-1,b-1) << '\n';
	}
}
```
이 문제는 최솟값 문제와 매우 비슷하다. 반대로 최댓값을 만들면 되나, pair을 통한 배열로 구현할 것인지 각자 세그먼트 트리를 범위의 최댓값을 넣는 트리와 최솟값을 넣는 트리로 두 가지를 나눠서 할 지 고민하였다.  

문제에서 메모리가 충분해 보이므로 두 개의 트리를 만들어서 각자 함수를 통해서 구하도록 만들었다. 이 문제에 경우에는 앞에서 푼 두 문제를 응용하면 충분히 풀만 하였다.  

처음에 세그먼트 트리를 이해하는 시간이 오래 걸렸지만 문제 해결에 있어서는 상당히 도움이 되는 자료구조다.

## 구간 곱 구하기
```c++
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000 + 1;
const int DIV = 1000000007;

int arr[MAX];
int tree[4*MAX];

long long init(int node, int start, int end) {
	if(start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = init(node*2, start, (start+end)/2) * init(node*2+1, (start+end)/2+1, end) % DIV;
}

long long update(int node, int start, int end, int idx, int val) {
	if(idx < start || end < idx)
		return tree[node];
	if(start == end)
		return tree[node] = val;
	
	return tree[node] = update(node*2, start, (start+end)/2, idx, val) * update(node*2+1, (start+end)/2+1, end, idx, val) % DIV;
}

long long mul(int node, int start, int end, int left, int right) {
	if(right < start || end < left)
		return 1;
	if(left <= start && end <= right)
		return tree[node] ;
		
	return mul(node*2, start, (start+end)/2, left, right) * mul(node*2+1, (start+end)/2+1, end, left, right) % DIV;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	init(1,0,n-1);
	m += k;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			b--;
			arr[b] = c;
			update(1,0,n-1,b,c);
		}
		else if (a == 2) {
			cout << mul(1,0,n-1,b-1,c-1) << '\n';
		}
	}
}
```
해당 문제는 구간 합 구하기와 비슷하게 하면 될 것이라고 막연하게 생각했지만 발상을 꺾기가 어려웠다.  

합 구하기와 비슷하게 하되 `update()` 함수에서 다른 문제와 달리 해야했다. 왜냐하면 다른 문제에서는 해당 값을 가지고 값을 갱신해도 상관이 없었다. 하지만 이 문제에서는 달랐다.  

이미 모듈러 연산을 통해서 값이 줄어들어있으므로 또 해당 값을 가지고 갱신하면서 모듈러 연산을 하게되면 값이 변하게 된다. 따라서 `update()` 함수에서도 리프 노드부터 값을 새로 갱신을 하여 값을 얻어냈다.

---

- 14日  

그래프 문제를 복습하는 차원에서 풀어보았는데, 상당히 막힌 부분이 많았다.  

벽 부수고 이동하기 시리즈이다. BFS로 생각하되 다른 생각지 못한 부분이 많아서 전체적으로 시간이 길어지고 집중력이 엄청 떨어졌다. `1번`은 수월하게 풀리는 경향이 있었고 `2번`도 `1번`을 조금씩 필요한 만큼 고쳐나갔다.  

벽 부수고 이동하기 2
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int arr[MAX][MAX];
bool visited[MAX][MAX][11];
int pos[4] = {0,0,1,-1};
int pos2[4] = {1,-1,0,0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{1,1},{0,1}});
	visited[1][1][0] = true;
	
	while(!q.empty()) {
		int ypos = q.front().first.first;
		int xpos = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		
		q.pop();
		
		if(ypos == n && xpos == m) {
			cout << cnt;
			return 0;
		}
		
		for (int i=0; i<4; i++) {
			int y = ypos + pos[i];
			int x = xpos + pos2[i];
			
			if(y > n || x > m || y < 1 || x < 1)
				continue;
				
			if(visited[y][x][wall]) continue;
			
			if(arr[y][x] == 1 && wall < k) {
				q.push({{y,x},{wall+1, cnt+1}});
				visited[y][x][wall+1] = true;
			}
			if(arr[y][x] == 0) {
				q.push({{y,x},{wall, cnt+1}});
				visited[y][x][wall] = true;
			}
		}
	}
	cout << "-1";	
}
```

하지만 시리즈 3부터 막히기 시작했다. `3번`부터 생각해낸 것은 밤과 낮에 다른 행동을 주기 위해서 카운트를 모듈러 연산 2를 하여서 밤 낮을 나눠, 부술 건지 말건지 선택하게 해서 풀었다.  


```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int arr[MAX][MAX];
bool visited[MAX][MAX][11];
int pos[4] = {-1,0,1,0};
int pos2[4] = {0,-1,0,1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{1,1},{0,0}});
	visited[1][1][0] = true;
	int ans = -1;
	while(!q.empty()) {
		int ypos = q.front().first.first;
		int xpos = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		
		q.pop();
		
		if(ypos == n && xpos == m) {
			ans = cnt + 1;
			break;
		}
		for (int i=0; i<4; i++) {
			int y = ypos + pos[i];
			int x = xpos + pos2[i];
			
			if(y > n || x > m || y < 1 || x < 1)
				continue;
			
			if(arr[y][x] == 1 && wall < k && !visited[y][x][wall+1]) {
				if(cnt % 2 == 0) {
					q.push({{y,x},{wall+1, cnt+1}});
					visited[y][x][wall+1] = true;
				}
				else if(cnt % 2 == 1) {
					q.push({{ypos,xpos},{wall,cnt+1}});
				}
			}
			else if(arr[y][x] == 0 && !visited[y][x][wall]) {
				q.push({{y,x},{wall, cnt+1}});
				visited[y][x][wall] = true;
			}
		}
	}
	cout << ans;
	
}
```

마지막 `4번`은 제일 시간이 오래걸렸고 다른 문제와 개념이 상이하게 되는 문제인 것 같다. 먼저 `플러드 필 알고리즘` 개념으로 영역마다 값을 넣고 이중 포문에서 벽이 선택되었을 때 주위에 있는 영역의 포함된 공간의 갯수와 자기 자신을 선택한 숫자를 더해서 출력해주면 되는 문제였다. 하지만 이 부분을 생각하기 위해서 문제를 이해하는데 오래걸렸다.  

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAX = 1000 + 1;

int map[MAX][MAX];
int n, m;
bool visit[MAX][MAX];
int resultmap[MAX][MAX];
int cnt;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void visitClear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = 0;
}

void dfs(int y, int x, int comType) {
	cnt++;
	map[y][x] = comType;

	for (int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(nx<0 || ny<0 || nx==m || ny==n) 
			continue;
			
		if(visit[ny][nx] || map[ny][nx])
			continue;
		visit[ny][nx] = true;
		dfs(ny,nx,comType);
	}
}

int main() {
	cin >> n >> m;
	char temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
			if((temp -'0') == 1)
				map[i][j] = -1;
		}
	}

	//컴포넌트 자리 찾아주기
	vector<int>com = {0};
	int comtype = 0; // 1부터시작
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0) {
				comtype++;
				cnt = 0;
				dfs(i, j, comtype);
				com.push_back(cnt);
			}

	//순회하며 컴포넌트 합쳐주기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//벽일때
			if (map[i][j] == -1) {
				//상하좌우의 컴포넌트 구해준거 다합쳐주기, 중복 조심
				int sum = 0;
				set<int> used;
				
				for (int k=0; k<4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					
					if(nx<0 || ny<0 || nx==m || ny==n) 
						continue;
					
					if(map[ny][nx] != -1 && used.count(map[ny][nx])==0) {
						used.insert(map[ny][nx]);
						sum += com[map[ny][nx]];
					}
					resultmap[i][j] = (sum + 1)%10;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << resultmap[i][j];
		}
		cout << '\n';
	}
}
```

---

- 15日  

# 비트마스크

비트마스크란, 정수의 이진수 표현을 활용한 기법이다. 비트가 가질 수 있는 상태는 0과 1로 이진수로 표현이 된다. 따라서 비트로 알 수 있는 정보는 다음과 같다.

- 0과 1로 true/false 상태를 갖는다.
- 이진수를 십진수로 표현 가능하다.

이러한 정보를 활용하는 방법을 봐보자.  
예를 들어 집합 `{0,1,2,3,4,5 ...}`이 있다고 가정한다. 이후 해당 원소가 선택 되었나 안되었나 체크를 하는 방법을 여러가지로 볼 수 있다. 먼저 배열을 통해서 해당 인덱스를 체크할 수 있다.  

```cpp
int array[n] = {1,1,1,1,1,...}; // 0,1,2,3,4
int array2[n] = {0,1,0,1,0,...}; //1,3...
```

이러하게 만든다면 메모리를 쓸데없이 낭비하게되며, 오버헤드가 증가한다. 따라서 다음과 같이 사용하게 되면 효율적일 수 있다.  

```cpp
{0,1,2,3,4} // 11111
{1,2,3,4} // 11110
{1,2,4} // 10110
{2,4} // 10100
{1} // 00010
```
부분집합으로 표현하여, index번째 요소가 존재한다면 1, 없다면 0으로 볼 수 있다. 이러한 값을 그대로 10진수로 변환할 수 있다.  
```cpp
{0,1,2,3,4} // 11111 (2^4 * 1) + (2^3 * 1) + (2^2 * 1) + (2^1 * 1) + (2^0 * 1) = 31
{1,2,3,4} // 11110 (2^4 * 1) + (2^3 * 1) + (2^2 * 1) + (2^1 * 1) = 30 
{1,2,4} // 10110 (2^4 * 1) + (2^2 * 1) + (2^1 * 1) = 22
{2,4} // 10100 (2^4 * 1) + (2^2 * 1) = 20
{1} // 00010 (2^1 * 1) = 2
```

이렇게 부분집합에서 빼고 넣어서 십진수로도 표현 가능할 수 있다. 비트를 제어하기 위해서 비트 연산이 존재한다.  

## 비트 연산

- &(AND) 연산

`1011 & 1100 = 1000` 이러한 식과 같이 해당 비트셋에서 대응하는 두 비트가 모두 1일 때 1을 반환하게 된다.

- |(OR) 연산

`1011 | 1100 = 1111` 이러한 식과 같이 해당 비트셋에서 대응하는 두 비트 둘 중 하나라도 1일 때 1을 반환하게 된다.

- ^(NOR) 연산

`1011 ^ 1100 = 0111` 이러한 식과 같이 해당 비트셋에서 대응하는 두 비트가 서로 다르면 1을 반환하게 된다.

- ~(NOT) 연산

`~1011 = 0100` 이러한 식과 같이 비트 값들을 반전하여 반환한다.  

- `>>,<<`(SHIFT) 연산

`001011 << 2 = 101100` 이러한 식과 같이 해당 값을 숫자만큼 비트들을 옮긴다. 이때 왼쪽 시프트는 `A * 2^B`, 오른쪽 시프트는 `A / 2^B`를 의미한다.  

## 연산

원하는 인덱스의 값을 바꾸고 싶을 때, 어떤 연산을 사용해야 가능한지 보자.  

예를 들어 `0101` => `1101`로 바꾸고 싶은 경우 여러가지 연산이 가능하다. 먼저 `0101 | 1000` 연산을 통해서 원하는 결과를 만들 수 있다. 또, `0101 | 1 << 3`을 통해서도 결과를 만들 수 있다.

- `0101 | 1000 = 1101`
- `0101 | 1 << 3 = 0101 | 1000 = 1101`

추가적으로 `~`연산을 통해서 반대의 값을 쉬프트해서 `&`, `|` 연산을 할때는 먼저 쉬프트한 뒤 그 값을 NOT 연산 뒤 AND나 OR 연산을 하여 값을 얻어낸다.  

마지막으로 연산을 통해서 원하는 인덱스 번째 비트의 값을 알아내는 연산을 봐보자.  

```cpp
Bitset & (1 << idx)
```

쉬프트 연산을 통해 해당 인덱스만큼 밀고 해당 값과 AND 연산을 통해서 1 혹은 0인지 알아 낼 수 있다.  

이러한 테크닉을 비트마스크라고 하며, 여러 문제에 활용될 수 있다. 그 문제 중 대표 문제는 Traveling Salesman Problem으로 외판원 순회 문제이다. 해당 [문제](https://www.acmicpc.net/problem/2098)를 풀어보며 조금 더 이해를 가져보는 시간을 가져보자.

```cpp
int dp[MAX][1<<MAX];
int tsp(int cur, int visited) {
	int& ret = dp[cur][visited];
	if(ret != -1)
		return ret;
		
	if(visited == (1<<n)-1) {
		if(arr[cur][0] != 0)
			return arr[cur][0];
		else
			return INF;
	}
	
	ret = INF;
	for (int i=0; i<n; i++) {
		if(arr[cur][i] && !(visited & (1 << i))) {
			int visit = visited | (1 << i);
			ret = min(ret, tsp(i, visit) + arr[cur][i]);
		}
	}
	
	return ret;
}
```
해당 문제에서 사용한 함수를 가져와봤다. 이런식으로 비트마스크를 사용했다.

---

- 16日  

# LCA

Lowest Common Ancestor(LCA) 즉, 최소 공통 조상을 구하는 알고리즘이다. 두 정점 u,v에서 가장 가까운 공통 조상을 찾는 과정이다.  

![이진 트리](https://ww.namu.la/s/80babca3318fe49e11009da782d4a7b3969bf17517764fe7dab69b05e0477ba3f057a995cd00c2434b4c964cd08ba76267c879cea21db822565ccd8a50252daee99e6b62a7fb63565a921230025be77d5a1f4090a56fb8a80dd67b6fbad32c6e)  

ex) LCA(2,6) = 7, LCA(6,11) = 6, LCA(5,4) = 2  
이런 식으로 노드들의 가장 가까운 위치의 공통 조상을 찾는 알고리즘이다. 또한, 두 노드의 가장 가까운 거리를 찾는다는 의미도 있어서 노드간 거리를 찾을 때도 사용된다.

## 구현 방법

구현 방법으로는 Loop을 이용한 방법과 이전에 공부했던 자료구조인 세그먼트 트리를 이용하는 방법과 DP를 이용하는 방법 3가지로 나눠서 봐보자.  

### Loop를 이용한 방법

먼저 다른 그래프 문제를 풀이하듯 트리구조를 생성해준다. 만일 root가 문제에서 주어진 경우 따로 기억해야한다.  

배열 두 개를 선언해주는데 이때 하나는 노드의 부모노드를 저장해주는 `parent` 배열이고 다른 하나는 깊이를 저장해줄 `depth` 배열이다.  
이후 DFS을 통해 root로부터 각각의 노드들의 parent와 depth을 저장해준다.  

이후 문제에서 주어진 조건을 보자. 두 노드가 주어지면 각각의 depth을 구한다. 두 노드 중 depth가 깊은 노드를 얉은 노드에 깊이만큼 맞춰준다. depth을 같게 맞춰주었는데도 공통 조상을 찾지 못했다면, 두 노드를 동시에 한 칸씩 끌어올리게 된다. 이러한 반복을 통해서 LCS 즉, 최소 공통 조상을 찾게 된다.

### DP 이용하는 방법

Loop로 LCA를 구할 때는 트리의 크기가 작을 때는 시간이 크게 걸리지 않지만 트리의 크기가 커질수록 시간은 부담이 된다. 따라서 시간을 줄일 수 있는 방법인 DP를 이용한 방법에 대해 알아보자.  

먼저 방법에 대해 크게 살펴보면 Loop에서 취한 방법은 모든 노드들의 부모를 다 체크해서 찾아가는 방법이였다. 이 부분을 효율적으로 탐색하기 위해 조상들을 접어서 탐색하는 방법을 취했다. 예를 들어 조상과 노드의 거리가 100이라고 가정시에 `100 = 2^6 + 2^5 + 2^2` 이런 식과 같이 3번의 접근으로 조상을 찾는 방법을 이용했다.  

DP를 통해서 각 노드들의 조상 정보를 저장하게 되는데, 이때 각 노드들의 부모를 먼저 저장하고 부모의 정보를 이용해서 두 단계 앞의 조상을 구한다. 두 단계 앞의 조상을 이용해 네 단계 앞 조상의 정보를 구하고 또 여덟 단계 앞 조상을 구할 수 있다. 이런식으로 나아가게 되면 해당 노드로부터 `2ⁿ`에 해당하는 조상들의 정보를 완성시켜서 이용할 수 있게 된다.  

이후에는 LCA를 구하는 과정을 통하면 된다. 이미 완성된 조상들의 정보로 Loop를 이용한 방식과 같이 얉은 깊이를 기준으로 동일시하게 만든 뒤 조상을 찾아가는 방법이다. 하지만 위치를 조정할 때는 깊이의 차이보다 작은 2ⁿ의 숫자 중 가장 큰 수를 선택하여 그 만큼 위치를 조정시켜준다. 차이가 아직 존재한다면 앞과 똑같이 반복한다.  

그 후 두 노드의 깊이가 같게 되어서 만나게 되면 해당 노드가 LCA가 되는 것이고 만나지 못한다면, 다시 조상노드를 찾기 위해 올라가기를 반복한다. 이때 Loop를 이용한 방법과 다른 점은 조상노드를 찾기 위해 올라갈 때 해당 노드 직전까지만 올라간다는 차이점이 있다. 따라서 두 노드의 부모를 선택하면 그 값이 LCA 즉 최소 공통 조상이 된다. 이러하게 하는 이유는 두 노드의 공통 조상을 찾을 때 가질 수 있는 최대 조상부터 계산을 시작하면, 루트 노드이든 다른 어떤 노드든 가질 수 있는 공통 조상중 가장 깊이가 얕은 조상을 선택할 가능성이 있기 때문이다.  

### 세그먼트 트리를 이용한 방법

세그먼트 트리는 노드들의 값에 해당 자식들에 해당하는 범위만큼의 합과 같은 연산을 통한 값을 저장해놓은 자료구조다. LCA를 구할 때는 작은 값을 찾는 세그먼트 트리로 변형해서 찾아보도록 한다.  

트리를 전순위 탐색하여 탐색순으로 세그먼트 리프노드에 (트리의 높이, 노드번호)를 갱신해준다. 이때 배열에 각 트리의 노드에 해당하는 세그먼트 리프 노드 번호를 기록한다.  

자식노드에서 부모노드로 돌아왔을 때 다시 세그먼트 리프에 (트리높이, 부모노드번호)를 삽입해준다. 리프 노드 번호를 기록할 필요 없다.  

발견된 순서에 따른 쿼리를 통해 두 노드의 LCA 즉, 최소 공통 조상을 구할 수 있다.  

---



