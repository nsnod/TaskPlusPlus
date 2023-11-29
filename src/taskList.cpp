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

void TaskList::editTask(Task* target, const string& action, const string& newVal) {
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

void TaskList::viewTasks() const {
    if (getNumOfTasks() != 0) {
        cout << getListName() << "\tCompleted Progression: " << setprecision(3) << getProgress() << "%" << endl;
        cout << "-----------------------------------------------" << endl << endl;

        int taskCount = 1;

        for (auto i : listOfTasks) {
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