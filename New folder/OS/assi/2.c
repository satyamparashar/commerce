#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[]) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create a child process
    if (!CreateProcess(
        NULL,               // Application name
        _T("notepad"),      // Command line
        NULL,               // Process handle not inheritable
        NULL,               // Thread handle not inheritable
        FALSE,              // Set handle inheritance to FALSE
        0,                  // No creation flags
        NULL,               // Use parent's environment block
        NULL,               // Use parent's starting directory
        &si,                // Pointer to STARTUPINFO structure
        &pi                 // Pointer to PROCESS_INFORMATION structure
    )) {
        _tprintf(_T("CreateProcess failed (%d)\n"), GetLastError());
        return 1;
    }

    _tprintf(_T("Child process created with PID: %d\n"), pi.dwProcessId);

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
