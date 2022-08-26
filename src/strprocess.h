//
// strprocess.h
//
// Created by Simon Pieto on July 2022
//

#ifndef STRPROCESS_H
#define STRPROCESS_H

#include "variable.h"

int strcode(Value* table, char* string, char* strencoded);
int strdecode(Value* table, char* string, char* strendecoded);
int intToByte(int value, int* result);
int equalArrays(int* array1, int* array2);
int findCaract(Value* table, int* bytes);
int paddingZero(int taille);
int paddingEqual(int taille);
int byteToInt(int* value);

#endif