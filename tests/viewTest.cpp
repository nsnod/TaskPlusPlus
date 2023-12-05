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

TEST(View, overallView) {
    Home admin;

    vector<string> listInput{"The Best List", "the best description"};
    vector<string> listInput2{"3", "the best description"};
    admin.createNewList(listInput);
    admin.createNewList(listInput2);

    vector<string> taskInputs1{"task one", "Low", "05/19/23", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs2{"task two", "High", "02/19/24", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs3{"task three", "Medium", "11/19/24", "11/18/23", "Description", "The Best List"};
    vector<string> taskInputs4{"task four", "Low", "12/19/24", "11/18/23", "Description", "3"};
    vector<string> taskInputs5{"task five", "High", "09/19/21", "11/18/23", "Description", "3"};
    vector<string> taskInputs6{"task six", "High", "01/19/23", "11/18/23", "Description", "3"};


    admin.createNewTask(taskInputs1);
    admin.createNewTask(taskInputs2);
    admin.createNewTask(taskInputs3);
    admin.createNewTask(taskInputs4);
    admin.createNewTask(taskInputs5);
    admin.createNewTask(taskInputs6);

    TaskList *theBestList = admin.findTaskList("The Best List");
    theBestList->findTask("task one")->switchCompleteStatus();
    
    View v1;
    
    v1.viewOverall(admin);
}

TEST(View, weeklyView) {
    Home admin;
    admin.createNewList({"The Best List", "Description"});
    admin.createNewList({"Random List", "Description"});

    vector<string> taskInputs1{"Name1", "Low", "05/19/23", "12/03/23", "Description", "The Best List"};
    vector<string> taskInputs2{"Name2", "Medium", "05/20/23", "12/03/23", "Description", "The Best List"};
    vector<string> taskInputs3{"Name3", "High", "05/21/23", "12/03/23", "Description", "The Best List"};

    vector<string> taskInputs4{"Name4", "Low", "05/24/23", "12/04/23", "Description", "Random List"};
    vector<string> taskInputs5{"Name5", "Medium", "05/25/23", "12/04/23", "Description", "Random List"};
    vector<string> taskInputs6{"Name6", "High", "05/26/23", "12/04/23", "Description", "Random List"};

    vector<string> taskInputs7{"Name7", "Low", "05/27/23", "12/05/23", "Description", ""};
    vector<string> taskInputs8{"Name8", "Medium", "05/28/23", "12/05/23", "Description", ""};
    vector<string> taskInputs9{"Name9", "High", "05/29/23", "12/05/23", "Description", ""};

    vector<string> taskInputs10{"Name10", "Low", "05/30/23", "12/06/23", "Description", "The Best List"};
    vector<string> taskInputs11{"Name11", "Medium", "05/31/23", "12/06/23", "Description", "The Best List"};
    vector<string> taskInputs12{"Name12", "High", "06/01/23", "12/06/23", "Description", "The Best List"};

    vector<string> taskInputs13{"Name13", "Low", "06/02/23", "12/07/23", "Description", "Random List"};
    vector<string> taskInputs14{"Name14", "Medium", "06/03/23", "12/07/23", "Description", "Random List"};
    vector<string> taskInputs15{"Name15", "High", "06/04/23", "12/07/23", "Description", "Random List"};

    vector<string> taskInputs16{"Name16", "Low", "06/05/23", "12/08/23", "Description", ""};
    vector<string> taskInputs17{"Name17", "Medium", "06/06/23", "12/08/23", "Description", ""};
    vector<string> taskInputs18{"Name18", "High", "06/07/23", "12/08/23", "Description", ""};

    vector<string> taskInputs19{"Name19", "Low", "06/08/23", "12/09/23", "Description", "Random List"};
    vector<string> taskInputs20{"Name20", "Medium", "06/09/23", "12/09/23", "Description", "Random List"};
    vector<string> taskInputs21{"Name21", "High", "06/10/23", "12/09/23", "Description", "Random List"};

    vector<string> taskInputs22{"Name22", "Low", "06/15/23", "12/10/23", "Description", "The Best List"};
    vector<string> taskInputs23{"Name23", "Medium", "06/16/23", "12/11/23", "Description", "Random List"};
    vector<string> taskInputs24{"Name24", "High", "06/17/23", "12/12/23", "Description", ""};
    vector<string> taskInputs25{"Name25", "Low", "06/18/23", "12/13/23", "Description", "Random List"};
    vector<string> taskInputs26{"Name26", "Medium", "06/19/23", "12/14/23", "Description", "The Best List"};

    admin.createNewTask(taskInputs1);
    admin.createNewTask(taskInputs2);
    admin.createNewTask(taskInputs3);
    admin.createNewTask(taskInputs4);
    admin.createNewTask(taskInputs5);
    admin.createNewTask(taskInputs6);
    admin.createNewTask(taskInputs7);
    admin.createNewTask(taskInputs8);
    admin.createNewTask(taskInputs9);
    admin.createNewTask(taskInputs10);
    admin.createNewTask(taskInputs11);
    admin.createNewTask(taskInputs12);
    admin.createNewTask(taskInputs13);
    admin.createNewTask(taskInputs14);
    admin.createNewTask(taskInputs15);
    admin.createNewTask(taskInputs16);
    admin.createNewTask(taskInputs17);
    admin.createNewTask(taskInputs18);
    admin.createNewTask(taskInputs19);
    admin.createNewTask(taskInputs20);
    admin.createNewTask(taskInputs21);
    admin.createNewTask(taskInputs22);
    admin.createNewTask(taskInputs23);
    admin.createNewTask(taskInputs24);
    admin.createNewTask(taskInputs25);
    admin.createNewTask(taskInputs26);

    View v1;

    v1.viewWeekly(admin);
}