/*
 * TestAufgabe2.c
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */


#include "TestAufgabe2.h"

void runTests(){
	char pattern[] = ":";
	char string[] = {"Du::Bist::Ein::Idiot"};
	char expected[] = {"Idiot"};
	suffix(pattern, string, expected);
}

Test suffix(char* pattern, char* input, char *expected){
	Test t=OK;
	printf("Pattern: %s\nString: %s\n", pattern, input);
	printf("Output: %s, Expected: %s\n", extract(input, pattern), expected);
	return t;
}
