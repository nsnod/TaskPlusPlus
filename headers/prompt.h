#pragma once 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class prompt{
    private:
    unsigned selection;

    public:
    prompt();
    void printMainMenu();
    vector<string> newTaskPrompt() const;
    void newListPrompt() const;
    void taskEditorPrompt() const;
    void listEditorPrompt() const;
    void viewArchivePrompt() const;
    void viewWeeklyTasksPrompt() const;
    void viewUpcomingTasksPrompt() const;
    void recommendWeeklySchedulePrompt() const;
    void setSelection(); //helper/setter function//
};