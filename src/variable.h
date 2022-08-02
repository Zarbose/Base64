#ifndef VARIABLE_H
#define VARIABLE_H

#define TAILLE_MAX 1000
#define NB_VALUE 65
#define TAILLE_BUFF 6

struct Value
{
    int index;
    int binary[6];
    char caract;
};
typedef struct Value Value;

#define CLEAR(ptr, size) memset((ptr), 0, (size)*sizeof(*ptr))

#endif