#pragma once
#include "overall.h"

// Константы текстовых сообщений:
static const string promptEnterNumforSearch = "Введите номер поездки для поиска: ";
static const string promptEnterDestinationForSearch = "Введите пункт назначения для поиска: ";
static const string promptEnterBusTypeForSearch = "Введите тип автобуса для поиска!\n";
static const string searchTable = "\
╔═══════════════════════════════════════════════╗\n\
║По каким характеристикам следует искать рейсы? ║\n\
╠═══════════════════════════════════════════════╣\n\
║1. По номеру рейса                             ║\n\
║2. По типу назначения                          ║\n\
║3. По месту прибытия                           ║\n\
║4. По времени отправления                      ║\n\
║5. По времени прибытия                         ║\n\
║6. Выход на главное меню                       ║\n\
╚═══════════════════════════════════════════════╝\n\
";
static const string SEARCH_MENU = "Вы находитесь в меню поиска\n";

// Прототипы функций:
void searchTrip(struct Trip* trips, int& tripCount); // Поиск рейса
void searchTripByTripNum(struct Trip* trips, int tripCount); // Поиск рейса по номеру рейса
void searchTripByBusType(struct Trip* trips, int tripCount); // Поиск рейса по типу автобуса
void searchTripByDestinationPunct(struct Trip* trips, int tripCount); // Поиск рейса по пункту назначения
void searchTripByDepartureTime(struct Trip* trips, int tripCount); // Поиск рейса по времени отправления
void searchTripByArrivalTime(struct Trip* trips, int tripCount); // Поиск рейса по времени прибытия
void displayAll(struct Trip* trips, const int tripCount); // Отображение всех рейсов