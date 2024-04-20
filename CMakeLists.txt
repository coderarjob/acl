cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(acl LANGUAGES C)

# Binaries, Libraties will be under 'bin', 'lib' directories.
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_library(${PROJECT_NAME} STATIC
            ${CMAKE_CURRENT_LIST_DIR}/linkedlist/acl_linkedlist.c
            ${CMAKE_CURRENT_LIST_DIR}/stack/acl_stack.c)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        linkedlist 
        stack
        intrusive_linkedlist
        intrusive_queue)

add_subdirectory(tests)
