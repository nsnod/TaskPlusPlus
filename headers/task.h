#include <string>

using namespace std;

class Task {
 public:
    Task();
    //Rule of three
    ~Task() {}
    Task(const Task&);
    Task& operator=(const Task&);
    // setters/editors
    void editTaskName(string &); //edits the task name 
    void editTaskDescription(string &); //edits the task description
    void editTaskPriority(string &); //edits the task priority
    void editTaskDueDate(); //edits the dueDate
    void editTaskAssignedDate(); //edits the assingedDate
    void switchCompleteStatus(); //edits the complete value
    void setList(); //prompts user to set the list
    //getters
    string getTaskName() { return name; }
    string getTaskDescription() { return description; }
    string getTaskPriority() { return priority; }
    bool getCompleteStatus() { return completed; }
    string getTaskDueDate();
    string getTaskAssignedDate(); 
 private:
    string name;
    string description;
    string priority;
    int dueDay;
    int dueMonth;
    int dueYear;
    int assignedDay;
    int assignedMonth;
    int assignedYear;
    bool completed;
};