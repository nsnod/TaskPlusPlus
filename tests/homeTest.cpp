#include "../headers/task.h"
#include "../headers/taskList.h"
#include "../headers/home.h"
#include "gtest/gtest.h"

//New list creation testing//

TEST(HomeCreateNewTask, listCreation) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription", "Upcoming"};

    admin.createNewList(listInputs);

    EXPECT_TRUE((admin.findTaskList("The Best List"))->getListDescription() == "ListDescription");
}

//New Task creation assigned to list testing//

TEST(HomeCreateNewTask, newTaskAssignedToExampleListFound) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription", "Upcoming"};
    vector<string> taskInputs{"Name", "High", "11/19/23", "11/18/23", "Description", "The Best List"};

    admin.createNewList(listInputs);
    admin.createNewTask(taskInputs);

    EXPECT_TRUE(((admin.findTaskList("The Best List"))->findTask("Name"))->getDescription() == "Description");
}

TEST(HomeCreateNewTask, newTaskAssignedToExampleListNotFound) {
    Home admin;

    vector<string> listInputs{"The Best List", "ListDescription", "Upcoming"};
    vector<string> taskInputs{"Name", "High", "11/19/23", "11/18/23", "Description", "The Best List"};

    admin.createNewList(listInputs);
    admin.createNewTask(taskInputs);

    EXPECT_TRUE(((admin.findTaskList("The Best List"))->findTask("Doesn't exist")) == nullptr);
}

//New Task creation assigned to no list testing //

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