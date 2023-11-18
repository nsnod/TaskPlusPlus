#pragma once 

class prompt(){
    private:
    unsigned selection;

    public:
    void homeScreen();
    void newTaskPrompt();
    void newListPrompt();
    void taskEditorPrompt();
    void listEditorPrompt();
    void viewArchivePrompt();
    void viewWeeklyTasksPrompt();
    void viewUpcomingTasksPrompt();
    void recommendWeeklySchedulePrompt();
}