# 11월

| 날짜 | 공부 내용 |
|------|----------|
| 1일 | PS |
| 2일 | QoS, Application Layer, File: High-level I/O |
| 3일 | PS, 코드 분석 |
| 4일 | AWS Database services |
| 5일 | 소공 중간고사, 프로그래머스 코딩챌린지 1회 회고 |
| 6일 | OSS: 윈도우 계산기 기능 추가 |
| 7일 | 우아한 테크코스 코딩테스트 회고 |
| 8일 | 분산컴퓨팅 프로젝트 주제 선정 |
| 9일 | DNS, 동적 메모리 할당 |
| 10일 | AWS Network Service, SMTP & FTP |
| 11일 | Github 기능: Project, Issue, WIki, Releases |
| 12일 | AWS VPC |
| 13일 | 소프트웨어공학 유스케이스, UML 모델링, 소프트웨어 설게 기법 |
| 14일 | 카카오 추천팀 인턴 코딩테스트 회고 |
| 15일 | PS, 편집거리 알고리즘 |
| 16일 | Github 기능: Pull Request, AWS ELB |
| 17일 | 연결 리스트, 클린 코드 독서 | 
| 18일 | PS, HTTP & WWW, 소프트웨어 설계 기법 |
| 19일 | 최소 편집 거리를 통한 코딩테스트 문제 재풀이, 클린 코드 독서 |
| 20일 | DB 구조 문서화, Node.js 비동기 |
| 21일 | Process Management |
| 22일 | PS |
| 23일 | Code Review with Github, AWS Route 53 |
| 24일 | 자료흐름 중심 설계, 데이터베이스 설계, IPC: Signal & 공유 메모리 |
| 25일 | 카네기 행복론 |
| 26일 | 카네기 행복론, 리트머스 DB 문서화 |
| 27일 | PS |
| 28일 | PS |
| 29일 | PS |
| 30일 | IPC: Socket, Network Security Protocols, 디자인 패턴, 사용자 인터페이스 |

---

- 1日

캐시
```cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    queue<string> cache;
    if (cacheSize == 0) {
        answer += 5 * cities.size();
        return answer;
    }

    for (int i = 0; i < cities.size(); i++) {
        bool isHit = false;
        string s = cities[i];

        for (int k = 0; k < s.size(); k++) {
            s[k] = toupper(s[k]);
        }

        int size = cache.size();
        for (int j = 0; j < size; j++) {
            string tmp = cache.front();
            cache.pop();
            if (s.compare(tmp) == 0)
                isHit = true;
            else
                cache.push(tmp);
        }
        if (isHit) { //cache hit
            cache.push(s);
            answer += 1;
        }
        else{ //cache miss
            if (size == cacheSize)
                cache.pop();
            cache.push(s);
            answer += 5;
        }
    }

    return answer;
}
```

이 문제는 컴퓨터의 캐시 교체 알고리즘 중 LRU 개념을 구현하면 되는 문제였다. Hit시에 시간은 1초 miss시에는 5초를 둬서 실행시간을 알아보면 되는데, 이 때, 대소문자 구별을 하지 않고, 캐시 크기만큼을 큐로 유지하며 도시 이름이 들어올 때마다 큐를 뒤져서 해당 도시가 이름이 저장되있나 체크한다. 없으면 다시 돌아올 수 있게 캐시를 한바퀴 회전시키고, 있다면 1초를 증가시키고 캐시에 넣고 없다면 5초를 증가시키고 캐시에 넣는다. 이 작업을 반복하도록하여 구현하였다.

여담으로 대소문자 구별을 없앨 때 `toupper`나 `tolower`를 사용해도 좋지만 아스키코드 표를 기준으로 `&31`을 통해서 대소문자 구분 없이 접근이 가능하다는 것도 계속 되뇌이면 후에 도움이 될 것 같다.

---

- 2日

# 컴퓨터 네트워크 : QoS

## Quality of Service

### Flow characteristics

Flow란?

- 일반적으로 응용 프로그램 연결 (FTP 연결, Video 연결 등)을 뜻함
- 망 사업자 관점에서 사용자 (사용자 A의 컴퓨터에서 오는 트래픽)
- IPv4에는 표준 정의가 없으나, IPv6에는 표준 정의가 내려져있음

정의된 Flow에 대해서 어떤 QoS를 제공할 것인가를 생각하는 것이 Flow Characteristics이다.

Flow Characteristics

- Reliability : 패킷 소실이 발생하지 않을 확률
- Delay
- Jitter : 패킷간 도착 간격의 차이
- Bandwidth

B-ISDN의 QoS의 모델은 하부망에서 ATM(Asynchronous Transfer Mode)이 인터넷의 QoS 보장 모델이 적용되지 않는 이유다. ATM이 가격 문제와, 고장이 자주 날 수 있어서 국내에선 사용하지 않는다.

### 인터넷의 QoS 모델

- IETF에서 표준화한 모델로, 두 가지 모델을 정의했다.
    - QoS 보장 서비스(Guaranteed Service) model : Flow 별로 전송 오류가 0%되고 보장한 대역폭을 100% 보장하는 모델
    - Qos 차별화 서비스(Differentiated Service) model : Flow들을 몇 개의 class로 나누고 각 클래스에 대해서 서비스를 차별화하는 모델

각 모델의 방식을 알아보자.

- QoS 보장 서비스

![image](https://user-images.githubusercontent.com/59367782/97831031-3e7e1800-1d12-11eb-8b6c-7a6fb7749368.png)

1개의 queue가 아니라 Flow 개수만큼 queue를 유지하므로 각 Flow에 QoS를 보장할 수 있다. Core 라우터의 경우 flow 개수가 1백만개 이상이다. 그렇다면 queue 또한 1백만개 이상이 생긴다. 우선순위 큐를 사용한 방법이므로 복잡도가 `O(log N)`이 되게 된다. 1백만개 넘게 되면 속도에 문제가 생기므로 크기가 제한적일 수 있다. 이러한 문제를 `Scalability Problem`이라한다.

- QoS 차별화 서비스

![image](https://user-images.githubusercontent.com/59367782/97831219-b9473300-1d12-11eb-9200-082311a3f1b6.png)

1개의 queue가 아니라 Class 개수만큼 queue를 유지한다. 망 사업자가 골드, 실버, 브론즈 서비스를 제공한다. 이 경우에는 3개의 queue만 가지고 있으면 되므로 구현이 간단하고 Scalability Problem이 없다. 하지만 만약 한 클래스에 다 몰리게 되면 차등별로 나눈 클래스의 의미가 없어진다. 이러한 문제를 해결하기 위해 각각의 클래스는 하위 클래스보다는 더 나은 서비스를 제공한다고 보장을 하는 식으로 해결할려고 하고 있다. 또한 각 Flow에 보장하는 QoS는 무엇인가가 아직도 문제로 남아있다.

### Techniques to Improve QoS

현재 라우터는 큐를 하나 사용하여 FIFO 방식으로 순서대로 제공하는 식으로 빠르고 싸게 구현하였다. 하지만 큐 별로 QoS를 제공할 수 없다. 따라서 멀티 큐로 우선순위 큐, 가중치를 준 공정 큐를 통해서 QoS를 제공하는 방법을 고안하기도 했다.

### Integrated Services

- Best-effort service (오늘날의 인터넷 서비스)
- Guaranteed service
    - Signaling
    - Flow Specification
    - Admission
    - Service Classes
    - RSVP(Reservation Protocol) : signaling을 위해서 사용

### RSVP

일대일 통신이 아니라 다자간 통신으로 Source와 여러 Receiver가 존재한다. 먼저 Path를 설정한 뒤 자원을 예약한다. 따라서 먼저 Path messages로 경로를 설정 한 뒤 역방향으로 Resv messages를 통해서 예약을 할 수 있게한다.

- Path messages
- Resv messages

### Differentiated Service

통합서비스를 대체하기 위해 차별화 서비스를 사용할려고 한다. 차별화 서비스는 flow-based가 아닌 class-based로 QoS 모델을 디자인한다.

---

# Application Layer

- **Client-server paradigm**
- Addressing
- Different servcies

## Client-Server Model: Socket Interface

Client와 Server가 Internet을 통해서 통신하는 방식을 의미한다. 대부분 여러 Client와 한 Server와 통신을 얘기한다. 가장 흔한 이러한 방식이 Web Server이다.

### Connectionless iterative server

Client가 연결 요청을 할 때 Server측에서 UDP 요청을 받아서 Client에게 결과를 반환하는 식인데 구현을 While을 통해서 구현되기 때문에 한번에 하나의 요청에만 답할 수 있으므로, 여러 요청시 순서대로 하나씩 응답할 수 있다. 이러한 방식은 구현이 간단하지만 Server의 성능이 비효율적이다. 그리고 UDP를 통한 요청이므로, 간단한 정보만 통신하기 좋다.

### Connection-oriented concurrent server

Client가 연결 요청 시 Server측과 TCP로 연결한 뒤 통신을 하게 되는데 Server가 자신을 Fork하여 Child Server를 통해서 한 Client당 하나의 Child Server를 둬서 통신을 유지한다. 이때 Server의 한 포트를 통해서 사용한다. Fork되는 여러 프로세스를 CPU 스케쥴링할 때 Context-switching에서 생기는 오버헤드 때문에 많은 양의 Server를 가질 수 없다. 이러한 Scalability Problem를 해결하기위해 프로세스를 Fork하지 않고 새로운 Thread를 만들어 Server 역할을 하게 되었다.

해당 방법을 Multi-threaded server라고 한다. 오늘날 기본은 Multi-threaded server가 기본이며, 두 방법을 혼용해서 사용하기도 한다.

### Cluster 방식의 Server implementation

해당 구조가 네이버나 구글같은 사용량이 높은 기업에서도 사용하는 구조이다.

![image](https://user-images.githubusercontent.com/59367782/97833305-6d978800-1d18-11eb-8beb-1fe948034829.png)

Client가 Web Accelerator(Load Balancer)가 HTTP 요청을 받은 뒤 Front-end Server들에 분산시켜서 요청을 보낸다. 이 때 Front-end Server가 다 독립적으로 사용하면 각각의 동기화 문제가 생기기 때문에 Back-end Server를 통해서 DB에 접근하는 구조로 되어있다. Client가 늘어나게 되면 Front-end Server를 늘리게 되면 부하를 이겨낼 수 있다.

## Socket Interface

소켓의 구조는 
||||
|---|---|---|
| Family | Type| Protocol |
|Local Socket address|||
|Remote Socket address|||

소켓 타입은 다음 그림과 같다. 화살표에 적힌 타입으로 코딩을 하게된다.

![image](https://user-images.githubusercontent.com/59367782/97835693-1ac0cf00-1d1e-11eb-9970-35c7bf8721a9.png)

### Socket interface for connectionless iterative server

![image](https://user-images.githubusercontent.com/59367782/97835823-5c517a00-1d1e-11eb-90d1-dff977602f34.png)

Server에서 요청을 받아야 결과를 응답할 수 있다.

### Socket interface for connection-oriented concurrent server

![image](https://user-images.githubusercontent.com/59367782/97835952-a3d80600-1d1e-11eb-8dd4-4d73d7d48fd7.png)
![image](https://user-images.githubusercontent.com/59367782/97835984-ae929b00-1d1e-11eb-815e-523d25a2d860.png)

Server에서 Fork하여 사용하는 이유

서버의 PCB에 레지스터 외에도 I/O Handler가 존재한다. I/O Handler에서 연결된 소켓을 핸들링하게 되는데, fork한 child와 server는 서로 다른 객체지만 child에서 I/O Handler를 똑같이 접근할 수 있으므로 연결된 소켓을 사용할 수 있게 된다.

- 운영체제에서 Process들은 서로 독립적
    - 서로의 메모리 접근 불가
    - 독립적인 프로세스가 자료를 공유하는 방법은 shared memory/message passing 방법이 있지만 서로 인지해야한다. 하지만 Server는 서로 다른 타입의 수많은 child가 언제 어떻게 데이터를 공유할지 알기 어려움
    - 따라서 코딩이 복잡하고 난해하므로 Fork-exec 조합이 server가 child에게 일을 넘기고 사용하기 좋은 방법

---

# File: High-level I/O

## I/O Stream

- Stream: 물줄기, 개울, 시내
    - I/O stream: 데이터가 흘러가는 것. 데이터의 이동을 표현하는 말
        - 예) Media streaming
        - Source 에서 Destination 으로 데이터가 이동함
        - 프로그램은 데이터가 이동하는 통로로, source 이자 destination 일 수 있음
- Input stream: Source로부터 데이터가 들어오는 경로
    - 예) Keyboard -> Program (`scanf()` 로 stream 을 연결할 수 있음)
- Output stream: Destination으로 데이터가 나가는 경로
    - 예) Program -> Console (`printf()` 로 stream 을 연결할 수 있음)

- 입력 스트림(input stream): 다른 곳에서 프로그램으로 들어오는 경로
    - 자료가 떠나는 시작 부분이 자료 원천부 (data source)
    - 표준입력: 원천부가 키보드
        - 파일입력: 파일이면 파일로부터 자료를 읽는 것
        - 스크린입력: 터치스크린이면 스크린에서 터치 정보
        - 네트워크입력: 다른 곳에서 프로그램으로 네트워크를 통해 자료가 전달
- 출력 스트림(output stream) : 프로그램에서 다른 곳으로 나가는 경로
    - 자료의 도착 장소가 자료 목적부 (data destination)
    - 표준출력: 목적부가 콘솔
        - 파일출력: 파일이면 파일에 원하는 값을 저장
        - 프린터출력: 프린터이면 프린터에 출력물
        - 네트워크출력: 네트워크이면 네트워크 출력이 되어 다른 곳으로 자료가 이동

## 텍스트 파일과 이진파일

- 텍스트 파일: 메모장(notepad) 같은 편집기로 작성된 파일
    - 내용이 아스키 코드(ascii code)와 같은 문자 코드값으로 저장
    - 메모리에 저장된 실수와 정수와 같은 내용도 문자 형식으로 변환되어 저장
    - 텍스트 편집기를 통하여 그 내용을 볼 수 있고 수정 가능

- 이진 파일: 실행파일과 그림 파일, 음악 파일, 동영상 파일 등
    - 목적에 알맞은 자료가 이진 형태(binary format)로 저장되는 파일
    - 자료는 메모리 자료 내용에서 어떤 변환도 거치지 않고 그대로 파일에 기록
    - 입출력 속도도 텍스트 파일보다 빠름
    - 메모장과 같은 텍스트 편집기로는 그 내용을 볼 수 없음
    - 내용을 이미 알고 있는 특정한 프로그램에 의해 인지될 때 의미가 있음

## 파일 스트림과 포인터

- 표준 입출력 라이브러리에서 제공하는 고수준 파일 입출력
    - File stream 이라는 서비스를 사용자에게 제공한다.
        - 저수준IO: 파일 vs. 고수준IO: 파일 스트림
- FILE* : 파일 포인터
    - 고수준 파일 입출력에서 열린 파일을 가리키는 포인터
    - 자료형으로 FILE * 형을 사용 -> 구조체에 대한 포인터

![image](https://user-images.githubusercontent.com/59367782/97855665-6f744200-1d3e-11eb-94cf-8449ff24ae72.png)

### 파일 스트림 열기

- 파일 스트림 열기: fopen(3)
```c
#include <stdio.h>

FILE *fopen(const char *pathname, const char *mode);
```
- Pathname으로 지정한 파일을 mode로 지정한 모드에 따라 열고 파일 포인터를 리턴
- mode 값
    - 파일모드에서 +의 삽입은 수정(update) 모드 의미
        - 원래의 모드에서 읽기 또는 쓰기가 추가되는 모드
        - 수정(update) 모드에서는 모드 간의 전환이 가능
    - 파일모드 r+
        - 처음에 읽기 모드로 파일을 열어 쓰기 모드로 전환 가능
        - 파일이 없으면 오류가 발생
    - 파일모드 w+
        - 처음에 쓰기 모드로 파일을 열어 필요하면 읽기 모드로 전환 가능
        - 만일 파일이 존재한다면 이전의 내용은 모두 사라짐
    - 파일모드 a+
        - 처음에 추가 모드로 파일을 열어 필요하면 읽기 모드로 전환 가능

### 파일 스트림 닫기

- 파일 스트림 닫기: fclose(3)
```c
#include <stdio.h>

int fclose(FILE *stream);
```
- Fopen() 으로 오픈한 파일 스트림을 닫는다.
- Close() 와 마찬가지로, 파일 스트림의 사용 종료를 알리는 역할이며, 저장 장치에 내용이 기록되는 것을 보장하지는 않는다
    - 저장 장치에 즉시 기록하려면: fflush(3)를 사용
- RETURN VALUE
    - On success: 0
    - On error: EOF
        - 성공하든, 실패하든 파일 접근은 더 이상 하면 안 됨

### 버퍼 기반 읽기 및 쓰기

- 버퍼 기반 입력함수: fread(3)
    - Stream으로 지정한 파일로부터, 항목의 크기가 size인 데이터를 **nitems에 지정한 개수**만큼 읽어 ptr에 저장 (구조체의 입출력에 적합함)
    - **성공하면 읽어온 항목 수를 리턴**
    - 읽을 항목이 없으면 0을 리턴
```c
#include <stdio.h>

size_t fread(void *ptr, size_t size, size_t nitems, FILE *stream);
```

- 버퍼 기반 출력함수: fwrite(3)
    - 항목의 크기가 size인 데이터를 **nitems에서 지정한 개수**만큼 ptr에서 읽어서 stream으로 지정한 파일에 출력
    - **성공하면 출력한 항목의 수를 리턴**
    - 오류가 발생하면 EOF를 리턴
```c
#include <stdio.h>

size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream);
```

### 파일 오프셋 지정

- 파일 오프셋 이동: fseek(3)
    - stream이 가리키는 파일에서 offset에 지정한 크기만큼 오프셋을 이동
    - whence는 lseek()와 같은 값을 사용
    - 성공하면 0을, 실패하면 EOF를 리턴
```c
#include <stdio.h>

int fseek(FILE *stream, long offset, int whence);
```

- 현재 오프셋 구하기: ftell(3)
    - 현재 오프셋을 리턴. 오프셋은 파일의 시작에서 현재 위치까지의 바이트 수
```c
#include <stdio.h>

long ftell(FILE *stream);
```

- 함수 fseek(f, 100L, SEEK_SET)의 호출
    - 파일 위치를 파일의 처음 위치에서 100바이트 떨어진 위치로 이동
- 함수 fseek(f, 100L, SEEK_CUR)의 호출
    - 파일의 현재 위치에서 100바이트 떨어진 위치로 이동
- 함수 fseek(f, -100L, SEEK_END)의 호출
    - 파일 끝 위치에서 앞으로 100바이트 떨어진 위치로 이동
- 함수 fseek()에서 offset
    - 양수이면 파일의 끝점으로,
    - 음수이면 파일의 시작점으로의 이동방향을 표시

![image](https://user-images.githubusercontent.com/59367782/97858991-4d30f300-1d43-11eb-93d2-cd8785709ee7.png)

- 처음 위치로 오프셋 이동: rewind(3)
    - 오프셋을 파일의 시작 위치로 즉시 이동

```c
#include <stdio.h>

void rewind(FILE *stream);
```

- 오프셋의 저장과 이동: fsetpos(3), fgetpos(3)
    - fgetpos() : 파일의 현재 오프셋을 pos가 가리키는 영역에 저장
    - fsetpos() : pos가 가리키는 위치로 파일 오프셋을 이동
```c
#include <stdio.h>

int fsetpos(FILE *stream, const fpos_t *pos);
int fgetpos(FILE *stream, fpos_t *pos);
```

## Text File I/O

### fprintf() and fscanf()

- 함수 fprintf()와 fscanf() 또는 fscanf_s()를 이용
    - 텍스트 파일에 자료를 쓰거나 읽기 위하여
    - 헤더 파일 stdio.h를 포함
        - 첫 번째 인자는 입출력에 이용될 파일
        - 두 번째 인자는 입출력에 이용되는 제어 문자열
        - 다음 인자들은 입출력될 변수 또는 상수 목록
```c
#include <stdio.h>

int fprintf(FILE *stream, const char *format, ...);

int fscanf(FILE *stream, const char *format, ...);
```
- 함수 fprintf()와 fscanf() 또는 fscanf_s()의 첫 번째 인자에 각각 stdin 또는 stdout를 이용하면 표준 입력, 표준 출력으로 이용이 가능
- Return value
    - fprintf(): 기록한 문자 수. 문자열 마지막의 NULL 문자는 제외
    - fscanf(): 읽은 아이템 수 혹은 파일의 끝에 도달한 경우 EOF

### feof() and ferror()

- 함수 feof(): 파일 스트림의 EOF(End Of File) 표시를 검사하는 함수
    - 읽기 작업이 파일의 이전 부분을 읽으면 0을 반환하고 **(EOF 아님)**
        - 그렇지 않으면 0이 아닌 값을 반환 **(파일 끝!)**
        - 이전 읽기 작업에서 EOF 표시에 도달하면 0이 아닌 값으로 지정 **(파일 끝!)**
    - **단순히 파일 지시자가 파일의 끝에 있더라도 feof()의 결과는 0**
        - 파일 끝에 도달한 다음, 한 번 더 읽기 동작이 수행되어야 EOF 가 셋팅됨
        - 이 동작 때문에 실제 사용 시, 잘못 사용하는 경우가 많음 *(사용 지양)*
- 함수 ferror(): 파일 처리에서 오류가 발생했는지 검사하는 함수
    - 이전 파일 처리에서 오류가 발생하면 0이 아닌 값을 반환 **(오류!)**
        - 오류가 발생하지 않으면 0을 반환 **(정상)**
    - 헤더파일 stdio.h 필요

### Additional services: fgetc() and fputc()

```c
#include <stdio.h>
int fgetc(FILE *stream);
int fputc(int c, FILE *stream);
```

- 함수 `fgetc()`
    - 파일로부터 문자 하나를 입력받는 함수
    - Return value
        - int 형 으로 casting 된 문자 하나를 반환
        - 만약 파일 끝인 경우, EOF 를 반환하며, 에러에는 0이 아닌 값
- 함수 `fputc()`
    - 문자 하나를 파일로 출력하는 함수
    - 함수들은 문자 하나의 입출력의 대상인 파일 포인터를 인자로 이용
- `getc()`와 `putc()`도 존재함. 그러나 잊어버릴 것.
    - Macro 로 구현되어 있을 가능성이 있어, `fgetc()`, `fputc()`보다 빠를 수도 있지만, 예상치 못한 문제점이 생길 수 있음

### Additional services: fgets() and fputs()

```c
#include <stdio.h>
char *fgets(char *s, int size, FILE *stream);
int fputs(const char *s, FILE *stream);
```

- 함수 `fgets()`: 파일로부터 한 행의 문자열을 입력 받는 함수
    - 파일로부터 문자열을 개행문자(`\n`)까지 읽어 마지막 개행문자를 `\0`문자로 바꾸어 입력 버퍼 문자열에 저장
        - 첫 번째 인자는 문자열이 저장될 문자 포인터
        - 두 번째 인자는 입력할 문자의 최대 수
        - 세 번째 인자는 입력 문자열이 저장된 파일
    - 텍스트 파일을 처리할 때, 라인 별로 처리가 가능하여 아주 편리함
- 함수 `fputs()`: 파일로 한 행의 문자열을 출력하는 함수
    - 문자열을 한 행에 출력
        - 첫 번째 인자는 출력될 문자열이 저장된 문자 포인터
        - 두 번째 인자는 문자열이 출력되는 파일
    - `fprintf()` 면 충분하지 않을까?

## Binary file I/O

### Text vs. Binary

- Text I/O: `fscanf()` and `fprintf()`
    - **본래 파일은 “Collection of Bytes”**
    - 텍스트 파일은? 자료의 입출력을 텍스트 모드(아스키 코드)로 처리
        - 텍스트 파일의 내용은 모두 지정된 아스키 코드와 같은 문자 코드값
    - 함수 `fprintf()`를 이용
        - int 형 변수 cnt의 값을 파일 f에 출력하는 과정
        - 실제로 파일에 저장되는 자료는 정수값 10에 해당하는 각 문자의 아스키 값
            - 각각의 문자 ‘1’과 ‘0’을 아스키 코드값으로 변환: 0x31, 0x30
            - 변환한 결과값을 저장함

![image](https://user-images.githubusercontent.com/59367782/97865530-b1f14b00-1d4d-11eb-8d80-94974f4fface.png)

- Binary I/O: `fread()` and `fwrite()`
    - **C 언어의 자료형을 유지하면서, 변환없이 그대로 바이트 단위로 저장**
    - 입출력은 Low-level I/O(read() and write())와 같이 바이트 단위로 수행되지만,
    - 자료형에 따라 데이터 개체 단위로 이용할 수 있도록 인터페이스가 다름
        - Low-level I/O: file, buf, **size**
        - High-level I/O: file, buf, **size and number of data objects**
    - 예) char[4] 형 자료의 쓰기
        - char name[4]; // sizeof(name) = 4
        - Low-level: write(fd, name, **4**); // 4B 사이즈의 데이터
        - High-level: fwrite(name, **4**, **1**, fp); // 4B 사이즈의 데이터를 1개 쓰기
    - **구조체 데이터를 읽고 쓰기에 적합함**
        - C에서는 연관있는 데이터를 구조체로 엮어서 사용하는 경우가 많고,
        - Binary I/O 는 Text I/O 보다 성능 및 용량 면에서 효율적으로 I/O가 가능함

![image](https://user-images.githubusercontent.com/59367782/97865792-1ca28680-1d4e-11eb-8354-f9e79f6d35ff.png)


## 예제

예제 1) `fread()`, `fwrite()`
```cpp
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        FILE *rfp, *wfp;
        char buf[80];
        int i=0, count;

        if(argc != 3) {
                printf("< Usage: ./file4 file_for_read file_for_write >\n");
                return 1;
        }
        rfp = fopen(argv[1], "r");
        if (rfp == NULL) {
                perror("Open file for read");
                exit(1);
        }
        wfp = fopen(argv[2], "w");
        if (wfp == NULL) {
                perror("Open file for write");
                exit(1);
        }
        printf("%s and %s are opened! rfp = %p wfp = %p\n", argv[1], argv[2], rfp, wfp);

        while((count = fread(buf, 1, 10, rfp)) > 0 ) {
                printf("%d: count=%d\n", i++, count);
                fwrite(buf, 1, count, wfp);
        }
        fclose(rfp);
        fclose(wfp);
        return 0;

```

예제 2) `fseek()`, `ftell()`
```cpp
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char buf[80];
int  count;
FILE* fp;

void read_five_bytes() {
        if ((count = fread(buf, 1, 5, fp)) <= 0) {
                perror("Read Error");
                exit(1);
        }
}

int main(int argc, char* argv[]) {
        if(argc != 2) {
                printf ("< Usage: ./high2 filename >\n");
                return 1;
        }

        fp = fopen(argv[1], "r");
        if (fp == NULL) {
                perror("Open");
                exit(1);
        }
        printf("%s is opened! fp = %p\n", argv[1], fp);
        read_five_bytes();
        printf("\n%d: %s\n", count, buf);
        printf("Current position: %ld\n", ftell(fp));

        fseek(fp, 1, SEEK_SET);
        read_five_bytes();
        printf("\n%d: %s\n", count, buf);
        printf("Current position: %ld\n", ftell(fp));

        fseek(fp, 2, SEEK_SET);
        read_five_bytes();
        printf("\n%d: %s\n", count, buf);
        printf("Current position: %ld\n", ftell(fp));

        fclose(fp);

        return 0;
}
```

예제 3) `fprintf()`
```cpp
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        FILE *fp;

        if(argc != 2) {
                printf("< Usage: ./high3 filename >\n");
                return 1;
        }
          
        fp = fopen(argv[1], "w"); 
        if(fp == NULL) {
                perror("Open");
                exit(1);
        }

        fprintf(fp, "%s %d %d %d %2.2f\n", "2015123", 80, 90, 100, 90.00);
        fprintf(fp, "%s %d %d %d %2.2f\n", "2016123", 50, 80, 60, 66.22);
        fprintf(fp, "%s %d %d %d %2.2f\n", "2017123", 70, 20, 70, 55.55);

        fclose(fp);
        return 0;
}    
```

예제 4) `fscanf()`
```cpp
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE *fp;
	char id[10];
	int grade1, grade2, grade3;
	float avg;
	if(argc != 2) {
		printf("< Usage: ./high4 filename >\n");
		return 1;
	}

	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		perror("Open");
		exit(1);
	}
	
	fscanf(fp, "%s %d %d %d %f\n", id, &grade1, &grade2, &grade3, &avg);
	fprintf(stdout, "%s %d %d %d %.3f\n", id, grade1, grade2, grade3, avg);

	fscanf(fp, "%s %d %d %d %f\n", id, &grade1, &grade2, &grade3, &avg);
	fprintf(stdout, "%s %d %d %d %.3f\n", id, grade1, grade2, grade3, avg);

	fscanf(fp, "%s %d %d %d %f\n", id, &grade1, &grade2, &grade3, &avg);
	fprintf(stdout, "%s %d %d %d %.3f\n", id, grade1, grade2, grade3, avg);

	fclose(fp);
	return 0;
} 
```

예제 5) `fscanf() with feof()`
```cpp
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
        FILE *fp;
        char id[10];
        int grade1, grade2, grade3;
        float avg;
        if(argc != 2) {
                printf("< Usage: ./high5 filename >\n");
                return 1;
        }

        fp = fopen(argv[1], "r");
        if(fp == NULL) {
                perror("Open");
                exit(1);
        }

        while(!feof(fp)) {
                fscanf(fp, "%s %d %d %d %f\n", id, &grade1, &grade2, &grade3, &avg);
                fprintf(stdout, "%s %d %d %d %.3f\n", id, grade1, grade2, grade3, avg);
        }

        fclose(fp);
        return 0;
}
```

예제 6-1) `fgets() with feof()`
```cpp
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF	80

int main(int argc, char* argv[]) {
	FILE *fp;
	int line=0;
	char buf[MAX_BUF];

	if(argc != 2) {
		printf("< Usage: ./high6 filename >\n");
		return 1;
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		perror("Open");
		exit(1);
	}
	
	while(!feof(fp)) {
		fgets(buf, MAX_BUF, fp);
		fprintf(stdout, "%3d: %s", line++, buf);
	}

	fclose(fp);
	return 0;
}
```
예제 6-2) `fgets()`
```cpp
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF	80

int main(int argc, char* argv[]) {
	FILE *fp;
	int line=0;
	char buf[MAX_BUF];

	if(argc != 2) {
		printf("< Usage: ./high6 filename >\n");
		return 1;
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		perror("Open");
		exit(1);
	}
	
	while(fgets(buf, MAX_BUF, fp) != NULL) {
		fprintf(stdout, "%3d: %s", line++, buf);
	}

	fclose(fp);
	return 0;
} 
```

예제 7) 구조체 파일 쓰기
```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct {
        char id[10];
        int grade1, grade2, grade3;
        float avg;
} student;

int main(int argc, char* argv[]) {
        FILE *fp;
        int i;
        student data[3];

        if(argc != 2) {
                printf("< Usage: ./high7 filename >\n");
                return 1;
        }

        if((fp = fopen(argv[1], "w")) == NULL) {
                perror("Open");
                exit(1);
        }

        for (i=0; i<3; i++) {
                if(fscanf(stdin, "%s %d %d %d", data[i].id, &data[i].grade1, &data[i].grade2, &data[i].grade3) > 0) {
                        data[i].avg = (data[i].grade1+data[i].grade2+data[i].grade3)/3;
                        fwrite(&data[i], sizeof(student), 1, fp);
                }       else {
                        break;
                }
        }

        fclose(fp);
        return 0;
}

```
이러한 소스코드로 바이너리 파일을 생성한 뒤 `vim` 편집기로 `:%!xxd`로 hex 데이터로 확인하면 해당 값을 볼 수 있다. 이 때, 구조체 크기를 보면 원래는 10, 4, 4, 4,4 를 통해서 26이여야하나, 파일에서는 sizeof(student)는 28이다. 이 이유는 memory alignment로, 인텔 CPU는 데이터의 메모리 시작 주소를 항상 4의 배수가 되도록 정렬한다.
- 이로 인해 10B 크기의 char id[10] 데이터가 저장된 다음, 2B 만큼의 padding space 가 생긴 것
- 다음 int grade1 은 12B 위치부터 저장됨. 이후에는 모든 데이터가 memory aligned 된 위치이므로 padding 이 없음

---

- 3日

# PS

파일명 정렬
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string,pair<string,int>> a, pair<string, pair<string,int>> b){
	if(a.first == b.first) {
        if(a.second.first == b.second.first)
            return a.second.second < b.second.second;
        return stoi(a.second.first) < stoi(b.second.first);
    }
    else
        return a.first < b.first;

}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string, pair<string,int>>> v;
    for (int i=0; i<files.size(); i++) {
        string temp = files[i];
        bool headflag = false;
        bool numflag = false;
        string head, number, tail;
        for (int j=0; j<temp.length(); j++) {
            if(isdigit(temp[j]))
                headflag = true;
            if(!headflag)
                head += tolower(temp[j]);
            else {
                if(!isdigit(temp[j]))
                    numflag = true;
                if(!numflag)
                    number += temp[j];
                else
                	break;
            }
        }
        v.push_back({head,{number,i}});
    }
    stable_sort(v.begin(),v.end(),cmp);
    for (int i=0; i<v.size(); i++) {
        answer.push_back(files[v[i].second.second]);
    }
    return answer;
}
```

파일명이 주어졌을 때, Head와 Number 그리고 Tail로 나누어서 정렬을 하는 문제였다. 이 때 조건이 Head의 경우 사전순, Number는 정수형으로 전환하여 사전순, 전부 같은 경우엔 순서를 유지한다. 이러한 내용을 문자열을 파싱한 뒤 cmp함수를 통해서 sort를 하는 방식으로 코드를 완성했다. 하지만 여기서 `algorithm`헤더에 있는 `sort()`는 불안정 퀵정렬로 안정성을 보장할 수 없다. 따라서 다른 정렬 함수를 사용해야한다. 알아본 바 버블정렬이나 합병정렬은 안정 정렬이라고 한다. 이러한 부분을 `algorithm`헤더에 `stable_sort()`라는 것으로 구현되어있다. 이 부분은 안정성 정렬 찾다가 알아낸 부분이다. 불안정 정렬에 경우에는 조건이 같은 경우에는 랜덤하게 순서가 잡힌다고 한다. 따라서 이러한 `stable_sort()`를 이용하여 해결할 수 있었다.

---

# OSS : 코드 분석 1

## 1단계: 준비

1. 프로젝트의 개요 파악
    - 개발 및 실행 환경 요구 사항
        - 내가 환경을 구성하기에 적절한 자원(컴퓨팅 환경, 시간, 비용 등)을 갖고 있는가?
    - 문서 및 추가 자료들이 있는가?
        - 공식 사이트에 Documentation 이 잘 되어있어야 함
        - 구글 등 검색에서 나오는 자료들이 많아야 trouble shooting이 용이함
        - Project Community 의 규모가 클수록 자료도 많음
2. 실제 SW의 동작 확인
    - 실행 환경을 구성해보지 않고도 미리 수행해볼 수 있다면 매우 좋음
        - 예) 소스 코드가 아니라도 실행 파일이 있거나, 앱이 있거나.
    - 수정할 대상이 될 기존 기능의 동작을 확인
3. 수정할 기능의 구상
    - 어떤 기능을 수정, 추가할 것인가?
        - 실제 사용해보면서 하려고 하는 일의 정확한 요구 사항을 파악해야 함
    - 구현이 가능할 것인지 미리 예측을 해봄
        - 겉으로 파악할 수 있는 세부 동작을 추측해가며 기능의 구현 방향을 다양하게 구상해보고, 난이도를 미리 예측해보아야 함
4. 빌드 및 실행 환경 구성
    - Build environment 의 구성에 관한 문서를 찾고 그에 따라 환경 구성
        - 뭔가 복잡한데 아무런 문서가 없으면…빠르게 포기하자
5. 빌드 후 정상 동작의 확인
    - 실행 환경을 구성하고 수정하고자 하는 기능의 정상 동작을 확인
    - Debug 모드가 있는지 확인하고, 있다면 Debug mode 로 작업

## 2단계: 구조 분석 (architecture)

1. Documents 확보
    - 전체적인 구조 및 세부 컴포넌트에 관한 Document 검색 및 확보
    - 버전을 잘 확인하면서 볼 것
2. 전체적인 구조와 각 컴포넌트의 역할, 인터페이스 파악
    - 구조를 설명하는 main document 전체를 처음 한 번은 정독하자
    - 당장 연관이 없어 보이더라도 소스코드를 볼 때 큰 도움이 됨
3. 수정 기능과 연관있는 세부 컴포넌트의 세부 역할 파악
4. 연관된 컴포넌트들 간의 인터페이스 파악

## 3단계: 코드 분석

1. Document에 따라 코드 분석의 진입점을 설정
    - Top-down: 동작 방식(event driven, procedure 등)에 따라 main() 함수 와 같이 뼈대가 되는 코드부터 call chain을 따라가며 수정하고자 하는 코드까지 trace를 진행
    - Bottom-up: 수정하고자 하는 코드를 바로 접근하고, 해당 코드를 호출하는 함수들을 추적해나가며 전체 구조를 파악
2. 수정하고자 하는 코드의 동작을 확인
    - 우선 코드에 존재하는 주석들을 통해 코드 전체의 흐름 파악
    - 간단한 debugging message를 통해 세부적인 사항 파악: 변수 및 sub-function의 기능 확인
3. 관련된 코드, 컴포넌트와의 연관 관계를 파악
    - 컴포넌트, 함수들 간의 관계를 잘 분리해서 설계하지 않은 코드의 경우, 해당 코드를 수정하면 다른 코드에 영향을 미치는 경우가 있음
    - 전체 코드가 공유하는 자료 구조, 전역 변수 등을 확인해야 함
4. 코드 수정
    - 수정하고자 하는 기능의 형태, 동작을 설계하고,
    - **Divide & Conquer** 방식으로 진행할 수 있도록 구현의 단계를 세분화
    - 한 단계씩 진행하며 반드시 필요한 테스트들을 진행
    - 기존 코드 내용을 수정할 경우, 최소한 주석 처리를 해두거나, `#ifdef` 와 같은 전처리 명령을 이용해 수정한 부분을 기존 코드와 분리할 것
    - 해당 프로젝트의 code convention 을 잘 확인하고, 그에 따라 진행할 것

---

- 4日

# AWS Database services

## Database란?

- A database is a collection of **structured** data
    - File is a collection of bytes (data)
- Database captures an abstract representation of the domain of an application
    - Typically organized as “records” (traditionally, large numbers, on disk)
    - and relationships between records
- DBMS (DB Management System)
    - is a (usually complex) piece of software that sits
    - in front of a collection of data,
    - and mediates applications accesses to the data,
    - guaranteeing many properties about the data and the accesses

### DB and DBMS

![image](https://user-images.githubusercontent.com/59367782/98074229-4e7e2f00-1ead-11eb-8fd2-91f6b8278e47.png)

### DBMS: Issues

- **Atomicity**
- **Consistency**
- **Isolation**
- **Durability**

### DBMS: Key Concepts

- Representing Data
    - Data model
    - Conceptual/Logical Schema
    - Physical Schema
- Declarative Querying and Query Processing
    - High level language for accessing data
    - `Data Independence` (logical and physical)
    - Optimization Techniques for efficiently accessing data
- **Transaction**
    - a way to group actions that must happen atomically (all or nothing)
    - guarantees to move the DB content from a consistent state to another
    - isolate from parallel execution of other actions/transactions
    - recoverable in case of failure (e.g., power goes out) 

### Storage System vs. DBMS

- 둘 모두 데이터를 저장하는 시스템
    - 일반적으로 DB는 스토리지 시스템 상위에 위치하며, 데이터 저장은 스토리지에서 담당
- 차이점은?
    - Representing Data?
    - Query Processing?
    - **Transaction (For ACID!)**

- 원자성(Atomicity): 트랜잭션과 관련된 작업들이 부분적으로 실행되다가 중단되지 않는 것
- 일관성(Consistency): 트랜잭션이 실행을 성공적으로 완료하면 언제나 일관성 있는 데이터베이스 상태로 유지하는 것
- 독립성(Isolation): 트랜잭션을 수행 시 다른 트랜잭션의 연산 작업이 끼어들지 못하도록 보장하는 것
- 지속성(Durability): 성공적으로 수행된 트랜잭션은 영원히 반영되어야 함

## AWS Database

### 서비스 특징

![image](https://user-images.githubusercontent.com/59367782/98075958-b41fea80-1eb0-11eb-8af2-4eb63fafce2c.png)

- 설치, 패치, 재시작 등 모든 관리 서비스 제공
- 필요한 시점에 쉽게 확장
- 사용한 만큼 비용 청구
- 여러 AWS 서비스와 편리한 연동

### 종류

- **관계형**
- **키-값**
- 문서
- **인 메모리** : 데이터 엑세스해야 할 때 데이터를 메모리에 직접 저장하여 마이크로 지연 시간 제공한다.
- 그래프
- 시계열
- 원장

### AWS DB 특징

- 특별히 구축된 데이터베이스
- 확장성
- 완전관리형 또는 서버리스
- 엔터프라이즈급

### AWS DB

![image](https://user-images.githubusercontent.com/59367782/98076582-d9f9bf00-1eb1-11eb-837c-d1b43d0e6a6b.png)

### 서비스 배치

![image](https://user-images.githubusercontent.com/59367782/98076629-f4cc3380-1eb1-11eb-8ec8-f0aa7e8d9c7b.png)

### 인스턴스 주의점

- 중지 (Stop) 기능
    - DB 인스턴스는 최대 7일간 중지 가능
        - 7일이 지날 때까지 수동으로 시작하지 않으면 자동으로 시작됨
    - 중지된 동안에도 스토리지와 백업 스토리지에 대해 요금 부과됨
- 중지할 수 없는 인스턴스
    - 읽기 전용 복제본을 포함한 또는 읽기 전용 복제본인 DB
    - 다중 AZ 배포인 DB 인스턴스
    - Microsoft SQL 서버 미러링을 사용하는 DB 인스턴스
- 중지된 상태에서의 제한
    - 중지된 DB 인스턴스는 수정할 수 없음
    - 중지된 DB 인스턴스와 연결된 옵션 그룹은 삭제할 수 없음
    - 중지된 DB 인스턴스에 연결된 DB 파라미터 그룹은 삭제할 수 없음

## AWS RDS & Aurora (Relational Database Service)

### RDS

- Relational DB 서비스
    - 클라우드에서 관계형 데이터베이스를 간편하게 설정, 운영 및 확장
        - 프로비저닝, 패치, 백업, 복원, 장애 탐지, 복구
    - DB가 설치, 설정된 인스턴스 형태로 제공
        - 메모리, 성능 또는 I/O 최적화 인스턴스 유형을 선택 가능
    - 6개의 DB 지원
        - Amazon Aurora, Oracle, Microsoft SQL Server, PostgreSQL, MySQL 및 MariaDB
    - 기존 DB의 migration 을 지원

[참고 자료](https://docs.aws.amazon.com/ko_kr/AmazonRDS/latest/UserGuide/Welcome.html)

### 주요 기능

- 확장성 (서비스 중지 최소화)
    - 스토리지 용량 확장 (MySQL, MariaDB, PostgreSQL 및 Oracle DB 가능)
    - 컴퓨팅 인스턴스 변경 (수 분 이내 종료)
- 성능
    - 범용 SSD: 최대 3,000 IOPS
    - Provisioned IOPS SSD: 최대 30,000 IOPS
- 가용성/내구성
    - 자동 백업, DB 스냅샷 관리, 다중 AZ 배포, HW 결함 시 자동 교체
- 관리
    - 편리한 생성/관리, 모니터링, SW 자동 패치, 이벤트 알림
- 참고
    - [AWS RDS 제품 세부 정보](https://aws.amazon.com/ko/rds/features/)
    - [RDS 스토리지](https://docs.aws.amazon.com/ko_kr/AmazonRDS/latest/UserGuide/CHAP_Storage.html)

### 다중 AZ 배포

- 다중 AZ DB 인스턴스
    - Amazon RDS는 기본 DB 인스턴스를 자동 생성하고,
    - 다른 가용 영역(AZ)에 있는 예비 인스턴스에 데이터를 동기적으로 복제
    - 인프라 장애가 발생하면, Amazon RDS가 예비 인스턴스 (또는 Amazon Aurora의 경우 읽기 전용 복제본)로 자동 장애 조치를 수행하여, 장애 조치 완료 후 데이터베이스 작업을 바로 재개
- 설정 방법
    - Console에서 해당 옵션 체크

[AZ 배포 참고](https://aws.amazon.com/ko/rds/features/multi-az/)

### RDS Scale out

- 읽기 트래픽을 자동으로 관리되는 `Read Replica`로 분산
- 복수의 Read Replica를 사용하여 워크로드 분산 처리
- 손쉬운 구성

### 읽기 전용 복제본 (Read Replica)

- 읽기 성능 향상
    - 특정 소스 DB 인스턴스의 복제본을 하나 이상 생성하여, 여러 데이터 사본에서 들어오는 대량의 애플리케이션 읽기 트래픽을 처리
- 가용성 향상
    - 장애 처리 시, 독립 실행형 DB 인스턴스로 승격될 수 있음
- 요금
    - 표준 인스턴스와 동일 요금
- 설정 방법
    - Console에서 해당 옵션 체크

[Read Replica 참고](https://aws.amazon.com/ko/rds/features/read-replicas/)    

### 요금

- CPU 크레딧: Xen과 같은 가상화 시스템에서 CPU를 분배하기 위해 사용하는 파라미터. RDS 인스턴스는 EC2인스턴스보다 높고 일관된 크레딧을 부여받아, 높은 성능을 제공할 수 있음
- 다중 AZ배포와 단일 AZ배포는 2배의 가격 차이

### Aurora

Aurora: Enterprise급 DB 서비스

- 자가 복구 분산 스토리지 기반의 AWS RDS
    - 읽기 전용 복제본 최대 15개, 특정 시점으로 복구, Amazon S3로 지속적 백업, 3개의 가용 영역에 걸친 6개의 데이터 복제
- 30초 이내에 인스턴스 장애 조치 수행
- MySQL, PostgreSQL 호환
- 상용 DB의 성능 및 99.99% 이상의 가용성 제공
    - 최대 MySQL 의 5배, PostgreSQL의 3배 성능

RDS보다 비싸고 좋은 성능을 제공한다.

---

- 5日

# 소프트웨어공학 중간고사

소프트웨어공학 강의 중 중요하다고 생각되는 것을 다시금 복습한다.

애자일 소프트웨어, 프로세스 관리, 좋은 사용자스토리의 조건 6가지, 관점 3가지, 소프트웨어 개발 방법 3가지, XP에 대해서, 리팩토링 기법, 요구사항 분석기법 특징

---

# 프로그래머스 코드챌린지 1회 회고

프로그래머스에서 코드챌린지를 하였는데 한달에 한 번 코딩테스트 느낌으로 알고리즘 문제를 해결할 수 있다. 총 4문제 정도가 나오며, 사람들의 참여를 장려하기 위해 상품도 마련했다고 한다. 9월에 2솔, 10월엔 일이 생겨서 참가하지 못했고, 11월엔 시험을 보고 늦게와서 2솔만 할 수 있었다. 전체적인 문제들이 어렵지 않으며 빠르게 생각하여 풀 수 있었다. 하지만 개중에서도 막히는 문제가 있어 곤란하였다. 아직도 바로 떠오르지 않는 문제가 많다는 것이기 때문이다. 다음에 또 개최하게 되면 이번에는 빠지지 않고 다 참여하며 많이 풀 수 있으면ㅁ 좋겠다.

이번 달은 코딩테스트를 위해서 PS를 위주로 하며 학교 강의는 과제 위주로 할 것 같다.

---

- 6日

# 윈도우 계산기 : 기능 추가

윈도우 계산기에 기능 추가를 해보았다. 먼저 오픈소스에 대한 소스 리뷰를 위해서 진행하였지만, 소스 리뷰와 동시에 기능을 추가하는 과제가 있었다. 이 부분에서 조금이라도 쉬운 것을 선택하기 보다는 조금이라도 더 난해한 부분을 해보고 싶어서 왼쪽 메뉴에 무언가를 추가하고 해당 기능을 구현하고 싶었다. 따라서 구현한 것은 학점변환이다.

학점은 학교마다 4.0, 4.3, 4.5, 5.0, 7.0, 100점 만점으로 나뉘게 된다. 따라서 학교마다의 학점의 차이를 보고 변환을 하기 위해서 계산기에서 변환 부분 메뉴를 하나 더 늘려서 그 부분을 학점 변환으로 만들었다. [소스](https://github.com/lee20h/calculator)는 다음을 참고하면 된다.

한국어 부분만 고쳐서 지원하도록 해놨지만, 이러한 기능 추가로 계산기 코드의 패턴이나 어떤 식으로 했는지 코드 리뷰를 할 수 있었다.

---

- 7日

# 우아한 테크코스 코딩테스트

우아한 테크코스 1차 온라인 코딩테스트를 보고 회고를 적으려한다. 4시간동안 7문제를 푸는 것으로, 난이도는 어렵지 않았다. 하지만 놀라운 것은 먼저 코드를 테스트 케이스로 실행 후 제출하면 서버의 테스트 케이스로 비교하여 점수를 주던 카카오 공채 코딩테스트와는 달리 코드만 제출하고 이후에 채점이되는 방식이다. 따라서 모든 문제를 풀었어도 맞았는지는 알 수 없다.

그래도 이전의 코딩테스트나 대회와 달리 난이도가 낮아서 모든 문제를 풀고 제출할 수 있었다. 어려운 문제는 딱히 없었으나 생각보다 4시간이 길어서 집중력이 흩어졌었다. 그래서 문제 해결 시에 시간을 날렸었다. 1~5번 문제까지는 무난하게 한 시간 정도에 해결할 수 있었으나 6번 문제에서 문자열을 파싱한 뒤 비교만 하면 되는데 엉뚱한 생각에 빠져 시간을 많이 날렸다. 이후 7번 문제에서도 접근 방법이 잘못되어서 전부 지우고 20분을 남기고 다시 시도하였다. 이후엔 15분만에 완료하여 제출을 하긴 했으나, 떨떠름한 기분이였다.

문제는 저작권이 있어 따로 올리진 않지만 대부분 문자열 문제였고, 구현 문제였다. 조건들이 쉽게 주어져서 생각보다 코딩하기 간편하게 되어있으며 어떤 문제는 풀고나서 이후에 더 빠른 방법을 알게되어서 아쉬운 문제도 있었다. 삼성 역량테스트 문제 중 아기상어 같은 문제였다.

다음 주에도 있는 코딩테스트를 더 열심히 준비해야겠다.

---

- 8日

# AWS 개발 환경 구성 주제선정

분산컴퓨팅 강의 중 AWS 개발 환경을 구성하기 위한 주제를 선정해야한다. 아직 틀을 정하지 못했지만 여러 가지를 생각해보았다. 먼저 AWS Lambda와 API Gateway와 DynanoDB를 사용한 서버리스를 구현 한 뒤 AWS에서 지원하는 도커같은 컨테이너 서비스 ECR과 Elastic beanstalk를 통해서 웹을 감싸서 배포할 생각을 해보았다. 프로젝트의 주제가 중요한 것이 아닌 AWS를 사용하여 클라우드 컴퓨팅 인프라를 구성하는 것이 목표이다.

수업에서 다룬 S3와 EC2, RDB는 이미 배웠으므로 사용하지 않은 여러 기능을 사용하는 것이 목표이다. 구성을 하기 위해서는 기능들을 사용해서 할 수 있는 것들을 알고 그것들을 사용하여 환경을 조성해야 한다. 

1. 챗봇을 위한 환경 조성
2. 서버리스 웹앱 구성 후 배포 환경 조성

둘 중 하나로 선택하여 제안서를 써볼려고 한다.

---

- 9日

# 컴퓨터 네트워크 : DNS(Domain Name System)

DNS는 IP 주소 대신에 이름을 사용해서 IP주소를 매핑하는 시스템이다.

IP주소 대신에 이름을 사용하는 방법 3가지

- 방법
    1. 컴퓨터내에 host file 유지
        - 인터넷 전체를 IP와 이름을 각 PC가 하나의 파일에 저장하기는 너무 큼
        - 바뀐 IP주소와 이름간의 매핑을 유지하기 어려움

    2. 중앙 서버에 host file 유지
        - 서버를 하나를 가지고 모든 컴퓨터들이 이용하게 되면 병목현상이 일어난다.

    3. DNS 사용
        - 로드 분산
        - 계층 구조

## Name Space

### Flat Name Space
- 각 주소에 유일한 이름을 할당
- 이름은 문자의 연속이고, 구조적이지 않음
    - ex) 210.117.187.210 hello, 210.117.187.184 hi, ...
- 인터넷과 같이 큰 시스템에는 이름 중복을 방지하거나 애매성을 없애기 적절치 않음
    - 즉, 한마디로 이름 관리가 어렵고, 구현이 효율적이지 않음

### Hierarchical Name Space
- 각 이름이 여러 파트로 나뉘어짐
    - ex) (조직의 특성, 조직 이름, 부서 이름, ..)
- 이름을 할당하고 제어하는 주체가 분산될 수 있다
    - 위의 예시에서 조직의 특성은 A, 조직의 이름은 B가 담당하는 식으로 나눌 수 있다.
    - 즉 관리가 쉽고 구현이 효율적임

Hierarchical Name Space에 대한 예시로 여러 조직에서 같은 이름을 PC에 붙일려고 한다면 이러하게 된다.

- 대학1 : `cse.fhda.edu`
- 대학2 : `cse.berkeley.edu`
- 회사1 : `cse.smart.com`

이러한 방식으로 짓게 된다면 이름을 체계적으로 관리할 수 있다.

## Domain Name Space

Hierarchical Name Space를 위해서 Domain Name Space가 설계되었다. 즉, 도메인을 기반한 name space가 존재한다는 말이다.  

![image](https://user-images.githubusercontent.com/59367782/98500767-a8596d00-2290-11eb-8881-1609706359d5.png)

Domain의 포함 관계를 나타낸 예시로, 포함을 하지만 도메인끼리 교차하는 경우는 없다.

구현 방법은 Label을 갖는 역-트리 (inverted tree) 구조를 이용한다.

### 역 트리 구조

![image](https://user-images.githubusercontent.com/59367782/98500859-efdff900-2290-11eb-933c-3cb5a516c71e.png)

- 동일 레벨에서는 각 이름이 유일해야 한다.
- 각 노드는 63자 이하의 문자열로 구성된 label을 갖는다.

### Domain names and labels

도메인 이름은 `dot(.)`으로 구분된 label의 연속이며 항상 해당 노드에서 루트 방향으로 읽으면 된다.

`challenger.atc.fhda.edu`을 보게 된다면 역 트리 구조로 이루어져 있다.
```
Root
  |
Label: edu         Domain name: edu.
  |
Label: fhda        Domain name: fhda.edu.
  |
Label: atc         Domain name: atc.fhda.edu.
  |
Label: challenger  Domain name: challenger.atc.fhda.edu
```

### Qualified Domain Name

- Fully Qualified Domain Name (FQDN)
    - 호스트의 전체 이름을 포함하는 도메인 이름
    - ex) challenger.atc.fhda.edu.
        - challenger라는 이름을 갖는 컴퓨터의 FQDN
    - DNS server는 FQDN만을 IP 주소로 매핑할 수 있음

- Partially Qualified Domain Name (PQDN)
    - 호스트의 앞쪽 이름으로만 구성
    - Resolver가 나머지 suffix를 제공해서 FQDN을 생성
    - ex) challenger
        - DNS client가 suffix인 atc.fhda.edu를 붙여서 DNS server에 요청

```
FQDN                        PQDN
challnger.atc.fhda.edu.     challenger.atc.fhda.edu
cs.hmme.com.                cs.hmme
www.funny.int.              www
```

## Distribution of Name Spaces

Domain name space를 1대에 컴퓨터에 저장하면 병목현상이 발생하고 안정성이 떨어진다. 따라서 동일한 데이터를 여러 대에 분산시키거나 여러 서버가 각자의 의무를 분산시킨다.

### Hierarchy of name servers

```
                      Root server
arpa server     edu server       com server  us server
        fhda.edu bk.edu   mcgraw.com irwin.com 
```

### 서버의 종류

- 루트 서버(root server)
    - 자신의 zone이 전체 트리를 구성하는 서버
    - 대개 자신의 authority를 다른 서버에 양도 (즉, com 서버, edu 서버 등)하고 그 서버들에 대한 참조만 유지
    - 현재 13개 이상의 루트 서버가 전세계에 존재

- 주 서버(Primary server)
    - 자신이 authority를 갖는 znoe에 대한 파일을 저장하는 서버이며, zone 파일의 생성, 유지, 갱신을 담당

- 보조 서버(secondary server)
    - zone 파일을 주 서버로부터 받아서만갱신하고 자신이 생성하지는 않음

- 주의: 하나의 서버가 Zone A에 대해서 주 서버 역할을 하고, Zone B에 대해서 보조 서버 역할을 할 수도 있음

## DNS In The Internet

Root는 Inverse domain, Generic domains, Country domains로 나뉜다.

### Generic domains

Root level에 밑에 Generic behavior에 따른 host를 등록한다. 과거에는 7개의 섹션이 존재하는데 필요에 따라 늘어나고 있다.

- Generic domain labels
    - com: Commercial organizations
    - edu: Educational institutions
    - gov: Government institutions
    - int: Internationa organizations
    - mil: Military groups
    - net: Network support centers
    - org: Nonprofit organizations

### Country domains

Root level 밑에 2문자로 나라의 약어를 통해 나라별 도메인을 둔다.

### Inverse domain

IP 주소를 이름으로 매핑하기 위한 도메인으로 다른 domain과 달리 목적이 반대이다. 

## Resolution

클라이언트가 요청하면 서버가 자신이 authority를 가진 경우 자신의 DB를 검색하여 결과를 전달하고, 그렇지 않은 경우 다른 서버에게 요청을 한 후 응답을 전달한다.

![image](https://user-images.githubusercontent.com/59367782/98503337-9202df80-2297-11eb-94bf-d964fc12b9a0.png)

- Recursive resolution
    - authority를 갖는 DNS Server를 계층 구조에서 찾아 요청하고 응답을 전달
    - Recursive Call과 유사
    - 클라이언트는 1번의 요청하면 됨
    - DNS server의 load가 생김 : Scalability 이슈가 있음

![image](https://user-images.githubusercontent.com/59367782/98503313-84e5f080-2297-11eb-86ec-97276230b974.png)

- Iterative resolution
    - 클라이언트가 각 서버에 직접 요청하여 응답을 받는다.
    - DNS server에 load가 적음

### Resolver

- DNS client (or resolver)
    - 가장 가까운 DNS server에 접근해서 mapping request를 수행
        - 서버는 그 요구를 만족시킬 수 있으면 그 정보를 전달하고, 그렇지 않으면 다른 서버에게 그 정보를 요청한 후 정보를 전달
    
    - 요구 종류
        - Mapping names to addresses
            - 도메인 이름에 대한 IP 주소를 요구 받으면 Generic domain 혹은 country domain을 검사하여 돌려줌
            - ex) `nclab.jbnu.ac.kr`을 요구하면 `210.117.187.184`를 돌려줌
        - Mapping addresses to names
            - Inverse domain을 사용
            - ex) `210.117.187.184`을 요구하면 `nclab.jbnu.ac.kr`을 돌려줌

### Caching

첫 요청 시

![image](https://user-images.githubusercontent.com/59367782/98504390-3a19a800-229a-11eb-9ef9-c545fc69003b.png)

두번째 같은 쿼리 요청 시

![image](https://user-images.githubusercontent.com/59367782/98504423-4bfb4b00-229a-11eb-8bd3-ef8f7fe1eb4b.png)

- 일관성 유지 필요
    - Caching한 매핑이 과거의 것일 수 있음
        - DNS 서버는 caching한 것을 보고 응답을 할 때는 `unauthoritative`라고 마킹함
    
    - 다음의 두 기법이 사용됨
        1. Authoritative server가 매핑 결과를 돌려줄 때 TTL(Time-to-live)을 추가시킴
            - 만일 caching 된 것의 TTL이 expire되면 caching 된 것을 사용하지 않고 authoritative server에게 다시 물어봄
        2. DNS server가 주기적으로 cache 데이터 중 TTL이 expire 된 것을 제거함

Caching은 속도가 느린 것에 병목 현상이 있을 때 속도 향상 목적으로 사용된다.

- 폰노이만 아키텍쳐에서 모든 프로그램을 메모리로 가져온 뒤 cpu로 옮겨서 실행해야한다. 이 때 cpu와 메모리에 병목현상이 있게 되는데, cpu에 cache를 둬서 해결한다.

![image](https://user-images.githubusercontent.com/59367782/98504837-4f430680-229b-11eb-871d-e70e89863216.png)

- 웹 서버와 클라이언트 사이에 요청이 늘어나면 트래픽이 늘어나게 된다. 이 때 병목 현상이 일어나게 된다. 이 때 클라이언트가 웹 서버에 접근하기 전 프록시 서버에 먼저 접근하여 웹 서버에 접근하게 된다. 이렇게 되면 병목 현상을 해결할 수 있다.

![image](https://user-images.githubusercontent.com/59367782/98504749-1c007780-229b-11eb-8650-bae87a05db0e.png)

![image](https://user-images.githubusercontent.com/59367782/98504767-26bb0c80-229b-11eb-90d2-aaf2b7cdd7e3.png)

### Caching 특징

이러한 caching 기법이 효과를 발휘하기 위해서는 반드시 `locality of reference`를 가져야 함
- Temporal locality: 시간적 지역성
- Spatial locality: 공간적 지역성

위의 예시들은 이러한 지역성들을 만족한다.

### Caching Overhead

Caching 기법이 갖는 overhead는 `Data consistency`이다. 만약 중복된 데이터가 서로 다른 값을 갖게 되면 문제가 생긴다.

따라서 속도 향상을 생각할 때 Caching 기법 적용 가능 유무를 항상 머리속에 가지고 있으면 좋다. OS의 virtual memory에서 Paging 기술도 일종의 caching 기법으로 간주 가능하다.

프록시 서버를 요즘 안 쓰는 이유는 웹 서버와 프록시 서버의 데이터 차이가 생길 수 있는데 이러한 내용이 자주 일어나게 되어 Temporal locality가 떨어지게 되어 사용하기 힘들게 되었다.

Caching overhead가 크면 적용하지 않지만 만약 overhead가 작다면 충분히 도입하면 효율이 좋으므로 생각을 항상 해주는 것이 좋다.

---

# 유닉스 : Dynamic Memory Allocation

## Memory Allocation

### Volatile and Non-volatile storage devices

- **Primary storage: Main memory**
    - 주기억장치로 사용하는 DRAM 등의 휘발성 저장 장치
    - 성능이 높지만, 적은 저장 공간 제공
        - **프로그램 내의 변수와 같이 용량은 적지만 자주 접근하는 자료를 저장**
- Secondary storage: Storage devices
    - 보조기억장치로 사용하는 HDD, SSD 등은 비휘발성 저장 장치
    - 느리지만, 많은 저장 공간을 제공
        - 시스템 종료 시에도 보관하여야 할 데이터를 적재하고, 시스템 재기동 시 다시 로드
    - 일반적으로 파일(file)의 형태로 데이터를 저장함

### Memory

- 메모리는 한정된 자원 (예. 8GB, 16GB)
    - OS와 여러 프로세스가 동시에 물리 메모리 공간을 공유하며 실행됨
    - OS는 자기 자신과 여러 프로세스에 대해 최대한 효율적으로 메모리를 할당하고자 함
        - 이를 위해 OS는 가상 메모리 관리 기법을 사용
- 가상 메모리 공간 (Virtual Memory Space)
    - 각 프로세스는 자기 자신만의 독립되고, 고립된 (isolated) 메모리 공간을 가짐
        - 프로세스들은 서로 다른 사람의 space 를 건드릴 수 없음!
        - 공간의 크기는? 일반적으로 32 비트 주소 공간 (각 주소 마다 1B 저장: total 4GB = 2^32)
            - 64비트 프로세스의 경우, 48비트 혹은 56 비트만 사용 (256 TB = 2^48 or 64 PB = 2^56)

### Memory Allocation

- OS의 메모리 관리
    - OS는 해당 “가상” 메모리 공간에 대해 필요할 때만, 필요한 만큼만 실제 물리 메모리를 할당해 줌 (짠돌이)
    - 예) 호텔을 예약하는데, 일단 100개 객실이 있는 호텔을 통째로 다 빌려준다고 말함
        - 실제 객실은 100개일수도 있고, 200개 일수도 있고, 10개일수도 있음!
    - Private hotel~! You are our only guest!
        - 거짓말 이지만 진짜! 실제로 다른 손님과 절대 만나는 일이 없도록 관리해 줌
    - 딴 사람한테도 그렇게 예약해줌 (over-booking)
    - **실제로 손님이 왔을 때에, 실제 객실을 나눠 줌**
    - 만약 실제 객실 수보다 많이 오면?
        - 객실 손님이 자고 있을 때, 슬쩍 방 전체를 아주 아주 넓은 창고로 옮김 (Secondary storage)
        - 해당 객실에 새 손님을 받음
    - 창고 용량도 넘어가면??? OOM!! (Out-Of-Memory)
        - 호텔 문 닫고 다 내쫓음 (프로세스 강제 종료)
- 따라서 실제로 메모리 공간을 사용할 때는, OS에게 메모리 할당을 요청해야 함

- OS는 두 가지 방식으로 메모리 할당을 수행함: Static and Dynamic
- Static (정적 할당)
    - 프로그램이 수행되어 새로운 프로세스를 생성하는 과정에서 메모리를 할당하고, 해당 프로세스가 종료되기 이전까지는 할당이 해제되거나 내용이 변경되지 않음
    - 사용할 메모리 공간의 크기를 정하는 주체: 컴파일러
        - 프로그램이 실행되기 이전에 컴파일러에 의해 변수의 저장 공간 크기가 정해짐
    - 대상 자료 형태: 변수, 배열, 구조체로 선언된 자료들
        - 예) `int i`; 로 선언하고 나면, 실제 수행 중에 그 크기와 저장 위치를 변경하는 것은 불가능
    - 단점: 실행 이전에 사용할 메모리의 공간 크기가 정해진다는 건?
        - 예) struct friend list[10]; 카톡에서 친구 10명에 관한 구조체 데이터를 저장하기 위한 배열
        - 만약 10명 이상이면? → 소스 코드를 고치고, 새로 컴파일하고, 새로 수행해야 함
        - 넉넉하게 한 100만명 잡으면? → 실제 사용량에 비해 너무 많은 메모리를 할당해 비효율적
        - **메모리 사용량 예측이 부정확한 경우, 정보 저장에 실패하거나 메모리를 낭비하게 됨**

- **필요할 때, 필요한 만큼 메모리 공간을 할당하고, 필요없을 때는 해제하고 싶다!**
    - OS and neighbors: “Good!!”
- Dynamic (동적 할당)
    - 프로세스의 실행 중에 필요한 메모리를 할당하는 방법
        - CS에서 Dynamic 이란 용어는 “프로세스의 실행 중” 으로 해석하면 됨
    - 메모리 사용 예측이 정확하지 않고 실행 중에 메모리 할당이 필요할 때 사용
    - 예) 카톡 친구가 한 명 추가될 때 마다,
        - 해당 친구의 정보를 저장하기 위해,
        - 메모리 공간을 필요한 만큼만 추가로 할당받아 저장한다.
        - 그리고 친구 삭제하면 해당 공간을 할당 해제 (deallocation or free) 하여 OS에게 되돌려준다.
    - 단점: 사용이 (아주 약간) 불편함
        - 메모리를 매번 명시적으로 할당/해제 해야 함
            - 필요한 메모리 양을 계산하고, 시스템콜을 사용하여 OS에 요청
        - 포인터의 사용이 필요함
            - 새로 할당받은 메모리 공간을 지칭하기 위함
            - 포인터가 없는 언어에서도 동적 할당은 필수적이며, 다양한 형태로 지원 (예. Java의 ArrayList)

### 메모리 할당 영역

- Code (text)
    - 프로그램 코드가 복제�������어 실행에 사용
- Data
    - Global and static local variables
- Heap
    - 동적으로 할당받은 메모리가 위치함
    - 동적 메모리 할당의 요청/해제에 따라, 늘어나거나 줄어듦
- Stack
    - 함수 호출에 따라 동적으로 변경되는 부분
    - Function call 에 따라 스택이 쌓이면서 늘어나고, return 에 의해 다시 줄어듦
    - 지역 변수 (local variable), 함수 호출에 따른 인자 등이 저장됨
- Code and data: 프로세스가 실행될 때, 크기가 정해지고 변하지 않음
- Heap and stack: 프로세스의 수행에 따라 계속 크기가 변경됨

## Dynamic Memory Allocation

### 동적 메모리 관련 함수

- 동적 메모리
    - 함수 `malloc()`의 호출로 힙(heap) 영역에 확보
    - 메모리는 사용 후 함수 `free()`를 사용해 해제
    - 만일 메모리 해제를 하지 않으면, 메모리 부족과 같은 문제를 일으킬 수 있으니, 꼭 해제하는 습관을 가질 것

- 동적 메모리 할당 함수: `malloc()`, `calloc()`, `realloc()` 3가지
    - Return type: void *
        - Void 형: 특정한 형태가 없음을 뜻함
        - 메모리에 적재할 자료의 포인터 형으로 변환(casting)해서 사용
            - 예) `int *data = (int *) malloc(sizeof(int));`
    - 헤더파일 stdlib.h 필요
- 동적으로 할당된 메모리를 해제하여 반환
    - 함수 `free()`

| 메모리 | 함수 원형 | 기능 |
|---|---|---|
| 메모리 할당 (기본값 없이) | void * malloc(size_t) | 인자만큼의 메모리 할당 후 기본 주소 반환 |
| 메모리 할당 (기본값 0으로) | void * calloc(size_t, size_t) | 뒤 인자 만큼의 메모리 크기로 앞 인자 수 만큼 할당 후 기본 주소 반환 |
| 기존 메모리 변경 (이전값 그대로) | void * realloc(void *, size_t) | 앞 인자의 메모리를 뒤 인자 크기로 변경 후, 기본 주소 반환 |
| 메모리 해제 | void free(void *) | 인자를 기본 주소로 갖는 메모리 해제 |

### 메모리 할당: malloc()

```cpp
int *pi = (int *)malloc(sizeof(int));
*pi = 3;
```

- 할당 이후, 간접연산자 *pi를 이용하여 원하는 값을 수정 가능
    - 이때 `malloc()`으로 할당받은 메모리 공간에 적재된 값이 변경되는 것
- pi를 다른 메모리 공간의 주소로 수정 가능
    - 기존 메모리 공간은?
    - 해당 주소를 알아야 `free()` 를 할 수 있으므로, 이렇게 유실되는 경우가 없어야 함

### 메모리 해제: free()
```cpp
free(pi);
```

- free(pi)
    - 함수 malloc()의 반환 주소를 저장한 변수 pi를 해제
        - 인자로 해제할 메모리 공간의 주소값을 갖는 포인터를 이용하여 호출
    - 변수 pi가 가리키는 4바이트의 자료값이 해제되어 더 이상 사용할 수 없음

### 메모리 할당: calloc()

```cpp
int *ary = NULL;
ary = (int *)calloc(3, sizeof(int));
```

- 할당받은 공간을 0으로 초기화해줌
    - 기존 공간에 저장된 쓰레기 값으로 인한 예측하지 못한 문제를 예방
- 인터페이스의 변경
    - 마치 고수준 I/O 의 `fread()`/`fwrite()` 처럼,
    - (자료의 개수, 자료 크기) 로 구성되어, 조금 더 편리한 인터페이스 제공
    - 예) `malloc()` 에서는 그냥 3 * `sizeof(int)` 로 전달

### 메모리 할당: realloc()
```cpp
int *reary, *cary;
cary = (int *)calloc(3, sizeof(int));
reary = (int *)realloc(cary, 4*sizeof(int));
```

- 이미 확보한 저장공간을 새로운 크기로 변경
    - 함수 realloc()에 의하여 다시 확보하는 영역
        - 기존의 영역을 이용하여 그 저장 공간을 변경하는 것이 원칙
            - 새로운 영역을 다시 할당하여 이전의 값을 복사할 수도 있음
        - 성공적으로 메모리를 할당하면 변경된 저장공간의 시작 주소를 반환
            - 실패하면 NULL을 반환
        - 인자
            - 첫 인자: 변경할 저장공간의 주소
                - NULL 을 주면, 그냥 malloc()과 동일하게 동작
            - 두 번째 인자: 변경하고 싶은 저장공간의 총 크기

### Useful C macros for debug messages
- `__FILE__`
    - 소스 파일 명을 출력
    - 컴파일러에 전달된 파일 이름에 따라, 절대 경로가 출력될 수 있음
- `__LINE__`
    - 현재 라인 번호를 출력
- `__func__`
    - 함수 이름을 출력
    - `__FUNCTION__` 이라는 동일한 기능의 매크로도 있으나, C 표준이 아니고, 몇몇 컴파일러에서 지원 (`__func__`는 C99)

---

- 10日

# AWS Network Service

## 네트워크 사전 지식

- IP
- Inbound/Outbound traffic (ingress/egress)
- Subnet
- CIDR (Classless Inter-Domain Routing)
- Routing
- DNS
- VPN, NAT

### Addressing: MAC

네트워크 세그먼트의 데이터 링크 계층에서 통신을 위한 네트워크 인터페이스에 할당된 고유 식별자로 주로 네트워크 주소로 사용됨

![image](https://user-images.githubusercontent.com/59367782/98638656-0065a180-236d-11eb-80f8-d1bcd5895d3e.png)


### Addressing: IP

네트워크와 노드의 주소를 표현한 방법 중 하나로, 전 세계를 연결해준 인터넷의 프로토콜이다.

![image](https://user-images.githubusercontent.com/59367782/98639301-2a1ec880-236d-11eb-915f-181eeb689e81.png)


### Routing

라우팅 알고리즘의 목적은 패킷을 어디로 보낼지 결정하는 것이다. 각자가 분산된 독립적인 형태로 이루어져있다. 

hop을 계산하여 보낼 수 있는 네트워크를 테이블화하여 라우팅 테이블을 작성한다. 라우팅 테이블은 네트워크의 주소와 hop을 매핑하여 작성된다. 이러한 테이블을 일정한 주기로 알려줘서 자신들이 패킷을 어디로 보낼 수 있는지 알 수 있다.

- Routed Protocol: IP, IPX, Apple Talk
- Routing Protocol: RIP, IGRP, EIGRP, OSPF, IS-IS, BGP, DBMPR, MOSPF, PIM Desne & Sparse

### OSI 7 Layers

![image](https://user-images.githubusercontent.com/59367782/98644376-b9c77580-2373-11eb-98e4-190faabba88f.png)

레이어에 따라서 패킷에 헤더를 추가하거나 줄이는 식으로 패킷을 전송한다.

![image](https://user-images.githubusercontent.com/59367782/98646491-cef1d380-2376-11eb-9191-d85260e8b9fc.png)

### Network Class

![image](https://user-images.githubusercontent.com/59367782/98646582-eb8e0b80-2376-11eb-85db-7fd840ea3a19.png)

- 필요성: IP를 분할하여 각 기관 별로 배분하기 위함.
- 단점
    - C클래스는 너무 작고, B클래스는 너무 크다 -> IP 주소의 낭비
    - 예) 전북대 직원은 2000명 내외. B클래스를 할당하면? 6만개 이상 IP는 낭비됨

### Subnet

![image](https://user-images.githubusercontent.com/59367782/98646714-1a0be680-2377-11eb-9167-f6ad46979a98.png)

- 서브넷: 각 클래스 내에서 다시 네트워크를 분할하는 단위
- 필요성: IP 할당의 낭비를 막고, 네트워크를 서로 구분해주기 위함
- 장점: 주소 절약, 라우팅 테이블 크기 감소
- 단점: 복잡하다.

### CIDR: Classless Inter-Domain Routing

- 비트 단위의 IP 주소 표준 분할 방식
    - “Class 로 나눈 것 부터가 잘못!”
    - 클래스 없이, IP 주소를 원하는 대로 분할할 수 있게 하자.

![image](https://user-images.githubusercontent.com/59367782/98646881-622b0900-2377-11eb-98df-7f4f0969cc07.png)

---

# SMTP and FTP

SMTP: Simple Mail Transfer Protocol  
FTP: File Transfer Protocol

## Electronic Mail

### User Agent

![image](https://user-images.githubusercontent.com/59367782/98677871-02e1ee80-23a1-11eb-9955-0f625b5cdfb5.png)

### MIME (Multipurpose Internet Mail Extensions)

- SMTP는 오직 7-bit ASCII 형식만 전송 가능
    - Extended(혹은 Enhanced) SMTP는 8bit도 가능하지만, 호환성 문제
    - 초기에 e-mail은 text만을 생각하기 때문

- 7-bit로 표현하지 못하는 데이터를 전송을 하기 위해 MIME이 생겨남
    - 한국어, 중국어, 프랑스어 등
    - 비디오나 오디오 데이터 등

- MIME은 SMTP를 대치하는 것이 아니라 보완하기 위함

![image](https://user-images.githubusercontent.com/59367782/98678980-aed80980-23a2-11eb-8752-7f1e0b62be17.png)

```
Email Header
---
MIME-Version: 1.1
Content-Type: type/subtype
Content-Transfer-Encoding: encoding type - 7bit 변경 방법
Content-id: message id
Content-Description: textual explanation of nontextual contents
---
Email body
```

MIME이 EMail이 아닌 다른 곳에서도 쓰일 수 있으므로, encoding-type을 `7Bit`나 `Base64`, `Quoted-printable`을 사용해야 한다.

### Base64

![image](https://user-images.githubusercontent.com/59367782/98679677-b9df6980-23a3-11eb-8bd2-8cbf3caafa92.png)

결과적으로 24비트가 32비트로 변환된다. 즉, 32/24 = 1.33이므로 33% 오버헤드가 발생한다.

4bit -> 6bit로 바꾸기 때문에 64개의 매핑 테이블이 생긴다. 이 갯수 때문에 Base64라고 불린다.

### Quoted-printable

Non-ASCII 데이터, 즉 상위 비트가 1인 바이트만 3바이트로 변환한다. (`=`, 16진수 값의 ASCII 값)

![image](https://user-images.githubusercontent.com/59367782/98679972-1b9fd380-23a4-11eb-8d2b-311698d14f03.png)

Non-ASCII를 보면 상위 비트가 1이므로 16진수로 표현하면 `9D`이다.

![image](https://user-images.githubusercontent.com/59367782/98680057-3a05cf00-23a4-11eb-8c2d-d4eb5ed83b99.png)

전체 데이터 중 Non-ASCII **데이터의 비율이 작을 때** Base64 encoding보다 **효율적**이다.

### E-mail 전달

- E-mail의 실제 전달은 MTA(Mail Transfer Agent)가 맡음
    - 예: UNIX의 경우 sendmail daemon 프로그램
    - 메일을 보내기 위해서는 MTA client가 필요
    - 메일을 수신하기 위해서는 MTA server가 필요
    - MTA client와 MTA server는 SMTP 사용

### Commands and responses

![image](https://user-images.githubusercontent.com/59367782/98680546-e5af1f00-23a4-11eb-9ebf-1d72122e5ed2.png)

예시 : telnet www.example.com port: 25
- MTA server 포트는 25번
- telnet을 이용하여 25번 포트에 TCP 연결
- 키보드로 치는 것을 전송
- telnet에서 ctrl-d를 누르면 TCP 종료

```
S: 220 www.example.com ESMTP Postfix - 서버응답
C: HELO mydomain.com
S: 250 Hello mydomain.com
C: MAIL FROM:<sencder@mydomain.com> - Client
S: 250 OK
C: RCPT TO:<friend@example.com>
S: 250 OK
C: DATA
S: 354 End data with <CR><LF>.<CR><LF>
C: Subject: test message
C: From: sender@mydomain.com
C: To: friend@example.com
C:
C: Hello,
C: This is a test.
C: Goodbye.
C: .
S: 250 OK: queued as 12345
C: QUIT
S: 221 Bye
```

### MTA client and server

A -> B 방향으로 메일을 보내면 ?

```
SMTP   | SMTP    SMTP    |                  |  SMTP     |   Mail Access Protocol (※No SMTP※)
client | server  client  |                  |  server   |   IMAP, POP3
A -> Mail Server ------> Internet ------> Mail server -> B
```

![image](https://user-images.githubusercontent.com/59367782/98681793-7cc8a680-23a6-11eb-8b0e-88fd37c4659a.png)

### Mail Access Protocols

- POP3 (Post Office Protocol version 3)
    - Text로 이뤄짐
- IMAP4 (Internet Mail Access Protocol version 4)
- Web-based Mail
    - naver나 Gmail 등
    - 웹 브라우져 (IE, netscape)로 HTTP를 이용
        - sending mail server에서 receiving mail server까지는 SMTP 사용

## File Transfer

FTP는 TCP를 사용하며 **2개의 TCP 연결**을 갖는다. Port 21를 이용한 제어를 위한 연결, Port 20을 이용하여 데이터를 전송하고 받는다.

ASCII를 이용하여 TCP 연결은 한 뒤 데이터를 전송하기 때문에 구현은 어렵지 않지만 User Interface에 따라 달라지게 된다. 

### Using the control connection

![image](https://user-images.githubusercontent.com/59367782/98682938-d54c7380-23a7-11eb-9121-cef80001f9d2.png)


port 20을 사용한 TCP 연결에서 200 ok를 받게 되면 데이터를 전송한다.

![image](https://user-images.githubusercontent.com/59367782/98683006-e72e1680-23a7-11eb-99a6-07c97d5e2363.png)

anonymous를 지원하므로 연결 상대가 허용하면 익명으로도 연결할 수 있다. 또한, **컨트롤 채널**로 **데이터를 주고 받는 방식**인 것을 기억하자.

---

- 11日

# GitHub: Features

## Project

### Kanban

- Agile SW 개발 방법의 또다른 형태
    - 연속적 흐름 처리 방식
    - 특징 1: 개발 프로세스를 칸반 보드로 시각화
        - 단계별 섹션을 만들고 현재 진행 상황을 작업 카드를 이동하여 표시
    - 특징 2: 단순성
        - 한 번에 진행하는 일의 수를 제한, 데드라인 없음, 별도 관리자 없음

![image](https://user-images.githubusercontent.com/59367782/98765072-96a6cf80-2420-11eb-836a-5bdefe7de95d.png)

- Vs. 스크럼
    - 스프린트 기반: 작업 시간을 추정하고, 할당된 작업시간으로 제한함
        - 아주 익숙하고 반복되는 작업이 아닌 경우, 작업 시간의 추정이 어려움
        - 각 개발자가 동시에 처리하는 작업에 대한 제어가 어려움
        - 스크럼 마스터, 스프린트 회의 등 부가적 요소가 많음

- 칸반: 동시에 처리할 수 있는 이슈의 수를 제한하여 생산성을 향상
    - Work-In-Process(WIP) 개수를 제한
        - 예) 개발자는 한 번에 하나의 일만 처리
    - 작업 데드라인이 없음
        - 데드라인을 지키기 위해 SW 품질을 떨어뜨리거나 단계를 건너뛰지 않음
    - 별도의 회의, 특별한 직책을 두지 않음
        - 오버헤드 감소

- 칸반 방식의 단점
    - 데드라인이 없다 → 생산성을 최대화하기 어려움
    - 프로젝트의 시작/종료에 따른 회의 없음 → 새로운 아이디어에 대한 논의, 프로젝트 진행에 대한 피드백 등을 충분히 논의하기 어려움
    - **완전한 솔루션은 없다**. 각 팀의 상황에 맞게 보완해서 사용할 것.

- 칸반 사용 후기
    - [칸반(Kanban) 5개월 사용 후기 by 이태희](https://brunch.co.kr/@bradlee/4)
    - [[번역] 잘 가요 스크럼, 반가워요 칸반 by Alex Salazar](https://pitzcarraldo.medium.com/%EB%B2%88%EC%97%AD-%EC%9E%98-%EA%B0%80%EC%9A%94-%EC%8A%A4%ED%81%AC%EB%9F%BC-%EB%B0%98%EA%B0%80%EC%9B%8C%EC%9A%94-%EC%B9%B8%EB%B0%98-e27d1db15699)

### Trello

- Kanban 기반의 스케줄, 프로젝트 관리 도구
    - Kanban board 서비스로 출발, 그러나 Kanban 이라는 것을 더 이상 강조하지 않음
    - 단순한 카드 배열, 이동을 지원하는 플랫폼이므로 자유롭게 활용할 수 있음
        - 개인 스케줄 관리, 메모장, 여행 일정 관리, 강의 일정 관리 등등
- 특징
    - 매우 간단하여 사용이 쉬움
    - 직관적이라 전체 현황 파악에 편리함
    - 단점
        - 모바일 앱의 기능이 웹 서비스보다 약간 제한적
        - 한글 지원

### Github Automention

Issue를 생성시 자동으로 프로젝트 To-do 섹션에 추가되는 기능

## Issue

### 이슈 관리

- 이슈
    - 프로젝트 진행에서 발생하는 모든 이벤트, 진행 과정을 관리
    - 모든 것은 이슈로 정리하고,
    - 이슈를 적절한 인력에 할당하여,
    - 이슈를 해결함으로써 프로젝트가 진행됨
- 이슈의 기본 관리
    - **Open -> Assign -> Review -> Merge -> Closed**
        - **Review**는 필요한 경우
        - **Merge**는 코드에 변화가 있는 이슈인 경우
- 이슈 관리를 위한 추가 기능
    - 레이블, 마일스톤

## Wiki

### 위키 페이지

- 정의 및 활용
    - 불특정 다수가 협업을 통해 내용과 구조를 수정하는 웹페이지
    - 많은 공개 SW 프로젝트에서 Documentation 작성을 위해 사용
- 형식
    - Mark-up language 이용 (e.g. html)
    - Rich text editor 이용
- *《위키 방식: 웹 상의 빠른 협업(The Wiki Way: Quick Collaboration on the Web)》*
    - 사이트를 방문한 누구나 위키 웹사이트 내의 문서를 고치거나 새로 만들 수 있다. 이를 위해 기본적인 웹브라우저만 있으면 되며, 추가적인 확장 기능을 요구하지 않는다.
    - 연결된 문서가 다른 문서 사이를 쉽고 직관적으로 링크할 수 있어, 관련된 주제의 연결을 돕는다.
    - 위키는 가벼운 방문자를 위해 잘 만들어진 사이트가 아니다. 하지만, 지속적으로 웹사이트의 풍경을 변화시켜 방문자가 그 변화와 협력의 지속적인 과정에 참여하도록 한다.

- GitHub 위키
    - Markdown 마크업언어 사용: 간단한 문법, but 표준이 없음
    - **Readme.md**: GitHub repo 에 처음 만들어지는 Markdown 파일.
        - 프로젝트 소개 용도로 활용

## Releases

- 특정 커밋의 소스 코드를 버전을 붙여 배포
- Tag를 붙여 관련 정보를 입력

---

- 12日

# AWS Network Services: VPC, ELB, Route 53

## AWS Network Servcies

- Amazon VPC : Virtual Private Cloud로 자체 프라이빗 가상 네트워크를 통해 클라우드 리소스를 격리

- Elastic Load Balancing : Load Balancing을 클라우드에서 여러 Amazon EC2 인스턴스 전체에 애플리케이션 트래픽을 자동으로 분산

- Amazon Route 53 : Domain Name Service(DNS) 서비스로, 사용자 요청을 AWS 리소스로 연결할 수 있는 가용성과 확장성이 뛰어난 클라우드 DNS

- AWS Direct Connect : AWS로의 전용 네트워크 연결한다. 사용자 네트워크와 Amazon VPC 간의 전용 네트워크 연결

### AWS Direct Connect 

- 사용자 서버에서 AWS로 전용 네트워크 연결을 설정
    - AWS와 사용자의 데이터 센터, 사무실, 또는 코로케이션 환경 사이에 프라이빗 연결을 설정
        - 인터넷 연결이 아님
    - 네트워크 비용을 줄이고, 대역폭 처리량을 향상하며, 인터넷 기반 연결보다 일관된 네트워크 경험을 제공
    - 사용자 서버에서 AWS 프라이빗 리소스에 액세스 가능
        - 예: 프라이빗 IP 공간을 사용하는 Amazon Virtual Private Cloud(VPC)에서 실행되고 있는 Amazon EC2 인스턴스


### AWS Direct Connect Pricing

- 포트 요금 + 데이터 송신 요금

![image](https://user-images.githubusercontent.com/59367782/98939980-9ea06580-252d-11eb-8216-7605b05ab505.png)

- 참고자료
    - [AWS VPC 소개](https://aws.amazon.com/ko/vpc/?hp=tile&so-exp=below)
    - [AWS VPC 시작하기](https://aws.amazon.com/ko/vpc/?hp=tile&so-exp=below)
    - [VPC Deep Dive (김상필 AWS solutions architect)](https://www.slideshare.net/awskorea/vpc-deep-dive?from_action=save)

## AWS VPC (Virtual Private Cloud)

### Network

- Cloud network service
    - 사용자의 가상 컴퓨팅 자원 간의 가상 네트워크를 구성하는 서비스
    - 기본: IP 주소 범위, 서브넷, 라우팅, 게이트웨이 구성 등
    - 확장: VPN, NAT 등
- AWS Network
    - Private: AWS 내부에서만 사용 가능한 주소
        - 집 공유기에 연결된 내 노트북 IP (192.168.0.22)
- Public: AWS 외부에서 연결 가능한 주소
    - 내 노트북으로 port forwarding 을 설정해 외부에서 접속하도록 한 경우
    - 외부 -> 공유기 (114.72.x.x / 192.168.0.1) -> 노트북 (114.72.x.x / 192.168.0.22)

### VPC

- VPC 서비스
    - Amazon Web Services(AWS) 클라우드에 논리적으로 격리된 **가상 네트워크를 정의**하고, 그 내부에 AWS 리소스를 배치, 사용할 수 있음
    - (Virtual IDC: __Internet Data Center__ 라고 생각할 수 있음)
- 기능
    - IP 주소 범위 선택, 서브넷 생성, 라우팅 테이블 및 네트워크 게이트웨이 구성 등 가상 네트워킹 환경을 제어
    - IPv4, v6 지원
    - 보안 기능 제공 (filtering, access control, h/w isolation)
- 비용: 무료
    - VPN, NAT 서비스 유료
    - [AWS 비용 참고](https://aws.amazon.com/ko/vpc/pricing)

### VPC를 이용한 네트워크 구성 예

![image](https://user-images.githubusercontent.com/59367782/98940812-e5db2600-252e-11eb-8415-b57dfdd87eee.png)

- 간단한 공용 웹 사이트 호스팅
    - 블로그 또는 간단한 웹 사이트와 같은 기본 웹 애플리케이션을 VPC에 호스팅
    - 웹 서버가 인터넷의 인바운드 HTTP 및 SSL 요청에 응답하도록 허용
    - 동시에 웹 서버가 인터넷에 대한 아웃바운드 연결을 시작하지 못하도록 하는 보안 그룹 규칙을 만들어 웹 사이트를 보호
        - 타 서버로 능동적으로 접근하지 못하게 하여 DDoS 등에 좀비 PC로 이용되는 것을 방지함

- 다중 계층 웹 애플리케이션 호스팅
    - 웹 서버, 애플리케이션 서버 및 데이터베이스 간에 액세스 및 보안 제한을 엄격하게 적용
    - 2개의 서브넷: 공개적으로 액세스할 수 있는 서브넷과 비공개로 액세스할 수 있는 서브넷
        - Public subnet: 웹 서버
        - Private subnet: 어플리케이션 서버, DB
            - Outbound access: NAT 게이트웨이 사용 (management console, update 등)
- 서버와 서브넷 사이의 액세스를 제어
    - 웹 서버가 (혹은 웹 서버만) App 서버 및 DB를 정상적으로 사용하도록,
    - 네트워크 액세스 제어 목록과 보안 그룹에서 제공하는 인바운드 및 아웃바운드 패킷 필터링을 사용

---

- 13日

# 소프트웨어공학: 인터넷쇼핑몰 유스케이스(Use Case)

## 이해관계자

- 소프트웨어를 개발하며 고객의 요구를 만족시키는 시스템을 만들기 위해 고객의 요구사항을 알아내는 것은 시스템을 개발하는 관리자와 실무자에게 중요한 일이며 가장 큰 도전이다.
- 요구사항 분석의 오류를 줄이기 위해 프로젝트 초기인 요구사항 분석 단계에서부터 다양한 이해관계자를 프로젝트 개발 과정에 참여시키는 것이 중요하다.
- 이해관계자는 **프로젝트 결과에 직간접으로 영향을 미치는 개인이나 그룹을 의미**하며, 프로젝트를 발주한 고객이나 실제 사용할 사용자, 개발팀 등이 있다.
- 이해관계자의 활발한 참여는 잘못된 요구사항을 밝혀내고 중요 요구사항 누락을 방지하는데 필수적이다.

### 고객(사용자)

- 고객 또는 프로젝트의 결과물을 사용할 사용자는 프로젝트의 이해관계자 중 가장 중요한 부류
- 이들의 참여를 통해 시스템을 사용할 사람들이 누구(user analysis)이고 어떤 역할(role)을 담당하며 그 역할을 위해 어떤 업무(task analysis)를 수행하는지 이해하게 된다.
- 이는 요구사항 분석의 출발점이자 프로젝틀르 이해하는 가장 핵심적인 사항
- 고객이나 사용자들이 자신의 역할과 임무를 효율적으로 수행하기 위해 요구되는 소프트웨어의 기능이 무엇인지 파악된다면 사용자의 개발할 시스템에 대한 목표를 파악한 것으로 볼 수 있다.

## 유스케이스 기법 개요

- 외부 사용자(external entity)를 찾아낸다. 사용자를 역할에 따라 동질성 있는 집단으로 분류하여 이를 행위자 또는 액터라고 부른다.
- 각 행위자는 시스템에 대하여 각기 다른 관점(view)과 용도를 가진다.
- 각 행위자의 시스템에 대한 용도라 할 수 있는 유스케이스를 식별한다.
- 각 유스케이스에 대하여 시나리오를 작성한다. 시나리오는 사건의 흐름과 과정을 나타내며 시스템과 행위자들이 주고 받는 정보뿐만 아니라 상호 작용이 발생하는 상황, 환경, 배경 등을 포함할 수 있다.

### 유스케이스 활용

- 유스케이스 기법은 사용자의 요구사항을 검증하는데 활용
- 시스템의 기능적인 요구를 결정하고 기술하여 시스템 개발자와 고객 사이의 합의를 도출할 수 있도록 도움
- 사용자의 관점에서 시스템의 요구사항을 제공하며 시스템의 범위를 나타내줘 일정과 예산을 추정하는데 도움을 줌
- 요구사항을 추적 가능하여 시스템 개발 후 인수 시험의 기초를 제공
- 유스케이스는 하나의 **공통적인 사용자 요구와 관련된 시나리오**들의 시스템과 사용자간에 주고받는 정보나 이벤트 등이 상세히 기술되어 있으며 이것을 바탕으로 시스템을 테스트 할 수 있어야함

### 유스케이스 다이어그램

- 유스케이스 : 시스템에 존재하는 어휘는 아무거나 상관없으나, 간단하게 짓는다.
- 행위자 : 사람의 형태로, 시스템을 사용하는 사람이지만 하드웨어나 행위자가 될 수도 있다. 여러 행위자들 사이에 공통된 속성이나 역할이 존재한다면 **일반화** 관계를 사용할 수 있다.
- 일반화 관계 : 유스케이스 사이의 일반화 관계는 기본적인 목표가 같지만 구체적인 수행 방법이 나뉘어지는 경우 사용되는 방법으로, 예를 들어 결제는 신용카드, 계좌이체, 무통장입금으로 나뉘는 경우를 들 수 있다.
- 포함관계 : 하나의 유스케이스를 실행할 때 다른 유스케이스의 행동을 포함하는 관계를 말한다. 예를 들어 회원정보를 수정하거나 비밀번호를 변경할 때 로그인이 먼저 선행되어야 한다는 것이다.
- 확장관계 : 특정한 조건에서 다른 유스케이스의 행동을 확장하는 관계이다. 기본 유스케이스는 단독으로 수행되다가 특정한 조건이 되면 확장 유스케이스로 변할 수 있다. 확장점을 표시하지 않아도 문법적으론 오류가 없지만 명시하는게 좋다. 화살표 방향은 **확장 유스케이스 -> 기본 유스케이스**이다.

### 유스케이스 시나리오

- 유스케이스 다이어그램을 완성한 다음 식별된 유스케이스들별로 유스케이스 시나리오를 작성한다
- 유스케이스 시나리오에 대한 표준은 없으나 유스케이스 시나리오에는 일반적으로 유스케이스 이름 및 개요, 유스케이스를 수행하는 행위자, 선행 및 후행조건, 유스케이스의 이벤트 흐름이 포함된다.
- 유스케이스 시나리오를 작성할 때에는 시스템이 무엇을 하는가에 대한 설명에 집중
- 시나리오를 자세하게 작성하는 것은 좋지만 고객이 이해할 수 있는 수준으로 작성하는 것이 중요
- 시스템이 해당 유스케이스를 수행하기 위한 방법과 같은 구현 방법에 대해서는 설명하지 않도록 한다.

### 유스케이스 시나리오 작성

- 유스케이스 다이어그램이 완성되면, 각각의 유스케이스에 대해 유스케이스 시나리오를 작성한다.
- 유스케이스 시나리오에 일반적으로 포함되는 내용은 다음과 같다.
    - 유스케이스 이름
    - 유스케이스를 수행하는 행위자
    - 유스케이스 내용
    - 선행 및 후행조건
    - 이벤트 흐름(**기본흐름**, 예외흐름, 대안흐름)
        - 기본흐름은 모든 시나리오에 반드시 작성되어야 함
        - 예외흐름과 대안흐름은 상황에 따라 작성하지 않을 수 있다.
        - 각각의 이벤트의 흐름은 사건의 추적과 비슷하게 행위자와 시스템 사이의 이벤트를 중심으로 기술

- 유스케이스 시나리오 작성하면 시스템에 해당 기능을 수행하기 위해 어떤 절차를 거치고 어떤 과정에서 행위자와 시스템이 어떠한 정보를 주고 받는지 파악할 수 있다.

- 작성된 유스케이스 시나리오는 이후에 수행할 클래스 다이어그램이나 시퀀스 다이어그램을 작성하는데 사용되고 개발된 시스템이 요구사항을 만족하는지 테스트하기 위한 근거로 활용 가능
        

## 인터넷 쇼핑몰 유스케이스 모델링

- 인터넷 쇼핑몰 문제설명서

인터넷 쇼핑몰 시스템은 상품의 판매나 구입을 간편하게 하기 위한 시스템이다. 쇼핑몰 관리자는 인터넷 쇼핑몰에 상품을 등록해서 상품의 판매를 쉽게 진행할 수 있으며, 구매자 또한 인터넷 쇼핑몰에 등록된 상품들 중에서 구매하고자 하는 상품을 간편하게 구매할 수 있다.

인터넷 쇼핑몰을 사용하는 사용자는 일반 고객(비회원), 회원, 관리자로 나뉜다. 일반 고객은 상품 구매와 같은 기능을 수행하기 위해서 회원으로 가입할 수 있다. 관리자는 상품 관리(등록, 수정, 삭제)나 회원 관리(조회, 삭제), 카테고리 관리 등과 같은 활동을 수행한다.

상품에 대한 조회 및 검색은 쇼핑몰에 가입한 회원뿐만 아니라 가입하지 않은 비회원 및 관리자도 수행할 수 있다. 상품 조회는 특정 카테고리의 선택 과정을 통해 이루어지며, 상품검색은 특정 검색어의 입력을 통해 이루어진다. 관리자는 카테고리의 분류 체계를 관리하고, 상품을 특정 카테고리에 포함시켜 등록한다.

상품구매는 회원만 할 수 있고, 상품을 구매하기 위해서는 먼저 원하는 상품을 장바구니에 담고, 장바구니에 담긴 상품들 주엥서 선택적으로 주문할 수 있다. 상품 구매시 결제 수단은 온라인 입금과 신용카드 결제로 구분한다. 온라인 입금은 뱅킹 시스템을 통해서 입금 여부를 확인한 후 결제 처리하며, 신용카드 결제는 신용카드 인증화사로의 결제승인 서비스를 통해 즉시 처리가 가능하도록 한다.

![image](https://user-images.githubusercontent.com/59367782/99071270-1daca100-25f5-11eb-943d-5e1b2fdac80b.png)


### 카테고리 등록 유스케이스 시나리오

![image](https://user-images.githubusercontent.com/59367782/99071839-408b8500-25f6-11eb-9475-fe5f1e17b662.png)
- 예외흐름
    - E1. 등록하고자 하는 카테고리명이 이미 존재하는 경우
        - 카테고리명은 카테고리를 구별할 수 있는 정보로서 중복되어 저장될 수 없으므로, 시스템은 이미 동일한 이름의 카테고리가 존재한다는 메시지를 보여주고, 동일한 이름의 카테고리가 전체 카테고리 목록에서 어느 위치에 존재하는지 보여준다.

### 상품등록 시나리오

![image](https://user-images.githubusercontent.com/59367782/99072048-9e1fd180-25f6-11eb-8372-15936b223887.png)
![image](https://user-images.githubusercontent.com/59367782/99072011-89433e00-25f6-11eb-89ff-68d37bfb2c36.png)
- 예외흐름
    - E1. 신규 상품 등록 시 상품의 정보 중에 누락된 값이 하나라도 존재한느 경우
        - 누락된 값이 존재한다는 메시지를 보여주고, 누락된 값을 입력하도록 해당 텍스트 박스에 커서를 이동시킨다.
    - E2. 등록하고자 하는 상품명이 이미 존재하는 경우
        - 이미 동일한 상품명이 존재한다는 메시지를 보여주고 상품명 텍스트 박스에 커서를 이동시킨다. 입력한 정보는 그대로 유지시킨다.

## 유스케이스 모델링 완료

- 유스케이스 시나리오까지 작성되면 유스케이스 모델링이 완료됨
- 유스케이스는 사용자가 시스템을 활용할 때 나타나는 쓰임새 혹은 시스템이 사용자에게 제공하는 서비슬르 나타낸 것으로써, 행위자가 자신의 목적을 위해서 시스템에서 제공받는 가장 단순하고 직관적인 기능이다.
- 행위자가 시스템에서 요구하는 기능들이 유스케이스로 표현되기 때문에 유스케이스는 시스템의 최상위 요구사항이라고도 볼 수 있다.
- 유스케이스 모델링은 시스템을 블랙박스로 보고 사용자의 관점에서 시스템을 분석한 것
- 유스케이스 식별부터 유스케이스 시나리오 작성까지의 전 과정을 살펴보면 우선 유스케이스 식별은 시스템의 최사위 기능을 찾아내는 것응로서 초기 기능 모델링이 이루어진 것
- 유스케이스 시나리오는 행위자와 시스템 사이에 이루어지는 유스케이스의 진행 과정과 흐름을 나타낸 것으로서 시스템에 대한 동적 모델링을 수행한 것
- 또한 유스케이스 시나리오에는 이벤트 흐름과 함께 행위자와 시스템이 주고 받는 정보들이 함게 나타나게 되어, 시스템 내부에서 저장되고 관리되어야 하는 중요 정보들에 대한 초기 정보 모델링이 이루어진 것

---

# 소프트웨어공학: 인터넷 쇼핑몰 UML 모델링

### UML 프로세스

- 유스케이스 모델링은 시스템을 블랙박스로 보고 고객의 요구사항을 분석한 것
- 유스케이스 모델링의 결과를 바탕으로 시스템을 열어 시스템 내부의 모습을 분석하는 과정을 조사
- 유스케이스 시나리오를 통해 행위자와 시스템이 주고받는 정보들을 활용하여 시스템 내부에 저장되고 관리되어야 하는 정보를 밝히는 정보 모델링을 수행하고 그 결과를 클래스 다이어그램으로 나타낸다.
- 유스케이스 시나리오를 확장하여 시퀀스 다이어그램 작성
- 업무 프로세스 내의 상호 작용에 대한 추가적인 이해가 필요할 경우 액티비티 다이어그램을 작성할 수 있다.

## 클래스 다이어그램

- 클래스 다이어그램은 시스템의 정적인 정보구조를 나타내는 정보 모델로써, 시스템에 필요한 클래스들과 이들 사이의 관계를 나타내는데 사용된다.
- 각 클래스는 해당 객체의 특성을 나타내는 여러 가지 속성들과 오퍼레이션으로 구분된다.
- 클래스, 클래스의 속성, 클래스들 간의 관계를 찾아내기 위해서는 선행 단게에서 작성된 문서들을 활용할 수 있는데, 문제 기술서나 유스케이스 시나리오가 클래스 도출에 사용될 수 있다.

### 회원가입 유스케이스 시나리오

1. 개요
![image](https://user-images.githubusercontent.com/59367782/99076929-489bf280-25ff-11eb-92e8-64211d5d87a6.png)

- 예외 흐름
    - E1. 주민번호가 중복된 경우
        - 개인의 중복가입을 방지하기 위하여 주민번호의 중복을 허용하지 않는다. 따라서 입력된 주민번호가 존재하는 경우 기존에 가입된 회원의 주민번호라는 것을 알리고 승인하지 않는다.
    - E2. 회원ID가 중복된 경우
        - 회원ID는 시스템이 사용자 개개인을 구별하기 위한 정보로서 중복이 허용되지 않기 때문에, 시스템은 이미 동일한 회원ID가 사용되고 있다는 메시지를 보여주고 다른 ID를 입력하도록 해당 필드에 커서를 옮긴다.

### 인터넷 쇼핑몰 클래스 다이어그램

![image](https://user-images.githubusercontent.com/59367782/99077255-c9f38500-25ff-11eb-9906-7bf7a2a11ce7.png)


## 시퀀스 다이어그램

- 유스케이스 정적 분석 방법을 사용하여 시스템을 구성하는 클래스를 찾아내고 각 클래스의 속성, 클래슫르 사이의 관계를 규명
- 정적 분석의 결과를 토대로 유스케이스 동적 분석 방법을 수행하는 방법임
- **책임 기반의 방법**은 객체들 사이의 상호 작용을 통해 클래스의 오퍼레이션을 도출
- 한 객체가 다른 객체에게 어떤 기능의 수행을 요청하는 메시지를 보내면, 메시지를 받는 객체는 요청된 기능을 수행할 책임이 있다.
- 이 때 수행할 기능이 클래스의 오퍼레이션이 된다. 객체들의 상호 작용을 나타내기 위해 일반적으로 시퀀스 다이어그램을 사용한다.
- 시간의 흐름에 따라 객체들의 주고받는 메시지의 전달과정을 강조하는 것

1. 책임 기반 방법
    - 객체들 사이의 상호 작용을 통해 클래스의 오퍼레이션을 도출
2. 상태 기반 방법
    - 객체들은 생명주기동안 여러 상태에 놓일 수 있으며, 객체는 한 순간에 한 상태에 존재한다.
    - 다른 상태로 변하는 것을 전이(Transmission)라고 한다.
    - 전체 객체의 상태를 전이하는 자극을 사건(Event)라고 한다.
    - 객체들의 상태 전이 과정을 나타낸 모델이 상태 변화도, 상태 변화도에서 객체의 상태를 변화시키는 사건들이 클래스의 오퍼레이션이 될 가능성이 높다.
    - 상태변화도는 객체들 사이의 상호작용을 모델링하는 전 과정 중에서 추가로 객체의 상태전이과정을 작성
    - 동적 분석의 궁극적 목적은 각 객체의 상태변화도 작성
    - 이미 상태변화도가 존재하다고 가정하기 때문에 역공학인 측면이 강하다. 따라서 상태변화도에서 오퍼레이션을 도출할 수 있다.
3. 클래스 속성의 기반 방법
    - 도출된 오퍼레이션은 클래스의 속성을 조회하거나 설정할 수 있다.

### 상품목록조회 유스케이스 시나리오

1. 최상위 카테고리 목록이 사용자에게 보여진다.
2. 조회하고자 하는 카테고리를 선택한다.
3. 선택된 카테고리의 하위 카테고리들을 보여 준다.
4. 최하위 카테고리를 선택할 때까지 2~3번 흐름을 반복한다.
5. 선택된 최하위 카테고리에 포함된 상품들의 목록을 보여준다.
6. 화면에 나타난 상품목록들 중에서 원하는 상품을 선택해서 상품의 상세접오 화면으로 이동할 수 있다.

### 상품목록조회 사건추적도

![image](https://user-images.githubusercontent.com/59367782/99078305-8bf76080-2601-11eb-9e7f-713d1a15c013.png)


### 상품목록조회 시퀀스 다이어그램

![image](https://user-images.githubusercontent.com/59367782/99078256-6f5b2880-2601-11eb-8fa3-1253d2c03deb.png)

### 장바구니에 상품 담기 시퀀스 다이어그램

![image](https://user-images.githubusercontent.com/59367782/99078385-a7fb0200-2601-11eb-9355-e755a11c0145.png)

## 액티비티 다이어그램

- 액티비티 다이어그램은 클래스 내에서 이벤트를 처리하는 논리적인 과정을 정확히 이해하기 위해 사용되는 다이어그램
- 복잡한 프로세스의 처리과정을 이해하거나 클래스의 추가적인 오퍼레이션을 식별하는데 사용된다.
- 각 유스케이스에서 어떤 활동들이 일어나고 활동들간 어떠한 의존 관계가 존재하는지 이해하는데 도움을 줄 수 있다.
- 특정 객체가 가지는 오퍼레이션이 내부적으로 복잡한 구조로 이루어져있을 때 액티비티 다이어그램을 사용하여 표현할 수 있다.

### 장바구니상품담기 액티비티 다이어그램

![image](https://user-images.githubusercontent.com/59367782/99078545-e690bc80-2601-11eb-9452-4d16ca324831.png)

## UML의 V 프로세스

![image](https://user-images.githubusercontent.com/59367782/99078643-0fb14d00-2602-11eb-9138-c36ccbdbd0e5.png)

## 모델의 통합

- 동적 분석에서 작성한 시퀀스 다이어그램을 통해 얻어진 이벤트들은 클래스 다이어그램에 오퍼레이션으로 반영된다.
- 동적 분석의 결과로 도출된 오퍼레이션들이 정적 분석의 결과물인 클래스 다이어그램에 반영되면, 비로소 완전한 분석 단계의 클래스 다이어그램이 만들어진다.

---

# 소프트웨어공학: 소프트웨어 설계 기법

### 소프트웨어 설계 단계

계획 -> 요구사항 분석 -> __소프트웨어 디자인__ -> 구현 -> 테스팅 -> 운용과 관리

## 소프트웨어 설계 개요

- 시스템을 구현하기 위해 시스템을 여러 서브시스템으로 나누고 서브시스템의 요소를 하드웨어와 소프트웨어에 할당하는 것을 **시스템 설계**라 한다.
- 시스템 설계는 설계의 첫 단계로 시스템 전체의 구조를 결정하며, 구체적인 설계에 들어가기 전에 이루어진다.
- 소프트웨어 설계는 소프트웨어에 할당된 서브시스템을 설계하는 과정이다.
- 요구사항 분석은 응용 분야의 개념에 초점을 맞추지만, 소프트웨어 설  계 단계에서는 컴퓨터의 개념으로 초점이 이동
- 분석 단계에서 밝혀진 요구사항은 설계를 위한 골격을 제공하며 설계는 그 위에 살을 붙여가는 과정
- 요구사항을 해결하기 위해 최소한 한 가지의 해결 방안은 가지고 있어야 하며, 가능하면 여러 해결 방법을 찾아내고 그들을 평가하는 것이 필요
- 소프트웨어 설계자는 여러 해결 방법 중 수행 시간, 기억장치 및 다른 비용과 자원들을 최소화 할 수 있는 방법을 선택하게 된다.

## 소프트웨어 설계 활동

- 설계는 관리적인 관점에서 크게 두 단계로 나뉜다.
- 첫 번째 단계인 **기본 설계 단계**(Preliminary design)에서는 소프트웨어 시스템의 구조와 데이털르 규명하며 사용자 인터페이스를 정의한다.
- 그 이후에 이루어지는 상세 설계 단계에서는 각 모듈의 구체적인 알고리즘에 초점을 맞추게 된다.
- 기본 설계는 상위 설계라고 부르기도 한다. 기본 설계에서 상세 설계로 진행하며 시스템의 추상화의 수준을 낮춘다.
- 설계 과정이 진행될수록 명세서에 더 구체적인 내용이 추가되어 설계 과정의 최종 산출물은 시스템 구현을 위한 기초로 사용

### 설계의 기술적인 관점

- 설계는 기술적인 관점에서 크게 **4가지** 활동, 즉 *데이터 설계*, *구조 설계*, *프로시져 설계*, *사용자 인터페이스 설계*로 나눌 수 있다.
    - 데이터 설계: 요구사항 분석 단계의 정보 모델링에서 밝혀진 정보를 이용하여 자료 구조와 데이터베이스를 설계한다.
    - 구조 설계: 기능 모델링과 동적 모델링에 나타난 결과를 이용하여 프로글매 구조상에 있는 각 구성 요소(모듈)들 사이의 관계를 기술한다.
    - 프로시져 설계: 각 모듈의 내부가 구체적으로 밝혀지며 어떤 알고리즘을 사용할지 결정한다.
    - 사용자 인터페이스 설계: 사용자가 시스템의 기능에 접근할 수 있도록 하는 사용자 인터페이스를 설계한다.

### 설계 가이드라인

1. 설계는 소프트웨어 구성 요소들 사이에 효과적인 제어를 가능하게 하는 계층 구조를 가져야한다.
2. 설계는 논리적으로 분할되어 모듈화되어야 한다. 일반적으로 기능에 의한 모듈화가 이루어지며 설계는 모듈들 사이의 계층 구조를 보여준다.
3. 모듈들 사이, 또는 외부 환경과의 인터페이스가 최소화되도록 설계되어야 한다. 이는 모듈 내부의 응집도는 높아야하고, 모듈들 사이의 결합도와 인터페이스는 최소화될수 있도록 설계되어야 함을 의미한다.
4. 분석 과정에서 나타난 결과를 활용하여 설계가 이루어져야 한다. 설계는 요구사항 분석 과정의 연장선상에서 보아져야 하며, 요구사항을 실현하기 위해 분석의 결과에 살을 붙여나가는 과정이다.

### 설계의 관리적 관점

- 기본 설계는 설계에 대한 경험이 많은 엔지니어가 하는 것이 일반적이며, 기본 설계가 이루어지면 상세 설계는 각 개발자가 분담하여 수행한다.
- 기본 설계 단계에서 우선 고려될 수 있는 것이 데이터에 대한 설  계
- 기본 설계에서는 시스템이 필요한 정보(또는 객체)를 자료구조와 데이터베이스 설계에 반영
- 기본 설계 단계에서 사용자 인터페이스를 설계하는 것이 바람직
- 또한 기본 설계에서는 사용자의 요구사항을 만족시킬 수 있도록 시스템의 구조를 설정
- 일반적으로 상위레벨에서 시스템을 분할한 시스템 구성요소를 서브시스템이라 부름
- 서브시스템은 일반적으로 자료와 제어 구조를 포함하며 독립적으로 기능을 수행할 수 있고 컴파일될 수 있는 프로그램 구성요소를 일컫는다.
- 서브시스템은 어떠한 서비스를 제공하는가에 의해 구별되며, 서비스는 공통적인 목표를 제공하기 위해 필요로하는 기능들의 모임

## 설계의 고려 사항

- 소프트웨어 설계에 사용되는 기본 원리들이 있다. 소프트웨어 설계는 품질에 직접적인 영향을 미치며, 다음 단계인 구현, 시험 및 유지보수와 밀접한 관계를 가지고 있다.
- 컴퓨터 엔지니어(프로그래머)의 지혜는 작동하는 프로그램을 얻는 것과 올바르게 만드는 것의 차이점을 깨닫는 것에서 시작한다.
- 소프트웨어도 개발과 운용, 유지보수를 효과적으로 행하기 위해 구성 요소(모듈, 엔터티 등)들로 분할된다.
- 이들 요소들은 각기 서로 다른 기능을 수행하는 독립성을 가지고 있어야 한다.
- 분할에서 추구하는 중요한 원칙은 서로 연관되어 있는 부분들은 같은 구성요소에 있어야 하고, 연관이 없다면 연광성이 없는 구성요소들에 할당되어야 한다.

### 추상화

- 추상화는 엔지니어링 전 과정에서 이뤄지는 중요한 원리이다.
- 엔지니어링이란 추상화가 높은 단계에서 낮은 단계로 이동되는 과정
- 설계 과정에서도 높은 추상화 단계에서 낮은 추상화 단계로 나아가며, 이를 위해 단계적인 정재가 이뤄진다.
- 기본 설계에서 상세 설  계로 나아가면 추상화의 수준은 낮아지고, 원시코드가 생성될 때 추상화는 최하위의 수준이 된다.
- 설계 단계에서 흔히 쓰는 추상화들은 **제어 추상화**, **과정 추상화 및 데이터 추상화**가 있다.

### 추상화 예시

- 두 개의 변수 값 Swap

```
temp := value1;
value1 := value2;
value2 := temp;
```

순서적 제어 구조 추상화

`value1 <-> value2`

이러한 추상화 매커니즘은 상세한 순서적 제어 구조의 내부 정보를 감추었지만 설계 단계에서의 명세 수준으로는 충분하며 이를 이용해 다음 단계에서 쉽게 코딩할 수 있다.

- 순환 제어 구조

```
for (회사의 모든 사업부) do
...
end for
```

순환 제어구조를 추상화시키면 회사의 각 사업부에 접근하는 방법에 대해 언급하지 않아도 된다.

- 과정 추상화란 어떤 기능을 수행하는 과정을 추상화하는 것
    - `ax + by = c`
    - `a'x + b'y = c'`
    - solve_equation(equationtype equ)
- 데이터 추상화도 제어 추상화 또는 과정 추상화와 같이 상세정보를 감추는 것이다.

### 데이터 추상화를 이용한 스택

```cpp
const int MAXSIZE = 100;

class stack {
    private:
        char stack_value[MAXSIZE];
        int top;
    public:
        stack()top = 0;;
        void push(char);
        char pop();
        void push(char x) {
            if(top+1 == MAXSIZE)
                error("stack is full";
            else
                stack_value[++top] = x;
        }
        void pop() {
            if (top == 0) {
                error("stack is empty");
                return NULL;
            }
            else 
                return stack_value[top--];
        }
};

int main() {
    stack st;
    char x, y;
    st.push('a');
    st.push('b');
    x = st.pop();
    y = st.pop();
    cout << x << y << endl;
}
```

메인에서 스택에 접근할 때 push, pop 오퍼레이션을 통해서만 접근 가능하다.

---

- 14日

# 카카오 추천팀 인턴 코딩테스트 회고

카카오 추천팀 인턴 코딩테스트를 13:00 ~ 17:00 동안 치뤘다. 총 5 문제로, 해커랭크에서 진행되었다. 제일 당황스러웠던 점은 해커랭크에서 한다고 했을 때 알아차려야했으나, 전부 영어 문제였다. 4문제는 흔히 보는 코딩테스트 문제와 같았고 1문제는 rest api를 이용해 해결하는 문제였다.

아쉽게도 영어 문제라서 처음 시작하여 이해하는데 시간이 걸렸고, 이후엔 node로 get을 쓰기 위해 찾는 시간이 오래걸렸다. express를 이용한 axios 모듈을 이용할 생각이였지만 컴파일이 되지 않아서 다른 방법을 찾는데 오래 걸렸다. 이후에 request.js 모듈을 사용해서 코드를 짰지만 써보질 않았을 뿐더러, request로 비동기를 제대로 구현하지 못해서 오래 걸렸다. 한번의 get으로 설정 값과 첫 페이지를 불러온다. 이후에는 설정값을 토대로 다음 페이지를 탐색할지 체크를 한다. 마지막 페이지까지 다 훑으면서 조건에 맞는 기기들을 찾는 문제였다.

이번 년에 많은 코딩테스트를 겪어봤지만 역시 아직도 많은 경험이 부족하다고 생각이 된다. 바로 생각나지 않는 부분이 많고 구현하기 위한 부분에서 매우 부족하다고 생각된다. c++뿐 아니라 자바스크립트 또한 사용하는 방법을 익혀놔야 다음에 확실히 도움이 될 것 같다.

이후엔 비동기 부분을 새로 다시 공부하기 위해서 promise와 콜백 함수에 대해 공부했다.

- [자바스크립트 비동기 처리와 콜백 함수](https://joshua1988.github.io/web-development/javascript/javascript-asynchronous-operation/)
- [자바스크립트 Promise 쉽게 이해하기](https://joshua1988.github.io/web-development/javascript/promise-for-beginners/)

---

- 15日

# PS

- 후보키

```cpp
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool check_minimality(const vector<int> &keys, const int bit) {
    for (int i=0; i<keys.size(); i++) {
        if((keys[i] & bit) == keys[i]) {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> keys;
    int cnt = 0;
    int tupleSize = relation.size();
    int columnSize = relation[0].size();
    
    for (int bit=1; bit < (1 << columnSize); bit++) {
        if(!check_minimality(keys, bit))
            continue;
        unordered_set<string> s;
        
        for (int i=0; i<tupleSize; i++) {
            string key;
            for (int j=0; j<columnSize; j++) {
                if(bit & (1 << j)) {
                    key += relation[i][j] + ' ';
                }
            }
            s.insert(key);
        }
        
        if(s.size() == tupleSize) {
            keys.push_back(bit);
            cnt++;
        }
    }
    
    
    return cnt;
}
```

후보키에 해당하는 튜플을 찾아서 갯수를 반환하는 문제이다. 비트마스킹을 통해서 문제를 해결한 코드이다. 문제를 해결할 때 다른 방법으로 접근하였으나, 다른 블로그를 보고 참고한 코드이다. 처음에는 이해가 되지 않았지만 계속 코드를 살펴봄으로써 이해가 되었다. 

bit를 컬럼사이즈만큼 늘리면서 해당 비트값의 최소성을 체크하고 이후에 유일성을 체크하게 된다. set에 집어넣어 set의 사이즈가 튜플사이즈와 같다면 겹치는 튜플이 없다는 뜻이므로, 이 경우에 vector에 집어넣어서 관리를 한다. 이후에 bit를 이용한 for문에서 최소성을 체크할 때 vector의 값이 동일한게 있나 체크할 때 또 사용하게 된다.

이후에는 vector의 크기를 반환하면 정답을 얻을 수 있었다.

---

# 편집 거리 알고리즘

- [참고 블로그](https://hsp1116.tistory.com/41)

이번 카카오 추천팀 인턴 코딩테스트에서 나온 문제 중에 이 알고리즘을 사용해서 풀어야하는 문제가 있었다. 알고리즘에 대해 알지 못해서 너무 돌아간 느낌이라 공부하고자 한다.

LIS와 같이 DP를 사용하여 해결하는 알고리즘으로, 블로그를 통해 제대로 된 이해가 필요할 것 같다.

---

- 16日

# Github: Pull Request

## Pull Request

- 내 변경사항을 공식 저장소에 반영요청
    - 공식 저장소의 관리자(maintainer)가 나의 요청을 받아들이면?
        - Merge를 수행해 줌

- Pull Request 가 필요한 경우
    - 오픈소스 프로젝트의 소스를 고친 경우
        - 내가 변경한 소스가 다른 사람에게도 의미가 있는 경우 (개선, 버그수정 등)
- Collaborate project에서 merge 권한 관리를 하고 싶을 때
    - 예) master/release 브랜치로의 merge는 무조건 pull request를 사용하고, 팀장이 merge를 수행하기로 정함

### Pull Request 수행

- Collaborator 가 아닌 repository에 작업하는 방법
    - GitHub의 remote repository 를 fork해, 내 계정에 remote repository 생성
        - Fork: remote repository를 복제하는 명령
- 이를 clone 하여 local repository 에서 작업

---

# AWS Network Services: VPC, ELB, Route 53

## ELB (Elastic Load Balancing)

### ELB

- 들어오는 애플리케이션 트래픽을 자동으로 분산
    - 대상: Amazon EC2 인스턴스, 컨테이너, IP 주소 등
        - 단일 가용 영역 또는 여러 가용 영역에 분산 가능
    - 애플리케이션의 내결함성 보장
        - 고가용성, 자동 확장/축소, 보안
    - 세 가지 로드 밸런서 제공

### Application and Network Load Balancer

- 차이점: 각각 L7 과 L4 계층에서 동작
    - 프로토콜
        - ALB: HTTP, HTTPS
        - NLB: TCP
    - 성능
        - 더 낮은 계층에서 동작하므로 **ALB에 비해 NLB의 처리 성능이 높음**
- Classic LB
    - L4, L7 으로 명확히 구분하기 전, 통합된 형태로 서비스하였음
    - VPC 이전에 EC2-classic 이라 불리던 네트워크 서비스에서 사용됨
    - VPC 사용 시에는 더 이상 사용을 권장하지 않음

### ELB 특징

- 고가용성
    - 인스턴스의 상태를 주기적으로 점검하여, 정상 상태의 인스턴스에만 트래픽을 전달함

- 탄력성
    - Auto-scaling 과 통합 가능
    - ELB 자체도 scale out 을 수행하여, 부하에 탄력적으로 대응함

- 기타
    - 보안: 보안 그룹으로 제어 가능
    - 모니터링: CloudWatch 와 통합
    - Hybrid load balancing: 사용자의 로컬 on premise 리소스와 통합 가능

- ELB Scale-out
    - ELB는 인스턴스를 기반으로 제공되는 서비스
    - 인스턴스가 감당하지 못하는 수준의 트래픽이 몰리면, scale out 수행
        - 추가 인스턴스를 생성해 처리함
        - 생성까지 시간이 걸리므로 요청이 단기간에 급증하는 경우, 서비스 딜레이가 생길 수 있음

- MultiAZ 로 로드 밸런싱을 하는 경우
    - 각 AZ 별로 ELB 인스턴스가 생성됨
    - AZ별로 같은 비율로 트래픽이 분배됨
        - 따라서 각 AZ의 서비스 처리 성능은 유사하게 유지되어야 함

### ELB 요금

- Application Load Balancer
    - 실행된 시간 또는 부분 시간 그리고 시간당 사용된 로드 밸랜서 용량 단위(LCU)에 대해 요금이 부과된다.

- Network Load Balancer
    - 실행된 시간 또는 부분 시간 그리고 시간당 Network Load Balancer에서 사용된 로드 밸랜서 용량 단위(LCU)에 대해 요금이 부과된다.

- [AWS ELB 요금](https://aws.amazon.com/ko/elasticloadbalancing/pricing/)

---

- 17日

# 유닉스 : Dynamic Memory Allocation

## Linked List: Basic

### 연결 리스트

- 연결 리스트
    - 순차적 자료 표현에 적합한 구조
    - 동적으로 항목이 추가되고, 항목 간의 순서가 변경되는 데이터의 관리에 적합
- 배열과의 비교
    - 컴파일 시 배열의 크기가 이미 결정되어, 실행 중간에 배열 크기 수정이 불가능
    - 순서 변경의 어려움
        - 맨 앞이나 중간에 새로운 항목이 삽입되면?
            - 삽입되는 항목 이후의 이미 저장된 항목들을 모두 뒤로 이동?
            - 많은 양의 데이터 복사로 수행 속도 저하
        - 중간에 하나 삭제하는 경우도 마찬가지

### 연결 리스트 구조

- 연결 리스트 기본 구조
    - 헤드에서 시작하여 가리키는 곳을 계속 따라가면 순차적 자료를 표현
- 연결 리스트 예
    - 헤드(head)는 “미수”를 가리키고
        - “미수”는 다시 “현순”을 가리키고
            - 계속해서 “윤원”, “현화”, “수성”, “나혜”
            - 그리고 다시 나혜는 마지막이라 가리키는 사람이 없는 것(NULL)과 같은 구조

![image](https://user-images.githubusercontent.com/59367782/99241795-b0418000-2841-11eb-86d4-428bd831b129.png)

### 연결 리스트 구조: 노드

- 연결 리스트 내의 각 항목은 “Node” 라는 형태로 구성
- 노드의 자료: 필요한 여러 변수의 조합으로 구성
    - 노드 간의 링크: **자기 참조 구조체의 포인터로 구현**
- Head : 항상 첫 번째 노드를 가리키는 포인터
- Tail : 마지막 노드를 가리키는 포인터

### 연결 리스트 구조: 자기 참조 구조체

- 자기참조 구조체(self reference struct)
    - 구조체의 멤버 중의 하나가 자기 자신의 구조체 포인터 변수를 갖는 구조체

```cpp
struct selfref {
    int n;
    struct selfref *next;
}
```

- 구조체 selfref
    - 멤버로 int 형 n과 struct selfref * 형 next로 구성
        - 즉, 멤버 next의 자료형은 지금 정의하고 있는 구조체의 포인터 형
    - 구조체 selfref는 자기 참조 구조체
        - 구조체의 멤버 중의 하나가 자기 자신의 구조체 포인터 변수
    - 구조체는 자기 자신 포인터를 멤버로 사용할 수 있으나
        - 자기 자신은 멤버로 사용 불가능: 재귀적 참조로 인해 크기를 결정할 수 없음

### 연결 리스트의 장단점

- 연결 리스트 장점
    - 항목 수를 프로그램 내부에서 메모리가 허용하는 한 늘릴 수 있다는 것
        - 배열과는 달리 프로그램 실행 전에 미리 기억장소를 확보해 둘 필요가 없음
    - 프로그램 실행 중이라도 필요할 때 노드를 동적으로 생성
        - 기존의 연결 리스트에 삽입 또는 추가 가능
    - 항목 들이 메모리 공간에 연속적으로 저장될 필요가 없음
        - 중간에 노드를 삽입 또는 삭제하더라도 배열에 비하여 다른 노드에 영향을 적게 미침
    - 결론적으로 연결 리스트는 동적으로 노드를 생성하고 관리함으로써,
        - 리스트 크기의 증가 감소에 따라 효율적으로 대처할 수 있으며
        - 노드의 삽입과 삭제와 같은 자료의 재배치를 빠르게 처리

- 단점: random access
    - 배열에 비하여 임의 접근(random access)에 많은 시간이 소용
    - 노드 검색은 헤드에서부터 링크를 따라가는 순차적 검색만이 가능

### 노드 순회(node traversal)

- 노드 순회(node traversal)
    - 연결 리스트에서 모든 노드를 순서대로 참조하는 방법
    - 헤드부터 계속 노드 링크의 포인터로 이동하면 가능
        - 링크가 NULL이면 마지막 노드
        - 노드 순회 방법을 이용하여 각 노드의 자료를 참조할 수 있음

---

# 클린 코드 ~ 객체와 자료구조 중간

### 주석

필요한 주석과 필요 없는 주석으로 나뉘어지며, 그러한 이유에 대해서 책에서 잘 설명해주었다. 주석은 설명이 필요한 코드나, 코드 자체로써 설명이 안되는 경우 사용하게 된다. 하지만 코드가 코드 자체로써 설명이 안된다면 이것은 좋은 코드가 아니라고 할 수 있다고 한다. 이외에는 날짜, 작성자과 같은 내용은 코드관리 시스템이 잘 되어있어 의미가 없으며, 코드를 주석하는 경우에는 다른 사람들이 이러한 코드가 중요한 것으로 여겨 손대지 않아 끝까지 남아있게 된다고 한다. 

앞에서 한 얘기의 연장선으로, 결국에는 변수나 함수가 자기 자신을 제대로 설명할 수 있게 작명되거나 구현되어있다면 이러한 주석이 전혀 필요없다고 설명한다. 나도 주석을 자주 이용하는 편이다. 아직 함수를 만들 때 정확히 한 가지 기능을 하도록 만들기가 익숙하지 않고, 작명하는 것 또한 서투르다. 그래서 다른 사람에게 코드를 보여줄 때 주석을 통해서 이야기를 하는데 이러한 습관 자체가 전부 안 좋은 것이라고 저자가 말해주었다. 비록 저자가 사용하는 코드가 JAVA를 이용한 코드로 예시로 들지만, 내가 어떤 언어를 쓰던지 이러한 부분은 적용이 될 수 있다고 생각이 들며, 고쳐야하는 것이라고 생각한다. 아직까지도 이 책은 나에게 어려우면 몇 번이고 계속 읽어볼 필요가 있음을 느낀다.

### 객체와 자료 구조

c++로 PS나 강의를 들으면서 코딩하면서 객체와 자료 구조에 차이점을 생각해본 적이 없다. 왜냐하면 객체지향이라는 개념이 생기면서 클래스를 같이 사용했기 때문에 클래스를 사용하여 만들게 되면 하나의 객체를 만드는 거라고 생각을 하였다. 하지만 안에 구성되어있는 자료나 함수에 의해서 이것이 자료 구조인지 객체인지 명확하게 구별된다는 것을 알게 되었다. 클래스 속 함수없이 모두 자료를 가지고 있다면 자료 구조라고 할 수 있고, 함수를 가지고 있으면 객체라고 할 수 있다. 객체와 자료 구조의 장단점은 명확하며 객체에게 유리한 것은 자료 구조에게 불리하며, 자료 구조에게 유리한 것은 객체에게 불리하다. 구체적으로 풀자면 자료 구조를 사용하는 절차적인 코드는 기존 자료 구조를 변경하지 않으면서 새 함수를 추가하기 쉽지만 객체 지향 코드는 기존 함수를 변경하지 않으면서 새 클래스를 추가하기 어렵다. 또한, 절차적인 코드는 새로운 자료 구조를 추가하려면 모든 함수를 고쳐야하므로 어렵다. 하지만 객체 지향 코드는 그 반대다.

디미터 법칙이란 내용이 나오는데 잘 알려진 휴리스틱으로, 모듈은 자신이 조작하는 객체의 속사정을 몰라야 한다는 법칙이다. 객체는 자료를 숨기고 함수를 공개한다. 따라서 객체는 조회 함수로 내부 구조를 공개하면 안된다는 의미이다. 처음에 강의를 들을 때 getter, setter를 만들어서 해당 클래스에 변수는 private하게 만들고 함수로써 접근하게 만들어서 이것을 충분히 정보은닉을 한거라고 생각했지만 저자가 말하는 것은 그것이 아니였다. 모든 내부구조를 알 수 없게 만들어야 된다는 의미로 조금 더 생각하게 만드는 부분이였다.

---

- 18日

# PS

최소 거리
```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
	string a, b;
	cin >> a >> b;
	a = "0" + a;
	b = "0" + b;
	
	int alen = a.length();
	int blen = b.length();
	
	for (int i=0; i<alen; i++)
		dp[i][0] = i;
	for (int i=0; i<blen; i++) 
		dp[0][i] = i;
	
	for (int i=1; i<alen; i++) {
		for (int j=1; j<blen; j++) {
			if(a[i]==b[j])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min({ dp[i-1][j-1], dp[i][j-1], dp[i-1][j] }) + 1;
		}
	}
	cout << dp[alen-1][blen-1];
}
```

최소 편집 알고리즘을 사용하여 해결하는 문제이다. 이전에 본 카카오 추천팀 인턴 코딩테스트에서 유사한 문제가 나와서 다시 복습하고자 풀어보았다. 전체적인 틀은 LCS알고리즘과 매우 유사하다. 만약 조금 더 생각했다면 코테에서도 잘 풀 수 있었지 않을까 싶다.

---

# 컴퓨���네트워크: HTTP and WWW

## HTTP

HTTP는 TCP port 80번을 이용한다.

### HTTP Transaction

클라이언트가 서버에게 HTTP Request, 서버가 클라어인트에게 HTTP Response 보내는 동작을 Transaction이라고 한다.

![image](https://user-images.githubusercontent.com/59367782/99490355-0979f280-29ad-11eb-8a53-7978a0f16b71.png)

### Request Message

| HTTP Request |
|---|
|Request line|
|Headers|
|A blank line|
|Body(present only in some messages)|

Header 이후 new line이 두 개가 나온다면 바로 Body가 나오게 된다.

### Reuqest line

`Request Type(method (GET, POST)) ` (space) `URL` (space) `HTTP version`

### URL

URL : Uniform resource locator

`Method`://`Host`:`Port`/`Path`

`http,https,ftp` :// `www.example.com:2030/test/hello.html`

예제) `GET http://google.com/index.html HTTP/1.1`

### Response message

| HTTP Response |
|---|
| Status line |
| Headers |
| A blank line |
| Body(present only in some messages) |

Request와 동일하게 Header이후에 new line이 두 번 반복하면 Body가 나오게 된다.

### Status line

`HTTP version` (space) `Status code` (space) `Status Phrase`

### Header format

`Header name`: (space) `Header value`

예제) Content-length: 168

### Headers

| HTTP Request | HTTP Response |
|---|---|
|Request line|Status line |
| General Headers|  General Headers |
|Request Headers| Request Headers |
|Entity Headers| Entity Headers |
|A blank line| A blank line |
|Body(present only in some messages)|Body(present only in some messages) |

Example 1)

![image](https://user-images.githubusercontent.com/59367782/99491194-a9844b80-29ae-11eb-8d3b-ea5b077a3b9f.png)

### Persistent vs. non-persistent

- Non-persistent connection
    - 접속한 클라이언트 연결에 대한 응답을 보낸 뒤 바로 끊음
    - 서버는 클라이언트가 이전에 어떤 요청을 했었는지 정보 유지하지 않음
        - 서버 로드가 줄어듦
        - 서버 데이터가 한번에 준비된느 것이 아니라 시간을 두고 준비되는 경우 모든 데이터가 준비될 때 까지 '지연'문제 발생

- Persistent connection
    - 접속한 클라이언트 연결을 응답을 보낸 뒤에도 계속 '유지'하는 것

HTTP version 1.1은 기본적으로 persistent connection을 기본으로 사용한다.

## GET vs. POST Request 매커니즘 이해

- 웹 서비스를 위한 전체 시스템 구성

![image](https://user-images.githubusercontent.com/59367782/99491701-8e660b80-29af-11eb-852b-f93458028639.png)


### HTTP GET Request

![image](https://user-images.githubusercontent.com/59367782/99493475-9c695b80-29b2-11eb-8d30-ac9c52733f8e.png)

`GET http://chonbuk.ac.kr/kor/?menuID=10&pid=254#dept_title HTTP/1.1`  
서버의 클라이언트 입력 정보를 `?key1=value1&key2=value2`의 형태로 제공한다

이러한 GET 파라미터를 UNIX 기준으로 봐보자.

- UNIX environment variable에 저장하게 된다.
- (key, value) 페어를 파싱한 후 이 정보를 기반으로 DB에서 정보를 추출한 후 응답 메시지 작성
- Environment variable은 운영체제에 따라 512 바이트, 1024바이트, 4096바이트 등 그 크기가 다름
- 만일 (key,value) 페어의 길이가 너무 크면 Environment variable에 저장 불가능
- 사용자로부터 이미지나 동영상을 업로드 하는 경우 HTTP 프로토콜은 ASCII기반이므로 MIME encoding을 수행한 후 URL_encoding을 수행하여 ?,=,& 등의 특수 용도로 사용되는 문자들을 %5F와 같은 형태로 변환하는데 그 크기가 수 MB 이상일 수 있음. ex) `?image=A` A <- URL_ENCODE(MIME_encode(image_data))
- 입력 데이터 크기가 크면 GET 방식으로 전달이 불가늫아고 POST 방식으로 전달해야 함

### HTTP POST Request

![image](https://user-images.githubusercontent.com/59367782/99493795-34ffdb80-29b3-11eb-9e1d-e28dc94c5d52.png)

GET과는 달리 HTTP 페이로드(body)에 담겨서 전송이 된다.

Request line: `POST http://chonbuk.ac.kr/kor HTTP1.1`
Body: `?menuID=10&pid=254#dept_title`

- UNIX 표준입력에 저장
- (key, value) 페어를 파싱한 후 이 정보를 기반으로 DB에서 정보를 추출한 후 응답 메시지 작성
- 표준 입력의 크기는 무한대이고 C 언어의 경우 `scanf()`로 읽으면 되며 언어에 맞게 표준 입력 함수를 호출하면 됨
- 사용자 입력 데이터 크기에 무관하게 적용할 수 있고 사용자 브라우저 창에 세부 정보가 직접적으로 출력되지않아 보안적으로 좀 더 안전함
- 사용자로부터 이미지나 동영상을 업로드 하는 경우 GET의 경우와 동일하게 MIME encoding, URL encoding을 해주어야 함.
- 웹 서버를 개발할 때 GET 방식은 웹 브라우저 입력창을 서버 테스트 입력 용도로 사용할 수 있는 장점이 있어 GET으로 개발한 후 POST로 전환하는 방식도 사용

### 정리

- GET/POST방식은 사용자 데이터를 어디에 저장하여 전달하는 지의 차이가 있으며 사용자 데이터 처리 방식은 사실상 동일

![image](https://user-images.githubusercontent.com/59367782/99494189-ee5eb100-29b3-11eb-8bf8-32fc8db50158.png)

## WWW

World-Wide-Web

![image](https://user-images.githubusercontent.com/59367782/99494463-64631800-29b4-11eb-92cd-a6ed4856f6ce.png)

문서에서 문서로 연결되는 것이 거미줄처럼 연결되어 있으면 전 세계로 뻗어있어서 이러한 이름을 갖게 되었다.

### Browser architecture

![image](https://user-images.githubusercontent.com/59367782/99494623-af7d2b00-29b4-11eb-82d4-4c62bd3fdccd.png)

이러한 프로토콜들을 전부 처리할 수 있으며 HTML, JS, JAVA언어를 해석하여 해주는 인터프리터 역할을 해주기도 한다.

### Categories of Web document

- Web document
    - Static: 미리 만들어 놓은 HTML 파일
    - Dynamic
    - Active

서버 프로그램이 동적으로 HTML 파일을 생성 (ex. C 프로그램이 printf() 함수로 HTML 명령어를 출력)

### Static document

클라이언트로부터 Request가 오면 서버측에서 Web document를 그대로 Response로 제공해주는 것이다.

문법은 Mark를 해서 angle bracket으로 속성을 부여할 수 있는데 브라우저마다 속성의 정도가 다를 수 있다.

`<TageName Attribute: Value Artribute: Value> ` Beginning Tag  
`</TagName>` Ending Tag

### Dynamic document

HTTP Request가 오게 되면 서버측에서 프로그램을 통해서 Document를 만들어서 클라이언트에 제공한다. 이런 경우에는 클라이언트가 많아질 수록 서버에 부하가 커지므로 scalability 문제가 있다.

![image](https://user-images.githubusercontent.com/59367782/99496730-2ec02e00-29b8-11eb-8d96-874a07d5baaf.png)

쉘 스크립트로 예시를 들게되면 위의 그림과 같다. 구조만 맞춰주면 쉘 뿐아니라 펄같은 다른 프로그래밍 언어를 사용해도 된다. 

### Active document

HTTP Request가 오게 되면 서버측에서 클라이언트에게 프로그램 코드를 보내 클라이언트에서 프로그램을 이용해서 Document를 만들어서 보게 된다. 이 경우에는 서버에 부하 부담이 없다.

### applet

브라우저가 즉, 클라이언트 사이드에서 해석하여 실행하게 된다. 하지만 속도가 느려서 요즘에 사용 안한다.

![image](https://user-images.githubusercontent.com/59367782/99497243-fb31d380-29b8-11eb-8d03-fda971f76f25.png)

이러한 과정으로 이뤄지게 된다고만 알아두자.

## JAVA vs JavaScript

두 언어는 전혀 다른 언어로 설명을 해본다.

### JAVA

- Sun Microsystems에서 셋톱박스, 전자레인지 등에 활용할 수 있도록 호환성에 초점을 맞춰 개발한 언어

- 기존 임베디드 시스템에서의 제어 프로그래밍
    - 어셈블리(asssembly)언어 -> CPU마다 새롭게 코딩
    - CPU에 무관하게 Java Virtual Machine(JVM)위에 Java byte code를 실행하게 하여 호환성 제공
        - 단 JVM을 울리는 작업은 CPU마다 새롭게 만들어야 함
        - 또한 JVM은 interpretation 방식이므로 느림
            - JIT(Just-In-Time) 컴파일러 등장으로 속도가 개선
                - byte code가 실행될 때 실제 machine instruction으로 compilation을 수행
                - 두번째 실행할될 때는 machine instruction이 바로 실행되므로 빠름
- 안드로이드 앱 개발에 자바 사용 후 주목 받음

### JavaScript

- 넷스케이프 브라우져에 사용자 입력을 받아 브라우저와 상호작용하는 언어를 개발 (라이브 스크립트)
- 이후 넷스케이프에 라이브 스크립트를 통합
- 이후 자바가 인기를 끌자 라이브 스크립트를 자바 스크립트로 명칭 변경
- 자바를 브라우저에서 실행하기 위해서는 별도의 플러그인을 설치해야 함
- 브라우저가 자바스크립트에 쓰여진 언어를 해석해서 실행하며 브라우저에 통합되어 있으므로 플러그인이 필요 없음

## Proxy 서버의 한계점

![image](https://user-images.githubusercontent.com/59367782/99497531-67143c00-29b9-11eb-9f43-68926eeaea22.png)

오늘날에는 Proxy server가 잘 동작하지 않는다.
- Web Server가 dynamic document를 주로 생성하기 때문
- 즉 동일한 HTTP Request에 대해 다른 HTTP Response가 돌아오는 경우가 많다. (caching한 데이터가 무용지물 됨)

---

# 소프트웨어공학: 소프트웨어 설계 기법

### 정보 은닉

- 정보 은닉이란 필요하지 않은 정보는 접근할 수 없도록 하여, 한 모듈 또는 하부 시스템이 다른 모듈의 구현에 영향을 받지 않게 설계 되는 것을 의미
- 소프트웨어 설계 단계에서 채택되는 설계 전략을 지역화하여  설계 전략에 변경이 발생하는 경우 그 영향이 최소한의 모듈들에만 미치도록 하는 것이다.
- 정보 은닉은 모듈들 사이의 독립성을 유지시켜 주며, 모듈 내부의 자료 구조나 수행 방법이 변경되더라도 그 모듈에서 제공하는 인터페이스를 사용하는 외부 모듈은 영향을 받지 않도록 하여 준다.
- 설계에서 은닉되어야 할 기본 정보
    1. 상세한 데이터 구조
    2. 하드웨어 디바이스를 제어하는 부분
    3. 특정한 환경에 의존하는 부분 (ex. 특수한 운영체제에 의존하는 부분 또는 특정한 DBMS에 의존하는 부분 등)
    4. 물리적 코드 (ex. IP주소, 문자코드 등)

- 시스템 설계에 있어 정보 은닉 개념은 구성 요소간의 독립성을 유지시켜준다는 점에서 중요
- 모듈 서로간의 내부 구조를 감추어 주고(추상화), 서로의 내부 구조를 알 필요가 없이 오직 정해진 인터페이스로만 서로 소통
- 만약 한 모듈에 수정이 요구되는 경우 모듈 내부의 자료 구조와 이에 접근하는 동작들에만 수정을 국한시킴으로써 ,변화에 쉽게 적응할 수 있고 유지보술르 용이하게 해나갈 수 있게 하는 기반을 제공
- 일반적으로 소프트웨어를 설계할 때 계층구졸르 이용하여 설계하는 것도 계층들 사이의 정보 은닉을 얻기 위함

- 결국 모듈 내부의 자료 구조나 수행 방법 등에 변화가 일어났을 때 외부 모듈들이 영향을 받지 않도록 설계할 수 있도록 지원하는 개념이 정보 은닉이다.
- 만약 모듈의 논리적인 수정(ex. 요구사항 변경)이 요구되는 경우는 어떻게 될까?
- 객체 지향 개발 방법의 중요한 개념 중의 하나인 캡슐화는 정보 은닉을 통한 추상화, 독립성 향상을 얻을 수 있는 방법

### 정보 은닉을 이용한 스택

```cpp
#define MAXSIZE 100;

struct STACK{
    char stack_value[MAXSIZE];
    int top;
};
typedef struct STACK stack;

void creat_satck(stack aStack) {
    aStack = new STACK;
    aStack->top = 0;
}

void push(stack aStack, char x) {
    if(aStack->top+1 == MAXSIZE)
        error("stack is full");
    else
        aStack->stack_value[++aStack->top] = x;
}

char pop(stack aStack) {
    if(aStack->top == 0) {
        error("stack is empty");
        return NULL;
    }
    else
        return aStack->stack_value[aStack->top--];
}

char top_element(stack aStack) {
    if(aStack->top == 0) {
        error("stack is empty");
        return NULL;
    }
    else
        return aStack->stack_value[aStack->top-1];
}

void destroy_stack(stack aStack) {
    delete aStack;
}

int main() {
    stack st1;
    char x, y;

    create_stack(st1);
    push(st1, 'a');
    push(st1, 'b');

    x = pop(st1);
    y = top_element(st1);

    destroy_stack(st1);
    printf("%c, %c", x, y);
    return 0;
}
```

### 정보 은닉이 정확히 되지 않은 스택

```cpp
#define MAXSIZE 100;
typedef struct {
    char stack_value[MAXSIZE];
    int top;
} stack;

void push(stack* aStack, char x) {
    if(aStack->top+1 == MAXSIZE)
        error("stack is full");
    else
        aStack->stack_value[++aStack->top] = x;
}

char pop(stack* aStack) {
    if(aStack->top == 0) {
        error("stack is empty");
        return NULL;
    }
    else
        return aStack->stack_value[aStack->top--];
}

int main() {
    stack* st1;
    char x, y;
    
    st1 = new stack;
    st1->top = 0;
    push(st1, 'a');
    push(st2, 'b');

    x = pop(st1);
    y = st1->stack_value[st1->top-1];

    delete st1;
    printf("%c, %c", x, y);
    return 0;
}
```

### 단계적 정제

- 단계적 정제는 하향식 설계 방법에 주로 사용되며, 기본 설계 단계에서 나타나는 프로그램의 구조에서 점차 모듈에 대한 세부 사항을 내려가며 구체화된다.
- 정제 과정에서 추상화의 수준은 낮아지며 각 기능은 분해되어 해결 방안을 제시하게 된다.
- 정제는 많은 노력을 들이는 과정이며, 세부적인 묘사를 가능하게 함으로써 시스템의 구현을 가능하게 한다.
- 앞에서 언급한 2가지 설계 단계인 기본 설계나 상세 설계는 높은 추상화 단계에서 낮은 추상화 단계로 가는 단계적 정제 과정
- 문제기술에서 요구사항 분석, 설계, 프로그래밍으로 이어지는 엔지니어링의 흐름도 단계적 정제 과정이라고 볼 수 있다.
- 일반적으로 큰 시스템을 상세화하면서 계층적인 배열을 두어 서로의 종속관계를 표시하는 것을 레벨화 또는 계층화라고 한다.

### 모듈화

- 모든 공학 분야에서 시스템을 구성 요소로 나누어 접근하는 경우가 대부분
- 소프트웨어의 경우 이 구성 요소를 대표하는 것이 모듈
- 소프트웨어의 모듈은 프로그래밍 언어로 표현하면 흔히 서브루틴, 프로시져, 함수 등으로 불리워짐
- 시슽메을 모듈화할 때 하향식 접근 방법을 사용하여 기능 단위로 쪼개어 나가는 것이 일반적
- 모듈화는 시스템을 지능적으로 관리할 수 있도록 하여주며, 복잡도의 문제를 해결해준다.
- 크고 복잡한 문제를 해결하기 위해 문제를 작은 단위인 모듈로 분할하여 정복하게 된다.
- 모듈화는 시스템의 유지 보수와 수정을 용이하게 하여 준다.
- 그러나 모듈의 수가 증가하면 상대적으로 각 모듈의 크기는 감소하며 모듈들 사이의 상호 교류가 증가하여, 시스템의 성능이 떨어지고 과부하현상이 나타나게 된다.

### 프로그램 구조화

- 소프트웨어 시스템의 구조화는 분할 과정에 의해 얻어질 수 있으며, 분할하여 정복하는 개념과 연관되어 있다.
- 분할 과정은 앞의 요구사항 분석 과정에서 일차로 이루어졌으며, 설계 단계에서 더욱 세분화
- 시스템의 중요 요소나 기능을 찾아내어 분할해 나가는 것은 분석가의 임무
- 분석의 결과를 구조화시키는 것은 설계자의 임무
- 시스템을 어떻게 분할해 나갈 것인가는 간단한 문제가 아니며 어떻게 분할하면 좋은지에 대한 완벽한 가이드 라인은 없다.
- 그러나 시스템의 특성을 파악하여 기존 시스템들의 경험과 가이드라인을 활용할 수 있다.
- 기존 시스템들을 살펴보면 시스템의 트것ㅇ에 따라 몇 가지의 구조적인 틀이 있다. 이러한 틀을 이용하면 유사한 특성을 가진 시스템을 만들고자 할 때 노력과 시간을 절약할 수 있다.

### 프로그램 구조에 사용하는 용어

- 제어 계층을 가진 프로그램 구조는 프로그램 요소인 모듈들 사이의 계층적 체계를 나타내주며 트리와 유사한 그림으로 표시된다.
- 사각형은 모듈을 나타내며 모듈들 사이의 선은 제어 관계를 나타낸다.
- 프로그램 구조를 측정하고 나타내는데 사용하는 용어는 다음과 같다.
    - 깊이
    - 넓이
    - 팬-아웃: 한 모듈이 직접 제어하는 하위 계층 모듈 수
    - 팬-인: 상위 계층의 조정 모듈 수

### 구조도표와 순서도

- 프로그램의 구조가 만들어진 다음 각 모듈들에 대한 구체적인 절차를 규명
- 순서도는 일반적으로 프로그램 구조를 나타내는데 사용되지 않으며, 모듈 내부의 작업 절차를 나타내는데 주로 이용

![image](https://user-images.githubusercontent.com/59367782/99504546-0689fc80-29c3-11eb-839f-8b1f041f86a8.png)

- 모스크 시스템 구조가 제일 이상적임

![image](https://user-images.githubusercontent.com/59367782/99504581-10abfb00-29c3-11eb-8bb4-df16849007f3.png)

### 데이터베이스 설계 구조

- 계층 구조
- 네트워크 구조
- 관계형 구조
- 객체 지향 구조

## 설계의 품질요소

- 좋은 설계를 명확히 정의 내리기가 쉽지 않다.
- 좋은 설계는 효율적으로 프로그램을 할 수 있게 하여 주는 설계라 할 수도 있고, 소프트웨어의 진화 문제를 잘 해결할 수 있도록 변화에 쉽게 적응할 수 있는 설계라 정의할 수 있다.
- 좋은 설계가 이루어졌다고 인식되기 위해서는 설계 결과인 설계 문서는 읽기 쉽고 이해하기 쉽게 만들어져야 하며, 시스템에 변화가 주어졌을 때 그 영향은 국소화 되어야 한다.
- 모듈들은 서로 독립적이어야 하고, 각 구성 요소는 내부의 응집력이 높아야 한다. 또한 모듈들 사이의 연결을 나타내는 결합도는 최소화되어야 한다.
- 모듈들 사이의 결합도가 약할수록 모듈의 독립성이 증가하고, 새로운 환경에 적응할 수 있는 적응력이 증가한다.
- 기능적 독립성, 응집도를 극대화하고 모듈들 사이의 결합도를 줄이는 것이 유지보수를 쉽게 할 수 있게 하는 우수한 설계의 원칙이라 할 수 있다.

### 모듈 독립성

- 소프트웨어는 이를 구성하고 있는 요소들이 독립성을 가지고 기능을 수행할 때 성숙된 모습을 나타낸다.
- 소프트웨어 구성 요소의 기능적 독립성은 모듈화 과정과 정보 은닉 개념에서 나타나는 부산물이다.
- 각 모듈이 하나의 기능만을 수행하며 **다른 모듈들과의 상호 교류와 결합을 최소화**시킬 때 모듈의 기능적 독립성은 극대화될 수 있다.
- **모듈간의 관계가 많고 복잡**하면 소프트웨어 설계가 복잡하여 설계에 투여되는 **노력이 많게 들게되며 설계 비용도 높아 지게 된다**.
- 모듈간의 관계가 많고 복잡하하면 소프트웨어의 이해가 어렵게 되고 작은 설계 변경이 요구되어도 많은 모듈에 영향을 주어 유지보수를 어렵게 할 수 있다.
- 모듈간의 관계가 최소화되고 단순한 경우 모듈의 독립성이 높다고 일컫는다.
- 설계 목표는 이해하기 쉽고 수정이 쉬운 소프트웨어를 만드는 것이며 높은 독립성을 갖고 있는 모듈들을 설계하는 것은 그 기본이라 할 수 있다.

### 설계 응집도

- 응집도는 모듈 내부가 얼마나 단단히 뭉쳐져 있는가를 나타내는 성숙도의 측정치이다.
- 응집도는 모듈 안의 구성 요소들이 어울리는 정도를 나타내며, 구성 요소들을 묶어주는 시멘트
- 또한 응집도는 모듈이 하나의 임무를 수행하는 정도를 나타내는 것으로 모듈의 독립성을 측정하는 또 다른 척도이다.
- 따라서 모듈 내부 요소들 사이의 응집도가 증가하도록 설계하는 것이 바람직하다. 모듈이나 시스템의 구성 요소는 하나의 논리적 기능을 수행하거나 하나의 논리적 엔티티를 나타내는 것이 바람직하다.
- 모듈의 응집도를 높이면 모듈 사이의 낮은 결합도를 얻을 수 있으며, 이와 반대로 낮은 응집도는 높은 결합도를 발생시킬 수 있다.
- 소프트웨어를 설계할 때 모듈들은 높은 응집도를 갖고, 모듈들 사이의 결합도가 낮게 하는 것이 바람직하다.

- 응집도 스펙트럼

![image](https://user-images.githubusercontent.com/59367782/99519078-bcaa1200-29d4-11eb-8c75-530808409ce8.png)

### 우연적 응집도

- 모듈내의 구성 요소들이 뚜렷한 연결성을 가지고 있지 않다.
- 극한적인 예로서 임의로 20줄씩 잘라 모듈을 만들었을 때 우연적인 응집도 밖에 기대할 수 없다.
- 뚜렷한 의미나 기능은 없지만 여러 모듈에 유사한 명령문들이 중복되어 있는 경우에 단지 중복되는 부분을 줄이려고 이를 묶어 모듈을 설계하였다면 이런 모듈은 우연적 응집도를 갖게 된다.
- 다음과 같이 모듈 A, B의 유사한 명령문들을 모아 모듈 C를 구성하였다고 하면, 이런 설계는 모듈 A, B에 대한 수정이 발생하지 않는다는 틀린 가정을 하고 있다. A 또는 B의 알고리즘의 설계 변경이 발생하였을 경우 C 모듈에 대한 수정이 불가피하며, C를 수정하는 것이 매우 어렵다.

### 논리적 응집도

- 설계 시 논리적으로 연관된 임무나 비슷한 기능을 묶어 한 모듈을 구성
- 그러나 만약 여러 기능 중 어느 한 기능에 변경이 발생 하였을 때 모듈의 수정이 필요

```
y = 5x^2 + 6x + 4
y = 6x^3 + 6x + 4
y = 7x^4 + 6x + 4
```

- 세 계산기 모두 6x + 4라는 식을 포함하기 때문에 하나의 모듈로 이 방정식을 푸는 임무를 수행

```cpp
long solve_equation(int no_equ, long x) {
    long y;
    y = 0;
    switch (no_equ) {
        case 1:
                y = 5 * x * x;
                break;
        case 2: 
                y = 6 * x * x * x;
                break;
        case 3: 
                y = 7 * x * x * x * x;
                break;
    }
    y = y + 6 * x + 4;
    return y;
}
```

### 시간적 응집도

- 모듈 내 구성 요소들이 서로 다른 기능을 같은 시간대에 함께 실행하는 경우
- 초기화 모듈은 흔히 볼 수 있는 시간적 응집도 모듈
- 예를 들면 초기화 모듈 *Init_Variables*는 변수에 대한 초기화 작업을 수행하는 시간적 응집 모듈이며, 각 변수들에 대한 초기화는 서로 연관성이 없다.
- 시간적 응집도를 가진 모듈도 여러 가지 임무를 수행하지만 같은 시간대에 실행한다는 점에서 이런 응집도는 우연적 응집도 또는 논리적 응집도 모듈 보다 응집도가 높다.

```cpp
void Init_Variables() {
    ...
    no_student = 0;
    no_department = 0;
    university_name = "Jeonbuk National University";
}
```

### 절차적 응집도

- 모듈 내 구성 요소들이 연광성이 있고, 특정 순서에 의해 수행되어야 하는 경우에 절차적 응집도를 가진다.
- 프로세스의 절차적인 요구 조건에 따라 모듈을 설  계할 경우 모듈이 단지 절차의 한 부분이라는 이유로 설계되었다면 응집도가 낮은 절차적 응집도만을 가진 모듈로 될 수 있다.
- ex) 방정식들의 계수를 입력하여 이차 방정식들을 풀고 (근: a + bi, a - bi) 해 이차원 a^2 + b^2 을 구하는 경우

### Solve_Quadratic_Equ 모듈

- 이 모듈의 구성 요소는 순환구조의 한 원소이기 때문에 절차적 응집 모듈의 특성을 가진다.
- 프로세스 절차에 의해서만 모듈화를 하게 되면 설  계된 모듈이 여러 임무를 수행할 수 있거나 한 임무의 일부분만을 수행할 수도 있다.
- 예제에서 2차 방정식을 푸는 임무는 해 2차원을 구하는 임무의 일부분이지만 데이터는 고려하지 않고 프로세스 절차만 고려하였기 때문에 Solve_quadartic_Equ는 해 2차원을 구하는 임무 전부를 수행하지 않고 있다.

![image](https://user-images.githubusercontent.com/59367782/99520649-b3ba4000-29d6-11eb-8ee0-2f8186462215.png)

### 대화적 응집도

- 모듈이 여러 가지 기능을 수행하며 모듈 내 구성 요소들이 같은 입력 자료를 이용하거나 동일 출력 데이터를 만들어 내는 경우
- 절차적 응집도는 오직 프로세스 절참나 고려하여 얻은 모듈이지만 대화적 응집 모듈은 모듈화에서 프로세스 절차와 데이터를 동시에 고려하여 모듈화된 것으로서 해결하려는 문제와 많은 연관성을 갖고 있어 절차적 응집도 보다 높은 응집도를 갖고 있다고 볼 수 있다.

![image](https://user-images.githubusercontent.com/59367782/99520828-f24ffa80-29d6-11eb-80f2-819a3afbbc34.png)

- 왼쪽 모듈은 같은 입력을 갖고 있고 오른쪽 모듈은 같은 출력을 갖고 있다.

- ex) 행렬의 값을 입력하고 전치행렬 A^T와 역행렬 A^-1을 계산하는 식

```cpp
void Compute_Matrix(long transform_matrix[][], long inverse_matrix[][]) {
    long aMatrix[5][5];
    
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            Read an element to aMatrix[i][j];
    
    transform_matrix = aMatrix^T를 계산한다.
    inverse_matrix = aMatrix^-1을 계산한다.
}
```


### 함수적 응집도

- 한 기능을 수행하기 위해 각 구성 요소들이 필요한 경우
- 이런 모듈 내부 요소들은 가장 밀접히 연관되어 있고, 또한 높은 응집도를 갖고 있다.
- 이런 모듈은 오직 하나의 기능을 수행함으로써 이해하기가 쉽고 수정하기도 쉽다.
- 예를 들면 행렬의 값을 입력하여 그의 역행렬을 계산하여 출력하는 프로그램을 입력 모듈, 역행렬 계산 모듈 및 출력 모듈로 나누어 설계하면 각 모듈은 함수적 응집도를 갖게 된다.

### 응집도 요약

- 한 모듈 안에 여러 기능을 합쳐 놓으면 오류를 일으킬 가능성이 증가하며, 시험하기도 어렵게 된다.
- 이는 앞의 기능이 변경되었을 때 뒤의 기능에 영향을 주게 되며, 오류가 확산될 가능성이 커지기 때문
- 높은 응집도는 모듈의 기능적 독립성을 높여주며 소프트웨어의 수정과 확장을 용이하게 하여 주어 고품질의 소프트웨어를 만드는 기준이 된다.
- 지금까지 응집도는 모듈을 중심으로 분류, 설명되었으나 시스템에 사용되는 객체를 중심으로 응집도가 분류 될 수 있다.
- 객체 지향 개발 방법은 객체의 정적인 데이터와 동작을 함께 묶어 객체를 정의함으로써 높은 응집도를 얻을 수 있는 개발 방법

### 결합도

- 결합도는 모듈 사이의 상호 연관성의 복잡도를 일컫는다.
- 모듈들 사이의 상호 교류가 많고 서로의 의존이 많을수록 모듈들 사이의 결합도는 높아지게 된다.
- 특히 인터페이스가 정확히 설정되어 있찌 않거나 기능이 정확히 나누어져 있지 않을 때 불필요한 인터페이스가 나타나 모듈 사이의 의존도는 높아지고 결합도는 증가
- 시스템의 구성 요소들 사이의 관계도 각 구성 요소의 독립성과 응집도를 바탕으로 구성 요소들 사이의 관계가 맺어져야 한다.
- 결합도는 프로그램 요소들 사이의 **상호 연관성**을 표시하여 주는 방법이며, **모듈의 독립성 및 응집도**와 밀접한 관계를 가지고 있다.
- 만약 두 모듈이 서로 옆에 있건 없건 완벽하게 기능을 수행하는 경우라면 이들은 서로 **완전히 독립적**이라 할 수 있으며 이는 **서로 상호 교류가 전혀 없음을 의미**한다.
- 결합도가 높을 수록 한 모듈의 변화가 다른 모듈에도 영향을 주어 **파문 효과**를 일으키게 된다.
- **파문 효과가 클수록 시스템을 유지보수하기 어려워진다.**

### 결합도에 영향을 미치는 4가지 요소

- 모듈들 사이의 연결 유형
    - 모듈들 사이의 연결은 한 모듈 안에 있는 요소가 다른 모듈에 의해 참조될 때 발생한다.

- 인터페이스의 복잡도
    - 각 인터페이스는 모듈들의 연결을 위해 꼭 필요한 정보만을 표시하여 복잡도가 최소화될 수 있도록 만들어져야 한다.

- 정보 흐름의 유형
    - 모듈들 사이에 교류되는 정보의 유형에는 크게 데이터와 제어 신호가 있다.

- 바인딩 시간
    - 모듈 사이의 연결을 묶는 때를 바인딩 시간이라 하며, 컴파일할 때, 로딩할 대, 실행할 때 등이 있다. 실행 시간에 바인딩되면 로딩 시간에 바인딩된 것보다 결합도가 약하며, 로딩 시간에 바인딩되면 컴파일 시간에 바인딩된 것보다 결합도가 약하다.

### 결합도 스펙트럼

![image](https://user-images.githubusercontent.com/59367782/99523254-27aa1780-29da-11eb-811b-737575fe8778.png)

### 직접적 결합이 없음

- 서로 독립적이고 상호 교류가 없는 경우이거나, 두 모듈이 다른 모듈에 속해있어 직접적으로 연결되어 있지 않을 때

### 데이터 결합도

- 한 모듈이 간단히 데이터들을 매개 변수를 통해 다른 모듈과 주고 받는 경우

### 스탬프 결합도

- 스탬프 결합도는 레코드 또는 배열과 같은 복잡한 데이터 구조를 모듈 인터페이스를 통해 주고 받는 경우
- 스탬프 결합도에서 호출 모듈과 피호출 모듈간에 데이터 교환에서 사용되는 자료구조를 공통으로 쓰고 있기에 이런 자료구조에 대한 정보를 알아야 한다.

### 제어 결합도

- 모듈 사이에 제어 신호를 주고 받아 다른 모듈의 행위를 변경할 수 있는 경우
- 이때 제어 신호가 하부 모듈에 전달되어 그 행위를 결정하게 된다
- 데이터를 교류하는 것보다 제어 신호를 교류하는 경우 모듈들 사이의 결합도가 높다

### 외부 결합도

- 입출력의 경우 모듈이 특수한 하드웨어에 결합되어 있거나, 통신 프로토콜, 운영체제, 컴파일러 등과 같은 소프트웨어 이외의 다른 시스템 구성 요소와 결합되어 있는 경우
- 모듈이 컴파일러의 비표준 선택사양에 의해 컴파일되는 경우(컴파일러 결합)나 표준화되어 있지 않은 운영체제 기능을 사용하는 모듈의 경우(문서화되어 있지 않은 MS-DOS 기능)가 이에 해당

### 공통 결합도

- 모듈들이 간단한 타입을 갖고 있는 전역 변수를 사용하는 경우 이 모듈들 사이에 공통 결합도를 갖고 있다.
- Fortran의 COMMON 블록도 이에 해당
- 공통 결합은 다음과 같은 결점이 있다. 첬재, 변수 값의 초기화 시기를 각 모듈이 미리 알고 있어야 한다. 둘째, 전역 변수는 모듈 사이에 정보를 교환하는데 사용된다.

### 내용 결합도

- 한 모듈이 다른 모듈 내부에 있는 데이터나 제어 신호를 사용하는 경우이거나, 다른 모듈의 중간에 뛰어들어가는 경우
- 모듈들이 서로 상대방의 내부 정보를 직접 이용한다는 것은 모듈화가 잘 되어있지 않다는 것이며 소프트웨어의 설계에서 극소수 상황을 제외하고는 이런 연결을 피하여야 한다.
- 현재 우리가 쓰고 있는 고급 프로그래밍 언어는 이런 결합을 모듈들의 관계에서 지원하지 않는다.
- ex) 한 모듈에서 GOTO 문으로 다른 모듈 내부에 들어갈 수 없고, 타 모듈 내부에서 정의된 변수도 이용할 수 없다.
- 하지만 FORTRAN 언어의 경우 ENTRY 문을 이용하여 다른 모듈의 내부에 직접 접근할 수 있으며, 프로그램의 성능을 고려하여 어셈블리 언어를 이용하여 내부 결합도를 가진 모듈을 설계할 수 있다.

### 이해도

- 프로그램 요소의 동작의 이해하지 않고는 프로그램을 만들기도 어렵거니와 유지보수 단계에서 고쳐나가기 어렵다.
- 프로그램 및 문서의 **이해도**는 다른 프로그램 요소나 정보를 참조하지 않고 이해할 수 있는 용이성이다.
- 시스템의 응집도가 높을수록 프로그램 요소들을 쉽게 이해할 수 있으며 고쳐나가기 쉽다.

### 이해도와 관계 있는 요소들

- 구조적으로 소프트웨어를 설계하여야 한다. 시스템은 서브시스템으로 구성되고 각 서브시스템은 독립성이 높아야 한다.
- 서브시스템을 구성하는 모듈간의 독립성을 높여야 한다. 모듈들은 서로 낮은 결합도를 갖고 있어야 하며, 정보 은닉이 잘되어 서로 참조하는 정보를 될 수록 줄여야 한다.
- 프로그램 이해의 전제는 프로그램을 읽는 것이기 때문에 프로그램을 읽기 쉽게 작성하여야 한다. 프로그램 구조, 모듈 및 변수 이름, 모듈의 복잡성 등은 프로그램을 쉽게 읽는 정도에 많은 영향을 준다.
- 설계 및 코드 문서는 정확하고 완전해야 한다. 부정확한 문서는 프로그램 이해에 도움을 주지 못할 뿐만 아니라 더욱 어렵게 한다. 문서가 없거나 불완전하면 코드에 의해서만 프로그램을 이해하여야 하기 때문에 프로그램을 이해하기 어렵다.

### 적응도

- 새로운 환경에 적절히 대응할 수 있도록 소프트웨어를 변경시킬 수 있는 용이성을 **적응도**라고 한다.
- 소프트웨어의 경우 이러한 환경의 변화는 피할 수 없는 것이다.
- 적응도가 높은 시스템을 만들기 위해서는 각 구성 요소들 사이의 결합도가 낮아야 한다.
- 문서들은 이해하기 쉬워야 하고 프로그램과 일치하도록 관리되어야 한다.
- 또한 환경 독립성을 높여 수정되어야 할 부분을 지역화하여 적은 부분을 수정하여 쉽게 새로운 환경에 적응할 수 있도록 하여야 한다.
- 환경과 연관된 부분을 지역화하여 이해도를 높이고 **이식성**도 높여야 한다.

## 요약

- 소프트웨어 설계는 소프트웨어 개발의 핵심
- 사용자 요구사항 분석도 안정감 있는 시스템을 설계하기 위한 준비 과정이라 볼 수 있다.
- 요구사항에 대하여 보다 잘 이해할수록 보다 이상적인 설계가 가능하다.
- 모듈들은 서로 독립적이어야 하고, 각 구성 요소는 내부의 응집력이 높아야 한다.
- 모듈들 사이의 연결을 나타내는 결합도는 최소화되어야 한다.
- 설계의 중요 활동은 데이터 설계, 구조 설계, 절차 설계, 인터페이스 설계가 있다.
- 관리적 측면에서 살펴보면 크게 기본 설계와 상세 설계의 두 가지로 나뉜다.
- 소프트웨어의 품질은 설계에서 시작한다.
- 설계는 소프트웨어의 품질을 향상시킬 수 있는 중요한 과정이며, 요구사항을 소프트웨어 시스템으로 변형시키는 개발의 첫 번째 단계이다.

---

- 19日

# 최소 편집 거리

최소 편집 알고리즘에서 만약 변경하는 연산이 없으며 쉬프트를 할 수 있고, 쉬프트는 연산으로 안 친다는 문제를 해결하기 위해서 생각을 해보았다. LCS와 같은 방식으로 DP를 구사를 한다. LCS를 이용하되, 쉬프트는 연산으로 안 치기 때문에 쉬프트를 26번을 하면서 모든 경우의 수에 LCS를 적용하여 가장 긴 공통 수열을 찾는다. 전체 문자열 길이에서 수열의 수를 빼게 되면 쉬프트로 같아지는 문자들이 사라지게 된다. 이후 남은 수를 다 제거하고 삽입을 하게 되면 A와 B 문자열은 같아진다. 따라서 남은 수 x 2를 리턴하게 되면 된다.

또 다른 상황으로 만약 쉬프트가 연산으로 친다고 하면, 왼쪽으로 13번 오른쪽으로 13번 쉬프트를 전부 하면서 쉬프트 연산 횟수와 남은 수를 제거하고 삽입하는 수. 즉, 쉬프트 연산으로 같아진 문자열을 제외한 모든 문자의 숫자 x 2를 더해서 취해지는 값들을 중 가장 작은 값을 리턴하면 된다.

이런 식으로 시나리오를 짜서 생각해보았다. 이미 지나간 코테지만 다시 회고하면서 정리해보니까 어렵지 않은 문제였다. 조금 더 생각을 빨리 할 수 있게 되었으면 좋겠다.

---

# 클린 코드

## 단위 테스트

TDD 법칙 3가지

1. 실패하는 단위 테스트를 작성할 때 가지 실제 코드를 작성하지 않는다.
2. 컴파일은 실패하지 않으면서 실행이 실패하는 정도로만 단위 테스트를 작성한다.
3. 현재 실패하는 테스트를 통과할 정도로만 실제 코드를 작성한다.

세 가지 규칙을 따르면 개발과 테스트가 30초 주기정도로 묶이게 된다. 라고 책에서 볼 수 있다.

TDD에 따른 개발론에서 보면 테스트를 위한 코드가 존재한다. 이 테스크 코드 또한 깨끗하게 유지되어야 한다고 저자는 말한다. 테스트 코드는 애플리케이션 코드 만큼 중요하다고 강조한다. 왜냐하면 개발에 있어서 테스트 케이스는 매우 중요하기 때문이다.

테스트 케이스가 없다면 어떠한 문제가 있는지 체크하는데에 있어서 어려움이 있을 수 있다. 책의 내용을 빌리자면, 개발자들은 테스트 케이스가 없다면 코딩에 두려움을 느낄 수 있다고 한다. 나도 공감하는 바이다. PS외에는 테스트 케이스나 테스크 코드와 같은 것을 대입할 일은 없지만, PS할 때 테스트 케이스에 맞춰서 코딩을 하는 경우도 있기 때문에 테스트 케이스를 통해서 깨달음을 얻을 때도 많기 때문이다.

분명 현업에 나가게 되면 이러한 테스트 케이스는 무조건 쓰인다고 생각하고 이러한 부분을 염두에 두고 생각해야겠다.

---

- 20日

# 우아한테크코스 회고

우아한 테크코스 1차에서 떨어졌다. 1차 코딩테스트에선 7문제 전부 풀어 제출해서 코딩테스트 점수에선 자신이 있었지만, 점수 산출 방식이 달랐다. 코테에서는 기준을 통과하기만 하면 전부 같은 점수로 보고 자기소개서에 비중이 높았다. 다른 인턴을 생각했던 것이 패착이다. 코테 점수가 일단 높아야 한다고 생각하여 자소서는 짧게 적고 도전을 해본 것이라 떨어질만 했다.

앞으로는 지원 성격에 맞게 지원서도 잘 쓰고 코테도 잘 보도록 해야겠다. 이 부분에 있어서는 모든 것을 다 열심히 하면 좋지만 생각보다 어려운 부분이 많아서 아쉬운 것 같다. 내년에 도전할 많은 인턴십과 공채에 있어서는 이런 부분을 보완하여 제대로 도전할 수 있었으면 좋겠다.

---

# DB 구조 문서화

학교 강의에서 진행하는 프로젝트 주제로 현재 전북대학교에서 사용하는 online judge site인 리트머스를 선택했다. 리트머스는 2008년도부터 선배들이 직접 참여해서 만든 프로젝트이며 현재 지금까지도 학부생들 수업에 쓰이고 있다. C언어와 C++, JAVA의 언어를 지원하여 문제를 올리고 테스트케이스 다 맞다면 Solve를 주는 방식이다.

하지만 처음에 만들어진 이후에 관리가 안되어서 거의 방치되다시피 서버가 돌아가고 있으므로 이번에 강의 프로젝트 겸 유지보수가 필요하다 생각이 들어 친구들과 파트를 나눠서 프로젝트에 기여하기로 하였다.

나는 mysql로 이뤄진 DB 시스템 전반에 대한 문서화를 하고 테이블만 보면 이해하기 어렵기 때문에 반대로 추상화를 시켜볼려고 한다. ER도를 그려서 다른 사람들이 리트머스의 구조를 볼 때 이해하고 접근하기 쉽도록 제작할려고 한다. 또한, 만약 쿼리에 최적화가 가능하다면 최적화를 하며, 백업을 할려고 한다. 백업은 리트머스 서버 자체가 너무 노화되어 mysqldump를 이용한 백업은 어려울 것으로 생각이 된다.

오늘은 리트머스 mysql 서버에 접속해서 테이블들을 둘러본 결과 오래 방치되어 쓰지 않는 테이블도 많고 테이블마다 하는 역할도 릴레이션도 정해져있지 않고 하드코딩이 되는 식으로 되어있다. 테이블의 역할을 전부 정리하고 현재 어떤 식으로 DB를 사용하는 지 둘러보았다. 버전도 10년 전 버전이며, DB의 구조가 복잡하게 엉켜있지 않고 데이터베이스 테이블마다 하나씩의 기본키만 가지고 코딩할 때 하드코딩을 하여 추상화에선 어렵게 느껴지지 않는다.

---

# node.js 비동기

- [NodeJS와 비동기 - 박명호님의 github.io](https://qkraudghgh.github.io/node/2016/10/23/node-async.html)
- [JS 비동기는 어떻게 구현되어있는가?? - thsoon님의 velog](https://velog.io/@thsoon/JS-%EB%B9%84%EB%8F%99%EA%B8%B0%EB%8A%94-%EC%96%B4%EB%96%BB%EA%B2%8C-%EA%B5%AC%ED%98%84%EB%90%98%EC%96%B4%EC%9E%88%EB%8A%94%EA%B0%80)

node.js 사용하다보면 다른 라이브러리나 프레임워크에 의존하여 사용해왔다. 그런 것들을 제하고 비동기로 코딩할려하니 막막해오는 것을 느껴서 다른 사용법보다 원리적인 내용을 알아야 된다고 생각이 들었고 원리부터 보기 위해서 다른 분들의 포스팅을 참고해서 살펴보았다.

오늘은 가볍게 훑어보는 정도로 끝났으나 다음에는 직접 정리할 수 있도록 공부해봐야겠다.

---

- 21日

# Process Management

## Process Creation

### 프로세스 생성: fork(2)

```c
#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);
```

- 프로세스 생성: fork(2)
    - 새로운 프로세스를 생성 : 자식 프로세스
    - fork 함수를 호출한 프로세스 : 부모 프로세스
    - **자식 프로세스는 부모 프로세스의 메모리 주소 공간을 그대로 복사**
        - 메모리 공간이 똑같이 복제됨에 따라, 아래 자원들도 그대로 복사됨
        - RUID, EUID, RGID, EGID, 환경변수
        - 열린 파일기술자, 시그널 처리, setuid, setgid
        - 현재 작업 디렉토리, umask, 사용가능자원 제한
    - 부모 프로세스와 다른 점
        - 자식 프로세스는 유일한 PID를 갖는다
        - 자식 프로세스는 유일한 PPID를 갖는다. (Parent PID)
        - 프로세스 잠금, 파일 잠금, 기타 메모리 잠금은 상속 안함
        - 자식 프로세스의 tms구조체 값은 0으로 설정 (수행 시간 관련 구조체)
    - 부모 프로세스와 자식 프로세스는 열린 파일을 공유하므로 읽거나 쓸 때 주의해야 한다. (동기화 문제 발생 가능)

![image](https://user-images.githubusercontent.com/59367782/99810371-fa4e9c80-2b86-11eb-8008-80352f9001b7.png)


### 프로세스 종료: exit(2)

```c
#include <stdlib.h>
void exit(int status);
```

- 프로세스 종료: exit(2)
    - status : 종료 상태값
        - 부모 프로세스가 이 상태값을 보고, 0이면 정상, 그 외 다른 값이면 비정상 종료되었다고 판단함.
    - `Main()` 함수에서 return 하는 것은 `exit()`와 동일한 효과
        - `exit()`는 문맥 어디에서든 수행하여 프로세스를 종료할 수 있음

```c
#include <stdlib.h>
int atexit(void (*func)(void));
```

- 프로세스 종료시 수행할 작업 등록: atexit(2)
    - func : 종료 시, 수행할 작업을 지정한 함수명
    - 등록한 함수들이 등록 순서의 역순으로 수행됨
    - `Main()` 에서 return 할 때도 수행됨

- 프로그램 종료 함수의 일반적 종료 절차
    0. atexit() 로 등록된 함수들을 수행한다.
    1. 모든 파일 기술자를 닫는다.
    2. 부모 프로세스에 종료 상태를 알린다.
    3. 자식 프로세스들에 SIGHUP 시그널을 보낸다.
    4. 부모 프로세스에 SIGCHLD 시그널을 보낸다.
    5. 프로세스간 통신에 사용한 자원을 반납한다.

## Program Execution

### 다른 프로그램을 실행시키려면? system(3)

```c
#include <stdlib.h>
int system(const char *string);
```

- 프로그램 실행 : system(3)
    - 새로운 프로그램을 실행하는 가장 간단한 방법
    - 실행할 프로그램명을 인자로 지정
        - 콘솔에 직접 입력하는 것과 마찬가지 효과를 냄
        - 예) `system(“ls -al”)`;
    - 위험하고 비효율적이므로 남용하지 말 것
        - 환경 변수 해킹 등에 의해 전혀 다른 명령이 수행되어 보안 상 위험할 수 있음
        - [관련 설명](https://www.joinc.co.kr/w/Site/system_programing/Unix_Env/secure_prog#AEN58)

### 환경변수의 이해

- 환경변수
    - 프로세스가 실행되는 기본 환경을 설정하는 변수
    - 로그인명, 로그인 쉘, 터미널에 설정된 언어, 경로명 등
    - 환경변수는 “환경변수=값”의 형태로 구성되며 관례적으로 대문자로 사용
    - 현재 쉘의 환경 설정을 보려면 env 명령을 사용

```shell
# env
_=/usr/bin/env
LANG=ko
HZ=100
PATH=/usr/sbin:/usr/bin:/usr/local/bin:.
LOGNAME=jw
MAIL=/usr/mail/jw
SHELL=/bin/ksh
HOME=/export/home/jw
TERM=ansi
PWD=/export/home/jw/syspro/ch5
TZ=ROK
...
```

### 다른 프로그램의 실행: exec(3) series

- exec 함수군
    - exec로 시작하는 함수들로, 명령이나 실행 파일을 실행할 수 있다.
    - exec 함수가 실행되면 **프로세스의 메모리 이미지는 해당 실행파일**로 바뀐다.

```c
#include <unistd.h>
int execl(const char *path, const char *arg0, ..., const char *argn, (char *)0);
int execv(const char *path, char *const argv[]);
int execle(const char *path, const char *arg0, ..., const char *argn, (char *)0, char *const envp[]);
int execve(const char *path, char *const argv[], char *const envp[]);
int execlp(const char *file, const char *arg0, ..., const char *argn, (char *)0);
int execvp(const char *file, char *const argv[]);
```

- Exec 함수군의 형태 6가지
    - Path or file : 실행할 명령의 파일 경로 지정
    - arg#, argv : main 함수에 전달할 인자 지정
    - envp : main 함수에 전달할 환경변수 지정 * 함수의 형태에 따라 NULL 값 지정에 유의!

### Execlp() 함수 사용하기

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("--> Before exec function\n");

    if (execlp("ls", "ls", "-a", (char *)NULL) == -1) {
        perror("execlp");
        exit(1);
    }

    printf("--> After exec function\n");

    return 0;
```

### Execv() 함수 사용하기

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *argv[3];
    printf("Before exec function\n");

    argv[0] = "ls";
    argv[1] = "-a";
    argv[2] = NULL;
    if (execv("/usr/bin/ls", argv) == -1) {
        perror("execv");
        exit(1);
    }
    printf("After exec function\n");
    return 0;
}
```

### Execve() 함수 사용하기

```c
int main(void) {
    char *argv[3];
    char *envp[2];

    printf("Before exec function\n");

    argv[0] = "arg.out";
    argv[1] = "100";
    argv[2] = NULL;

     envp[0] = "MYENV=hanbit";
    envp[1] = NULL;

    if (execve("./arg.out", argv, envp) == -1) {
        perror("execve");
        exit(1);
    }

    printf("After exec function\n");

    return 0;
}
```

### 일반적인 exec() 사용 방법

- Fork()로 생성한 자식 프로세스에서 exec() 함수군을 호출
    - 자식 프로세스의 메모리 이미지가 부모 프로세스 이미지에서 exec() 함수로 호출한 새로운 명령으로 대체
        - 이를 이용해 자식 프로세스는 부모 프로세스와 다른 프로그램을 실행
        - **Exec() 수행이 완료된 이후, 해당 코드 이하의 내용은 해당 프로세스에서는 삭제되므로 실행되지 않음**
- 부모 프로세스와 자식 프로세스가 각기 다른 작업을 수행해야 할 때 fork() 와 exec() 함수를 함께 사용

## Process Termination

### 프로세스 트리

- 프로세스는 항상 부모로부터 태어남
    - 즉, 모든 프로세스는 가족으로 family tree 가 형성됨
- 부모의 역할
    - 자식 프로세스의 종료 상태를 확인하고,
    - 상태에 따른 작업을 처리함

### 부모의 역할: 자식의 종료 상태 확인

- 예) 파일 전송을 수행하는 서버 프로세스
    - 각 사용자의 요청에 따라 실제 파일 전송을 담당하는 child process 생성
    - 만약 child 가 파일 전송에 실패했다고 하면?
    - 에러 코드에 따라 문제 상황을 해결하고,
        - 에러 코드: main() 함수의 return 값. 혹은 exit() 로 전달되는 값
        - 이걸 어떻게 전달 받을 수 있을까? -> **wait() 시스템콜**
- 다른 child 를 만들어 파일 전송을 다시 시도함
- 만약 에러 코드를 전달하지 못하고, (아무도 에러 코드를 받아주지 않고) 프로세스가 종료되면?
    - Zombie 프로세스!
        - 프로세스는 종료되었지만, PID 등의 자원이 반환되지 않음
- **따라서 parent는 항상 wait() 를 이용해 child process의 종료를 확인하여야 함**

### 자식 프로세스 상태 대기: wait(3)

```c
#include <sys/types.h>
#include <sys/wait.h>
pid_t wiat(int *wstatus);
```

- wait(3)
    - 부모 프로세스는 `wait()` 함수에서 멈춘 상태로,
    - 프로세스의 상태 변화를 대기: 종료, (시그널에 의한) 중단, 재개 등
        - `wait()` 함수를 호출 전에 child가 이미 종료했다면 `wait()` 함수는 호출 즉시 리턴
    - wstatus : 자식 프로세스가 전달한 상태 정보를 저장할 주소
    - wait 함수의 리턴값은 자식 프로세스의 PID
    - 리턴값이 -1이면 살아있는 자식 프로세스가 하나도 없다는 의미

### 부모-자식 프로세스의 관리

- 부모 프로세스와 자식 프로세스의 종료 절차
    - 부모, 자식 프로세스는 순서와 상관없이 실행하고, 먼저 실행을 마친 프로세스는 종료
    - `wait()` 이 제대로 진행되지 않는 상황에 따라 좀비 or 고아 프로세스 발생
- 좀비 프로세스
    - 실행을 종료한 자식 프로세스의 종료 상태를 부모 프로세스가 가져가지 않는 경우
    - 좀비 프로세스는 프로세스 테이블에만 존재 (제한된 슬롯: PID는 모두 65536개)
        - 웹서버 등 사용자 요청에 따라 많은 프로세스를 생성해 사용하는 경우, 문제가 될 수 있음
    - 좀비 프로세스는 일반적인 제거 방법은 없음
- 고아 프로세스 (orphan process)
    - 자식 프로세스보다 부모 프로세스가 먼저 종료할 경우, 자식 프로세스들은 고아 프로세스가 됨
    - 이를 해결하기 위해, 고아 프로세스는 1번 프로세스(init)의 자식 프로세스로 등록
        - Init 프로세스가 `wait()` 를 호출해서 정상 종료시켜 줌

---

- 22日

# PS

압축
```cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;
    int cnt = 1;
    for (int i=0; i<26; i++) {
        string temp;
        char c = 'A' + i;
        temp += c;
        m[temp] = cnt++;
    }
    
    for (int i=0; i<msg.length(); i++) {
        string str;
        str += msg[i];
        int idx = i;
        while(m.find(str) != m.end()) {
            str += msg[++idx];
        }
        i += idx - i - 1;
        m[str] = cnt++;
        str.pop_back();
        answer.push_back(m[str]);
    }
    return answer;
}
```

압축 알고리즘 중 LZW 압축 알고리즘을 구현한 것으로, 문자열을 한 문자당 매핑되는 값을 두기 위해서 map 컨테이너를 사용하였고 그 중 속도를 개선하기 위해서 unordered_map을 사용했다. map 컨테이너에서 처음 보는 문자인 경우 cnt 값을 늘려서 넣어주고 아닌 경우에는 그대로 answer 벡터에 넣어주었다. 조금 더 줄이기 위해서 다른 사람들의 코드를 참고했다. 처음 짠 코드는 너무 장황해서 보기가 힘들었다.

---

- 23日

# Code Review with Github

## 코드 리뷰 개요

- 코드 리뷰
    - 협업 과정 중에 각자 수정한 코드를 서로 확인하는 과정
    - 목적: 협력을 통한 품질 향상
        - 오류 검출 뿐 아니라 코드 가독성도 높이고, 팀원들의 전체 코드에 대한 이해를 높여, 보다 품질 좋은 코드를 작성하기 위함
- 다양한 방식으로 수행
    - 회의를 열고 line by line 으로 세밀하게 체크
    - Merge, release 이후에 필요한 시점에 필요한 코드만 서로 확인

### 코드 리뷰 효과

- 버그 개수 감소
- 팀원의 트레이닝 도구로 활용
- 코드 가독성 증가 및 품질 상승
- 코드 세부 구현사항에 대한 기록 보존
- 팀 역량 상향평준화
- 디버깅 시간 및 프로젝트 수행 기간 단축

![image](https://user-images.githubusercontent.com/59367782/99927333-559bad00-2d88-11eb-89a1-0289511182b9.png)


### 코드 리뷰

- Experience from Naver Development team
    - 개발 전체 단계에서 코드 품질을 높이기 위한 노력
        - 표준 코드 스타일 제정
        - 단위 테스트, 코드 리뷰 회의
        - 자동화된 코드 품질 측정: Jenkins CI 도구의 plugin 사용
- 기존 코드 리뷰 방법
    - 개발 이후, 브랜치 병합 이후에 정례/비정례 코드 리뷰 회의
        - 회의 시간이 길어짐: 작성자의 코드 설명
        - 배포 이후라, 코드 리뷰를 생략하게 되고, 하더라도 오류를 뒤늦게 발견
- 코드 리뷰를 배포 이전에 강제할 필요가 있음
    - Gerrit을 코드 리뷰 시스템으로 선정하고, 개발 과정에 포함

### Githb 기반의 코드 리뷰

- Pull request 를 이용한 리뷰 운영 방법
    - 항상 Pull request를 이용해서 commit을 업로드함
        - 각 개발자는 fork해서, 혹은 개별 branch 에서 작업함
    - 리뷰 규칙을 정함
        - 예) Review master가 리뷰 여부 및 리뷰어 설정,
        - 리뷰 규칙: 1일 이내에 수정 요청, 코멘트 혹은 approve 여부 작성
            - 모든 response는 1일 이내에 할 것
    - 리뷰가 완료되면 review master가 merge (혹은 merge 담당에게 요청)
- 역할
    - Maintainer: repository 관리자 (merge 권한)
    - Reviewer: repository collaborator
    - Contributor: 외부 기여자

---

# AWS Network Servcies: Route 53

## AWS Route 53 (DNS Service)

- 참고 자료
    - [Route 53 설명서](https://docs.aws.amazon.com/route53/index.html)
    - [Route 53 개발자 메뉴얼](http://docs.aws.amazon.com/ko_kr/Route53/latest/DeveloperGuide/route53-dg-ko_kr.pdf)

### DNS

- 도메인 이름과 IP 간의 연결을 담당하는 서비스
- [AWS DNS 설명](https://aws.amazon.com/ko/route53/what-is-dns/)


### DNS related concepts

- 최상위 도메인(Top-Level Domain)
    - .com, .org 등 도메인 이름의 마지막 부분. 두 가지 유형의 TLD 존재
    1. 일반적인 최상위 도메인: 웹사이트의 내용과 연관되어 명명된 도메인
        - 예) .edu
    2. 지리적 최상위 도메인: 웹사이트의 지리적 영역과 연관되어 명명된 도메인
        - 예) .kr
- 도메인 등록 기관
    - 특정 최상위 도메인을 가진 도메인을 판매할 권리를 소유한 기관
- 도메인 등록 대행자
    - 국제인터넷주소관리기구(ICANN)가 인증한, 특정 최상위 도메인(TLD) 등록을 처리하는 회사.
    - 예) Amazon Registrar, Inc.는 .com, .net, .org 도메인의 등록 대행자

### AWS Route 53

- 클라우드 DNS 서비스
    - 최종 사용자와 웹서비스와의 연결을 담당
        - 53은 DNS service port
- 기능
    - 기본 DNS 기능, 트래픽 관리, 도메인 이름 등록, 상태 확인
        - 공개 DNS 레코드를 생성하고 관리함으로써 서비스 상태에 따라 동적으로 도메인 이름과 IP의 연결을 변경 가능
- 비용: 종량 과금제 (pay-per-use)
    - 호스팅 영역, 트래픽 흐름, 쿼리 당 요금제 적용
    - [AWS 요금 정책](https://aws.amazon.com/ko/route53/pricing/)

![image](https://user-images.githubusercontent.com/59367782/99928163-42d6a780-2d8b-11eb-8e46-87cf8b4e2b37.png)


### Rotue 53의 특징

- 가중치 기반 규칙 (1:1, 1:10)
- 장애 조치 규칙 (Primary, Slave)
- 지리 위치 규칙 (USA, Asia)
- 지연시간 규칙 (Region-based)
- 다중 응답 규칙 (Random)
- 엔드포인트
    - 최종 도달점 (S3, EC2 등) 설정

### DNS 서비스

- 단순히 도메인 이름과 IP 주소 간의 변환 기능만 제공하는 것이 아니라, DNS를 활용한 서비스 전달 경로의 설정이 가능함
    - 사용자는 동일한 Domain name으로 접근하고,
    - 지역에 따라, 혹은 가용 상태에 따라 서로 다른 Region, AZ에서 실제 서비스를 제공함
- 최상위 레벨의 Load balancing, traffic management 역할을 수행할 수 있음

---

# HTTP and WWW

## Server-side Programming

- 사용자 요구에 맞게 Dynamic 혹은 Active document를 생성하기 위해 서버쪽에서 행하는 프로그래밍
- 결국 HTTP request 메시지를 수신할 때마다 서버에서 사용자 입력을 가지고 코드를 실행

### 종류

- CGI
- PHP
- JSP
- ASP
- Node.js
- Go
- ...

### CGI

![image](https://user-images.githubusercontent.com/59367782/99930171-7289ad80-2d93-11eb-8a8d-6f4b4ec507ca.png)

- Web server가 test.pl에게 데이터를 넘겨주는 방법이 문제
    - Web serve와 test.pl은 둘 다 process이므로 process communication 문제
    - GET 방식이면 test.pl process의 환경 변수에 저장
    - POST 방식이면 test.pl process의 표준 입력에 저장
- 한 서버에 process 숫자가 100개 넘어서면 **scalability** 문제가 발생

### PHP

![image](https://user-images.githubusercontent.com/59367782/99930395-3b67cc00-2d94-11eb-81e7-eb215b14db4d.png)

- Web server가 test.php를 직접 실행하므로 CGI와 같은 데이터 전달 문제가 없음
- HTTP request가 많아져도 process 숫자가 증가하지 않으므로 **scalability** 문제 완화

### ASP

![image](https://user-images.githubusercontent.com/59367782/99931063-8e428300-2d96-11eb-898a-767fbd3b606d.png)

- 서버가 Microsoft 운영체제이어야만 하며 윈도우 운영체제의 보안문제에 취약
- 윈도우 서버가 scalability가 좋지 않기 때문에 확장성 측면에서 다소 불리
- 윈도우 서버가 유닉스 서버에 비해 설치가 쉽기 때문에 학원에서 많이 다룸
    - 운영체제가 특정 한 회사에 한정되고 표준과 무관하므로 가급적 피하는 것이 좋음

### JSP

![image](https://user-images.githubusercontent.com/59367782/99931097-af0ad880-2d96-11eb-9760-4dd433286f95.png)

- Web server가 test.jsp를 직접 실행하므로 CGI와 같은 데이터 전달 문제가 없음
- Java 언어에 익숙한 사용자가 server side programming할 때 고려
- 생성 -> 변환 -> 실행을 해야하기 때문에 서버 부하가 큼 (대략 PHP 방식보다 2-3배 느림)

### Node.js

![image](https://user-images.githubusercontent.com/59367782/99931141-d2358800-2d96-11eb-853a-ef07dcff3ac2.png)

- Client 웹 페이지에 개발에 사용된 자바스크립트를 서버에도 사용
    - 자바스크립트에 익숙한 개발자들이 서버 프로그래밍할 때 용이
    - 비동기 I/O 사용 (I/O가 많은 작업을 처리할 때 유리)

### Go

![image](https://user-images.githubusercontent.com/59367782/99931189-f729fb00-2d96-11eb-90c3-65aa50922960.png)

- Google이 networked server, tools, system programming에 적합하게 **단순(simplicity)**하고 고성능을 목적으로 개발
- 새로운 언어인 GO를 배워야 하는 부담이 존재
- 클래스 계층구조를 없애고 복잡한 객체는 composition으로 생성
- 일반적으로 현재 **가장 고성능**

### Performance 비교

- 일반적으로 (GO , Node.js )-> (PHP, ASP) -> JSP -> CGI
- 각 sider-side programming은 계속 성능 개선을 하고 있으므로 유의
    - CGI -> FastCGI, PHP -> ReactPHP (event-driven), … 
- 응용의 특성 (예: I/O 요구 특성)에 따라 성능이 달라질 수 있음
- 프로젝트의 특성(예: 보안, 호환성 유지 등)에 따라 맞는 것을 선택

---

# Multimedia

### 기술

- Video 데이터
    - 640x480 (VGA) x RGB (3byte) x 30 fps x 3600s(1 hour) = 약 100GB
        - 1990년 초 HDD 1MB 당 1만원 산정시 10억
    - 고효율 압축은 선택이 아닌 필수
    - B-ISDN 서비스의 경우 초기에 저해상도, 저프레임, CBR 영상 서비스 추진
        - 90년대 Video-On-Demand(VOD) 서비스 추진 -> 사업접기 -> 2000년대 다시 추진
            - 당시 video data는 HDD, 테이프 등에 저장 후 전송하는 연구
            - 당시의 인프라, 하드웨어 환경, 사회적 배경을 기준으로 당시 선택을 평가해야 하고, 미래에 대한 안목의 중요성을 알 수 있음

- 90년대 이후 Video 데이터 압축 표준 진행
    - MPEG-1 (기존 TV 품질 압축)
        - 인텔 펜티엄 CPU 성능으로 소프트웨어 압축을 시연
    - MPEG-2 (HDTV 품질 압축)
    - MPEG-3 (mp3 – 음성 압축)
    - MPEG-4 (.mp4 – 객체기반 압축)
        - 개념은 화면 단위가 아닌 한 화면내 객체 단위로 압축
        - 실제 구현은 Layered encoding (base layer + enhanced layer)
        - T-commerce의 미래로 기대했으나 아직 미미한 실정


### Internet audio/video

- Internet audio/video
    - Streaming stored audio/video
        - ex) VOD
    - Streaming live audio/video
        - ex) radio, TV
    - Interactive audio/video
        - ex) zoom

## Audio/Video Compression

### JPEG gray scale

![image](https://user-images.githubusercontent.com/59367782/99933755-4bd17400-2d9f-11eb-9da7-2989f1955ec6.png)

- 이미지 하나를 압축하는 방식
- 블락 단위로 인코딩
- 전송 중에 데이터가 깨지더라도 해당 프레임만 영향을 받는다.

### JPEG process

![image](https://user-images.githubusercontent.com/59367782/99933825-77545e80-2d9f-11eb-9c5e-1e2e92770dff.png)

### process

- uniform gray scale

![image](https://user-images.githubusercontent.com/59367782/99933842-863b1100-2d9f-11eb-9f50-905856d5f137.png)

- two sections

![image](https://user-images.githubusercontent.com/59367782/99933843-8804d480-2d9f-11eb-9d28-9cee5456db4f.png)

- gradient gray scale

![image](https://user-images.githubusercontent.com/59367782/99933849-89ce9800-2d9f-11eb-88a2-d18c8fab344b.png)

### Reading the table

![image](https://user-images.githubusercontent.com/59367782/99933904-b5ea1900-2d9f-11eb-8d30-baef25814167.png)

해당 데이터를 압축한 것이 JPEG라고 할 수 있다.

### MPEG frames

![image](https://user-images.githubusercontent.com/59367782/99933935-ce5a3380-2d9f-11eb-9446-088ca30281aa.png)

- construction

![image](https://user-images.githubusercontent.com/59367782/99933938-cf8b6080-2d9f-11eb-8f76-5aff029c994b.png)

- 여러 패턴이 존재
- I 프레임은 다른 프레임을 참조하지 않고 자기 자신만을 압축
- B 프레임은 I 프레임을 참조
- P 프레임은 B, I 프레임 참조
- 만약 I 프레임이 깨진 경우 전부 깨짐

## Streaming Stored Audio/Video

### Using a Web server

![image](https://user-images.githubusercontent.com/59367782/99935728-bafd9700-2da4-11eb-8ed2-5f99229eed37.png)

- Using a Web server with a metafile

![image](https://user-images.githubusercontent.com/59367782/99935749-c650c280-2da4-11eb-811b-5a811489f085.png)

- Using a media server

![image](https://user-images.githubusercontent.com/59367782/99935783-d9639280-2da4-11eb-828f-de7ab756b07d.png)

- Using a media server and RTSP

![image](https://user-images.githubusercontent.com/59367782/99935810-e97b7200-2da4-11eb-8428-f33790720275.png)

## Voice Over IP

- SIP(Session Initiation Protocol) : 멀티미디어 세션 제어 프로토콜
- H.323 : 시청각 통신 세션을 제공하는 프로토콜 (ex. 화상 회의)

### SIP Messages

- INVITE
- ACK
- BYE
- OPTIONS
- CANCLE
- REGISTER

**전화 -> SIP**

### SIP formats

- IPv4 address
- Email address
- Phone number

### H.323 architecture

![image](https://user-images.githubusercontent.com/59367782/99936015-6eff2200-2da5-11eb-8452-f76f91d76f41.png)

- 인터넷 상에서 화상 회의에 쓰이는 표준 프로토콜이다.

### H.323 protocols

![image](https://user-images.githubusercontent.com/59367782/99936020-758d9980-2da5-11eb-97fb-f4f87916b23d.png)

- 추가적으로 데이터 공유도 포함되어있다.

### example
![image](https://user-images.githubusercontent.com/59367782/99936025-77575d00-2da5-11eb-9767-98ef9a349e5e.png)

---

- 24日

# 자료흐름 중심 설계 (Data Flow Oriented Design)

## 구조적 설계의 기본 개념

- 구조적 분석기법에서 사용하는 **자료흐름도**(DFD)가 논리적인 관점에서 자료흐름과 기능을 기술한다고 하면, 구조적 설계에서 사용하는 **구조도표**(structure chart)는 소프트웨어의 구조와 설계를 구체적으로 나타내는데 사용된다.
- 구조적 설계는 사용자의 요구사항이 자료흐름도로 표시되어 있음을 가정하고 있다.
- 자료흐름을 나타내는 표기법은 다른 많은 공학과 학문 분야에서도 오랫동안 사용되어 왔다. 소프트웨어 분야에서는 이러한 표기법이 구조적 설계 기법을 만들어낸 저자들에 의하여 소개되어 사용되었다.

### 프로그램 구조

- 구조적 설계를 위한 입력은 DFD에 기초한 요구사항 명세서이다.
- 구조적 설게는 DFD에 포함되어 있는 정보를 프로그램 구조의 모습을 가진 설계로 전이하는데 요구되는 가이드라인과 법칙들을 제공하고 있다.
- 프로그램 구조는 소프트웨어 모듈들 사이의 제어를 보여주는 계층적인 구조를 가지고 있다.
- **프로그램 구조**는 서로 연결되어 있는 소프트웨어 모듈들로 구성되어 있다. 또한 프로그램 구조는 호출하는 모듈과 호출되는 모듈 사이의 관계를 나타내어 준다.

### 구조도표의 표기법

- 구조도표(structure chart)는 모듈간의 자료와 제어 정보의 교환, 주요 루프, 의사 결정 등을 보여 주며, 설계 단계에서 모듈체게와 모듈들 사이의 상호교류 내용을 나타내주는 모델
- 구조도표는 구조적 설계(architectural design)의 결과를 나타내는데 사용되며, 소프트웨어 시스템이 상호 유기적인 관계를 가지고 작용하는 기능들로 분할된 모습을 보여 준다.
- 구조도표에서 사각형은 모듈을 나타내며, 오각형으로 표시된 것은 다른 페이지로 연결(off-page connector)되어 있는 모듈을 나타낸다.
- 또한 모듈사이의 정보흐름은 작은 원이 있는 화살표로 표시되어 있으며, 속이 하얀 것은 데이터 흐름(data flow)을 나타내고 속이 까만 것은 제어흐름(control flow)을 나타낸다.

## 정보 흐름의 유형

- 자료흐름도는 시스템의 자료흐름과 자료처리 기능을 보여준다. 프로세스의 동작을 크게 두 가지의 유형으로 나눠 볼 수 있다.
- **변환흐름**: 입력을 받아들여 가공 처리한 후 새로운 결과물을 만들어 내는 프로세스를 들 수 있다. 이 경우 입력을 가공처리하는 기능을 수행하며 출력물은 입력을 정제한 것이라 볼 수 있다.
- **트랜잭션흐름**: 입력을 받아들여 입력 값에 의해 결정을 내린 후 입력과 관계없는 결과물을 출력하는 경우이다. 이 경우 프로세스는 주어진 입력에 의해 결정을 내리며 서로 다른 처리동작을 수행하여 출력물을 생성하는 것이다.

### 자료 흐름 프로그램 구조로 전환

1. 우선 요구사항 분석에서 나온 결과를 검토하고 필요하면 수정한다.
2. 자료흐름의 유형을 조사한다. 자료흐름 유형은 변환흐름과 트랜잭션 흐름이 있다.
3. 자료흐름의 유형에 따라 흐름의 경계를 정한다.
4. 자료흐름도를 프로그램 구조로 매핑시킨다.
5. 분할하여 제어계층 구조를 정의한다. 상위 레벨부터 분할하여 하위레벨로 내려가는 하향식 접근방법을 사용한다.
6. 결과를 설계의 가이드라인과 시스템의 특성을 고려하여 다듬는다.

## 변환흐름 중심 설계

- 변환흐름 중심 설계는 정보를 받아들여 가공처리한 후 그 결과를 외부세계에 출력하는 시스템을 이에 합당한 컴퓨터 구조로 매핑시키는 기법
- 이 기법은 시스템을 구성요소들로 분할시켜주며 기본적인 기능을 수행하는 모듈들과 모듈들 사이의 계층구조를 생성한다.
- 변환흐름 중심은 시스템을 3가지로 나눌 수 이싿.
    - 입력흐름: 입력을 받아들여 시스템에서 사용할 수 있는 데이터로 정제하는 일을 수행한다.
    - 변환중심: 데이터를 가공처리하는 기능을 담당한다. 계산을 수행하는 대부분의 프로세스들이 이 범주에 들어간다고 할 수 있다.
    - 출력흐름: 가공처리된 정보를 받아 적당한 출력물로 변환시켜 출력한다.

### 변환흐름 중심 시스템

`외부입력 -> 입력접수 -> 정제된 입력 -> 입력 가공 -> 결과물 -> 출력생산 -> 출력`

### 프로그램 구조로 전환 가이드라인과 단계

- 1단계: 요구사항 명세서로부터 정제된 자료흐름도를 만든다.
    - 구조적 기법에서 요구사항 명세서는 균형을 이루며 계층적인 구조를 띈 자료흐름도의 집합이다.
    - 최상위 계층의 자료흐름도인 배경도와 다이어그램은 구체적인 정보흐름을 나타내기 어려우며, 각각의 하위계층 자료흐름도는 구체적인 정보흘므을 나타내나 한정된 부분의 내용만을 포함하고 있다.
    - 상위 계층으로부터 하위 계층으로 내려가며 하위 계층의 자료흐름도를 상위 계층의 자료흐름도에 합하여 하나의 자료흐름도를 만든다.

- 2단계: 자료흐름의 유형을 조사한다.
    - 자료흐름도가 변환흐름 특성을 갖는지, 아니면 트랜잭션흐름을 갖는지 결정한다.
    - 만약 자료흐름도가 이와 같이 변환흐름을 주요 특성으로 가지고 있으면 다음 단계들을 적용하여 프로그램 구조를 만든다.

- 3단계: 입력경계와 출력경계를 정한다.
    - 입력 경계와 출력 경계를 명시함으로써 변환 중심을 고립시킬 수 있다. 이 단계는 3가지 세부 단계로 구성되어 있다.
    - 3.1단계: 입력 흐름과 관계되는 버블들을 규명한다. 이는 시스템의 외부객체로부터 자료흐름을 추적하여 외부와 연결된 모습을 조사하여 규명할 수 있다.
        - `회전수 -> 회전수 접수 -> 초당 회전수 -> 거리계산 -> 거리 -> + 시간 -> 속도계산 -> 속도`
    - 3.2단계: 출력흐름과 관계되는 버블들을 규명한다. 시스템의 내부 버블로부터 외부객체로 이동하는 자료흐름을 추적하여 규명할 수 있다.
    - 3.3단계: 입력흐름에 속한 버블과 출력흐름에 속한 버블들을 규명한다.
    
    - 입력되는 자료흐름의 경계는 외부객체로부터 들어오는 정제되지 않은 자료로 부터 시작하여 시스템에 입력으로 작용하는 정제된 자료를 만들어내는 가장 멀리 떨어진 버블을 포함한다.

- 4단계: 최상위 수준에서 자료흐름 중심 프로그램 구조 개발
    - 이제 자료흐름 중심의 프로그램 구조를 만들기 시작한다.
    - 이 과정은 Yourdon에 의해 '최상위 수준의 세분화'라 불러지며, 세분화는 분할을 의미한다.
    - 상위계층의 모듈은 시스템의 기능을 수행하지 않고, 다만 이러한 기능이 하위계층 모듈에 의해 수행될 수 있도록 분류하고 이관하는 일을 담당하도록 설계한다.
    - 최상위 수준의 세분화는 최상위 프로그램 구조를 얻는데 그 목적이 있다. 최상위 수준의 프로그램 구조는 추후 세부적이고 정제된 프로그램 구조를 얻는 출발점이 된다.

    - 변환흐름 중심의 자료흐름도에서 최상위 프로그램 구조의 3가지의 구성요소
        - 입력을 처리하는 입력 제어 모듈
        - 변환을 처리하는 변환 제어 모듈
        - 출력을 처리하는 출력 제어 모듈

- 5단계: 자료흐름도를 프로그램 구조로 전환 (두번째 수준의 세분화)
    - 입력 제어 모듈에 대한 세분화 작업은 다음과 같이 이뤄진다.
        - 입력 제어모듈에서 주모듈에 제공하는 입력 자료들을 규명한다.
        - 이 입력 자료를 만들기 위해 **요구되는 변환과 이를 수행하는 버블들을 규명**한다.
        - 변환을 수행하는 버블에 대응하는 변환 모듈을 만든다. 이 모듈은 상위 입력 모듈 아래에 둔다.
        - 변환 모듈에 입력을 제공하는 입력 모듈을 변환 모듈과 같은 계층에 놓는다.
        - 새로이 만들어진 하위 계층 입력 모듈을 세분화해 나간다.
    - 출력 제어 모듈에 대한 세분화 작업은 앞 작업의 역순으로 이뤄지며 다음과 같다.
        - 주모듈에 의해 **출력 제어 모듈에 제공되는 출력 자료들을 규명**한다.
        - 외부에서 보여지는 양식에 접근된 출력 자료를 만들기 위해 요구되는 변환과 이를 수행하는 버블을 규명한다.
        - 변환을 수행하는 버블에 대응하는 변환 모듈을 만든다. 이 모듈은 상위 입력 모듈 아래에 둔다.
        - 변환 모듈의 출력을 처리하는 출력 모듈을 변환 모듈과 같은 계층에 놓는다.
        - 새로이 만들어진 하위 계층 출력 모듈을 세분화해 나간다.

    - 입력흐름의 세분화
        - 변환중심과의 경계로부터 외부 입력을 받아들이는 방향으로 나악며 추가적인 세분화와 매핑이 이뤄진다.
        - 세분화는 **프로그램 구조의 상위 계층 모듈을 먼저 정의하고 아래**로 내려가며, 자료흐름도에서는 변환 중심과의 경계로부터 **왼쪽으로 진행**된다.
        - 자료흐름도의 버블은 일반적으로 **프로그램 구조의 모듈과 일 대 일**로 매핑된다.

    - 출력흐름에 대한 세분화 순서
        - 변환중심과의 경계에 가까운 버블로부터 시작하여 외부에 나가는 출력자료를 만드는 방향으로 이뤄진다.
        - 즉 자료흐름도의 중앙에서 시작하여 출력을 내보내는 오른쪽으로 이동하며 세분화는 프로그램 구조의 아래 방향으로 이뤄진다.

    - 변환중앙에 있는 모듈에 대한 세분화
        - 자료흐름도의 변환중앙에 있는 각 버블은 프로그램 구조의 새로운 모듈로 매핑될 수 있다.
        - 모든 변환 모듈들이 변환 제어 모듈의 아래에 올 수 있다. 즉 모든 변환 모듈은 변환 제어 모듈 바로 아래 계층의 모듈로 나타낼 수 있음을 의미한다.

두 번째 수준의 세분화
![image](https://user-images.githubusercontent.com/59367782/99963630-64f51780-2dd5-11eb-9203-7908186a35d6.png)


- 6단계: 프로그램 구조의 정제
    - 모듈 제거, 추가
    - 세분화, 통합

## 트랜잭션흐름 중심 설계

- 대부분의 시스템이 전체적인 관점에서 보면 변환흐름 중심이지만, 세부적인 경우를 들여다 보면 많은 경우 트랜잭션흐름 중심 설계가 프로그램 구조를 만드는데 사용될 수 있다.
- 트랜잭션이란 자료나 제어 시그널 등이 어떠한 행위를 유발시키는 것을 의미한다.
- 트랜잭션흐름에 의한 설계는 **들어온 입력을 여러 갈래의 출력흐름**으로 쪼갤 수 있는 경우에 가능하다.
- 이 경우 정보흐름의 중심을 **트랜잭션 중심**이라고 한다.

### 트랜잭션 중심 전환 가이드라인과 단계

- 1단계: 요구사항 명세서로부터 하나의 자료흐름도를 만든다.
- 2단계: 자료흐름도가 트랜잭션흐름을 갖는지 결정한다.
- 3단계: 트랜잭션 중심과 동작 경로를 파악한다.
    - 만약 자료흐름도가 트랜잭션흐름을 가지고 있는 경우 트랜잭션 중심이 어디있는가를 규명하는 일이 선행되어야 한다.
    - 트랜잭션 중심은 하나의 입력 경로와 여러 출력 경로를 가지고 있다. 각 동작 경로(출력 경로)는 여러 버블로 구성될 수 있으며, 변환흐름이나 트랜잭션흐름을 가질 수 있다.
- 4단계: 트랜잭션흐름 프로그램 구조 개발
    - 이 단계에서는 트랜잭션에 기초한 프로그램 구조를 만든다.
    - 이 구조는 세 구성 요소로 이뤄져 있다.
        - 트랜잭션 중심으로 작용하는 모듈
        - 입력을 받아들이는 모듈
        - 각 동작 경로에 **해당하는 하나 이상의 모듈**
- 5단계: 자료흐름도를 프로그램 구조로 매핑
    - 트랜잭션에 기초한 최초의 프로그램 구조가 만들어지고 난 후, 입력 제어와 각 동작 경로를 **세분화**하여 나갈 수 있다.
    - 각 경로마다 **새로이 프로그램 구조**를 만들어 나가는 것이라 볼 수 있으며 각 동작 경로와 입력 제어가 변환흐름 또는 트랜잭션흐름 중 어느 특징을 가지고 있는가 결정한다.
    - 동작 경로가 변환흐름을 가지고 있다고 하면 입력, 출력, 변환 중심의 경계를 정하게 된다. 또한 변환흐름에 적용될 수 있는 단계들이 적용된다.
    - 만약 동작 경로가 트랜잭션흐름을 가지고 있다고 하면 트랜잭션 중심과 동작 경로가 규명되고 트랜잭션흐름에 필요한 단계들이 적용된다.
    - 일반적으로 시스템은 변환흐름이 지배적이며 일부 트랜잭션 흐름을 가지고 있다.
    - 또한 일부 **트랜잭션흐름의 동작 경로**는 변환흐름의 특성을 가지며 다른 경로는 트랜잭션흐름 특성을 가질 수 있다.

- 6단계: 프로그램 구조 정제
    - 이 단계는 앞의 변환흐름에 기초한 프로그램 구조 정제 단계와 유사하다.
    - 변환흐름에 기초한 프로그램 구조가 정제되어야 하는 것과 마찬가지로 트랜잭션에 기초한 프로그램 구조도 정제되어야 한다.
    - 프로그램 구조는 **낮은 결합도와 높은 응집도를 얻을 수 있도록 세분화**되어야 하며, **구현과 시험이 용이하도록 프로그램 구조 정제 과정에서 세분화**되어야 한다.
    - 이러한 설계 방법은 기계적으로 이뤄지니 설계 단계에서 고려해야 하는 많은 요소들이 무시되어 이싿.
    - 결국 많은 경우 최적화가 필요하고, 이를 위해 환경과 응용분야에 대한 지식을 최대한 활용하여야 한다.

## 요약

- 구조적 설계는 구조적 분석기법으로 만들어진 요구사항 명세를 체계적으로 설계로 전환할 수 있도록 지원해주는 기법
- 구조적 설계는 **자료흐름도로 표시되어 있는 요구사항**을 **구조도표**로 표시하는 프로그램 구조로 전환한다.
- 자료흐름도에서 구조도표로의 전환은 요구사항 명세서에 표시되어 있는 **정보흐름의 유형을 판단**하여 이뤄진다.
- 일반적으로 두 가지 유형의 정보흐름이 있으며 **변환흐름**과 **트랜잭션흐름**이라 불리워진다.
- 구조적 설계는 시스템의 두 가지 유형에 따라 *요구사항을 설계로 매핑할 수 있는 단계와 가이드라인을 제시*하고 있다.
- 이러한 설계는 많은 정제를 필요로 하는 것이 일반적이며 좋은 프로그램 구조를 만들기 위해 설계 가이드라인이 적용된다. 이에 적용되는 기준으로는 *낮은 결합도, 높은 응집력, 구현과 시험의 용이성* 등이 있다.

---

# 데이터베이스 설계

### 데이터 디자인

- 정보 모델링은 시스템의 정적인 정보 구조를 나타내는데 사용
- 정보 모델링은 엔티티들을 정의하고 이들 사이의 연관성을 규명하는 작업
- 이 모델은 객체를 중심으로 객체의 특성을 정의한다.
- 정보 모델은 데이터를 개념적 차원에서 기술하며, 물리적인 면은 고려하지 않는다.
- 사용자의 관점을 나타내는 개념적인 단계에서는 시스템의 데이터가 어떻게 저장되고 유지되는지에 관한 세부사항을 나타낼 필요가 없다.

### 데이터 추상화 3단계

| 데이터 추상화 3단계 | 데이터 |
|---|---|
| 관점 단계 | 뷰 |
| 개념 단계 | 개념적 스키마 |
| 물리 단계 | 물리적 스키마 |

- 뷰 단계는 데이터베이스 사용자들의 서로 다른 요구사항과 관점을 나타내는 단계이다.
- 각 사용자는 자신의 직무 및 역할과 관련된 일부분에만 관심을 가지고 이싿.
- 뷰 단계에서 규명된 다양한 사용자의 고나점과 데이터가 모여 통합되는 과정이 두 번재 단계인 개념 단계
- 이 단계에서 다양한 사용자로부터 요구사항이 통합되며, 이를 **뷰 통합**이라 부른다.
- 뷰 통합이 이뤄진 후 EER 모델로부터 데이터의 저장을 위한 물리적인 구조를 설계해야 한다. 이 단계를 물리적 단계라 부르며, **소프트웨어 개발 라이프사이클의 설계 단**계에 해당한다.

## 관계형 모델

- 관계형 모델은 Codd에 의해 1970에 처음 소개되었으며, 간단하며 단순한 구조를 가지고 있으 많은 사람들이 이용
- 관계형 모델은 테이블을 이용하여 나타낸다. 각 테이블은 릴레이션이라 불리워지며, 테이블의 각 행은 튜플이라 불리워진다.
- 각 튜플은 연관된 데이터 값들의 모임으로 실세계의 엔티티나 관계를 나타낸다.
- 관계형 모델은 수학에서의 집합 이론에 근거하고 있다. 각 테이블은 집합이며, 테이블의 각 튜플은 집합의 원소에 해당한다.
- 각 테이블은 여러 속성들의 모임으로 정의되며, 테이블 열 머리 부분에 표시된다.

### 관계형 모델 제약 조건

- 데이터 제약 조건: 도메인 제약 조건, 키 제약조건, 매핑 제약조건, 참여 제약조건, 참조 무결성 제약조건 등
- 이러한 제약조건을 일반적으로 무결성 제약조건이라 부르며, 무결성 제약 조건의 목적은 데이터베이스에 잘못된 데이터가 들어가지 않도록 제약을 가하는 것
- 실제로 바람직한 데이터베이스는 데이터에 대하여 실세계에서 요ㅕ구하는 제약조건을 정확히 반영할 때 가능

## 매핑

- 1단계
    - EER 모델의 각 엔티티 타입에 대해 하나의 테이블을 만들고, 엔티티 타입의 속성들을 테이블의 속성으로 포함
    - 엔티티 타입의 주키는 테이블의 주키가 된다. 필요하면 시스템 생성키 사용
- 2단계
    - 두 엔티티 타입이 이차 관계 타입으로 일 대 일 대응 관곌르 가지고 있는 경우, 이 관계 타입은 두 엔티티 타입 중 하나에 포함될 수 있다.
    - 만약 참여 제약조건이 필수인 엔티티 타입이 있으면 필수인 엔티티 타입에 포함시키는 것이 일반적이다.
    - 만약 두 엔티티 타입이 모두 필수적으로 차명하고 있는 경우 두 엔티티 타입과 관계 타입을 하나의 테이블로 묶어 나타낼 수도 있다.
    - 두 엔티티 타입이 다른 관계 타입에 참여하지 않을 때 이렇게 합치는 것이 가능하다.
    - 엔티티 타입이 선택적으로 일 대 일 매핑을 하는 경우 두 엔티티를 합치는 것은 일반적으로 바람직하지 않다.
- 3단계
    - 두 엔티티 사이의 관계가 일 대 다 매핑의 경우에도 일(1-side)로 참여하는 엔티티 타입의 테이블에 관계 타입을 묶어 표현
    - 다수(N-side)로 참여하는 엔티티 타입의 주키를 외래키로 포함시킬 수 있다.
- 4단계
    - 두 엔티티 타입 사이에 이차 다 대 다 관계가 있는 경우, 관계 타입을 위해 독립적인 테이블 S를 만든다.
    - **참여 엔티티 타입의 주키들은 S에 외래키**로 포함시킨다.
    - 일반적으로 *참여 엔티티 타입의 주키들이 합친 것이 S의 주키*가 된다.
    - 만약 **관계 타입에 속한 속성이 있는 경우** S의 속성이 된다.
- 5단계
    - 만약 관계 타입의 차수가 3차 이상인 경우 새로운 테이블 S를 만든다.
    - 참여 엔티티 타입의 주키들은 S에 외래키로 포함시킨다.
    - 일반적으로 참여 엔티티 타입의 주키들이 합쳐져 S의 주키가 된다.
    - 또한 관계 타입에 속한 속성들이 있으면 S에 속성으로 포함시킨다.
- 6단계
    - 계층적 구조 (선택1)
        - 상위 클래스에 해당하는 테이블을 만들고 상위 클래스에 주키를 포함한 모든 속성을 포함시킨다.
        - 하위 클래스마다 테이블을 만들고 주키를 포함한 하위 클래스의 모든 속성을 포함시킨다. 이 때 상위 클래스의 주키와 하위 클래스의 주키는 같다.
    - 계층적 구조 (선택2)
        - 각 하위 클래스에 대해 테이블을 만들고, 각 테이블에 상위 클래스의 모든 속성을 포함시킨다.
        - 즉 상위 클래스의 모든 속성은 하위 클래스에 상속되어 나타나며, 상위 클래스를 위한 테이블은 따로 존재하지 않는다.
        - 이러한 선택은 해체, 전체 특수화의 경우에만 가능하다.
    - 계층적 구조 (선택3)
        - 하위 클래스를 모두 합하여 하나의 테이블로 나타낸다.
        - 상위 클래스의 속성들도 이 테이블에 포함시킨다.
        - 하위 클래스들 사이에 해체 조건이 있는 경우, 새로운 속성 t를 추가하여 각 튜플이 어느 하위 클래스에 속한 것인지 구별한다.
        - 이러한 접근 방법을 취하는 경우 많은 속성들이 null 값을 가질 수 있다는 단점을 가지고 있다.
    - 계층적 구조 (선택4)
        - 3번째 선택과 마찬가지로 하위 클래스를 모두 합하여 하나의 테이블로 나타낸다.
        - 하위 클래스들 사이에 중복조건이 있어 상위 클래스에 있는 한 엔티티가 여러 하위 클래스에 존재할 수 있는 경우, 새로운 속성들 `t1, t2, t3, ... tm`을 추가하여 각 튜플이 어느 하위 클래스에 속한 것인지를 구별한다.
        - 중복 특수화의 경우 이러한 선택이 가능하며, 서브 클래스의 수만큼 논리값을 가지는 타입의 수를 만든다.

## 중복성 관리와 정규화

- 데이터의 중복성은 많은 문제를 야기시킨다.
- 데이터의 불필요한 중복성을 줄이고 정보의 검색이 용이하도록 테이블들을 정의하는 일이 중요
- 논리적인 관점에서 보면 데이터는 오직 한 번만 저장되어야 한다.
- 데이터의 중복성 문제는 물리적인 구현 단계에서 발생한다.
- 제어된 중복성: 중복되는 데이터를 제어할 수 있도록 한다.
- 이상: 제어되지 않는 데이터의 중복의 결과로 초래하는 특성
    - 삭제 이상
    - 삽입 이상
    - 갱신 이상

### 제1 정규형

- 테이블의 각 속성들이 쪼개질 수 없는 값을 가지며, 각 튜플의 속성이 이의 도메인으로부터 오직 하나의 값만을 가질 때, 이 테이블은 1NF라 한다.
- 1NF이 아닌 경우 관계형 데이터베이스에서 제공하는 기본 오퍼레이션을 사용할 수 없으며, 관계형 데이터베이스의 중요한 개념인 함수적 종속성, 키 등에 관한 이론이 적용되지 못한다.

### 제2 정규형

- 테이블이 1NF이고, 키가 아닌 각 속성이 모든 키에 대하여 **완전 함수 종속**될 때 이 테이블은 2NF이라 한다.

### 제3 정규형

- 테이블이 2NF이고, 키가 아닌 속성들이 어떤 키에도 이행적으로 종속되지 않을 때 이 테이블은 3NF이라 한다.

## 뷰

- 관계형 DBMS에 실제 존재하는 테이블이 있다.
- 한편 사용자에게 보여지거나 연산을 위해 만들어진 **가상적인 테이블**이 존재하며, 뷰라한다.
- 뷰는 실제 존재하는 테이블로부터 연산을 수행하여 그 결과를 보여주는 것이며, 사용자는 뷰를 통하여 실제 데이터베이스에 접근하게 된다.
- 뷰는 그 자체가 권한을 관리하는 메커니즘이라 할 수 있다.
- 뷰를 통해 실제 테이블의 일부 속성만을 검색하는 권한을 부여할 수 있다.
- 데이터 추상화 3단계를 보면 사용자의 요구사항을 나타내기 위해 뷰를 정의하고, 이를 개념적 스키마와 매핑하는 과정이 필요함을 알 수 있다.
- 또한 뷰는 실제로 존재하지는 않지만 자주 참조할 필요가 있는 테이블을 명시하는데 사용한다.

### 뷰 갱신

- 대부분의 경우 뷰를 통해 데이터를 검색하게 되며, 뷰에 대한 검색 질의는 아무런 제약을 받지 않는다.
- 그러나 뷰를 통해 데이터를 갱신하는 것, 즉 뷰갱신은 복잡하고 애매모호하여 문제를 일으킬 수 이싿.
- 한 물리적 테이블에서 만들어진 뷰를 통해 데이터를 갱신하는 경우에는 큰 문제가 없을 수 있으나, 여러 테이블을 조인하여 뷸르 만든 경우 여러가지 해석이 가능한 경우들이 있다.
- 뷰 갱신을 제대로 수행하기 위해 특정 원칙들이 사전에 수립되어야 한다.
- 일반적으로 뷰를 통한 갱신은 물리적인 데이터베이스에 관한 충분한 지식을 가지고 있는 제한된 사용자에게만 허용하는 것이 바람직하다.

## 시스템의 데이터 처리

- 일반적으로 데이터의 저장은 파일, 데이터베이스, 자료 구조에 의해 구현된다. 어느 것을 사용할 것인가의 문제는 여러 요소에 의해 결정될 수 이싿.
- 데이터의 양이 너무 많고 구조화하기 어려운 경우이거나 많은 양의 데이터임에도 불구하고 빈번한 검색이 요구되는 경우, 원시 데이터 또는 오래 저장될 필요가 없는 휘발성이 강한 데이터를 가지고 있는 경우에는 파일에 저장하는 것이 타당하다.
- 파일을 사용하는 것이 자료를 저장하는 가장 값싼 방법이다. 파일을 사용하여 자료들을 영구히 저장할 수 있다. 그러나 파일을 사용하는 경우 각 자료를 관리하는 프로그램을 만들어야 하며, 많은 경우 응용 프로그램과 파일 관리 기능이 분리되기 어려워 이식성에 문제가 생길 수 있다.
- 한편 데이터가 DBMS에 저장되어야 하는 경우는 많은 사용자가 동시에 데이터를 사용하거나, 보다 나은 자료 관리가 요구되는 경우이다. 서로 다른 하드웨어와 소프트웨어에 데이터를 이식시켜야 하는 경우에도 DBMS를 사용하는 것이 좋다.
- DBMS는 표준화된 인터페이스를 응용 시스템에 제공할 수 있으며, 자료에 대한 보안, 일치성, 병행 처리 등과 같은 기능을 제공한다. 시스템 개발자는 데이터를 처리하는 많은 기능을 프로그램할 필요없이 시스템 개발을 할 수 있다.

## 요약

- 이 장에서는 요구사항 분석 단계에서 나타난 정보 모델링의 결과를 관계형 데이터베이스로 설계하는 과정에 대하여 살펴보았다.
- 관계형 데이터베이스로 설계는 정보 모델링의 결과인 엔티티, 엔티티의 속성, 엔티티 사이의 연관성을 관계형 데이터베이스의 기본 구조인 테이블로 매핑하여 이뤄진다.
- EER 모델에서 관계형 모델로의 매핑은 쉽게 자동적으로 이뤄지는 부분이 많으며, 전환을 위해 필요한 가이드라인과 단계가 제시되어 있다.
- 관계형 모델에 있는 데이터가 고도의 정확도와 일관성을 유지하기 위해 만족해야 할 제약 조건들이 있다. 이러한 제약조건으로는 도메인 제약조건, 키 제약조건, 매핑 제약조건, 참여 제약조건, 참조 무결성 제약조건 등이 있다.
- 관계형 데이터베이스를 설계할 때 중점적으로 고려되어야할 사항은 불필요한 데이터의 중복성을 줄이고 정보의 검색이 용이하도록 테이블들을 정의하는 일이다. 동일한 정보를 여러 번 저장하는 중복성은 여러 문제를 야기시킨다. 논리적으로는 한 번이지만 물리적으로는 데이터가 중복된 횟수만큼 반복하여 변경해야 한다.

---

# IPC: Signal and Shared Memory

## IPC: Inter-process communication

### IPC의 필요성

- Many processes are co-operating
    - 서로 협업하는 프로세스: 한 가지 목적을 위해 여러 프로세스가 함께 동작
        - 큰 프로그램의 모듈화, 병렬 작업을 통한 성능 향상, 사용자 편의성 향상 등
        - 예) Game: video and audio processing, background data loading, chatting, etc.
    - 이를 위해서는 상호 간의 정보 교환이 필수
- 그러나 프로세스들은 가상 메모리 공간 (Virtual Memory Space) 에 갇혀 있음
    - **각 프로세스는 자기 자신만의 독립되고, 고립된 (isolated) 메모리 공간을 가짐**
        - 프로세스들은 서로 다른 프로세스의 space 를 침범할 수 없음! 존재조차 모름.
    - 함께 일을 해야 하는데, 그럼 어떻게 정보를 주고 받지? → **IPC**

### IPC: Inter-Process Communication

- IPC: 프로세스 간 통신
    - 모든 프로세스들의 공간에 접근할 수 있는 OS의 도움을 받아, 프로세스들 간에 서로 정보를 교환하는 것
    - 예) Message queue, shared memory, signal, pipe, socket 등
    - (더 쉬운 예. CTRL+C, V)
- 어떤 medium 을 어떤 방식으로 사용해서 정보를 전달하느냐에 따라 서로 다른 통신 특성을 갖게 됨
    - 커널 및 유저 메모리 공간, 네트워크 등이 medium 이 될 수 있음
    - 예) Signal: 커널 메모리 공간을 통해 아주 단순한 정보만 단방향으로 전달
    - 예) Shared memory: 유저 메모리 공간을 통해 양방향으로 정보 전달 가능
        - 그러나 양쪽이 동시에 데이터를 수정할 수 있기 때문에 동기화 문제 발생 가능
    - 예) Socket: 네트워크를 통해 원격 시스템에서 동작하는 프로세스와 통신 가능
- 협업 방식 및 상황에 따라 적절한 IPC 를 선택할 수 있어야 함

## Signal

### 시그널의 개념

- 시그널
    - 프로세스에 무슨 일이 발생했음을 알리는 간단한 메시지를 **비동기적**으로 보내는 것
    - 예) 메모: “전화왔음” (누구한테?? 거기까진 알 수 없음. 메모 종류도 한정적)
- 발생사유
    - 0으로 나누기처럼 프로그램에서 예외적인 상황이 일어나는 경우
    - Kill(2) 처럼 시그널을 보내는 시스템콜을 호출해 다른 프로세스에 시그널을 보내는 경우
    - 사용자가 CTRL+C 와 같이 키를 입력해 인터럽트를 발생시킨 경우
- 시그널 처리방법
    - **각 시그널에 지정된 기본 동작 수행. 대부분의 기본 동작은 프로세스 종료**
    - 무시: 발생한 시그널을 무시하고 진행
    - 핸들러 호출: 특정 시그널 처리를 위한 함수(핸들러)를 지정해두고, 시그널을 받으면 해당 함수를 호출
    - 블록: 발생한 시그널을 처리하지 않고 그대로 둠. 블록을 해제하면 그때 전달되어 처리

### 시그널 종류

![image](https://user-images.githubusercontent.com/59367782/100050890-d082c780-2e5d-11eb-8d97-38549679d545.png)

- OS에 따라 번호와 종류의 차이가 있을 수 있음
- 사용할 시그널의 자세한 내용은 항상 OS에 따라 확인하고 사용

### 시그널 보내기: kill(2)

```
# kill -9 3255
```

- (이미 배운) kill 명령어
    - 프로세스에 시그널을 보내는 명령 (예. PID가 3255인 프로세스에 9번 SIGKILL 전달)


```c
#include <sys/types.h>
#include <signal.h>

int kill(pid_t pid, int sig);
```

- 시그널 보내기: kill(2)
    - **pid가 0보단 큰 수 : pid로 지정한 프로세스에 시그널 발송**
    - pid가 -1이 아닌 음수 : **프로세스 그룹ID가 pid의 절대값인 프로세스 그룹**에 속하고, 시그널을 보낼 권한을 가지고 있는 모든 프로세스에 시그널 발송
    - pid가 0 : 특별한 프로세스를 제외하고 프로세스 그룹ID가 시그널을 보내는 프로세스의 **프로세스 그룹ID와 같은 모든 프로세스**에게 시그널 발송
    - pid가 -1 : 시그널을 보내는 프로세스의 유효 사용자ID가 root가 아니면, 특별한 프로세스를 제외하고 프로세스의 실제 사용자ID가 시그널을 보내는 프로세스의 **유효 사용자ID와 같은 모든 프로세스**에 시그널 발송

### 시그널 보내기: raise(2) and abort(3)

```c
#include <signal.h>

int raise(int sig);
```

- 시그널 보내기: raise(2)
    - 함수를 호출한 프로세스 자기 자신에게 시그널 발송

```c
#include <stdlib.h>

void abort(void);
```

- 시그널 보내기: abort(3)
    - 함수를 호출한 프로세스에 자기 자신에게 SIGABRT시그널 발송
    - SIGABRT 시그널은 프로세스를 비정상적으로 종료시키고 코어덤프 생성

### 시그널 핸들러: signal(3)

- 시그널 핸들러
    - 시그널을 받았을 때, 기본 동작을 대체하여 이를 처리하기 위해 지정된 함수
    - 시그널을 받으면, 받은 시점에 수행 중이던 코드에서 마치 핸들러를 호출한 것 처럼 동작
    - 프로세스를 종료하기 전에 처리할 것이 있거나, 특정 시그널에 대해 종료하고 싶지 않을 경우 지정

```c
#include <signal.h>

void (*signal(int sig, void (*disp)(int)))(int);
```

- 시그널 핸들러 지정: signal(3)
    - disp : sig로 지정한 시그널을 받았을 때 처리할 방법
        - 시그널 핸들러 함수명
        - SIG_IGN : 시그널을 무시하도록 지정
        - SIG_DFL : 기본 처리 방법으로 처리하도록 지정
    - (어떤 Unix 시스템에서는) 한 번 핸들러가 수행되고 나면, 핸들러 지정이 취소됨

### 시그널 핸들러: sigset(3)

```c
#include <signal.h>

void (*sigset(int sig, void (*disp)(int)))(int);
```
- 시그널 핸들러 지정: sigset(3)
    - disp : sig로 지정한 시그널을 받았을 때 처리할 방법
        - 시그널 핸들러 함수명
        - SIG_IGN : 시그널을 무시하도록 지정
        - SIG_DFL : 기본 처리 방법으로 처리하도록 지정
    - **sigset함수는 signal함수와 달리 시그널 핸들러가 한 번 호출된 후에 기본동작으로 재설정하지 않고, 해당 시그널 핸들러를 자동 재지정한다.**

### 시그널 핸들러: sigaction()

```c
#include <signal.h>

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

- sigaction 함수
    - signal이나 sigset 함수처럼 시그널을 받았을 때 이를 처리하는 함수 지정
    - signal, sigset 함수보다 다양하게 시그널 제어 가능
    - signum : 처리할 시그널 번호
    - **act : 시그널을 처리할 방법을 지정한 구조체 주소**
    - oldact : 기존에 시그널을 처리하던 방법을 저장할 구조체 주소
    - 첫번째 인자로 SIGKILL과 SIGSTOP을 제외한 어떤 시그널도 사용 가능

### struct sigaction

```c
struct sigaction {
    int sa_flags;
    union {
        void (*sa_handler)();
        void (*sa_sigaction)(int, siginfo_t *, void *);
    } _funcptr;
    sigset_t sa_mask;
};
```

- 핸들러의 동작을 보다 세밀하고 정확하게 제어하기 위한 정보를 전달
    - sa_flags : 시그널 전달 방법을 수정할 플래그
        - 예) SA_RESETHAND: 시그널 핸들러가 한 번 호출되면 지정이 취소됨
    - **sa_handler**/sa_sigaction : 시그널 처리를 위한 동작 지정
        - sa_flags에 SA_SIGINFO가 설정되어 있지 않으면 sa_handler에 시그널 처리동작 지정
        - sa_flags에 SA_SIGINFO가 설정되어 있으면 sa_sigaction 멤버 사용
    - **sa_mask** : 시그널 핸들러가 수행되는 동안 블록될 시그널을 지정한 시그널 집합

### 시그널 집합: sigset_t

```c
typedef struct {
    unsigned int __sigbits[4];
} sigset_t;
```

- 복수의 시그널을 한 번에 지정, 처리하기 위해 도입한 개념
    - Bit masking: 각 비트가 각각 시그널의 지정 여부를 표시
    - 프로세스 수행 상태에 따라 전체 시그널의 상태가 혼동스러울 수 있으므로, 항상 전체 시그널 모두에 대해 어떤 처리를 지정하도록 하기 위함

```c
int sigemptyset(sigset_t *set);
```

- 시그널 집합 비우기 : sigemptyset(3)
    - 시그널 집합에서 모든 시그널을 0으로 설정

```c
int sigfillset(sigset_t *set);
```
- 시그널 집합에 모든 시그널 설정: sigfillset(3)
    - 시그널 집합에서 모든 시그널을 1로 설정

```c
int sigaddset(sigset_t *set, int signo);
```
- 시그널 집합에 시그널 설정 추가: sigaddset(3)
    - signo로 지정한 시그널을 시그널 집합에 추가

```c
int sigdelset(sigset_t *set, int signo);
```
- 시그널 집합에서 시그널 설정 삭제: sigdelset(3)
    - signo로 지정한 시그널을 시그널 집합에서 삭제

```c
int sigismember(sigset_t *set, int signo);
```
- 시그널 집합에 설정된 시그널 확인: sigismember(3)
    - signo로 지정한 시그널이 시그널 집합에 포함되어 있는지 확인

### 시그널의 블록: sigprocmask(2)

```c
#include <signal.h>

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```
- how : 시그널을 블록할 것인지, 해제할 것인지 여부
    - SIG_BLOCK : set에 지정한 시그널 집합을 시그널 마스크에 추가
    - SIG_UNBLOCK : set에 지정한 시그널 집합을 시그널 마스크에서 제거
    - SIG_SETMASK : set에 지정한 시그널 집합으로 현재 시그널 마스크 대체
- set : 블록하거나 해제할 시그널 집합 주소
- oldset : NULL 또는 이전 설정값을 저장한 시그널 집합 주소
- Obsoleted services: sighold(2) and sigrelse(2)

### 시그널 대기: sigsuspend(2)

```c
#include <signal.h>

int sigsuspend(const sigset_t *set);
```
- 지정한 시그널(들)이 도착할 때까지 대기
    - set : **기다리려는 시그널들을 제외한 다른 모든 시그널들을 지정**한 시그널 집합
    - 정확한 동작: 현재 동작 중인 프로세스의 시그널 마스크를 set 으로 대치하여, 기다리려는 시그널들을 제외한 다른 시그널들은 블록 처리됨. 따라서 기다리려는 시그널만 프로세스로 전달될 수 있게 설정되는 것
- Obsoleted service: sigpause (2)

### 알람 시그널: alarm(2)

- 알람 시그널
    - 일정한 시간이 지난 후에 자동으로 시그널이 발생하도록 하는 시그널
    - 일정 시간 후에 한 번 발생시키거나, 일정 간격을 두고 주기적으로 발송 가능

```c
#include <unistd.h>

unsigned int alarm(unsigned int sec);
````

- 알람 시그널 생성: alarm(2)
    - sec : 알람이 발생시킬 때까지 남은 시간(초 단위)
    - 일정 시간이 지나면 SIGALRM 시그널 발생
    - 프로세스별로 알람 시계가 하나 밖에 없으므로 알람은 하나만 설정 가능

## Shared Memory

- 공유 메모리
    - 같은 메모리 공간을 두 개 이상의 프로세스가 공유하는 것
        - 물론 OS의 허가를 받고 공유함. 그런데 처음 허가 한 번 받고 나면 끝. OS는 관여하지 않음
    - 같은 메모리 공간을 사용하므로 이를 통해 데이터를 주고 받을 수 있음
    - 문제점: 동기화
        - A가 데이터를 기록하는 동안, 같은 위치에 B가 데이터를 쓰면?
        - A가 데이터를 아직 다 쓰지 않았는데, B는 다 쓴 줄 알고 데이터를 읽어가면?

### 공유 메모리 생성: shmget(2)

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int shmget(key_t key, size_t size, int shmflg);
```
- key : IPC_PRIVATE 또는 ftok()로 생성한 키 값
    - 상호 약속된 키 값을 기입해야 공유 메모리를 접근할 권한을 얻을 수 있음
    - IPC_PRIVATE: 부모-자식 간의 공유 메모리 공유를 위해 사용
    - key_t ftok(const char *pathname, int proj_id);
        - 주어진 파일명(절대 경로)과 proj_id 를 이용해 키 값을 생성함
        - 절대 경로, proj_id 가 동일해야 같은 키 값이 생성됨
- size : 공유할 메모리 크기. 페이지 크기의 배수로 지정.
    - 페이지: 메모리를 관리하는 기본 단위. 보통 4KB
- shmflg : 공유 메모리의 속성을 지정하는 플래그
    - IPC_CREAT: 공유 메모리 공간을 새로 생성함
    - IPC_EXCL: IPC_CREAT 와 함께 사용해서, 만약 기존 공간이 있다면 fail 하도록 설정
- 공유 메모리 식별자를 리턴
    - OS가 공유 메모리 공간을 관리하는 자료 구조를 가리킴. 파일 기술자와 유사.

### 공유 메모리 연결 및 해제

```c
#include <sys/types.h>
#include <sys/shm.h>
void *shmat(int shmid, const void *shmaddr, int shmflg);
```

- 공유 메모리 연결: shmat(2)
    - shmid : 공유 메모리 식별자
    - shmaddr : 공유 메모리를 연결할 주소
    - shmflg : 공유 메모리에 대한 읽기/쓰기 권한
        - 0(읽기/쓰기 가능), SHM_RDONLY(읽기 전용)

```c
#include <sys/types.h>
#include <sys/shm.h>
int shmdt(char *shmaddr);
```
- 공유 메모리 연결 해제: shmdt(2)
    - shmaddr: 연결을 해제할 공유 메모리 주소

### 공유 메모리 제어

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```

- 공유 메모리 제어: shmctl(2)
    - cmd : 수행할 제어기능
        - IPC_RMID : 공유 메모리 제거 (할당 해제)
        - IPC_SET : 공유 메모리 정보 내용 중 shm_perm.uid, shm_perm.gid, shm_perm.mode 값을 세번째 인자로 지정한 값으로 변경
        - IPC_STAT : 현재 공유 메모리의 정보를 buf에 지정한 메모리에 저장
        - SHM_LOCK : 공유 메모리를 잠근다.
        - SHM_UNLOCK : 공유 메모리의 잠금을 해제한다.

---

- 25日

# 카네기 행복론

행복론을 읽기 시작하였으며, 가장 기억에 남는 구절을 적어보려고 한다. 아직 몇 구절 읽지 못했지만 바로 기억에 남는 구절이 있다.  
`과거를 닫아 버리십시오. 지나간 일들은 과거로 묻어 두십시오.` 이 구절이다. 내일과 어제의 짐을 모두 오늘 지고 가려하면 강한 사람이라도 쓰러지기 마련이다. 그러므로 미래나 과거를 모두 닫아버리고 오늘에 충실하는 사람이 되라는 말이다. 생각하면 별거 아닌 구절일 수 있다. 하지만 항상 앞일과 뒷일에 신경쓰는 사람들은 현재에 집중을 하지 못한다. 직접 경험하기도 했으며 많은 사람들이 그러하다. 미래가 바로 오늘이라고 생각하며 오늘을 충실히 살면 미래도 충분히 좋아질 수 있다고 살아가는 것이 바로 카네기가 말하는 바라고 생각 된다.

걱정거리 해소 챕터에서 이야기한 부분이지만 이 부분은 인생살이의 전반에 걸쳐서 적용되는 부분이라고 생각한다. 항상 조급하게 생각하지 말고 이 모든 것이 미래를 위한 발돋움이며 나중에는 꼭 결실을 맺을 수 있다고 믿자.

---

- 26日

# 카네기 행복론

## 걱정을 극복하기 위한 기본 원칙

1. 걱정을 피하고 싶으면
    - 하루하루를 충실히 살아라
    - 미래에 대해서는 마음을 쓰지 마라
    - 잠들기 전까지 그날의 일만 생각하고 생활하라
2. 걱정에 사로잡혀 헤어날 수 없다면
    - 문제를 해결할 수 없을 때 최악의 상황을 생각하라
    - 불가피한 경우에는 최악의 상황을 받아들일 준비하라
    - 이후에는 침착하게 최악의 상황을 개선하기 위해 노력하라
3. 걱정을 계속하게 되면 건강을 해치는 엄청난 대가를 치른다는 것을 잊지마라. **걱정과 싸울 줄 모르는 사람은 단명한다.**

# 리트머스 DB 문서화

리트머스 데이터베이스 부분을 문서화하여 PR을 날렸다. 리트머스 프로젝트는 약 10년 전쯤에 만들어서 계속 이용해오는 프로젝트인데, 유지보수가 되지 않아서 많이 먼지가 쌓여있다는 표현이 맞는거 같다. 그 때에 문서화가 되어있지 않아서 지금 우리가 받아들이기에는 시간이 필요하다. 이 부분을 언젠간 해결해야 하므로 문서화를 시작하였다.

문서화를 하며 느낀 점은 분명 돌아가는 프로젝트지만 바로바로 이해하기 어렵다는 것이였다. 다음에도 누군가가 프로젝트에 기여할 수 있는데 그 누군가도 많은 시간을 할애해서 프로젝트를 이해한다면 악순환인 것이 확실했다. 따라서 문서화의 중요성을 느꼈고, 프로젝트를 개발한 뒤 유지보수도 분명 중요한 작업이기 때문에 이들을 위한 문서는 기본적으로 만드는 것이 협업의 시작이라고 생각이 든다.

학교에서 사용하는 lms를 만들고 관리하는 기업에서 실습을 진행할 때 느꼈던 클린 코드의 중요성과 이번에 리트머스 프로젝트에 기여하면서 느끼는 문서의 중요성은 나중에 실무를 하게 되었을 때 꼭 가지고 가야하는 부분이라고 생각된다. 이러한 부분을 조금 더 개선하기 위해서 클린 코드 책을 읽어보고 여러 개발자들의 협업에 대한 생각을 정리한 포스팅을 읽어보면서 나의 생각도 키워가야겠다.

---

- 27日

# PS

방금그곡
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<pair<string, int>> v;
    for (int i=0; i<m.length(); i++) {
        if(m[i] == '#') {
            string temp;
            temp += tolower(m[i-1]);
            string str = m.substr(0, i-1) + temp + m.substr(i+1);
            m = str;
        }
    }
    
    for (int i=0; i<musicinfos.size(); i++) {
        string start, end, title, music;
        start = musicinfos[i].substr(0, 5);
        end = musicinfos[i].substr(6, 5);
        
        bool flag = false;
        for (int j=12; j<musicinfos[i].length(); j++) {
            if(musicinfos[i][j] == ',') {
                flag = true;
                continue;
            }
            if(!flag) {
                title += musicinfos[i][j];
            }
            else {
                music += musicinfos[i][j];
            }
        }
        
        for (int j=0; j<music.length(); j++) {
            if(music[j] == '#') {
                string temp;
                temp += tolower(music[j-1]);
                string str = music.substr(0, j-1) + temp + music.substr(j+1);
                music = str;
            }
        }
        
        int begin = stoi(start.substr(0,2)) * 60 + stoi(start.substr(3));
        int last = stoi(end.substr(0,2)) * 60 + stoi(end.substr(3));
        // if(last == 0) {
        //     last = 24 * 60;
        // }
        int runtime = last - begin;
        string total_music = music;
        while(runtime > total_music.length()) 
            total_music += music;
        while(runtime < total_music.length())
             total_music.pop_back();
        
        if(total_music.find(m) != string::npos) {
            v.push_back({title, runtime});
        }
    }
    stable_sort(v.begin(), v.end(), cmp);
    if(!v.empty())
        answer = v[0].first;
    else
        answer = "(None)";
    return answer;
}
```

주어진 조건에 따라서 문자열을 파싱하고 계산 한 뒤 `find()`를 통해서 조건에 부합하는 노래 제목만 벡터에 넣은 뒤 안정 정렬을 통해 노래 재생 시간이 긴 순으로 내림차순 정렬하였다. 그 이후 인덱스 첫번째를 리턴하게 했는데, 이 과정에서 오타로 인해 2시간 정도 허비하였다. 바로 정렬의 매개변수를 잘못 기입한 것이었다. 이후에는 끝나는 시간이 00:00이 되는 경우를 처리해줄려고 했으나, 저 부분이 없어야 오히려 정답 처리가 되어서 당황스러웠다. 문제의 오점인지 나의 생각이 잘못된건지 모르겠지만 아쉬운 판단이였다.

---

- 28日

# PS

프렌즈 4블록
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool erase = true;
    
    while(erase) {
        bool arr[30][30] = {false,};
        erase = false;
        
        for (int i=0; i<m-1; i++) {
            for (int j=0; j<n-1; j++) {
                if(board[i][j] == 'x')
                    continue;
                
                char target = board[i][j];
                if(board[i][j+1] == target && board[i+1][j] == target && board[i+1][j+1] == target) {
                    arr[i][j] = true;
                    arr[i+1][j] = true;
                    arr[i][j+1] = true;
                    arr[i+1][j+1] = true;
                    erase = true;
                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if(arr[i][j]) {
                    for(int k=i-1; k>=0; k--) {
                        board[k+1][j] = board[k][j];
                        board[k][j] = 'x';
                    }
                    
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}
```

게임 구현사항을 구현하는 테스트로 2x2 블록이 같은 경우 해당 블록을 지운 뒤 블록이 얼마나 지워졌나 반환하는 문제였다. 처음에는 상당히 어렵게 생각하여 접근했으나, 완전탐색으로 다 훑으면서 2x2 블록이 전부 같은 블록인 경우 bool 배열로 체크해논 뒤 다시 한번 더 완전탐색으로 체크한 부분을 지운 뒤 위의 부분과 자리를 바꿔 위에 위치한 블록들이 아래로 내려오게 구현하였다.

---

- 29日

# PS

추석 트래픽
```cpp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gettime(string line) {
    int h = stoi(line.substr(11,2)) * 60 * 60 * 1000;
    int m = stoi(line.substr(14,2)) * 60 * 1000;
    int s = stoi(line.substr(17)) * 1000 + stoi(line.substr(20));
    return h + m + s;
}

int getduring(string line) {
    int sec = stod(line.substr(24)) * 1000;
    return sec;
}

int solution(vector<string> lines) {
    int answer = 1;
    vector<int> endTime;
    vector<int> duringTime;
    for (int i=0; i<lines.size(); i++) {
        endTime.push_back(gettime(lines[i]));
        duringTime.push_back(getduring(lines[i]));
    }
    
    int start, range;
    for(int i=0; i<lines.size(); i++) {
        int cnt = 1;
        range = endTime[i] + 1000;
        for (int j=i+1; j<lines.size(); j++) {
            start = endTime[j] - duringTime[j] + 1;
            if(start < range)
                cnt++;
        }
        if (answer < cnt)
            answer = cnt;
    }
    return answer;
}
```

트래픽이 주어질 때 1초간 가장 많은 처리를 한 횟수를 찾는 문제이다. string을 파싱하여 시작과 끝나는 시간을 구하되 시간의 기준은 ms로 한다. 이후엔 1초를 기준으로 얼마나 많은 트래픽이 있나 확인해야 한다. 거기에 주어진 배열은 처음에 끝나는 시간을 기준으로 오름차순으로 정렬이 되어있기 때문에 끝나는 시간에서 1초를 더한 뒤 자기 자신을 제외하고 그 뒤에 트래픽들을 시작시간을 구한뒤 시작시간이 1초을 더한 기준과 크기를 비교한다. 만약 시작시간이 더 작다면 포함되기 때문에 트래픽 수를 증가시킨다. 이러한 과정을 반복 한 뒤 그 중 가장 큰 값을 취해서 반환한다.

이 문제는 생각보다 오래걸렸다. 문자열 파싱은 금방하였으나, 이중포문을 통해서 일련의 과정을 적용할 때 오름차순으로 정렬되어 있으므로 시작시간이 기준보다 작지 않으면 해당 포문에서 break를 하는 오류를 범했다. 왜냐하면 오름차순이므로 그 뒤에는 적용되는 케이스가 없다고 착각했기 때문이다. 하지만, 트래픽의 실행시간이 각각 다르기 때문에 그렇게 생각하면 안되는 부분이였다. 오히려 뒷 부분에 있지만 실행시간이 길어서 포함이 될 수 있다는 것을 생각하지 못했다.

---

- 30日

# IPC: Socket

## TCP/IP Overview

- TCP/IP
    - 인터넷 통신을 위한 표준 프로토콜
    - 4계층으로 구성
    - Packet 단위로 데이터를 주고 받음

| 계층 | 이름 |
|---|---|
|L4 | 응용 계층 |
|L3 | 전송 계층 |
|L2 | 인터넷 계층 |
|L1 | 네트워크 엑세스 |

### IP address and hostname

- IP주소와 호스트명
    - IP 주소: 네트워크에서 특정 시스템 혹은 노드 (node)를 식별하는 주소 체계
        - 점(.)으로 구분된 32비트 값 (192.168.0.1)
    - Host name: 로컬 네트워크에서 시스템에 부여된 이름
    - Domain name: 인터넷에서 IP 주소에 대해 Domain Name Service 에 의해 부여된 이름
        - nslookup 명령을 통해 domain name 이 가리키는 IP 주소를 알 수 있음
    - Special IP address 127.0.0.1 (loopback) : 자기 자신을 가리키는 특수한 IP 주소
- Public and Private IPs
    - Public IP: 전체 인터넷 망에서 각 시스템을 구분하는 주소
        - 전세계 어디서든 동일한 IP로 특정 시스템에 접속 가능 (예. 203.254.143.152)
    - Private IP: Private (or local) network 에서 각 시스템을 구분하는 주소
        - 예) 우리집 공유기 안에서만 노트북, 핸드폰, 스마트 TV를 구분 (192.168.0.xxx)
- 호스트 명과 IP주소 간의 변환
    - /etc/hosts 파일 또는 DNS 등
    - /etc/nsswitch.conf 파일에 주소변환을 누가 할 것인지 지정

### Port

- Port: an endpoint of the network communication
    - 실제 통신을 수행하는 주체를 구분하는 번호
        - 주체: 호스트에서 동작하고 있는 서비스
        - 서비스: 한 프로세스가 여러 서비스(여러 포트를 통해)를 운영할 수도 있고, 하나의 서비스가 여러 프로세스를 이용해 동작할 수 있음
    - 2바이트 정수로 0~65535까지 사용 가능
    - `<IP address>:<port number>`형태로 전체 주소를 지정
        - 예) 203.254.143.152:80 -> 해당 호스트에서 동작하는 http 서비스
- 잘 알려진 포트
    - 잘 알려진 서비스들 (well-known services)의 포트 번호 (보통 1024 이하)
    - SSH(22), HTTP(80), FTP(21)
    - /etc/services : 잘 알려진 포트 번호들을 저장

### IP Network Communication

- IP 주소를 통해 네트워크 상에서 특정 호스트를 식별하고,
- Port 번호를 통해 호스트 내에서 특정 서비스를 식별하여,
- 원격 서비스들 간의 통신이 가능함

### TCP and UDP

- IP 상단의 전송 계층(L3)에서 통신을 위한 부가적인 기능을 제공하는 프로토콜들
    - IP 의 역할: 인터넷 상에서 특정 IP 주소를 가진 시스템을 찾아 패킷을 전해주는 것
    - TCP/UDP 의 역할: 단순히 패킷을 전달한다 라는 것을 넘어, 패킷을 순서대로 전달한다거나, 패킷이 전달되었다는 것을 보장한다거나, 패킷을 보내는 속도를 조절하여 성능을 극대화 하는 등의 부가 기능을 수행
    - 일반적으로 프로그램(L4)은 TCP 혹은 UDP 를 이용하여 실제 통신을 수행함
- UDP(User Datagram Protocol): 매우 단순한 패킷 전송 역할만 수행
- TCP(Transmission Control Protocol): 신뢰성있는 통신을 위한 다양한 기능 제공
    - 인터넷에서 TCP를 주로 사용하기 때문에, TCP/IP 라고 부름

| TCP | UDP |
|---|---|
| 연결지향형 | 비연결형 |
| 신뢰성 보장 | 비신뢰성 |
| 흐름 제어 기능 제공 | 흐름 제어 기능 X |
| 순서 보장 | 순서 보장 X |

## Socket

- Socket: an endpoint of the network communication (?!)
    - OS에서 제공하는 네트워크 통신을 위한 IPC abstraction
        - 소켓이 바로 IP:Port 를 이용해서 통신을 수행하는 주체
            - 예) 소켓=핸드폰, IP:port=핸드폰 번호
        - 즉, ip:port 는 결국 특정 소켓을 지정하는 이름이라 할 수 있음
- 프로그램은 고유의 포트 번호를 부여받은 소켓을 이용해서 네트워크 통신을 수행할 수 있음
    - 예) 친구랑 전화를 하고 싶으면?
        - 새 핸드폰을 산다 ≈ 새 소켓을 연다
        - 통신사 등록하여 개통한다 ≈ 소켓에 Port 번호를 부여함 (IP 주소는 이미 있음)
        - 전화를 건다 ≈ TCP 의 경우, 전화를 걸고, 받아서 연결이 수립되어야 통신 가능
        - 통화를 한다 ≈ 소켓을 이용해 패킷 단위로 데이터를 주고 받는다
        - (통신을 다 했으면? 소켓을 닫는다 ≈ 핸드폰을 버린다)

### 소켓: 종류 및 통신 방식

- 소켓의 종류
    - AF_UNIX : 유닉스 도메인 소켓 (시스템 내부 프로세스간 통신)
    - AF_INET : 인터넷 소켓 (네트워크를 이용한 통신)
- 소켓의 통신 방식
    - SOCK_STREAM : TCP 사용
    - SOCK_DGRAM : UDP 사용
- 즉, 아래와 같이 4가지 종류의 소켓을 사용할 수 있음
    - (AF_INET, SOCK_STREAM): 일반적인 TCP 를 이용한 인터넷 통신
    - (AF_INET, SOCK_DGRAM)
    - (AF_UNIX, SOCK_STREAM)
    - (AF_UNIX, SOCK_DGRAM)

### 소켓: 관련 시스템콜

- socket() : 소켓 파일 기술자 생성
- bind() : 소켓 파일 기술자를 지정된 IP 주소/포트번호와 결합(bind)
- listen() : 클라이언트의 접속 요청 대기
- connect() : 클라이언트가 서버에 접속 요청
- accept() : 클라이언트의 접속 허용
- recv() : 데이터 수신(SOCK_STREAM)
- send() : 데이터 송신(SOCK_STREAM)
- recvfrom() : 데이터 수신(SOCK_DGRAM)
- sendto() : 데이터 송신(SOCK_DGRAM)
- close() : 소켓 파일기술자 종료

### 소켓: TCP 통신을 위한 수행 순서

![image](https://user-images.githubusercontent.com/59367782/100572157-2d77f500-3318-11eb-9a51-93087f2623bc.png)

### 1. 소켓 생성: socket(2) 

```c
#include <sys/types.h>
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
```

- domain : 소켓 종류 (AF_UNIX, AF_INET)
- type : 통신 방식 (TCP, UDP)
- protocol : 소켓에 이용할 프로토콜
    - 0: 지정한 통신 방식의 기본 프로토콜
- Return value: 새롭게 생성된 소켓의 file descriptor
- 소켓 또한 파일 형태로 관리가 됨
- 따라서 소켓을 모두 이용한 다음에는 close()를 이용해서 닫기

```c
int sd;
sd = socket(AF_INET, SOCK_STREAM, 0);
close(sd);
```

### 2. 소켓 이름 지정: bind(3)

```c
#include <sys/types.h>
#include <sys/socket.h>
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

- sockfd: socket file descriptor
- addr : 소켓의 이름을 표현하는 구조체 sockaddr 의 주소
- addrlen: struct sockaddr 의 크기

```c
int sd = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in sin;
memset((char *)&sin, '\0', sizeof(sin));

sin.sin_family = AF_INET;
sin.sin_port = htons(9000);
sin.sin_addr.s_addr = inet_addr("192.168.100.1");

bind(sd, (struct sockaddr *)&sin, sizeof(struct sockaddr));
```

### 네트워크 주소를 표현하는 구조체

- 인터넷 소켓의 주소 구조체

```c
struct sockaddr_in {
    sa_family_t sin_family; // AF_INET
    in_port_t sin_port; // 네트워크 바이트 port
    struct in_addr sin_addr; // 인터넷 주소
};

struct in_addr {
    uint32_t s_addr; // 네트워크 바이트 주소
}
```

- 유닉스 도메인 소켓의 주소 구조체

```c
struct sockaddr_un {
    sa_familyy_t sun_family; // AF_UNIX
    char sun_path[108]; // 통신에 사용할 파일의 경로명
}
```

### 바이트 저장 순서 지정: endian

- Endian
    - 정수를 저장하는 방식 : Big and Little endian
    - Little endian: 메모리의 높은 주소에 정수의 첫 바이트를 위치 -> 인텔, ARM
    - Big endian: 메모리의 낮은 주소에 정수의 첫 바이트를 위치 -> 모토로라, 썬
- 인텔 머신과 썬 머신이 서로 통신을 하면???
    - 인텔: “야 내가 0x0102 (258) 이라고 했잖아!”
    - 썬: “너 0x0201 (513) 라고 했거든!!”
- TCP/IP 표준: Big Endian
    - Host byte order(HBO)
    - Network byte order(NBO)
    - HBO와 NBO가 항시 다를 수 있음을 기억할 것

### 바이트 저장 순서 지정: 관련 서비스

```c
#include <arpa/inet.h>

uint32_t htonl(unit32_t hostlong);
uint32_t ntohl(unit32_t netlong);
uint16_t htons(unit16_t hostshort);
uint16_t ntohs(unit16_t netshort);
```

- htonl :32비트 HBO를 32비트 NBO로 변환
- ntohl : 32비트 NBO를 32비트 HBO로 변환
- htons : 16비트 HBO를 16비트 NBO로 변환
- ntohs : 16비트 NBO를 16비트 HBO로 변환
- Endian 을 변환해주어야 하는 정보
    - Type 이 지정되어 저장되는 정보
        - IP주소, 포트 번호 (int port = 8080;)
    - 실제 데이터를 주고 받을 때는 문자열 배열과 같은 형태의 바이트 집합을 주고받기 때문에 변환이 불필요함 (unsigned char buf[80];)

### 네트워크 주소 변환 서비스

```c
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

in_addr_t inet_addr(const char *cp);
char *inet_ntoa(const struct in_addr in);
```
- IP주소의 형태
    - 192.168.10.1과 같이 점(.)으로 구분된 형태
    - 시스템 내부 저장 방법 : 이진값으로 바꿔서 저장
    - 외부에서는 일반적으로 문자열로 표기
- 문자열 형태의 IP주소를 NBO 32비트 값으로 변환 : inet_addr(3)
- 구조체 형태의 NBO IP주소를 문자열 형태로 변환: inet_ntoa(3)

### 3. 연결 대기 및 수락: listen(3) and accept(3)

```c
#include <sys/types.h>
#include <sys/socket.h>

int listen(int sockfd, int backlog);
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

- 클라이언트 연결 기다리기: listen(3)
    - backlog : 동시 접속을 허용할 최대 클라이언트 수
- 연결 요청 수락하기: accept(3)
    - addr, addrlen: 접속을 요청한 클라이언트의 IP 정보를 저장할 메모리 주소들
        - Addrlen 은 반드시 구조체 크기 값으로 설정을 해주어야 함
    - Return value: 수락된 연결에 대한 새로운 소켓을 반환
        - 다수 클라이언트와 동시에 통신하기 위해,
        - Sockfd 소켓은 또다른 연결 요청을 대기하기 위해 사용하고,
        - 새로운 소켓을 이용해 클라이언트와 통신을 수행함
- UDP의 경우, 비연결성 프로토콜이기 때문에 “연결” 동작이 불필요함
    - 따라서 listen(), accept(), connect() 를 사용하지 않음

### 4. 연결 요청: connect(3)

```c
#include <sys/types.h>
#include <sys/socket.h>

int connect(int sockfd, const struct sockaddr *addr, int addrlen);
```
- addr : 접속하려는 서버의 IP 정보
- addrlen : addr 구조체의 크기

```c
int sd = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in sin;
memset((char *)&sin, '\0', sizeof(sin));

sin.sin_family = AF_INET;
sin.sin_port = htons(9000);
sin.sin_addr.s_addr = inet_addr("192.168.100.1");

connect(sd, (struct sockaddr *)&sin, sizeof(struct sockaddr));
```

### 5. TCP 데이터 송수신: send(3) and recv(3)

```c
#include <sys/types.h>
#include <sys/socket.h>

ssize_t send(int sockfd, const void *buf, size_t len, int flags);

ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```

- buf, len: 데이터가 기록된/기록될 공간의 주소와 크기
- flags: IO 블록킹, 에러 처리 등의 옵션을 쓸 수 있음. 보통 0.
- Return value: 전송한/수신한 데이터의 크기

```c
char *msg = "Send Test\n";
int len = strlen(msg) + 1; //문자열 종료 문자 ‘\0’ 를 포함시키기 위함
if (send(sd, msg, len, 0) == -1) {
    perror("send");
    exit(1);
}
```
```c
char buf[80];
int len=sizeof(buf), rlen=0; //buf[]의 크기를 recv()에 전달해 overflow 방지
if ((rlen = recv(sd, buf, len, 0)) == -1) {
    perror("recv");
exit(1);
}
```

### 6. UDP 데이터 송수신: sendto(3) and recvfrom(3)

```c
#include <sys/types.h>
#include <sys/socket.h>

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
```

- TCP의 send(), recv()와 다른 점
    - UDP는 비연결성 프로토콜이기 때문에,
    - 매 호출 시마다 보낼 주소, 받을 주소를 명시하여야 함
    - 1회성으로 정보를 다수 서버에 전송할 경우, 효율적임

---

# Network Security Protocols

## 네트워크 보안 개요

### 인터넷 망구조가 안고 있는 보안 위협

- 인터넷 망은 여러 관리 주체가 분산 소유/관리 함
    - 여러 인터넷 서비스 제공 
    - 망 관리자는 자신의 망을 통과하는 패킷을 모니터링 할 수 있음

- 다른 사람이 자신이 보낸 데이터를 받을 수 있음
    - 엿보기, 허브(hub)의 mirroring 기능 등의 이유

- 다른 사람이 자신이 보낸 것처럼 할 수 있음
    - IP 주소는 ICANN (Internet Corporation for Assigned Names and Numbers)에서 할당하고 관리
    - ISP는 자신에게 할당된 IP 주소들만 사용
    - IP 주소를 알면 해당 컴퓨터 혹은 최소한 특정 지역을 찾아 낼 수 있음
    - 따라서, “기술적으로는“ IP spoofing을 막을 수 있음
    - 그러나, 이 요구사항은 필수가 아니기 때문에 모든 라우터가 IP spoofing을 방지하는 것은 아님
    - IP spoofing은 DOS (Denial-Of-Service) 공격의 온상

### IP Spoofing

![image](https://user-images.githubusercontent.com/59367782/100573869-19ce8d80-331c-11eb-8df0-540e0aef5760.png)

### 분산 DOS 공격

![image](https://user-images.githubusercontent.com/59367782/100574026-7762da00-331c-11eb-88d7-cea166d6e717.png)

### 포트 스캐닝

- IANA에서 포트번호와 응용간 매핑을 정의
    - 65536개 중 0번부터 1023번까지 예약되어 있음
    - 예: HTTP:80, FTP:21

- 포트 스캐닝 공격
    - 특정 포트에 특정 메시지를 보내고 반응을 수집함으로써 어느 포트가 열려 있는 지를 검사
    - 해당 포트에 보안 공격을 감행

### 계층별 보안 프로토콜이 필요한 이유

- 하위 계층, 예를 들어 IP 계층에서 제공하면 굳이 TCP나 응용 계층에서 제공할 필요가 없는 것 아닐까?

- 이유 2가지
    - IP 계층 보안은 모든 패킷들을 암호화할 수 있지만 사용자 수준의 보안(인증)을 할 수 없음
        - 즉, “어느 컴퓨터”에서 작업을 요구하는 지는 알아도, “누가” 하는 지는 모름

    - 많은 부분을 IP 계층 보안이 처리할 수 있다손 치더라도 응용들이 원하는 다양한 서비스가 모든 라우터에 설치되기까지는 많은 시간이 소요

## 웹서버 정보 보안

### HTTP 보안

- HTTP “기본” 사용자 인증
    - 서버에 htpasswd 프로그램으로 쉽게 설정
    - 특정 디렉토리에 있는 파일들에 인증을 한 후 접근하게 함
    - Base-64 인코딩하여 전달


- HTTP 기본 사용자 인증은 “안전하지 않음”
    - 사용자 이름/비밀번호를 바로 읽을 수 없도록 인코딩됐지만 디코딩 알고리즘을 돌리면 즉시 해독됨
        - 해독을 위한 **비밀키가 전혀 필요 없음**
    - 심지어 인코딩된 것을 그대로 해커가 재사용해도 그 보안 파일을 접근할 수 있음 (replay 공격)
    - 보안 설정한 파일을 접근할 때 마다 브라우져가 자동으로 사용자 이름/비밀번호를 같이 보내기 때문에 쉽게 공격자가 몰래 복사할 기회가 많음

- HTTP 요약 접근 인증 방법

![image](https://user-images.githubusercontent.com/59367782/100574429-5bac0380-331d-11eb-9bd5-f93deb75f82e.png)

- HTTP 요약 접근 인증 방법의 취약점
    - Man-in-the-middle 공격에 취약
        - 근본적 이유는 서버가 브라우저에게 인증 받지 않기 때문 
- HTTP 요약 접근 인증 방법의 또다른 취약점
    - 암호 자체는 아니라도 관련 데이터를 서버에 저장하기 때문에 위험
- WWW 보안에 완전하지 않음
    - 인증만 제공하고 암호화나 무결성 보장은 하지 않음
    - 처음 사용자와 서버간에 암호를 정하는 방법이 명시 안됨
- 대신 SSL/TLS를 이용한 HTTP 보안이 널리 쓰임

## 전자메일 보안

### 안전한 전자 메일 설계

- 목적
    - 두 사람이 보낸 메일을 타인은 읽을 수 없게 함 (**기밀성**)
    - 받은 메일이 진정 상대방이 보낸 것인지 확신 (**인증**)
    - 받은 메일이 타인이 중간에서 내용 변경한 것이 아님을 확신 (**무결성**)
    - 받은 메일을 상대방이 보낸 것이 아니라고 우기는 것을 방지 (**부인 방지**)

- 대칭키로 문서를 암호화하는 경우와 공용키/개인키로 암호화하는 경우

### 대칭키 1개만 사용하는 방법

![image](https://user-images.githubusercontent.com/59367782/100574847-3bc90f80-331e-11eb-92a0-2a1a33aac52a.png)

- 둘이 모두  “안전하게” 하나의 비밀키를 유지해야 함
- “공유”되는 비밀키 하나로 암호화, 인증, 무결성을 모두 신뢰
- 상대를 완전히 서로 신뢰하는 경우만 적용 가능


### 안전한 전자메일을 위한 PGP

- PGP (Pretty Good Privacy) 프로그램
    - 1991년에 Phil Zimmermann에 의해 작성
        - 3년동안 미국연방 조사의 표적
    - 전자우편을 암호화할 때 사실상(de facto) 표준이 됨
        - PGP는 전자우편뿐 아니라 다른 응용(예:파일암호)에도 적용
    - `www.pgpi.org` 에서 무료로 다운할 수 있음

- 특성
    - 기밀성 : 대칭키 및 공용키 암호화 기술 사용 
    - 인증, 무결성 : 해쉬(hash) 함수와 디지털 서명 사용

### PGP: 보내는 부분

![image](https://user-images.githubusercontent.com/59367782/100574710-f1479300-331d-11eb-8c43-5a2d26cf0bf9.png)

- 춘향의 서명을 요약 대신 e-mail 자체를 사용할 수 있지만 속도가 문제
    - E-mail 자체가 아닌 해싱(hashing)한 e-mail을 대신 (춘향의 개인키로) 서명함으로써 속도 향상

- E-mail과 서명을 몽룡의 공용키로 암호화할 수 있지만 공용키가 너무 커서 암호화 속도가 너무 느림
    - 세션키(춘향이 임의로 생성한 작은 크기의 대칭키)를 대신 암호화에 사용하고 세션키를 몽룡의 공용키로 암호화해서 같이 보냄으로써 속도 향상

### PGP: 받는 부분

![image](https://user-images.githubusercontent.com/59367782/100574961-7af76080-331e-11eb-8915-aeb8e2464d75.png)

### 공용키 검증 방식

- PGP를 이용한 안전한 행위를 위해 가장 주의해야 하는 것은 과연 공용키가 진정 상대방의 것이 맞는 지 확인하는 것

- PGP는 CA (Certification Authority)와 다른 방식

- CA의 공용키 인증 방식
    - CA(예:VerySign)를 통한 검증 방식은 우리가 그 CA를 신뢰하고, CA가 책임지고  (공용키, 소유자)의 짝을 직접 인증하는 방식
    - 현재 웹 브라우져가 채택하는 방식

### CA 공용키 검증 방식

- 각 주체(사람, 라우터)는 자신의 공용키를 CA에 등록
    - 각 주체는 CA에게 “자신에 대한 인증”을 받음
    - CA는 “이것이 이 사람의 공용키임”을 의미하는 인증서를 저장

![image](https://user-images.githubusercontent.com/59367782/100575152-da557080-331e-11eb-9bf4-aec27f3672a2.png)

- 몽룡이 춘향의 공용키를 원하는 경우
    - 춘향의 인증서를 구함 (춘향에게 혹은 다른 곳)
    - CA의 공용키로 적용해서 춘향의 공용키 구함


![image](https://user-images.githubusercontent.com/59367782/100575231-ffe27a00-331e-11eb-9252-aa3d51ac5b22.png)

- CA 공용키 인증서 내용:
    - 시리얼 번호 (CA가 할당하는 유일한 인증서 번호)
    - 인증하는 주체에 관한 정보
    - 인증서 발급한 곳(CA)의 정보
    - 유효일
    - 디지털 서명

### PGP의 공용키 검증 방식

- “Web of Trust”
    - 우리의 신뢰 구조와 비슷: 누가 누구를 신뢰하느냐는 “자신”의 몫
        - 자신이 맞다고 “확인”한 것은 믿음
        - 자신이 신뢰하는 사람이 틀림없다고 한 것은 믿음
    - 각 키는 validity와 trust 항목이 있음
        - Validity: 그 키가 그 사용자임을 말하는 것
        - Trust: 그 사용자를 얼마나 신뢰하느냐를 말하는 것
            - Trust level로 신뢰 정도를 표현

## 전송 계층 보안 프로토콜: SSL, TLS

### 전송 계층 보안 프로토콜 역사

![image](https://user-images.githubusercontent.com/59367782/100575612-ceb67980-331f-11eb-8a3b-3feac68bbb23.png)

### SSL 소개

- SSL (Secure Socket Layer)
    - 웹 클라이언트와 서버 사이에 데이터 암호화와 인증을 위해서 설계한 프로토콜
    - 웹 응용 외에도 TCP위에서 동작하는 모든 응용에 적용 가능
    - 오늘날 거의 모든 브라우저와 웹 서버에 구현됨
        - HTTPS로 시작되는 URL은 SSL을 통해서 HTTP를 구현한 것

### SSL 프로토콜

![image](https://user-images.githubusercontent.com/59367782/100575685-f7d70a00-331f-11eb-92a8-afd6a3391c78.png)

![image](https://user-images.githubusercontent.com/59367782/100575698-ff96ae80-331f-11eb-8b16-1fc0aa93a633.png)


### SSL 속도 성능에 관해

- SSL을 사용했을 때 성능상의 문제점
    - 사용자가 인지할 수 있음
    - SSL세션을 초기화할 때 요구되는 공용키 암호화와 해독에 주로 많은 시간이 걸림
    - HTML 데이터를 암호화하고 및 해독하는 시간
        - 상대적으로 위의 경우보다 덜 심각함

## IP 계층 보안 프로토콜: IPsec

### IPsec 이전 네트워크 보안 프로토콜

- IETF IPSEC WG 탄생 이전의 네트워크 계층 보안 프로토콜
    - Security Protocol 3(SP3)
        - NSA, NIST가 개발한 것으로 주로 미국 군사용 외에 널리 퍼지지 못함

- Network Layer Security Protocol (NLSP)
    - ISO에서 Connectionless Network Protocol (CLNP)을 보호하기 위해서 개발, SP3과 호환 안됨

- Integrated NLSP (I-NLSP)
    - SP3와 비슷하며 NIST가 IP와 CLNP 둘 다에 보안 서비스를 제공하기 위해서 개발

- swIPe 
    - John Ioannidis와 Matt Blaze가 개발한 IP 보안 프로토콜
    - `ftp://ftp.csua.berkeley.edu/pub/cypherpunks/swIPe/swipe.tar.Z`

### IPsec 프로토콜

- 두 가지 종류
    - ESP (Encapsulating Security Payload) 프로토콜
        - 암호화, 무결성, 인증 (AH 보다는 범위가 작음)
    - AH (Authentication Header) 프로토콜
        - 인증, 무결성
        - 암호화는 제공 안함

## VPN

### 사설망

![image](https://user-images.githubusercontent.com/59367782/100576012-9499a780-3320-11eb-9ba0-b17cbe3ff50c.png)

### 혼합망

![image](https://user-images.githubusercontent.com/59367782/100576034-9d8a7900-3320-11eb-8623-e3da5cbd4c9c.png)

### 가상 사설망

![image](https://user-images.githubusercontent.com/59367782/100576051-a5e2b400-3320-11eb-9179-a2a7330b8d36.png)


### 가상 사설망 구현

![image](https://user-images.githubusercontent.com/59367782/100576072-ada25880-3320-11eb-85fe-42339938e70c.png)

---

# 디자인 패턴

## 소프트웨어 디자인 패턴

- 건축물의 설계에 빈번하게 발생하는 동일한 설계 내용이 있기 때문에, 이런 것들을 하나의 패턴으로 보고 다른 건축물 설계에 재사용하면 문제 해결에 대한 고민을 반복하지 않고 백만 번 이상 재사용 할 수 있다.
- 디자인도 소프트웨어에서 한 역할을 할 수 있다.

### 디자인 패턴의 정의

- 소프트웨어 디자인 패턴은 소프트웨어를 설게할 때 특정 상황에서 자주 사용하는 패턴을 정형화한 것이며, 좋은 소프트웨어 설계를 위한 개발자들의 경험적 산물이라 할 수 있다. 이 경험적 산물은 최적화된 알고리즘 코드일 수도 있고 클래스나 모듈들의 좋은 구조로 정의되기도 한다.

### 디자인 패턴의 특징

- 경험을 통해서 얻을 수 있다.
- 특정한 형식을 갖고 체계적으로 작성되는 것이 일반적이다.
- 패턴에는 각기 다른 추상화 수준이 존재하며 계속적으로 진화한다.
- 디자인 패턴은 소프트웨어 설계 시 개발자들에게 추천 지침으로 제공될 수 있다.
- 추천 지침은 개발자들이 설계를 빠르고 정확하게 할 수 있도록 도와주어 소프트웨어 품질을 높일 수 있다.

### 디자인 패턴의 장점

- 디자인 패턴은 의사소통에 도움을 준다. 디자인 패턴을 알고 있는 설게자들은 특정 문제에 대해 공통적으로 알고 있는 패턴을 이용해 해결책에 대한 논의를 할 수 있기 떄문에 보다 원활하게 의사소통을 할 수 있다.

- 검증된 지식인 패턴을 사용하면 높은 완성도의 디자인을 빠른 시간에 만들어 낼 수 있어 소프트웨어 개발 비용을 줄일 수 있고 경제적이다. 또한 코드의 수준을 한 단계 높여주고 적은 수의 클래스로 원하는 목적을 달성할 수 있는 환경이 제공된다.

- 좋은 설계나 아키텍처가 패턴이라는 이름으로 명명되어 있어 개발자는 그 패턴의 이름만으로도 그 소프트웨어의 구조를 알 수 있다. 이를 바탕으로 이전의 소프트웨어 개발에서 사용한 설계나 구조를 쉽게 이해할 수 있고, 새로운 소프트웨어로 빠르게 적용할 수 있어 소프트웨어 재사용을 용이하게 한다.

### Alexander의 패턴 기술 형식

- 패턴 이름
- 특정상황
- 문제점
- 해결책
- 패턴의 구조도

### 패턴의 기술 형식

- 패턴 이름과 분류
- 의도
- 다른 이름
- 동기
- 활용성
- 구조
- 참여객체
- 협력방법
- 결과
- 구현
- 예제 코드
- 잘 알려진 사용 예
- 관련 패턴

### GoF의 패턴 분류

![image](https://user-images.githubusercontent.com/59367782/100577580-e1cb4880-3323-11eb-83dd-fcb8e5ed18e7.png)

### 다형성

- 폴리모피즘이라고도 불리며, 같은 오퍼레이션이 다른 클래스에서 다르게 동작하는 것
- 하나의 함수 이름이나 연산자가 여러 목적으로 사용될 수 있는 것을 의미
- 객체지향에서의 다향성은 주로 상속 관계에서 사용되어 상위 클래스에 정의된 하나의 오퍼레이션에 대해 각 하위 클래스가 가지고 있는 고유한 방법으로 응답할 수 있도록 유연성을 제공
- 다형성은 상위 클래스를 통하여 하위 클래스의 메소드를 호출할 수 있도록 하는 개념

### 동적바인딩

- 메시지를 보내는 측에서 상위 클래스의 오퍼레이션을 호출하면 객체가 어떤 타입인지 알 필요없이 실행 시간에 개게의 타입에 따라 자동적으로 하위 클래스의 적합한 동작이 결정된다.
- 실행 시간에 하위 클래스의 객체를 통해 동작이 정해지는 것을 동적바인딩이라고 한다.
- 다형성과 동적바인딩은 디자인 패턴을 이해하기 위한 필수 개념
- 특히 GoF의 디자인패턴 분류에서 범위 분류 중 객체에 적용하는 패턴들은 대부분 다형성과 동적바인딩을 다루는 패턴들이다.

### 다형성과 동적바인딩

- 상위 클래스만 알고 있는 상태에서 컴파일되며, 하위 클래스에 대한 결정은 실행 시간에 동적바인딩을 통해 이뤄진다.
- 다형성을 통해 저마다의 기능을 가진 하위 클래스를 자유롭게 정의할 수 있으며, 새로운 하위 클래스가 기존 코드의 변경 없이 쉽게 추가될 수 있다.
- 공통적인 속성과 오퍼레이션을 상위 클래스에 정의하고 상속하게 함으로서 디자인과 코드의 중복성을 줄이고 객체지향의 장점을 극대화할 수 있다.


### Singleton 패턴

- Singleton 패턴은 클래스의 인스턴스가 오직 하나임을 보장하며 이 인스턴스에 접근할 수 있는 방법을 제공
    1. 싱글톤 패턴으로 클래스 이름 지정
    2. Private 접근 제한자를 갖는 자기 자신의 타입의 static 멤버 변수 선언
    3. Private 접근 제한자를 갖는 기본생성자를 만들어 외부에서 인스턴스를 생성할 수 없도록 함
    4. 싱글톤 객체를 반환하는 static getInstsance() 메소드 생성
        - 싱글톤 인스턴스가 생성되어 있지 않으면 생성
    5. 현재 생성된 싱글톤 인스턴스 반환

![image](https://user-images.githubusercontent.com/59367782/100578858-72a32380-3326-11eb-9c37-e63166198c54.png)

### Facade 패턴

- Facade란 건물의 앞쪽을 말하고 건물의 주된 정문으로 현관을 포함하고 있는 부분을 말한다.
- 퍼사드 패턴도 건물의 정문에 있는 안내소처럼 개발자가 사용해야 하는 서브시스템의 가장 앞쪽에 위치하고 있으면서 하위시스템에 있는 객체들을 사용할 수 있도록 하는 역할을 하게 된다.
- 따라서 퍼사드 패턴은 시스템의 복잡성을 줄이기 위해 서브시스템을 구조화하고 서브시스템으로의 접근을 **하나의 퍼사드 객체로 제공**하는 패턴이다.

![image](https://user-images.githubusercontent.com/59367782/100579145-0248d200-3327-11eb-9f40-4ad5fd689409.png)

### Facade 패턴이 필요한 경우

- 복잡한 서브시스템에 대한 단순한 인터페이스 제공이 필요할 때
- 클라이언트와 구현 클래스 간에 너무 많은 의존성의 존재하여 클라이언트와 다른 서브시스템간의 결합도를 줄일 필요가 있을 때
- 빌딩블록 아키텍쳐나 컴포넌트 기반 개발 또는 Service Oriented Architecture 등의 경우와 같이 서로의 내부 구조를 감추고 블랙박스로 이해해야 할 떄
- 서브시스템들이 계층화를 이루어 각 서브시스템의 계층별 안내소인 접근점을 제공하려 할 때

### Strategy 패턴

- 전략 패턴은 다양한 알고리즘이 존재할 때 이들 **각각을 하나의 클래스로 캡슐화**하여 알고리즘을 대체가 가능하도록 한다.
- 이를 통해 클라이언트에 영향을 주지 않고 다양한 알고리즘으로 변형할 수 있어 알고리즘을 바꾸더라도 클라이언트는 어떤 변경도 할 필요가 없다.
- 전략 패턴을 GoF의 분류적인 관점에서 다시 설명하면 알고리즘을 담당하는 각각의 클래스를 만들어 책임을 분산하기 위한 목적으로 만든 행위 패턴이고, 각각의 알고리즘을 필요한 시점에서 동적으로 변경하여 사용할 수 있기 때문에 범위적인 측면에서는 객체 패턴이다.

![image](https://user-images.githubusercontent.com/59367782/100583803-88b4e200-332e-11eb-9b79-b091441d339d.png)

### Strategy 패턴 유용하게 사용되는 경우

- 행위들이 조금씩 다를 뿐 개념적으로 관련된 많은 클래스들이 존재하는 경우, 각각의 서로 다른 행위 별로 클래스를 작성한다.
- 알고리즘의 변형이 필요한 경우에 사용할 수 있다. 저장 공간과 처리 속도 간의 절충에 따라 서로 다른 알고리즘을 사용할 수 있다.
- 많은 행위를 정의하기 위해 클래스 안에 복잡한 다중 조건문을 사용해야 하는 경우 이런 선택문 보다는 Strategy 클래스로 만드는 것이 바람직하다.
- 어떤 알고리즘이 클라이언트가 알아서는 안될 데이터를 사용하거나 알고리즘에 종속된 복잡한 자료구조를 사용할 때 유용하다.

### Factory Method 패턴

- 객체를 생성하기 위해 일정한 절차가 필요하거나 **객체를 생성하는 시점이 불명확**할 경우 객체를 생성하는 메소드를 이용할 수 있다.
- Factory Method 패턴은 객체를 생성하기 위한 인터페이스를 정의하지만, 어떤 클래스의 인스턴스를 생성할지에 대한 결정은 하위 클래스에서 이뤄지도록 인스턴스 생성의 책임을 미룬다.
- 이 패턴은 **기반 클래스가 모든 일을 하지만 정확히 어떤 객체를 갖고 작업할지에 대해서는 런타임시로 미룰 때 유용**하다.

![image](https://user-images.githubusercontent.com/59367782/100584425-712a2900-332f-11eb-8887-3ee3b5d4d2f4.png)

### Adapter 패턴

- 소프트웨어 개발을 할 때 관련 라이브러리에서 제공하는 API를 사용하지 않고 개발하는 경우는 드물다.
- Adapter 패턴은 적은 비용으로 기존의 라이브러리를 사용할 수 있는 방법을 제시하고 있는 패턴이다.
- 클래스의 인터페이스를 클라이언트가 기대하는 다른 인터페이스로 변환한다.
- Adapter 패턴은 호환성이 없는 인터페이스이기 때문에 같이 사용할 수 없는 클래스를 개조하여 함께 작동하도록 해준다.

![image](https://user-images.githubusercontent.com/59367782/100584782-e85fbd00-332f-11eb-8991-b1b562ad472c.png)

### Adpater 패턴이 유용하게 사용된느 경우

- 기존의 클래스를 사용해야 하나 인터페이스가 수정되어야 하는 경우
- 아직 예측하지 못한 클래스나 실제 관련되지 않는 클래스들이 기존의 클래스를 재사용하고자 하지만, 이미 정의된 재사용 가능한 클래스가 지금 요청하는 인터페이스를 꼭 정의하고 있지 않는 경우, 즉 이미 만들어진 것을 재사용하고자 하나 이 재사용 가능한 라이브러리를 수정할 수 없는 경우

### 패턴의 남용

- 패턴을 사용하지 말아야할 곳에도 사용하게 되면 필요 이상으로 설계가 복잡해질 수 있다
- 유지보수가 어려운 소프트웨어가 만들어질 수 있다.
- 따라서 패턴에 대해 제대로 이해하고 소프트웨어의 기능이나 규모에 따라 패턴을 유연하게 사용할 수 있어야 한다.

## 요약

- 소프트웨어 디자인 패턴은 GoF의 디자인패턴에서 소개한 23개 패턴 외에도 다양하게 존재한다.
- 디자인 패턴은 과거의 경험을 검증된 해결책을 적용하여 소프트웨어 코드의 품질을 향상시키기 위한 것이며, 결과적으로 소프트웨어의 재사용성을 높이는데 그 목적이 있다.
- 디자인 패턴은 리팩토링 결과 만들어진 좋은 설계구조를 미리 포함하고 있기 때문에 디자인 패턴을 이용한 소프트웨어 설계는 리팩토링 비용을 줄여주는 효과가 있다.

---

# 사용자 인터페이스

### 배경

- 컴퓨터가 널리 보급되면서 사용자 인터페이스에 대한 중요성이 날로 증가하고 있다.
- 이러한 환경에서 컴퓨터와의 상호작용이 직관적으로 이뤄져야 하므로 직접적이고 명쾌하게 설계되어야 한다.

### 인터페이스

- 소프트웨어 개발 라이프 사이클에서 보면 사용자 인터페이스에 대한 조사는 요구사항 분석 단계에서부터 이뤄질 수 있다.
- 요구사항 분석 과정에서 사용자들의 관심이 되는 데이터를 정의 내려야 하며, 사용자들이 입력하는 정보와 시스템이 출력하는 정보가 정의된다.
- 그러나 구체적인 사용자 인터페이스에 대한 정의는 설계의 초기단계인 기본 설계 과정에서 이루어지는 것이 일반적이다.
- 사용자 인터페이스는 메뉴 구조, 각 스크린의 모양과 데이터, 필요한 버튼 등을 포함한다.
- 사용자 인터페이스는 그래픽스에 기초하고 있으며 사람 중심으로 만들어져야한다.
- 특히 사용자가 편리하게 소프트웨어를 활용할 수 있도록 변화되어 왔으며, 요사이는 윈도우를 이용한 사용자 인터페이스가 보편화되고 있다.
- 마이크로소프트의 제품이나 성공적인 소프트웨어들을 살펴보면 성공하는 이유가 보다 편한 사용자 인터페이스를 제공하는데 있다는 것을 쉽게 찾아볼 수 있을 것이다.

## 인터페이스 개발 과정

- 사용자 인터페이스와 사용자의 요구사항은 매우 밀접한 관계를 가지고 있다.
- 사용자가 무엇을 얻을 것인가를 결정하는 것이 요구사항 분석이므로 사용자가 보아야 할 데이터, 상태의 변화, 기능 수행 등을 포함하는 사용자의 요구사항이 사용자 인터페이스에 모두 반영되어야 한다.
- 따라서 사용자 인터페이스에 대한 논의는 분석 단계에서 부터 이뤄지는 것이 일반적이다.
- 기본적인 인터페이스에 대한 정의는 설계의 초기 단계에서 이뤄지는 것이 바람직하다.
- 요구사항 명세서에 기본 사용자 매뉴얼을 포함시킬 수 있다. 이 때 매뉴얼의 사용자가 누구인가 규명하고, 사람과 시스템 사이의 인터페이스에 대한 정보를 기술한다.
- 입출력 데이터를 중심으로 하여 예상되는 메뉴 구조, 스크린, 보고서 형식 등이 기본 사용자 매뉴얼에 포함될 수 있다.
- 분석이 끝난 후 기본 설계 과정에서 사용자 인터페이스와 소프트웨어 구조가 설계된다.
- 특히 사용자와의 상호 작용이 많은 시스템의 경우 사용자에게 어떻게 보이는지, 어떻게 반응하는지는 소프트웨어 내부 구조를 생각하기 이전에 고려되어야 하는 중요한 문제이다.
- 기존의 접근 방법은 시스템의 기본 구조를 설계한 후 사용자 인터페이스를 설계하는 방식을 취했으나, 이제 많은 시스템의 경우 사용자 인터페이스를 설계한 후 프로그램 구조를 설계하는 접근 방법을 취하고 있다.
- 이는 사용자에게 보여지는 것이 중요시되는 것을 의미하며, 엔지니어링 과정에서 무엇이 어떻게보다 더 우선시되어야 한다는 경향이 반영한 것이라 볼 수 있다.
- 사용자 인터페이스에 대한 구체적인 설명은 **사용자 안내서**에 기록된다. 시스템의 목적, 주요 기능, 구조, 다른 소프트웨어 및 하드웨어와의 인터페이스 등이 기술된다.
- 스크린에 대한 설명으로는 메뉴, 스크린 종류, 스크린 형식, 데이터를 선택하거나 입력하는 방식 등을 포함하며, 사용자가 임무를 수행하는 것과 시스템의 task, 스크린, 명령어 사이에 연관성을 알 수 있도록 참조 기능을 제공한다.

## 인적요소

- 사용자 인터페이스를 잘 설계하려면 사용자, 즉 인간에 대한 분석이 필요하다.
- 사용자 인터페이스가 중요시 되지 않았던 시기 소프트웨어의 설계자는 인적요소에 큰 관심을 두지 않았다.
- 어떤 방법으로 사용자 인터페이스를 설계하면 좋은 시스템이 될 수 있을까?
- 사람은 눈과 머리가 협동하여 일을 수행한다. 우선 인간의 심리학적인 요소를 알아야 하고, 사용자의 인터페이스에 대한 요구를 알아야만 한다.
- 좋은 사용자 인터페이스를 만들기 위해서는 인적요소를 살펴보고, 인간의 사물에 대한 인식 방법, 시각적인 지각 능력, 연역 또는 귀납적인 추론 능력, 인간 사회와 조직 등을 연구해야 한다.

### 인식 모델

`입력 정보 -> 해석 -> 비교 -> 응답 선택 -> 응답 수행 -> 출력 또는 응답`

### 확장 모델

- 인지 프로세스가 어떤 방법으로 정보를 지각하는지
- 정보가 어떻게 관심의 대상이 되는지
- 정보가 어떻게 처리되고 저장되는지

인식 모델에 기억 장치와 관심 부분을 추가하여 만든 모델이다.

### 사회적 및 조직적인 요소

- 사회 환경에서 배우고, 듣고, 본 모든 정보가 두뇌에 저장되어 있고 또한 이를 바탕으로 인식을 수행한다.
- 인간은 사회 환경에서 같은 문화를 갖고 있다고 하지만 각기 다른 조직에서 다양한 임무를 수행하며 컴퓨터에 대한 이해도도 다르다.

### 사용자 인터페이스의 조직적 요소

- 컴퓨터 시스템은 인간을 위한 것이며 조직이 업무를 능률적으로 수행하도록 지원해야 한다.
- 사용자가 조직에서 수행하는 역할은 다양하므로 역할을 고려하여 사용자 인터페이스를 설계해야 한다.
- 사용자의 기술 수준에 따라 사용자 인터페이스를 설계해야 한다.

## 사용자 인터페이스 방식

- 사용자 인터페이스도 다양한 스타일이 있고 이런 여러가지 스타일을 잘 활용해야 좋은 인터페이스르 만들 수 있다.

### 명령어

- 명령어는 컴퓨터 시스템이 도입된 초기에 널리 이용된 사용자 인터페이스 형태였다.
- 사용자는 명령어 이름 및 선택 사항으로 명령어를 구성, 입력하여 필요한 기능을 수행할 수 있다.


### 메뉴지향 시스템

- 메뉴란 항목으로 구성된 것이며, 사용자는 메뉴에서 항목을 선택하는 방법으로 필요한 기능을 수행한다.
- 사용자는 메뉴의 각 항목을 기억할 필요가 없다. 각 항목이 어떤 기능을 수행하는가를 판정하기만 하면 된다.
- 사용자가 메뉴 시스템에서 항목을 선택하여 필요한 기능을 수행하기 때문에 키보드 입력이 필요 없고, 명령 입력에서 발생하는 오류도 없앨 수 있다.
- 메뉴 시스템은 다양한 메뉴 항목을 제공한다.

### 기타 메뉴

- Radio-Button
    - 기능과 연관된 선택 사항을 메뉴 형식으로 설계 가능하며, 배타적일 수도 있다.
- Check-Box
    - 선택 사항에서 비배타적으로 선택할 수 있다. 즉, 동시에 여러가지 사항 선택 가능

### 서식 기입

- 서식 기입식 인터페이스는 입력하는 정보에 따라 다양한 필드 제공한다.
- 필드마다 필드 이름을 갖고 있어 직관적이며 업무의 서식과 유사하여 사용하기 쉽다.
- 데이터베이스 시스템에서도 많이 사용된다.

## 인터페이스 설계 지침

- 시스템의 모든 사용자 인터페이스는 일관성을 가져야 한다.
- 일반적으로 큰 시스템을 개발하는 경우 여러 사람이 사용자 인터페이스를 설계, 구현함으로 일관성을 유지하기 어렵다.
- 일관성을 갖기 위해 개발 이전에 인터페이스에 대한 표준안을 만들어야하며, 개발 후에도 이를 점검하여 오류를 수정해야 한다.
- 한 시스템의 모든 사용자 인터페이스가 일관성을 가져야 되는 것처럼 한 회사에서 만드는 제품들에게도 일관성이 요구된다.

### 사용자 인터페이스 지침

1. 인터페이스는 일관성있게 설계
2. 의미있는 피드백 제공
3. 파괴적인 행동을 하고자할 때 확인
4. 사용자가 취한 대부분의 행동에 대하여 원상태로 되돌릴 수 있게 허용
5. 행동들 사이에 기억해야할 정보의 양을 줄여라
6. 대화, 움직임, 생각의 효율성을 추구하기 위해 키 입력, 마우스 거리도 화면 설계에 맞춰 최소화
7. 실수에 관대하라
8. 기능에 따라 활동을 분할하고 화면을 배치. 명령어와 활동들을 분류하여 배치하여 응집력있게 하자
9. 문맥-의존 도움말 기능을 제공하라. 지금 수행하는 활동과 연관된 도움말을 쉽게 볼 수 있도록 도움말 기능 제공
10. 간단한 동사와 명령어 사용
11. 불필요한 입력 제외

## 객체지향 사용자 인터페이스

- 이미 존재한 HCI 모듈과 라이브러리 객체들을 이용해 인터페이스를 빠르게 개발 가능
- 인터페이스에 대한 표준을 얻을 수 있고, 재사용성은 물론 품질을 향상시켜왔다.
- 객체지향 기법을 이용한 사용자 인터페이스 구현 도구들이 인터페이스 설계, 구현에 도움을 많이 준다.
- 사용자의 요구사항을 빠르게 검증할 수 있는 프로토타입 기법으로 대부분 채택되고 있다.
- 프로토타입을 빨리 만들 수 있는 제작 도구들이 개발되었으며, 이를 사용자 인터페이스 제작 도구 또는 사용자 인터페이스 개발 시스템이라 부른다.
- 사용자 인터페이스 제작도구와 객체지향 개발 기술의 발전에 힘입어 빠르게 응용시스템을 개발하려는 노력이 많이 시도된다.

## 요약

- 컴퓨터의 사용량이 늘어날수록 사용자 인터페이스의 중요성이 높아진다.
- 특히 대화형으로 만들어지는 시스템이 많아 사용자에 대한 인적요소들과 인터페이스 기술에 대한 이해가 요구된다.
- 인터페이스를 설  계하기 위해서는 인간의 심리적인 요소와 요구사항을 알아야한다.
- 한 제품은 물론 한 회사의 사용자 인터페이스에 대한 표준안이 마련되어야 한다.

---