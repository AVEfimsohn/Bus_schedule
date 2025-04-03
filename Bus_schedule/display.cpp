#include "display.h"

// Функция для вывода всех рейсов в табличном формате.
void displayAll(struct Trip* trips, const int tripCount) {
    setlocale(LC_ALL, "RU.UTF-8"); // Поддержка кириллицы

    // Шапка таблицы
    cout << "╔═══════════╦══════════════╦══════════════╦═════════════════╦════\
══════════╗\n";
    cout << "║" << setw(10) << "Номер рейса" << "║ " << setw(15)
        << "Тип автобуса" << " ║" << setw(10) << "Место прибытия" << "║"
        << setw(10) << "Время отправления" << "║" << setw(10)
        << "Время прибытия" << "║\n";
    cout << "╠═══════════╬══════════════╬══════════════╬═════════════════╬════\
══════════╣\n";

    // Данные рейсов
    for (int i = 0; i < tripCount; i++) {
        struct tm tmDep, tmArr; // Структуры для времени

        localtime_s(&tmDep, &trips[i].departureTime); // Преобразование времени
        localtime_s(&tmArr, &trips[i].arrivalTime);

        wstring busType = cstrToWstring(trips[i].busType); // Поддержка кириллицы
        wstring destination = cstrToWstring(trips[i].destinationPunct);

        wcout << L"║ " << setw(9) << trips[i].tripNum << L" ║ " << setw(12)
            << busType << L" ║ " << setw(12)
            << destination << L" ║ " << setw(13) << put_time(&tmDep, L"%H:%M")
            << L" ║ " << setw(10) << put_time(&tmArr, L"%H:%M") << L"║\n";
    }

    // Нижняя граница таблицы
    cout << "╚═══════════╩══════════════╩══════════════╩═════════════════╩════\
══════════╝\n";
}