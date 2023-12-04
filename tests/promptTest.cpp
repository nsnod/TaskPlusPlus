#include "../headers/prompt.h"
#include "../headers/home.h"
#include "../headers/taskList.h"
#include "gtest/gtest.h"


Home* h;
TaskList* t;

TEST(promptTest, printMenu){
    prompt *p;

    //testing the mutator for prompt

    //testing that printing main menu doesnt cause an error
    EXPECT_NO_THROW(p->printMainMenu());

}

TEST(promptTest, newListPrompt){
    prompt p;

    EXPECT_NO_THROW(p.newListPrompt());
}

TEST(promptTest, newTaskPrompt){

    prompt p;

    EXPECT_NO_THROW(p.newTaskPrompt(h));
    
}

TEST(promptTest, taskEditorPrompt){

    prompt p;
    
    EXPECT_NO_THROW(p.taskEditorPrompt(t));
    
}