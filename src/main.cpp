//#pragma once
#include <iostream>

#include "../headers/home.h"
#include "../headers/prompt.h"
#include "../headers/task.h"
#include "../headers/taskList.h"
#include "../headers/view.h"

using namespace std;

int main(){

    prompt Prompt;
    Home* home = new Home;
    View view;
    do{
        Prompt.printMainMenu();

        if(Prompt.getSelection() == "1"){
            Prompt.newTaskPrompt(home);
        }

        else if(Prompt.getSelection() == "2"){
            Prompt.newListPrompt(home);
        }
        //weekly tasks
        else if(Prompt.getSelection() == "3"){
            Prompt.viewWeekly(*view, home);
        }
        //view tasks by priority
        else if(Prompt.getSelection() == "4"){
            view.viewOverall(*home);
        }
        //edit tasks
        else if(Prompt.getSelection() == "5"){
            string userPriority;
            cout << "Enter the priority of tasks you would like to view (Completed, Uncompleted, All): " << endl;
            getline(cin, userPriority);

            view.viewPriority(*home, userPriority);
            
        }
    }while(Prompt.getSelection() != "Task--");

    delete home;

    return 0;
}
