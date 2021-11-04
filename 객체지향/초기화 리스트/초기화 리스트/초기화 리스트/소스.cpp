#include <iostream>
using namespace std;
class Knight
{
public:
	Knight() : _hp(5) //초기화 리스트
	{
		//_hp = 100; 이렇게 추가될경우 2번 호출 되는 비효율적인 작업이 된다.
	}
public:
	//int _hp = 5; 모던 c++에서 추가됬다.
	int _hp;
};

int main()
{
	Knight k;
	cout << k._hp << endl;
	return 0;
}