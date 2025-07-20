#include "treap.h"
#include "interval_tree.h"
#include <iostream>
#include <vector>
#include <string>

struct Employee{
    string name;
    int totalHoursWorked;
};

void insertion(std::vector<Employee>& input){
    int size = input.size();
    for (int i = 1; i < size; i++){
        Employee key = input[i];
        int j = i - 1;
        while (j >= 0 && input[j].totalHoursWorked > key.totalHoursWorked){
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = key;
    }
}

void bucketSort(std::vector<Employee>& input, int maxVal, int minValue){
    int size = input.size();
    std::vector<std::vector<Employee> > buckets(size);

    for (int i = 0; i < size; i++){
        int bucketI = (input[i].totalHoursWorked - minValue) * size / (maxVal - minValue + 1);
        buckets[bucketI].push_back(input[i]);
    }
    for (int i = 0; i < size; i++){
        insertion(buckets[i]);
    }
    int index = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < buckets[i].size(); j++){
            input[index++] = buckets[i][j];
        }
    }
}

int main() {
    std::cout << "POS System Initializing..." << std::endl;

    IntTree* timeClock = new IntTree();
    Treap* itemCounts = new Treap();

    int maxValue = -1;
    int minValue = 1000000;

    std::vector<Employee> shiftLens;

    string pass = "1";

    while(pass != "0") {
        std::cout << "Please enter your password, or type 0 to quit program: " << std::endl;
        std::cin >> pass;

        bool breakKey = false;

        while (!breakKey) {
            if (pass == "employee") {

                string numEm;

                std::cout << "Please choose a function by typing the corresponding number:" << std::endl;
                std::cout << "1: Record a Shift" << std::endl;
                std::cout << "2: Record Stock Numbers" << std::endl;
                std::cout << "3: End Session" << std::endl;

                std::cin >> numEm;

                if (numEm == "1") {
                    string beginStr;
                    string endStr;
                    Employee newEmployee;
                    int begin;
                    int end;

                    std::cout << "Please enter your name:" << std::endl;
                    std::cin >> newEmployee.name;

                    std::cout << "Please enter the length of your shift (in minutes):" << std::endl;
                    std::cin >> newEmployee.totalHoursWorked;

                    if(newEmployee.totalHoursWorked > maxValue){
                        maxValue = newEmployee.totalHoursWorked;
                    }
                    if(newEmployee.totalHoursWorked < minValue){
                        minValue = newEmployee.totalHoursWorked;
                    }

                    shiftLens.push_back(newEmployee);

                    bucketSort(shiftLens, maxValue, minValue);

                    std::cout << "Please enter the start time of your shift.  Format should be military time with no "
                                 "colon.  " << std::endl;
                    std::cout << "Example: 2:43 pm should be entered as 1443." << std::endl;

                    std::cin >> beginStr;
                    begin = std::stoi(beginStr);

                    std::cout << "Enter the end time in the same format." << std::endl;

                    std::cin >> endStr;
                    end = std::stoi(endStr);

                    timeClock->insert(std::make_pair(begin, end));
                }
                else if (numEm == "2") {
                    string item;
                    int count;
                    std::cout << "Please enter the name of the item you would like to record: " << std::endl;
                    cin >> item;

                    std::cout << "Please enter the current quantity of the item: " << std::endl;
                    cin >> count;

                    itemCounts->insert(item, count);
                }
                else if (numEm == "3") {
                    std::cout << "Have a Nice Day!" << std::endl;
                    breakKey = true;
                }
                else {
                    std::cout << "You have entered an invalid choice" << std::endl;
                    breakKey = true;
                }
            }
            else if (pass == "manager") {

                string numMan;

                std::cout << "Please choose a function by typing the corresponding number:" << std::endl;
                std::cout << "1: Overlapping Shift Search" << std::endl;
                std::cout << "2: Check Stock Numbers" << std::endl;
                std::cout << "3: Find Longest Working Employee" << std::endl;
                std::cout << "4: Quit Program" << std::endl;

                std::cin >> numMan;

                if (numMan == "1") {
                    vector<pair<int, int> > intervalList;
                    int data;

                    std::cout << "Please enter the hour you would like to see shift overlaps for as a whole number:"
                    << std::endl;
                    std::cin >> data;

                    timeClock->overlap(data, intervalList);

                    if(!intervalList.empty()){
                        std::cout << "The shifts that overlap with the given time are:" << std::endl;

                        for(int i = 0; i < intervalList.size(); ++i){
                            std::cout << intervalList[i].first << " to " << intervalList[i].second << std::endl;
                        }
                    }
                    else{
                        std::cout << "There are no overlapping shifts stored" << std::endl;
                    }

                }
                else if (numMan == "2") {
                    if(!itemCounts->root){
                        std::cout << "There are currently no items stored." << std::endl;
                    }
                    else{
                        std::cout << "The item with the highest stock is " << itemCounts->root->key
                        << " with a stock number of " << itemCounts->root->priority << "." << std::endl;
                    }
                }
                else if (numMan == "3") {
                    if(!shiftLens.empty()){
                        std::cout << "The longest working employee is " << shiftLens[shiftLens.size()-1].name << " with "
                                  << shiftLens[shiftLens.size()-1].totalHoursWorked << " minutes worked." << std::endl;
                    }
                    else{
                        std::cout << "No employees have logged their shifts yet." << std::endl;
                    }
                }
                else if (numMan == "4") {
                    std::cout << "Have a Nice Day!" << std::endl;
                    breakKey = true;
                }
                else {
                    std::cout << "You have entered an invalid choice" << std::endl;
                    breakKey = true;
                }

            } 
            else if(pass == "0"){
                std::cout << "Terminating session... Have a nice day!" << std::endl;
                breakKey = true;
            }
            else{
                std::cout << "You have entered an incorrect password" << std::endl;
                breakKey = true;
            }
        }
    }
    std::cout << "Program has been terminated..." << std::endl;
    return 0;
}
