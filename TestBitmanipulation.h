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

void runTestBitmanipulation(int no, TestCaseBit test[]);

Test testLowHigh(short int i, short int expected);
Test testLowHighLow(short int i, short int expected);
void runSwitchTests();
Test testSerialize(Status s, Numbers n, short int *data, short int expected);
void runSerializeTests();
Test testDeserialize(Status *s, Numbers *n, short int data,
		Status expectedStatus, Numbers expectedNumber);
void runDeserializeTests();
Test testSerializeDeserialize(Status s, Numbers n, short int *data,
		short int expectedData, Status expectedStaus, Numbers expectedNumber);
void runSerializeDeserializeTests();
Test testDeserializeSerialize(Status *s, Numbers *n, short int data,
		Status expectedStatus, Numbers expectedNumber, short int expectedData);
void runDeserializeSerializeTests();

#endif /* TESTBITMANIPULATION_H_ */
