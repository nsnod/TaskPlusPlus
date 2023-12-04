#include "../headers/view.h"
#include "gtest/gtest.h"

TEST(View, testingSort) {
    Home admin;

    vector<string> listInput{"The Best List", "slkjl"};
    admin.createNewList(listInput);

    vector<string> taskInputs1{"Name1", "Low", "05/19/23", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs2{"Name2", "High", "02/19/24", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs3{"Name3", "Medium", "11/19/23", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs4{"Name99", "Low", "12/19/21", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs5{"Name5", "High", "09/19/23", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs6{"Name6", "High", "01/19/23", "11/18/23", "Description", "The Best List"};

    admin.createNewTask(taskInputs1);
    admin.createNewTask(taskInputs2);
    admin.createNewTask(taskInputs3);
    admin.createNewTask(taskInputs4);
    admin.createNewTask(taskInputs5);
    admin.createNewTask(taskInputs6);

    TaskList *theBestList = admin.findTaskList("The Best List");
    theBestList->findTask("Name3")->switchCompleteStatus();
    theBestList->findTask("Name99")->switchCompleteStatus();
    theBestList->findTask("Name5")->switchCompleteStatus();

    View v1;
    
    v1.viewPriority(admin, "Completed");
    cout << endl;
    v1.viewPriority(admin, "Uncompleted");
    cout << endl;
    v1.viewPriority(admin, "All");
    cout << endl;
}