#include "../headers/taskList.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

TaskList::TaskList() : name(""), description(""), classification(""), complete(false), numOfCompleted(0) {}

// TaskList::~TaskList() { NOT SURE IF NEEDED

// }

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

void TaskList::addTask(const Task task) {
    userList.push_back(task);
}

void TaskList::removeTask(int index) {
    userList.erase(userList.begin() + index);
}

void TaskList::editTask(int index) {
    // Waiting for prompt to be able to edit that certain task
}

void TaskList::findCompletedTasks() {
    for(int i = 0; i < userList.size(); ++i) {
        if (userList.at(i).getCompleteStatus() == true) {
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
    return numOfCompleted / userList.size();
}