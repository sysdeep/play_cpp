#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "../bbs_header.h"
#include "../utils.h"






void test_header(){
    bbs_header_t record;
    record.magic = 1;
    record.version = 23;

    char *buf = (char*)malloc(BBS_HEADER_SIZE);

    


    bbs_header_t readed_record;


    pack_header(buf, &record);
    print_buffer(buf, BBS_HEADER_SIZE);
    unpack_header(buf, &readed_record);


    printf("magic before: %d, magic after: %d\n", record.magic, readed_record.magic);
    printf("version before: %d, version after: %d\n", record.version, readed_record.version);


    print_header(&record);
    print_header(&readed_record);

    free(buf);

}


int main(){

    // printf("%d\n",s)

    
    //--- table record
    test_header();

    return 0;
}