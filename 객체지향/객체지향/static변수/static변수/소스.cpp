#include <tchar.h>
#include <iostream>
using namespace std;

class Marine
{
public:
	int _hp;
	static int s_attack; //설계도 상으로만 존재
	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		//_hp = 100; 오류가 일어남. 스태틱이 붙는 순간 전역 함수처럼 되기에 멤버 변수를 고치지 못함
		s_attack = 100;
	}
}; 
int Marine::s_attack = 0;  // Eㅏ로 선언을 해줘야함
int main()
{
	Marine m1;
	m1._hp = 40;
	Marine m2;
	m2._hp = 40;

	Marine::s_attack = 6;

	cout << Marine::s_attack << " 공격력!" << endl;
	
	Marine::s_attack = 7;
	Marine::SetAttack();
	cout << Marine::s_attack << " 업그레이드 공격력!" << endl;

	return 0;
}