#include <tchar.h>
#include "�����ǰ��.h"
#include "cCore.h"
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR*, int) {
    InfiniteStairs *pGame = nullptr;

    // ��ü�� �����ϰ� �����Ѵ�.
    pGame = new InfiniteStairs(hInstance);
    pGame->Run();
    
    if (!cCore::GetInst()->Init(hInstance))
    {
        cCore::DestroyCore();
        return 0;
    }
    //int iRev = cCore::GetInst()->Run();
    cCore::DestroyCore();
    // �����Ѵ�.
    delete pGame;

    return 0;
}