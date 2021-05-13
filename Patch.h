#pragma once

#include "Offset.h"
#include "D2Intercepts.h"

PatchHook pHooks[] = {
	{PatchCall, GetDllOffset("D2Gfx.DLL",0xB6A8),		(DWORD)Multi,			6},
	{PatchCall,	GetDllOffset("D2Gfx.DLL",0xB8D9),		(DWORD)Windowname,		6},
	{PatchJmp,	GetDllOffset("D2Launch.dll",0x10B03),	(DWORD)InitMainMenu,	5},
	{PatchJmp,  GetDllOffset("D2Client.dll", 0x1D7B4),  (DWORD)GameDraw_STUB,	6},
	{PatchCall,	GetDllOffset("BNCLIENT.dll",0xF494),	(DWORD)CacheFix,		6},
	{PatchCall,	GetDllOffset("BNCLIENT.dll",0xF7E4),	(DWORD)CacheFix,		6},

	{PatchBytes,GetDllOffset("D2CLIENT.dll",0x27713),	(WORD)0x9090,			2}, // Sleep
	{PatchBytes,GetDllOffset("D2Win.DLL",0xEDAF),		(BYTE)0xEB,				1}, // OOG Sleep

	{PatchBytes,GetDllOffset("D2MCPCLIENT.dll",0x61E0),	(DWORD)0xc3,			1}, // RD Blocker
	{PatchCall,GetDllOffset("D2CLIENT.dll",0x443FE),	(DWORD)FailToJoin_Interception,	6} // FTJ Reducer
};