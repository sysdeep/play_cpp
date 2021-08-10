cmake_minimum_required(VERSION 3.10)

# set the project name
project(path_walker_tests)



# include_directories(../../path_walker)
# add_subdirectory(../../path_walker)

# add the executable
add_executable(path_walker_tests ./main.c)


target_link_libraries(path_walker_tests
    path_walker
)