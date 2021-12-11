#include "pPlayer.h"
#include <Windows.h>
void pPlayer:: StartMove()
{
	

	LookDirection();
}
void pPlayer::LookDirection()
{
	Message(L"나를 따르는 사람은 모두 뒤를 돌아라");
}

// private 항목입니다.

void pPlayer::DrawPlayer()
{
	
}