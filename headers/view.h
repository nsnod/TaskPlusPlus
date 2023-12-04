#ifndef VIEW_H
#define VIEW_H

#include "home.h"
#include "taskList.h"
#include "task.h"

class Home;
class View {
 public:
    void viewWeekly() const;
    void viewPriority(Home target, string userChoice) const;
    void viewOverall() const;
//  private:
    void sortTasks(Home target);
    bool compareTasks(Task const* task1, Task const* task2);
    vector<Task*> sortedTasks;
};

#endif