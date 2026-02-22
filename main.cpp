#include <iostream>
#include "GroceryTracker.h"

using namespace std;

int main() {

    GroceryTracker tracker;

    int choice = 0;
    string itemSearch;

    while (true) {

        tracker.displayMenu();
// keeps program running while user is using
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please enter a variable between 1-4." << endl;
            continue;
        }
        switch (choice) {

            case 1:
                cout << "Enter item name: ";
                cin >> itemSearch;
//displays how many times an item was purchased
                cout << itemSearch << " was purchased "
                     << tracker.getItemFrequency(itemSearch) << " times." << endl;
                break;

                case 2:
                tracker.printAllItems();
                break;

                case 3:
                tracker.printHistogram();
                break;
// program exit message.
                case 4:
                cout << "Thank you for using the Grocery Tracker by Garner Stephens Jr Made on 02/21/2026 for CS 210";
                return 0;
// if the user inputs an invlaid option this is dispalyed,
            default:
                cout << "Invalid option, please select another." << endl;
        }
    }
    return 0;
}