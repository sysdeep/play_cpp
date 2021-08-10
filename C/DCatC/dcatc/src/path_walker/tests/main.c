#include <stdio.h>
#include "path_walker.h"

int main(int argc, char *argv[]){
    printf("PathWalker - test \n");


    path_walker_walk("/tmp");
    path_walker_walk("/opt");


    return 0;
}