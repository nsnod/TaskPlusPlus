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

    Prompt.printMainMenu();

    if(Prompt.getSelection() == "1"){
        Prompt.newTaskPrompt(home);
    }

    delete home;
    return 0;
}