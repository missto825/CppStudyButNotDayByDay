#include "WinClass.h"
#include "gFileBundle.h"
WinClass::WinClass(HINSTANCE hInstance) {


    // WNDCLASS�� ���� ä���.


    this->cbClsExtra = 0;
    this->cbWndExtra = 0;
    this->hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
    this->hCursor = LoadCursor(nullptr, IDC_ARROW);
    this->hIcon = LoadIcon(nullptr, IDC_ICON);
    this->hInstance = hInstance;
    this->lpfnWndProc = cCore::WndProc;
    this->lpszClassName = TEXT("WinClass");
    this->lpszMenuName = nullptr;
    this->style = 0;

    // �� Ŭ������ WNDCLASS�κ��� ��� �޾Ҵ�.

    RegisterClass(this);
}