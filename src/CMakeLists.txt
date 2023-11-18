add_library(simpleLibrary
    task.cpp
    taskList.cpp
)

# add_executable(runAllTests
#    task.cpp
# )

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})