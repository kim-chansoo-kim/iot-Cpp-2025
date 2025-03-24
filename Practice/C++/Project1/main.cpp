#define HUNGRY 1
// 1. 가독성
// 2. 유지보수


#include <iostream>

int main()
{
	// 자료형 (크기 단위, byte) Data Type
	// 정수형 : char(1), short(2), int(4), long(4), long long(8)
	// 실수형 : float(4), double(8)

	int i = 0;

	// 1 바이트로 양수만 표현
	// 256 가지 -> 0 ~ 255
	unsigned char c = 0;
	c; // 양의 정수만 표현하는 1byte 공간
	c = 0;
	//c = 255;
	c = -1; // == 255

	// 1 바이트로 양수, 음수 둘다 표현
	// -128 ~ 0 ~127
	char c1 = 0;
	c1 = 255;

	// 음의 정수 찾기(2의 보수법)
	// 대응되는 양수의 부호를 반전 후, 1을 더한다
	/*------------------------------------------------------------------------------------*/


	// switch/삼항 연산자
	/*------------------------------------------------------------------------------------*/
	int iTest = 20;
	switch (10)
	{
	case 10:
		break;	// 걸리면 switch를 나가겠다 없으면 바로 안나가고 아래의 구문으로 내려감

	case 20:
		break;

	default:
		break;
	}

	// == 위 아래 같은 느낌

	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}
/*------------------------------------------------------------------------------------*/
	int iTest = 20;
	switch (10)
	{
	case 10:
	case 20:
	case 30:

		break;
	default:
		break;
	}

	if (iTest == 10 || iTest == 20 || iTest == 30)
	{

	}
	else
	{

	}
	// 삼항 연산자
	iTest == 20 ? iTest = 100 : iTest = 200;	// 가독성이 좀 떨어짐

	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}
	/*------------------------------------------------------------------------------------*/


	/*------------------------------------------------------------------------------------*/
	// define/비트 연산자
	// 쉬프트 <<, >>

	// 비트 곱(&), 합(|), xor(^), 반전(~)
	// 비트 단위로 연산을 진행.
	// & 둘다 1인 경우 1
	// | 둘중 하나라도 1이면 1
	// ^ 같으면 0, 다르면 1
	// ~ 1은 0으로, 0은 1로

	int istatus = HUNGRY;	// HUNGRY == 1 위에서 디파인으로 전처리 해놔서 1로 지정됨
	// 지정된 값을 수정하면 모든 값이 수정됨

	/*------------------------------------------------------------------------------------*/

	return 0;
}