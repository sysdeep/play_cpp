#include <stdio.h>
#include "path_walker.h"

int main(int argc, char *argv[]){
    printf("DCatC - start \n");


    path_walker_walk("/tmp");


    return 0;
}