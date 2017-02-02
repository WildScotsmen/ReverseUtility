#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/************************************************************************************
* @author Scoots
* @version 2/02/2017
* @see file_utils.c
*
* This file contains the main method for executing the functions in file_utils.c.
*************************************************************************************/

/*
* Performs functions on data passed through the command line.
*
* @param argc, number of arguments.
* @param argv, command line arguments.
* @return 0 if the function failed and 1 if it succeeded.
*/
int main(int argc, char** argv) {
	// Variables
	char* arg1; 
	char* arg2;
	char* buffer;
	int size;

	// Checks for correct number of arguments
	if (argc != 3) {
		fprintf(stderr, "Invalid command. %d arguments passed. Only 2 allowed.\n", argc - 1);
		return 0;
	}
	
	// Stores filenames
	arg1 = argv[1];
	arg2 = argv[2];

	// Performs functions on variables
	size = read_file(arg1, &buffer);
	write_file(arg2, buffer, size);
	
	// Returns
	return 1;
}