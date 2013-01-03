#include <stdio.h>
#include <string.h>

int *bc_char2bits(int ch, int *bits){
  int bit;
  int j = 7;
  while ( ch != 0 ){
    bit = ch%2;
    
    //printf("%d", i);
    bits[j] = bit;
    ch = ch/2;
    j--;
  }
  return bits;
}

int main(int argc, char **argv) {
  char barcode[8][80] = {0};
  int i, j, x;
  int bits[8];
  int counter = 0;
  //creating barcode
  for ( i = 1; i < argc; i++ ){
    for ( j = 0; argv[i][j]; j++ ){
      //printf("%c", argv[i][j]);
      
      bc_char2bits(argv[i][j], bits);
      for ( x = 0; x < 8; x++ ){
	    if ( bits[x] == 1 ){
	      barcode[x][counter] = '#';
	    }
	    else{
	      barcode[x][counter] = ' ';
	    }
      }
      counter++;
      
    }
  }
  
  //printing barcode
  
  for ( i = 0; i < 8; i++ ){
    for ( j = 0; j < 80; j++ ){
      printf("%c", barcode[i][j]);
    }
    printf("\n");
  }
  
  return 0;
} 


