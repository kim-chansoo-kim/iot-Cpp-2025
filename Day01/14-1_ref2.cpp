/*
	다른 함수에 선언된 지역변수의 값을 바꾸는 방법2
	래퍼런스 -  또 다른 이름, 보이지 않는 포인터, 메모리를 사용하지 않는다.
*/
#include <iostream>
using namespace std;

void chFunc(int& rn)			// & 래퍼런스(참조변수) 선언
{
	rn = 20;
}

int main()
{
	int n = 10;
	cout << "호출 전 n: " << n << endl;

	chFunc(n);
	// 호출 후 n = 20

	cout << "호출 후 n: " << n << endl;
	return 0;
}