# Task++
> Authors:  
> [Noah Snodgrass](https://github.com/noahsnod)\
> [Brandon Tran](https://github.com/brandontran1220)\
> [Samuel Uribe](https://github.com/samuribe013)\
> [Rohan Gujral](https://github.com/rgujr001)

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
    * Optional: If the user decides to add priorities and scheduling options
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
        * Duplicating lists
        * Noting the completion of lists
        * Undoing action
        * Choosing to have the application suggest a weekly schedule
        * Choosing between weekly list or an overall undated list of the lists
        * Choosing day if weekly
        * Archive lists
        * Retrieve lists from archive

**What are the features that the project provides?**
* Users can create tasks with a title, description, classification, priority, duration, and due date
* Tasks lists can be made that will contain multiple tasks within it
* Each task will have the option to contain subtasks
* Users will be able to manage all of their tasks and tasks lists with displaying, creation, deletion, and editing
* Users will also have the option to undo their actions
* You will be able to sort lists based on their classification
* The application will also suggest a weekly schedule based on priority and due date
* Users will be able to assign tasks to the day to make weekly sets of tasks as well as
* store the tasks in an overall undated category rather than the weekly set
* Users will have the option to change an undated overall task and assign a date/edit priority
* Download a task document on their machine
* will have the option to archive the lists or tasks instead of deleting them if they want to reuse them (example: a long list of tasks that you will have to reuse you can archive to keep your overall tasks and weekly tasks clean)
* Users will have the option to take tasks and lists out of the archive 

 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` (aka Sprint Backlog) column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots on Tuesday of week 6. The check-ins will occur on Zoom. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
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
 
