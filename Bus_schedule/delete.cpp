#include "delete.h"

// Функция для удаления рейса.
void deleteTrip(struct Trip* trips, int& tripCount) {
    cout << "На текущий момент вы удаляете рейс\n";
    displayAll(trips, tripCount); // Показать все рейсы

    int num; // Номер рейса для удаления
    bool isCorrect = true; // Флаг корректности ввода

    do {
        isCorrect = true;

        cout << promptEnterTripNumberToDelete; // Запрос номера
        inputIntValue(num, enterNum); // Ввод номера

        // Проверка существования рейса
        for (int i = 0; i < tripCount; i++) {
            if (trips[i].tripNum == num) break;
            if (i == tripCount - 1) {
                cout << busDoesnotExist; // Сообщение об ошибке
                isCorrect = false;
            }
        }
    } while (!isCorrect);

    // Удаление рейса
    for (int i = 0; i < tripCount; i++) {
        if (trips[i].tripNum == num) {
            // Сдвиг элементов массива
            for (int j = i; j < tripCount - 1; j++) {
                trips[j] = trips[j + 1];
            }
            tripCount--; // Уменьшение счетчика
            cout << tripDeletedMessage; // Сообщение об успехе
            return;
        }
    }
    cout << tripNotFoundMessage; // Сообщение об ошибке
}