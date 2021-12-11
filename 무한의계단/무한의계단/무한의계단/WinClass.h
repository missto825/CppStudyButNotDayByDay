#pragma once

#include <Windows.h>
#include <string>
class WinClass:private WNDCLASS
{
private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
public:
    WinClass(HINSTANCE hInstance);
    virtual ~WinClass(void) { }
    std::basic_string<TCHAR> GetName(void) const { return TEXT("WinClass"); }
};

