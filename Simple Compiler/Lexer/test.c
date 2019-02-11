//Title: Lexical Analyzer first build v1.0
//Purpose: The goal of this build is to conudct lexical analysis on the content of the file.
//Limitation: Current build strcutures the grammar to be dictated by whitespace; token only gets lexed if a whitspace is in-between the next token


#include <stdio.h>
#include <string.h>
#define FILE_NAME "result.txt"
#define buffer_size 1024

void filewriter(char *filename, char *content);
char* filereader(char *filename); //reads the content of the file and return them as a string. Only reads 1 line so far

int main(void){
	char *output="what";

	output = filereader("input.txt");

	filewriter(FILE_NAME, output);

	return 0;

}


char* filereader(char *filename){
	FILE *file_pointer;
	static char buffer[buffer_size]="initialization"; //memory will reallocate at buffer if "static" isnt defined

	file_pointer = fopen(filename, "r");
	fgets(buffer, sizeof(buffer), file_pointer);
	fclose(file_pointer);
	//printf("%s",buffer);
	return buffer;
}

void filewriter(char *filename, char *content){
	FILE *file_pointer;
	file_pointer = fopen(filename, "w");
	fprintf(file_pointer, content);
	fclose(file_pointer);
}