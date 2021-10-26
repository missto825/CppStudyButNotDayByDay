#include <iostream>
using namespace std;
// 20분

//메모리

//[  [ player ]  ]
//[    knight    ]

// 상속

// 생성자
// 생성자의 경우 상속되는 개념이 아님
// - Knight를 생성하면 Player의 생성자를? Knight의 생성자?
// 둘다 호출된다.
// 생성자의 경우 부모님이 먼저, 소멸자의 경우 자식이 먼저
class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}
	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) 기본 생성자 호출" << endl;
	}
	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}
	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};
class Knight : public Player
{
public:
	Knight()

		//선처리 영역
		// -여기서 Player() 생성자를 호출
		//즉, 나이트 생성자에 오기전 플레이어 생성자가 먼저 호출됨(나이트가 플레이어를 부른다가 아님)

	{
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
		//선처리 영역
		// -여기서 Player(int hp) 생성자를 호출
		//즉, 나이트 생성자에 오기전 플레이어 생성자가 먼저 호출됨(나이트가 플레이어를 부른다가 아님)

	{
		_stamina = 100;
		cout << "Knight(int stamia) 기본 생성자 호출" << endl;
	}
	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}
	//후처리 영역
	// - 여기서 ~Plyaer() 소멸자를 호출
public:
	//재정의 : 부모님의 유산을 거부(?)
	void Move() { cout << "Knight Move 호출" << endl; }
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
	//k.Player::Move(); 문법이있지만 재정의한걸 또 사용하는건 좋지않고 사용하지도 않음


	k.Attack();
	k.Die();

	return 0;
}