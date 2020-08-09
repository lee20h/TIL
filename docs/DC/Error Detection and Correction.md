---
sidebar: auto
---

# Error Detection and Correction

Single-bit error  
serial 전송에서 자주 일어나며, parallel에서도 가끔 일어난다.  
Burst error  
2개 이상 bit 오류, 연속일 필요가 없다. Length of burst : 처음 깨진 부분부터 마지막에 깨진 부분까지 전부  

## Redundancy  
### Parity check  
홀짝체크하는 방법  
모든 싱글에러를 체크 할 수 있으며, 버스트에러에서는 홀수개의 비트가 바뀐 경우만 체크할 수 있다.  
### 2-D Partiy check  
2차원으로 row와 column의 홀짝을 맞춰서 bit을 만들어준다. 1차원의 Partiy check에서 못 찾는 버스트 에러같은 부분을 찾을 수 있으나, 정확히 같은 위치에 에러가 난다면 찾지 못한다.  

### Cyclic redundancy check(CRC)  
가장 강력하며, 널리 사용된다. 이진법을 나누기를 하여 사용한다.  
Sender에서는 CRC generator가 있으며, Reciver에서는 CRC checker가 있다.  

![CRC_Generator](/TIL/images/Data_Communication/CRC_Generator.JPG)  

![CRC_Checker](/TIL/images/Data_Communication/CRC_Checker.JPG)  

### Polynomials
Polynomials는 2가지 조건을 만족해야한다. 1. **x로 나누어지면 안된다.**(모든 버스트 에러를 체크할 수 있다.) 2. **x+1로는 나누어져야한다.**(홀수갯수의 버스트 에러를 체크할 수 있다.)  
이러한 조건을 만족할 때의 Performance는 모든 Burst Error에서 홀수개의 숫자가 바뀐 경우 다 찾아낸다. degree of polynomial보다 낮거나 같은 Burst Error들은 다 찾아낸다. 짝수의 Burst Error도 높은 확률로 찾아낸다.  

### CheckSum  
CRC보다 속도가 빠르지만 검출 능력이 떨어진다. 하드웨어를 간단히 구현할 때 사용한다. n bit 단위로 쪼갠 다음 1의 보수로 합한다. 원본과 보수를 더했을 때 0이 나오면 정상, 아니면 오류가 난 것이다.  
Parity < Checksum < CRC  

## Error Correction  
Forward error correction (FEC)  
해밍코드로 몇번째 bit가 깨졌는지 알아 낼 수 있다.  
![hamming_code](/TIL/images/Data_Communication/hamming_code.JPG)  