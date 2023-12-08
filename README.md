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
    * Displaying the weekly tasks schedule and the days
    * Displaying if tasks are completed or not completed
    * Displaying a percentage of completed tasks within a list
    * Individual daily tasks
    * Overall undated tasks
    * Weekly Tasks and Lists
    * Tasks based on priority
    * Home Screen
    * All different options on every different screen to pivot to other screens
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
        * Assigning a date
    * Lists:
        * List’s name
        * List’s priority
        * Changing the list’s name
        * Changing Priority
        * Deleting lists
        * Noting the completion of lists
        * Undoing action
        * Choosing to have the application suggest a weekly schedule
        * Assigning tasks to a list


**What are the features that the project provides?**
* Users can create tasks with a title, description, classification, priority, assigned date and due date
* Tasks lists can be made that will contain multiple tasks within it
* Users will be able to manage all of their tasks and tasks lists by creating and deleting 
* Users will also have the option to undo their actions
* Users will be able to view tasks by their priority to see which need to be completed first
* The application will output a weekly view with a updating weekly schedule that is handled on the back-end
* Users will be able to assign tasks to the certain day they want to do them 
* Users will be able to view all of their tasks and task lists even if the tasks do not belong to a list
* Users will have the option to edit any aspect of their task or task list
* Users will have the option to mark different tasks as complete and see this represented through a check mark
* Users will be able to view the completed status of their lists and the percentage of how many tasks have been completed within

## User Interface Specification

### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Navigation.png)\
Once you boot the program, you will be taken to the home screen and will have multiple options of where to pivot to. You will be able to create a new task list, a new task, and will have multiple viewing options of the weekly tasks, the overall tasks and lists, and your tasks organized by their priority. Within the new task screen, you will be able to create new tasks, confirm creation, and undo any errors you may have made. The new task list will have the same features but will be a list containing multiple other tasks. From the different viewing screens, you will be able to edit the tasks and lists, or delete them. From the overall updated viewing screen, You will be able to see individual tasks not assigned to a list and then all the lists with tasks inside of them. Each list will have a percentage to show how many tasks in that list have been completed. All screens have the option to return home.

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

S: We designed our classes with the single-responsibility principle in mind for cleaner and concise code. Specifically, our Task class is only responsible for operations related only to individual tasks. In addition, our TaskList class is only responsible for actions related to only task lists. This change helped us write better code because it allowed us to reduce confusion on the operations of each class.

O: The open-closed principle was applied by our Home class. The home class uses aggregation to be able to use the various operations that class Task and TaskList provides. For example, the home class is able create a task list and manipulate tasks within those lists. This change helped us write better code because the code was more concise which provided a clear indication of the operations that the home class can access and it avoids the need to change the code within Home if Task or taskList were to change.

L: The Liskov substitution principle is applied by the base class, View, and the children of this class. The derived classes, Archive, Weekly, and Upcoming all share the common function view() that was from the View class. Although each class hold different responsibilities, they still need the view() function to perform their operations correctly. This change helped ue write better code because it allowed us to be less repetitive and use the function from any derived classes with ease.

I: We used the interface segregation principle when designing the subtype classes, Archive, Weekly, and Upcoming, which are derived from the View base class. These 3 classes are all derived from View so they all share the inherited functions of View, but every class has separate functions to deal with their sole responsibilites. This code change helped us write better code because the code became more concise and clean since each class was tailored to their specific responsibility.

D: The Dependency inversion principle is applied by the Home class. The Home class are provided with Task and TaskList's operations through aggregation which allows Home to access the tools needed to perform the necessary actions. This separates Home from concrete details and implementations. This improved our code by keeping classes flexible, extendable and reusable in the future.

 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
The following images are screenshots of specific screens in our application

![Main Menu](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/Main_Menu.png)

The user will be presented with the main menu of our task manager. We have displayed the logo in a special font above.

![New Task Prompt](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/New_Task_Prompt.png)

After selecting the corresponding option, the user will be prompted with the relevant information for their new task. They will also be asked to confirm or amend that task.

![View Overall Tasks](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/View_Overall_Tasks.png)

After entering the option to View Overall Tasks, the application will display the weekly calender with the tasks dispersed throughout the week.


 ## Installation/Usage
1. Open your terminal application and use the cd command to navigate to a suitable directory
2. To properly import all the required files, run the command: git clone --recursive https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013.git
3. Run the command cmake . followed by make
4. To execute the Task Manager program, simply run ./bin/TaskPlusPlus
 ## Testing
 We utilized the GoogleTest framework to test all of our classes concurrently as we were developing them. We ran various macros provided to test different functionalities of our classes. More specifically, we performed stress testing with a large amount of inputs as well as covering all possible edge cases.
 
