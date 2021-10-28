#include <iostream>
using namespace std;

//���м�
//���� �Ǵ°� ����ϰ� ����°�!
// 
//�Ϲ� ������ ���忡�� ����ϴ°�
// - �ڵ� / ��� / ��
//���� �Ǵ°�(�ǵ�� ū�ϳ��°�)
// - ����, ���� ���⼱


// public (������?) protected(��ȣ�޴�?) private(������?)
// public : ��� ���ٰ���
// protected : �ڱ��ڽı����� ���� ����
// private : ���� ����Ұ�

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������
// �θ������ �������� ������ �� ���� �ڼյ鿡�Ե� �Ȱ��� ������� ���� ����
// �ٵ� public�� ��, ������ c++ �⺻ ������ protected�� public�� ������Ѵ�.
// - public : ������ ���, �θ�� ���� ���� �״��
// - protected : ��ȣ���� ���, �� �ڼ����׸� ������(�ѹ��� ���)
// - private : �������� ���, �������� ���� �ڼ����״� �ȹ�����
class Car
{
public: // ���� ������
	void MoveHandle() { }
	void PushRedal() { }
	void OpenDoor() { }

	void TurnKey()
	{
		RunEngine();
	}
protected: // private �ϰ�� �ڽĵ��� ������ ����.
	void DIsassembleCar() {}
	void RunEngine() { }
	void ConnectCiruit() { }

public:
	//�ڵ�
	//���
	//����
	//��
	//���� ���⼱
};
class SuperCar : public Car // ��� ���� ������
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
// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� �������� ������� ��
class Berserker
{
public:
	int GetHp() { return _hp; }
	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ� ( ������ )
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}
private:
	void SetBerserkerMode() {
		cout << "�ſ� ������!" << endl;
	}
private:
	int _hp = 100;
};
int main()
{
	TestSupurCar car;
	return 0;
}