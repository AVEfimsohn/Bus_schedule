#include "overall.h"

// Преобразует строку времени в time_t
time_t toTimeT(const char* timeStr) {
    struct tm tm = {};

    sscanf(timeStr, "%i:%i", &tm.tm_hour, &tm.tm_min);

    tm.tm_year = UNIX_YEAR;
    tm.tm_mon = UNIX_MONTH;
    tm.tm_mday = UNIX_DAY;
    return mktime(&tm);  // Конвертирует tm в time_t
}

// Проверяет, является ли символ цифрой
inline bool isDigit(char& chr) {
    return ('0' <= chr && chr <= '9');
}

// Преобразует символ в строку
inline string stringify(const char& chr) {
    return string(1, chr);
}

// Извлекает подстроку (две цифры) из строки времени
inline int substr(const char* str, const int& begValue, const int& endValue) {
    return stoi(stringify(str[begValue]) + stringify(str[endValue]));
}

// Ввод времени с валидацией
void inputTime(char* time) {
    bool isCorrect = true;

    do {
        isCorrect = true;

        cout << promptEnterTime;
        cin >> time;

        // Проверка формата HH:MM
        if (!(isDigit(time[0]) && isDigit(time[1]) && isDigit(time[3])
            && isDigit(time[4]) && (time[2] == ':'))) {
            cout << errorMessage;
            isCorrect = false;
        }
        // Проверка диапазона часов и минут
        else if (substr(time, 0, 1) > 23 || substr(time, 3, 4) > 59) {
            cout << invalidTimeMessage;
            isCorrect = false;
        }
    } while (!isCorrect);
}

// Ввод целого числа с обработкой ошибок
void inputIntValue(int& choice, const string& errorMessage) {
    while (!(cin >> choice)) {
        cout << errorMessage;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Конвертирует C-строку в широкую строку (для поддержки кириллицы)
wstring cstrToWstring(const char* str) {
    mbstate_t state = mbstate_t();
    const char* src = str;
    size_t len = mbsrtowcs(nullptr, &src, 0, &state);

    if (len == (size_t)(0))
        return L"";

    wstring wstr(len, L'\0');

    mbsrtowcs(&wstr[0], &str, len, &state);
    return wstr;
}

// Ввод выбора через getch() (без отображения ввода)
void inputChoice(int& choice, const string& errorMessage) {
    while (!(choice = getch())) {
        cout << errorMessage;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Ожидание нажатия любой клавиши
void wait() {
    cout << promptUserToEnterSmth;
    getch();
    system("cls");
}