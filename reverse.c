#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv) {
	char* arg1; 
	char* arg2;
	struct stat st;

	if (argc != 3) {
		fprintf(stderr, "Invalid command. %d arguments passed. Only 2 allowed.\n", argc - 1);
		return 0;
	}
	
	arg1 = argv[1];
	arg2 = argv[2];

	stat(arg1, &st);
	int size = st.st_size;

	char* buffer;
	size = read_file(arg1, &buffer);
	write_file(arg2, buffer, size);
	return 1;
}