add_library(simpleLibrary
    task.cpp
)

#add_executable(taskPlusPlus
#    task.cpp
#)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})