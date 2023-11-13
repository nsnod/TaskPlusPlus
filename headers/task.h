class Task {
 public:
    Task();
    ~Task();
    void createNewTask(); //prompts user for task creation information that is used for constructor
    void editTaskName(string &name); //edits the task name 
    void editTaskDescription(string &description); //edits the task description
    void editTaskPriority(string &priority); //edits the task priority
    void editTaskDueDate(string &dueDate); //edits the dueDate
    void editTaskAssignedDate(string &assignedDate); //edits the assingedDate
    void markComplete(); //edits the complete value
    void setList(); //prompts user to set the list
 private:
    string name;
    string description;
    string priority;
    string dueDate;
    string assignedDate;
    bool completed;
};