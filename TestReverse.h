/*
 * TestReverse.h
 *
 *  Created on: 02.04.2019
 *      Author: eric
 */

#ifndef TESTREVERSE_H_
#define TESTREVERSE_H_

#define TEST_NO_REVERSE 6

#include "enums.h"
#include "libs.h"
#include "reverseString.h"

typedef struct{
	char *input;
	char *expected;
}TestCaseReverse;


void runTestsReverse(int no, TestCaseReverse test[]);
Test testReverse(char *input, char *expected);


#endif /* TESTREVERSE_H_ */
