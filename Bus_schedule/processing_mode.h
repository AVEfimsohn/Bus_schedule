#pragma once
#include "overall.h"

static const string YOU_IN_PROCESSING_MODE = "Вы находитесь в режиме обработки\n";
static const string PROCESSING_MODE_TABLE = "\
╔═══════════════════════════════════════════════╗\n\
║ Что бы вы хотели?                             ║\n\
╠═══════════════════════════════════════════════╣\n\
║1. Поиск рейса по заданному значению           ║\n\
║2. Сортировка рейсов по заданному значению     ║\n\
║3. Рейсы за 12 часов до времени                ║\n\
║4. Выход                                       ║\n\
╚═══════════════════════════════════════════════╝\n\
";
static const string OUTPUT_BUSES_BEFORE_12_INTRODUCTION
    = "Вывод информации о всех рейсах, которыми можно воспользоваться для приб\
ытия в пункт назначения не позднее чем за 12 часов до времени, задаваемого пол\
ьзователем\n";


void showProcessingTable(struct Trip* trips, const int& tripCount, char* time);
void inputChoice(int& choice, const string& errorMessage); // Ввести выбор
void searchTrip(struct Trip* trips, int tripCount); // Поиск рейса
void sortTrips(struct Trip* trips, int tripCount); // Отсортировать рейсы
// Вывод информации о всех рейсах, со временем не позднее чем за 12 часов
void outputBusesBefore12(struct Trip* trips, const int& tripCount, const char* inputTime);