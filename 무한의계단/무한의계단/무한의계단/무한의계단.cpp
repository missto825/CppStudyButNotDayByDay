#include "무한의계단.h"

InfiniteStairs::InfiniteStairs(HINSTANCE hInstance) {
	m_pClass = new WinClass(hInstance);
	m_pMainWindow = new Window(m_pClass->GetName(), TEXT("SampleApp"), hInstance);
}

void InfiniteStairs::Run(void) {
	MSG msg = { };

	m_pMainWindow->Show(true);

	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}