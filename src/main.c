//
// main.c
//
// Created by Simon Pieto on July 2022
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strprocess.h"
#include "variable.h"
#include "load.h"

int main(int argc, char* argv[]) {
    Value table[NB_VALUE];
    char strencoded[TAILLE_MAX];
    char strendecoded[TAILLE_MAX];
    char string[255];

    CLEAR(strencoded,TAILLE_MAX);
    CLEAR(strendecoded,TAILLE_MAX);
    CLEAR(string,TAILLE_MAX);

    readFile(table);

    printf("Write a word :");
    scanf("%s",string);

    
    strcode(table,string,strencoded);
    printf("code of \"%s\" => %s\n",string,strencoded);

    strdecode(table,strencoded,strendecoded);
    printf("decode of \"%s\" => %s\n",strencoded,strendecoded);


    return 0;
}