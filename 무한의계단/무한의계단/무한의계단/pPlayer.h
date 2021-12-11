#pragma once
#include "cCore.h"
class pPlayer : public cCore
{
public:
	void StartMove();
	void LookDirection();

private:
	void DrawPlayer();
};

