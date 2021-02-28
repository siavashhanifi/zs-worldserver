#include "main.h"

using namespace zs_worldserver;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    WindowConfig config = { hInstance, nCmdShow, L"MainClass", "zs_worldserver client" };
    WindowCreator window(config);
    HWND hWindow = window.getWindow();

    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (!SUCCEEDED(hr)) {
        MessageBox(
            hWindow,
            L"Failed to initialize COM Library",
            L"Error",
            MB_OK
        );
    }

    window.messageLoop();

    CoUninitialize();
    return 0;
}

