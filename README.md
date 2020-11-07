# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록 후 [정적 웹페이지](https://lee20h.github.io/TIL/)에 정리
* Github Action으로 배포
* markdown으로 작성
* 문제 풀고 [Problem Solving](https://github.com/lee20h/TIL/tree/master/Problem%20Solving) 폴더에 모으기

---  

# 2020년

| [5월](./month/5월) | [6월](./month/6월) | [7월](./month/7월) | [8월](./month/8월) | [9월](./month/9월) | [10월](./month/10월) |
|----|-----|-----|---|---|---|

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