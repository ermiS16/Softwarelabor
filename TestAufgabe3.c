/*
 * TestAufgabe3.c
 *
 *  Created on: 21.11.2018
 *      Author: Eric
 */


#include "TestAufgabe3.h"

#define MAXWORDS 5

void runTests4(){
	testBreakIntoWords();
}

Test testBreakIntoWords(){
	char string[] = "Dies ist ein Beispieltext";
	char *words[MAXWORDS];
	words[0] = malloc(sizeof(char) * MAXWORDS);
	int index = 0;
	int amountWords = 0;
	amountWords = breakIntoWords(string, MAXWORDS, words);
	for(int i=0; i<amountWords;i++){
//		wordPtr = words[amountWords];
		index=0;
		while(*words[index] != ' ' && *words[index] != '\0'){
			printf("Word: %c", *words[index]);
			index++;
		}
		printf(" ");
	}
	printf("\n");
	Test t=OK;
	return t;
}
