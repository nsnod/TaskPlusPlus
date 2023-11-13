#include "../header/task.h"

class TaskList {
 public:
    TaskList();
    ~TaskList();
    void editListName(string& name); // Edit list's name
    void editListDescription(string& description); // Edit list's description
    void editListClassification(string& classification); // Edit list's classification
    void markComplete(); // Mark if list has completed all tasks
    void addTask(Task task); // Add task to list
    void removeTask(int index); // Remove a specific task from list
    void viewTasks(); // Display all tasks within list
    void editTask(int index); // Edit a specific task within the test
 private: 
    vector<Task> userList;
    string name;
    string description;
    string classification;
    bool complete;
};