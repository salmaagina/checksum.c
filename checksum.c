/********************************/
/* Program Name: Checksum.c     */
/* Author: Salma Agina          */
/* Date: 2/9/2021               */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"

#define max_int (255)
#define byte (char)

int main(int argc, char * argv[], char ** envp)
{

	int count = 10;
	int sum = 0;
	int checksum;
	int complement;
	int quotient;
	int remainder;
	int input;

	for (int c = 1; c <= count; c++)
	{
		scanf_s("%d", &input);
		if (input > max_int)
		{
			fprintf(stderr, "Error in input \n");
			exit(1);
		}

		if (c == 10)
		{
			checksum = input;
			input = 0;
		}

		sum += input;
	}

	quotient = sum / (max_int + 1);
	remainder = sum & (max_int + 1);
	sum = quotient + remainder;
	complement = max_int - sum;

	/* the following is the prototype for the read system call */
	/* int read(int fildes, void *buf, size_t nbyte);  */
	fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
	if (checksum != complement) {
		fprintf(stderr, "Error Detected!\n");
		return 1;
	}
	return 0;
}
