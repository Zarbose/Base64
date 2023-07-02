//
// encode.c
// base64
//
// Created Simon Pieto on 02/07/2023.
//

#include <string.h>
#include <stdio.h>
#include <math.h>


#include "encode.h"
#include "utils.h"
#include "constants.h"


void encode(char* str){

    int len_bits=strlen(str)*8;
    len_bits+=padding_zero(len_bits);

    int bits[len_bits];
    CLEAR(bits,len_bits);

    int start = 0;
    for ( int i = 0; str[i] != '\0'; i++){
        char_to_bin(str[i],bits,start);
        start+=8;
    }

    print_int_table(bits,len_bits);
}