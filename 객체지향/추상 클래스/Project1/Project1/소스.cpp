#include <iostream>
using namespace std;

class Animal {
public:
	virtual void work() = 0;
};

class Dog {
public:
	virtual void work() { cout << "�� ������!" << endl; }
};
class Cat {
public:
	virtual void work() { cout << "�� ����..." << endl; }
};
int main()
{
	Dog d;
	d.work();
	Cat c;
	c.work();
//	Animal a;
	return 0;
}