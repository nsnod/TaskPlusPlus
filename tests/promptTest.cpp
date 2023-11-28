#include "../headers/prompt.h"
#include "gtest/gtest.h"

TEST(promptTest, printMenu){
    Prompt p;

    //testing the mutator for prompt
    EXPECT_NO_THROW(p.SetSelection());

    //testing that printing main menu doesnt cause an error
    EXPECT_NO_THROW(p.printMainMenu());

}

TEST(promptTest, newListPrompt){
    Prompt p;

    EXPECT_NO_THROW(p.newListPrompt());
}

TEST(promptTest, newTaskPrompt){

    Prompt p;

    EXPECT_NO_THROW(p.newTaskPrompt());
    
}

TEST(promptTest, taskEditorPrompt){

    Prompt p;
    
    EXPECT_NO_THROW(p.taskEditorPrompt());
    
}