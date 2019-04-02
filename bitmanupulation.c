/*
 * bitmanipulation.c
 *
 *  Created on: 31.10.2018
 *      Author: eric
 */


#include "bitmanipulation.h"

short int switchLowHighByte(short int i){
	unsigned short int j = i;
	unsigned short int result = 0;
	unsigned short int temp_low = 0;
	unsigned short int temp_high = 0;

//		printf("Number: 0x%04X, ", j);
		temp_low = j >> BYTE;
		temp_high = j << BYTE;
		result = temp_high | temp_low;
//		printf("Switch: 0x%04X\n", result);

	return result;
}



void serialize(Status s, Numbers n, short int *data){
	*data = s;
	*data = *data << BYTE;
	*data |= n;
}
void deserialize(short int data, Status *s, Numbers *n){
	*n = data & BYTEMASK;
	data = data >> BYTE;
	*s = data & BYTEMASK;
}

