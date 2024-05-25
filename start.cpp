#include <windows.h>

// Function declaration for the Window Procedure
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Entry point of our program
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"MyWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    // Register the window class
    if (!RegisterClassW(&wc)) {
        OutputDebugString(L"Error registering window class\n"); // Print error message
        return -1;
    }

    // Create the window
    HWND hWnd = CreateWindowW(L"MyWindowClass", L"Freddy & Mia (Early)", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 1280, 720, NULL, NULL, NULL, NULL);
    if (!hWnd) {
        OutputDebugString(L"Error creating window\n"); // Print error message
        return -1;
    }

    // Message loop
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Window Procedure: Handles events for our window
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}
