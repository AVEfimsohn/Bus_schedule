#include "search.h"

// Функция поиска рейсов по номеру
void searchTripByTripNum(struct Trip* trips, int tripCount) {
    int num;

    setlocale(LC_ALL, "RU.UTF-8");  // Установка русской локали для корректного вывода

    cout << promptEnterNumforSearch;
    inputIntValue(num, enterNum); 

    cout << "╔═══════════╦══════════════╦══════════════╦═════════════════╦════\
══════════╗\n";

    // Поиск по всем рейсам в массиве
    for (int i = 0; i < tripCount; i++) {
        const struct Trip& trip = trips[i];
        if (trips[i].tripNum == num) {  
            struct tm tmDeparture, tmArrival; 

            // Конвертация строк char* в wstring для корректного вывода русских символов
            wstring busType = cstrToWstring(trips[i].busType);
            wstring destination = cstrToWstring(trips[i].destinationPunct);

            // Преобразование времени из time_t в структуру tm
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

    cout << promptUserToEnterSmth; 

    getch();  
    system("cls");
}

// Функция поиска рейсов по типу автобуса
void searchTripByBusType(struct Trip* trips, int tripCount) {
    char type[MAX_STRING_LENGTH];

    setlocale(LC_ALL, "RU.UTF-8");  // Установка локали

    cout << promptEnterBusTypeForSearch; 
    cin >> type; 

    cout << "╔═══════════╦══════════════╦══════════════╦═════════════════╦════\
══════════╗\n";

    // Поиск по массиву рейсов
    for (int i = 0; i < tripCount; i++) {
        const struct Trip& trip = trips[i]; 

        // Сравнение типа автобуса (без учета регистра)
        if (strcmp(trips[i].busType, type) == 0) {
            struct tm tmDeparture, tmArrival;

            // Конвертация в широкие строки
            wstring busType = cstrToWstring(trips[i].busType);
            wstring destination = cstrToWstring(trips[i].destinationPunct);

            // Преобразование времени
            localtime_s(&tmDeparture, &trip.departureTime);
            localtime_s(&tmArrival, &trip.arrivalTime);

            // Вывод информации о рейсе
            wcout << L"║ " << setw(9) << trips[i].tripNum << L" ║ " << setw(12)
                << busType << L" ║ " << setw(12) << destination << L" ║ "
                << setw(13) << put_time(&tmDeparture, L"%H:%M") << L" ║ "
                << setw(10) << put_time(&tmArrival, L"%H:%M") << L"║\n";
        }
    }

    cout << "╚═══════════╩══════════════╩══════════════╩═════════════════╩════\
══════════╝\n";

    cout << promptUserToEnterSmth;
    getch();  
    system("cls");
}

// Функция поиска рейсов по пункту назначения
void searchTripByDestinationPunct(struct Trip* trips, int tripCount) {
    char dest[MAX_STRING_LENGTH];

    setlocale(LC_ALL, "RU.UTF-8");  // Установка локали

    cout << promptEnterDestinationForSearch; 
    cin >> dest;  

    cout << "╔═══════════╦══════════════╦══════════════╦═════════════════╦════\
══════════╗\n";

    // Поиск по массиву
    for (int i = 0; i < tripCount; i++) {
        const struct Trip& trip = trips[i];

        // Сравнение пункта назначения
        if (strcmp(trips[i].destinationPunct, dest) == 0) {
            struct tm tmDeparture, tmArrival;

            // Конвертация в широкие строки
            wstring busType = cstrToWstring(trips[i].busType);
            wstring destination = cstrToWstring(trips[i].destinationPunct);

            // Преобразование времени
            localtime_s(&tmDeparture, &trip.departureTime);
            localtime_s(&tmArrival, &trip.arrivalTime);

            // Вывод информации
            wcout << L"║ " << setw(9) << trips[i].tripNum << L" ║ " << setw(12)
                << busType << L" ║ " << setw(12) << destination << L" ║ "
                << setw(13) << put_time(&tmDeparture, L"%H:%M") << L" ║ "
                << setw(10) << put_time(&tmArrival, L"%H:%M") << L"║\n";
        }
    }
    
    cout << "╚═══════════╩══════════════╩══════════════╩═════════════════╩════\
══════════╝\n";

    cout << promptUserToEnterSmth;
    getch();  
    system("cls");  
}

// Функция поиска рейсов по времени отправления
void searchTripByDepartureTime(struct Trip* trips, int tripCount) {
    char time_s[MAX_STRING_LENGTH];

    setlocale(LC_ALL, "RU.UTF-8");  // Установка локали

    inputTime(time_s);
    time_t time = toTimeT(time_s); 

    cout << "╔═══════════╦══════════════╦══════════════╦═════════════════╦════\
══════════╗\n";

    // Поиск по массиву
    for (int i = 0; i < tripCount; i++) {
        const struct Trip& trip = trips[i];

        // Сравнение времени отправления
        if (trips[i].departureTime == time) {
            struct tm tmDeparture, tmArrival;

            // Конвертация в широкие строки
            wstring busType = cstrToWstring(trips[i].busType);
            wstring destination = cstrToWstring(trips[i].destinationPunct);

            // Преобразование времени
            localtime_s(&tmDeparture, &trip.departureTime);
            localtime_s(&tmArrival, &trip.arrivalTime);

            // Вывод информации
            wcout << L"║ " << setw(9) << trips[i].tripNum << L" ║ " << setw(12)
                << busType << L" ║ " << setw(12) << destination << L" ║ "
                << setw(13) << put_time(&tmDeparture, L"%H:%M") << L" ║ "
                << setw(10) << put_time(&tmArrival, L"%H:%M") << L"║\n";
        }
    }

    cout << "╚═══════════╩══════════════╩══════════════╩═════════════════╩════\
══════════╝\n";

    cout << promptUserToEnterSmth;
    getch();  
    system("cls"); 
}

// Функция поиска рейсов по времени прибытия
void searchTripByArrivalTime(struct Trip* trips, int tripCount) {
    char time_s[MAX_STRING_LENGTH];

    setlocale(LC_ALL, "RU.UTF-8");  // Установка локали

    inputTime(time_s); 
    time_t time = toTimeT(time_s); 

    cout << "╔═══════════╦══════════════╦══════════════╦═════════════════╦════\
══════════╗\n";

    // Поиск по массиву
    for (int i = 0; i < tripCount; i++) {
        const struct Trip& trip = trips[i];

        // Сравнение времени прибытия
        if (trips[i].arrivalTime == time) {
            struct tm tmDeparture, tmArrival;

            // Конвертация в широкие строки
            wstring busType = cstrToWstring(trips[i].busType);
            wstring destination = cstrToWstring(trips[i].destinationPunct);

            // Преобразование времени
            localtime_s(&tmDeparture, &trip.departureTime);
            localtime_s(&tmArrival, &trip.arrivalTime);

            // Вывод информации
            wcout << L"║ " << setw(9) << trips[i].tripNum << L" ║ " << setw(12)
                << busType << L" ║ " << setw(12) << destination << L" ║ "
                << setw(13) << put_time(&tmDeparture, L"%H:%M") << L" ║ "
                << setw(10) << put_time(&tmArrival, L"%H:%M") << L"║\n";
        }
    }

    cout << "╚═══════════╩══════════════╩══════════════╩═════════════════╩════\
══════════╝\n";

    cout << promptUserToEnterSmth; 
    getch();  
    system("cls");  
}

// Функция поиска с меню выбора
void searchTrip(struct Trip* trips, int tripCount) {
    int choice;  

    do {
        system("cls"); 
        cout << SEARCH_MENU;
        cout << searchTable;  
        inputChoice(choice, enterNum);  

        // Обработка выбора пользователя
        switch (choice) {
        case '1': 
            searchTripByTripNum(trips, tripCount);
            break;

        case '2': 
            searchTripByBusType(trips, tripCount);
            break;

        case '3':  
            searchTripByDestinationPunct(trips, tripCount);
            break;

        case '4':  
            searchTripByDepartureTime(trips, tripCount);
            break;

        case '5':  
            searchTripByArrivalTime(trips, tripCount);
            break;

        case '6':  
            break;

        default:  
            cout << invalidChoiceMessage; 
            break;

        }
    } while (choice != '6');
}