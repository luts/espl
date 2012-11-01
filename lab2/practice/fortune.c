#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1] , "rt");

  if(!f){
    printf("ERROR");
    return -1;
  }
  
  printf("WORKS\n");
  char line[128];
  int counter = 1;
  int num_of_lines = 0;
  
  //counting number of lines:
  while( fgets(line,sizeof(line),f) != NULL ){
    num_of_lines++; 
  }
  //rewind(f);
  fseek(f, 0L, SEEK_SET);
  srand(time(0));
  int random = (rand() % (num_of_lines)) + 1;

  printf("random num: %d\n", random );
  while( fgets(line,sizeof(line),f) != NULL ){
    if ( random == counter ){
      printf("%d: ", counter);
      fputs ( line, stdout ); 
    }
    counter++;
    
  }
  
  fclose(f);
  return 0;
} 
