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
                    for (int k=0; k<TAILLE_BUFF; k++){
                        if (val[k] == '0')
                            table[i].binary[k] = 0;
                        else
                            table[i].binary[k] = 1;
                    }
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