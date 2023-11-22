#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <cstdlib>
#include "home.h"

using namespace std;

class prompt{
    private:
    string selection = "";

    public:
    void printMainMenu();
    vector<string> newTaskPrompt(/*const Home&*/);
    void newListPrompt();
    void taskEditorPrompt();
    void listEditorPrompt();
    void viewArchivePrompt();
    void viewWeeklyTasksPrompt();
    void viewUpcomingTasksPrompt();
    void recommendWeeklySchedulePrompt();
    void setSelection(); //helper/setter function//
    string getSelection() const;
};