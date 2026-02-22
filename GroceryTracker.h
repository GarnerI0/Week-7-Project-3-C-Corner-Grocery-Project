// Created by Garner Stephens Jr for CS-210 on 2/21/2026.
#ifndef WEEK7PROJECT3_GROCERYTRACKER_H
#define WEEK7PROJECT3_GROCERYTRACKER_H

#include <string>
#include <map>

// this class was made to handle the reading, storing, and display of Corner's Data
class GroceryTracker {

private:
    std::map<std::string, int> itemFrequency;

    void loadFile();
    //creates a backup file in case of any errors or mistakes.
    void createBackupFile();
    //converts everything to lowercase to allow both capital and lowercase to be found
    std::string toLowerCase(std::string word);

public:
    GroceryTracker();

    int getItemFrequency(std::string itemName);
    // prints all items and displays historical item freqenucies
    void printAllItems() const;
    void printHistogram() const;
    //displays user menu
    void displayMenu() const;
};
#endif //WEEK7PROJECT3_GROCERYTRACKER_H