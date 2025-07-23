cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

###########################################################################
# INTRUSIVE LINKED LIST
###########################################################################
project(intrusive_linkedlist_test)

add_executable(${PROJECT_NAME} src/intrusive_linkedlist_test.c)

target_link_libraries(${PROJECT_NAME} acl)
###########################################################################
# LINKED LIST
###########################################################################
project(linkedlist_test)

add_executable(${PROJECT_NAME} src/linkedlist_test.c)

target_link_libraries(${PROJECT_NAME} acl)
###########################################################################
# STACK
###########################################################################
project(stack_test)

add_executable(${PROJECT_NAME} src/stack_test.c)

target_link_libraries(${PROJECT_NAME} acl)
###########################################################################
# INTRUSIVE QUEUE
###########################################################################
project(intrusive_queue)

add_executable(${PROJECT_NAME} src/intrusive_queue_test.c)

target_link_libraries(${PROJECT_NAME} acl)
