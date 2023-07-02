//
// main.c
// base64
//
// Created Simon Pieto on 02/07/2023.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "encode.h"
#include "constants.h"

char str[50];
int action = 1;

int scan_opt(int argc, char **argv, const char *opt) {
	char c;
	while ((c = getopt (argc, argv, opt)) != -1)
		switch (c) {
			case 's': strcpy(str, optarg); break;
			case 'e': action = 1; break;
			case 'd': action = 0; break;
			default: return(-1);
		}
	return(0);
}

int generate(char *istr) {


    if (strlen(istr) == 0) return __OFF__;
    
    if (action == 1){
        
        encode(istr);
    }
    else {
        // Check format
        // decode(str);
    }

	return(__ON__);
}


int main(int argc, char * argv[]) {
	int exit_value = EXIT_SUCCESS;
	
	char *syntax =
	"c          -e : to encode the given string (default)\n"
	"c          -d : to encode the given string\n"
	"c          -s string    where string is the input string\n"
	"c          -h : help (shows the argument list)\n"
	;
	
	goto on_continue;
on_break:

	printf("c Syntax: %s <... Args ...>\n", argv[0]);
	printf("c Args:\n");
	printf("%s", syntax);
	printf("\n");
	exit_value = 1;
	goto end;
	
on_continue:
	if(scan_opt(argc, argv, "s:edh")) goto on_break;
	
	
	if(!generate(str)) {
		exit_value = EXIT_FAILURE;
	}
	
end:
	return((int) exit_value);
}