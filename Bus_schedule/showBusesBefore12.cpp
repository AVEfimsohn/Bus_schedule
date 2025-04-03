#include "showBusesBefore12.h"

// Функция вывода автобусов, прибывающих за 12 часов до заданного времени
void outputBusesBefore12(struct Trip* trips, const int& tripCount, const char* inputTime) {
    time_t targetArrivalTime = toTimeT(inputTime);
    time_t thresholdTime = targetArrivalTime - 12 * 3600;

    system("cls"); 

    setlocale(LC_ALL, "RU.UTF-8");  // Установка русской локали

    cout << tripsWithin12Hours;
    cout << "╔═══════════╦══════════════╦══════════════╦═════════════════╦════\
══════════╗\n";

    for (int i = 0; i < tripCount; i++) {
        const struct Trip& trip = trips[i];

        if (trip.arrivalTime <= targetArrivalTime &&
            trip.arrivalTime >= thresholdTime) {
            struct tm tmDeparture, tmArrival; 

            // Конвертация строк в широкие строки (для поддержки Unicode)
            wstring busType = cstrToWstring(trips[i].busType);
            wstring destination = cstrToWstring(trips[i].destinationPunct);

            // Преобразование времени в локальное представление
            localtime_s(&tmDeparture, &trip.departureTime);
            localtime_s(&tmArrival, &trip.arrivalTime);

            // Форматированный вывод информации о рейсе
            wcout << L"║ " << setw(9) << trips[i].tripNum << L" ║ " << setw(12)
                << busType << L" ║ " << setw(12) << destination << L" ║ "
                << setw(13) << put_time(&tmDeparture, L"%H:%M") << L" ║ "
                << setw(10) << put_time(&tmArrival, L"%H:%M") << L"║\n";
        }
    }

    cout << "╚═══════════╩══════════════╩══════════════╩═════════════════╩════\
══════════╝\n";
}