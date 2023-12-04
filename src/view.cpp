#include <iostream>
#include "../headers/view.h"
#include "../headers/home.h"
#include "../headers/taskList.h"
#include "../headers/task.h"

using namespace std;

void View::viewPriority(string userChoice) const {
    if (Home::isEmpty() != true) {
        if (userChoice == "Completed") {
            
        }
        else if (userChoice == "Uncompleted") {

        }
        else if (userChoice == "All") {

        }
    }
    else {
        cout << "-------------NO TASKS AVAILABLE-------------" << endl;
    }
}

void View::viewOverall() const {
    
}