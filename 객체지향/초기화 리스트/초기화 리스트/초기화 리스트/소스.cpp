#include <iostream>
using namespace std;
class Knight
{
public:
	Knight() : _hp(5) //�ʱ�ȭ ����Ʈ
	{
		//_hp = 100; �̷��� �߰��ɰ�� 2�� ȣ�� �Ǵ� ��ȿ������ �۾��� �ȴ�.
	}
public:
	//int _hp = 5; ��� c++���� �߰����.
	int _hp;
};

int main()
{
	Knight k;
	cout << k._hp << endl;
	return 0;
}