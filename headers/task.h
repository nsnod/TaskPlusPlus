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
   void editName(string &); //edits the task name 
   void editDescription(string &); //edits the task description
   void editPriority(string &); //edits the task priority
   void editDueDate(int, int, int); //edits the dueDate
   void setDueDay(int);
   void setDueMonth(int);
   void setDueYear(int);
   void editAssignedDate(int, int, int); //edits the assingedDate
   void switchCompleteStatus(); //edits the complete value
   void setList(); //prompts user to set the list

   //getters
   string getName() { return name; }
   string getDescription() { return description; }
   string getPriority() { return priority; }
   bool getCompleteStatus() { return completed; }
   string getFullDueDate();
   int getDueDay() { return dueDay; }
   int getDueMonth() { return dueMonth; }
   int getDueYear() { return dueYear; }
   string getFullAssignedDate(); 
   int getAssignedDay() { return assignedDay; }
   int getAssignedMonth() { return assignedMonth; }
   int getAssignedYear() { return assignedYear; }

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