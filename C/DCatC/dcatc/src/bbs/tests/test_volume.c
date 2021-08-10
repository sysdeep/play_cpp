#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "../bbs_volume.h"
#include "../utils.h"






void test_volume(){
    bbs_volume_t record;

    record.created = 1;
    record.icon = 2;
    record.records = 3;
    record.table_len = 4;
    record.heap_len = 5;
    record.npos = 6;
    record.nsize = 7;
    record.ppos = 8;
    record.psize = 9;
    record.dpos = 10;
    record.dsize = 11;


    char *buf = (char*)malloc(BBS_VOLUME_SIZE);

    


    bbs_volume_t readed_record;


    pack_volume(buf, &record);
    print_buffer(buf, BBS_VOLUME_SIZE);
    unpack_volume(buf, &readed_record);


    print_volume(&record);
    print_volume(&readed_record);

    free(buf);

}


int main(){

    // printf("%d\n",s)

    
    //--- table record
    test_volume();

    return 0;
}