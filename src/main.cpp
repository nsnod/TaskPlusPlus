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
            view.viewWeekly(*home);
        }
        //view tasks by priority
        else if(Prompt.getSelection() == "4"){
            string userPriority;
            cout << "Please enter a priority category (Completed, Uncompleted, All): " << endl;
            cin >> userPriority;

            view.viewPriority(*home, userPriority);
        }
        //edit tasks
        else if(Prompt.getSelection() == "5"){
            Prompt.taskEditorPrompt();
        }
    }while(Prompt.getSelection() != "Task--");

    delete home;

    return 0;
}

/*
cout << "Completed solo tasks: " << endl;
            
            for(unsigned int i = 0; i < home->soloTasks->getNumOfTasks(); i++){
                if(home->soloTasks->)
            }
            */