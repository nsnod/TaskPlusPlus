#ifndef HOME_H
#define HOME_H

#include "../headers/task.h"
#include "../headers/taskList.h"
#include "../headers/task.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Home {
 public:
   void createNewTask(const vector<string>&);
   void createNewList(const vector<string>&);
   void viewLists() const;
   void editList(string, string, string) const;
   void setList(Task*, const string&);
   void setClassification(Task*);
   //void deleteTask()
   //NO DOUBLE FREES
   //delete from one list and then just erase from the other because there are two pointers
   Task* findSoloTask(const string&) const;
   TaskList* findTaskList(const string&) const;
   
 private:
   unordered_map<string, unordered_set<Task*>> classificationTaskStorage;
   unordered_set<TaskList*> overallLists;
   TaskList* soloTasks = new TaskList;
};

#endif