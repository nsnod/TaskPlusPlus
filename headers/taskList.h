#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"
#include <vector>

class TaskList {
 public:
    TaskList(); // Default Constructor
    // ~TaskList(); // Destructor
    // TaskList(const TaskList&); // Copy Constructor
    // TaskList& operator=(const TaskList&); // Assignment operator

    // setters
    void editListName(const string& newName); // Edit list's name
    void editListDescription(const string& newDescription); // Edit list's description
    void editListClassification(const string& newClassification); // Edit list's classification
    void switchCompleteStatus(); // Change the completion status of the list
    void addTask(Task task); // Add task to list
    void removeTask(int index); // Remove a specific task from list
    void editTask(int index); // Edit a specific task within the test
    void findCompletedTasks(); // Count the number of completed tasks

    // getters
    void viewTasks() const; // Display all tasks within list
    string getListName() const; // Return the list's name
    string getListDescription() const; // Return the list's description
    string getListClassification() const; // Return the list's classification
    bool getListCompleteStatus() const; // Return the completion status of the list
    double getProgress() const; // Return the progress of completed tasks to total tasks
    
 private: 
    vector<Task> userList;
    string name;
    string description;
    string classification;
    bool complete;
    double numOfCompleted;
};

#endif