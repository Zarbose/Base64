#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "load.h"
#include "variable.h"

int readFile(Value *table){

    FILE* inputFile = fopen( "../data/Base64Table.csv", "r" );
    char chaine[TAILLE_MAX];
    int i=0;


    if( inputFile == NULL){
        printf("Cannot open file\n");
    }
    else{
        fgets(chaine, TAILLE_MAX, inputFile);
        while ( fgets(chaine, TAILLE_MAX, inputFile) != NULL ){

            int j=0;
            char* s = strdup(chaine);
            char* val = strsep(&s,";");

            while(val!=NULL)
            {
                if (j==0){
                    table[i].index=atoi(val);
                }

                if (j==1){
                    strcpy(table[i].binary,val);
                }
                
                if (j==2){
                    table[i].caract=val[0];
                }   

                j++;
                val = strsep(&s,";");
            }
            i++;
        }
    }
    
    fclose(inputFile);

    return 0;
}