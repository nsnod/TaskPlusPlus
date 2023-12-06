#include "../headers/prompt.h"
#include "../headers/home.h"
#include "../headers/task.h"
#include "../headers/taskList.h"
#include "gtest/gtest.h"

TEST(promptTest, printMenu){ //tests if menu prints//
    prompt p;
    
    EXPECT_NO_THROW(p.printMainMenu());
}

TEST(promptTest,newListPrompt){
    prompt p3;
    vector<string> mockData = {"mockTitle","mockDescription"};

    EXPECT_EQ(p3.newListPrompt(),mockData);

}

TEST(promptTest,taskEditorPrompt){
    prompt p4;
    
}

TEST(promptTest,newTaskPrompt){
    Home *h = new Home;
    prompt p2;

    vector<string> mockTaskData = {"mockTitle", "Low",  "00/00/00", "00/00/00", "mockDesc", ""};
    vector<string> mockListData = {"mockListTitle", "mockListDescription"};

    EXPECT_EQ(p2.newTaskPrompt(h),mockTaskData); //testing w/o adding to list checks if two vectors//

    h->createNewList(mockListData);

    mockTaskData.push_back("mockListTitle");
    
    EXPECT_EQ(p2.newTaskPrompt(h),mockTaskData);
}



