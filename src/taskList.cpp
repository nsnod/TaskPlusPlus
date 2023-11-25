#include "../headers/taskList.h"
#include <iostream>
#include <string>

using namespace std;

TaskList::TaskList() : name(""), description(""), classification(""), complete(false), numOfCompleted(0) {}

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
    for (auto target : listOfTasks) {
        if (target->getName() == taskName) {
            listOfTasks.erase(target);
            delete target;
        }
    }
}

template<typename T> void TaskList::editTask(Task* target, const string& action, T newVal) {
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
    else if (action == "Due Day") {
        target->setDueDay(newVal);
    }
    else if (action == "Due Month") {
        target->setDueMonth(newVal);
    }
    else if (action == "Due Year") {
        target->setDueYear(newVal);
    }
    else if (action == "Assigned Day") {
        target->setAssignedDay(newVal);
    }
    else if (action == "Assigned Month") {
        target->setAssignedMonth(newVal);
    }
    else if (action == "Assigned Year") {
        target->setAssignedYear(newVal);
    }
}

void TaskList::findCompletedTasks() {
    for(auto i : listOfTasks) {
        if (i->getCompleteStatus() == true) {
            ++numOfCompleted;
        }
    }
}

void TaskList::viewTasks() const {
    // Going to call prompt NEED TO WAIT
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
    return numOfCompleted / listOfTasks.size();
}

Task* TaskList::findTask(const string& taskName) const {
    for (auto i : listOfTasks) {
        if (i->getName() == taskName) {
            return i;
        }
    }
    return nullptr;
}