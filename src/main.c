#include <stdio.h>
#include <stdlib.h>

#include "strprocess.h"
#include "variable.h"
#include "load.h"


int main(int argc, char* argv[]) {
    Value table[NB_VALUE];
    char strencoded[TAILLE_MAX];
    char string[4]={"Man"};

    readFile(table);

    strcode(table,string,strencoded);

    printf("%s\n",strencoded);
}