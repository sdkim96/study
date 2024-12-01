## Signed / Unsigned

- C에서는 unsigned 라는 단어를 자료형 앞에 이름 앞에 넣어둬야함.
- unsigned / signed를 생략하면 기본은 signed
- 예외는 char

## char

- char는 최소 8비트인 정수형 (문자형이 아님. 그래서 정수형 집어넣어도됨)
- C89에선 8비트 이상이라고만 정의함.
- char가 unsigned인지 signed인지는 컴파일러마다 다름

**따라서 어떤 플랫폼이던간에 컴파일러 오류를 내고 싶지 않다면 char에도 unsigned, signed를 넣어주는게 좋다**
예를 들어, char자료형 8비트의 최상위는 부호기 때문에 타입을 지정해주는게 좋음
현재 내 mac 에선 min이 -128이기 때문에 signed char이다.

## short

- 최소 16비트 (2바이트)
- 포팅문제 없는 값의 범위 (-32767~32767), (0~65535)
- int 보다 short가 메모리는 더 적게 먹지만, cpu성능은 int가 더 좋음

## int

- 표준에 따르면 **최소 16비트이고, short보다 큰**
- CPU가 딱 아는 크기여야함. 
- CPU의 산술 논리장치가 사용하는 기본 데이터 -> 워드 -> 워드 크기 == 레지스터 크기
- 즉 CPU따라 다름
- 32bit 컴퓨터가 나오면서 int는 32비트가 됨.
- 포팅에 안전한 범위는 short와 같음 but 웬만한 플랫폼에선 (-2^16) ~ (2^16 -1)

## long

- 표준에 따르면 **최소 32비트고 Int보다 큰**
- c89에선 64비트 없음


## float
- unsigned없고
- char (8비트 이상) 이상

## double
- unsigned 없고
- 크기 64비트
- 범위 IEEE 754 Double과 동일