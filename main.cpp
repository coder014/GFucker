#include"GFucker.h"
#include"resource.h"
extern ATOM hk_f, hk_d, hk_q, hk_r;
bool isHide;
int WINAPI WinMain(						//main entry
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	HANDLE hMutex = CreateMutex(NULL, FALSE, "FuckYYK_e3caefa67c8ae96cf157");	//create mutex
	if (hMutex)
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)
		{
			CloseHandle(hMutex);
			return -1;
		}
	}
	else
	{
		CloseHandle(hMutex);
		return -1;
	}

	SetProcessDPIAware();
	MSG msg;
	BOOL bRet;

	MyRegisterClass(hInstance);
	if (!InitInstance(hInstance))
		return -1;

	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
			break;
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

BOOL InitInstance(HINSTANCE hInstance)		//init window
{
	HWND hWnd_t = GetDesktopWindow();
	HDC hdc = GetWindowDC(hWnd_t);
	int w = GetDeviceCaps(hdc, DESKTOPHORZRES);
	int h = GetDeviceCaps(hdc, DESKTOPVERTRES);
	ReleaseDC(hWnd_t, hdc);

	HWND hWnd = NULL;
	hWnd = CreateWindowEx(
		WS_EX_TOPMOST,
		"GFUCKER",
		"GFUCKER",
		NULL,
		0, 0,
		w, h,
		NULL, NULL, hInstance, NULL);

	if (hWnd == NULL)
		return FALSE;

	LONG lStyle = GetWindowLong(hWnd, GWL_STYLE);
	SetWindowLong(hWnd, GWL_STYLE, lStyle & ~WS_CAPTION);

	RegKey(hWnd, KEYADD);
	ShowCursor(false);
	//isHide = false;
	isHide = true;
	ShowWindow(hWnd, SW_HIDE);
	//ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	return TRUE;
}

ATOM MyRegisterClass(HINSTANCE hInstance)	//register class
{
	WNDCLASSEX mywnd;
	ZeroMemory(&mywnd, sizeof(mywnd));

	HBITMAP hBmp = (HBITMAP)LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	HBRUSH hbrBackground = CreatePatternBrush(hBmp);

	mywnd.cbSize = sizeof(mywnd);
	mywnd.lpfnWndProc = WindowProc;
	mywnd.hInstance = hInstance;
	mywnd.lpszClassName = "GFUCKER";
	mywnd.style = CS_HREDRAW | CS_VREDRAW;
	mywnd.hbrBackground = hbrBackground;
	mywnd.hCursor = NULL;
	mywnd.hIcon = NULL;
	mywnd.cbClsExtra = 0;
	mywnd.cbWndExtra = 0;

	return RegisterClassEx(&mywnd);
}

void CALLBACK HandleHotKey(HWND hWnd, WPARAM wParam)
{
	if (wParam == hk_f)
	{
		ShowWindow(hWnd, SW_SHOW);
		isHide = false;
	}
	else if (wParam == hk_d)
	{
		ShowWindow(hWnd, SW_HIDE);
		isHide = true;
	}
	else if (wParam == hk_q)
	{
		RegKey(hWnd, KEYDEL);
		ShowCursor(true);
		isHide = true;
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}
	/*else if (wParam == hk_r)
		realBSOD();*/
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_PAINT:	break;
	case WM_KILLFOCUS:
	{
		if (!isHide)
		{
			HWND hForegdWnd = GetForegroundWindow();
			DWORD dwForegdWndThreadID = GetWindowThreadProcessId(hForegdWnd, NULL);
			DWORD dwThreadID = GetCurrentThreadId();
			AttachThreadInput(dwThreadID, dwForegdWndThreadID, TRUE);
			SetForegroundWindow(hWnd);
			SetFocus(hWnd);
			AttachThreadInput(dwThreadID, dwForegdWndThreadID, FALSE);
		}
		break;
	}
	case WM_HOTKEY:
	{
		HandleHotKey(hWnd,wParam);
		break;
	}
	case WM_CLOSE:	break;
	default:	return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}