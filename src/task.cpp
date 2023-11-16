#include "../headers/task.h"
#include <iostream>
#include <string>

using namespace std;

//Always construct a default task when user creates a task, then prompt them
//for imformation during new task screen... only fill in what they need
Task::Task(): name(""), description(""), priority(""), dueDay(-1), dueMonth(-1), dueYear(-1),
              assignedDay(-1), assignedMonth(-1), assignedYear(-1), completed(false) {}

void Task::editTaskName(string &n) {
    name = n;
}

void Task::editTaskDescription(string &d) {
    description = d;
}

void Task::editTaskPriority(string &p) {
    priority = p;
}

void Task::editTaskDueDate() {
    //temp filler
}

void Task::editTaskAssignedDate() {
    //temp filler
}

void Task::switchCompleteStatus() {
    if (completed == false) {
        completed = true;
    } else if (completed == true) {
        completed = false;
    }
}

void Task::setList() {
    //temp filler
}

string Task::getTaskDueDate() {
    if (dueDay == -1 || dueMonth == -1 || dueYear == -1) {
        return "No due date has been set for this task.";
    }

    return "/" + to_string(dueMonth) + "/" + to_string(dueDay)
               + "/" + to_string(dueYear);
}

string Task::getTaskAssignedDate() {
    if (assignedDay == -1 || assignedMonth == -1 || assignedYear == -1) {
        return "No assigned date has been set for this task.";
    }
    return "/" + to_string(assignedMonth) + "/" + to_string(assignedDay)
               + "/" + to_string(assignedYear);
}