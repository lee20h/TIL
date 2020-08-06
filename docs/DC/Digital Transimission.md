---
sidebar: auto
---
# Digital Transimission
## Line coding  
Binary data를 Digital signal로 변환하는 과정  
Signal level, data level  
![signal,data-level](./images/Data_Communication/signal,data-level.JPG)  

Line coding schemes
### Unipolar  
한극성을 이용하며 가장 간단하며 기초적이다. 하지만 요즘엔 사용하지 않는다.  
voltage는 하나로, 1 : a voltage level, 0 : zero voltage level  
두 가지 문제점이 존재한다. DC component가 있으며, 동기화가 부족하다.  

### Polar  
양극성을 이용하며, 여전히 동기화 문제가 존재한다.  
Polar가 4가지 종류로 나뉘어진다. 
	1) NRZ (Nonreturn to Zero)  
	zero voltage을 갖지 않으며 양 혹은 음의 수를 갖는다.  
	- NRZ-L(Level)  
		0 : positive  
		1 : negative  
		동기화 문제가 여전히 존재  
	- NRZ-I(invert)  
		1 : voltage level을 역으로 바꿈  
		0 : voltage 변화 x  
		NRZ-L보다는 동기화가 발전했다.  
![NRZ](./images/Data_Communication/NRZ.JPG)  

	2) RZ (Return to Zero)  
	동기화 문제를 해결하기 위해 생긴 방법으로, 각 비트에 있어서 Signal change bit을 둔다. 3가지 value을 갖되 zero는 동기화를 위한 value이다.  
	1 : positive-to-zero  
	0 : negative-to-zero  
	효율적인 동기화가 가능하나, 시간이 낭비된다.  

	3) Manchester  
	0 : positive-to-negative  
	1 : negative-to-positive  
	RZ와 비슷하나, value 중 zero가 없음  
![Manchester](./images/Data_Communication/Manchester.JPG)  
	4) Differential Manchester  
	0 : additional transition  
	1 : no transition  
![Differential-Manchester](./images/Data_Communication/Differential-Manchester.JPG)  
	장점 : 1이 들어오면 한번 바뀐다.  

### Bipolar  
3 voltage level 사용한다.  
0 : zero level  
1 : alternating positve and negative voltages  
AMI(alternate mark inversion)  
많이 사용하는 bipolar encoding 방식으로 0이 들어오면 zero level을 사용하지만 1이면 처음엔 positive으로 시작해서 1이 들어올 때 마다negative 반복해서 바뀐다.  
단점 : 0이 계속 들어오면 동기화에 문제가 생긴다.  

pulse : symbol을 전송하는데 필요한 시간  
pulse rate : 1초당 일어난 pulse  
Bit rate = pulse rate * log₂L (L : number of data levels)  

DC components  
적합하지 않은 이유가 두 가지가 있다. 장비를 통과할 때 오류가 있을 수 있다. 부가적인 에너지로 쓸모가 없다.  

### Self-synchronization (동기화문제)  
receiver의 bit interval이 정확하지 않으면 문제가 생길 수 있다.
![lack_of_synchronization](./images/Data_Communication/lack_of_synchronization.JPG)  
동기 시스템은 sender와 receiver clock을 맞추고, 비동기 시스템은 signal에 해당 정보가 필요하다.  

## Block coding  
line coding이 동기화 문제가 있거나 (NRZ에서 0이나 1이 연속된 경우) bandwidth가 절반만 쓰인다.(RZ 계속 0으로 바뀌어 B/W 절반쓰임)  
이러한 문제를 해겷하기 위해 block으로 보낸다는 생각이다. 먼저 m bit 그룹들로 나눈다. 그 다음 m bit 그룹들을 n bit 그룹들로 또 나눈다. 이러한 방식들은 연속적인 1과 0을 없앤다. 그다음 line coding해서 전송한다.  
대표적인 방법 4B/5B으로, 4bit을 5bit으로 바꿔줘야하는데 16개 중 32개에 매핑해주며, 안 쓰인 16개는 버린다. 매핑해주는 방법은 연속된 1이나 0이 3개 이상인 경우는 사용하지 않는다.  
![block_coding](./images/Data_Communication/block_coding.JPG)  
4B/5B 방법은 시작 부분에 0으로 시작하고 끝 부분이 0이 두개 이상 나오는 경우가 Worst case이다. 따라서 0이 3개 초과해서 나오지 않는다.  NRZ-I가 이 방법을 사용하며, Bandwidth가 20% 더 필요하다는 단점이 있다. Fast Ethernet이 이 방법을 사용한다.  
8B/10B느 방법은 4B/5B와 비슷하지만 오류가 더 적으므로 Gigabit Ethernet에서 쓰인다.  
8B/6T 방법은 앞에서의 방법과는 달리 bandwidth를 낭비하지 않지만 level을 더 쓴다. 8 bit 그룹을 6 symbol code로 바꾼다. signal level이 3개로 2^8 -> 3^6개로 늘어난다.

## **Sampling**  
analog data를 digital data로 바꿔서 digital전송을 한다.  
PAM(Pulse Amplitude Modulation)  
analog signal을 sampling하여 digital전송함  
PCM(Pulse Code Modulation)  
PAM을 기반으로 하나, Quantization(양자화 - 노이즈가 강해짐)를 통해서 Binary data로 바꾼다. PAM -> Quantization -> binary encoding -> line coding  
Sign magnitude사용해서 Binar encoding 한다. Block coding 후 Line coding (NRZ-L)을 한다.  
![PCM](./images/Data_Communication/PCM.JPG)  

Sampling rate : Nyquist theorem  
**반드시 origianl signal의 가장 높은 주파수 두배 이상이 되어야한다.**  

sample당 bit의 갯수는 Bit = ┌log₂N┐ N : level  

bit rate = sampling rate * number of bits per sample  

## Parallel and serial 전송  
Serial 방식은 동기(sender, reciver같은 clock), 비동기(다른 clock) 방식으로 나뉜다.  
Parallel 전송은 속도가 빠르나 Cost(선 갯수)가 많이 들며, 거리가 짧다.(동시에 보내서 동시에 받으므로 동기화 문제 때문)  
Parallel과 serial은 서로 변환 가능  
Serial 전송은 먼저 conversion으로 데이터를 직렬화 시킨 후 전송하고 다시 conversion으로 데이터를 병렬화시킨다.  

비동기화 전송은 공통된 시간을 사용하지 않으며 Sender와 Receiver사이의 약속이 있다. Start bit(0)와 Stop bit(1)으로 구별한다. Parallel와 동기 전송보다는 느리지만 가격이 싸고 효율적이다. 예로 키보드 연결할 때 쓰인다.  
동기화 전송은 공통 시간을 맞춰야 한다. byte간의 gap이 없으므로 속도가 빠르다. 동기화의 타이밍을 맞추는 것이 가장 중요하다.  