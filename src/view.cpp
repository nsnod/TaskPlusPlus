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

void View::sortTasks(Home& target) {
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


void View::viewPriority(Home& target, string userChoice) {
    if (target.isEmpty() != true) {
        sortTasks(target);

        if (userChoice == "Completed" || userChoice == "completed") {
            cout << "HIGH PRIORITY - COMPLETED\n" << "---------------------------\n";
            printHighPriority(true, false);

            cout << "MEDIUM PRIORITY - COMPLETED\n" << "---------------------------\n";
            printMedPriority(true, false);

            cout << "LOW PRIORITY - COMPLETED\n" << "---------------------------\n";
            printLowPriority(true, false);
        }
        else if (userChoice == "Uncompleted" || userChoice == "uncompleted") {
            cout << "HIGH PRIORITY - UNCOMPLETED\n" << "---------------------------\n";
            printHighPriority(false, true);

            cout << "MEDIUM PRIORITY - UNCOMPLETED\n" << "---------------------------\n";
            printMedPriority(false, true);

            cout << "LOW PRIORITY - UNCOMPLETED\n" << "---------------------------\n";
            printLowPriority(false, true);
        }
        else if (userChoice == "All" || userChoice == "all") {
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

void View::viewOverall(Home& target) const {
    if (target.listEmpty() != true) {
        cout << "Solo Tasks" << endl;
        target.soloTasks->viewTasks();
        cout << endl << endl;

        for (TaskList* list : target.overallLists) {
            if (list->getNumOfTasks() == 0) {
                cout << list->getListName() << endl;
                cout << "-------------NO TASKS AVAILABLE-------------" << endl << endl;
            } else {
                list->viewTasks();
                cout << endl << endl;
            }
        } 
    }
}

void View::viewWeekly(Home& target) {
    loadStringStreams(target);
}

void View::unloadStringStreams(stringstream& sun, stringstream& mon, stringstream& tues, stringstream& weds,
                stringstream& thurs, stringstream& fri, stringstream& sat) {
    outputOptions("Sunday");
    cout << sun.str() << endl;
    
    outputOptions("Monday");
    cout << mon.str() << endl;

    outputOptions("Tuesday");
    cout << tues.str() << endl;

    outputOptions("Wednesday");
    cout << weds.str() << endl;

    outputOptions("Thursday");
    cout << thurs.str() << endl;

    outputOptions("Friday");
    cout << fri.str() << endl;

    outputOptions("Saturday");
    cout << sat.str() << endl;
}

void View::loadStringStreams(Home& target) {
    stringstream sun, mon, tues, weds, thurs, fri, sat;
    if (target.isEmpty() != true) {
        for (auto taskList : target.overallLists) {
            for(auto task : taskList->getTasks()) {
                if (isDateInWeek(task) == true) {
                    if (calculateDayOfWeek(task) == "Sun") { loadTaskData(sun, task); } 
                    else if (calculateDayOfWeek(task) == "Mon") { loadTaskData(mon, task); }
                    else if (calculateDayOfWeek(task) == "Tue") { loadTaskData(tues, task); }
                    else if (calculateDayOfWeek(task) == "Wed") { loadTaskData(weds, task); }
                    else if (calculateDayOfWeek(task) == "Thu") { loadTaskData(thurs, task); }
                    else if (calculateDayOfWeek(task) == "Fri") { loadTaskData(fri, task); }
                    else if (calculateDayOfWeek(task) == "Sat") { loadTaskData(sat, task); }
                }
            }
        }
        unordered_set<Task*> soloTaskIterator = target.getSoloTasks()->getTasks();
        for (Task* task : soloTaskIterator) {
            if (isDateInWeek(task) == true) {
                if (calculateDayOfWeek(task) == "Sun") { loadTaskData(sun, task); } 
                else if (calculateDayOfWeek(task) == "Mon") { loadTaskData(mon, task); }
                else if (calculateDayOfWeek(task) == "Tue") { loadTaskData(tues, task); }
                else if (calculateDayOfWeek(task) == "Wed") { loadTaskData(weds, task); }
                else if (calculateDayOfWeek(task) == "Thu") { loadTaskData(thurs, task); }
                else if (calculateDayOfWeek(task) == "Fri") { loadTaskData(fri, task); }
                else if (calculateDayOfWeek(task) == "Sat") { loadTaskData(sat, task); }
            }
        }
        unloadStringStreams(sun, mon, tues, weds, thurs, fri, sat);
    }
}

string View::calculateDayOfWeek(Task* target) {
    tm datetime = {};

    datetime.tm_mon = target->getAssignedMonth() - 1;
    datetime.tm_mday = target->getAssignedDay(); 
    datetime.tm_year = target->getAssignedYear();

    time_t time = mktime(&datetime);
    tm* timeinfo = localtime(&time);

    const string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    int weekday = datetime.tm_wday - 1;

    if (weekday < 0) {
        weekday = 6;
    }

    return days[weekday];
}

void View::loadTaskData(stringstream& ss,Task* task) {
    ss << task->getName() << " " << task->getFullDueDate();
    if (task->getCompleteStatus()) {
        ss << " \u2713";
    }
    ss << endl;
}

bool View::isDateInWeek(Task* target) {
    auto now = time(nullptr);
    tm currentDate = *localtime(&now);

    // get first day of week (Sunday = 0, Saturday = 6)
    int currentWeekday = currentDate.tm_wday;  

    // calculate current week date range
    int currentWeekStart = currentDate.tm_mday - currentWeekday;  
    int currentWeekEnd = currentWeekStart + 6;

    return (target->getAssignedMonth() == (currentDate.tm_mon + 1) 
            && target->getAssignedDay() >= currentWeekStart  
            && target->getAssignedDay() <= currentWeekEnd);
}

void View::outputOptions(string const& weekday) const {
    if (weekday == "Sunday") {
cout << R"(
   ____             __         
  / __/_ _____  ___/ /__ ___ __
 _\ \/ // / _ \/ _  / _ `/ // /
/___/\_,_/_//_/\_,_/\_,_/\_, / 
                        /___/  )" << endl;
cout << "-------------------------------" << endl;

    } else if (weekday == "Monday") {
cout << R"(        
   __  ___             __         
  /  |/  /__  ___  ___/ /__ ___ __
 / /|_/ / _ \/ _ \/ _  / _ `/ // /
/_/  /_/\___/_//_/\_,_/\_,_/\_, / 
                           /___/  )" << endl;
cout << "----------------------------------" << endl;

    } else if (weekday == "Tuesday") {
cout << R"(           
 ______                __         
/_  __/_ _____ ___ ___/ /__ ___ __
 / / / // / -_|_-</ _  / _ `/ // /
/_/  \_,_/\__/___/\_,_/\_,_/\_, / 
                           /___/  )" << endl;
cout << "----------------------------------" << endl;

    } else if (weekday == "Wednesday") {
cout << R"(
  _      __       __                __         
 | | /| / /__ ___/ /__  ___ ___ ___/ /__ ___ __
 | |/ |/ / -_) _  / _ \/ -_|_-</ _  / _ `/ // /
 |__/|__/\__/\_,_/_//_/\__/___/\_,_/\_,_/\_, / 
                                        /___/  )" << endl;
cout << "-----------------------------------------------" << endl;
    } else if (weekday == "Thursday") {
cout << R"(  
 ________                   __         
/_  __/ /  __ _________ ___/ /__ ___ __
 / / / _ \/ // / __(_-</ _  / _ `/ // /
/_/ /_//_/\_,_/_/ /___/\_,_/\_,_/\_, / 
                                /___/  )" << endl;
cout << "---------------------------------------" << endl;
    } else if (weekday == "Friday") {
cout << R"(   
   ____    _    __         
  / __/___(_)__/ /__ ___ __
 / _// __/ / _  / _ `/ // /
/_/ /_/ /_/\_,_/\_,_/\_, / 
                    /___/  )" << endl;
cout << "---------------------------" << endl;
    } else if (weekday == "Saturday") {
cout << R"(  
   ____     __              __         
  / __/__ _/ /___ _________/ /__ ___ __
 _\ \/ _ `/ __/ // / __/ _  / _ `/ // /
/___/\_,_/\__/\_,_/_/  \_,_/\_,_/\_, / 
                                /___/  )" << endl;
cout << "---------------------------------------" << endl;
    }
}