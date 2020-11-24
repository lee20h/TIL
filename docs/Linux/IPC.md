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