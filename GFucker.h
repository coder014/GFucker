#include<windows.h>
#define KEYADD 0
#define KEYDEL 1

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void CALLBACK HandleHotKey(HWND hWnd, WPARAM wParam);
void realBSOD(void);
void RegKey(HWND hWnd,int func);