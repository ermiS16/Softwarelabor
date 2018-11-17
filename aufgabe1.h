/*
 * aufgabe1.h
 *
 *  Created on: 31.10.2018
 *      Author: eric
 */

#ifndef AUFGABE1_H_
#define AUFGABE1_H_

#include "libs.h"
#include "enums.h"

#define BYTEMASK 0xFF
#define BYTE 8

short int switchLowHighByte(short int i);
void serialize(Status s, Numbers n, short int *data);
void deserialize(short int data, Status *s, Numbers *n);


#endif /* AUFGABE1_H_ */
