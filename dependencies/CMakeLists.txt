# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:41:30
# ---------------------------------------------------

if(NOT TARGET UtilsCPP)
    find_program(GIT_PATH git REQUIRED)
    execute_process(COMMAND ${GIT_PATH} submodule update --init UtilsCPP WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    set(UTILSCPP_BUILD_TESTS OFF)
    add_subdirectory(UtilsCPP)
    set_target_properties(UtilsCPP PROPERTIES FOLDER "dependencies")
endif()
target_link_libraries(Math PUBLIC UtilsCPP)