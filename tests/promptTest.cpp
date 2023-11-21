#include "../headers/prompt.h"
#include "gtest/gtest.h"

TEST(promptTest, printMenu){
    Prompt p;

    //testing the mutator for prompt
    EXPECT_NO_THROW(p.SetSelection());

    //testing that printing main menu doesnt cause an error
    EXPECT_NO_THROW(p.printMainMenu());

}

TEST(promptTest, newTaskPrompt){
    Prompt p;

    EXPECT_EQ(p.newTaskPrompt(), {"Homework", "High", "04/04/22", "05/06/23", "physics, math"})
}