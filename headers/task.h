#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task {
 public:
   Task();
   //Rule of three
   ~Task() {}
   // Task(const Task&);
   // Task& operator=(const Task&);
   bool operator<(Task const& rhs);

   // setters //
   void setName(const string& n) { name = n; }
   void setDescription(const string& d) { description = d; }
   void setPriority(const string& p) { priority = p; }
   void setFullDueDate(const string&);
   void setFullAssignedDate(const string&);
   void setDueDay(int dD) { dueDay = dD; }
   void setDueMonth(int dM) { dueMonth = dM; }
   void setDueYear(int dY) { dueYear = dY; }
   void setAssignedDay(int aD) { assignedDay = aD; }
   void setAssignedMonth(int aM) { assignedMonth = aM; }
   void setAssignedYear(int aY) { assignedYear = aY; }
   void switchCompleteStatus();

   // getters //
   string getName() const { return name; }
   string getDescription() const { return description; }
   string getPriority() const { return priority; }
   bool getCompleteStatus() const { return completed; }
   string getFullDueDate() const { return fullDueDate; }
   string getFullAssignedDate() const { return fullAssignedDate; }
   int getDueDay() const { return dueDay; }
   int getDueMonth() const { return dueMonth; }
   int getDueYear() const { return dueYear; }
   int getAssignedDay() const { return assignedDay; }
   int getAssignedMonth() const { return assignedMonth; }
   int getAssignedYear() const { return assignedYear; }

 private:
   string name;
   string description;
   string priority;
   string fullDueDate;
   string fullAssignedDate;
   string classification;
   int dueDay;
   int dueMonth;
   int dueYear;
   int assignedDay;
   int assignedMonth;
   int assignedYear;
   bool completed;
};

#endif