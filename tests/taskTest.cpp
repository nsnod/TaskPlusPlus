#include "../headers/task.h"
#include "gtest/gtest.h"

//CompletedFeature//

TEST(TaskCompletedFeature, originallyCompleted) {
    Task newTask;
    newTask.switchCompleteStatus();

    EXPECT_TRUE(newTask.getCompleteStatus() == true);
}

TEST(TaskCompletedFeature, originallyUncompleted) {
    Task newTask;

    EXPECT_TRUE(newTask.getCompleteStatus() == false);
}

//DueDateFeature//

TEST(TaskDueDateFeature, defaultDueDate) {
    Task newTask;

    EXPECT_TRUE(newTask.getDueDay() == -1);
    EXPECT_TRUE(newTask.getDueMonth() == -1);
    EXPECT_TRUE(newTask.getDueYear() == -1);
    EXPECT_TRUE(newTask.getFullDueDate() == "");
}

TEST(TaskDueDateFeature, taskWithEditedDueDate) {
    Task newTask;

    newTask.setFullDueDate("11/18/23");
    EXPECT_TRUE(newTask.getDueDay() == 18);
    EXPECT_TRUE(newTask.getDueMonth() == 11);
    EXPECT_TRUE(newTask.getDueYear() == 23);
    EXPECT_TRUE(newTask.getFullDueDate() == "11/18/23");
}

//AssignedDateFeature//

TEST(TaskAssignedDateFeature, defaultAssignedDate) {
    Task newTask;

    EXPECT_TRUE(newTask.getAssignedDay() == -1);
    EXPECT_TRUE(newTask.getAssignedMonth() == -1);
    EXPECT_TRUE(newTask.getAssignedYear() == -1);
    EXPECT_TRUE(newTask.getFullAssignedDate() == "");
}

TEST(TaskAssignedDateFeature, taskWithEditedAssignedDate) {
    Task newTask;

    newTask.setFullAssignedDate("11/18/23");
    EXPECT_TRUE(newTask.getAssignedDay() == 18);
    EXPECT_TRUE(newTask.getAssignedMonth() == 11);
    EXPECT_TRUE(newTask.getAssignedYear() == 23);
    EXPECT_TRUE(newTask.getFullAssignedDate() == "11/18/23");
}

//NameChangeFeature//

TEST(TaskNameChangeFeature, defaultName) {
    Task newTask;
    
    EXPECT_TRUE(newTask.getName() == "");
}

TEST(TaskNameChangeFeature, taskWithEditedName) {
    Task newTask;

    newTask.setName("Complete CS100 Phase III");
    EXPECT_TRUE(newTask.getName() == "Complete CS100 Phase III");

    newTask.setName("Demo final deliverable for CS100");
    EXPECT_TRUE(newTask.getName() == "Demo final deliverable for CS100");
}

//DescriptionChangeFeature//

TEST(TaskDescriptionChangeFeature, defaultDescription) {
    Task newTask;

    EXPECT_TRUE(newTask.getDescription() == "");
}

TEST(TaskDescriptionChangeFeature, taskWithEditedDescription) {
    Task newTask;

    newTask.setDescription("This might just be the greatest task ever");
    EXPECT_TRUE(newTask.getDescription() == "This might just be the greatest task ever");

    newTask.setDescription("Oops I had to change it this is the worst task");
    EXPECT_TRUE(newTask.getDescription() == "Oops I had to change it this is the worst task");
}

//TaskPriorityChangeFeature//

TEST(TaskPriorityChangeFeature, defaultPriority) {
    Task newTask;

    EXPECT_TRUE(newTask.getPriority() == "");
}

TEST(TaskPriorityChangeFeature, taskWithEditedPriority) {
    Task newTask;

    newTask.setPriority("High");
    EXPECT_TRUE(newTask.getPriority() == "High");

    newTask.setPriority("Medium");
    EXPECT_TRUE(newTask.getPriority() == "Medium");

    newTask.setPriority("Low");
    EXPECT_TRUE(newTask.getPriority() == "Low");
}