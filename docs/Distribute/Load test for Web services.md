# Load test for Web services

## 부하 테스트

소프트웨어 시스템에 요청을 보내서 응답을 측정하는 절차

- 웹서비스의 품질을 파악하기 위한 테스트
    - 현재 서비스 구성의 제한(limit)을 찾기 위함
    - 원하는 부하를 수용할 수 있게끔 구성되었는지 확인하기 위함
    - 병목 지점을 찾고 병목 현상을 제거하기 위함
- 우리가 만든 웹서비스의 성능을 테스트하기 위해 사용
    - 얼마나 많은 요청을 처리할 수 있을까? (현재의 HA 구성에서)
    - 많은 요청 수에 대해 자동으로 처리 성능을 조절할 수 있을까?
    - 차후 Auto Scaling 의 동작 및 성능 확인에 사용

## 스트레스 테스트

시스템의 안정성을 결정하기 위해서 수행되는 의도적인 심한 테스트로, 일반적인 운영 용량을 넘은 테스트를 수행하여 결과를 관찰한다.

## AB

- 아파치 웹서버 성능검사 도구
    - Apache HTTP Server 의 간단한 성능 벤치마킹 도구
        - 정적 컨텐츠, REST API 등
    - 아파치 서버 패키지에 포함
    - 특히 아파치가 현재 초당 몇개의 요청을 서비스하는지 알려줌
- 유의할 점
    - AB는 서버의 응답에 걸리는 시간만 측정
        - Server-side centric benchmark
    - 사용자가 실제로 느끼는 체감 성능은?
        - HTML translation, image file loading, and etc.
        - Request 간의 delay를 줄 수 없기 때문에, 실제 요청 패턴과 차이가 있음

### Usage

Usage: `ab [options] [http[s]://]hostname[:port]/path`

### options

- `-n` : 성능을 검사하기위해 보내는 요청수. 기본값으로 요청을 한번만 보내기 때문에 일반적인 성능검사 결과를 얻을 수 없다.
- `-c` : 동시에 요청하는 요청수. 기본적으로 한번에 한 요청만 보낸다.
- `-g` : 측정한 모든 ㄱ밧을 'gnuplot' 혹은 TSV (Tab separate values, 탭으로 구분한 값) 파일에 기록한다. 라벨은 output 파일의 첫번째 라인을 참고한다.
- `-t` : 성능을 검사하는 최대 초단위 시간. 내부적으로 `-n 50000`을 가정한다. 정해진 시간동안 서버 성능을 검사할때 사용한다. 기본적으로 시간제한 없이 검사한다.
- `-v` : 출력 수준을 지정한다. 4 이상이면 헤더에 대한 정보, 3 이상이면 응답코드, 2 이상이면 경고와 정보를 출력한다.
- `-A` : 프록시를 통해 BASIC Authentication 정보를 제공한다. :로 구분한 사용자명과 암호를 base64 인코딩하여 전송한다.
- `-X` : proxy[:port] 프록시 서버를 사용하여 요청한다.

### example

- `ab -c 50 -t 10`
    - 서버가 10초동안 동시에 50개의 요청을 지속적으로 처리
    - 즉, 서버에 50개의 요청 부하가 지속적으로 몰려있는 상황
        - 50명의 사용자가 아니라, n명의 사용자가 무작위로 요청을 보내는데,
        - 서버 입장에서 볼 때, 언제나 50개의 요청이 대기 큐에 쌓여있는 것
    - 성능이 좋을수록, 총 처리된 요청 개수가 많아질 것.
- `ab -n 500 -c 10`
    - 서버가 10개의 동시 요청을 총 500개 처리하는 시나리오
    - 대기큐에 10개의 요청이 항상 쌓여있는데, 총 요청 수는 500개
    - 성능이 좋을수록, 총 수행 시간이 짧아질 것.

### Result

`-c 500 -t 10`

- Concurrency evel : 500
- Time taken for tests : 10001 seconds
- Complete requests : 2447
- Failed requests : 0
- Total transferred : 34507594 bytes
- HTML transferred : 33479854 bytes
- Requests per second : 244.67 [#/sec] (mean)
- Time per request : 2043.556 [ms] (mean)
- Time per request : 4.087 [ms] (mean, across all concureent requests)
- Transfer rate : 3369.47 [Kbytes/sec] received

- Percentage of the requests served within a certain time (ms)
    - 50% : 1905
    - 66% : 2022
    - 75% : 2103
    - 80% : 2175
    - 90% : 2333
    - 95% : 2495
    - 98% : 2660
    - 99% : 2726
    - 100% : 3137 (longest request)

50%와 100% 사이에 오차가 적어야 좋은 시스템을 의미한다.

### Result Analysis

- Failed requests
    - Fail 이 있을 경우, reliability 의 훼손
        - 즉, 서버가 제공할 수 있는 범위를 벗어남
            - 벤치마킹 중간에 정지될 수 있음
        - Length 제외: 첫 요청에 대한 응답과 다른 길이의 응답이 오는 경우를 측정함. 동적인 컨텐츠의 경우, 지속적으로 발생할 수 있음
- Response time
    - 요청 처리 시간의 표준 편차가 너무 크거나,
    - 요청 처리 시간 백분위에서 tail 이 길게 형성이 되거나,
    - 요청 처리 시간 자체가 너무 긴 경우,
    - 서비스의 품질이 사용자 요구사항에 크게 미달할 수 있음

### Long tail of Response time

`$ab -n 100 -c 10 -g result.plot http://www.google.com/index.html`

[참고사이트](https://blog.hkwon.me/ab-apache-http-server-benchmarking-tool/)

- 약 10% 의 요청이 800ms 이내에 처리되었음.
즉, 나머지 90%의 요청은 800ms 이상 소요되었음
- -c 10 옵션을 주었으므로 10개의 요청이 쌓일 때까지
이전 9개 까지는 빠르게 처리되다가, 10개 이후부터는
서버에 부하가 쌓이며 점차 느려지는 양상을 볼 수 있음
- 실제 서버의 부하는 상당 시간 서비스가 지속된 상태,
즉, 평균 사용자 수로 상당 시간 유지된 상태의
평균 요청 처리 수를 보아야
실제 사용자가 느끼는 서비스 수준을 파악할 수 있음