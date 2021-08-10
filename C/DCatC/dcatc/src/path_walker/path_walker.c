#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "./path_walker.h"


void path_walker_walk(const char *path){
    printf("PathWalker - start walk: %s\n", path);



    listdir(path, 0);


    printf("PathWalker - end walk\n");
}



/**
 * 
 * 
 * 
 **/
void listdir(const char *path, int indent){


    DIR *dir;
    struct dirent *entry;

    if(!(dir = opendir(path))){
        printf("unable open dir: %s\n", path);
        return;
    }


    while((entry = readdir(dir)) != NULL){
        if(entry->d_type == DT_DIR){
            char new_path[1024];

            //--- ., ..
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
        
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
            // printf("[%s]\n", entry->d_name);
            printf("%*s[%s]\n", indent, "", entry->d_name);
            listdir(new_path, indent + 2);
        }else{
            printf("%*s- %s\n", indent, "", entry->d_name);
            // printf("file -  %s\n", entry->d_name);
        }
    }

    closedir(dir);
}