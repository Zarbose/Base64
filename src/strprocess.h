#ifndef STRPROCESS_H
#define STRPROCESS_H

#include "variable.h"

int strcode(Value* table, char* string, char* strencoded);
int intToByte(int value, int* result);
int equalArrays(int* array1, int* array2);
int findCaract(Value* table, int* bytes);

#endif