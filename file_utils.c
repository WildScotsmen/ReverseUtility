#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/* This post taught me everything I now know about files in C: 
http://stackoverflow.com/questions/22697407/reading-text-file-into-char-array */
int read_file(char* filename, char **buffer) {
	// Variables. The stat struct is from Professor Woodring.
	FILE *fil;
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	// Opens up the file for extracting the data. If statement is for error-checking.
	fil = fopen(filename, "r");
	if (!fil) {
		fprintf(stderr, "Unable to read file.");
		return 0;
	}

	// Creates the space for our array. If statement is for error-checking.
	*buffer = malloc((size) * sizeof(char));
	if (!*buffer) {
		fprintf(stderr, "Unable to allocate memory.");
		fclose(fil);
		return 0;
	}

	/* Reads the data into our array. If statement is for error-checking, but it also contains the 
	command that reads in the data. */
	if (fread(*buffer, size, 1, fil) != 1) {
		fprintf(stderr, "Error copying file to memory.");
		fclose(fil);
		return 0;
	}

	// Closes the file and returns.
	fclose(fil);
	return size;
}

int write_file(char* filename, char *buffer, int size) {
	// File being operated on.
	FILE *fil;

	// Opens up the file for printing the data. If statement is for error-checking.
	fil = fopen(filename, "w");
	if (!fil) {
		fprintf(stderr, "Unable to write to that file.");
		fclose(fil);
		return 0;
	}

	/* Iterates through the buffer passed and prints it backwards to a text file. 
	If statement is for error-checking, but it also contains the command that writes the data. */
	for (size = size - 1; size >= 0; size--) {
		if (fprintf(fil, "%c", buffer[size]) != 1) {
			fprintf(stderr, "Error when writing to file.");
			fclose(fil);
			return 0;
		}
	}

	fclose(fil);
	return 1;
}