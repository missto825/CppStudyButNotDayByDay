#include <iostream>
using namespace std;

class Knight
{
public:
	Knight operator+(const Knight& arg)
	{
		Knight k;
		k._attack = _attack + arg._attack;
		k._hp = _hp + arg._hp;
		k._defence = _defence + arg._defence;
		return k;
	}
public:
	int _attack;
	int _hp;
	int _defence;
};
Knight operator=(const Knight& arg)
{

}
int main()
{
	return 0;
}