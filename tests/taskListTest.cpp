#include "../headers/taskList.h"
#include "gtest/gtest.h"

TEST(TestingTaskList, originallyCompleted) {
    TaskList newList;
    newList.switchCompleteStatus();

    EXPECT_TRUE(newList.getListCompleteStatus() == true);
}

TEST(TestingTaskList, originallyUncompleted) {
    TaskList newList;

    EXPECT_TRUE(newList.getListCompleteStatus() == false);
}

TEST(TestingTaskList, nameEmpty) {
    TaskList newList;

    EXPECT_TRUE(newList.getListName() == "");
}

TEST(TestingTaskList, nameNotEmpty) {
    TaskList newList;
    newList.editListName("Test");

    EXPECT_TRUE(newList.getListName() == "Test");
}

TEST(TestingTaskList, classificationWeekly) {
    TaskList newList;
    newList.editListClassification("Weekly");

    EXPECT_TRUE(newList.getListClassification() == "Weekly");
}

TEST(TestingTaskList, classificationChange) {
    TaskList newList;
    newList.editListClassification("Weekly");
    newList.editListClassification("Upcoming");

    EXPECT_TRUE(newList.getListClassification() == "Upcoming");
}

TEST(TestingTaskList, descriptionEmpty) {
    TaskList newList;

    EXPECT_TRUE(newList.getListDescription() == "");
}

TEST(TestingTaskList, descriptionNotEmpty) {
    TaskList newList;
    newList.editListDescription("Testing 1 2 3");

    EXPECT_TRUE(newList.getListDescription() == "Testing 1 2 3");
}