#include "../headers/prompt.h"
#include "gtest/gtest.h"

TEST(promptTest, printMenu){
    prompt p;

    //testing the mutator for prompt
    EXPECT_NO_THROW(p.setSelection());

    //testing that printing main menu doesnt cause an error
    
    EXPECT_NO_THROW(p.printMainMenu());

}