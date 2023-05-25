
# find GoogleTest
find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE zmesh_test_srcs CONFIGURE_DEPENDS ../src/core/*.cpp ../src/gl/*.cpp ../src/io/*.cpp ../src/algo/*.cpp)

macro(zmesh_add_test test_name test_srcs)
    add_executable(${test_name} ${test_srcs} ${zmesh_test_srcs})
    target_include_directories(${test_name} PUBLIC ../include)
    target_link_libraries(${test_name} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    add_test(${test_name} ${test_name})
endmacro()

zmesh_add_test("test_iterator" "test_iterator.cpp")


