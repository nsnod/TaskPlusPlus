#include "../headers/prompt.h"

enum TaskAlias{ //Youtube: The Cherno: ENUMS in C++//
    TaskQ = 7
}


prompt::prompt(){
    this->selection = 0;
}




void prompt::setSelection(){
    int userSelection;
    cin >> userSelection;

    while (cin.fail() || userChoice > 7 || userChoice < 0){ 

        if(cin.fail()){
            cin.clear();
            cin.ignore();
        }

        cout << "INVALID INPUT: Please enter 1-6 or \"TaskQ\" to exit termal";
        cin >> userSelection;
    }
        
    selection = userChoice;
}

void prompt::printMainMenu(){

    cout << "Task++" << endl;
    cout << "Select your option below (Number or Name)" << endl;
    cout << "1. New Task" << endl;
    cout << "2. New Task List" << endl;
    cout << "3. View Task Archive" << endl;
    cout << "4. New Upcoming Tasks" << endl;
    cout << "5. View Weekly Tasks" << endl;
    cout << "6.Reccomend Weekly Schedule" << endl;
    cout << "(Type Task - to exit terminal)" << endl << endl;
    cout << "Please make your selection (Input corresponding numerical value): ";
    this->setSelection();
    
    cout << endl;

    
}

void prompt::newTaskPrompt(){
    //fill out with prompt
}

void prompt::newListPrompt(){
    //fill out with prompt
}

void prompt::taskEditorPrompt(){
    //fill out with prompt
}
void prompt::listEditorPrompt(){
    //fill out with prompt    
}
void prompt::viewArchivePrompt(){
    //fill out with prompt
}
void prompt::viewWeeklyTasksPrompt(){
    //fill out with prompt
}
void prompt::viewUpcomingTasksPrompt(){
    //fill out with prompt
}
void prompt::recommendWeeklySchedulePrompt(){
    //fill out with prompt
}