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
            cout << "HIGH PRIORITY - UNCOMPLETED\n" << "---------------------------\n";
            printHighPriority(false, true);

            cout << "MEDIUM PRIORITY - UNCOMPLETED\n" << "---------------------------\n";
            printMedPriority(false, true);

            cout << "LOW PRIORITY - UNCOMPLETED\n" << "---------------------------\n";
            printLowPriority(false, true);
        }
        else if (userChoice == "All") {
            cout << "HIGH PRIORITY - ALL\n" << "---------------------------\n";
            printHighPriority(true, true);

            cout << "MEDIUM PRIORITY - ALL\n" << "---------------------------\n";
            printMedPriority(true, true);

            cout << "LOW PRIORITY - ALL\n" << "---------------------------\n";
            printLowPriority(true, true);
        }

        sortedTasks.clear();
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
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << " \u2713" << endl;
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
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << " \u2713" << endl;
            }
            else if (target->getCompleteStatus() == false && printUncompleted == true) {
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << endl;
            }
        }
    } 
    cout << endl;
}

void View::printLowPriority(bool printCompleted, bool printUncompleted) const {
    for (int i = 0; i < sortedTasks.size(); ++i) {
        Task* target = sortedTasks.at(i);
        if (target->getPriority() == "Low") {
            if (target->getCompleteStatus() == true && printCompleted == true) {
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << " \u2713" << endl;
            }
            else if (target->getCompleteStatus() == false && printUncompleted == true) {
                cout << i + 1 << ".) " << target->getName() << " " << target->getFullDueDate() << endl;
            }
        }
    } 
    cout << endl;    
}

void View::viewOverall(Home target) const {
    if (target.isEmpty() != true) {
        cout << "Solo Tasks" << endl;
        target.soloTasks->viewTasks();
        cout << endl << endl;

        for (TaskList* list : target.overallLists) {
            list->viewTasks();
            cout << endl << endl;
        } 
    } else {
        cout << "-------------NO TASKS AVAILABLE-------------" << endl;
    }    
}

void View::viewWeekly(Home target) const {

}