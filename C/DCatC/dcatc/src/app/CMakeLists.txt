cmake_minimum_required(VERSION 3.10)

# set the project name
project(dcat)



# include_directories(src/path_walker)


# add_subdirectory(src/path_walker)



# add the executable
add_executable(dcat ./main.c)


target_link_libraries(dcat
    path_walker
)