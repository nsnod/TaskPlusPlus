#include "../headers/prompt.h"
#include "gtest/gtest.h"

TEST(promptTest, printMenu){
    prompt p;
    

    EXPECT_NO_THROW(p.printMainMenu());
}


/*TEST(promptTest, newTaskPrompt){
    prompt p;
    //Home h;

    EXPECT_EQ(p.newTaskPrompt(), {});
}*/