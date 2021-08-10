#include <stdio.h>
#include "bbs_header.h"
#include "utils.h"

void pack_header(char *buf, bbs_header_t *record){
    size_t pos = 0;

    pack_u16(buf, &pos, record->magic);
    pack_u16(buf, &pos, record->version);
    
};

void unpack_header(char *buf, bbs_header_t *record){
    size_t pos = 0;

    record->magic = unpack_u16(buf, &pos);
    record->version = unpack_u16(buf, &pos);
};

void print_header(bbs_header_t *record){
    printf("=== header ===\n");
    printf("magic:   %d\n", record->magic);
    printf("version: %d\n", record->version);
    printf("==============\n");
}