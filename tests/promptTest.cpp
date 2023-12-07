#include "../headers/prompt.h"
#include "../headers/home.h"
#include "../headers/task.h"
#include "../headers/taskList.h"
#include "../headers/view.h"
#include "gtest/gtest.h"



TEST(promptTest,selection){
    prompt p1;
    prompt p2;
    prompt p3;
    
    p1.setSelection("1");
    p2.setSelection("Task--");

    
    EXPECT_EQ(p1.getSelection(),"1");
    EXPECT_EQ(p2.getSelection(), "Task--");
}

/*TEST(promptTest, newTaskPrompt){
    vector<string> mList = {"mockName", "mockDesc"};

    Home* homeTest = new Home;
    homeTest->createNewList(mList);

    prompt p1;

    EXPECT_EQ(p1.newTaskPrompt(homeTest),m1); //manually type inpu

    delete homeTest;
    homeTest = nullptr;
}

TEST(promptTest,newListPrompt){
    prompt p1;

    EXPECT_EQ(p1.newListPrompt(),m1);

    
    
}

TEST(promptTest,editTask){
    Home* h = new Home;
    prompt p1;
    
    h->createNewTask(m1);

    p1.taskEditorPrompt(h->findSoloTask("mockTitle"),h->findParentList("mockTitle"));
    delete h;

}
*/
TEST(promptTest,viewWeekly){
    Home h;
    View v;
    prompt p;

    h.createNewList({"MockList","MockDesc"});
    h.createNewList({"MockList2", "MockDesc2"});

    vector<string> taskInputs1{"Name1", "Low", "05/19/23", "12/03/23", "Description", "MockList"};
    vector<string> taskInputs2{"Name2", "Medium", "05/20/23", "12/03/23", "Description", "MockList2"};
    vector<string> taskInputs3{"Name3", "High", "09/21/23", "12/03/23", "Description", "MockList2"};
    vector<string> taskInputs4{"Name4", "High", "10/03/23", "12/03/23", "Description", ""};

    h.createNewTask(taskInputs1);
    h.createNewTask(taskInputs2);
    h.createNewTask(taskInputs3);
    h.createNewTask(taskInputs4);

    p.viewWeekly(&v,&h);
    
    
    






}





