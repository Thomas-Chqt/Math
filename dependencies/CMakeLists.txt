# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <thomas.publique@icloud.com>
# Date: 2024/05/24 09:41:30
# ---------------------------------------------------

if(NOT TARGET UtilsCPP)
    execute_process(COMMAND git submodule update --init ${CMAKE_CURRENT_SOURCE_DIR}/UtilsCPP)
    add_subdirectory(UtilsCPP)
endif()
target_link_libraries(Math PUBLIC UtilsCPP)
