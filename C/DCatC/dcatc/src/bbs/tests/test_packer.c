#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "../bbs_table_record.h"
#include "../utils.h"





void test_u16(){
    printf("test u16 - start\n");
    char *buf = (char*)malloc(32);
    size_t pos_write = 0;
    size_t pos_read = 0;
    uint16_t source = UINT16_MAX;
    uint16_t result;

    pack_u16(buf, &pos_write, source);
    // print_buffer(buf, 32);
    result = unpack_u16(buf, &pos_read);
    // printf("source: %ld, result: %ld \n", source, result);
    assert(result == source);


    // pack_u16(buf, 1, source);
    // print_buffer(buf, 32);
    // result = unpack_u16(buf, 1);
    // assert(result == source);

    free(buf);
    printf("test u16 - end\n");
}



void test_u32(){
    printf("test u32 - start\n");
    char *buf = (char*)malloc(64);
    size_t pos_write = 0;
    size_t pos_read = 0;
    uint32_t source = UINT32_MAX;
    uint32_t result;

    pack_u32(buf, &pos_write, source);
    // print_buffer(buf, 64);
    result = unpack_u32(buf, &pos_read);
    assert(result == source);


    // pack_u32(buf, &pos_write, source);
    // // print_buffer(buf, 64);
    // result = unpack_u32(buf, &pos_read);
    // assert(result == source);

    free(buf);
    printf("test u32 - end\n");
}



void test_u64(){
    printf("test u64 - start\n");
    char *buf = (char*)malloc(64);
    size_t pos_write = 0;
    size_t pos_read = 0;
    uint64_t source = UINT64_MAX;
    uint64_t result;

    pack_u64(buf, &pos_write, source);
    // print_buffer(buf, 64);
    result = unpack_u64(buf, &pos_read);
    // printf("source: %lu, result: %lu \n", source, result);
    assert(result == source);

    free(buf);
    printf("test u64 - end\n");
}





int main(){

    // printf("%d\n",s)

    //--- pack unpack
    test_u16();
    test_u32();
    test_u64();


    return 0;
}