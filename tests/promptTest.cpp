#include "../headers/prompt.h"
#include "gtest/gtest.h"

TEST(promptTest, printMenu){
    prompt p;
    Home *userHome;

    //testing the mutator for prompt
    EXPECT_NO_THROW(p.setSelection());

    //testing that printing main menu doesnt cause an error
    
    EXPECT_NO_THROW(p.printMainMenu());

    EXPECT_EQ(p.getSelection(), "1");

    EXPECT_NO_THROW(p.newTaskPrompt(userHome));
    

}


/*TEST(promptTest, newTaskPrompt){
    prompt p;
    //Home h;

    EXPECT_EQ(p.newTaskPrompt(), {});
}*/