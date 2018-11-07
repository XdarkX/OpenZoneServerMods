// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "DisablePK.h"

void InstallHooks()
{
	ZoneServerPrint("----- OpenZoneServerMods.dll v1.0.1 -----");
	ZoneServerPrint("Installing hooks...");
	HookIsEnabled2PK();
	ZoneServerPrint("Installing hooks completed!");
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InstallHooks, NULL, NULL, NULL);
		break;
	default:
        break;
    }
    return TRUE;
}

void ZoneServerPrint(const char *msg)
{
	// Calling original Print function from the ZoneServer
	((int(__cdecl*)(const char* string))0x00435EC0)(msg);
}

