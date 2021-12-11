#include "cCore.h"
bool cCore::Init(HINSTANCE hInst)
{
	m_hInst = hInst;

	m_tRs.iW = 1280;
	m_tRs.iH = 720;
	return true;
}
LRESULT CALLBACK cCore::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg) {
	case WM_CREATE:
	{
		break;

	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
void cCore::Message(LPCWSTR text)
{
	MessageBox(m_hWnd, text, text, NULL);
}