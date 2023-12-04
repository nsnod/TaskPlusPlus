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

    void setSelection(); //helper//
    string getSelection() const; //helper//
    
    void printMainMenu();

    vector<string> newTaskPrompt(const Home*) const;
    vector<string> newListPrompt() const;

    void taskEditorPrompt(TaskList*);
    void listEditorPrompt(TaskList*);
    
    void viewWeekly() const;
    void viewPriority() const;
    void viewOverall() const;

    void printTaskPlusPlus();
    void printEnd(); //print at end XD//
    
    
};