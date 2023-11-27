#include "../headers/taskList.h"
#include "gtest/gtest.h"

TEST(TestingComplete, originallyCompleted) {
    TaskList newList;
    newList.switchCompleteStatus();

    EXPECT_TRUE(newList.getListCompleteStatus() == true);
}

TEST(TestingComplete, originallyUncompleted) {
    TaskList newList;

    EXPECT_TRUE(newList.getListCompleteStatus() == false);
}

TEST(TestingName, nameEmpty) {
    TaskList newList;

    EXPECT_TRUE(newList.getListName() == "");
}

TEST(TestingName, nameNotEmpty) {
    TaskList newList;
    newList.editListName("Test");

    EXPECT_TRUE(newList.getListName() == "Test");
}

TEST(TestingClassification, classificationWeekly) {
    TaskList newList;
    newList.editListClassification("Weekly");

    EXPECT_TRUE(newList.getListClassification() == "Weekly");
}

TEST(TestingTaskListClassification, classificationChange) {
    TaskList newList;
    newList.editListClassification("Weekly");
    newList.editListClassification("Upcoming");

    EXPECT_TRUE(newList.getListClassification() == "Upcoming");
}

TEST(TestingDescription, descriptionEmpty) {
    TaskList newList;

    EXPECT_TRUE(newList.getListDescription() == "");
}

TEST(TestingDescription, descriptionNotEmpty) {
    TaskList newList;
    newList.editListDescription("Testing 1 2 3");

    EXPECT_TRUE(newList.getListDescription() == "Testing 1 2 3");
}