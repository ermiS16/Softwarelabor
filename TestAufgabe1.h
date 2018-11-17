/*
 * switchTest.h
 *
 *  Created on: 01.11.2018
 *      Author: eric
 */

#ifndef TESTAUFGABE1_H_
#define TESTAUFGABE1_H_

#include "enums.h"
#include "libs.h"
#include "aufgabe1.h"


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

#endif /* TESTAUFGABE1_H_ */
