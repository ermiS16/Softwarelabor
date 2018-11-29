/*
 * TestAufgabe3.c
 *
 *  Created on: 21.11.2018
 *      Author: Eric
 */

#include "TestAufgabe3.h"

#define MAXWORDS 3


void runTests4(int no, TestCaseBreakWord test[]) {
//	char input[] = "Dies ist ein Beispieltext";
//	char *expected[] = { "Dies", "ist", "ein", "Beispieltext" };
	for (int i = 0; i < no; i++) {
		printf("Test %d: \n", i+1);
		printf("Test: %d\n", testBreakIntoWords(test[i].input, test[i].maxwords,
				test[i].expectedWords, test[i].expected));
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
	printf("\n");
	printf("Words found: %d\n", amountWords);
	printf("Words Expected: %d\n", expectedWords);
	return t;
}
