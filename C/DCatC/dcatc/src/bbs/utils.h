#ifndef BBS_UTILS_H
#define BBS_UTILS_H
#include <stdio.h>
#include <stdint.h>

void print_buffer(char *buf, size_t size);

uint16_t unpack_u16(char *buf, size_t *offset);
void pack_u16(char *buf, size_t *offset, uint16_t value);

uint32_t unpack_u32(char *buf, size_t *offset);
void pack_u32(char *buf, size_t *offset, uint32_t value);

uint64_t unpack_u64(char *buf, size_t *offset);
void pack_u64(char *buf, size_t *offset, uint64_t value);


#endif