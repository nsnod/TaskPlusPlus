#include "../headers/prompt.h"

string prompt::getSelection() const{ //TESTED//
    return this->selection;
}

void prompt::setSelection(const string& payload){ //ONLY FOR TESTING//
    this->selection = payload;

}

void prompt::printSeparator(int length) {
    for (int i = 0; i < length; ++i) {
        cout << "=";
    }
    cout << endl;
}

void prompt::displayHorizontalLine(int length = 30, char symbol = '-') {
    cout << setfill(symbol) << setw(length) << "" << setfill(' ') << endl;
}

void prompt::clearScreen() {
#ifdef _WIN32
    system("CLS"); // For Windows
#else
    // Assume Unix-like system
    system("clear"); // For Linux/Unix
#endif
}

void prompt::setSelection(){ //TESTED//
    

    string userChoice = "";
    getline(cin,userChoice);
    
    while (userChoice != "1" && userChoice != "2" && userChoice != "3" && userChoice != "4" && userChoice != "5" && userChoice != "Task--"){ 
        cout << "INVALID INPUT: Please enter 1-6 or \"Task--\" to exit terminal:";
        getline(cin,userChoice);
    }
        
    this->selection = userChoice;
}

void prompt::printMainMenu(){ //TESTED//

    printLogos("printMainMenu");

    cout << "==============================================" << endl;
    cout << "             Task++ Menu Options             " << endl;
    cout << "==============================================" << endl;
    cout << "1. Make a New Task" << endl;
    cout << "2. Make a New Task List" << endl;
    cout << "3. View Weekly Tasks" << endl;
    cout << "4. View Overall Tasks" << endl;
    cout << "5. View Tasks by Priority" << endl;
    cout << "==============================================" << endl;
    cout << "(Type \"Task--\" to exit the terminal)" << endl;
    cout << "==============================================" << endl;
    cout << "Please select an option (Enter the corresponding number): ";
    this->setSelection();
  
}

void prompt::newTaskPrompt(Home* userHome) const {
    vector<string> userData;
    string title = "", desc = "", priority = "", dueDate = "", assignedDate = "", userListChoice = "",assignToList = "";

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
    
    do{
        cout << "Please Enter Y for yes or N for no to assign task to a task list: ";
        getline(cin,assignToList);
    }while(assignToList != "Y" && assignToList != "N" && assignToList != "y" && assignToList != "n"); //checks if user properly enter y or n, to see if they want to assign it to a list//

    
    if(assignToList == "Y"){ 

        userHome->viewLists(); //lists out existing task lists !!FIX NOT DISPLAYING!!
        cout << "Please select list: ";
        getline(cin,userListChoice);

        while(userHome->findTaskList(userListChoice) == nullptr){ //checks if list exist//
            userHome->viewLists();
            cout << "Please select a existing list (listed above): ";
            getline(cin,userListChoice);
        }
    }

    userData.push_back(title);
    userData.push_back(priority);
    userData.push_back(dueDate);
    userData.push_back(assignedDate);
    userData.push_back(desc);
    userData.push_back(userListChoice);
    

    userHome->createNewTask(userData);
}

void prompt::newListPrompt(Home* h) const { //WORKS//

    string listTitle = "", listDescription = "", addTasks = "";
    cout << "==============================================" << endl;
    cout << "Enter List Title: ";
    getline(cin, listTitle);
    cout << "Enter Description: ";
    getline(cin, listDescription);
    cout << "==============================================" << endl;

    h->createNewList({listTitle,listDescription});
 
}

void prompt::taskEditorPrompt(Task* userTask, TaskList* taskList){
    vector<string> userChanges;
    string targetTask = "", action = "", newVal = "";
    string choice = "";
    string toLeave = "";

    
    printLogos("taskEditorPrompt");
    
    printSeparator(55);
    cout << "Edit your task below!" << endl;

    cout << "1) Edit Title: " << userTask->getName() << endl; // Target task name
    cout << "2) Edit Priority: " << userTask->getPriority() << endl; // Target task priority
    cout << "3) Edit Due Date: " << userTask->getFullDueDate() << endl; // Target task FULL due date
    cout << "4) Edit Assigned Date: " << userTask->getFullAssignedDate() << endl; // Target task assigned date
    cout << "5) Edit Description: " << userTask->getDescription() << endl; // Target task description

    targetTask = userTask->getName();

    printSeparator(55);

    do {
        cout << "Please select an action to edit (enter the corresponding number): ";
        getline(cin, choice);
    } while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5");

    displayHorizontalLine();

    if (choice == "1") {
        action = "Name";
        cout << "Enter the new name: ";
        getline(cin, newVal);

    } else if (choice == "2") {
        action = "Priority";
        do {
            cout << "Enter the new priority (\"High\", \"Medium\", \"Low\"): "; // Check for valid priority
            getline(cin, newVal);
        } while (newVal != "High" && newVal != "Medium" && newVal != "Low" && newVal != "high" && newVal != "medium" && newVal != "low");

    } else if (choice == "3") {
        action = "Full Due Date";

        do {
            cout << "Enter the new date (format mm/dd/yy): ";
            getline(cin, newVal);
        } while (newVal.size() != 8 || newVal[2] != '/' || newVal[5] != '/' || !isdigit(newVal[0]) || !isdigit(newVal[1]) || !isdigit(newVal[3]) || !isdigit(newVal[4]) || !isdigit(newVal[6]) || !isdigit(newVal[7]));

    } else if (choice == "4") {
        action = "Full Assigned Date";

        do {
            cout << "Enter the new assigned date (format mm/dd/yy): ";
            getline(cin, newVal);
        } while (newVal.size() != 8 || newVal[2] != '/' || newVal[5] != '/' || !isdigit(newVal[0]) || !isdigit(newVal[1]) || !isdigit(newVal[3]) || !isdigit(newVal[4]) || !isdigit(newVal[6]) || !isdigit(newVal[7]));
    } else if (choice == "5") {
        action = "Description";
        cout << "Enter the new description: ";
        getline(cin, newVal);
    }

    displayHorizontalLine();

    taskList->editTask(targetTask, action, newVal);

    cout << "New " << action << ": " << newVal << endl;

    do{
        cout << "Type \"Task--\" to leave: ";
        getline(cin,toLeave);
    }while(toLeave != "Task--");

}

void printSeparator(int length) {
    for (int i = 0; i < length; ++i) {
        cout << "=";
    }
    cout << endl;
}

void prompt::listEditorPrompt(Home* h) {
    string choice = "";
    string action = "";
    string payload = "";
    string userList = "";

    printLogos("listEditorPrompt");
    
    displayHorizontalLine(50);

    h->viewLists();

    cout << "Please Select a list to edit: ";
    getline(cin,userList);

    while(h->findTaskList(userList) == nullptr){
        h->viewLists();
        cout << "Please enter a valid list";
        getline(cin,userList);
    }

    


    cout << "Edit the List Below!" << endl;

    displayHorizontalLine(50); // Print a separator

    cout << "1) " << userList << endl;
    cout << "2) " << h->findTaskList(userList)->getListDescription() << endl;

    do {
        cout << "Please Type 1 to edit your list name or Type 2 to edit your list description: ";
        getline(cin, choice);
    } while (choice != "1" && choice != "2");

    if (choice == "1") {
        action = "Name";
        cout << "Enter new Title: ";
        getline(cin, payload);
    } else {
        action = "Description";
        cout << "Enter new description: ";
        getline(cin, payload);
    }

    h->editList(userList,action,payload);
    
}


void prompt::viewWeekly(View* mainView, Home* userHome) {
    string choice = "";

    mainView->viewWeekly(*userHome);

    cout << "Would you like to select a task to edit? (Enter 'Yes' or 'No'): ";
    getline(cin, choice);

    while (choice != "yes" && choice != "Yes" && choice != "no" && choice != "No") {
        cout << "Please enter a valid choice (Yes or No): ";
        getline(cin, choice);
    }

    if (choice == "no" || choice == "No") {
        cout << "See ya!" << endl;
        return;
    }

    cout << endl;

    string taskChoice = "";
    Task* tempTask = nullptr;
    TaskList* tempTaskList = nullptr;

    int rev = 0;

    while (tempTask == nullptr) {

        if (rev == 0) {
            cout << "Please select a task: ";
            rev++;
        } else {
            cout << "Please select a valid task: ";
        }

        getline(cin, taskChoice);

        if (userHome->findParentList(taskChoice) != nullptr) {
            tempTaskList = userHome->findParentList(taskChoice);
            tempTask = tempTaskList->findTask(taskChoice);
        }
    }

    cout << endl;

    string userOption = "0";

    printSeparator(23); // Print a line separator
    cout << "   Edit Options" << endl;
    printSeparator(23); // Print a line separator

    cout << "1.) Edit a task" << endl << endl;
    cout << "2.) Delete a task" << endl << endl;
    cout << "3.) Mark a task as complete" << endl << endl;
    cout << "4.) Back out" << endl;

    printSeparator(23); // Print a line separator

    int rev2 = 0; // Counter for loop to choose output//

    do {
        if (rev2 == 0) {
            cout << "Choose an option (Enter 1-4): ";
            rev2++;
        } else {
            cout << "Please choose a valid option (Enter 1-4): ";
        }
        getline(cin, userOption);

    } while (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4");

    if (userOption == "4") {
        cout << "See ya!" << endl;
        return;
    } else if (userOption == "3") {
        if (tempTask->getCompleteStatus() == true) { // If task is already marked as complete//
            cout << "Task is already complete" << endl;
            return;
        }

        tempTask->switchCompleteStatus();
        cout << "Task successfully marked as complete" << endl;
    } else if (userOption == "2") {
        tempTaskList->removeTask(taskChoice);
        cout << "Task successfully deleted" << endl;
    } else {
        clearScreen(); // Assuming this function clears the screen
        taskEditorPrompt(tempTask, tempTaskList);
    }

    tempTaskList = nullptr;
    tempTask = nullptr;

    
}

void prompt::viewPriority(View* mainView, Home* userHome){
    string userDifficulty = "";
    string choice = "";

    cout << "Which priority tasks would you like to view (\"High\",\"Medium\",\"Low\"): ";
    getline(cin,userDifficulty);

    while(userDifficulty != "High" && userDifficulty != "Medium" && userDifficulty != "Low" && userDifficulty != "high" && userDifficulty != "medium" && userDifficulty!= "low"){
        cout << "Please choose (\"High\",\"Medium\",\"Low\"): ";
        getline(cin,userDifficulty);
    }

    mainView->viewPriority(*userHome,userDifficulty); //Uncompleted, Completed, All//
    cout << "Would you like to select a task to edit? (Enter 'Yes' or 'No'): ";
    getline(cin, choice);

    while (choice != "yes" && choice != "Yes" && choice != "no" && choice != "No") {
        cout << "Please enter a valid choice (Yes or No): ";
        getline(cin, choice);
    }

    if (choice == "no" || choice == "No") {
        cout << "See ya!" << endl;
        return;
    }

    cout << endl;

    string taskChoice = "";
    Task* tempTask = nullptr;
    TaskList* tempTaskList = nullptr;

    int rev = 0;

    while (tempTask == nullptr) {

        if (rev == 0) {
            cout << "Please select a task: ";
            rev++;
        } else {
            cout << "Please select a valid task: ";
        }

        getline(cin, taskChoice);

        if (userHome->findParentList(taskChoice) != nullptr) {
            tempTaskList = userHome->findParentList(taskChoice);
            tempTask = tempTaskList->findTask(taskChoice);
        }
    }

    cout << endl;

    string userOption = "0";

    printSeparator(23); // Print a line separator
    cout << "   Edit Options" << endl;
    printSeparator(23); // Print a line separator

    cout << "1.) Edit a task" << endl << endl;
    cout << "2.) Delete a task" << endl << endl;
    cout << "3.) Mark a task as complete" << endl << endl;
    cout << "4.) Back out" << endl;

    printSeparator(23); // Print a line separator

    int rev2 = 0; // Counter for loop to choose output//

    do {
        if (rev2 == 0) {
            cout << "Choose an option (Enter 1-4): ";
            rev2++;
        } else {
            cout << "Please choose a valid option (Enter 1-4): ";
        }
        getline(cin, userOption);

    } while (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4");

    if (userOption == "4") {
        cout << "See ya!" << endl;
        return;
    } else if (userOption == "3") {
        if (tempTask->getCompleteStatus() == true) { // If task is already marked as complete//
            cout << "Task is already complete" << endl;
            return;
        }

        tempTask->switchCompleteStatus();
        cout << "Task successfully marked as complete" << endl;
    } else if (userOption == "2") {
        tempTaskList->removeTask(taskChoice);
        cout << "Task successfully deleted" << endl;
    } else {
        clearScreen(); // Assuming this function clears the screen
        taskEditorPrompt(tempTask, tempTaskList);
    }

    tempTaskList = nullptr;
    tempTask = nullptr;

    


    
    //fill out with prompt
}

void prompt::viewOverall(View* mainView, Home* userHome){

    mainView->viewOverall(*userHome);
    string choice = "";

   cout << "Would you like to select a task to edit? (Enter 'Yes' or 'No'): ";
    getline(cin, choice);

    while (choice != "yes" && choice != "Yes" && choice != "no" && choice != "No") {
        cout << "Please enter a valid choice (Yes or No): ";
        getline(cin, choice);
    }

    if (choice == "no" || choice == "No") {
        cout << "See ya!" << endl;
        return;
    }

    cout << endl;

    string taskChoice = "";
    Task* tempTask = nullptr;
    TaskList* tempTaskList = nullptr;

    int rev = 0;

    while (tempTask == nullptr) {

        if (rev == 0) {
            cout << "Please select a task: ";
            rev++;
        } else {
            cout << "Please select a valid task: ";
        }

        getline(cin, taskChoice);

        if (userHome->findParentList(taskChoice) != nullptr) {
            tempTaskList = userHome->findParentList(taskChoice);
            tempTask = tempTaskList->findTask(taskChoice);
        }
    }

    cout << endl;

    string userOption = "0";

    printSeparator(23); // Print a line separator
    cout << "   Edit Options" << endl;
    printSeparator(23); // Print a line separator

    cout << "1.) Edit a task" << endl << endl;
    cout << "2.) Delete a task" << endl << endl;
    cout << "3.) Mark a task as complete" << endl << endl;
    cout << "4.) Back out" << endl;

    printSeparator(23); // Print a line separator

    int rev2 = 0; // Counter for loop to choose output//

    do {
        if (rev2 == 0) {
            cout << "Choose an option (Enter 1-4): ";
            rev2++;
        } else {
            cout << "Please choose a valid option (Enter 1-4): ";
        }
        getline(cin, userOption);

    } while (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4");

    if (userOption == "4") {
        cout << "See ya!" << endl;
        return;
    } else if (userOption == "3") {
        if (tempTask->getCompleteStatus() == true) { // If task is already marked as complete//
            cout << "Task is already complete" << endl;
            return;
        }

        tempTask->switchCompleteStatus();
        cout << "Task successfully marked as complete" << endl;
    } else if (userOption == "2") {
        tempTaskList->removeTask(taskChoice);
        cout << "Task successfully deleted" << endl;
    } else {
        clearScreen(); // Assuming this function clears the screen
        taskEditorPrompt(tempTask, tempTaskList);
    }

    tempTaskList = nullptr;
    tempTask = nullptr;

    

}



void prompt::printLogos(const string& logoChoice) const{
    

    if(logoChoice == "printMainMenu"){
        cout << R"(
  ______           __                
 /_  __/___ ______/ /__     __    __ 
  / / / __ `/ ___/ //_/  __/ /___/ /_
 / / / /_/ (__  ) ,<    /_  __/_  __/
/_/  \__,_/____/_/|_|    /_/   /_/   
)";
    cout << endl;
        

    }
    else if(logoChoice == "newTaskPrompt"){
        cout << R"(
        _   __                ______           __      
       / | / /__ _      __   /_  __/___ ______/ /__    
      /  |/ / _ \ | /| / /    / / / __ `/ ___/ //_/    
     / /|  /  __/ |/ |/ /    / / / /_/ (__  ) ,<       
    /_/ |_/\___/|__/|__/    /_/  \__,_/____/_/|_|      
                                                   
)";
    cout << endl;
                        
    }

    else if(logoChoice == "newListPrompt"){
        cout << R"(
        _   __                __    _      __ 
       / | / /__ _      __   / /   (_)____/ /_
      /  |/ / _ \ | /| / /  / /   / / ___/ __/
     / /|  /  __/ |/ |/ /  / /___/ (__  ) /_  
    /_/ |_/\___/|__/|__/  /_____/_/____/\__/  
    )";
    cout << endl;
        

    }
    else if(logoChoice == "taskEditorPrompt"){
        cout << R"(
          ______           __      ______    ___ __            
         /_  __/___ ______/ /__   / ____/___/ (_) /_____  _____
          / / / __ `/ ___/ //_/  / __/ / __  / / __/ __ \/ ___/
         / / / /_/ (__  ) ,<    / /___/ /_/ / / /_/ /_/ / /    
        /_/  \__,_/____/_/|_|  /_____/\__,_/_/\__/\____/_/     
        )";
    cout << endl;
        

    }
    else if(logoChoice == "listEditorPrompt"){
        cout << R"(
        __    _      __     ______    ___ __            
       / /   (_)____/ /_   / ____/___/ (_) /_____  _____
      / /   / / ___/ __/  / __/ / __  / / __/ __ \/ ___/
     / /___/ (__  ) /_   / /___/ /_/ / / /_/ /_/ / /    
    /_____/_/____/\__/  /_____/\__,_/_/\__/\____/_/     
    )";
        

    }
    else if(logoChoice == "viewWeekly"){
        cout << R"(
     _    ___                 _       __          __   __     
    | |  / (_)__ _      __   | |     / /__  ___  / /__/ /_  __
    | | / / / _ \ | /| / /   | | /| / / _ \/ _ \/ //_/ / / / /
    | |/ / /  __/ |/ |/ /    | |/ |/ /  __/  __/ ,< / / /_/ / 
    |___/_/\___/|__/|__/     |__/|__/\___/\___/_/|_/_/\__, /  
                                                 /____/   
    )";
        


    }
    else if(logoChoice == "viewPriority"){
        cout << R"(
    _    ___                 ____       _            _ __       
    | |  / (_)__ _      __   / __ \_____(_)___  _____(_) /___  __
    | | / / / _ \ | /| / /  / /_/ / ___/ / __ \/ ___/ / __/ / / /
    | |/ / /  __/ |/ |/ /  / ____/ /  / / /_/ / /  / / /_/ /_/ / 
    |___/_/\___/|__/|__/  /_/   /_/  /_/\____/_/  /_/\__/\__, /  
                                                    /____/   
    )";


    }
    else if(logoChoice == "viewOverall"){
        cout << R"(
     _    ___                 ____                        ____
    | |  / (_)__ _      __   / __ \_   _____  _________ _/ / /
    | | / / / _ \ | /| / /  / / / / | / / _ \/ ___/ __ `/ / / 
    | |/ / /  __/ |/ |/ /  / /_/ /| |/ /  __/ /  / /_/ / / /  
    |___/_/\___/|__/|__/   \____/ |___/\___/_/   \__,_/_/_/   
                                                          
    )";

    }
    else{
        

    }



}


