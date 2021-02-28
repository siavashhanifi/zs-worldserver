#include "WindowCreator.h"

zs_worldserver::WindowCreator::WindowCreator(WindowConfig config) {
    this->config = config;
    registerWindow();
    createWindow();
    showWindow();
}

void zs_worldserver::WindowCreator::registerWindow() {
 
    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = config.hInstance;
    wc.lpszClassName = (LPCSTR) config.winClassName.c_str();

    RegisterClass(&wc);
}

void zs_worldserver::WindowCreator::createWindow() {
    LPCSTR className = (LPCSTR) config.winClassName.c_str();
    LPCSTR windowName = (LPCSTR) config.windowName.c_str();

    hWindow = CreateWindowEx(
        0,                              // Optional window styles.
        className,                     // Window class
        windowName,    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        config.hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hWindow == NULL)
        throw std::runtime_error("Failed to create window.");
}

void zs_worldserver::WindowCreator::showWindow() {
    ShowWindow(hWindow, config.nCmdShow);
}

void zs_worldserver::WindowCreator::messageLoop() {
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

HWND zs_worldserver::WindowCreator::getWindow() {
    return hWindow;
}

void zs_worldserver::WindowCreator::onPaint() {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWindow, &ps);
    FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_GRAYTEXT + 1));
    EndPaint(hWindow, &ps);
}

LRESULT zs_worldserver::WindowCreator::handleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        this->onPaint();
    }
    return 0;

    default:
        return DefWindowProc(hWindow, uMsg, wParam, lParam);
    }
    return TRUE;
}

LRESULT CALLBACK zs_worldserver::WindowCreator::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    WindowCreator* pThis = NULL;

    if (uMsg == WM_NCCREATE) {
        CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
        pThis = (WindowCreator*)pCreate->lpCreateParams;
    }

    if (pThis)
    {
        return pThis->handleMessage(uMsg, wParam, lParam);
    }
    else
    {
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

