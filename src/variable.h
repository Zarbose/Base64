#ifndef VARIABLE_H
#define VARIABLE_H

#define TAILLE_MAX 1000
#define NB_VALUE 64

struct Value
{
    int index;
    char binary[7];
    char caract;
};
typedef struct Value Value;

#endif