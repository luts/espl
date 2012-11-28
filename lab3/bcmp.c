#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(int argc, char **argv) {
      unsigned int letter1 = 0;
      unsigned int letter2 = 0;
      FILE *file1 = fopen( "file1.txt", "r");
      FILE *file2 = fopen( "file2.txt", "r");
      int counter = 0;
      if (!file1){
	printf("Can't open the file1\n" );
	return 0;
      }
      if (!file2){
	printf("Can't open the file2\n" );
	return 0;
      }      
      while(fread(&letter1, 1, 1, file1) & fread(&letter2, 1, 1, file2)) {
	if ( letter1 != letter2 ){
	  printf("byte %d -%d +%d\n",  counter+1, letter1, letter2 );
	}
	counter++;
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
	

