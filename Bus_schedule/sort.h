#pragma once
#include "overall.h"

// Константы текстовых сообщений:
// Таблица сортировки
static const string sortTable = "\
╔══════════════════════════════════════════════════════╗\n\
║По каким характеристикам следует отсортировать рейсы? ║\n\
╠══════════════════════════════════════════════════════╣\n\
║1.По номеру рейса                                     ║\n\
║2.По типу назначения                                  ║\n\
║3.По месту прибытия                                   ║\n\
║4.По времени отправления                              ║\n\
║5.По времени прибытия                                 ║\n\
║6. Выход на главное меню                              ║\n\
╚══════════════════════════════════════════════════════╝\n\
";
static const string thereIsNoSuchAMessage
    = "Такого выбора нет! \nПовторите попытку!\n";

static const string SORT_MENU = "Вы находитесь в меню сортировки\n";

// Прототипы функций:
void sortTrips(struct Trip* trips, int tripCount); // Отсортировать рейсы
void displayAll(struct Trip* trips, const int tripCount); // Отображение всех рейсов
inline bool compareTripsByTripNumber(const struct Trip& a, const struct Trip& b); // Сравнить рейсы по номеру рейса
inline bool compareTripsByBusType(const struct Trip& a, const struct Trip& b); // Сравнить рейсы по типу автобуса
inline bool compareTripsByCityName(const struct Trip& a, const struct Trip& b); // Сравнить рейсы по пункту назначения
inline bool compareTripsByDepartureTime(const struct Trip& a, const struct Trip& b); // Сравнить рейсы повремени отправления
inline bool compareTripsByArrivalTime(const struct Trip& a, const struct Trip& b); // Сравнить рейсы по времени прибытия
void sort(Trip* first, Trip* last, bool (*comparator)(const struct Trip&, const struct Trip&)); // Сортировка