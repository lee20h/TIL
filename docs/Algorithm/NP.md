---
sidebar: auto
---
# NP

NP-완비와 NP-하드에 대해 공부해보았다. 먼저 P와 NP의 개념에 대해 살펴보자.

## P와 NP

**P** : Deterministic Turing Machine에서 **Polynomial Time**에 풀리는 문제  

**NP** : Non-Polynomial이 아닌, Nondeterminisitic Turing Machine에서 **Polynomial Time**에 풀리는 문제, Yes라는 해가 나왔을 때 다항식 시간에 확인할 수 있으면 NP (병렬 처리가 가능하다고 한다.)  
성질 P ⊂ NP은 자명하다.

## NP-완비  
알고리즘에서 **NP-완비 이론**을 공부했다.  
현실적인 시간으로 풀 수 있는 문제들은 n의 다항식으로 표시되는 시간복잡도를 가진 문제들을 `P`문제라고한다. 이때의 P는 Polynominal의 P이다.  
이외의 비다항식 시간 즉 현실적인 시간으로 풀 수 없는 문제들의 예로는  

- 지수시간 (2ⁿ)  
- 계승시간 (n!)  

**Yes/No** 문제  
ex) 그래프 G에서 길이가 k이하인 해밀토니안 경로가 존재하는가?  
**최적화** 문제  
ex) 그래프 G에서 길이가 가장 짧은 해밀토니안 경로는 얼마인가?  
이 두문제는 동전의 앞뒷면문제와 같다. YES/NO문제로 최적화 문제를 해결할 수 있다.  

이러한 내용을 알고 NP-완비 이론에 차차 접근해보자.   

- YES/NO의 대답을 요구하는 문제에 국한 (최적화 문제와 밀접한 관계 가짐)  
- 문제를 현실적인 시간에 풀 수 있는가  
- 거대한 군을 이룸  

현재까지 연구결과로 어떤 문제가 NP-완비라면 현실적인 시간에 풀 수 없다. 허나, 아직 증명이 되지 못했다.  

**다항식 시간 변환**(Polynominal Time Reduction)은 문제 A의 사례 α를 문제 B의 사례β가 있을 때 아래의 성질을 만족해야하며, α≤ｐβ로 표기한다.  

알고리즘은 아래 사진과 같다.  
![Polynominal Time Reduction](/TIL/images/Polynominal-Time-Reduction.JPG)  

1) 문제 A를 다항식 시간에 문제 B로 변환한다.  
2) 변환된 문제 B를 푼다.  
3) 문제 B의 대답이 Yes이면 Yes, No이면 No를 반환한다.  

## NP-완비/하드

**NP-완비/하드**  
**NP-하드** : 모든 NP문제가 NP-하드로 다항식 시간에 변환가능하다.  
**NP-완비**(complete) : NP-완비는 NP이며, NP-하드이다.  
+ NP-하드 ⊂ NP-완비  

예를 들어 이러한 예시가 있을 때
![Polynominal Time Reduction](/TIL/images/Algorithm/Polynominal-Time-Reduction.JPG)  
알려진 임의의 NP-하드 문제 A로부터 문제 L로 다항식 시간에 변환가능하면 문제 L도 NP-하드이다.  

**NP-하드의 증명**  
해밀토니안 싸이클(그래프의 모든 정점을 단 한번씩 방문하고 돌아오는 경로)문제가 NP-하드임을 알고 있을 때 TSP(Traveling Salesman Problem)문제도 NP-하드임을 보인다.  
![TSP](/TIL/images/Algorithm/TSP.JPG)  
`해밀토니안 싸이클을 갖는다 ⇔ 길이가 정점n 이하인 해밀토니안 싸이클을 갖는다.`  
따라서 TSP는 NP-하드이다.  

NP-완비 문제의 예  
- 최단 경로  
	- 그래프의 정점 s에서 t로 가는 최단 경로는 간단히 구할 수 있다.
- 최장경로
	- 그래프의 정점 s에서 t로 가는 최장경로는 간단히 구할 수 없다.
	- NP-완비

두 문제의 난이도는 차이가 엄청나다.  
*최장경로 문제* : 주어진 그래프에서 정점 s에서 t로가는 길이 k 이상인 단순경로가 존재하는가?  
*두 점 사이 해밀토니안 경로 문제* : 주어진 그래프에서 정점 s에서 t에 이르는 해밀토니안 경로가 존재하는가? (NP-완비)  
해밀토니안 경로 문제를 이용해서 최장경로 문제를 해결해보자. 
![Longest-Path](/TIL/images/Algorithm/Longest-Path.JPG)  
두 점 s와 t사이에 해밀토니안 경로를 갖는다 ⇔ 두 점 s와 t 사이에 길이가 4인 단순경로를 갖는다.  
따라서 최장경로 문제는 NP-하드다.  

어떤 문제가 NP-완비/하드로 확인되면  
- 쉬운 알고리즘을 찾으려는 헛된 노력 중지
- 주어진 시간 예산 내에서 최대한 좋은 해를 찾는 알고리즘(휴리스틱) 개발에 집중한다. (대부분 Greedy 알고리즘 이용)  

포함관계  
![NP-Relation](/TIL/images/Algorithm/NP-Relation.JPG)   
P ⊂ NP (O)  
NP ⊂ P (?) 아직까지 밝혀진 바가 없다.  