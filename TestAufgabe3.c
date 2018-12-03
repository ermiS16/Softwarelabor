/*
 * TestAufgabe3.c
 *
 *  Created on: 21.11.2018
 *      Author: Eric
 */

#include "TestAufgabe3.h"

#define MAXWORDS 3


void runTestsBreakWord(int no, TestCaseBreakWord test[]) {
	Test t;
	for (int i = 0; i < no; i++) {
		printf("Test %d: \n\n", i+1);
		t = testBreakIntoWords(test[i].input, test[i].maxwords,
				test[i].expectedWords, test[i].expected);
		if(t == OK){
			printf("Test: OK\n\n");
		}else{
			printf("Test: FAIL\n\n");
		}

	}

}

Test testBreakIntoWords(char *input, int maxwords, int expectedWords,char *expected[]) {
	Test t = OK;
	char *words[maxwords];
	int amountWords = 0;
	printf("Input: %s\n", input);
	printf("Maxwords: %d\n", maxwords);
	amountWords = breakIntoWords(input, maxwords, words);
	for (int i = 0; i < amountWords; i++) {

		if (strcmp(words[i], expected[i]) == 0) {
			t = OK;
		} else {
			t = FAIL;
		}
		printf("Word %d: %s, ", i + 1, words[i]);
		printf("Expected: %s\n", expected[i]);
	}
	printf("Words found: %d\n", amountWords);
	printf("Words Expected: %d\n", expectedWords);
	return t;
}
