/*

- magic 		[ushort 2] - идентификатор файла и метка контроля структуры
- version 		[ushort 2] - версия структуры файла
- header_len 	[ushort 2] - длина данных структуры заголовка
- row_len		[ushort 2] - длина данных структуры строки данных файла
- header_struct - структура заголовка
- row_struct - структура строки данных

*/
#ifndef BBS_HEADER_H
#define BBS_HEADER_H
#include <stdint.h>

#define BBS_HEADER_SIZE 4

typedef struct bbs_header_t{
    uint16_t magic;
    uint16_t version;
}bbs_header_t;


void pack_header(char *buf, bbs_header_t *record);
void unpack_header(char *buf, bbs_header_t *record);
void print_header(bbs_header_t *record);


#endif