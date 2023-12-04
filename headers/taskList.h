#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"
#include <vector>
#include <unordered_set>
#include <iomanip>

// template<typename T>
class TaskList {
 public:
    TaskList(); // Default Constructor
    ~TaskList(); // Destructor
    // TaskList(const TaskList&); // Copy Constructor
    // TaskList& operator=(const TaskList&); // Assignment operator

    // setters
    void editListName(const string& newName); // Edit list's name
    void editListDescription(const string& newDescription); // Edit list's description
    void editListClassification(const string& newClassification); // Edit list's classification
    void switchCompleteStatus(); // Change the completion status of the list
    void addTask(Task* newTask); // Add task to list
    void removeTask(const string& taskName); // Remove a specific task from list
    void editTask(string taskName, string action, string newVal); // Edit a specific task within the test

    // getters
    void viewTasks() const; // Display all tasks within list
    bool compareTasks(Task*, Task*) const; // used in viewTasks to sort
    string getListName() const; // Return the list's name
    string getListDescription() const; // Return the list's description
    string getListClassification() const; // Return the list's classification
    bool getListCompleteStatus() const; // Return the completion status of the list
    double getProgress() const; // Return the progress of completed tasks to total tasks
    Task* findTask(const string& taskName) const; // Finds the task in a list based on its name
    int getNumOfTasks() const; // Return the number of tasks in list
    double findCompletedTasks() const; // Count the number of completed tasks
    
 private: 
    unordered_set<Task*> listOfTasks;
    string name;
    string description;
    string classification;
    bool complete;
};

#endif