#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


#define max_int (255)
#define byte unsigned char


int main(int argc, char * argv[], char ** envp)
{

	int count = 10;
	int sum = 0;
	byte checksum;
	byte complement;
	int quotient;
	int remainder;
	byte header[10];

	/* the following is the prototype for the read system call */
	read(STDIN_FILENO, &header, count);

	for (int c = 1; c <= count; c++)
	{
		if (c == 6)
		{
			checksum = header[c];
			header[c] = 0;
		}
		sum += header[c];
	}

	quotient = sum / (max_int + 1);
	remainder = sum & (max_int + 1);
	sum = quotient + remainder;
	complement = max_int - sum;



	fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
	if (checksum != complement) 
	{
		fprintf(stderr, "Error Detected!\n");
		return 1;
	}
	return 0;
}
