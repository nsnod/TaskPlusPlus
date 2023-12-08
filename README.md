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
* Our project will be primarily implemented in C++. As a primarily terminal based project, we will make use of multiple data structures to efficiently store the user’s information. When testing our software, we will use Valgrind and Google Test to run all unit tests to rigorously stress test our executable.

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
    * Displaying when a user wants to redo a attribute
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
![Main Menu](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-1.jpg)
From the Main Menu, the user has the following options above available to them. Selecting one options will take them to another screen.

![New Task Prompt](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-2.jpg)
Users will be prompted to enter all the relevant information for a new task they input. At the end, they will be prompted to confirm this or re enter the information.

![New List Prompt](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-3.jpg)
Similar to task, users will be able to create a list with a title and a description. Users will be able to add tasks to this list from another screen.

![Task Editor](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-4.jpg)
When the user wants to edit information regarding the task, they will access this screen outside of the main menu.

![List Editor](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-5.jpg)
The user will also have the option to edit data regarding the list from some of the view screens.

![Weekly View](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-6.jpg)
Users are presented with a calendar of the current week when viewing weekly tasks, with each task displayed alongside its due date. Users can manage the entire week or select individual days of the week. Actions include editing, archiving, deleting, or marking tasks as complete for the week or specific days. Users can also edit individual tasks on specific days. Users can also view the progress bar for the percentage of tasks they have completed for the week. User can type Task-- to back out and return to the home screen.

![View Priority](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-7.jpg)
Users will be able to view tasks sectioned by their priority as shown above.

![View Overall](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/CS100%20New%20Layouts-8.jpg)
View overall tasks.

## Class Diagram
![UML](https://github.com/cs100/final-project-btran159-nsnod001-rgujr001-surib013/blob/master/images/UML_4.png)\
The UML diagram we constructed has one main class, Home, that is connected to other classes through aggregation. Every class has their own responsibilities and have been separated with their respective information. Our different viewing options have similar and different functionalities so they are to share an abstract class and also have their own private functions and values. Our relationships between the classes ensure that they only have access to what they must use implementing the rule of least privilege.

The SOLID principles we applied to this project included Single-Responsibility Principle (SRP) and Dependency Inversion Principle (DIP). We designed our classes with the single-responsibility principle in mind for cleaner and concise code. Specifically, our Task class is only responsible for operations related only to individual tasks. This includes things like getting task name, task status, task priority, and etc. In addition, our TaskList class is only responsible for actions related to only task lists. Similarly, TaskList includes methods like adding tasks, removing tasks, getting counts of tasks and etc. This change helped us write better code because it allowed us to reduce confusion on the operations of each class. Through aggregation with View & Home, and Prompt & Home, we are able to provide the tools necessary for the Home class to operate, thus following Dependency Inverison Principle. This change helped us write better code because it allowed us to reduce confusion on the operations of each class. This improved our code by keeping classes flexible, extendable and reusable in the future. If we need to make changes to how individual tasks work in our application, we only need to modify the Task class. Additionally, in terms of Dependency Inversion Principle our high-level class, Home, depend on abstractions, Prompt and View.
 
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
 
