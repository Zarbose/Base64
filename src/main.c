#include <stdio.h>
#include <stdlib.h>

#include "strprocess.h"
#include "variable.h"
#include "load.h"


int main(int argc, char* argv[]) {
    Value table[NB_VALUE];

    readFile(table);

    char string[4]={"Man"};
    strcode(table,string);

}