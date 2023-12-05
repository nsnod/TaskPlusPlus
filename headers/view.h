#ifndef VIEW_H
#define VIEW_H

#include "home.h"
#include "taskList.h"
#include "task.h"

class Home;
class View {
 public:
    void viewWeekly(stringstream&, stringstream&, stringstream&, stringstream&,
                    stringstream&, stringstream&, stringstream&) const;
    void viewPriority(Home target, string userChoice);
    void viewOverall(Home target) const;
 private:
    void loadStringStreams(Home target);
    void sortTasks(Home target);
    bool compareTasksDueDate(Task const* task1, Task const* task2);
    bool compareTasksAssignedDate(Task const* task1, Task const* task2);
    string calculateDayOfWeek(Task*);
    bool isDateInWeek(Task*);
    void loadTaskData(stringstream&, Task*);
    void printHighPriority(bool printCompleted, bool printUncompleted) const;
    void printMedPriority(bool printCompleted, bool printUncompleted) const;
    void printLowPriority(bool printCompleted, bool printUncompleted) const;
    vector<Task*> sortedTasks;
};

#endif