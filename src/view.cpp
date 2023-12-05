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

void View::viewWeekly(Home target) {
    loadStringStreams(target);
}

void View::unloadStringStreams(stringstream& sun, stringstream& mon, stringstream& tues, stringstream& weds,
                stringstream& thurs, stringstream& fri, stringstream& sat) {
    cout << "Sunday!" << endl;
    cout << sun.str() << endl;
    
    cout << "Monday!" << endl;
    cout << mon.str() << endl;

    cout << "Tuesday!" << endl;
    cout << tues.str() << endl;

    cout << "Wednesday!" << endl;
    cout << weds.str() << endl;

    cout << "Thursday!" << endl;
    cout << thurs.str() << endl;

    cout << "Friday!" << endl;
    cout << fri.str() << endl;

    cout << "Saturday!" << endl;
    cout << sat.str() << endl;
}

void View::loadStringStreams(Home target) {
    stringstream sun, mon, tues, weds, thurs, fri, sat;
    if (target.isEmpty() != true) {
        for (auto taskList : target.overallLists) {
            for(auto task : taskList->getTasks()) {
                if (isDateInWeek(task) == true) {
                    if (calculateDayOfWeek(task) == "Sunday") { loadTaskData(sun, task); } 
                    else if (calculateDayOfWeek(task) == "Monday") { loadTaskData(mon, task); }
                    else if (calculateDayOfWeek(task) == "Tuesday") { loadTaskData(tues, task); }
                    else if (calculateDayOfWeek(task) == "Wednesday") { loadTaskData(weds, task); }
                    else if (calculateDayOfWeek(task) == "Thursday") { loadTaskData(thurs, task); }
                    else if (calculateDayOfWeek(task) == "Friday") { loadTaskData(fri, task); }
                    else if (calculateDayOfWeek(task) == "Saturday") { loadTaskData(sat, task); }
                }
            }
        }
        unordered_set<Task*> soloTaskIterator = target.getSoloTasks()->getTasks();
        for (Task* task : soloTaskIterator) {
            if (isDateInWeek(task) == true) {
                if (calculateDayOfWeek(task) == "Sunday") { loadTaskData(sun, task); } 
                else if (calculateDayOfWeek(task) == "Monday") { loadTaskData(mon, task); }
                else if (calculateDayOfWeek(task) == "Tuesday") { loadTaskData(tues, task); }
                else if (calculateDayOfWeek(task) == "Wednesday") { loadTaskData(weds, task); }
                else if (calculateDayOfWeek(task) == "Thursday") { loadTaskData(thurs, task); }
                else if (calculateDayOfWeek(task) == "Friday") { loadTaskData(fri, task); }
                else if (calculateDayOfWeek(task) == "Saturday") { loadTaskData(sat, task); }
            }
        }

        unloadStringStreams(sun, mon, tues, weds, thurs, fri, sat);
    }
}

string View::calculateDayOfWeek(Task* target) {
    // adjust the year for years since 1900 because thats how tm works
    int year = target->getAssignedYear() < 69 ? 100 + target->getAssignedYear() : target->getAssignedYear();
    tm structure = {};
    structure.tm_year = year - 1900;
    structure.tm_mon = target->getAssignedMonth() - 1;  // Adjust for months (0-11)
    structure.tm_mday = target->getAssignedDay();

    time_t time = mktime(&structure);

    vector<string> daysOfWeek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int dayIndex = localtime(&time)->tm_wday;

    return daysOfWeek[dayIndex];
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
    
    tm* currentTM = localtime(&currentTimeT);

    // calculates the day of the week for the given date
    int year = target->getAssignedYear() < 69 ? 100 + target->getAssignedYear() : target->getAssignedYear();
    tm givenDate = {0, 0, 0, target->getAssignedDay(), target->getAssignedMonth()
                 - 1, year};

    mktime(&givenDate);
    int currentDayOfWeek = currentTM->tm_wday;
    int givenDayOfWeek = givenDate.tm_wday;
    int daysDifference = (givenDayOfWeek - currentDayOfWeek + 7) % 7;

    return (daysDifference >= 0 && daysDifference <= 6);
}
