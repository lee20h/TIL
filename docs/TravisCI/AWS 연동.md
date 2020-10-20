  
 
  

# Travis AWS 연동

AWS의 elastic bean stalk를 이용하여 배포할려 한다.  

## AWS 환경 생성 후 설정

`.travis.yml`  

- provider : 외부 서비스 표시 (s3, elasticbeanstalk, firebase 등)
- region : 현재 사용하고 있는 AWS의 서비스가 위치하고 있는 물리적 장소 (DockerReactApp-env.eba-b5gvhnvz.**ap-northeast-2**.elasticbeanstalk.com)
- app : 생성된 애플리케이션의 이름
- env : DockerReactApp-env
- bucket_name : 해당 elasticbeanstalk을 위한 s3 버켓 이름 (elasticbeanstalk-ap-northeast-2-089802069060)  

여기서 s3는 Travis CI에서 가지고 있는 파일을 압축해서 S3로 보내는데 이때 필요한 것이 bucket_name이다.  

- bucket_path : 애플리케이션의 이름과 동일

on
- branch : 어떤 브랜치에 push할 때 AWS에 배포할 지

## AWS 인증 설정

AWS에서 제공해주는 Secret Key를 Travis yml 파일에다가 적어주면 된다.  

API 키 받는 순서

1. IAM USER 생성 (IAM(Identity and Access Management) : AWS 리소스에 대한 엑세스를 안전하게 제어할 수 있는 웹 서비스로, IAM을 사용하여 리소스를 사용하도록 인증 및 권한 부여 대상을 제어)  

이때 Root 사용자가 IAM 사용자에게 권한을 부여해서 사용하면 된다. Root 사용자는 가급적 사용하지 않은 것이 보안에 좋다.  

2. API키를 Travis yml 파일에 적어주기 : 노출을 피하는 것이 좋다. 따라서 Travis 웹사이트 해당 저장소 대쉬보드에서 Environment Variables에 저장해서 사용하는 것이 좋다.  

사용시에는 `access_key_id: $AWS_ACCESS_KEY`  
`secret_access_key: $AWS_SECRET_ACCESS_KEY`와 같이 명시해주면 된다.