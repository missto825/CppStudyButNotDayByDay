#include <tchar.h>
#include <iostream>
using namespace std;

class Marine
{
public:
	int _hp;
	static int s_attack; //���赵 �����θ� ����
	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		//_hp = 100; ������ �Ͼ. ����ƽ�� �ٴ� ���� ���� �Լ�ó�� �Ǳ⿡ ��� ������ ��ġ�� ����
		s_attack = 100;
	}
}; 
int Marine::s_attack = 0;  // E���� ������ �������
int main()
{
	Marine m1;
	m1._hp = 40;
	Marine m2;
	m2._hp = 40;

	Marine::s_attack = 6;

	cout << Marine::s_attack << " ���ݷ�!" << endl;
	
	Marine::s_attack = 7;
	Marine::SetAttack();
	cout << Marine::s_attack << " ���׷��̵� ���ݷ�!" << endl;

	return 0;
}