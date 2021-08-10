#include "bbs_table_record.h"
#include "utils.h"

void pack_table_record(char *buf, bbs_table_record_t *record){
    size_t pos = 0;

    pack_u16(buf, &pos, record->type);
    pack_u64(buf, &pos, record->size);
    pack_u64(buf, &pos, record->ctime);
    pack_u16(buf, &pos, record->rights);
    pack_u32(buf, &pos, record->fid);
    pack_u32(buf, &pos, record->pid);
    pack_u32(buf, &pos, record->npos);
    pack_u16(buf, &pos, record->nsize);
    pack_u32(buf, &pos, record->dpos);
    pack_u16(buf, &pos, record->dsize);

};

void unpack_table_record(char *buf, bbs_table_record_t *record){
    size_t pos = 0;

    record->type = unpack_u16(buf, &pos);
    record->size = unpack_u64(buf, &pos);
    record->ctime = unpack_u64(buf, &pos);
    record->rights = unpack_u16(buf, &pos);
    record->fid = unpack_u32(buf, &pos);
    record->pid = unpack_u32(buf, &pos);
    record->npos = unpack_u32(buf, &pos);
    record->nsize = unpack_u16(buf, &pos);
    record->dpos = unpack_u32(buf, &pos);
    record->dsize = unpack_u16(buf, &pos);
};
