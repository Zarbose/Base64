//
// utils.c
// base64
//
// Created Simon Pieto on 02/07/2023.
//

#include <stdio.h>

#include "constants.h"

void char_to_bin(char c, int *result, int start) {
    for (int i = 7; i >= 0; --i){
        result[start] = (c & (1 << i)) ? 1 : 0; start++;
        // printf("%c", (c & (1 << i)) ? '1' : '0');
    }
    // printf("\n");
}

void print_int_table(int *tab, int size) {
    for (int i = 0; i < size; i++){
        printf("%d",tab[i]);
    }
    printf("\n");
}

int padding_zero(int size){
    int r=(size)%6;
    if(r == 0) return 0;
    else return 6-r;
}