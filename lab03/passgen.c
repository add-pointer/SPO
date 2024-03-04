#include <windows.h>
#include <stdio.h>
#include <time.h>

#define ID_GENERATE_BUTTON 101
#define ID_PASSWORD_TEXT 102

// Функция, которая генерирует случайный пароль
void GeneratePassword(HWND hwnd) {
    char password[16]; // Максимальная длина пароля - 15 символов

    // Используем текущее время как сид для генератора случайных чисел
    srand(time(NULL));

    // Генерируем случайный пароль из букв и цифр
    for (int i = 0; i < 8; i++) {
        int randomChar = rand() % 62;
        if (randomChar < 10) {
            password[i] = '0' + randomChar; // Цифры
        } else if (randomChar < 36) {
            password[i] = 'A' + (randomChar - 10); // Заглавные буквы
        } else {
            password[i] = 'a' + (randomChar - 36); // Строчные буквы
        }
    }
    password[8] = '\0'; // Завершаем строку нулевым символом

    // Отображаем сгенерированный пароль в текстовом поле
    HWND passwordText = GetDlgItem(hwnd, ID_PASSWORD_TEXT);
    SetWindowText(passwordText, password);
}

// Основная процедура обработки сообщений
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            // Создаем кнопку "Генерировать пароль"
            HWND generateButton = CreateWindow("BUTTON", "Generate password", WS_VISIBLE | WS_CHILD,
                                               10, 10, 150, 30, hwnd, (HMENU)ID_GENERATE_BUTTON, NULL, NULL);

            // Создаем текстовое поле для отображения пароля
            CreateWindow("STATIC", "Password:", WS_VISIBLE | WS_CHILD,
                         10, 50, 60, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY,
                         80, 50, 150, 20, hwnd, (HMENU)ID_PASSWORD_TEXT, NULL, NULL);
            break;
        }
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case ID_GENERATE_BUTTON:
                    GeneratePassword(hwnd);
                    break;
            }
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = "PasswordGenerator";

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Ошибка регистрации класса окна!", "Ошибка", MB_ICONERROR);
        return 1;
    }

    HWND hwnd = CreateWindowEx(0, "PasswordGenerator", "Password Generator", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 300, 150, NULL, NULL, hInstance, NULL);

    if (!hwnd) {
        MessageBox(NULL, "Ошибка создания окна!", "Ошибка", MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
