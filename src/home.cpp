#include "../headers/home.h"
#include "../headers/taskList.h"
#include "../headers/task.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void Home::createNewTask(vector<string> inputs) {
    Task* newTask = new Task;

    newTask->setName(inputs[0]);
    newTask->setPriority(inputs[1]);
    newTask->setFullDueDate(inputs[2]);
    newTask->setFullAssignedDate(inputs[3]);
    newTask->setDescription(inputs[4]);
    setList(newTask, inputs[5]);
}

void Home::createNewList(vector<string> inputs) {
    TaskList* newList = new TaskList;

    newList->editListName(inputs[0]);
    newList->editListDescription(inputs[1]);
    newList->editListClassification(inputs[2]);

    classificationBasedStorage[newList->getListClassification()].insert(newList);
}

void Home::viewLists() {

}

void Home::editLists() {

}

void Home::setList(Task* newTask, string selectedList) {
    if (selectedList == "") {
        soloTasks.insert(newTask);
    } else {
        for (auto classifications : classificationBasedStorage) {
            for (auto taskLists : classifications.second) {
                if (taskLists->getListName() == selectedList) {
                    taskLists->addTask(newTask);
                }
            }
        }
    }
}

Task* Home::findSoloTask(string taskName) const {
    for (auto i : soloTasks) {
        if (i->getName() == taskName) {
            return i;
        }
    }
    return nullptr;
}

TaskList* Home::findTaskList(string listName) const {
    for (auto classifications : classificationBasedStorage) {
        for (auto taskLists : classifications.second) {
            if (taskLists->getListName() == listName) {
                return taskLists;
            }
        }
    }
    return nullptr;
}

