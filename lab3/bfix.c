#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "diff.h"

int main(int argc, char **argv) {
      int print = 0;
      while (1) {
	      char c;
	      c = getopt (argc, argv, "hrm\n");
	      if (c == -1) {
		  break;
	      }
	      switch (c) {
	      case 'h':
		  printf ("OPTIONS\n");
		  printf ("-h  print a summary of options and exit\n");
		  printf ("-r  reverse the differences\n");
		  printf ("-m  print a message each time a change is applied\n");
		  break;
	      case 'r':
		  break;
	      case 'm':
		  print = 1;
		  break;	    
	      default:
		  printf ("default\n");
	      }
      }  	
      char *file_diff = argv[argc-1];
      char *file_to_fix = argv[argc-2];      
      FILE *file_differences = fopen( file_diff, "r");
      FILE *file1 = fopen( file_to_fix, "r+");
      
      struct diff diff;
      int counter = 0;
      if (!file_differences){
	printf("Can't open the file_differences\n" );
	return 0;
      }
      if (!file1){
	printf("Can't open the file1\n" );
	return 0;
      }      
      char line[64];
      while( fgets(line,sizeof(line),file_differences) != NULL ){
	parsediff(line, &diff);
	fseek( file1, diff.offset-1, SEEK_SET );
	fwrite( &diff.new, 1, 1, file1 );
	if ( print ){
	  printf("A change has been applied\n");
	}
      }
      fclose(file_differences);
      fclose(file1);
      return 0;
}








  /*for ( i = 1; i < argc; i++ ){
    if ( !strcmp(argv[i], "-h") ){ 
      printf("OPTIONS\n");
      printf("             -h  print a summary of options and exits.\n");
      printf("             -x  print the checksum as a hexadecimal rather than decimal number.\n");
      return 0;
    }    
    else if ( !strcmp(argv[i], "-x") ){ 
      type = 0;
    }
    else {
      file_index = i;
    }
      if ( type ){
	printf("checksum: %d\n",  checksum );
      }
      else{
	printf("checksum: %X\n",  checksum );
      }
      fclose(fp);    
  }*/
	

