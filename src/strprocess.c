#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strprocess.h"
#include "variable.h"


int strcode(Value* table, char* string, char* strencoded){

    int nb_byte=0, padding_zero=0, i=0, SIZE_LIST=0, padding_equal=0;
    int* list_byte = NULL;

    nb_byte=strlen(string);

    padding_zero=paddingZero(nb_byte); // Détection du nombre de zéros à rajouter
    SIZE_LIST=(8*nb_byte)+padding_zero;

    padding_equal=paddingEqual(SIZE_LIST); // Détection du nombre de = à rajouter
    SIZE_LIST=SIZE_LIST+padding_equal;

    // printf("SIZE_LIST = %d\n",SIZE_LIST);

    list_byte = malloc((SIZE_LIST)*sizeof(int));
    CLEAR(list_byte,SIZE_LIST);

    for (i=0; string[i]!='\0'; i++){ // Construction du tableau qui va contenir la liste des bits

        int token[8];
        intToByte((int)string[i],token);

        for (int j=0; j<8; j++){
            list_byte[(8*i)+j]=token[j];
        }
    }

    i=8*i;
    if (padding_zero > 0){ // Ajout des 0 pour le padding
        while (padding_zero > 0){
            list_byte[i]=0;
            padding_zero--; i++;
        }
    }

    if(padding_equal > 0){ // Ajout des valeurs pour le padding avec =
        while (padding_equal > 0){
            list_byte[i]=2;
            padding_equal--; i++;
        }
    }

    // for (int w=0; w<SIZE_LIST; w++){
    //     printf("%d",list_byte[w]);
    // }

    int cpt=0, index=0, cpt2=0;
    int buff[TAILLE_BUFF];

    for (int j=0; j<(SIZE_LIST)+1; j++){ // Construction de la chaine de sortie
        if(cpt == TAILLE_BUFF || j == SIZE_LIST){
            index=findCaract(table,buff);
            strencoded[cpt2]=table[index].caract;
            cpt=0;
            cpt2++;
        }

        buff[cpt]=list_byte[j];
        cpt++;
    }

    free(list_byte);
    
    return 0;
}

int paddingZero(int taille){
    int reste=(8*taille)%6;
    if(reste == 0)
        return 0;

    reste=6-reste;
    return reste;
}

int paddingEqual(int taille){
    int tmp=taille%24;
    if (tmp == 0)
        return 0;

    tmp=24-tmp;
    tmp=tmp/6;
    return tmp*6;
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