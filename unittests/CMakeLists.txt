# Fetch [googletest](https://github.com/google/googletest)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/5126f7166109666a9c0534021fb1a3038659494c.zip
    )

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

set(UNITTEST_ALL_TARGET zeroc_unit_tests)
add_custom_target(${UNITTEST_ALL_TARGET})
set_target_properties(${UNITTEST_ALL_TARGET} PROPERTIES FOLDER "Zeroc Unit Tests")

function(zeroc_add_unittest name)
    cmake_parse_arguments(ARG "" "" "SOURCES;LIBS" ${ARGN})
    get_target_property(folder ${UNITTEST_ALL_TARGET} FOLDER)
    zeroc_add_executable(${name}
        FOLDER ${folder}
        SOURCES ${ARG_SOURCES}
        LIBS ${ARG_LIBS} gtest_main)
    add_dependencies(${UNITTEST_ALL_TARGET} ${name})
    gtest_discover_tests(${name})
endfunction(zeroc_add_unittest)
