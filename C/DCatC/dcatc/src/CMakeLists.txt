cmake_minimum_required(VERSION 3.10)

# set the project name
# project(dcat)



include_directories(path_walker)


add_subdirectory(path_walker)
add_subdirectory(bbs)
add_subdirectory(app)



# # add the executable
# add_executable(dcat src/main.c)


# target_link_libraries(dcat
#     path_walker
# )