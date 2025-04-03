#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include "overall.h"

using namespace std;

// Прототипы функций:
wstring cstrToWstring(const char* str); // Преобразует C-строку в широкую строку для поддержки кириллицы.
void displayAll(struct Trip* trips, const int tripCount); // Отображает всех рейсов.