/*
 * TestBitmanipulation.h
 *
 *  Created on: 01.11.2018
 *      Author: eric
 */

#ifndef TESTBITMANIPULATION_H_
#define TESTBITMANIPULATION_H_

#include "bitmanipulation.h"
#include "enums.h"
#include "libs.h"

#define TEST_NO_LOWHIGH 11
#define TEST_NO_SERIALIZE 12
#define TEST_NO_DESERIALIZE 12

typedef struct {
	short int input;
	short int expected;
}TestCaseLowHigh;

typedef struct {
	Status status;
	Numbers number;
	short int expected;
}TestCaseSerialize;

typedef struct{
	short int data;
	Status expectedStatus;
	Numbers expectedNumber;
}TestCaseDeserialize;

void runTestLowHigh(int no, TestCaseLowHigh test[]);
Test testLowHigh(short int i, short int expected);

void runTestSerialize(int no, TestCaseSerialize test[]);
Test testSerialize(Status s, Numbers n, short int *data, short int expected);

void runTestDeserialize(int no, TestCaseDeserialize test[]);
Test testDeserialize(Status *s, Numbers *n, short int data,
		Status expectedStatus, Numbers expectedNumber);

#endif /* TESTBITMANIPULATION_H_ */
