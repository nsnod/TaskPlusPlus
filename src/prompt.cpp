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

void prompt::printMainMenu() {

    prompt::printTaskPlusPlus();
    cout << "==============================================" << endl;
    cout << "             Task++ Menu Options             " << endl;
    cout << "==============================================" << endl;
    cout << "1. Make a New Task" << endl;
    cout << "2. Make a New Task List" << endl;
    cout << "4. View Weekly Tasks" << endl;
    cout << "5. View Overall Tasks" << endl;
    cout << "6. View Tasks by Priority" << endl;
    cout << "==============================================" << endl;
    cout << "(Type \"Task--\" to exit the terminal)" << endl;
    cout << "==============================================" << endl;
    cout << "Please select an option (Enter the corresponding number): ";
    this->setSelection();
  
}

vector<string> prompt::newTaskPrompt(const Home* userHome) const {
    vector<string> userData;
    string title = "", desc = "", priority = "", dueDate = "", assignedDate = "";

    cout << "    _   __                ______           __  " << endl;
    cout << "   / | / /__ _      __   /_  __/___ ______/ /__" << endl;
    cout << "  /  |/ / _ \\ | /| / /    / / / __ `/ ___/ //_/" << endl;
    cout << " / /|  /  __/ |/ |/ /    / / / /_/ (__  ) ,<   " << endl;
    cout << "/_/ |_/\\___/|__/|__/    /_/  \\__,_/____/_/|_|" << endl;


    cout << "Input Information as prompted!" << endl;
        
    cout << "Please enter the name of the new task: ";
    getline(cin, title);
    
    while(priority != "High" && priority != "Medium" && priority != "Low" && priority != "high" && priority != "medium" && priority != "low"){
        cout << "Please enter the priority of the new task (\"High\", \"Medium\",\"Low\"): ";
        getline(cin,priority);
    }

    do{
        cout << "Please enter the due date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
        getline(cin,dueDate);
    }while(dueDate.at(2) != '/' || dueDate.at(5) != '/' || !(isdigit(dueDate.at(0))) || !(isdigit(dueDate.at(1))) || !(isdigit(dueDate.at(3))) || !(isdigit(dueDate.at(4))) || !(isdigit(dueDate.at(6))) || !(isdigit(dueDate.at(7))));
    
    
    do{
        cout << "Please enter the assigned date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
        getline(cin,assignedDate);
    }while(assignedDate.at(2) != '/' || assignedDate.at(5) != '/' || !(isdigit(assignedDate.at(0))) || !(isdigit(assignedDate.at(1))) || !(isdigit(assignedDate.at(3))) || !(isdigit(assignedDate.at(4))) || !(isdigit(assignedDate.at(6))) || !(isdigit(assignedDate.at(7))));

    cout << "Please enter the description of the new task: ";
    getline(cin, desc);

    string assignToList = "";
    
    do{
        cout << "Please Enter Y for yes or N for no to assign task to a task list: ";
        getline(cin,assignToList);
    }while(assignToList != "Y" && assignToList != "N" && assignToList != "y" && assignToList != "n"); //checks if user properly enter y or n, to see if they want to assign it to a list//

    string userListChoice = "";
    if(assignToList == "Y"){ 

        userHome->viewLists(); //lists out existing task lists !!FIX NOT DISPLAYING!!
        cout << "Please select list: ";
        getline(cin,userListChoice);

        while(userHome->findTaskList(userListChoice) == nullptr){ //checks if list exist//
            cout << "Please select a existent list: "; 
            userHome->viewLists(); //lists out existing task lists !!FIX NOT DISPLAYING!!
            getline(cin,userListChoice);
        }
    }

    userData.push_back(title);
    userData.push_back(priority);
    userData.push_back(dueDate);
    userData.push_back(assignedDate);
    userData.push_back(desc);
    userData.push_back(userListChoice);
    

    return userData;
}

vector<string> prompt::newListPrompt() const { //WORKS//

    cout << "    _   __                __    _      __ " << endl;
    cout << "   / | / /__ _      __   / /   (_)____/ /_" << endl;
    cout << "  /  |/ / _ \\ | /| / /  / /   / / ___/ __/" << endl;
    cout << " / /|  /  __/ |/ |/ /  / /___/ (__  ) /_" << endl;
    cout << "/_/ |_/\___/|__/|__ /  /_____/_/____/\\__/" << endl;

    vector<string> userListData;

    string listTitle = "", listDescription = "", addTasks = "";
    cout << "==============================================" << endl;
    cout << "Enter List Title: ";
    getline(cin, listTitle);
    cout << "Enter Description: ";
    getline(cin, listDescription);
    cout << "==============================================" << endl;



    userListData.push_back(listTitle);
    userListData.push_back(listDescription);
    
   return userListData;
    
}

void prompt::taskEditorPrompt(Task* userTask, TaskList* taskList){
    vector<string> userChanges;
    string targetTask = "", action = "", newVal = "";
    string choice = "";

    cout << "Task Editor" << endl;
    cout << "Edit your task below!" << endl;

    cout << "1) " << userTask->getName() << endl; //target task name//
    cout << "2) " << userTask->getPriority() << endl; //target task priority//
    cout << "3) " << userTask->getFullDueDate() << endl; //target task FULL due date//
    cout << "4) " << userTask->getFullAssignedDate() << endl; //target task assigned date//
    cout << "5) " << userTask->getDescription() << endl; //target task description//

    targetTask = userTask->getName();

    do{
        cout << "Please select action of what you want to edit (enter numerical value): ";
        getline(cin,choice);
    }while(choice!= "1" && choice != "2" && choice != "3" && choice != "4" && choice !="5");

    if(choice =="1"){
        action = "Name";
        cout << "Enter new name: ";
        getline(cin,newVal); 

    }
    else if(choice =="2"){
        action = "Priority";
        do{
            cout << "Enter new priority(\"High\", \"Medium\",\"Low\"): "; //checks if valid priority//
            getline(cin,newVal);
        }while(newVal != "High" && newVal != "Medium" && newVal != "Low" && newVal != "high" && newVal != "medium" && newVal != "low");
        

    }
    else if(choice =="3"){
        action = "Full Due Date";

        do{
            cout << "Enter new date (format mm/dd/yy): ";
            getline(cin,newVal);
        }while(newVal.at(2) != '/' || newVal.at(5) != '/' || !(isdigit(newVal.at(0))) || !(isdigit(newVal.at(1))) || !(isdigit(newVal.at(3))) || !(isdigit(newVal.at(4))) || !(isdigit(newVal.at(6))) || !(isdigit(newVal.at(7))));

    }
    else if(choice =="4"){
        action = "Full Assigned Date";

        do{
            cout << "Enter new assigned date (format mm//dd/yy): ";
            getline(cin,newVal);
        }while(newVal.at(2) != '/' || newVal.at(5) != '/' || !(isdigit(newVal.at(0))) || !(isdigit(newVal.at(1))) || !(isdigit(newVal.at(3))) || !(isdigit(newVal.at(4))) || !(isdigit(newVal.at(6))) || !(isdigit(newVal.at(7))));
    }

    else if(choice == "5"){
        action = "Description";
        cout << "Enter new description: ";
        getline(cin,newVal);
    }
    
    taskList->editTask(targetTask, action, newVal);
}

void prompt::listEditorPrompt(TaskList* userList){ //untested//
    string choice = "";
    string action = "";
    string payload = "";
    cout << "List Editor" << endl;
    cout << "Edit the List Below!" << endl;

    cout << "1) " << userList->getListName() << endl;
    cout << "2) " << userList->getListDescription() << endl;

    do{
        cout << "Please Type 1 to edit your list name or Type 2 to edit your list description: ";
        getline(cin,choice);
    }while(choice != "1" && choice != "2");

    if(choice == "1"){
        action = "Name";
        cout << "Enter new Title: ";
        getline(cin,payload);
    }
    else{
        action = "Description";
        cout << "Enter new description: ";
        getline(cin,payload);
    }


}


void prompt::viewWeekly(View* mainView, Home* userHome){
    string choice = "";

    cout << "//   _    ___                 _       __          __   __     " << endl;
    cout << "//  | |  / (_)__ _      __   | |     / /__  ___  / /__/ /_  __" << endl;
    cout << "//  | | / / / _ \\ | /| / /  | | /| / / _ \\/ _ \\/ //_/ / / / /" << endl;
    cout << "//  | |/ / /  __/ |/ |/ /    | |/ |/ /  __/  __/ ,< / / /_/ / " << endl;
    cout << "//  |___/_/\\___/|__/|__/    |__/|__/\\___/\\___/_/|_/_/\\__, /  " << endl;
    cout << "//                                                   /____/   " << endl;

    mainView->viewWeekly(*userHome);

    cout << "Would you like to select a task to edit? (enter yes or no): ";
    getline(cin,choice);

    while(choice != "yes" && choice != "Yes" && choice != "no" && choice != "No" ){
        cout << "please enter valid choice (yes or no): ";
        getline(cin, choice);
    }
    
    if(choice == "no" || choice == "No"){
        return;
    }

    string taskChoice = "";
    Task* tempTask = nullptr;
    TaskList* tempTaskList = nullptr;

    int rev = 0;
        
    while(tempTask == nullptr){

        if(rev == 0){
        cout << "Please select a task: ";
        rev++;
        }
        else{
            cout << "Please select a valid task: ";
        }

        getline(cin,taskChoice);

        if(userHome->findParentList(taskChoice) != nullptr){
            tempTaskList = userHome->findParentList(taskChoice);
            tempTask = tempTaskList->findTask(taskChoice);
        } 
    }

    string userOption = "0";

    cout << "==== Edit Options ====" << endl;
    cout << "1.) Edit a task" << endl;
    cout << "2.) Delete a task" << endl;
    cout << "3.) Mark a task as complete " << endl;
    cout << "4.) Back out" << endl;
    cout << "======================" << endl;

    int rev2 = 0; //counter for loop to choose output//

    do{
        if(rev2 == 0 ){
            cout << "Choose a option (enter 1-4): ";
            rev2++;
        }
        else{
            cout << "Please choose a valid option (enter 1-4):";
        }
        getline(cin,userOption);

        
    }while(userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4");


    if(userOption == "4"){
        cout << "See ya!" << endl;
        return;
    }

    else if(userOption == "3"){
        if(tempTask->getCompleteStatus() == true){ //if task is already marked as complete//
            cout << "Task is already complete" << endl;
            return;
        }

        tempTask->switchCompleteStatus();
        cout << "Task successfully marked as complete" << endl;
    }

    else if(userOption == "2"){
        
        tempTaskList->removeTask(taskChoice);
        cout << "Task successfully deleted" << endl;

    }
    else{
        taskEditorPrompt(tempTask,tempTaskList);
    }

    tempTaskList = nullptr;
    tempTask = nullptr;

    // calls the function from weekly view class (outputs and calcs all days of week)
    // then this function will take input for if they want to select a task or back out
    // then this function will check if their task actually exists
    // then the user can choose to edit the task mark it as complete or delete the task
    // if they chose to edit then we call edit task prompt

}

void prompt::viewPriority(){
    //fill out with prompt
}

void prompt::viewOverall(){

}

void prompt::printTaskPlusPlus() {
    string asciiArt = R"(
  ______           __             
 /_  __/___ ______/ /__  __    __ 
  / / / __ `/ ___/ //_/_/ /___/ /_
 / / / /_/ (__  ) ,< /_  __/_  __/
/_/  \__,_/____/_/|_| /_/   /_/   
)";

    cout << asciiArt << endl;
}


