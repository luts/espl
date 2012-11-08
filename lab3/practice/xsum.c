#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(int argc, char **argv) {
  int i;
  int type = 1;
  int file_index = 0;
  for ( i = 1; i < argc; i++ ){
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
  }
  //if ( argv
  if ( file_index != 0 ){
      unsigned int word;
      unsigned int checksum;
      FILE *fp = fopen( argv[file_index], "r");      
      while(fread(&word, sizeof(word), 1, fp)) {
	//printf("word: %d\n",  word );
	checksum = checksum ^ word;
      }
      if ( type ){
	printf("checksum: %d\n",  checksum );
      }
      else{
	printf("checksum: %X\n",  checksum );
      }
      fclose(fp);
  }
  return 0;
}

	

