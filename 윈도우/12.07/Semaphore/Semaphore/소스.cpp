#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;
#define MAX_COUNT 3

bool g_bExit = false;

BOOL g_abUsedFlag[MAX_COUNT];
INT g_anSharedRes[MAX_COUNT] = { 5,3,7};
HANDLE g_hShareLock; //가용 자원의 검색을 위한 뮤텍스 핸들...가용 자원의 검색이면 자원이 몇개 남았나 검색인가

DWORD WINAPI SemaphoreProc(PVOID pParam);

void _tmain()
{
	cout << "세마포어 테스트 시작" << endl;
	g_hShareLock = CreateMutex(NULL, FALSE, NULL);
	//세마포어의 경우 여러개의 스레드가 동시활성화가 가능,따라서 뮤텍스로 이들 사이에서도 동기화를 시켜준다.
	HANDLE hSemaphore = CreateSemaphore(NULL, MAX_COUNT, MAX_COUNT, NULL);
	//세마포어 생성, 마찬가지로 보안속성과 이름인 첫,마지막은 NULL로 주고 사용가능한 최대 ㅈ자원개수를 3, 최초 사용가능한 횟수도 3으로 시그널 상태로 만들었다.

	DWORD dwThrld;
	HANDLE hThreads[MAX_COUNT + 2];
	for (int i = 0; i < MAX_COUNT + 2; i++)
		hThreads[i] = CreateThread(NULL, 0, SemaphoreProc, hSemaphore, 0, &dwThrld);
	// 스레드를 만들어 넘겨준다. 이러면 세마포어가 지정한 최초가 3개였으니 2개는 대기에빠진다.
	getchar();
	g_bExit = true;

	WaitForMultipleObjects(MAX_COUNT + 2, hThreads, TRUE, INFINITE);

	for (int i = 0; i < MAX_COUNT + 2; i++)
		CloseHandle(hThreads[i]);
	CloseHandle(hSemaphore);
	CloseHandle(g_hShareLock);

	cout << "세마포어 테스트가 끝났습니다" << endl;
}

DWORD WINAPI SemaphoreProc(PVOID pParam)
{
	HANDLE hSemaphore = (HANDLE)pParam;
	DWORD dwThreadId = GetCurrentThreadId();
	while (!g_bExit)
	{
		DWORD dwWaitCode = WaitForSingleObject(hSemaphore, INFINITE);
		if (dwWaitCode == WAIT_FAILED)
		{
			cout << "WaitForSingleObject가 실패하엿습니다 ! 이유 : " << GetLastError() << endl;
			break;
		}
		int nSharedIdx = 0;
		WaitForSingleObject(g_hShareLock, INFINITE);
		for (; nSharedIdx < MAX_COUNT; nSharedIdx++)
		{
			if (!g_abUsedFlag[nSharedIdx])
				break;
		}
		g_abUsedFlag[nSharedIdx] = TRUE;
		ReleaseMutex(g_hShareLock);

		cout << dwThreadId << "스레드가" << g_anSharedRes[nSharedIdx] * 1000 << "만큼의 시간을" << "기다린다" << endl;
		Sleep((DWORD)g_anSharedRes[nSharedIdx] * 1000);
		cout << "스레드" << dwThreadId << "가 세마포어를 릴리즈했대요" << endl;
		g_abUsedFlag[nSharedIdx] = FALSE;

		ReleaseSemaphore(hSemaphore, 1, NULL);
	}
	cout << " *** 스레드 " << dwThreadId << "가 탈출했습니다." << endl;
	return 0;
}