#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "home.h"
#include "task.h"
#include "taskList.h"

using namespace std;

class prompt{
    private:
    string selection = "";

    public:
    
    void printMainMenu();
    vector<string> newTaskPrompt(const Home*) const;
    vector<string> newListPrompt() const;
    void taskEditorPrompt(const TaskList*) const;
    vector<string> listEditorPrompt(const TaskList*) const;
    
    void viewWeeklyTasksPrompt() const;
    void viewPriority() const;
    
    void setSelection(); //helper/setter function//
    string getSelection() const;
};