/*

type VolumeHeader struct {
	Created     uint64 // (8)				- дата создания(unix timestamp)
	Icon        uint16 // (2)				- icon_id
	Records     uint64 // (8)				- кол-во записей в базе
	TableLength uint64 // (8)				- длина секции табличных данных
	HeapLength  uint64 // (8)				- длина секции кучи
	NPos        uint32 // [uint 4] 	- позиция названия в куче
	NSize       uint16 // [ushort 2] 	- размер названия в куче
	PPos        uint32 // [uint 4] 	- позиция пути сканирования в куче
	PSize       uint16 // [ushort 2] 	- размер пути сканирования в куче
	DPos        uint32 // [uint 4] 	- позиция описания в куче
	DSize       uint16 // [ushort 2] 	- размер описания в куче
}

*/
#ifndef BBS_VOLUME_H
#define BBS_VOLUME_H
#include <stdint.h>

#define BBS_VOLUME_SIZE 52

typedef struct bbs_volume_t{
    uint64_t created;
    uint16_t icon;
    uint64_t records;
    uint64_t table_len;
    uint64_t heap_len;
    uint32_t npos;
    uint16_t nsize;
    uint32_t ppos;
    uint16_t psize;
    uint32_t dpos;
    uint16_t dsize;
}bbs_volume_t;



void pack_volume(char *buf, bbs_volume_t *record);
void unpack_volume(char *buf, bbs_volume_t *record);
void print_volume(bbs_volume_t *record);



#endif