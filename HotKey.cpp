#include "GFucker.h"

extern ATOM hk_f, hk_d, hk_q, hk_r;
ATOM hk_f, hk_d, hk_q, hk_r;
void RegKey(HWND hWnd, int func)
{
	switch (func)
	{
		case KEYADD:
		{
			hk_f = GlobalAddAtom("GFucker_show");
			hk_d = GlobalAddAtom("GFucker_hide");
			hk_q = GlobalAddAtom("GFucker_quit");
			//hk_r = GlobalAddAtom("GFucker_real");
			RegisterHotKey(hWnd, hk_f, MOD_ALT | MOD_CONTROL | MOD_SHIFT, 'F');
			RegisterHotKey(hWnd, hk_d, MOD_ALT | MOD_CONTROL | MOD_SHIFT, 'D');
			RegisterHotKey(hWnd, hk_q, MOD_ALT | MOD_CONTROL | MOD_SHIFT, 'Q');
			//RegisterHotKey(hWnd, hk_r, MOD_ALT | MOD_CONTROL | MOD_SHIFT, 'R');
			break;
		}
		case KEYDEL:
		{
			UnregisterHotKey(hWnd, hk_f);
			UnregisterHotKey(hWnd, hk_d);
			UnregisterHotKey(hWnd, hk_q);
			//UnregisterHotKey(hWnd, hk_r);
			GlobalDeleteAtom(hk_f);
			GlobalDeleteAtom(hk_d);
			GlobalDeleteAtom(hk_q);
			//GlobalDeleteAtom(hk_r);
		}
	}
}