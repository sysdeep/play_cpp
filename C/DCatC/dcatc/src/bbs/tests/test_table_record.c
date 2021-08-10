#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "../bbs_table_record.h"
#include "../utils.h"






void test_table_record(){
    bbs_table_record_t table_record;
    table_record.type = 1;
    table_record.size = INT64_MAX;
    table_record.ctime = INT32_MAX;
    table_record.pid = 0;
    table_record.fid = 10;
    table_record.npos = 0;
    table_record.nsize = 10;
    table_record.dpos = 11;
    table_record.dsize = 10;

    char *buf = (char*)malloc(BBS_TABLE_RECORD_SIZE);

    // pack_table_record(buf, &table_record);
    // buf[0] = 1;
    // buf[2] = 13;

    

    // print_buffer(buf, BBS_TABLE_RECORD_SIZE);


    bbs_table_record_t readed_record;


    pack_table_record(buf, &table_record);
    print_buffer(buf, BBS_TABLE_RECORD_SIZE);
    unpack_table_record(buf, &readed_record);


    printf("type before: %d, type after: %d\n", table_record.type, readed_record.type);
    printf("size before: %lu, size after: %lu\n", table_record.size, readed_record.size);
    printf("ctime before: %lu, ctime after: %lu\n", table_record.ctime, readed_record.ctime);
    printf("rights before: %du, rights after: %du\n", table_record.rights, readed_record.rights);
    printf("fid before: %u, fid after: %u\n", table_record.fid, readed_record.fid);
    printf("pid before: %u, pid after: %u\n", table_record.pid, readed_record.pid);
    printf("npos before: %u, npos after: %u\n", table_record.npos, readed_record.npos);
    printf("nsize before: %du, nsize after: %du\n", table_record.nsize, readed_record.nsize);
    printf("dpos before: %u, dpos after: %u\n", table_record.dpos, readed_record.dpos);
    printf("dsize before: %du, dsize after: %du\n", table_record.dsize, readed_record.dsize);

    free(buf);

}


int main(){

    // printf("%d\n",s)

    
    //--- table record
    test_table_record();

    return 0;
}