#include <iostream>
using namespace std;
// 20��

//�޸�

//[  [ player ]  ]
//[    knight    ]

// ���

// ������
// �������� ��� ��ӵǴ� ������ �ƴ�
// - Knight�� �����ϸ� Player�� �����ڸ�? Knight�� ������?
// �Ѵ� ȣ��ȴ�.
// �������� ��� �θ���� ����, �Ҹ����� ��� �ڽ��� ����
class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() �⺻ ������ ȣ��" << endl;
	}
	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) �⺻ ������ ȣ��" << endl;
	}
	~Player()
	{
		cout << "~Player() �Ҹ��� ȣ��" << endl;
	}
	void Move() { cout << "Player Move ȣ��" << endl; }
	void Attack() { cout << "Player Attack ȣ��" << endl; }
	void Die() { cout << "Player Die ȣ��" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};
class Knight : public Player
{
public:
	Knight()

		//��ó�� ����
		// -���⼭ Player() �����ڸ� ȣ��
		//��, ����Ʈ �����ڿ� ������ �÷��̾� �����ڰ� ���� ȣ���(����Ʈ�� �÷��̾ �θ��ٰ� �ƴ�)

	{
		_stamina = 100;
		cout << "Knight() �⺻ ������ ȣ��" << endl;
	}

	Knight(int stamina) : Player(100)
		//��ó�� ����
		// -���⼭ Player(int hp) �����ڸ� ȣ��
		//��, ����Ʈ �����ڿ� ������ �÷��̾� �����ڰ� ���� ȣ���(����Ʈ�� �÷��̾ �θ��ٰ� �ƴ�)

	{
		_stamina = 100;
		cout << "Knight(int stamia) �⺻ ������ ȣ��" << endl;
	}
	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}
	//��ó�� ����
	// - ���⼭ ~Plyaer() �Ҹ��ڸ� ȣ��
public:
	//������ : �θ���� ������ �ź�(?)
	void Move() { cout << "Knight Move ȣ��" << endl; }
public:
	int _stamina;
};

class Mage : public Player
{
public:
	int _mp;
};

int main()
{
	Knight k(100);

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	k.Move();
	//k.Player::Move(); ������������ �������Ѱ� �� ����ϴ°� �����ʰ� ��������� ����


	k.Attack();
	k.Die();

	return 0;
}