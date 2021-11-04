#include <iostream>
using namespace std;

//다형성(Polymorphism) 겉은 똑같은데, 기능이 다름
//오버로딩(Overloading) 함수 중복 정의 = 함수 이름의 재사용
//오버라이딩(Overriding) 재정의, 부모 클래스의 함수를 자식 클래스에서 재사용

//바인딩(Binding) = 묶는다.
// -정적 바인딩(Static Binging) : 컴파일 시점에 결정
// -동적 바인딩(Dynamic Binging) : 실행 시점에 결정
// 
// 일반 함수는 정적 바인딩을 사용
// 동적 바인딩을 원한다면? -> 가상 함수 (virtual function)

//가상함수는 어떻게 알아서 타입을 찾을수 있던걸까?
//객체지향의 또다른 좋은점
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
	//가상 함수는 재정의를 하더라도 가상함수다!
	//즉, virtual이 없어도 가상함수가 됨
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
	//MoveKnight(&p); 플레이어는 기사다? NO


	Knight k;
	//MoveKnight(&k);
	MovePlayer(&k); // 기사는 플레이어다? YES
	//플레이어의 코드가 발생한다.


	//즉, 최상위 객체로 뭉뚱그려 코드를 짤수 있다.
	return 0;
}