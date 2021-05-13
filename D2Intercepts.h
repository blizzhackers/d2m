#ifndef D2INTERCEPTS_H
#define D2INTERCEPTS_H


HMODULE __stdcall Multi(LPSTR Class,LPSTR Window);
VOID  __fastcall InitMainMenu();
DWORD MainMenuAddress();
HANDLE __stdcall Windowname(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
HANDLE __stdcall CacheFix(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
void GameDraw(void);
VOID __fastcall ClassicSTUB();
VOID __fastcall LodSTUB();
void GameDraw_STUB();
void FailToJoin_Interception();

extern CHAR szClassic[26];
extern CHAR szLod[26];

#endif
