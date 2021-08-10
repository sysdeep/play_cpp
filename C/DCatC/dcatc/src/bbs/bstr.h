/*
- bstr - счётная строка [[str_len - ushort][binary string - str_len]]
*/
#ifndef BBS_BSTR_H
#define BBS_BSTR_H
#include <stdint.h>

typedef struct bstr_t{
    int32_t len;
    char *str;
}bstr_t;

#endif