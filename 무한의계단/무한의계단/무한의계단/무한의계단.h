#pragma once

#include "resource.h"
#include <Windows.h>
#include "WinClass.h"
#include "Window.h"

class InfiniteStairs {
private:
    WinClass *m_pClass = nullptr;
    Window *m_pMainWindow = nullptr;

public:


    InfiniteStairs(HINSTANCE hInstance);


    virtual ~InfiniteStairs(void) {
        delete m_pClass;
        delete m_pMainWindow;
    }
    void Run(void);
};