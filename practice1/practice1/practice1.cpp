#include <Windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM IParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
    static LPTSTR szAppName = "EasyText";
    static LPTSTR szTitleName = "Practice1-1";

    HWND hwnd;
    MSG msg;
    WNDCLASSEX WndClass;

    WndClass.cbSize = sizeof(WNDCLASSEX);
    WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    WndClass.lpfnWndProc = WndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = szAppName;
    WndClass.hIconSm = 0;

    RegisterClassEx(&WndClass);

    hwnd = CreateWindow(
        szAppName,
        szTitleName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
    }

    LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM IParam) {
        HDC hdc;
        RECT rect;
        PAINTSTRUCT ps;
        LPTSTR szMsg1 = "I Love Window Programming!";
        LPTSTR szMsg2 = "키보드가 눌러졌습니다";
        LPTSTR szMsg3 = "키보드가 떼어졌습니다.";

        switch (message)
        {
        case WM_CREATE:
            break;
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));
            EndPaint(hwnd, &ps);
            break;
        case WM_KEYDOWN:
            hdc = GetDC(hwnd);
            GetClientRect(hwnd, &rect);
            DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            ReleaseDC(hwnd, hdc);
            break;
        case WM_KEYUP:
            hdc = GetDC(hwnd);
            GetClientRect(hwnd, &rect);
            DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            ReleaseDC(hwnd, hdc);
            break;
        case WM_LBUTTONDBLCLK:
            MessageBox(hwnd, "마우스 더블 클릭!", "마우스메시지", MB_OK | MB_ICONASTERISK);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, IParam);
        }
        return 0;
    }