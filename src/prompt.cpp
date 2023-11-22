#include "../headers/prompt.h"

string prompt::getSelection() const{
    return this->selection;
}

void prompt::setSelection(){
    

    string userChoice = "";
    getline(cin,userChoice);
    
    while (userChoice != "1" && userChoice != "2" && userChoice != "3" && userChoice != "4" && userChoice != "5" && userChoice != "6" && userChoice != "Task--"){ 
        cout << "INVALID INPUT: Please enter 1-6 or \"Task--\" to exit terminal: ";
        getline(cin,userChoice);
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
    cout << "(Type \"Task--\" - to exit terminal)" << endl << endl;
    cout << "Please make your selection (Input corresponding numerical value): ";
    this->setSelection();
    


}

vector<string> prompt::newTaskPrompt(/*const Home& userHome*/){
    vector<string> userData;
    string title = "", desc = "", priority = "", dueDate = "", assignedDate = "";
        
    cout << "Please enter the name of the new task: ";
    getline(cin, title);
    
    while(priority != "High" && priority != "Medium" && priority != "Low"){
        cout << "Please enter the priority of the new task (\"High\", \"Medium\",\"Low\"): ";
        getline(cin,priority);
    }

    while(dueDate.at(2) != '/' || dueDate.at(5) != '/' || !(isdigit(dueDate.at(0))) || !(isdigit(dueDate.at(1))) || !(isdigit(dueDate.at(3))) || !(isdigit(dueDate.at(4))) || !(isdigit(dueDate.at(6))) || !(isdigit(dueDate.at(7)))){
        cout << "Please enter the due date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
        getline(cin,dueDate);
    }
    
    cout << "Please enter the description of the new task: ";
    getline(cin, desc);

    string assignToATask = "";
    cout << "Would you like to assign this task? Type Y/N: ";

    getline(cin,assignToATask);

    while(assignToATask != "Y" && assignToATask != "N"){
        cout << "Please Enter Y for yes or N for to assign task to a task list: ";
        getline(cin,assignToATask);
    }

    if(assignToATask == "Y"){
        string userListChoice;
        cout << "Please select (Input corresponding numerical value from the below options): ";
        getline(cin,userListChoice);
        //userHome.viewLists();

        while(!isdigit(userListChoice.at(0))){
            cout << "Please select (Input corresponding numerical value from the below options): ";
            getline(cin,userListChoice);
        }
        assignedDate = userListChoice;
    }

    userData.push_back(title);
    userData.push_back(priority);
    userData.push_back(dueDate);
    userData.push_back(desc);
    userData.push_back(assignedDate);

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