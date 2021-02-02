# 📙 Today I Learned

## 규칙

- 기억에 남는 내용 기록 후 [정적 웹페이지](https://lee20h.github.io/TIL/)에 정리
- Github Action으로 배포
- markdown으로 작성
- 문제 풀고 [Problem Solving](https://github.com/lee20h/TIL/tree/master/Problem%20Solving) 폴더에 모으기

---

# 2020년

| [5월](./years/2020/5월.md) | [6월](./years/2020/6월.md) | [7월](./years/2020/7월.md) | [8월](./years/2020/8월.md) | [9월](./years/2020/9월.md) | [10월](./years/2020/10월.md) | [11월](./years/2020/11월.md) | [12월](./years/2020/12월.md) |
| -------------------------- | -------------------------- | -------------------------- | -------------------------- | -------------------------- | ---------------------------- | ---------------------------- | ---------------------------- |

---

# 2021년

| [1월](./years/2021/1월.md) |
| -------------------------- |

---

- 1 日

# C++ 정규 표현식

C++에서는 C++11부터 표준으로 추가된 정규 표현식에 대해서 알아볼려고 한다.

사용되는 객체는 다음과 같다.

- `std::regex`
- `std::smatch`, `std::cmatch`

regex는 사용할 정규 표현식을 지정하면 된다.  
smatch와 cmatch의 경우에는 매칭된 문자열을 `string` 혹은 `const char*`으로 반환해준다.

사용되는 함수는 다음과 같다.

- `std::regex_match`
- `std::regex_search`
- `std::regex_replace`

## 함수

- std::regex_match

```cpp
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
  string str = "100100100110";
  regex reg("(100|110)+");
  smatch m;

  bool flag = regex_match(str, m, reg);
  flag ? cout << "YES" : cout << "NO";
}
```

reg 변수에 정규 표현식을 넣은 뒤 원하는 문자열과 smatch 혹은 cmatch 변수를 regex_match 함수에 파라미터로 넘겨주면 반환값이 boolean 값으로 받을 수 있다.

- std::regex_search

search는 match와 매우 유사하다. 다른 점은 match의 경우에는 모든 문자열이 다 정규 표현식에 일치해야하는데 search에 경우에는 패턴이 일부라도 들어가있다면 true를 반환하는 함수이다. 따라서 사용하는 예시는 match와 유사하다.

- std::regex_replace

replace 함수는 정규 표현식에 매칭되는 문자열을 원하는 표현식에 맞게 수정해주는 역할을 한다. 파라미터로는 문자열, 찾을 정규식, 대체할 정규식 이러한 순서로 3가지를 넣으면 된다.

## 문제 풀이

- `1013. Contact`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	regex reg("(100+1+|01)+");
	smatch m;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string str;
		cin >> str;
		bool flag = regex_match(str, m, reg);
		flag ? cout << "YES\n" : cout << "NO\n";
	}
}
```

## 레퍼런스

- [씹어먹는 C++](https://modoocode.com/303)

---

- 2 日

# PS

- `2023. 신기한 소수`

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int obj;

bool prime(int n) {
	if(n == 0 || n == 1)
		return false;

	for(int i=2; i*i<=n; i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}

void dfs(int n, int cnt) {
	if(cnt == obj) {
		cout << n << '\n';
		return;
	}

	for (int i=1; i<10; i++) {
		if(prime(n*10+i))
			dfs(n*10+i, cnt+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> obj;

	for (int i=1; i<=9; i++) {
		if(prime(i))
			dfs(i, 1);
	}
}
```

주어진 n의 숫자만큼 자릿수를 가진 숫자들 중 1~n자릿수가 전부 소수인 숫자를 출력하는 문제이다. 깊이우선탐색으로 숫자를 만들고 에라토스테네스의 체로 소수를 체크해줘서 n자리 숫자만큼 커지면 해당 값을 출력했다.

---
