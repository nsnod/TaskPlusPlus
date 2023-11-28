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
    vector<string> newTaskPrompt(/*const Home&*/) const;
    void newListPrompt() const;
    void taskEditorPrompt() const;
    void listEditorPrompt() const;
    void viewArchivePrompt() const;
    void viewWeeklyTasksPrompt() const;
    void viewUpcomingTasksPrompt() const;
    void recommendWeeklySchedulePrompt() const;
    void setSelection(); //helper/setter function//
    string getSelection() const;
};