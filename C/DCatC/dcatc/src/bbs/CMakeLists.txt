cmake_minimum_required(VERSION 3.10)

# set the project name
project(bbs_tests)



# include_directories(../../path_walker)
# add_subdirectory(../../path_walker)

# add the executable
add_executable(test_table_record 
    ./tests/test_table_record.c
    ./utils.c
    ./bbs_table_record.c
    )


add_executable(test_packer 
    ./tests/test_packer.c
    ./utils.c
    ./bbs_table_record.c
    )


add_executable(test_header 
    ./tests/test_header.c
    ./utils.c
    ./bbs_header.c
    )


add_executable(test_volume 
    ./tests/test_volume.c
    ./utils.c
    ./bbs_volume.c
    )
# target_link_libraries(path_walker_tests
#     path_walker
# )