#include <stdlib.h>
#include <stdio.h>
#include "fgetname.h"
#include <string.h>
#include <assert.h>
#include "namelist.h"

int main(int argc, char **argv) {
	int i;
	namelist nl = make_namelist();
	char *save_keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "unsigned", "void", "volatile" ,"while"};
	for(i = 0; i < 31; i++) {
	  add_name(nl, save_keywords[i]);  
	}
	for ( i = 1; i < argc; i++){
	    FILE *stream = fopen( argv[i], "r");
	    char name[64];
	    if(!stream) {
		    fprintf(stderr, "run the test in the source directory\n");
		    return 1;
	    }
	    // insert the save keywords into a name list
	    while(fgetname(name, sizeof(name), stream)){
		    int i;
		    for(i = 0; i < 31; i++) {
			    if(!strcmp(name,save_keywords[i])) {

				  add_name(nl, name);  
			    }

		    }
	    }
	    fclose(stream);
	}
	// insert the save keywords into a name list
	for(i = 0; i!=nl->size; ++i) {
		if(nl->names[i].count == 2) {
		  printf("Save keyword: %s \n", nl->names[i].name);
		}
	}
	return 0;


}

	

