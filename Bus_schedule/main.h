#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include "conio.h"
#include "overall.h"

using namespace std;

// Константы текстовых сообщений:
static const string fileName = "trips.txt";
// Таблица главного меню
static const string menuOptions = "\
╔═══════════════════════════════════════════════╗\n\
║ Что бы вы хотели?                             ║\n\
╠═══════════════════════════════════════════════╣\n\
║1. Просмотр всех рейсов                        ║\n\
║2. Добавить рейс                               ║\n\
║3. Удалить рейс                                ║\n\
║4. Редактировать рейс                          ║\n\
║5. Режим обработки                             ║\n\
║6. Выход                                       ║\n\
╚═══════════════════════════════════════════════╝\n\
";
static const string dataSavedExitMessage = "\nДанные сохранены. Выход.\n";

// Прототипы функций:
void inputDataFromFile(struct Trip* trips, int& tripCount); // Ввод данных из файла
void inputChoice(int& choice, const string& errorMessage); // Ввести выбор
void wait(); // Подождать
void addTrip(struct Trip* trips, int& tripCount);  // Добавление рейса
void displayAll(struct Trip* trips, const int tripCount);  // Отображение всех рейсов
void deleteTrip(struct Trip* trips, int& tripCount); // Удаление рейса
void editTrip(struct Trip* trips, int tripCount); // Редактирование рейса
void searchTrip(struct Trip* trips, int tripCount); // Поиск рейса
void sortTrips(struct Trip* trips, int tripCount); // Отсортировать рейсы
// Вывод информации о всех рейсах, со временем не позднее чем за 12 часов
void outputBusesBefore12(struct Trip* trips, const int& tripCount, const char* inputTime);
void showProcessingTable(struct Trip* trips, const int& tripCount, char* time);
void saveToFile(struct Trip* trips, int tripCount); // Сохранить в файл
