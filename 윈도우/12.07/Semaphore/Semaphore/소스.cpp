#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;
#define MAX_COUNT 3

bool g_bExit = false;

BOOL g_abUsedFlag[MAX_COUNT];
INT g_anSharedRes[MAX_COUNT] = { 5,3,7};
HANDLE g_hShareLock; //���� �ڿ��� �˻��� ���� ���ؽ� �ڵ�...���� �ڿ��� �˻��̸� �ڿ��� � ���ҳ� �˻��ΰ�

DWORD WINAPI SemaphoreProc(PVOID pParam);

void _tmain()
{
	cout << "�������� �׽�Ʈ ����" << endl;
	g_hShareLock = CreateMutex(NULL, FALSE, NULL);
	//���������� ��� �������� �����尡 ����Ȱ��ȭ�� ����,���� ���ؽ��� �̵� ���̿����� ����ȭ�� �����ش�.
	HANDLE hSemaphore = CreateSemaphore(NULL, MAX_COUNT, MAX_COUNT, NULL);
	//�������� ����, ���������� ���ȼӼ��� �̸��� ù,�������� NULL�� �ְ� ��밡���� �ִ� ���ڿ������� 3, ���� ��밡���� Ƚ���� 3���� �ñ׳� ���·� �������.

	DWORD dwThrld;
	HANDLE hThreads[MAX_COUNT + 2];
	for (int i = 0; i < MAX_COUNT + 2; i++)
		hThreads[i] = CreateThread(NULL, 0, SemaphoreProc, hSemaphore, 0, &dwThrld);
	// �����带 ����� �Ѱ��ش�. �̷��� ������� ������ ���ʰ� 3�������� 2���� ��⿡������.
	getchar();
	g_bExit = true;

	WaitForMultipleObjects(MAX_COUNT + 2, hThreads, TRUE, INFINITE);

	for (int i = 0; i < MAX_COUNT + 2; i++)
		CloseHandle(hThreads[i]);
	CloseHandle(hSemaphore);
	CloseHandle(g_hShareLock);

	cout << "�������� �׽�Ʈ�� �������ϴ�" << endl;
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
			cout << "WaitForSingleObject�� �����Ͽ����ϴ� ! ���� : " << GetLastError() << endl;
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

		cout << dwThreadId << "�����尡" << g_anSharedRes[nSharedIdx] * 1000 << "��ŭ�� �ð���" << "��ٸ���" << endl;
		Sleep((DWORD)g_anSharedRes[nSharedIdx] * 1000);
		cout << "������" << dwThreadId << "�� ������� �������ߴ��" << endl;
		g_abUsedFlag[nSharedIdx] = FALSE;

		ReleaseSemaphore(hSemaphore, 1, NULL);
	}
	cout << " *** ������ " << dwThreadId << "�� Ż���߽��ϴ�." << endl;
	return 0;
}