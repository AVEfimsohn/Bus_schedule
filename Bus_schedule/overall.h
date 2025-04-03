#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include "conio.h"

using namespace std;

// Константы для максимальной длины строки и количества рейсов
const int MAX_STRING_LENGTH = 64;
const int MAX_NUMBER_OF_TRIPS = 100;
const int UNIX_YEAR = 71;
const int UNIX_DAY = 1;
const int UNIX_MONTH = 0;

// Константы текстовых сообщений:
inline const string CHOICE = "Выбор: ";
inline const string enterNum = "Введите число!\n";
inline const string promptEnterTime = "Введите время (в формате HH:MM): ";
inline const string errorMessage = "У вас ошибка!\n";
inline const string invalidTimeMessage = "Время должно быть от 0 до 23 для часов и от 0 до 59 для минут.\n";
inline const string promptUserToEnterSmth = "Введите любую клавишу чтобы продолжить\n";
inline const string invalidChoiceMessage = "Неверный выбор!\nПовторите попытку!\n";
inline const string maxTripsReached = "Достигнут максимум рейсов!\n";

// Структура для хранения данных о рейсе
struct Trip {
    int tripNum = 0;                      // Номер рейса
    char busType[MAX_STRING_LENGTH];      // Тип автобуса
    char destinationPunct[MAX_STRING_LENGTH]; // Пункт назначения
    time_t departureTime = 0;             // Время отправления
    time_t arrivalTime = 0;               // Время прибытия
};

// Прототипы функций:
inline bool isDigit(char& chr); // Проверить на число
inline string stringify(const char& chr); // Превратить С-строку в std-строку
inline int substr(const char* str, const int& begValue, const int& endValue); // Найти подстроку
wstring cstrToWstring(const char* str); //
time_t toTimeT(const char* timeStr); // Превратить С-строку во время
void inputTime(char* time); // Ввести время
void inputIntValue(int& choice, const string& errorMessage); // Ввести целочисленное значение
void inputChoice(int& choice, const string& errorMessage); // Ввести выбор
void wait(); // Подождать