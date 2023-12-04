#include <iostream>
#include <string>
#include <algorithm>
#include "../headers/view.h"
#include "../headers/home.h"
#include "../headers/taskList.h"
#include "../headers/task.h"

using namespace std;

void View::sortTasks(Home target) {
    for (Task* i : target.classificationTaskStorage["Dated"]) {
        sortedTasks.push_back(i);
    }

    for (unsigned int i = 0; i < sortedTasks.size() - 1; ++i) {
        int min = i;
        for (unsigned int j = i + 1; j < sortedTasks.size(); ++j) {
            if (compareTasks(sortedTasks.at(j), sortedTasks.at(min))) {
                min = j;
            }
        }
        swap(sortedTasks.at(i), sortedTasks.at(min));
    }
}

bool View::compareTasks (Task const* task1, Task const* task2) {
    if (task1->getDueYear() < task2->getDueYear()) {
        return true;
    }
    if (task1->getDueYear() > task2->getDueYear()) {
        return false;
    }
    if (task1->getDueMonth() < task2->getDueMonth()) {
        return true;
    }
    if (task1->getDueMonth() > task2->getDueMonth()) {
        return false;
    }

    return task1->getDueDay() < task2->getDueDay();
}


void View::viewPriority(Home target, string userChoice) {
    if (target.isEmpty() != true) {
        sortTasks(target);

        if (userChoice == "Completed") {
            cout << "HIGH PRIORITY - COMPLETED\n" << "---------------------------\n";
            printHighPriority(true, false);

            cout << "MEDIUM PRIORITY - COMPLETED\n" << "---------------------------\n";
            printMedPriority(true, false);

            cout << "LOW PRIORITY - COMPLETED\n" << "---------------------------\n";
            printLowPriority(true, false);
        }
        else if (userChoice == "Uncompleted") {

        }
        else if (userChoice == "All") {

        }
    }
    else {
        cout << "-------------NO TASKS AVAILABLE-------------" << endl;
    }
}

void View::printHighPriority(bool printCompleted, bool printUncompleted) const {
    for (int i = 0; i < sortedTasks.size(); ++i) {
        Task* target = sortedTasks.at(i);
        if (target->getPriority() == "High") {
            if (target->getCompleteStatus() == true && printCompleted == true) {
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << "\u2713" << endl;
            }
            else if (target->getCompleteStatus() == false && printUncompleted == true) {
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << endl;
            }
        }
    } 
    cout << endl;
}

void View::printMedPriority(bool printCompleted, bool printUncompleted) const {
    for (int i = 0; i < sortedTasks.size(); ++i) {
        Task* target = sortedTasks.at(i);
        if (target->getPriority() == "Medium") {
            if (target->getCompleteStatus() == true && printCompleted == true) {
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << "\u2713" << endl;
            }
            else if (target->getCompleteStatus() == false && printUncompleted == true) {
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << endl;
            }
        }
    } 
    cout << endl;
}

void View::printLowPriority(bool printCompleted, bool printUncompleted) const {

}

void View::viewOverall() const {
    
}