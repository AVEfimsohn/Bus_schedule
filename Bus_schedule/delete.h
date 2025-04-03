#pragma once
#include "overall.h"

// Константы текстовых сообщений:
static const string tripNotFoundMessage = "Рейс не найден.\n"; 
static const string tripDeletedMessage = "Рейс удален.\n";
static const string busDoesnotExist = "Автобуса с таким номером нет!\n";
static const string promptEnterTripNumberToDelete = "Введите номер рейса для удаления: ";
static const string DELETE_INTRODUCTION = "На текущий момент вы удаляете рейс\n";

// Прототипы функций:
void deleteTrip(struct Trip* trips, int& tripCount);        // Удаление рейса
void displayAll(struct Trip* trips, const int tripCount);   // Отображение всех рейсов