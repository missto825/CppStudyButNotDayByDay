#include <iostream>
using namespace std;
// �����Ҵ�� ������ �Լ�/������ : malloc / free, new/ delete , new[] / delete[]

// malloc
// - �Ҵ��� �޸� ũ�⸦ �ǳ��ش�(size_t)
// - �޸� �Ҵ� �� ���� �ּҸ� ����Ű�� �����͸� ��ȯ���ش�.(�޸� ������ NULL)
// free
// 
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
	free(pointer);
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
	return 0;
}

