
#include "main.h"
#include "D2Intercepts.h"

HMODULE __stdcall Multi(LPSTR Class, LPSTR Window){ return 0; }

DWORD MainMenuAddress(){ return GetDllOffset("D2Launch.dll",0x10B08); } //Backjmp.

VOID __declspec(naked) __fastcall InitMainMenu()
{
	__asm{
		call Shutdown
		pop esi
		pop ebp
		add esp,0x20
		jmp [MainMenuAddress]
	}
}

HANDLE __stdcall Windowname(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam)
{
	ParseCommandLine(GetCommandLineA());

	CHAR szWindowName[100] = "Diablo II";
	sLine *Command = GetCommand("-title");

	if(Command)
		if(strlen(Command->szText) > 1)
			strcpy_s(szWindowName,sizeof(szWindowName),Command->szText);

	return CreateWindowExA(dwExStyle,lpClassName,szWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);
}


HANDLE __stdcall CacheFix(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile)
{
	EraseCacheFiles();
	CHAR path[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH,path);

	if (Globals::cachefix)
	{
		ParseCommandLine(GetCommandLineA());
		sLine *Command = GetCommand("-title");
		CHAR Def[100] = "";
		
		if (Command)
		{
			sprintf_s(Def,"\\bncache%d.dat", Command);

			strcat_s(path,Def);
		}
		else
		{
			srand((unsigned int)time(NULL));
			sprintf_s(Def,"\\bncache%d.dat",rand()%0x2000);

			strcat_s(path,Def);
		}
	}
	else
		strcat_s(path,"\\bncache.dat");

	return CreateFileA(path,dwDesiredAccess,dwShareMode,lpSecurityAttributes,dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);
}

void GameDraw(void)
{
	if (Globals::sleepy)
		Sleep(10);
}

void __declspec(naked) GameDraw_STUB()
{
	__asm
	{
		call GameDraw;

		POP ESI
		POP EBX
		POP ECX
		RETN 4
	}
}

void __declspec(naked) FailToJoin_Interception()
{
    __asm
    {
        cmp esi, 4000;
        ret;
    }
}