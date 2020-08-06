---
sidebar: auto
---
# Signals
## Analog Signal
무한한 숫자의 값을 가짐, 주기적인 Signal을 사용  
주기와 주파수는 역의 관계  
사인파 그래프에서의 주기와 주파수 관계 알아보기  
하나의 사인파 그래프는 유용하지 않다. 하지만 진폭이나 위상, 주파수를 바꾸면 유용해진다. 즉, 복합신호로 사용할 수 있다. Fourie analysis에 의하면 임의의 신호는 여러 사인파를 조합하면 구할 수 있다. 또, 반대로 분할이 가능하다.  

Square wave : 여러 사인파(harmonic)를 합치게 되면 직사각형 신호와 비슷하게 나온다.  

![Transmission_mediun](/TIL/images/Data_Communication/Transmission_mediun.JPG)  
**Bandwidth** : medium이 통과시킬 수 있는 주파수의 범위(signal의 절반이상을 통과 시키는 경우, highest - lowest)  
medium의 bandwidth와 signal의 bandwidth가 일치 할 수록 데이터의 손실이 줄어든다.  

Digital bandwidth (bps)  
- Maximum bit rate  

Annalog bandwidth (hz)  
- range of frequencies  

## Digital Signal
유한한 숫자의 값을 가짐, 비주기적인 Signal을 사용  
Bit interval : single bit을 보낼 때 시간  
Bit rate : 1초간 bit interval 몇 개 나오는 정도  
Wide-Bandwidth Medium을 사용해야함  

bandwidth에 한계가 있을 때 bps의 숫자와 최소 필요 bandwidth가 만족되면 디지털 데이터를 보낼 수 있다.  
**Nyquist Theorem** : 채널 오류 고려하지 않은 상태에서 이론적인 한계  
**Shannon Capacity** : 오류(노이즈)를 고려한 한계  

1개의 harmonic일 때의 bps와 필요한 BandWidth  
최소한의 **bandwidth B = n/2이다.(Shannon capacity)**  
여러개의 harmonic일 때의 bps와 필요한 Bandwidth  
**bandwidth B >= n/2 or n <= 2B(Nyquist theorem)**  

bit rate와 bandwidth는 서로 비례한다.  

Low-pass : 일정 주파수 밑으로 다 통과시킴 (디지털 전송)  
band-pass : 일정 주파수 범위만 통과 시킴 (아날로그 전송)  

디지털 전송  
low-pass channel이 필요하다. 선을 독점하거나 시간을 나눠서 독점하는 제한된 환경에서만 사용가능하다.  

아날로그 전송  
band-pass channel을 대부분 사용한다. low-pass channel은 제한적이며, low-pass channel을 band-pass channel로 나눠서 각각 사용할 수 있다.  

**Data rate limits**  
- the bandwidth available  
- the levels of signals we can use  
- the quality of the channel(the level of the noise)  
noise 없으면 Nyquist 있으면 Shannon channel 사용  

Nyquist bit rate  
노이즈가 없는 채널에서 bps을 구하면 2 x bandwidth x log₂L (L : number of signal levels)  

Shannon capacity bps  
노이즈가 있는 채널에서 bps을 구하면 bandwidth x log₂(1 + SNR) (SNR = signal-to-noise ratio : signal의 power/noise의 power)  

문제 중 B/W와 SNR이 주어졌을 때 bit rate와 signal level을 구하는 문제에 있어서 Shannon capacity로 bps을 구하고 Nyquist로 그 식으로 signal level을 구하되 오류를 고려해주기 위해 level을 1을 뺀다.  

## **Transmission Impairment** (전송 장애 3가지)
Attenuation - 약화  
저항에 의한 열 에너지로 변해서 손실난 부분을 amplifier(증폭기)를 통해 복구 dB = 10log(P₂/P₁)을 통해서 양수면 증폭, 음수면 약화  
Decibel을 위의 식처럼 사용하는데 만약 Point-to-point에서 여러 point사이의 증픅과 약화를 알아 볼 수 있으며, dB계산이 쉽다.  

Distortion - 왜곡  
Composite signal(복합 시그널)에서 생길 수 있는 시그널의 모양이 변하는 것이다. 분해 후 Medium 통과 후 합성 하는 경우 왜곡 생김  

Noise  
온도, 유도, crosstalk (선 꼬기. 자기장 야기), 번개, 고압선 등에 의해서 생길 수 있다.