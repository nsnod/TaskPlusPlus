#include "../headers/home.h"
#include "../headers/taskList.h"
#include "../headers/task.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

void Home::createNewTask(vector<string> inputs) {
    Task* newTask = new Task;

    newTask->setName(inputs[0]);
    newTask->setPriority(inputs[1]);
    newTask->setFullDueDate(inputs[2]);
    newTask->setFullAssignedDate(inputs[3]);
    newTask->setDescription(inputs[4]);
    newTask->setList(inputs[5]);
}

void Home::createNewList(vector<string> inputs) {

}

void Home::viewLists() {

}

void Home::editLists() {

}