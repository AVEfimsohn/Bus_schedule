#pragma once
#include "overall.h"

using namespace std;

// Константы текстовых сообщений:
static const string busNumExists = "Такой номер автобуса уже существует!\n";
static const string busTypeIncorrect = "Название типа автобуса не должен состоять из более чем 12 символов!\n";
static const string arrivalPlaceIncorrect = "Название пункта прибытия не должно состоять из более чем 12 символов!\n";
static const string promptEnterBusType = "Автобус какого типа вы хотели бы добавить?\n";
static const string promptEnterDestination = "Куда автобус должен прибывать?\n";
static const string promptEnterTripNumber = "Введите номер поездки?\n";
static const string ADD_INTRODUCTION = "На текущий момент вы добавляете новый рейс\n";

// Прототипы функций:
void displayAll(struct Trip* trips, const int tripCount); // Отображение всех рейсов
void addTrip(struct Trip* trips, int& tripCount); // Добавление рейса
void inputTime(char* inputTime); // Ввод времени
void inputStrValue(char* value, const string& errorMessage); // Ввод строкового значения
void inputTripNumber(struct Trip* trips, int tripCount, struct Trip& newTrip); // Ввод номера рейса
int strSize(const char* value); // Узнать размер С-строки