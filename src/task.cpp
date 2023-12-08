#include "../headers/task.h"
#include "../headers/home.h"
#include "../headers/taskList.h"
#include <iostream>
#include <string>

using namespace std;

//Always construct a default task when user creates a task, then prompt them
//for imformation during new task screen... only fill in what they need
Task::Task(): name(""), description(""), priority(""), fullDueDate(""), fullAssignedDate(""), dueDay(-1), dueMonth(-1), dueYear(-1),
              assignedDay(-1), assignedMonth(-1), assignedYear(-1), classification(""), completed(false) {}

Task::Task(const Task& other)
    : name(other.name), description(other.description), priority(other.priority),
      fullDueDate(other.fullDueDate), fullAssignedDate(other.fullAssignedDate),
      classification(other.classification), dueDay(other.dueDay),
      dueMonth(other.dueMonth), dueYear(other.dueYear),
      assignedDay(other.assignedDay), assignedMonth(other.assignedMonth),
      assignedYear(other.assignedYear), completed(other.completed) {
}

void Task::setFullDueDate(const string& dueDate) {
    fullDueDate = dueDate;

    setDueMonth(stoi(dueDate.substr(0, 2)));
    setDueDay(stoi(dueDate.substr(3, 2)));
    setDueYear(stoi(dueDate.substr(6, 2)));
}

void Task::setFullAssignedDate(const string& assignedDate) {
    fullAssignedDate = assignedDate;

    setAssignedMonth(stoi(assignedDate.substr(0, 2)));
    setAssignedDay(stoi(assignedDate.substr(3, 2)));
    setAssignedYear(stoi(assignedDate.substr(6, 2)));
}

void Task::switchCompleteStatus() {
    if (completed == false) {
        completed = true;
    } else if (completed == true) {
        completed = false;
    }
}