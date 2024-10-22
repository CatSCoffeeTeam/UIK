#include <CatSCoffeeTeam/UIK/Core/UIK.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH: {

        } return TRUE;

        case DLL_THREAD_ATTACH: {

        } return TRUE;

        case DLL_THREAD_DETACH: {

        } return TRUE;

        case DLL_PROCESS_DETACH: {

        } return TRUE;
    }
}