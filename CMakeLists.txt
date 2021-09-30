cmake_minimum_required(VERSION 3.20.5)

#${CMAKE_CXX_COMPILER} "/usr/bin/g++"

project(HLIB)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(Adder)



#               DOWLOAD ALL THE SUBMODULES
# does a git submodule update --init --recursive if needed or posible
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#     CHECK ALL THE SUBMODULES EXISTS
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
 message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(external/glfw/)
add_subdirectory(external/glad/)
#add_subdirectory(external/freetype/)

#project source code paths
target_include_directories(${PROJECT_NAME}
  PUBLIC Adder
  PUBLIC external/glfw/include/
  PUBLIC external/glad/include/
  #PUBLIC external/freetype/include/
)

#how to include GTK or other GUI libs
#/usr/include/ ???
#paths to libs (from build folder)
target_link_directories(${PROJECT_NAME}
  PRIVATE Adder
  PRIVATE external/glfw/src/
  PRIVATE external/glad/src/
  #PRIVATE external/freetype/src/
)

#leave of the lib part and the .a part (may not need number at end off glfw3)
target_link_libraries(${PROJECT_NAME} adder glfw glad)
