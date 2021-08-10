#include "bbs_volume.h"
#include "utils.h"


void pack_volume(char *buf, bbs_volume_t *record){
    size_t pos = 0;

    pack_u64(buf, &pos, record->created);
    pack_u16(buf, &pos, record->icon);
    pack_u64(buf, &pos, record->records);
    pack_u64(buf, &pos, record->table_len);
    pack_u64(buf, &pos, record->heap_len);
    pack_u32(buf, &pos, record->npos);
    pack_u16(buf, &pos, record->nsize);
    pack_u32(buf, &pos, record->ppos);
    pack_u16(buf, &pos, record->psize);
    pack_u32(buf, &pos, record->dpos);
    pack_u16(buf, &pos, record->dsize);

}

void unpack_volume(char *buf, bbs_volume_t *record){
    size_t pos = 0;

    record->created = unpack_u64(buf, &pos);
    record->icon = unpack_u16(buf, &pos);
    record->records = unpack_u64(buf, &pos);
    record->table_len = unpack_u64(buf, &pos);
    record->heap_len = unpack_u64(buf, &pos);
    record->npos = unpack_u32(buf, &pos);
    record->nsize = unpack_u16(buf, &pos);
    record->ppos = unpack_u32(buf, &pos);
    record->psize = unpack_u16(buf, &pos);
    record->dpos = unpack_u32(buf, &pos);
    record->dsize = unpack_u16(buf, &pos);
}

void print_volume(bbs_volume_t *record){
    printf("=== volume ===\n");
    printf("created:   %lu\n", record->created);
    printf("icon: %d\n", record->icon);
    printf("records: %lu\n", record->records);
    printf("table_len: %lu\n", record->table_len);
    printf("heap_len: %lu\n", record->heap_len);
    printf("npos: %d\n", record->npos);
    printf("nsize: %d\n", record->nsize);
    printf("ppos: %d\n", record->ppos);
    printf("psize: %d\n", record->psize);
    printf("dpos: %d\n", record->dpos);
    printf("dsize: %d\n", record->dsize);
    printf("==============\n");
}
