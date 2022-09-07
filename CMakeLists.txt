cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME ZeroCompiler)
project(${PROJECT_NAME})

option(BUILD_SHARED_LIBRARY
    "Build libraries as shared libraries." OFF)
option(BUILD_UNITTESTS
    "Pull GoogleTest and build all unit test cases." ON)
option(BUILD_DOC
    "Build documentation." ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(zeroc_add_executable name)
    cmake_parse_arguments(EXE "" "FOLDER" "SOURCES;LIBS" ${ARGN})
    add_executable(${name} ${EXE_SOURCES})

    if (MSVC)
        target_compile_options(${name} PRIVATE /W4)
    else ()
        target_compile_options(${name} PRIVATE
            -Wall -Wextra -Wpedantic -Wno-unused-function)
    endif ()

    target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${name} PRIVATE ${EXE_LIBS})

    if (EXE_FOLDER)
        set_target_properties(${name} PROPERTIES FOLDER ${EXE_FOLDER})
    endif ()
endfunction(zeroc_add_executable)

function(zeroc_add_library name)
    cmake_parse_arguments(LIB "" "FOLDER" "SOURCES;LIBS" ${ARGN})

    if (BUILD_SHARED_LIBRARY)
        add_library(${name} SHARED ${LIB_SOURCES})
    else ()
        add_library(${name} ${LIB_SOURCES})
    endif ()

    if (MSVC)
        target_compile_options(${name} PRIVATE /W4)
    else ()
        target_compile_options(${name} PRIVATE
            -Wall -Wextra -Wpedantic -Wno-unused-function)
    endif ()

    target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${name} PRIVATE ${LIB_LIBS})

    if (LIB_FOLDER)
        set_target_properties(${name} PROPERTIES FOLDER ${LIB_FOLDER})
    else ()
        set_target_properties(${name} PROPERTIES FOLDER "Zeroc Libs")
    endif ()
endfunction(zeroc_add_library)

add_subdirectory(lib)
add_subdirectory(doc)
if (BUILD_UNITTESTS)
    enable_testing()
    add_subdirectory(unittests)
endif ()
