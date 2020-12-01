# Auto Scaling

- Scale in-out 을 자동으로 수행해주는 서비스
    - 유동적으로 변동하는 애플리케이션의 로드를 처리할 수 있는 정확한 수의 Amazon EC2 인스턴스를 보유하도록 보장
    - 내결함성 향상
        - 비정상 인스턴스를 검출하고, 대체 인스턴스 시작
        - 복수의 가용 영역을 사용하도록 구성 가능
    - 가용성 향상
        - 현재의 트래픽 요구를 처리할 수 있는 적절한 용량을 항상 갖출 수 있음
    - 비용 관리 개선
- 기타
    - EC2 Console 에서 제어
    - 비용: 무료
    - 참고: [AWS Auto Scaling Documentation](https://docs.aws.amazon.com/ko_kr/autoscaling/ec2/userguide/what-is-amazon-ec2-auto-scaling.html)

### Auto Scaling 구성 요소

![image](https://user-images.githubusercontent.com/59367782/100739748-ecb4d480-341a-11eb-9092-4d1ae375b914.png)

### 시작 구성, 시작 템플릿 및 AS 그룹

- 시작 구성
    - EC2 인스턴스를 시작하는 데 사용하는 템플릿
- 시작 템플릿
    - 시작 구성의 Renewal: 새로운 기능들에 대한 지원
    - 스팟 인스턴스를 자동으로 선택해 구성해주는 기능이 추가됨
- AS 그룹
    - 유사한 특성을 공유하고, 인스턴스 조정 및 관리 목적의 논리적 그룹으로 취급되는, EC2 인스턴스들의 모음
    - 조정 정책: 인스턴스의 수를 자동으로 조절하는데 사용되는 정책
- 특징
    - 한 시작 구성 혹은 템플릿은 여러 AS 그룹에서 사용될 수 있음
    - 한 AS 그룹은 하나의 시작 구성 혹은 템플릿만 사용할 수 있음

### AS 그룹

- Auto scaling 그룹의 제어 파라미터
    - 최소 인스턴스 수: 그룹의 크기가 이 값 아래로 내려가지 않음
    - 목표 인스턴스 수: 확보하는 것이 언제나 보장되는 인스턴스 수
        - 실제 콘솔에서는 현재 Auto scaling 그룹이 정책에 따라 유지하려는 숫자가 표시
    - 최대 인스턴스 수: 그룹의 크기가 이 값을 넘지 않음

![image](https://user-images.githubusercontent.com/59367782/100739822-0d7d2a00-341b-11eb-87b8-a6ec5a22fef4.png)

- 구성 시, 미리 필요한 정보
    - 서버 시작 및 구성에 걸린 시간 (생성 시작부터 사이트 접속 가능까지)
    - 애플리케이션의 성능과 가장 연관성이 높은 지표 (예. 홈페이지 반응 속도)
    - Auto Scaling 그룹에 포함하려는 가용 영역 수
    - Auto Scaling에서 수행하려는 역할
        - Auto Scaling의 조정 기능을 사용하여 용량을 늘리거나 줄일지, 그저 일정한 서버 수가 항상 실행되도록 하는 데만 Auto Scaling을 사용할지 여부 (Auto Scaling은 두 기능을 동시에 수행할 수 있음)
    - 사용할 수 있는 기존 리소스 (예: EC2 인스턴스 또는 AMI)