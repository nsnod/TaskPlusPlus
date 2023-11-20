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
   void createNewTask(vector<string>);
   void createNewList(vector<string>);
   void viewLists();
   void editLists();
 private:
   unordered_map<string, unordered_set<TaskList*>> classificationBasedStorage;
   unordered_map<string, Task*> soloTasks;
};

#endif