#include "sort.h"

// Функция сравнения для сортировки по номеру рейса
inline bool compareTripsByTripNumber(const struct Trip& a, const struct Trip& b) {
    return a.tripNum < b.tripNum;
}

// Функция сравнения для сортировки по типу автобуса
inline bool compareTripsByBusType(const struct Trip& a, const struct Trip& b) {
    return a.busType < b.busType;
}

// Функция сравнения для сортировки по названию города назначения
inline bool compareTripsByCityName(const struct Trip& a, const struct Trip& b) {
    return a.destinationPunct < b.destinationPunct;
}

// Функция сравнения для сортировки по времени отправления
inline bool compareTripsByDepartureTime(const struct Trip& a, const struct Trip& b) {
    return a.departureTime < b.departureTime;
}

// Функция сравнения для сортировки по времени прибытия
inline bool compareTripsByArrivalTime(const struct Trip& a, const struct Trip& b) {
    return a.arrivalTime < b.arrivalTime;
}

// Основная функция сортировки (реализация алгоритма пузырьковой сортировки)
void sort(Trip* first, Trip* last, bool (*comparator)(const struct Trip&, const struct Trip&)) {
    int n = last - first;  
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (!comparator(first[j], first[j + 1])) {
                Trip temp = first[j];
                first[j] = first[j + 1];
                first[j + 1] = temp;
            }
        }
    }
}

// Функция интерфейса для сортировки рейсов
void sortTrips(struct Trip* trips, int tripCount) {
    int choice; 

    do {
        system("cls");  
        cout << SORT_MENU;
        cout << sortTable;  

        inputChoice(choice, enterNum);

        switch (choice) {
        case '1':
            sort(trips, trips + tripCount, compareTripsByTripNumber);
            break;

        case '2':
            sort(trips, trips + tripCount, compareTripsByBusType);
            break;

        case '3':  
            sort(trips, trips + tripCount, compareTripsByCityName);
            break;

        case '4': 
            sort(trips, trips + tripCount, compareTripsByDepartureTime);
            break;

        case '5': 
            sort(trips, trips + tripCount, compareTripsByArrivalTime);
            break;

        case '6':
            break;

        default:
            cout << invalidChoiceMessage;
            break;

        }
    } while (choice != '6');
}