#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv) {
	int barcode[BC_WIDTH+1][BC_NBITS];
	int i, j,
		n = 0; /* number of characters in the barcode */

	/* encode */
	while(*(++argv)) {
        char *arg = *argv;
		while(*arg) {
			bc_char2bits(*(arg++), barcode[n++]);
			if(n==BC_WIDTH)
				break; /* truncate on overflow */
		}

	    /* add space between words */
		bc_char2bits(' ', barcode[n++]);
	}
	if(n) --n; /* remove extraneous space at the end */
	
	/* print */
	for(j = 0; j!=BC_NBITS; ++j) {
		for(i = 0; i!=n; ++i)
			printf("%c", barcode[i][j]?BC_ONE:BC_ZERO);
		printf("\n");
	}
	
	return 0;
}
