#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>
int main(int argc, char **argv) {
      int number = 0;
      int i;	
      int print = 1;
      while (1) {
	      char c;
	      c = getopt (argc, argv, "hnq\n");
	      if (c == -1) {
		  break;
	      }
	      switch (c) {
	      case 'h':
		  printf ("OPTIONS\n");
		  printf ("-h  print a summary of options and exit\n");
		  printf ("-n NUMBER  print first NUMBER differences and exit\n");
		  printf ("-q do not print out the differences, exits with code 0\n if the files are identical, 1 otherwise\n");
		  break;
	      case 'n':
		  for (i=0; i<argc; i++){
		    if ( !strcmp(argv[i], "-n") ){
		      number = atoi( argv[i+1] );
		      printf("number: %d\n", number);
		    }
		  }
		  break;
	      case 'q':
		  print = 0;
		  break;	    
	      default:
		  printf ("default\n");
	      }
      }  
      char *file1_name = argv[argc-2];
      char *file2_name = argv[argc-1];      
      unsigned int letter1 = 0;
      unsigned int letter2 = 0;
      FILE *file1 = fopen( file1_name, "r");
      FILE *file2 = fopen( file2_name, "r");
      int counter = 0;
      int counter2 = 0;      
      if (!file1){
	printf("Can't open the file1\n" );
	return 0;
      }
      if (!file2){
	printf("Can't open the file2\n" );
	return 0;
      }      

      while(fread(&letter1, 1, 1, file1) & fread(&letter2, 1, 1, file2)) {
	if ( ((letter1 != letter2) && number == 0 ) | ((letter1 != letter2) && number != 0 && counter < number )  ){  
	  if ( print ){
	    printf("byte %d -%d +%d\n",  counter2+1, letter1, letter2 );
	    counter++;
	  }
	}
	counter2 ++;
      }
      if ( counter > 0 ){
	return 1;
      }
      fclose(file1);
      fclose(file2);    
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
	

