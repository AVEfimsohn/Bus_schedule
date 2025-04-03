#include "add.h"

// Функция для ввода номера рейса с проверкой уникальности.
void inputTripNumber(struct Trip* trips, int tripCount, struct Trip& newTrip) {
    bool isCorrect = true;

    do {
        isCorrect = true;

        inputIntValue(newTrip.tripNum, enterNum); // Ввод номера

        // Проверка на уникальность номера
        for (int i = 0; i < tripCount; i++)
            if (trips[i].tripNum == newTrip.tripNum) {
                cout << busNumExists; // Сообщение об ошибке
                isCorrect = false;
                break;
            }
    } while (!isCorrect);
}

// Функция для ввода строкового значения с проверкой длины.
void inputStrValue(char* value, const string& errorMessage) {
    bool isCorrect = false;

    while (!isCorrect) {
        cin >> value; // Ввод строки

        if (strSize(value) > 12) // Проверка длины
            cout << errorMessage;
        else
            isCorrect = true;
    }
}

// Функция для подсчета длины строки с учетом кириллицы.
int strSize(const char* value) {
    const int CYRILLIC_BYTE = 0xffffffd0; // Маркер кириллицы
    int size = 0;

    for (int i = 0; value[i] != '\0'; i++) {
        size += sizeof(value[i]); // Подсчет байтов
    }

    // Корректировка длины для кириллицы
    if (value[0] == CYRILLIC_BYTE)
        return size / sizeof(value[0]) / 2;
    else
        return size / sizeof(value[0]);
}

// Функция для добавления нового рейса.
void addTrip(struct Trip* trips, int& tripCount) {
    cout << ADD_INTRODUCTION ;

    displayAll(trips, tripCount); // Показать все рейсы

    if (tripCount >= MAX_NUMBER_OF_TRIPS) { // Проверка лимита
        cout << maxTripsReached;
        return;
    }

    struct Trip newTrip; // Новый рейс

    cout << promptEnterTripNumber;
    inputTripNumber(trips, tripCount, newTrip); // Ввод номера

    cout << promptEnterBusType;
    inputStrValue(newTrip.busType, busTypeIncorrect); // Ввод типа автобуса

    cout << promptEnterDestination;
    inputStrValue(newTrip.destinationPunct, arrivalPlaceIncorrect); // Ввод пункта назначения

    char timeStr[MAX_STRING_LENGTH];
    inputTime(timeStr); // Ввод времени отправления
    newTrip.departureTime = toTimeT(timeStr);

    inputTime(timeStr); // Ввод времени прибытия
    newTrip.arrivalTime = toTimeT(timeStr);

    trips[tripCount++] = newTrip; // Добавление рейса в массив
}