#include "../headers/prompt.h"

string prompt::getSelection() const{
    return this->selection;
}




void prompt::setSelection(){
    cin.ignore();
    string userChoice = "";
    getline(cin,userChoice);
    cin.ignore();
    
    while (userChoice != "1" && userChoice != "2" && userChoice != "3" && userChoice != "4" && userChoice != "5" && userChoice != "6" && userChoice != "Task--"){ 
        cout << "INVALID INPUT: Please enter 1-6 or \"Task--\" to exit terminal: ";
        getline(cin,userChoice);
        cin.clear();
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
    
    cout << endl;


}

vector<string> prompt::newTaskPrompt(/*const Home& userHome*/){
    vector<string> userData;

    

    string title = "", desc = "", priority = "", dueDate = "", assignedDate = "";
        
    cout << "Please enter the name of the new task: ";
    cin.ignore();
    getline(cin, title);
    
    cout << endl;
        
    

    
    
    while(priority != "High" && priority != "Medium" && priority != "Low" && priority != "high" && priority != "medium" && priority != "low"){
        cout << "Please enter the priority of the new task: ";
        cin >> priority;
        cout << endl;

    }

    while(/*cin.peek() != EOF ||*/ dueDate.size() != 8 || dueDate.at(2) != '/' || dueDate.at(5) != '/' || !(isdigit(dueDate.at(0))) || !(isdigit(dueDate.at(1))) || !(isdigit(dueDate.at(3))) || !(isdigit(dueDate.at(4))) || !(isdigit(dueDate.at(6))) || !(isdigit(dueDate.at(7)))){
        cout << "Please enter the due date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
        cin >> dueDate;
        cout << endl;

    }

    

    
    cout << "Please enter the description of the new task: ";
    cin.ignore();
    getline(cin, desc);
    cout << endl;
    

    string assignToATask = "";
    cout << "Would you like to assign this task? Y/N: ";

    cin >> assignToATask;

    while(assignToATask != "Y" && assignToATask != "N"){
        cout << "Please Enter Y for yes or N for to assign thit task to a task list: ";
        cin >> assignToATask;
        cout << endl;
    }

    if(assignToATask == "Y"){
        char userListChoice;
        cout << "Please select (Input corresponding numerical value from the below options): ";
        cin >> userListChoice;
        //userHome.viewLists();
        cout << endl;

        while(!isdigit(userListChoice) ){
            cout << "Please select (Input corresponding numerical value from the below options): ";
            cin >> userListChoice;
            cout << endl;
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