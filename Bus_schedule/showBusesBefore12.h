#pragma once
#include "overall.h"

// Константы текстовых сообщений:
static const string tripsWithin12Hours = "Рейсы, прибывающие не позднее чем за 12 часов до заданного времени:\n";

// Прототипы функций:
// Вывод информации о всех рейсах, со временем не позднее чем за 12 часов
void outputBusesBefore12(struct Trip* trips, const int& tripCount, const char* inputTime);
