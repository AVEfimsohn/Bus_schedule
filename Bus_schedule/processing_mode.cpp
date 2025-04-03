
#include "processing_mode.h"
void showProcessingTable(struct Trip* trips, const int& tripCount, char* time) {
    int choice = 0;
    bool error = false;

    system("cls");
    while (choice != '4') {
        cout << YOU_IN_PROCESSING_MODE;
        cout << PROCESSING_MODE_TABLE;

        if (error) {
            cout << invalidChoiceMessage;
            error = false;
        }
        inputChoice(choice, invalidChoiceMessage);
        switch (choice) {
        case '1':
            searchTrip(trips, tripCount);
            system("cls");
            break;

        case '2':
            sortTrips(trips, tripCount);
            system("cls");
            break;

        case '3':
            system("cls");
            cout << OUTPUT_BUSES_BEFORE_12_INTRODUCTION;
            inputTime(&time[0]);
            outputBusesBefore12(trips, tripCount, &time[0]);
            wait();
            system("cls");
            break;

        case '4':
            system("cls");
            break;

        default:
            system("cls");
            error = true;

        }
    }


}