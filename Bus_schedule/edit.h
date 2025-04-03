#pragma once
#include "overall.h"

// Константы текстовых сообщений:
static const string newTripTypeLabel = "Новый тип автобуса: ";
static const string promptEnterTripNumberToEdit = "Введите номер рейса для редактирования: ";
static const string newTripDestinationLabel = "Новый пункт назначения: ";
static const string tripEditedMessage = "Рейс отредактирован.\n";
static const string tripNotFoundMessage = "Рейс не найден.\n";
static const string EDIT_INTRODUCTION = "На текущий момент вы редактируете рейс\n";

// Прототипы функций:
void displayAll(struct Trip* trips, const int tripCount);  // Отображение всех рейсов
void editTrip(struct Trip* trips, int tripCount); // Редактирование рейса