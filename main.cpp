
#include "main.h"

BOOL Globals::sleepy = FALSE;
BOOL Globals::cachefix = FALSE;
BOOL Globals::rdblock = FALSE;
BOOL Globals::ftjReduce = FALSE;

BOOL WINAPI DllMain(HINSTANCE hDll,DWORD dwReason,LPVOID lpReserved) 
{
	if(dwReason==DLL_PROCESS_ATTACH) 
	{
		DisableThreadLibraryCalls(hDll);
		Install();
	}
	if (dwReason == DLL_PROCESS_DETACH)
		RemovePatches();

	return TRUE;
}

VOID WINAPI Install()
{
	sLine *Command;

	LoadLibraryA("D2GFX.dll");
	LoadLibraryA("D2WIN.dll");
	LoadLibraryA("BNCLIENT.dll");

	ParseCommandLine(GetCommandLineA());

	Command = GetCommand("-ftj");
	if(Command)
		Globals::ftjReduce = TRUE;

	Command = GetCommand("-rd");
	if(Command)
		Globals::rdblock = TRUE;

	Command = GetCommand("-cachefix");
	if(Command)
		Globals::cachefix = TRUE;

	Command = GetCommand("-sleepy");
	if(Command)
		Globals::sleepy = TRUE;

	DefineOffsets();
	InstallPatches();
}

DWORD WINAPI Unload(LPVOID lpParam)
{
	Sleep(100);
	FreeLibraryAndExitThread(GetModuleHandleA("D2M.dll"),0);
	return 0;
}

VOID WINAPI Shutdown()
{
	if (!Globals::cachefix && !Globals::sleepy)
		CreateThread(0,0,Unload,0,0,0);
}

