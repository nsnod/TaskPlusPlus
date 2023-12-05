#include "../headers/taskList.h"
#include <iostream>
#include <string>

using namespace std;

TaskList::TaskList() : name(""), description(""), classification(""), complete(false) {}

TaskList::~TaskList() { 
    for (auto i : listOfTasks) {
        delete i;
    }
}

void TaskList::editListName(const string& newName) {
    name = newName;
}

void TaskList::editListDescription(const string& newDescription) {
    description = newDescription;
}

void TaskList::editListClassification(const string& newClassification) {
    classification = newClassification;
}

void TaskList::switchCompleteStatus() {
    if (complete == true) complete = false;
    else complete = true;
}

void TaskList::addTask(Task* newTask) {
    listOfTasks.insert(newTask);
}

void TaskList::removeTask(const string& taskName) {
    if (listOfTasks.size() > 0 && findTask(taskName) != nullptr) {
        for (auto target : listOfTasks) {
            if (target->getName() == taskName) {
                listOfTasks.erase(target);
                delete target;
                target = nullptr;

                return;
            }
        }
    }
}

void TaskList::editTask(string taskName, string action, string newVal) {
    Task *target = findTask(taskName);
    
    if (action == "Name") {
        target->setName(newVal);
    }
    else if (action == "Description") {
        target->setDescription(newVal);
    }
    else if (action == "Priority") {
        target->setPriority(newVal);
    }
    else if (action == "Full Due Date") {
        target->setFullDueDate(newVal);
    }
    else if (action == "Full Assigned Date") {
        target->setFullAssignedDate(newVal);
    }

    target = nullptr;
}

double TaskList::findCompletedTasks() const {
    double numOfCompleted = 0;
    for(auto i : listOfTasks) {
        if (i->getCompleteStatus() == true) {
            ++numOfCompleted;
        }
    }

    return numOfCompleted;
}

bool TaskList::compareTasks(Task* task1, Task* task2) const {
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

void TaskList::viewTasks() const {
    if (getNumOfTasks() != 0) {

    // Sorting by date for output
        vector<Task*> sortedByDate;

        for (Task* i : listOfTasks) {
            sortedByDate.push_back(i);
        } 
        for (unsigned int i = 0; i < sortedByDate.size() - 1; ++i) {
            int min = i;
            for (unsigned int j = i + 1; j < sortedByDate.size(); ++j) {
                if (compareTasks(sortedByDate[j], sortedByDate[min])) {
                    min = j;
                }
            }
            swap(sortedByDate[i], sortedByDate[min]);
        }

    // outputting
        cout << getListName() << "\tCompleted Progression: " << setprecision(3) << getProgress() << "%" << endl;
        cout << "-----------------------------------------------" << endl;

        int taskCount = 1;

        for (auto i : sortedByDate) {
            cout << taskCount << ".) " << i->getName() << " " << i->getFullDueDate() << " ";

            if (i->getCompleteStatus() == true) {
                cout << "\u2713";
            }
            cout << endl;

            ++taskCount;
        }
    }
    else {
        cout << "------------LIST IS EMPTY------------" << endl;
    }
}

string TaskList::getListName() const {
    return name;
}

string TaskList::getListDescription() const {
    return description;
}

string TaskList::getListClassification() const {
    return classification;
}

bool TaskList::getListCompleteStatus() const {
    return complete;
}

double TaskList::getProgress() const {
    double numOfCompleted = findCompletedTasks();
    return 100.0 * (numOfCompleted / getNumOfTasks());
}

Task* TaskList::findTask(const string& taskName) const {
    for (auto i : listOfTasks) {
        if (i->getName() == taskName) {
            return i;
        }
    }
    return nullptr;
}

int TaskList::getNumOfTasks() const {
    return listOfTasks.size();
}