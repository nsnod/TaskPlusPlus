#include "../headers/task.h"
#include "gtest/gtest.h"

TEST(TestingTaskCPP, originallyCompleted) {
    Task newTask;
    newTask.switchCompleteStatus();

    EXPECT_TRUE(newTask.getCompleteStatus() == true);
}

TEST(TestingTaskCPP, originallyUncompleted) {
    Task newTask;

    EXPECT_TRUE(newTask.getCompleteStatus() == false);
}