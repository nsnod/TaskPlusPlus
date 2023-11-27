add_library(simpleLibrary
    task.cpp
    taskList.cpp
    home.cpp
    prompt.cpp
    # archive.cpp
    # recommender.cpp
    # upcoming.cpp
    # view.cpp
    # weekly.cpp
)

# add_executable(runAllTests
#    task.cpp
# )

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})