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
   void editLists() const;
   void setList(Task*, const string&);
   Task* findSoloTask(const string&) const;
   TaskList* findTaskList(const string&) const;
   
 private:
   unordered_map<string, unordered_set<TaskList*>> classificationBasedStorage;
   TaskList* soloTasks = new TaskList;
};

#endif