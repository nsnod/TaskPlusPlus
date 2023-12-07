#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "home.h"
#include "task.h"
#include "taskList.h"


#include "task.h"
#include "taskList.h"
#include "view.h"

using namespace std;

class prompt{
    private:
    string selection = "";

    public:

    void clearScreen();
    void setSelection(); //helper//
    void setSelection(const string&);
    void printSeparator(int);
    string getSelection() const; //helper//
    
    

    
    void printMainMenu();

    void newTaskPrompt(Home*) const;
    void newListPrompt(Home*) const;

    void taskEditorPrompt(Task*, TaskList*);
    void listEditorPrompt(Home*);
    
    void viewWeekly(View*,Home*);
    void viewPriority(View*,Home*);
    void viewOverall(View*,Home*); //viewing all lists  (lists inside the tasks) and solo tasks gets input //

    void printLogos(const string&) const;

    void displayHorizontalLine(int, char);
};
    
    
    
