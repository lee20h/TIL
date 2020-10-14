# AWS Storage Services 1: EBS, EFS

| 요구 사항: | 추천 제품: | 
|---|---|
|Amazon EC2, 관계형 및 NoSQL 데이터베이스, 데이터 웨어하우징, 엔터프라이즈 애플리케이션, 빅 데이터 처리 또는 백업 및 복구를 위한 영구 로컬 스토리지|Amazon elastic Block Store(Amazon EBS)|
|Linux 기반의 워크로드를 AWS 클라우드 서비스와 온프레미스 리소스에서 사용할 수 있도록 지원하는 간단하고 확장 가능하며 탄력적인 파일 시스템입니다. 이 제품은 애플리케이션을 중단하지 않고 온디맨드 방식으로 페타바이트 규모까지 확장하도록 구축되어 파일을 추가하고 제거할 때 자동으로 확장되고 축소되므로, 애플리케이션은 필요할 때 필요한 만큼 스토리지를 사용할 수 있습니다.|Amazon ElasticFile System(Amazon EFS)|
|사용자 생성 콘텐츠, 활성 아카이브, 서버리스 컴퓨팅, 빅 데이터 스토리지 또는 백업 및 복구를 위해 인터넷 위치에서 데이터에 액세스할 수 있도록 지원하는 확장 가능하고 안정적인 플랫폼입니다.|Amazon Simple Storage Service(Amazon S3)|
|아카이브 및 규제 준수를 위해 테이프를 대체할 수 있는 매우 저렴한 장기 스토리지 클래스| Amazon Glacier 및 Amazon S3 Glacier Deep Archive|
|고성능 컴퓨팅, 기계 학습 및 미디어 데이터 처리 워크플로우와 같이 컴퓨팅 집약적 워크로드에 최적화된 완전관리형 파일 시스템으로, Amazon S3에 완벽하게 통합되어 있습니다.|Amazon FSx for Lustre|
|Windows Server를 기반으로 구축된 완전관리형 네이티브 Microsoft Windows 파일 시스템으로, 이 제품을 사용하면 SMB 프로토콜 및 Windows NTFS, AD(ActiveDirectory) 통합, DFS(분산 파일 시스템)에 대한 전체 지원을 비롯하여, 파일 스토리지가 필요한 Windows 기반 애플리케이션을 AWS로 쉽게 이전할 수 있습니다. |Amazon FSx for Windows File Server|
|버스팅, 계층화 또는 마이그레이션을 위해 Amazon 클라우드 스토리지로 온프레미스 환경을 보강해주는 하이브리드 스토리지 클라우드입니다.| AWS Storage Gateway|
|유형 및 크기에 상관없이 모든 데이터를 AWS 클라우드로, 혹은 AWS 클라우드에서 이동하는 작업을 간소화 및 가속화할 수 있도록 지원하는 서비스 포트폴리오입니다.| 클라우드 데이터 마이그레이션 서비스|
|클라우드뿐 아니라 온프레미스에서도 AWS Storage Gateway를 사용해 AWS 서비스 전체에서 데이터 백업을 손쉽게 중앙화하고 자동화할 수 있는 완전관리형 백업 서비스입니다.|AWS Backup|


![image](https://user-images.githubusercontent.com/59367782/95824899-0adf4c00-0d6b-11eb-8136-7dcbe70d52ce.png)  

## EBS와 EFS

- EBS (Elastic Block Storage)
    - Amazon EC2 인스턴스에 연결된 영구 볼륨에 블록 데이터를 저장하고 이를 처리
    - 일반 HDD, SSD와 같은 블록 기반의 입출력을 지원하는 스토리지
    - EC2 VM의 OS, 데이터를 저장하기 위한 저장장치로 사용됨
    - 연간 고장률 AFR: 0.1%~0.2% (일반 HDD: 4%)
- EFS (Elastic File System)
    - 간편하고 확장 가능한 파일 시스템에 데이터를 저장 및 공유
    - Ext4, NTFS와 같이 파일 시스템 access semantics 에 따른 FS 인터페이스를 제공하는 서비스
    - 자체 고가용성, 내구성을 제공하도록 설계
    - 용량 자동 확장 및 축소

### EBS Pricing

- Amazon EBS 범용 SSD(gp2) 볼륨
    - $0.114 프로비저닝된 스토리지의 월별 GB당
    - 예) 30GB 한달 쓰면? $3.342 = 약 4천원
- Amazon EBS 프로비저닝된 IOPS SSD(io1) 볼륨
    - $0.128 프로비저닝된 스토리지의 월별 GB당
    - $0.067 프로비저닝된 월별 IOPS당
- Amazon EBS 처리량 최적화 HDD(st1) 볼륨
    - $0.051 프로비저닝된 스토리지의 월별 GB당
- Amazon EBS 콜드 HDD(sc1) 볼륨
    - $0.029 프로비저닝된 스토리지의 월별 GB당
- Amazon S3에 대한 Amazon EBS 스냅샷
    - $0.05 저장된 데이터의 월별 GB당

### EFS Pricing

- 표준 스토리지
    - $0.33 월별 GB당
- Infrequent Access 스토리지
    - $0.0272 월별 GB당
    - $0.011 전송량 기준
- 프로비저닝된 처리량 유형
    - $6.60 월별 MB/s
    
- 예) 30GB 한달: $9.9 (약 12,000원)
- EBS보다 약 3배 가량 비쌈.
    - EFS는 보다 고급의 기능을 제공하기 때문
    - IA는 약 1/12 수준 (다만 계층 간 전송에 대해 요금 부과) 

![image](https://user-images.githubusercontent.com/59367782/95834620-2866e280-0d78-11eb-9907-ba964f192c3c.png)

## Block storage and File system

- Block storage
    - 512B 단위로 분할된, (sector)
    - 0부터 시작하는 선형 주소 공간 (linear address space)에,
    - 데이터를 읽거나 쓸 수 있는 스토리지 장치
- File system
    - 하나의 파일 시스템 내에서 각기 unique name 을 갖는,
    - File 이라는 독립적인 개체에,
    - 1B 단위로 분할된,
    - 0부터 시작하는 선형 주소 공간 (linear address space)에,
    - 데이터를 읽거나 쓸 수 있는 스토리지 시스템
    - 일반적으로 블록 스토리지 장치의 상단에 위치함
        - 실제 데이터는 블록 스토리지에 저장됨

![image](https://user-images.githubusercontent.com/59367782/95825908-85f53200-0d6c-11eb-8002-2e3bd5ecf047.png)

- Block storage (left)
    - 데이터를 기록하기 위해 블록 스토리지 상의 주소를 직접 사용해야함
- File system (right)
    - 파일 시스템이 제공해주는 파일 이라는 추상적 개체를 이용
    - 모든 데이터는 0부터 시작하는 독립된 주소 공간에 기록할 수 있음
    - 실제 데이터가 기록되는 공간은 블록 스토리지이며,
    - 파일의 주소 공간과 블록 스토리지 주소 공간 사이의 mapping 을 파일 시스템이 관리
        - 이때 이 **매핑 정보** 또한 블록 스토리지에 저장되어야 함

- Block storage 장단점
    - (장점) 중간 계층을 거치지 않으므로 액세스가 빠르다.
    - (단점) 같은 주소 공간을 다수가 공유하므로, 데이터 관리가 어려움
        - 예) A와 B가 동시에 서로 다른 데이터를 0번 주소에 기록하려하면?
- File system 장단점
    - (장점) 파일마다 서로 주소 공간이 분리되어 있기 때문에, 서로 분리되어야 할 데이터를 쉽게 관리할 수 있음
        - 예) 위의 예에서, A와 B는 서로 다른 파일의 주소 공간에 각각 접근하므로 문제가 없음
    - (단점) 성능 저하
        - 파일의 데이터가 실제 블록 스토리지 어느 주소에 위치하는지 변환이 필요 (mapping)
        - 그러나 mapping 정보와 데이터의 메모리 캐싱을 통해 많은 부분 해소됨

## 그외

- S3 (Simple Storage Service)
    - AWS의 가장 기본적인 Object based storage
    - 일반적인 클라우드 스토리지와 동일함 (예. 네이버/다음 클라우드)
    - 내구성: 99.999 999 999% (11-9)
- Glacier (뜻: 빙하)
    - 데이터 보관 및 백업을 위한 안전하고 내구성있는 스토리지
    - 싸고 성능이 느림
    - 연평균 99.999 999 999%의 내구성

- AWS Storage Gateway
    - 사용자가 기존에 사용하던 스토리지 인프라 및 데이터를 포함한, 모든 스토리지 서비스를 AWS 클라우드와 통합할 수 있도록 지원
    - 파일, 볼륨, 테이프 인터페이스 지원
    - NFS, iSCSI 인터페이스 지원

- AWS Backup
    - 완전관리형 백업 서비스
    - 중앙 관리 및 자동화
        - AWS Storage Gateway를 사용해 AWS 서비스 전체에서 데이터 백업을 손쉽게 중앙집중화하고 자동화
        - AWS Backup 콘솔에서 클릭 몇 번이면 백업 일정과 보존 관리를 자동화하는 백업 정책을 생성할 수 있음