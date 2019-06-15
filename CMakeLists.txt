cmake_minimum_required(VERSION 3.14)
project(GEN_LAB05)

set(CMAKE_CXX_STANDARD 14)

add_executable(Main
        src/main.cpp
        src/Customer.cpp src/Customer.h
        src/Movie.cpp src/Movie.h
        src/Rental.h
        src/price/Price.cpp src/price/Price.h
        src/price/RegularMoviePrice.cpp src/price/RegularMoviePrice.h
        src/price/NewReleaseMoviePrice.cpp src/price/NewReleaseMoviePrice.h
        src/price/ChildrenMoviePrice.cpp src/price/ChildrenMoviePrice.h)

add_executable(Testing
        src/Customer.cpp src/Customer.h
        src/Movie.cpp src/Movie.h
        src/Rental.h test/CustomerTest.cpp
        src/price/Price.cpp src/price/Price.h
        src/price/RegularMoviePrice.cpp src/price/RegularMoviePrice.h
        src/price/NewReleaseMoviePrice.cpp src/price/NewReleaseMoviePrice.h
        src/price/ChildrenMoviePrice.cpp src/price/ChildrenMoviePrice.h)

include(DownloadProject.cmake)
download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()


# Trivial example using gtest and gmock
target_link_libraries(Testing gtest gmock gmock_main)
