#include <iostream>
using namespace std;

// 1. struct VS class
// 둘은 정말 거의 똑같은데, 그나마 아래처럼 기본형태가 struct는 public, class는 private라는 차이 정도만 있다.
// 이렇게 같은데도 통일시키지 않고 구별해놓는 이유는, c++가 c와의 호환을 중요시하기 때문,
// 그리고 c++에서는 struct는 구조체(데이터 묶음) 정도만 하기를 원하고, class는 객체지향을 나타내는 용도이다.


struct TestStruct
{
	int _a;
	int _b;
};
class TestClass
{
	int _a;
	int _b;
};


int main()
{
	TestStruct ts;
	TestClass tc;

	ts._a = 10;
	tc._a = 10;
	return 0;
}