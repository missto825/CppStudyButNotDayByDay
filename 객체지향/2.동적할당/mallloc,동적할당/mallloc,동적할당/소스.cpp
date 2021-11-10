#include <iostream>
using namespace std;
// 동적할당과 연관된 함수/연산자 : malloc / free, new/ delete , new[] / delete[]

// malloc
// - 할당할 메모리 크기를 건내준다(size_t)
// - 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다.(메모리 부족은 NULL)
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
	// void* , 새로운 문법
	// void니까 아무것도 없는것은 아니다
	// 타고가면 void 뭐가 있는지 모르니 너가 알아서 변환해 사용해라
	void* pointer = malloc(sizeof(Monster));
	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// Heap Overflow
	// - 유효한 힙 범위를 초과해 사용하여 발생하는 문제

	free(pointer); //필요가 없어지면 놔주면 된다!
	//free를 하지 않으면 메모리가 계속 늘어나서 메모리 눗
	free(pointer);
	//Double free
	// - 이건 대부분 그냥 크러시만 나고 끝난다.

	// Use-After-Free
	// 	이미 free로 할당을 해제를 해도 그 변수에 접근 할수있는데, 이경우 완전히 다른 값에 들어갈수도있고
	//  언제 일어났는지 모를수도 있기에 재앙이 된다.
	// - 프로그래머 입장 : 개망,메모리가 전혀 딴데에서 일어남
	// - 해커는 뚫기 쉬워짐
	//m1->_hp = 100;
	//m1->_x = 1;
	//m1->_y = 2;
	return 0;
}

