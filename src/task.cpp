#include "../headers/task.h"
#include <iostream>
#include <string>

using namespace std;

//Always construct a default task when user creates a task, then prompt them
//for imformation during new task screen... only fill in what they need
Task::Task(): name(""), description(""), priority(""), dueDay(-1), dueMonth(-1), dueYear(-1),
              assignedDay(-1), assignedMonth(-1), assignedYear(-1), completed(false) {}

void Task::editName(const string &n) {
    name = n;
}

void Task::editDescription(const string &d) {
    description = d;
}

void Task::editPriority(const string &p) {
    priority = p;
}

void Task::editDueDate(int dD, int dM, int dY) {
    dueDay = dD;
    dueMonth = dM;
    dueYear = dueYear;
}

void Task::editAssignedDate(int aD, int aM, int aY) {
    assignedDay = aD;
    assignedMonth = aM;
    assignedYear = aY;
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

string Task::getFullDueDate() const {
    if (dueDay == -1 || dueMonth == -1 || dueYear == -1) {
        return "No due date has been set for this task.";
    }

    return "/" + to_string(dueMonth) + "/" + to_string(dueDay)
               + "/" + to_string(dueYear);
}

void setDueDay(int dD) {
    
}

void setDueMonth(int dM) {
    
}

void setDueYear(int dY) {
    
}

string Task::getFullAssignedDate() const {
    if (assignedDay == -1 || assignedMonth == -1 || assignedYear == -1) {
        return "No assigned date has been set for this task.";
    }
    return "/" + to_string(assignedMonth) + "/" + to_string(assignedDay)
               + "/" + to_string(assignedYear);
}

