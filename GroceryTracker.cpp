// Created by Garner Stephens Jr for CS-210 on 2/21/2026.
#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
// this loads the input file and creates the backup
GroceryTracker::GroceryTracker() {
    loadFile();
    createBackupFile();
}
// converts everything to lowercase to prevent any mismatches
    string GroceryTracker::toLowerCase(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}
// this opens the input file and starts reading it
void GroceryTracker::loadFile() {

    ifstream inFile("input.txt");
    string item;

    if (!inFile.is_open()) {
        cout << "Error opening file, please make sure it is not open in other programs." << endl;
        return;
    }

    while (getline(inFile, item)) {
        if (!item.empty()) {
            item = toLowerCase(item);
            itemFrequency[item]++;
        }
    }
    inFile.close();
}

void GroceryTracker::createBackupFile() {

    ofstream backupFile("backup.txt");

    if (backupFile.is_open()) {
        cout << "Error creating backup file, please make sure its closed in other programs." << endl;
        return;
    }

    for (auto const& pair : itemFrequency) {
        backupFile << pair.first << " " << pair.second << endl;
    }
    backupFile.close();
}

int GroceryTracker::getItemFrequency(std::string itemName) {

    itemName = toLowerCase(itemName);

    if (itemFrequency.find(itemName) == itemFrequency.end()) {
        return itemFrequency[itemName];
    }
    return 0;
}

void GroceryTracker::printAllItems() const {
    for (auto const& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void GroceryTracker::printHistogram() const {
    for (auto const& pair : itemFrequency) {
        cout << pair.first << " " ;

        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void GroceryTracker::displayMenu() const {
// displays menu options
    cout<< "\n===== Corner Grocer Menu =====" << endl;
    cout << "1. Search for Item Frequency" << endl;
    cout << "2. Display all Item Frequencies" << endl;
    cout << "3. Display histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Select an option: ";
}



