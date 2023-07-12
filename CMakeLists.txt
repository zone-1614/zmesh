cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
    ZMesh
    LANGUAGES CXX
    VERSION 1.0.1
)

find_path(STB_INCLUDE_DIRS "stb_image_write.h")

find_package(Eigen3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_USE_MATH_DEFINES -DNOMINMAX -D_CRT_SECURE_NO_WARNINGS")
endif()

if (MSVC)
    add_compile_options(/wd4267) # convert from size_t
    add_compile_options(/wd4244) # convert from double to float
    add_compile_options(/wd4305) # truncate from double to float
    add_compile_options(/wd4819) # 字符编码相关的warning
endif()

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS 
    src/core/*.cpp include/core/*.h
    src/io/*.cpp include/io/*.h
    src/algo/*.cpp include/algo/*.h
    include/util.h include/zmesh.h
)

add_library(zmesh STATIC ${srcs})

set_target_properties(zmesh PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(zmesh PUBLIC include)
target_include_directories(zmesh PUBLIC ${STB_INCLUDE_DIRS})

target_link_libraries(zmesh PUBLIC Eigen3::Eigen)
target_link_libraries(zmesh PUBLIC spdlog::spdlog spdlog::spdlog_header_only)

install(
    TARGETS zmesh
    EXPORT zmeshTargets
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION bin
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(
    DIRECTORY include/zmesh/core include/zmesh/io include/zmesh/algo
    DESTINATION include/zmesh
)
install(
    FILES include/zmesh/util.h include/zmesh/zmesh.h
    DESTINATION include/zmesh
)
