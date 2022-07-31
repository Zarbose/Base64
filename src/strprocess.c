#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strprocess.h"
#include "variable.h"


int strcode(Value* table, char* string){
    printf("\n");
    for (int i=0; string[i]!='\0'; i++){
        int result[8];
        intToByte((int)string[i],result);

        for(int j=0;j<8;j++){
            printf("%d",result[j]);
        }
        // printf("\n");
    } 
    
    return 0;
}

int intToByte(int value, int* result){

    int tab[8], nbr=value, j;
        
    for(j=0; nbr > 0; j++) {  
        tab[j] = nbr%2;  
        nbr = nbr/2;  
    } 
        
    // printf("%d Le nombre binaire est = ",j);


    if(j<8){
        int bites[8];
        int diff = 8-j;
        int k=0;

        for(k=0; k<diff;k++){
            bites[k]=0;
        }

        for(int l=0; l<8-diff;l++){
            bites[k]=tab[l];
            k++;
        }

        for (int m=0;m<8;m++){
            result[m]=bites[m];
        }

        return 0;
    }
    else{
        for (int m=0;m<8;m++){
            result[m]=tab[m];
        }
    }
    
    // for(j=j-1; j >= 0; j--) {  
    //     printf("%d",tab[j]);  
    // } 
    // printf("\n");


    return 0;
}