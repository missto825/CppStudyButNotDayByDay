#include <iostream>
using namespace std;
// �����Ҵ�� ������ �Լ�/������ : malloc / free, new/ delete , new[] / delete[]

// malloc
// - �Ҵ��� �޸� ũ�⸦ �ǳ��ش�(size_t)
// - �޸� �Ҵ� �� ���� �ּҸ� ����Ű�� �����͸� ��ȯ���ش�.(�޸� ������ NULL)
// free
// 

// new / delete
// - C++�� �߰���
// malloc/free�� �Լ�! new/delete�� ������


// new[] / delete[]
// - new�� malloc�� ���� ������,�������� �Ƿ��Ҽ��� �ִ�!

// malloc/free vs new/delete
// - ��� ���Ǽ� -> new/delete�� �ξ� ����!
// - Ÿ�Կ� ������� Ư���� ũ���� �޸� ������ �Ҵ�������� -> malloc/free

// ������ ���� �߿��� �������� malloc/free�� �ٸ��� new/delete�� ������/�Ҹ��ڸ� ȣ�����ش�.
class Monster {
public:
	int _hp;
	int _x;
	int _y;
};
int main()
{
	// void* , ���ο� ����
	// void�ϱ� �ƹ��͵� ���°��� �ƴϴ�
	// Ÿ���� void ���� �ִ��� �𸣴� �ʰ� �˾Ƽ� ��ȯ�� ����ض�
	void* pointer = malloc(sizeof(Monster));
	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// Heap Overflow
	// - ��ȿ�� �� ������ �ʰ��� ����Ͽ� �߻��ϴ� ����

	free(pointer); //�ʿ䰡 �������� ���ָ� �ȴ�!
	//free�� ���� ������ �޸𸮰� ��� �þ�� �޸� ��
	//free(pointer);
	//Double free
	// - �̰� ��κ� �׳� ũ���ø� ���� ������.

	// Use-After-Free
	// 	�̹� free�� �Ҵ��� ������ �ص� �� ������ ���� �Ҽ��ִµ�, �̰�� ������ �ٸ� ���� �������ְ�
	//  ���� �Ͼ���� �𸦼��� �ֱ⿡ ����� �ȴ�.
	// - ���α׷��� ���� : ����,�޸𸮰� ���� �������� �Ͼ
	// - ��Ŀ�� �ձ� ������
	//m1->_hp = 100;
	//m1->_x = 1;
	//m1->_y = 2;


	Monster* m2 = new Monster;
	//�⺻������ malloc�� ������ �� ���.
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;
	delete m2; //freeó�� ������ ������!

	Monster* m3 = new Monster[5];
	m3->_hp = 200;
	m3->_x = 2;
	m3->_y = 3;

	Monster* m4 = (m3+1);
	delete[] m3;


	return 0;


	
}

