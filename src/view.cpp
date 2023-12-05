#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <sstream>
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
            if (compareTasksDueDate(sortedTasks.at(j), sortedTasks.at(min))) {
                min = j;
            }
        }
        swap(sortedTasks.at(i), sortedTasks.at(min));
    }
}

bool View::compareTasksDueDate (Task const* task1, Task const* task2) {
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

void View::loadStringStreams(Home target) {
    stringstream sun, mon, tues, weds, thurs, fri, sat;
    if (target.isEmpty() != true) {
        for (auto task : target.classificationTaskStorage["Undated"]) {
            if (isDateInWeek(task) == true) {
                if (calculateDayOfWeek(task) == "sun") { loadTaskData(sun, task); } 
                else if (calculateDayOfWeek(task) == "mon") { loadTaskData(mon, task); }
                else if (calculateDayOfWeek(task) == "tues") { loadTaskData(tues, task); }
                else if (calculateDayOfWeek(task) == "weds") { loadTaskData(weds, task); }
                else if (calculateDayOfWeek(task) == "thurs") { loadTaskData(thurs, task); }
                else if (calculateDayOfWeek(task) == "fri") { loadTaskData(fri, task); }
                else if (calculateDayOfWeek(task) == "sat") { loadTaskData(sat, task); }
            }
        }
        for (auto task : target.classificationTaskStorage["Dated"]) {
            if (isDateInWeek(task) == true) {
                if (calculateDayOfWeek(task) == "sun") { loadTaskData(sun, task); } 
                else if (calculateDayOfWeek(task) == "mon") { loadTaskData(mon, task); }
                else if (calculateDayOfWeek(task) == "tues") { loadTaskData(tues, task); }
                else if (calculateDayOfWeek(task) == "weds") { loadTaskData(weds, task); }
                else if (calculateDayOfWeek(task) == "thurs") { loadTaskData(thurs, task); }
                else if (calculateDayOfWeek(task) == "fri") { loadTaskData(fri, task); }
                else if (calculateDayOfWeek(task) == "sat") { loadTaskData(sat, task); }
            }
        }
        unordered_set<Task*> soloTaskIterator = target.getSoloTasks()->getTasks();
        for (Task* task : soloTaskIterator) {
            if (isDateInWeek(task) == true) {
                if (calculateDayOfWeek(task) == "sun") { loadTaskData(sun, task); } 
                else if (calculateDayOfWeek(task) == "mon") { loadTaskData(mon, task); }
                else if (calculateDayOfWeek(task) == "tues") { loadTaskData(tues, task); }
                else if (calculateDayOfWeek(task) == "weds") { loadTaskData(weds, task); }
                else if (calculateDayOfWeek(task) == "thurs") { loadTaskData(thurs, task); }
                else if (calculateDayOfWeek(task) == "fri") { loadTaskData(fri, task); }
                else if (calculateDayOfWeek(task) == "sat") { loadTaskData(sat, task); }
            }
        }
    }
}

string View::calculateDayOfWeek(Task* target) {
    return "";
}

void View::loadTaskData(stringstream& ss,Task* task) {
    ss << task->getName() << " " << task->getFullDueDate();
    if (task->getCompleteStatus()) {
        ss << " \u2713";
    }
    ss << endl;
}

bool View::isDateInWeek(Task* target) {
    // gets the current time point
    auto currentTime = chrono::system_clock::now();
    time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
    // converst the current time to a tm structure
    tm* currentTM = localtime(&currentTimeT);
    // calculates the day of the week for the current time
    int currentDayOfWeek = currentTM->tm_wday;
    // calculates the day of the week for the given date
    tm givenDate = {0, 0, 0, target->getAssignedDay(), target->getAssignedMonth()
                 - 1, target->getAssignedYear() - 200};
    mktime(&givenDate);
    int givenDayOfWeek = givenDate.tm_wday;
    // difference in days between the current day and the given date
    int daysDifference = (givenDayOfWeek - currentDayOfWeek + 7) % 7;
    // checks if the given date is in the current week
    return (daysDifference >= 0 && daysDifference <= 6);
}
