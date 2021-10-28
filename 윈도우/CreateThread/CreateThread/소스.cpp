#include "windows.h"
#include "iostream"
#include "tchar.h"
using namespace std;

void _tmain()
{
	cout << "Main thread creating sub thread..." << endl;

	DWORD dwThreadID = 0;
	HANDLE hThread = CreateThread
	(
		NULL,
		0,
		ThreadProc(),
		(PVOID)5000,
		0,
		&dwThreadID
	);
	if (hThread == NULL)
	{
		cout << "~~~ CreateThread failed,error code : " << GetLastError() << endl;
		return;
	}
	Sleep(10000);
	DWORD dwExitCode = 0;
	GetExitCodeThread(hThread, &dwThreadID);

	cout << "Sub thread " << dwThreadID << " terminated with ExitCode " << dwExitCode << endl;

	CloseHandle(hThread);
}

DWORD WINAPI ThreadProc(PVOID pParam)
{
	DWORD dwDelay = (DWORD)pParam;
	cout << ">>>>> Thread " << GetCurrentThreadId() << " enter." << endl;
	Sleep(dwDelay);
	cout << ">>>>> Thread " << GetCurrentThreadId() << " leave." << endl;
}
