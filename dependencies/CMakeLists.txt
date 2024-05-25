# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:41:30
# ---------------------------------------------------

if(NOT TARGET UtilsCPP)
    execute_process(COMMAND git submodule update --init UtilsCPP WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(UtilsCPP)
endif()
target_link_libraries(Math PUBLIC UtilsCPP)
