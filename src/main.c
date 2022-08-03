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
    strcpy(string,"M");

    readFile(table);

    strcode(table,string,strencoded);
    strdecode(table,strencoded,strendecoded);

    printf("%s\n",strencoded);
    printf("%s\n",strendecoded);
}