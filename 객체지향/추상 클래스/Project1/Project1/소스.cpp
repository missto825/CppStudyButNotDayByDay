#include <iostream>
using namespace std;

class Animal {
public:
	virtual void work() = 0;
};

class Dog {
public:
	virtual void work() { cout << "난 강하지!" << endl; }
};
class Cat {
public:
	virtual void work() { cout << "난 고얌미..." << endl; }
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