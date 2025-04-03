#include "main.h"

using namespace std;

// Функция для загрузки данных о рейсах из файла.
void inputDataFromFile(struct Trip* trips, int& tripCount) {
    ifstream file(fileName); 
    char line[MAX_STRING_LENGTH]; 

    while (file.getline(line, sizeof(line))) {
        struct Trip trip; 
        char depTime[MAX_STRING_LENGTH], arrTime[MAX_STRING_LENGTH];

        // Парсинг строки и заполнение структуры Trip
        sscanf(line, "%d %s %s %s %s", &trip.tripNum, &trip.busType,
            &trip.destinationPunct, &depTime, &arrTime);
        trip.departureTime = toTimeT(depTime); // Преобразование времени в time_t
        trip.arrivalTime = toTimeT(arrTime);
        trips[tripCount++] = trip; // Добавление рейса в массив
    }
    file.close(); // Закрытие файла
}

// Функция для сохранения данных о рейсах в файл.
void saveToFile(struct Trip* trips, int tripCount) {
    ofstream file(fileName); // Открытие файла для записи

    for (int i = 0; i < tripCount; i++) {
        struct tm tmDep, tmArr;

        localtime_s(&tmDep, &trips[i].departureTime); // Преобразование time_t в tm
        localtime_s(&tmArr, &trips[i].arrivalTime);

        // Запись данных в файл в формате: номер тип пункт время_отправления время_прибытия
        file << trips[i].tripNum << " " << trips[i].busType
            << " " << trips[i].destinationPunct << " "
            << put_time(&tmDep, "%H:%M") << " "
            << put_time(&tmArr, "%H:%M") << endl;
    }
    file.close();
}

int main() {
    struct Trip trips[MAX_NUMBER_OF_TRIPS];
    int tripCount = 0; 
    string time; 
    int choice = 0; 
    bool error = false;

    inputDataFromFile(trips, tripCount);

    while (choice != '6') {
        cout << "Вы находитесь в главном меню приложения\"Расписание движения автобусов\"\n";
        cout << menuOptions; 

        if (error) {
            cout << invalidChoiceMessage;
            error = false;
        }

        cout << CHOICE;
        inputChoice(choice, invalidChoiceMessage);

        switch (choice) {
        case '1':
            system("cls");
            displayAll(trips, tripCount); 
            wait();
            break;

        case '2':
            system("cls");
            addTrip(trips, tripCount); 
            system("cls");
            break;

        case '3':
            system("cls");
            deleteTrip(trips, tripCount);
            system("cls");
            break;

        case '4':
            system("cls");
            editTrip(trips, tripCount);
            system("cls");
            break;
        case '5':
            showProcessingTable(trips, tripCount, &time[0]);
            break;

        case '6':
            saveToFile(trips, tripCount);
            cout << dataSavedExitMessage;

            break;
        default:
            system("cls");
            error = true;
            
            break;
        }
    };
    return 0;
}