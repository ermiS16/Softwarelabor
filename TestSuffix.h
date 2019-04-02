/*
 * TestSuffix.h
 *
 *  Created on: 07.11.2018
 *      Author: eric
 */

#ifndef TESTSUFFIX_H_
#define TESTSUFFIX_H_

#include "enums.h"
#include "suffix.h"

#define TEST_NO_SUFFIX 14

typedef struct {
	char* pattern;
	char* input;
	char* expected;
} TestCaseExtract;

void runTestSuffix(int no, TestCaseExtract test[]);
Test testSuffix(char *pattern, char *input, char *expected);
void runTestSuffix2(int no, TestCaseExtract test[]);
Test testSuffix2(char *pattern, char *input, char *expected);
#endif /* TESTSUFFIX_H_ */
