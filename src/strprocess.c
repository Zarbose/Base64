#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strprocess.h"
#include "variable.h"


int strcode(Value* table, char* string, char* strencoded){

    int nb_byte=0;
    int* list_byte = NULL;

    nb_byte=strlen(string);
    list_byte = malloc((8*nb_byte)*sizeof(int));
    CLEAR(list_byte,8*nb_byte);

    for (int i=0; string[i]!='\0'; i++){ // Construction du tableau qui va contenir la liste des bits

        int token[8];
        intToByte((int)string[i],token);

        for (int j=0; j<8; j++){
            list_byte[(8*i)+j]=token[j];
        }
    }

    int cpt=0, index=0, cpt2=0;
    int buff[TAILLE_BUFF];

    for (int i=0; i<(8*nb_byte)+1; i++){

        if(cpt == TAILLE_BUFF || i == 8*nb_byte){
            index=findCaract(table,buff);
            strencoded[cpt2]=table[index].caract;
            cpt=0;
            cpt2++;
        }

        buff[cpt]=list_byte[i];
        cpt++;
    }

    free(list_byte);
    
    return 0;
}

int equalArrays(int* array1, int* array2){
    for (int i=0; i<TAILLE_BUFF; i++){
        if (array1[i] != array2[i])
            return 1;
    }
    return 0;
}

int findCaract(Value* table, int* bytes){
    int index=0;
    for (int i=0; i<NB_VALUE; i++){
        if (equalArrays(table[i].binary,bytes) == 0)
            index=i;
    }
    return index;
}

int intToByte(int value, int* result){

    int tab[8], nbr=value, j;
        
    for(j=0; nbr > 0; j++) {  
        tab[j] = nbr%2;  
        nbr = nbr/2;  
    } 

    if(j<8){
        int bites[8];
        int diff = 8-j;
        int k=0;

        for(k=0; k<diff;k++){
            bites[k]=0;
        }

        for(j=j-1; j >= 0; j--){
            bites[k]=tab[j];
            k++;
        }

        for (int m=0;m<8;m++){
            result[m]=bites[m];
        }

        return 0;
    }
    else{
        int k=0;
        for (j=j-1; j >= 0; j--){
            result[k]=tab[j];
            k++;
        }
    }

    return 0;
}