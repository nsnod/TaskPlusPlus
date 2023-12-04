#include <iostream>
#include <string>
#include <algorithm>
#include "../headers/view.h"
#include "../headers/home.h"
#include "../headers/taskList.h"
#include "../headers/task.h"

using namespace std;

void View::sortTasks(Home target) {
    for (auto i : target.classificationTaskStorage["Dated"]) {
        sortedTasks.push_back(i);
    }

    for (unsigned int i = 0; i < sortedTasks.size() - 1; ++i) {
        int min = i;
        for (unsigned int j = i + 1; j < sortedTasks.size(); ++j) {
            if (compareTasks(sortedTasks.at(i), sortedTasks.at(min))) {
                swap(sortedTasks.at(i), sortedTasks.at(min));
            }
        }
    }
}

bool View::compareTasks (Task const* task1, Task const* task2) {
    return task1 < task2;
}


void View::viewPriority(Home target, string userChoice) const {
    if (target.isEmpty() != true) {
        if (userChoice == "Completed") {
            
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

void View::viewOverall() const {
    
}