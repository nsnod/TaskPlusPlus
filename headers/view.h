#ifndef VIEW_H
#define VIEW_H

#include "home.h"
#include "taskList.h"
#include "task.h"

class View {
 public:
    void viewWeekly() const;
    void viewPriority(string userChoice) const;
    void viewOverall() const;
 private:
    void sortTasks();
    vector<Task*> sortedTasks;
};

#endif