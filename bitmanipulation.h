/*
 * bitmanipulation.h
 *
 *  Created on: 31.10.2018
 *      Author: eric
 */

#ifndef BITMANIPULATION_H_
#define BITMANIPULATION_H_

#include "libs.h"
#include "enums.h"

typedef struct{
 char *input;
 char *expected;
}TestCaseBit;

#define TEST_NO_BIT 10
#define BYTEMASK 0xFF
#define BYTE 8

short int switchLowHighByte(short int i);
void serialize(Status s, Numbers n, short int *data);
void deserialize(short int data, Status *s, Numbers *n);


#endif /* BITMANIPULATION_H_ */
