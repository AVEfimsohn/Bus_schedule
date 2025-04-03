#include "edit.h"

// Функция для редактирования рейса.
void editTrip(struct Trip* trips, int tripCount) {
    cout << "На текущий момент вы редактируете рейс\n";
    displayAll(trips, tripCount); // Показать все рейсы

    int num; // Номер рейса для редактирования
    bool isCorrect = true; // Флаг корректности ввода

    do {
        isCorrect = true;

        cout << promptEnterTripNumberToEdit; // Запрос номера рейса
        inputIntValue(num, "Введите число!\n"); // Ввод номера

        // Проверка существования рейса
        for (int i = 0; i < tripCount; i++) {
            if (trips[i].tripNum == num) 
                break;
            if (i == tripCount - 1) {
                cout << "Автобуса с таким номером нет!\n";
                isCorrect = false;
            }
        }
    } while (!isCorrect);

    // Редактирование рейса
    for (int i = 0; i < tripCount; i++) {
        if (trips[i].tripNum == num) {
            cout << newTripTypeLabel;
            cin >> trips[i].busType; // Новый тип автобуса

            cout << newTripDestinationLabel;
            cin >> trips[i].destinationPunct; // Новый пункт назначения

            char timeStr[MAX_STRING_LENGTH];

            inputTime(timeStr); // Ввод времени отправления
            trips[i].departureTime = toTimeT(timeStr);

            inputTime(timeStr); // Ввод времени прибытия
            trips[i].arrivalTime = toTimeT(timeStr);

            cout << tripEditedMessage; // Сообщение об успешном редактировании
            return;
        }
    }
    cout << tripNotFoundMessage; // Сообщение об ошибке
}