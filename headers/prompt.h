#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "home.h"
#include "task.h"
#include "taskList.h"
#include "view.h"

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

    void taskEditorPrompt(const string&);
    void listEditorPrompt(TaskList*);
    
    void viewWeekly(View*,Home*);
    void viewPriority() const;
    void viewOverall() const; //viewing all lists  (lists inside the tasks) and solo tasks gets input //

    void printTaskPlusPlus();
    void printEnd(); //print at end XD//
    
    
};