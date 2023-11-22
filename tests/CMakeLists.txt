cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")

add_subdirectory(googletest)


add_executable(testingTask
    taskTest.cpp
)

add_executable(promptTestS
    ../src/prompt.cpp
    promptTest.cpp
)



add_executable(testingTaskList
    ../src/task.cpp
    taskListTest.cpp
)

add_executable(testingHome
    ../src/home.cpp
    homeTest.cpp
)

add_executable(runAllTests
    ../src/task.cpp
    ../src/taskList.cpp
    taskTest.cpp
    taskListTest.cpp
    homeTest.cpp
)



target_link_libraries(testingTask gmock gtest gtest_main)
target_link_libraries(testingTask simpleLibrary)
target_link_libraries(testingTaskList gmock gtest gtest_main)
target_link_libraries(testingTaskList simpleLibrary)
target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)
target_link_libraries(testingHome gmock gtest gtest_main)
target_link_libraries(testingHome simpleLibrary)
target_link_libraries(promptTestS gmock gtest gtest_main)
target_link_libraries(promptTestS simpleLibrary)