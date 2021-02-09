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

- 7 日

# PS

- Shortest Distance to a Character

```cpp
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> v, ans;
        for (int i=0; i<s.length(); i++) {
            if(s[i] == c) {
                v.push_back(i);
            }
        }
        int idx= 0;
        for (int i=0; i<s.length(); i++) {
            if(idx != v.size()-1) {
                if(abs(v[idx]-i) >= abs(v[idx+1]-i)) {
                    idx++;
                }
            }
            ans.push_back(abs(i-v[idx]));
        }
        return ans;
    }
};
```

문자열과 특정한 문자가 주어졌을 때 문자열 속에서 가장 가까운 특정한 문자의 거리를 문자마다 구해서 반환하는 문제이다.

예를 들어 `nicemeetyou`가 주어졌을 때 문자는 `e`라고 가정한다. 그렇다면 원하는 정답 배열은 `32101001234`이다.

먼저 특정한 문자가 문자열에 어떤 인덱스에 위치해있는지 구한다. 그렇게되면 문자열에서 몇번째 인덱스에서 특정한 문자가 나오는지 알고 있다. 따라서 문자열 인덱스에서 특정한 문자가 들어있는 인덱스를 빼 준 거릿값 만큼을 출력하면 된다. 이 때, 가장 가까운 특정한 문자를 찾아야하므로 현재 인덱스와 다음 인덱스 중 가까운 것을 취해서 빼줘야한다.

- 여행경로

```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e5+1;

bool visited[MAX];
string ans = "abc";

void dfs(vector<vector<string>> &tickets, string from, string path, int level) {
    if(level == tickets.size()) {
        if(path < ans)
        	ans = path;
        return;
    }

    for (int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == from && !visited[i]) {
            visited[i] = true;
            dfs(tickets, tickets[i][1], path + tickets[i][1], level+1);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    string start = "ICN";
    sort(tickets.begin(), tickets.end());

    dfs(tickets, start, start, 0);

    for(int i=0; i<ans.length(); i+=3) {
        answer.push_back(ans.substr(i,3));
    }
    return answer;
}
```

DFS 문제로, 모든 여행지를 다 돌 수 있다고 가정하고 여행지들을 경유해서 돈다. 이 때, 도는 순서를 찾는 문제이다. 따라서 dfs를 통해서 쭈욱 따라가서 찾되, 똑같은 레벨의 여행지라면 사전 순으로 정렬되어야한다. 정렬 후 dfs 함수를 통해서 모든 값을 구한다.

dfs 함수에서는 돌아보지 않은 여행지 중 출발 여행지가 같다면 dfs 함수를 호출하며, 총 찾은 숫자가 주어진 티켓과 같다면 모든 여행지를 경유한 것이므로 해당 값들 중 가장 사전적 정의가 앞서는 문자열을 가지고 파싱하여 반환한다.

---

# 토익

토익을 치뤘는데 단지 졸업조건으로써 응시했다. 하지만 영어 레퍼런스를 읽는 정도라고 생각했지만 상당히 부족한걸 느꼈다. 영어 레퍼런스를 읽는 날이 많아질테니 앞으로 조금씩 영어 공부를 쭉 해나가야겠다.

---

- 8 日

# PS

- Peeking Iterator

```cpp
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.

	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return Iterator(*this).next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        return Iterator::next();
	}

	bool hasNext() const {
        return Iterator::hasNext();
	}
};
```

Leetcode 오늘의 문제로 Iterator 클래스가 주어지고 이 클래스를 상속하는 PeekingIterator 클래스의 함수를 만들어주는 문제이다. 문제에서 여러 가지 조건을 주석을 통해서 넣어주었다. 나는 최대한 짧고 있는 함수를 이용하려고 하였다. 따라서 next와 hasNext는 있는 클래스에서 그대로 호출하였고 peek의 경우에만 현재 객체를 상위 클래스에 맞춰서 next 함수를 호출하여 다음 원소만 알아볼 수 있게 하였다.

- `2174. 로봇 시뮬레이션`

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 2;

int board[MAX][MAX];

int px[4] = {-1, 0, 1, 0};
int py[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, n, m;
	int robot = 0, wall = 0, crashRobot = 0;
	cin >> a >> b >> n >> m;
	vector<pair<pair<int,int>, int>> v;
	v.push_back({{0,0}, 0});
	for (int i=1; i<=n; i++) {
		int y, x, intDir;
		char dir;
		cin >> x >> y >> dir;
		if(dir == 'N')
			intDir = 1;
		else if (dir == 'E')
			intDir = 2;
		else if (dir == 'S')
			intDir = 3;
		else
			intDir = 0;
		v.push_back({{x,y},intDir});
		board[x][y] = i;
	}

	for (int i=0; i<m; i++) {
		int num, repeat;
		char cmd;

		cin >> num >> cmd >> repeat;

		if(wall || robot)
			continue;

		int dx = v[num].first.first;
		int dy = v[num].first.second;
		int dir = v[num].second;
		while(repeat--) {

			if(cmd == 'F') {
				board[dx][dy] = 0;
				dx += px[dir];
				dy += py[dir];
				if(dy < 1 || dx < 1 || dy > b || dx > a) {
					wall = num;
					break;
				}
				if(board[dx][dy]) {
					robot = num;
					crashRobot = board[dx][dy];
					break;
				}
				board[dx][dy] = num;
				v[num] = {{dx, dy}, dir};
			}
			else if(cmd == 'R') {
				dir = (dir + 1) % 4;
				v[num] = {{dx, dy}, dir};
			}
			else if (cmd == 'L') {
				dir = (dir + 3) % 4;
				v[num] = {{dx, dy}, dir};
			}
		}
	}
	if(wall)
		cout << "Robot " << wall << " crashes into the wall";
	else if(robot)
		cout << "Robot " << robot << " crashes into robot " << crashRobot;
	else
		cout << "OK";
}
```

좌표계가 조금 다르다는거만 빼면 천천히 구현해나가면 된다. y축이 반대로 되어있다는 것을 이용해서 좌표계를 눕혀서 생각했다. 따라서 원래 이차원 배열을 사용할 때 사용하는 좌표인 `arr[y][x]`를 `arr[x][y]`로 바꿔서 이용하였고 방향에 따른 움직임도 그러하게 90도 틀었다. 이후에는 벽에 부딪히는 것과 로봇 끼리 만나는 것을 구현해주기, 방향 틀기만 구현해주었다.

---

- 9 日

# PS

- Convert BST to Greater Tree

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
    void inorder(TreeNode* root, vector<int*>& nums) {
        if(root != nullptr) {
            inorder(root->left, nums);
            nums.push_back(&root->val);
            inorder(root->right, nums);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int*> nums;
        inorder(root, nums);

        for (int i=nums.size()-1; i>0; i--) {
            *nums[i-1] += *nums[i];
        }
        return root;
    }
};
```

- [leetcode](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)

같은 문제로 주소를 달았다.

![예시](https://assets.leetcode.com/uploads/2019/05/02/tree.png)

예제 사진과 같이 오른쪽 자식트리 -> 루트 -> 왼쪽 자식트리의 값을 경로에 따라 더해서 그대로 반환해주면 되는 문제이다.

문제에서는 오른쪽부터 시작하는 것으로 보이나, 결국에는 왼쪽 자식들의 값이 다 더한 값이 되므로, 트리 순회중 중위 순회를 이용하여 순서를 좌->루트->우로 만들 수 있다면 매우 편하게 풀 수 있을 것 같다.

따라서 중위 순회를 이용하여 벡터에 값을 넣어주며, 벡터의 인덱스로 접근할 수 있게 정수의 주소값을 자료형으로 삼았다. 이후에는 중위순회의 순서를 반대로 값을 더해가면 nums[0]에는 최종적으로 모든 값의 합이 담기게 되며, 그 경로의 값들 또한 잘 더해진다.

---

# 객체지향의 사실과 오해

이번 설 연휴를 이용하여 사놓고 잠시 잊혀졌던 책을 읽어볼려고 한다. 바로, 객체지향의 사실과 오해라는 책이다. 이 책은 사람들이 객체지향이라는 패러다임에 대해서 흔히 가지게 되는 오해와 생각들을 이해하기 쉽게 정리해준다.

그 중 하나는 바로 객체지향을 생각할 때 핵심을 클래스로 생각하게 되는데 객체지향에 있어서 핵심은 클래스가 아닌 적절한 책임을 수행하는 역할간의 유연하고 견고한 협력관계를 구축하는 것이다. 클래스는 단지 협력하는 객체를 만들 때 필요한 구현 매커니즘일 뿐이라는 것이다. 클래스가 중요하지 않은 것이 아니라 사람들이 핵심을 잘못 알고 있다는 점을 지적해준다.

나는 객체지향에 대해서 배울 때 C++과 Java를 이용해서 클래스를 구축하고 캡슐화, 다형성 등 여러가지 용어에 대해서 배웠다. 하지만 책의 필자는 그것들이 중요한 것이 아니라고 얘기한다. 즉, 다른 것들은 구현하기 위한 수단일 뿐이고 객체지향의 목적과 핵심을 정확히 생각하라는 것이다.

실생활과 빗대어서 객체에 대해 설명하는데 많은 생각을 하게 하였다. 클래스를 구현하고 그걸 토대로 객체지향 프로그래밍을 했다고 생각하였고 클래스를 사용함을써 나는 객체지향을 배웠다고 생각했다. 하지만 이 책은 몇 장 읽지 않았는데 그 부분이 오해였다고 말하니 다음에 이야기할 내용이 무엇인지 궁금해진다.

---
