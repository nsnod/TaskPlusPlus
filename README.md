# Task++
Authors:  
[Noah Snodgrass](https://github.com/noahsnod)\
[Brandon Tran](https://github.com/brandontran1220)\
[Samuel Uribe](https://github.com/samuribe013)\
[Rohan Gujral](https://github.com/rgujr001)

## Project Description
**Why is it important or interesting to you?**
* This project is important to us because, as college students, time management is the key to success. According to “collegesuccessplan.edu” “78% of students claim to struggle with time management throughout their college experience, with an additional 9% claiming to “always” struggle with this” and “80% of college professors believe their students struggle with time management “most” of the time.” With Task++ it enables users to manage their time efficiently with task management. With the ability to manage all your daily, weekly, or monthly tasks within lists and plans, you can be assured your time management will be maximized.

**What languages/tools/technologies do you plan to use? (This list may change over the course of the project)**
* Our project will be primarily implemented in C++. As a primarily terminal based project, we will make use of multiple data structures to efficiently store the user’s information. We are also going to archive or store our past user data through a SQL database. We may also implement functionality for our user to run pre-written scripts for the user to access some of their past lists. When testing our software, we will use Valgrind and Google Test to run all unit tests to rigorously stress test our executable.

**What will be the input/output of your project?**
* Output:
    * Displaying all tasks on the list and the number of total items
    * Displaying possible actions for items or list
    * Displaying Lists
    * Displaying tasks that are finished and not finished
    * Creating a file that stores user's task list information
    * Displaying the weekly tasks schedule and the days
    * Displaying if lists are completed or not completed
    * File outputted to machine(in user chosen directory)
    * Total percentage bar of tasks completed for the week
    * Individual daily percentage bar of tasks completed for the week
    * Individual daily tasks
    * Tasks for the weeks
    * Overall undated tasks
    * Archived tasks and lists
* Input:
    * Tasks:
        * Task’s name, priority
        * Duplicate Tasks
        * Changing the priority of tasks
        * Deleting the task
        * Increasing the count of tasks
        * Decreasing the count of tasks
        * Noting a completion of the tasks
        * Renaming tasks
        * Undoing action
        * Redoing action
        * Choosing between weekly task or an overall undated list of tasks
        * Choosing day if weekly
        * Archive tasks
        * Retrieve tasks from archive
    * Lists:
        * List’s name
        * List’s priority
        * Changing the list’s name
        * Changing Priority
        * Deleting lists
        * Noting the completion of lists
        * Undoing action
        * Choosing to have the application suggest a weekly schedule
        * Choosing between weekly list or an overall undated list of the lists
        * Choosing day if weekly
        * Archive lists
        * Retrieve lists from archive

**What are the features that the project provides?**
* Users can create tasks with a title, description, classification, priority, and due date
* Tasks lists can be made that will contain multiple tasks within it
* Each task will have the option to contain subtasks
* Users will be able to manage all of their tasks and tasks lists with displaying, creation, deletion, and editing
* Users will also have the option to undo their actions
* You will be able to sort lists based on their classification
* The application will also suggest a weekly schedule based on priority and due date
* Users will be able to assign tasks to the day to make weekly sets of tasks as well as
store the tasks in an overall undated category rather than the weekly set
* Users will have the option to change an undated overall task and assign a date/edit priority
* Download a task document on their machine
* Users will have the option to archive the lists or tasks instead of deleting them if they want to reuse them (example: a long list of tasks that you will have to reuse you can archive to keep your overall tasks and weekly tasks clean)
* Users will have the option to take tasks and lists out of the archive 

## User Interface Specification

### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Navigation.png)\
Once you boot the program, you will be taken to the home screen and will have multiple options of where to pivot to. You will be able to create a new task list, a new task, and will have multiple viewing options of the task archive, the overall undated tasks, and your weekly set of tasks. Within the new task screen, you will be able to create new tasks, confirm creation, and undo any errors you may have made. The new task list will have the same features but will be a list containing multiple other tasks. From the different viewing screens, you will be able to download the set of tasks for each viewing screen, edit the tasks and lists, or delete them. From the overall updated viewing screen, you will be able to create a recommended list of tasks for your week. You will be able to archive any tasks or task lists from within the viewing screens. All screens have the option to return home.

### Screen Layouts
![Home Screen](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Home_Screen.jpg)\
The home screen prompts the user to enter their preferred action. Options include creating a new task, creating a new list, viewing the archive, checking weekly tasks, examining upcoming tasks, and selecting the weekly schedule recommender. The user can type their choice, and the program will parse it to determine the next course of action. There's also an exit option for users to leave the program when they're done. User can type Task-- to back out and return to the terminal.

![New Task](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/New_Task.jpg)\
When creating a new task, users are required to input the task name, task description, priority, due date, assigned date, and whether they want to assign it to an existing list or not. While on this screen, users have the flexibility to edit the task description extensively. They can undo any possible mistakes when given the final option to confirm. After they're satisfied with the changes, users can choose to return to the home screen. User can type Task-- to back out and return to the home screen.

![New List](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/New_List.jpg)\
Users can specify a list name and provide a description or any relevant information about the list's purpose. After naming the list and providing the description, users are given the option to pivot to the new task screen with the "add task" option. User can type Task-- to back out and return to the home screen.

![Task Editor](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Task_Editor.jpg)\
When tasks are selected for editing, users are taken to the edit screen. This edit screen displays all current data of the task, including the title, priority, due date, assigned date, description, and whether it has an assigned list or not. Users have the option to continue editing aspects of the task or confirm their changes. User can type Task-- to back out and return to the home screen.

![List Editor](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/List_Editor.jpg)\
When lists are selected for editing, users are taken to the list editor screen. The edit screen displays all the data of the current list, including the title and the description. Users are given the option to continue editing aspects of the list or confirm their changes. User can type Task-- to back out and return to the home screen.

![Weekly View](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Weekly.jpg)\
Users are presented with a calendar of the current week when viewing weekly tasks, with each task displayed alongside its due date. Users can manage the entire week or select individual days of the week. Actions include editing, archiving, deleting, or marking tasks as complete for the week or specific days. Users can also edit individual tasks on specific days. Users can also view the progress bar for the percentage of tasks they have completed for the week. User can type Task-- to back out and return to the home screen.

![Upcoming View](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Upcoming.jpg)\
Users get to see an overall list of undated tasks as well as their weekly tasks assigned to days beyond the current week. Users can edit, delete, archive, or mark tasks and lists as complete. They can also manage tasks within the selected lists. User can type Task-- to back out and return to the home screen.

![Archive View](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Archive.jpg)\
Users can view all archived lists and tasks and choose between the two options. They can enter a number corresponding to the task or list in the selected category. Users can also see the automated completed task list, which stores all completed tasks and lists. Options include editing, deleting, uploading, or marking as complete. Uploading allows users to move archived weeks into a new week for easier week creation. User can type Task-- to back out and return to the home screen.

## Class Diagram
![UML](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/UML_3.png)\
The UML diagram we constructed has one main class, Home, that is connected to other classes through aggregation. Every class has their own responsibilities and have been separated with their respective information. Our different viewing options have similar and different functionalities so they are to share an abstract class and also have their own private functions and values. Our relationships between the classes ensure that they only have access to what they must use implementing the rule of least privilege.

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
