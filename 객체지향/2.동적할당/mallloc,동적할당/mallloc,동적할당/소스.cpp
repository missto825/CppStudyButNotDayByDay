#include <iostream>
using namespace std;
// 동적할당과 연관된 함수/연산자 : malloc / free, new/ delete , new[] / delete[]

// malloc
// - 할당할 메모리 크기를 건내준다(size_t)
// - 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다.(메모리 부족은 NULL)
// free
// 

// new / delete
// - C++에 추가됨
// malloc/free는 함수! new/delete는 연산자


// new[] / delete[]
// - new가 malloc에 비해 좋지만,여러개가 피룡할수도 있다!

// malloc/free vs new/delete
// - 사용 편의성 -> new/delete가 훨씬 좋다!
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받을려면 -> malloc/free

// 하지만 가장 중요한 차이점은 malloc/free와 다르게 new/delete는 생성자/소멸자를 호출해준다.
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
	//free(pointer);
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


	Monster* m2 = new Monster;
	//기본적으로 malloc의 오류는 다 뜬다.
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;
	delete m2; //free처럼 무조건 해주자!

	Monster* m3 = new Monster[5];
	m3->_hp = 200;
	m3->_x = 2;
	m3->_y = 3;

	Monster* m4 = (m3+1);
	delete[] m3;


	return 0;


	
}

