#ifndef VIEW_H
#define VIEW_H

#include "home.h"
#include "taskList.h"
#include "task.h"

class Home;
class View {
 public:
    void viewWeekly(Home&);
    void viewPriority(Home& target, string userChoice);
    void viewOverall(Home& target) const;
 private:
    void loadStringStreams(Home& target);
    void unloadStringStreams(stringstream& sun, stringstream& mon, stringstream& tues, stringstream& weds,
                stringstream& thurs, stringstream& fri, stringstream& sat);
    void sortTasks(Home& target);
    bool compareTasksDueDate(Task const* task1, Task const* task2);
    bool compareTasksAssignedDate(Task const* task1, Task const* task2);
    string calculateDayOfWeek(Task*);
    bool isDateInWeek(Task*);
    void loadTaskData(stringstream&, Task*);
    void outputOptions(string const&) const;
    void printHighPriority(bool printCompleted, bool printUncompleted) const;
    void printMedPriority(bool printCompleted, bool printUncompleted) const;
    void printLowPriority(bool printCompleted, bool printUncompleted) const;
    vector<Task*> sortedTasks;
};

#endif