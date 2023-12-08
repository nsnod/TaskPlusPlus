#include "../headers/home.h"
#include "../headers/taskList.h"
#include "../headers/task.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Home::~Home() {
    delete soloTasks;

    for (auto i : overallLists) {
        delete i;
    }
}

void Home::createNewTask(const vector<string>& inputs) {
    Task* newTask = new Task;

    newTask->setName(inputs[0]);
    newTask->setPriority(inputs[1]);
    newTask->setFullDueDate(inputs[2]);
    newTask->setFullAssignedDate(inputs[3]);
    newTask->setDescription(inputs[4]);
    setClassification(newTask);
    setList(newTask, inputs[5]);
}

void Home::deleteList(const string& listName) {

    if (listName == "Solo Tasks") {
        cout << "You cannot delete Solo Tasks. This is not a User List." << endl;
        return;
    }

    TaskList* target = findTaskList(listName);

    if (target != nullptr) {
        overallLists.erase(target);
        delete target;
        target = nullptr;
    }
}

void Home::createNewList(const vector<string>& inputs) {
    TaskList* newList = new TaskList;

    newList->editListName(inputs[0]);
    newList->editListDescription(inputs[1]);

    overallLists.insert(newList);
}

void Home::viewLists() const {

    int listCount = 1;

    for (auto list : overallLists) {
        cout << listCount << ".)" << list->getListName() << endl;
        listCount++;
    }
}

void Home::editList(string newList, string action, string newVal) const {
    TaskList *target = findTaskList(newList);

    if (action == "Title") {
        target->editListName(newVal);
    } else if (action == "Description") {
        target->editListDescription(newVal);
    }

    target = nullptr;
}

void Home::setList(Task* newTask, const string& selectedList) {
    if (selectedList == "") {
        soloTasks->addTask(new Task(*newTask));
        delete newTask;
    } else {
        Task* taskCopy = (new Task(*newTask));
        for (auto taskLists : overallLists) {
            if (taskLists->getListName() == selectedList) {
               taskLists->addTask(taskCopy);
               delete newTask;
               break;
            }
        }
        if (!isAdded) {
            delete newTask;
        }
    }
}

void Home::setClassification(Task* newTask) { 
    if (newTask->getFullDueDate() == "") {
        classificationTaskStorage["Undated"].insert(newTask);
    } else {
        classificationTaskStorage["Dated"].insert(newTask);
    }
}

Task* Home::findSoloTask(const string& taskName) const {
    return soloTasks->findTask(taskName);
}

TaskList* Home::findTaskList(const string& listName) const {
    for (auto taskLists : overallLists) {
        if (taskLists->getListName() == listName) {
            return taskLists;
        }
    }
    return nullptr;
}

TaskList* Home::findParentList(const string& taskName) const {
    if (findSoloTask(taskName) != nullptr) {
        return soloTasks;
    } else {
        for (auto list : overallLists) {
            if (list->findTask(taskName) != nullptr) {
                return list;
            }
        }
    }
    return nullptr;
}


bool Home::isEmpty() {
    if (classificationTaskStorage.size() == 0) {
        return true;
    }
    
    return false;
}

bool Home::listEmpty() {
    if (overallLists.size() == 0) {
        return true;
    }
    
    return false;
}