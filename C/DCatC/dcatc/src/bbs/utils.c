/*
// uint32_t result = (unsigned char)(buf[0+offset])  |
    //         (unsigned char)(buf[1+offset]) << 8 |
    //         (unsigned char)(buf[2+offset]) << 16 |
    //         (unsigned char)(buf[3+offset]) << 24;


    // buf[offset] = (unsigned char)value;
    // buf[offset + 1] = (unsigned char)(value >> 8);
    // buf[offset + 2] = (unsigned char)(value >> 8);
    // buf[offset + 3] = (unsigned char)(value >> 8);

*/
#include <stdio.h>
#include "utils.h"


void print_buffer(char *buf, size_t size){
    for(int i=0; i<size; i++)
        printf("%#x ", buf[i]);
    printf("\n");
}






uint16_t unpack_u16(char *buf, size_t *offset){

    uint16_t result = 0;
    for(int i=0; i<2; i++){
        result |= (unsigned char)(buf[*offset]) << i*8;
        *offset += 1;
    }

    return result;
}

void pack_u16(char *buf, size_t *offset, uint16_t value){

    for(int i=0; i<2; i++){
        buf[*offset] = (unsigned char)(value >> (i*8));    
        *offset += 1;
    }

}


uint32_t unpack_u32(char *buf, size_t *offset){
    uint32_t result = 0;
    for(int i=0; i<4; i++){
        result |= (unsigned char)(buf[*offset]) << i*8;
        *offset += 1;
    }

    

    return result;
}

void pack_u32(char *buf, size_t *offset, uint32_t value){
    
    for(int i=0; i<4; i++){
        buf[*offset] = (unsigned char)(value >> (i*8));    
        *offset += 1;
    }
}


uint64_t unpack_u64(char *buf, size_t *offset){

    uint64_t result = 0;
    for(int i=0; i<8; i++){
        result |= (unsigned char)(buf[*offset]) << i*8;
        *offset += 1;
    }

    

    return result;
}

void pack_u64(char *buf, size_t *offset, uint64_t value){
    for(int i=0; i<8; i++){
        buf[*offset] = (unsigned char)(value >> (i*8));    
        *offset += 1;
    }


}