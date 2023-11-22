#include "gtest/gtest.h"
#include "../headers/prompt.h"
#include "../headers/home.h"


TEST(promptTest, printMenu){
    prompt p;

    //testing that printing main menu doesnt cause an error
    
    EXPECT_NO_THROW(p.printMainMenu());

    EXPECT_EQ(p.getSelection(), "1");

    EXPECT_NO_THROW(p.newTaskPrompt());
    

}


/*TEST(promptTest, newTaskPrompt){
    prompt p;
    //Home h;

    EXPECT_EQ(p.newTaskPrompt(), {});
}*/