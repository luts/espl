#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>

void compare(FILE *file1, FILE *file2);

/*int old_main(int argc, char **argv) {
  
      //char *file1_name = argv[1];
     //char *file2_name = argv[2];   
      //FILE *file1 = fopen( file1_name, "r");
      //FILE *file2 = fopen( file2_name, "r");
           
      compare(file1, file2);
      
      fclose(file1);
      fclose(file2);    
      return 0;
} 
*/
void compare(FILE *file1, FILE *file2){
         
	int counter = 0;           
	unsigned int letter1 = 0;
	unsigned int letter2 = 0;
	while(fread(&letter1, 1, 1, file1) & fread(&letter2, 1, 1, file2)) {
	    if ( letter1 != letter2 ){
		printf("byte %d -%d +%d\n",  counter+1, letter1, letter2 );
	    }
	    counter ++;
	}  
}

	

