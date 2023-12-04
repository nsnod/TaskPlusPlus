#ifndef VIEW_H
#define VIEW_H

#include "home.h"
#include "taskList.h"
#include "task.h"

class Home;
class View {
 public:
    void viewWeekly(Home target) const;
    void viewPriority(Home target, string userChoice);
    void viewOverall(Home target) const;
 private:
    void sortTasks(Home target);
    bool compareTasks(Task const* task1, Task const* task2);
    void printHighPriority(bool printCompleted, bool printUncompleted) const;
    void printMedPriority(bool printCompleted, bool printUncompleted) const;
    void printLowPriority(bool printCompleted, bool printUncompleted) const;
    vector<Task*> sortedTasks;
};

#endif