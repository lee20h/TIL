---
sidebar: auto
---
# Analog Transmission
Modulation of digital data  
Binary data -> band-pass  
low-pass analog signal -> analog signal  
Analog signal 특징 3가지  
**진폭 주파수 위상**  

bit rate  
1초에 전송되는 bits  
Baud rate  
1초당 Signal units, bit rate와 같거나 작다.  

Carrier signal  
아날로그 전송할 때 정보를 싣게 되는 기반이 되는 주파수 대역. Carrier signal을 진폭이나 주파수를 조절할지 고른다. 

## **ASK(Amplitude Shift Keying)**  
Carrier signal의 amplitude을 올렸다가 내렸다 하므로, Noise에 약하다는 단점이 있다. Bandwidth = (1 + d) * N_baud (d : modulation preocess)  
**baud rate == bit rate**  
![ASK](./images/Data_Communication/ASK.JPG)  
진폭을 기준으로 한다.  
![ASK_BW](./images/Data_Communication/ASK_BW.JPG)  
bandwidth = N_baud  

## **FSK (Frequency Shift Keying)**  
Carrier signal의 주파수를 바꾸므로 Noise의 문제가 없다. 좋은 주파수 대역이 정해져 있다.  
**baud rate == bit rate**  
![FSK](./images/Data_Communication/FSK.JPG)  
![FSK_BW](./images/Data_Communication/FSK_BW.JPG)
Bandwidth = f_c1 - f_c0 + N_baud  
Bandwidth가 많이 필요하다.  

## **PSK (Phase Shift Keying)**  
Carrier signal의 위상을 바꾼다. 0 : zero 1 : inverse  
![PSK](./images/Data_Communication/PSK.JPG)  
PSK의 특징은 noise에 강하며, Bandwidth가 많이 필요하지 않아 ASK랑 같다.  
bit 수를 늘린 2-PSK는 ASK와 bit rate가 같지만 4-PSK, 8-PSK는 2bit, 3bit로 늘어난다.  
bandwidth = N_baud (ASK의 Bandwidth와 같다.)
4-PSK (Q-PSK)  
![Q-PSK](./images/Data_Communication/Q-PSK.JPG)  
| Dibit | Phase |
|-------|-------|
| 00 | 0 |
| 01 | 90 |
| 10 | 180 |
| 11 | 270 |  

## QAM (Quadraturer Amplitude modulation)  
ASK와 PSK을 조합해서 사용한다. Bandwidth가 ASK와 PSK와 같다. 하지만 ASK에서 Noise 문제가 발생할 수 있다.  
4-QAM, 8-QAM  
![QAM](./images/Data_Communication/QAM.JPG)  
여러 방식이 가능하다. Bit rate는 Baud rate에 bit수를 곱해주면 된다.  
| Modulation | Units | Bits/Baud | Baud rate | Bit Rate |
|-------|-------|-------|-------|-------|
| ASK,FSK,2-PSK | Bit | 1 | N | N |
| 4-PSK,4-QAM | Dibit | 2 | N | 2N |
| 8-PSK, 8-QAM | Tribit | 3 | N | 3N |  

## AM (Amplitude Modulation)  
Bandwidth = Bandwidth(minimum)의 2배  
주어진 Modulating singal을 Carrier frequency을 기준으로 Amplitude을 Modulation한다. 따라서 Noise에 약하다.  
AM baud는 붙어서 할당되어 가끔 서로 겹치기도 한다.  
FM (Frequency Modulation)  
Bandwidth = AM의 Bandwidth의 5배 = Bandwidth(minimum)의 10배  
AM와 같이 하되 Frequency을 Modulation하므로 Noise 문제가 생기지 않는다.  
FM baud는 간섭을 막을려고 서로 띄어 놓는다.  