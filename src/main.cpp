<<<<<<< HEAD
//#pragma once
#include <iostream>

#include "../headers/home.h"
#include "../headers/prompt.h"
#include "../headers/recommender.h"
#include "../headers/task.h"
#include "../headers/taskList.h"
#include "../headers/upcoming.h"
#include "../headers/view.h"
#include "../headers/weekly.h"

using namespace std;

int main(){

    prompt Prompt;
    Home* home = new Home;

    do{
        Prompt.printMainMenu();

        if(Prompt.getSelection() == "1"){
            home->createNewTask(Prompt.newTaskPrompt(home));
        }

        else if(Prompt.GetSelection() == "2"){
            home->createNewList(Prompt.newListPrompt());
        }

        else if(Prompt.getSelection() == "3"){
            //what the fuck
        }

        else if(Prompt.getSelection() == "4"){
            
        }
    }while(Prompt.getSelection() != "Task--");


    delete home;
=======
#include <iostream>
#include "home.h"
#include "task.h"
#include "taskList.h"

using namespace std;

int main() {
        

>>>>>>> a91b7ed740d7c5af8caa460e3cbbb1cbbfc1a2f0
    return 0;
}