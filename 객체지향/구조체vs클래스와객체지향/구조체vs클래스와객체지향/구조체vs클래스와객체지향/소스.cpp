#include <iostream>
using namespace std;

// 1. struct VS class
// ���� ���� ���� �Ȱ�����, �׳��� �Ʒ�ó�� �⺻���°� struct�� public, class�� private��� ���� ������ �ִ�.
// �̷��� �������� ���Ͻ�Ű�� �ʰ� �����س��� ������, c++�� c���� ȣȯ�� �߿���ϱ� ����,
// �׸��� c++������ struct�� ����ü(������ ����) ������ �ϱ⸦ ���ϰ�, class�� ��ü������ ��Ÿ���� �뵵�̴�.


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