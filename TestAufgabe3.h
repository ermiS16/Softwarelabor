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

typedef struct{
	char *input;
	int maxwords;
	char **expected;
}TestCaseBreakWord;

void runTests4(int no, TestCaseBreakWord test[]);
Test testBreakIntoWords(char *input, int maxwords, char *expected);

#endif /* TESTAUFGABE3_H_ */
