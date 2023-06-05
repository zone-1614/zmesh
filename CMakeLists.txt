cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
    ZMesh
    LANGUAGES CXX
    VERSION 1.0.0
)

# zmesh options 
option(ZMESH_TESTS "enable testing for ZMesh" OFF)

find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")

find_package(Eigen3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
# find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_USE_MATH_DEFINES -DNOMINMAX -D_CRT_SECURE_NO_WARNINGS")
endif()

if (MSVC)
    add_compile_options(/wd4267) # convert from size_t
    add_compile_options(/wd4244) # convert from double to float
    add_compile_options(/wd4305) # truncate from double to float
endif()

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/**)

# add_library(zmesh STATIC ${srcs})

add_executable(zmesh ${srcs})

target_include_directories(zmesh PUBLIC include)
target_include_directories(zmesh PUBLIC ${STB_INCLUDE_DIRS})

target_link_libraries(zmesh PUBLIC Eigen3::Eigen)
target_link_libraries(zmesh PUBLIC spdlog::spdlog spdlog::spdlog_header_only)
target_link_libraries(zmesh PUBLIC glad::glad)
target_link_libraries(zmesh PUBLIC glfw)
target_link_libraries(zmesh PUBLIC imgui::imgui)

if (ZMESH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()