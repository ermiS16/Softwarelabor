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

typedef struct {
  char* input;
  int expected;
} TestCaseCount;

void runTestsSuffix(void);
Test testSuffix(char *pattern, char *input, char *expected);
void runTestsSuffix2(void);
Test testSuffix2(char *pattern, char *input, char *expected);

Test testCount(char* input, int expected);
void runTestsCount(int no, TestCaseCount test[]);


#endif /* TESTAUFGABE2_H_ */
