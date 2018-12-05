/*
 * TestAufgabe2.h
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */

#ifndef TESTAUFGABE2_H_
#define TESTAUFGABE2_H_

#include "aufgabe2.h"
#include "enums.h"

#define TEST_NO_COUNT 9
#define TEST_NO_SUFFIX 10

typedef struct {
	char* input;
	int expected;
} TestCaseCount;

typedef struct {
//	char* pattern;
	char* input;
	char* expected;
} TestCaseExtract;

void runTestSuffix(int no, TestCaseExtract test[]);
Test testSuffix(char *pattern, char *input, char *expected);
void runTestSuffix2(int no, TestCaseExtract test[]);
Test testSuffix2(char *pattern, char *input, char *expected);

Test testCount(char* input, int expected);
void runTestsCount(int no, TestCaseCount test[]);

#endif /* TESTAUFGABE2_H_ */
