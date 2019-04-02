/*
 * TestCount.h
 *
 *  Created on: 02.04.2019
 *      Author: eric
 */

#ifndef TESTCOUNT_H_
#define TESTCOUNT_H_

#include "enums.h"
#define TEST_NO_COUNT 9

typedef struct {
	char* input;
	int expected;
} TestCaseCount;

Test testCount(char* input, int expected);
void runTestsCount(int no, TestCaseCount test[]);


#endif /* TESTCOUNT_H_ */
