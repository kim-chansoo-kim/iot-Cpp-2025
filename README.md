# iot-C--2025
IoT 개발자 C++언어 리포지토리

## 1일차

#### C ++ 기초 화면 출력
- cout - 출력을 담당하는 객체
- endl - 개행을 시켜주는 객체(출력 후 한칸 뛰어쓰기)
- ::   - 범위를 나타내는 스코프
- cin  - 입력을 담당하는 객체

	```c++
	#include <iostream>
	using namespace std;						// std라는 namespace를 사용하겠다

	int main()
	{	
		// 변수
		int num = 100;
		char str[100] = "홍길동";
		double d = 3.14;
		
		std:: cout << "abcdefg";		
		std:: cout << num << std:: endl;
		std:: cout << str << std:: endl;
		cout << d << endl;						// using namespace std; - 이 구문을 통해 앞에 std를 안붙여도 실행

		return 0;
	}
	```

#### 함수의 다형성

- 함수 오버로딩 
	- 함수의 다중정의
	```c++
	/*
	함수 오버로딩(다중정의) : 이름은 같지만 매개변수의 타입, 갯수 등이 다르면 다른 함수이다.
	*/
	#include <iostream>
	using namespace std;

	int func() { return 10; }
	int func(char c) { return c; }
	int func(int n) { return 10 + n; }
	int func(int n1, int n2) { return n1 + n2; }
	//char func(char c) { return c; } - 8line과 충돌 // 타입과 상관없이 변수가 같을 수는 없다

	int main()
	{
		cout << func() << endl;			// int func() { return 10; }
		cout << func('a') << endl;		// 97 아스키코드로 a - func(char c)의 출력
		cout << func(10) << endl;		// int func(int n) { return 10 + n; }
		cout << func(10, 20) << endl;	// int func(int n1, int n2) { return n1 + n2; }


		return 0;
	}
	```
- 함수 오버라이딩 
	- 함수의 재정의 --> 상속

#### 디폴트 매개변수

1. 입력이 없으면 디폴트 매개변수가 적용된다
	```c++
	#include <iostream>
	int func(int num = 10) {
		return num * num;
	}

	int main()
	{
		int res;
		res = func(10);
		std::cout << res << std::endl;

		res = func(0);
		std::cout << res << std::endl;

		res = func();						// 입력이 없으면 디폴트 매개변수가 적용된다.
		std::cout << res << std::endl;
		return 0;
	}
	```

2. 디폴트 매개변수를 여러개 적용할때 가장 오른쪽부터 순서대로 작성한다
	```c++
	#include <iostream>
	#include <math.h>
	using namespace std;
	int coordinates(int x, int y = 0, int z = 0);		// default값은 선언(원형)에만 작성한다.

	int main()
	{
		cout << "(10, 20, 30): " << coordinates(10, 20, 30) << endl;
		cout << "(10, 20, def): " << coordinates(10, 20) << endl;
		cout << "(10, def, def): " << coordinates(10) << endl;

		return 0;
	}

	int coordinates(int x, int y, int z)
	{
		int res = 0;
		res = pow(x, 2) + pow(y, 2) + pow(z, 2);	// 제곱
		return sqrt(res);							// 제곱근
	}
	```

- 함수 오버로딩중 디폴트 매개변수와 입력이 없는 순수한 함수 정의가 있을 때,
  입력없는 함수 호출시 문제가 발생한다
	```c++
	#include <iostream>
	using namespace std;

	int func(int n = 0) { return n * n; }
	int func() { return 10; }

	int main()
	{
		cout << func(10) << endl;
		// cout << func() << endl; 위에 두함수를 구분 못함

		return 0;
	}
	```

#### namespace
- 이름 충돌을 방지하기 위한 기능
-  :: 연산자로 네임스페이스 내부 요소를 접근할 수 있다
- using 키워드로 네임스페이스 생략가능
	- using namespace를 사용하면 네임스페이스 생략이 가능하지만, 충돌 위험이 있다
	```c++
	#include <iostream>
	namespace aName
	{
		void func()
		{
			printf("aName::func()\n");
		}
	}
	namespace bName
	{
		void func()
		{
			printf("bName::func()\n");
		}
	}
	namespace cName
	{
		void func()
		{
			printf("cName::func()\n");
		}
	}
	using namespace cName;
	int main()
	{
		aName::func();
		bName::func();
		func(); // using을 사용해 func()를 사용했을때 cName이 나옴
		return 0;
	}
	```

#### new
1. 메모리 동적 할당: new - delete
2. 자료형 포인터 = new 자료형(크기)
3. new는 생성자를 호출한다.(즉 new는 객체를 생성시킨다)
4. 객체를 생성하기 위해서는 생성자 호출이 있어야 한다
5. new는 생성자 호출이되므로 초기화가 가능하다
	- 생성자 - 객체를 생성하고, 초기화시키는 기능을 가지는 특별한 메서드이다

	```c++
	#include <iostream>
	using namespace std;

	int main()
	{
		int* parr;
		parr = new int[3] {10, 20, 30};				// 이름없는 배열객체 생성하고 10, 20, 30으로 초기화
													// parr = new int[3] = {10, 20, 30};
		cout << parr[0] << ", " << parr[1] << ", " << parr[2] << endl;
		delete[] parr;								// new가 나오면 반드시 delete가 따라온다
		return 0;
	}
	```

#### Reference
- 또 다른 이름(별명)
	```c++
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

		chFunc(n);					// 호출 후 n = 20

		cout << "호출 후 n: " << n << endl;
		return 0;
	}
	```
- 원형과 같은 메모리를 공유한다
- 레퍼런스를 통해 원본 변수에 접근하고 수정할 수 있다
- const 레퍼런스는 원본 변경을 방지하며, 임시 객체도 참조 가능하다
- 선언과 동시에 반드시 초기화해야만 한다
- 상수레퍼런스 - 상수도 참조 가능하다.

	```c++
	#include <iostream>
	using namespace std;

	int main()
	{
		int n = 10;
		// int& ref = n;
		// int& ref = 10; - 원래는 참조기 때문에 메모리를 저장할 수 없다
		const int& ref = 10;	// 상수레퍼런스로 선언하면 리터럴도 참조할 수 있다
								// 임시객체를 저장할 수 있는 공간이 생성된다.

		cout << "ref: " << ref << endl;

		return 0;
	}
	```



#### c++ 구조체


## 2일차