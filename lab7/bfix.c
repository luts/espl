#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "diff.h"

void fix ( FILE *file1, char *line, int print);

int main(int argc, char **argv) {
      int print = 0;
      pid_t child_id;
      
      
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
	child_id = fork();
	if (child_id == -1) { perror("fork"); exit(EXIT_FAILURE); }
	if (child_id == 0) {
	      counter++;
	      printf("New child has been created. PID is %ld\n", (long) getpid());
	      fix(file1, line, print);
	      exit(0);	      
	}
      }
      int i;
      for ( i = 0; i < counter; i++ ){
	wait(0);
      }
      fclose(file_differences);
      fclose(file1);
      return 0;
}

void fix ( FILE *file1, char *line, int print){
        struct diff diff;
  	parsediff(line, &diff);
	fseek( file1, diff.offset-1, SEEK_SET );
	fwrite( &diff.new, 1, 1, file1 );
	if ( print ){
	  printf("A change has been applied\n");
	}	
}

