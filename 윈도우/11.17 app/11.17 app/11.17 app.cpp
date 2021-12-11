#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <tchar.h>
#include <iostream>
using namespace std;
#define NUM_OF_GATE 2           // 쓰레드 개수

LONG gTotalCount = 0;

CRITICAL_SECTION hCriticalSection;

void problem()
{
    gTotalCount++;
}
int g_id = 0;
//unsigned int WINAPI ThreadProc(LPVOID lpParam)
//{
//    int id=g_id++;
//    while(true)
//    {
//        if(id==0)
//            Sleep(1000);
//        else
//            Sleep(100);
//        EnterCriticalSection(&hCriticalSection);
//        if(id==0)
//            Sleep(100);
//        else
//            Sleep(100);
//        cout<<id<<"    ";
//        LeaveCriticalSection(&hCriticalSection);
//    }
//    return 0;
//}
unsigned int WINAPI ThreadProc(LPVOID lpParam)
{
    int id = g_id++;
    while (true)
    {
        if (id == 0)
            Sleep(100);

        EnterCriticalSection(&hCriticalSection);
        if (id == 0)
        {
            Sleep(10);
            cout << id << endl;
        }
        else
        {
            Sleep(10);
            cout << id << "    ";
        }
        LeaveCriticalSection(&hCriticalSection);
    }
    return 0;
}
int _tmain(int argc, TCHAR* argv[])
{
    DWORD dwThreadId[NUM_OF_GATE];
    HANDLE hThread[NUM_OF_GATE];

    InitializeCriticalSection(&hCriticalSection);

    for (DWORD i = 0; i < NUM_OF_GATE; i++)
    {
        hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, NULL, CREATE_SUSPENDED, (unsigned*)&dwThreadId[i]);

        if (hThread[i] == NULL)
        {
            _tprintf(_T("Thread creation fault!\n"));
            return -1;
        }
    }

    for (DWORD i = 0; i < NUM_OF_GATE; i++)
    {
        ResumeThread(hThread[i]);
    }

    WaitForMultipleObjects(NUM_OF_GATE, hThread, TRUE, INFINITE);

    _tprintf(_T("total count : %d \n"), gTotalCount);

    for (DWORD i = 0; i < NUM_OF_GATE; i++)
    {
        CloseHandle(hThread[i]);
    }

    DeleteCriticalSection(&hCriticalSection);
    return 0;
}