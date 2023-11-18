#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task {
 public:
   Task();
   //Rule of three
   // ~Task() {}
   // Task(const Task&);
   // Task& operator=(const Task&);

   // setters/editors
   void editName(const string &); //edits the task name 
   void editDescription(const string &); //edits the task description
   void editPriority(const string &); //edits the task priority
   void editDueDate(int, int, int); //edits the dueDate
   void setDueDay(int);
   void setDueMonth(int);
   void setDueYear(int);
   void editAssignedDate(int, int, int); //edits the assingedDate
   void switchCompleteStatus(); //edits the complete value
   void setList(); //prompts user to set the list

   //getters
   string getName() const { return name; }
   string getDescription() const { return description; }
   string getPriority() const { return priority; }
   bool getCompleteStatus() const { return completed; }
   string getFullDueDate() const;
   int getDueDay() const { return dueDay; }
   int getDueMonth() const { return dueMonth; }
   int getDueYear() const { return dueYear; }
   string getFullAssignedDate() const; 
   int getAssignedDay() const { return assignedDay; }
   int getAssignedMonth() const { return assignedMonth; }
   int getAssignedYear() const { return assignedYear; }

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

#endif