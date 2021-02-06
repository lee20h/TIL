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

이 문제로 에라토스테네스의 체와 백트래킹을 다시 공부할 수 있었다.

---

- 3 日

# PS

- `2436. 공약수`

```cpp
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int g, l, n;
	long long a, b;
	cin >> g >> l;

	int num = l / g;

	for (int i=1; i*i<=num; i++) {
		if(num%i == 0 && gcd(i, num/i) == 1) {
			n = i;
		}
	}

	a = g * n;
	b = g * (num/n);
	cout << a << ' ' << b;
}

```

최대 공약수와 최소 공배수가 주어졌을 때 해당 값을 구하기 위한 두 자연수를 구하는 문제이다. 최대 공약수란 두 수를 서로소가 나올 때 까지 나누었을 때 나온 공약수의 곱이며, 최소 공배수는 최대 공약수에 나머지 서로소의 값들을 곱해준 값이다. 따라서 두 값의 서로소들의 곱을 구한 뒤 그 값을 기준으로 약수를 구한다.

약수를 구할 때는 서로소들의 곱의 제곱근까지만 약수를 구하며, 약수이면서 서로소들의 곱과 또 서로소인 값들을 찾아서 최대 공약수와 곱해주면 원하는 값을 찾을 수 있다.

- `2589. 보물섬`

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;

int py[4] = {0, 0, 1, -1};
int px[4] = {1, -1, 0, 0};

char arr[MAX][MAX];
int cache[MAX][MAX];
int w, h;

int bfs(int a, int b) {
	int ans = 0;
	queue<pair<int,int>> q;
	q.push({a,b});
	memset(cache, 0, sizeof(cache));
	cache[a][b] = 1;
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i=0; i<4; i++) {
			int dy = y + py[i];
			int dx = x + px[i];
			ans = max(ans, cache[y][x]);
			if(dy < 0 || dx < 0 || dy >= h || dx >= w)
				continue;
			if(arr[dy][dx] == 'W' || cache[dy][dx])
				continue;
			q.push({dy,dx});
			cache[dy][dx] = cache[y][x] + 1;
		}
	}

	return ans-1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> h >> w;

	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if(arr[i][j] == 'L')
				ans = max(ans,bfs(i, j));
		}
	}

	cout << ans;
}

```

지도의 크기와 지도에 각 타일에 육지와 바다가 주어진 다음에 육지와 육지 거리 중에서 가장 긴 부분이 보물상자가 있는 곳이라고 한다. 이 문제의 풀이를 너비우선탐색을 하되 주어진 출발점이 없으므로 모든 육지 지점에서 너비우선탐색을 하며, 가장 긴 지점을 찾았다.

첫 시도는 boolean형 배열을 이용하여 매번 초기화를 시켜주면서 시간을 체크하고 queue 컨테이너에 좌표 뿐아니라 움직인 거리를 집어넣었었다. 하지만, 답은 나오나 시간초과였다.

다음 시도는 boolean형 배열이 아닌 int형 배열을 가지고 움직인 거리를 적도록 하였다. queue 컨테이너에서 좌표만 표시하며 함수의 반환형을 int로 바꿨다. 그 부분을 바꿨더니 해결할 수 있었다.

---

- 4 日

# 2021 카카오 추천팀 봄 인턴 코딩테스트

결론부터 말하자면 망했다. 해커랭크로 진행되며 총 5문제가 나왔다.

rest api 문제 1개, 객관식 1개, ps 문제 3개가 나왔는데 너무 어렵게 생각했다. 생각보다 쉽게 풀 수 있는 문제가 있었는데 문제를 끝까지 다 읽지 않고 input 위주로 해결하려하다보니 너무 어렵게 접근했다. 또한, 모든 풀이에서 2% 부족했다. 만약 문제를 더 읽고 하나하나 천천히 접근했다면 결과는 달랐을 것 같다. 그리디 1문제, 그래프 1문제, 구현 1문제라 생각된다.

지금 생각하면 1문제 제외하고는 시간 내에 해결할 수 있을 것 같다. 지식과 경험이 부족해서 원하는 만큼 해결하지 못한 경험을 할 수 있었다. 다음에도 이러한 내용이 나올 수 있으므로 조금 더 열심히 공부해서 도전해야겠다.

---

- 5 日

# Absoulte Path & Canonical Path

- 레퍼런스: [absolute-path-vs-canonical-path](https://www.benjaminlog.com/entry/absolute-path-vs-canonical-path)

유닉스 시스템에서 사용하는 경로 중 절대 경로에 대해서는 프로그래밍을 하면 많이 접해볼 상식이다. 하지만 canonical path에 대해서는 접해보지 못했는데 위의 글에서는 다음과 같이 설명한다.

> Canonical Path는 어떤 파일의 경로를 나타내기 위한 유일한 심볼이다. 또한 Canonical path는 항상 절대경로이기도 하다. 물론 역은 성립하지 않는다.

여기서 absoulte path와 비교를 하면서 설명을 더해보자.

`/origin/file1`과 `/origin/../origin/file1`의 absoulte path는 다를까?

둘 다 absoulte path라고 할 수 있다. 즉, 많은 수의 absoulte path는 만들어질 수 있다.

하지만 canonical path는 설명한 바와 같이 유일한 경로를 가진다. 여기서는 `/origin/file1` 이 한 경로만이 canonical path라고 할 수 있다.

---

# PS

LeetCode에서 매달 진행하는 LeetCoding Challenge를 계속 참여하려고 한다. 저번에 본 코딩테스트에서 느낀 점은 영어 문제에 대해서 조건과 목표를 파악하는 부분이 너무 느리기 때문에 영어 문제에 대해 많이 접해볼려고 하며, 하루에 한 문제는 꼭 푸는 방향으로 나아갈 것이다.

- Simpliy Path

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string temp, ans;
        for(int i=0; i<path.length(); i++) {
            if(path[i] == '/') {
                if(temp == ".") {
                    temp.clear();
                    continue;
                }
                else if(temp == "..") {
                    if(v.size())
                        v.pop_back();
                }
                else if(!temp.empty()) {
                    v.push_back(temp);
                }
                temp.clear();
            } else {
                temp += path[i];
            }
        }
        if(path[path.length()-1] != '/') {
            if(temp == "..") {
                if(v.size())
                    v.pop_back();
            }
            else if(!temp.empty() && temp != ".") {
                v.push_back(temp);
            }
        }
        for (int i=0; i<v.size(); i++)
            ans += '/' + v[i];

        if(ans.empty())
            ans = '/';

		return ans;
    }
};
```

주어진 absolute path를 canonical path로 바꿔야하는 문제이다. 따라서 `.`은 무시하며 `..`의 역할만 주어진 채로 구현하였다. 이 때 `/`를 통해서 지금까지 들어온 문자열을 벡터에 넣어서 관리해주었다. 마지막에는 `/`가 나올 수도 있고 안 나올 수도 있다. 따라서 만약 마지막 값이 `/`가 아니라면 포문 내에서 사용한 논리 그대로 이어서 사용해주었다. 벡터 원소 값 앞에 `/`를 붙여서 반환해주면 마무리가 된다.

---

- 6 日

# PS

LeetCode

- Binary Tree Right Side View

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	void rightSideViewFunc(TreeNode *root, int level, int *maxLevel, vector<int> &v) {
		if(root == NULL)
			return;

		if(*maxLevel < level) {
			v.push_back(root->val);
			*maxLevel = level;
		}

		rightSideViewFunc(root->right, level + 1, maxLevel, v);
		rightSideViewFunc(root->left, level + 1, maxLevel, v);
	}

    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        int maxLevel = 0;
        rightSideViewFunc(root, 1, &maxLevel, v);
        return v;
    }
};
```

이진트리가 주어졌을 때 가장 오른쪽에 있는 노드를 출력하는 문제이다. 주어진 구조체를 이용하면서 함수를 완성시켜야 하므로 DFS와 같이 구현하였다. 각 level을 보면서 해당 층에서 가장 먼저 접하는 값을 벡터에 넣어서 반환하도록 하였다. 이것이 가능한 이유는 함수에서 제일 먼저 루트의 오른쪽을 먼저 탐색하도록 하였기 때문이다.

다른 사람들의 코드를 보다가 효율이 매우 좋은 코드를 보게 되어서 같이 올린다.

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int i;
        while(!q.empty())
        {
            int n=q.size();
            for(i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(i==n-1)
                    ans.push_back(temp->val);
            }
        }
        return ans;
    }
};
```

이진트리의 각 층의 오른쪽 노드들을 얻기 위해서 내가 했던 방식과는 달리 큐를 이용한 방법으로 while문이 한번 끝날 때마다 이진트리의 한 층이 끝나는 것이다. 따라서 큐에는 현재 층의 노드들이 들어있으며, 왼쪽과 오른쪽의 자식 노드들을 큐에 집어 넣게 된다. 처음에 큐의 크기만큼 포문을 구성하여 한 층에서만 돌게 하였는데 이 때, 포문의 마지막 반복에는 무조건 해당 층의 오른쪽 노드가 오게 된다. 따라서 해당 노드를 모아서 반환해주면 된다.

이진트리에 대해서 공부할 때, 강의와 책을 보고 배운 것을 이용하여 풀었다. 내가 푼 풀이도 성능 면에서는 나쁘지는 않다. 하지만, 같은 생각을 선택한 컨테이너에 따라서 성능이 확실히 달라지므로 선택할 수 있는 폭을 넓혀야겠다. 큐로 푼 풀이는 내가 생각하기에는 정말 좋은 풀이라고 생각된다.

---
