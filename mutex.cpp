#include <iostream>
#include <windows.h>

//checking mutex
BOOL IsAlreadyRun()
{
    HANDLE hMutex = NULL;
    hMutex = ::CreateMutex(NULL, FALSE, L"check_v");
    if (hMutex)
    {
        if (ERROR_ALREADY_EXISTS == ::GetLastError())
        {
            MessageBoxW(NULL, L"傻屌，程序已经开始运行啦！", L"Message", MB_OK | MB_ICONINFORMATION);
            return TRUE;
        }
    }
    return FALSE;
}

int main()
{
    if (IsAlreadyRun())
    {
        return 0;
    }
    system("pause");
    return 0;
    
}

