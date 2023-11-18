#include "../headers/task.h"
#include "gtest/gtest.h"

TEST(TaskCompletedFeature, originallyCompleted) {
    Task newTask;
    newTask.switchCompleteStatus();

    EXPECT_TRUE(newTask.getCompleteStatus() == true);
}

TEST(TaskCompletedFeature, originallyUncompleted) {
    Task newTask;

    EXPECT_TRUE(newTask.getCompleteStatus() == false);
}

TEST(TaskDueDateFeature, defaultTaskDay) {
    Task newTask;

    EXPECT_TRUE(newTask.getDueDay() == -1);
    EXPECT_TRUE(newTask.getDueMonth() == -1);
    EXPECT_TRUE(newTask.getDueYear() == -1);
}

// TEST(TaskDueDateFeature, ) {
//     Task newTask;

//     newTask.
// }

// TEST(TaskDueDateFeature, ) {
    
// }

// TEST(TaskDueDateFeature, ) {
    
// }