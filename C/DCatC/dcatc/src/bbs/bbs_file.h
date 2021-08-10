/*
    Binary File Format


    header
    volume
    table
    heap

*/
#ifndef BBS_FILE_H
#define BBS_FILE_H

#include <stdlib.h>
#include "./bbs_header.h"
#include "./bbs_volume.h"
#include "./bbs_table_record.h"
// #include "./bbs_heap.h"
#include "./bstr.h"

typedef struct bbs_t{
    bbs_header_t header;
    bbs_volume_t volume;
    bbs_table_record_t *table;
    bstr_t *heap;
    // bbs_heap_t heap;
}bbs_t;



// void load_db(char *buf, bbs_t *db);
// void dump_db(char *buf, bbs_t *db);


// void load_db(int fd, bbs_t *db);
// void dump_db(int fd, bbs_t *db);



//--- high level operations
void read_heap_string(char *buf, int16_t len, int64_t pos);
int64_t write_heap_string(char *buf, int16_t len);          // -> pos




#endif