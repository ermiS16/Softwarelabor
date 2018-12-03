/*
 * TestAufgabe3.h
 *
 *  Created on: 21.11.2018
 *      Author: Eric
 */

#ifndef TESTAUFGABE3_H_
#define TESTAUFGABE3_H_

#include "libs.h"
#include "enums.h"
#include "aufgabe3.h"

#define TEST_NO_BREAK 3
#define MAXWORDS1 5
#define MAXWORDS2 3
#define MAXWORDS3 5
#define EXPECTEDWORDS1 4
#define EXPECTEDWORDS2 3
#define EXPECTEDWORDS3 0

typedef struct{
	char *input;
	int maxwords;
	int expectedWords;
	char **expected;
}TestCaseBreakWord;


void runTestsBreakWord(int no, TestCaseBreakWord test[]);
Test testBreakIntoWords(char *input, int maxwords,
		int expectedWords, char *expected[]);

#endif /* TESTAUFGABE3_H_ */
