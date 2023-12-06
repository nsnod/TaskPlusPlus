#include "../headers/task.h"
#include "../headers/taskList.h"
#include "../headers/home.h"
#include "gtest/gtest.h"

//New list creation testing//

TEST(HomeCreateNewTask, listCreation) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription"};

    admin.createNewList(listInputs);

    EXPECT_TRUE((admin.findTaskList("The Best List"))->getListDescription() == "ListDescription");
}

//New Task creation assigned to list testing//

TEST(HomeCreateNewTask, newTaskAssignedToExampleListFound) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription"};
    vector<string> taskInputs{"Name", "High", "11/19/23", "11/18/23", "Description", "The Best List"};

    admin.createNewList(listInputs);
    admin.createNewTask(taskInputs);
    EXPECT_TRUE(((admin.findTaskList("The Best List"))->findTask("Name"))->getDescription() == "Description");
}

TEST(HomeCreateNewTask, newTaskAssignedToExampleListNotFound) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription"};
    vector<string> taskInputs{"Name", "High", "11/19/23", "11/18/23", "Description", "The Best List"};

    admin.createNewList(listInputs);
    admin.createNewTask(taskInputs);
    EXPECT_TRUE(((admin.findTaskList("The Best List"))->findTask("Doesn't exist")) == nullptr);
}

// New Task creation assigned to no list testing //

TEST(HomeCreateNewTask, newTaskWithNoAssignedListFound) {
    Home admin;

    vector<string> inputs{"Name", "High", "11/19/23", "11/18/23", "Description", ""};

    admin.createNewTask(inputs);

    EXPECT_TRUE((admin.findSoloTask("Name"))->getDescription() == "Description");
}

TEST(HomeCreateNewTask, newTaskWithNoAssignedListNotFound) {
    Home admin;

    vector<string> inputs{"Name", "High", "11/19/23", "11/18/23", "Description", ""};

    admin.createNewTask(inputs);

    EXPECT_TRUE(admin.findSoloTask("Doesn't exist") == nullptr);
}

// Testing edit //

TEST(HomeView, editingList) {
    TaskList *tL1 = new TaskList;
    TaskList *tL2 = new TaskList;

    tL1->editListName("List 1");
    tL2->editListName("List 2");

    EXPECT_TRUE(tL1->getListName() == "List 1");
    EXPECT_TRUE(tL2->getListName() == "List 2");

    delete tL1;
    delete tL2;
}

// Testing isEmpty //

TEST(HomeEmpty, isHomeEmpty) {
    Home emptyHome;

    EXPECT_TRUE(emptyHome.isEmpty() == true);
}

// Testing Delete List //

TEST(HomeDeleteList, deletingOneList) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription"};
    admin.createNewList(listInputs);

    EXPECT_FALSE(admin.findTaskList("The Best List") == nullptr);

    admin.deleteList("The Best List");

    EXPECT_TRUE(admin.findTaskList("The Best List") == nullptr);
}

TEST(HomeDeleteList, deletingTwoLists) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription"};
    vector<string> listInputs2{"The Best List 2", "ListDescription"};
    admin.createNewList(listInputs);
    admin.createNewList(listInputs2);

    EXPECT_FALSE(admin.findTaskList("The Best List") == nullptr);
    EXPECT_FALSE(admin.findTaskList("The Best List 2") == nullptr);

    admin.deleteList("The Best List");
    admin.deleteList("The Best List 2");

    EXPECT_TRUE(admin.findTaskList("The Best List") == nullptr);
    EXPECT_TRUE(admin.findTaskList("The Best List 2") == nullptr);
}

TEST(HomeDeleteList, doubleFreeTest) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription"};
    admin.createNewList(listInputs);

    EXPECT_FALSE(admin.findTaskList("The Best List") == nullptr);

    admin.deleteList("The Best List");
    admin.deleteList("The Best List");
    admin.deleteList("The Best List");

    EXPECT_TRUE(admin.findTaskList("The Best List") == nullptr);
}