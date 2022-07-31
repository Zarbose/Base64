#include <stdio.h>

#include "load.h"
#define NB_VALUE 64


int main(int argc, char* argv[]) {
    Value table[NB_VALUE];

    readFile(table);

    for (int i=0; i<NB_VALUE;i++){
        printf("%d %s %c\n",table[i].index,table[i].binary,table[i].caract);
    }

}