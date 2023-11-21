#include "../headers/prompt.h"

enum TaskAlias{ //Youtube: The Cherno: ENUMS in C++//
    TaskQ = 7
};


prompt::prompt(){
    this->selection = 0;
}




void prompt::setSelection(){
    int userChoice;
    cin >> userChoice;

    while (cin.fail() || userChoice > 7 || userChoice < 0){ 

        if(cin.fail()){
            cin.clear();
            cin.ignore();
        }

        cout << "INVALID INPUT: Please enter 1-6 or \"TaskQ\" to exit termal";
        cin >> userChoice;
    }
        
    this->selection = userChoice;
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

vector<string> prompt::newTaskPrompt(){
    vector<string> userData;

    string title = "", desc = "", priority = "", dueDate = "", assignedDate = "";

    if(cin.peek() != EOF){ //reference c++.com//
        cin.clear();

    }
    
    while(title == ""){
        cout << "Please enter the name of the new task: ";
        getline(cin, title);
        cout << endl;
    }

    cin.ignore();
    
    while(priority != "High" || priority != "Medium" || priority != "Low"){
        cout << "Please enter the priority of the new task: ";
        cin >> priority;
        cout << endl;
    }

    cin.ignore();

    while(dueDate.size() != 8 || dueDate.at(2) != '/' || dueDate.at(5) != '/' || !(isdigit(dueDate.at(0))) || !(isdigit(dueDate.at(1))) || !(isdigit(dueDate.at(3))) || !(isdigit(dueDate.at(4))) || !(isdigit(dueDate.at(6))) || !(isdigit(dueDate.at(7)))){
        cout << "Please enter the due date of the task in the format MM/DD/YY: ";
        cin >> dueDate;
        cout << endl;

    }

    while(assignedDate.size() != 8 || assignedDate.at(2) != '/' || assignedDate.at(5) != '/' || !(isdigit(assignedDate.at(0))) || !(isdigit(assignedDate.at(1))) || !(isdigit(assignedDate.at(3))) || !(isdigit(assignedDate.at(4))) || !(isdigit(assignedDate.at(6))) || !(isdigit(assignedDate.at(7)))){
        cout << "Please enter the assigned date of the task: ";
        cin >> assignedDate;
        cout << endl;

    }

    cin.ignore();

    while(desc == ""){
        cout << "Please enter the description of the new task: ";
        getline(cin, desc);
        cout << endl;
    }

    cin.ignore();

    userData.push_back(title);
    userData.push_back(priority);
    userData.push_back(dueDate);
    userData.push_back(assignedDate);
    userData.push_back(desc);

    return userData;
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