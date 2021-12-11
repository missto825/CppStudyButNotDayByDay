#include <tchar.h>
#include "무한의계단.h"
#include "cCore.h"
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR*, int) {
    InfiniteStairs *pGame = nullptr;

    // 객체를 생성하고 실행한다.
    pGame = new InfiniteStairs(hInstance);
    pGame->Run();
    
    if (!cCore::GetInst()->Init(hInstance))
    {
        cCore::DestroyCore();
        return 0;
    }
    //int iRev = cCore::GetInst()->Run();
    cCore::DestroyCore();
    // 종료한다.
    delete pGame;

    return 0;
}