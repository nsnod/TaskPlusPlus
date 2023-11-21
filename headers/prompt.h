#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class prompt{
    private:
    unsigned selection;

    public:
    void printMainMenu();
    vector<string> newTaskPrompt();
    void newListPrompt();
    void taskEditorPrompt();
    void listEditorPrompt();
    void viewArchivePrompt();
    void viewWeeklyTasksPrompt();
    void viewUpcomingTasksPrompt();
    void recommendWeeklySchedulePrompt();
    void setSelection(); //helper/setter function//
};