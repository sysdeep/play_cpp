/*

## Структура Записи данных - row_struct

[type][size][ctime][rights][fid][pid][name][description]

- type 			[ushort 2]	- тип файла(каталог - 0/файл - 1)
- size 			[ulong 8]	- размер файла
- ctime 		[ulong 8]	- дата создания файла(unix timestamp)
- rights 		[ushort 2]	- код доступа(unix 777)
- fid 			[uint 4]	- id записи
- pid 			[uint 4]	- id родителя(0 - корень)
- name 			[bstr]		- название
- description 	[bstr]		- произвольное описание


Эти не пригодились ещё нигде...

- reserv 		[uint 4]	- резерв
- owner 		?[uint 4]	- владелец
- group			?[uint 4]	- группа



    Type   uint16
	Size   uint64
	Ctime  uint64
	Rights uint16
	FID    uint32
	PID    uint32
	NPos   uint32
	NSize  uint16
	DPos   uint32
	DSize  uint16


*/
#ifndef BBS_TABLE_RECORD_H
#define BBS_TABLE_RECORD_H
#define BBS_TABLE_RECORD_SIZE 52
#include <stdint.h>

// const int BBS_TABLE_RECORD_SIZE = 52;

typedef struct bbs_table_record_t{
    uint16_t type;          // 2
    uint64_t size;          // 8
    uint64_t ctime;         // 8
    uint16_t rights;        // 2
    uint32_t fid;           // 4
    uint32_t pid;           // 4
    uint32_t npos;          // 4
    uint16_t nsize;         // 2
    uint32_t dpos;          // 4
    uint16_t dsize;         // 2
}bbs_table_record_t;


void pack_table_record(char *, bbs_table_record_t *);
void unpack_table_record(char *, bbs_table_record_t *);

#endif