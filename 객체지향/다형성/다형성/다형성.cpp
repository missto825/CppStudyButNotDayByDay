#include <iostream>
using namespace std;

//������(Polymorphism) ���� �Ȱ�����, ����� �ٸ�
//�����ε�(Overloading) �Լ� �ߺ� ���� = �Լ� �̸��� ����
//�������̵�(Overriding) ������, �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ����

//���ε�(Binding) = ���´�.
// -���� ���ε�(Static Binging) : ������ ������ ����
// -���� ���ε�(Dynamic Binging) : ���� ������ ����
// 
// �Ϲ� �Լ��� ���� ���ε��� ���
// ���� ���ε��� ���Ѵٸ�? -> ���� �Լ� (virtual function)

//�����Լ��� ��� �˾Ƽ� Ÿ���� ã���� �ִ��ɱ�?
//��ü������ �Ǵٸ� ������
class Player
{
public:
	void Move() { cout << "Move Player!" << endl; }
	virtual void VMove() { cout << "Move Player!" << endl; }
	virtual void VDie() { cout << "Die Player!" << endl; }
	//void Move(int a) { cout << "Move Player!(int)" << endl; }
public:
	int _hp;
};
class Knight : public Player
{
public:
	void Move() { cout << "Move Knight!" << endl; }
	//���� �Լ��� �����Ǹ� �ϴ��� �����Լ���!
	//��, virtual�� ��� �����Լ��� ��
	virtual void VMove() { cout << "Move Knight!" << endl; }
	virtual void VDie() { cout << "Di Knight!" << endl; }

public:
	int _stamina;
};
class Mage : public Player
{
public:
	int _mp;
};

void MovePlayer(Player* player)
{
	player->VMove();
}
void MoveKnight(Knight* knight)
{
	knight->Move();
}
int main()
{
	/*Player p;
	p.Move();*/
	Player p;
	//MovePlayer(&p); 
	//MoveKnight(&p); �÷��̾�� ����? NO


	Knight k;
	//MoveKnight(&k);
	MovePlayer(&k); // ���� �÷��̾��? YES
	//�÷��̾��� �ڵ尡 �߻��Ѵ�.


	//��, �ֻ��� ��ü�� ���ױ׷� �ڵ带 ©�� �ִ�.
	return 0;
}