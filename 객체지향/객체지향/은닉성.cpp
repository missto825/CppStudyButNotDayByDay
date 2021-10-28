#include <iostream>
using namespace std;

//은닉성
//몰라도 되는건 깔끔하게 숨기는것!
// 
//일반 구매자 입장에서 사용하는것
// - 핸들 / 페달 / 문
//몰라도 되는것(건들면 큰일나는것)
// - 엔진, 각종 전기선


// public (공개적?) protected(보호받는?) private(개인의?)
// public : 모두 접근가능
// protected : 자기자식까지만 접근 가능
// private : 나만 사용할것

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지
// 부모님한테 물려받은 유산을 꼭 나의 자손들에게도 똑같이 물려줘야 하진 않음
// 근데 public만 씀, 하지만 c++ 기본 설정이 protected라서 public를 써줘야한다.
// - public : 공개적 상속, 부모님 유산 설계 그대로
// - protected : 보호받은 상속, 내 자손한테만 물러줌(한번만 상속)
// - private : 개인적인 상속, 나까지만 쓰고 자손한테는 안물러줌
class Car
{
public: // 접근 지정자
	void MoveHandle() { }
	void PushRedal() { }
	void OpenDoor() { }

	void TurnKey()
	{
		RunEngine();
	}
protected: // private 일경우 자식들이 받을수 없다.
	void DIsassembleCar() {}
	void RunEngine() { }
	void ConnectCiruit() { }

public:
	//핸들
	//페달
	//엔진
	//문
	//각종 전기선
};
class SuperCar : public Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};
class TestSupurCar : public SuperCar
{
public:
	void Test()
	{
		DIsassembleCar(); 
	}
};
// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:
	int GetHp() { return _hp; }
	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 ( 강해짐 )
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}
private:
	void SetBerserkerMode() {
		cout << "매우 강해짐!" << endl;
	}
private:
	int _hp = 100;
};
int main()
{
	TestSupurCar car;
	return 0;
}