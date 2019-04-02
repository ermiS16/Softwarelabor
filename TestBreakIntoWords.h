/*
 * TestBreakIntoWords.h
 *
 *  Created on: 21.11.2018
 *      Author: Eric
 */

#ifndef TESTBREAKINTOWORDS_H_
#define TESTBREAKINTOWORDS_H_

#include "breakIntoWords.h"
#include "libs.h"
#include "enums.h"

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

#endif /* TESTBREAKINTOWORDS_H_ */
