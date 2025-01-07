#include <windows.h>
#include <string>
using namespace std;
constexpr int FirstText = 1;
constexpr int SecondText = 2;
constexpr int FirstMn = 3;
constexpr int SecondMn = 4;
constexpr int FindB = 5;
constexpr int FindF = 6;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: {

        CreateWindowEx(0, "STATIC", "Первое множество:",
            WS_CHILD | WS_VISIBLE,
            50, 50, 200, 25, hwnd, (HMENU)FirstText, NULL, NULL);
        CreateWindowEx(0, "STATIC", "Второе множество:",
            WS_CHILD | WS_VISIBLE,
            50, 150, 200, 25, hwnd, (HMENU)SecondText, NULL, NULL);

        CreateWindowEx(0, "EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            50, 80, 400, 25, hwnd, (HMENU)FirstMn, NULL, NULL);
        CreateWindowEx(0, "EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            50, 180, 400, 25, hwnd, (HMENU)SecondMn, NULL, NULL);

        CreateWindowEx(0, "BUTTON", "Найти объединение множеств",
            WS_CHILD | WS_VISIBLE,
            125, 220, 250, 30, hwnd, (HMENU)FindB, NULL, NULL);
        CreateWindowEx(0, "STATIC", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            50, 300, 400, 120, hwnd, (HMENU)FindF, NULL, NULL);
        break;
    }

    case WM_COMMAND: {
        if (LOWORD(wParam) == FindB) {
            char firstMnozh[512], secondMnozh[512];
            GetDlgItemText(hwnd, FirstMn, firstMnozh, sizeof(firstMnozh));
            GetDlgItemText(hwnd, SecondMn, secondMnozh, sizeof(secondMnozh));
            string firstStr = firstMnozh, secondStr = secondMnozh, resultOfMnozh="Объединением множеств являются значения:\n", bufW;
            bool foundedFull=false;
            for (int i = 0; i < firstStr.size(); i++) {
                if (firstStr[i] != ' ')
                    bufW += firstStr[i];
                if (firstStr[i + 1] == ' ' || firstStr[i+1]=='\0')
                    foundedFull = true;
                if (foundedFull) {
                    if (secondStr.find(bufW) != string::npos)
                        resultOfMnozh += bufW+" ";
                    foundedFull = false;
                    bufW = "";
                }
            }
            SetDlgItemText(hwnd, FindF, resultOfMnozh.c_str());
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nShowCmd) {
    const char CLASS_NAME[] = "SimpleAppClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Lab_11",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 550,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nShowCmd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}