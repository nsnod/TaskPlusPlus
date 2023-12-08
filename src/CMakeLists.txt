add_library(simpleLibrary
    task.cpp
    taskList.cpp
    home.cpp
    prompt.cpp
    view.cpp
    main.cpp
)

add_executable (TaskPlusPlus
  main.cpp
  view.cpp 
  task.cpp 
  taskList.cpp 
  home.cpp 
  prompt.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})