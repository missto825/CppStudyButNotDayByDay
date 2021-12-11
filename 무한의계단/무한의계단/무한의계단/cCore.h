#pragma once
#include <Windows.h>
#include "gFileBundle.h"
class cCore
{
private:
	static cCore* m_pCore;
public:
	static cCore* GetInst()
	{
		if (!m_pCore)
			m_pCore = new cCore;
		return m_pCore;
	}
	static void DestroyCore()
	{
		delete m_pCore;
	}

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
public:
	bool Init(HINSTANCE hInst);
	void Message(LPCWSTR text);
private:
	PAINTSTRUCT ps;

private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	RESOLUTION m_tRs;

private:
	HDC Memdc;
	HDC hdc;  
};  

