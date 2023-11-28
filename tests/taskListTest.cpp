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

TEST(TestingAdd, oneTask) {
    TaskList newList;
    Task *t1 = new Task;
    newList.addTask(t1);

    EXPECT_TRUE(newList.getNumOfTasks() == 1);
}

TEST(TestingAdd, multipleTask) {
    TaskList newList;
    Task *t1 = new Task;
    Task *t2 = new Task;
    Task *t3 = new Task;
    Task *t4 = new Task;

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_TRUE(newList.getNumOfTasks() == 4);
}

TEST(TestingProgression, noneCompleted) {
    TaskList newList;
    Task *t1, *t2, *t3, *t4;
    t1 = new Task;
    t2 = new Task;
    t3 = new Task;
    t4 = new Task;

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_DOUBLE_EQ(newList.getProgress(), 0);
}

TEST(TestingProgression, someCompleted) {
    TaskList newList;
    Task *t1, *t2, *t3, *t4;
    t1 = new Task;
    t2 = new Task;
    t3 = new Task;
    t4 = new Task;

    t1->switchCompleteStatus();

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_DOUBLE_EQ(newList.getProgress(), 0.25);
}

TEST(TestingProgression, allCompleted) {
    TaskList newList;
    Task *t1, *t2, *t3, *t4;
    t1 = new Task;
    t2 = new Task;
    t3 = new Task;
    t4 = new Task;

    t1->switchCompleteStatus();
    t2->switchCompleteStatus();
    t3->switchCompleteStatus();
    t4->switchCompleteStatus();

    newList.addTask(t1);
    newList.addTask(t2);
    newList.addTask(t3);
    newList.addTask(t4);

    EXPECT_DOUBLE_EQ(newList.getProgress(), 1.0);
}

TEST(TestingEditTask, stringNewVal) {
    TaskList newList;
    Task *t1 = new Task;
    newList.addTask(t1);

    string priority = "High";
    string description = "NEED TO DO ASAP";

    newList.editTask(t1, "Priority", priority);
    newList.editTask(t1, "Description", description);

    EXPECT_EQ(t1->getPriority(), priority);
    EXPECT_EQ(t1->getDescription(), description);
}