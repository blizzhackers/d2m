
#pragma once
#pragma comment(lib, "shlwapi.lib") 

#include <windows.h>
#include <shlwapi.h>
#include <stdio.h>
#include <time.h>
#include "Offset.h"
#include "File.h"
#include "ArrayEx.h"
#include "CommandLine.h"

#define ArraySize(x) (sizeof(x) / sizeof(x[0]))

VOID WINAPI Shutdown();
VOID WINAPI Install();
DWORD WINAPI Unload(LPVOID);

namespace Globals
{
	extern BOOL sleepy;
	extern BOOL cachefix;
	extern BOOL rdblock;
	extern BOOL ftjReduce;
}