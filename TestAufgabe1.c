/*
 * switchTest.c
 *
 *  Created on: 01.11.2018
 *      Author: eric
 */

#include "TestAufgabe1.h"

void runSwitchTests() {
	short int number[] = { 0x0001, 0x1000, 0x1001, 0x0110, 0x1100, 0x0011,
			0x1110, 0x0111, 0x0101, 0x1010, 0xABCD };
	short int numberExpected[] = { 0x0100, 0x0010, 0x0110, 0x1001, 0x0011,
			0x1100, 0x1011, 0x1101, 0x0101, 0x1010, 0xCDAB };

	int number2[] = { 0xFFEFF, 0xFEEEF };
	int number2Expected[] = { 0xFFFE, 0xEFEE };
	printf("------------ Start Switch Byte Test ----------\n");
	//For Numbers in the valid Range
	printf("\nTest for Values inside the range:\n\n");
	for (int i = 0; i < sizeof(number) / sizeof(short int); i++) {
		printf("%d. Test: \n", i + 1);
		printf("switchLowHighByte: %d\n",
				testLowHigh(number[i], numberExpected[i]));
		printf("Switch-Switch: %d\n\n", testLowHighLow(number[i], number[i]));
	}
	//For Numbers outside the valid range
	printf("\nTest for Values outside the range:\n\n");
	for (int i = 0; i < sizeof(number2) / sizeof(int); i++) {
		printf("%d. Test: \n", i + 1);
		printf("Full Number: 0x%X: \n", number2[i]);
		printf("LowHighByte: %d\n",
				testLowHigh(number2[i], number2Expected[i]));
		printf("Switch-Switch: %d\n\n", testLowHighLow(number[i], number[i]));
	}
	printf("\n-------------- End Switch Byte Test -------------\n");
}

Test testLowHighLow(short int i, short int expected){
	Test t;
	short int switchNumber = switchLowHighByte(i);
	printf("Number: %04hX, ", i);
	printf("1. Switch: %04hX, ", switchNumber);
	switchNumber = switchLowHighByte(switchNumber);
	printf("2. Switch: %04hX, ", switchNumber);
	printf("Expected 2. Switch: %04hX\n", expected);
	if (expected == switchNumber) {
		t = OK;
	} else {
		t = FAIL;
	}
	return t;
}

Test testLowHigh(short int i, short int expected) {
	Test t;
	short int switchNumber = switchLowHighByte(i);
	printf("Number: %04hX, ", i);
	printf("Switch: %04hX, ", switchNumber);
	printf("Expected: %04hX\n", expected);
	if (expected == switchNumber) {
		t = OK;
	} else {
		t = FAIL;
	}
	return t;
}

void runSerializeTests() {
	Status s[] = { Stop, Start, Finish, Fail };
	Numbers n[] = { One, Fifteen, Last };
	short int expectedData[4][3] = { { 0x0001, 0x000F, 0x00FF }, { 0x0101, 0x010F,
			0x01FF }, { 0x0501, 0x050F, 0x05FF }, { 0xFF01, 0xFF0F, 0xFFFF },
			};
	short int data = 0;
	short int *dat = &data;
	int counter = 1;

	printf("\n-------------- Start Serialize Test -----------\n\n");
	for (int i = 0; i < sizeof(s) / sizeof(Status); i++) {
		for (int k = 0; k < sizeof(n) / sizeof(Numbers); k++) {
			printf("%d. Test:\n", counter++);
			printf("Test Serialize: %d\n\n",
					testSerialize(s[i], n[k], dat, expectedData[i][k]));

		}
	}
	printf("\n-------------- End Serialize Test -----------\n");
}

Test testSerialize(Status s, Numbers n, short int *data, short int expected) {
	Test t = OK;
	serialize(s, n, data);
	if (*data == expected) {
		t = OK;
	} else {
		t = FAIL;
	}
	printf("Status: %04X, Number: %04X, Serialized: %04hX, Expected: %04hX\n",
			s, n, *data, expected);
	return t;
}

void runDeserializeTests() {
	printf("\n-------------- Start Deserialize Test ------------\n\n");
	Status expectedStatus[] = { Stop, Start, Finish, Fail };
	Status stat = 0;
	Status *s = &stat;
	Numbers expectedNumber[] = { One, Fifteen, Last };
	Numbers numb = 0;
	Numbers *n = &numb;
	short int data[4][3] = { { 0x0001, 0x000F, 0x00FF }, { 0x0101, 0x010F,
			0x01FF }, { 0x0501, 0x050F, 0x05FF }, { 0xFF01, 0xFF0F, 0xFFFF}};
	int counter = 1;

	for (int i = 0; i < sizeof(data) / sizeof(*data); i++) {
		for (int k = 0; k < sizeof(*data) / sizeof(**data); k++) {
			printf("%d. Test:\n", counter++);
			printf("Test Deserialize: %d\n\n",
					testDeserialize(s, n, data[i][k], expectedStatus[i],
							expectedNumber[k]));
		}
	}

	printf("\n-------------- End Deserialize Test -----------\n");
}

Test testDeserialize(Status *s, Numbers *n, short int data,
		Status expectedStatus, Numbers expectedNumber) {
	Test t = OK;
//	printf("Data: %04X, ", data);
	deserialize(data, s, n);
	if (*s == expectedStatus) {
		if (*n == expectedNumber) {
			t = OK;
		}
	} else {
		t = FAIL;
	}
	printf("Data: %04hX, Status: %04X, Number: %04hX, Expected Status: %04hX, "
			"Expected Number: %04hX\n", data, *s, *n, expectedStatus,
			expectedNumber);
	return t;
}

void runSerializeDeserializeTests() {
	Status s[] = { Stop, Start, Finish, Fail };
	Numbers n[] = { One, Fifteen, Last };
	short int expectedData[4][3] = { { 0x0001, 0x000F, 0x00FF }, { 0x0101, 0x010F,
			0x01FF }, { 0x0501, 0x050F, 0x05FF }, { 0xFF01, 0xFF0F, 0xFFFF } };
	short int data = 0;
	short int *dat = &data;
	int counter=1;
	printf("\n-------------- Start Serialize-Deserialize Test -----------\n");
	for (int i = 0; i < sizeof(s) / sizeof(Status); i++) {
		for (int k = 0; k < sizeof(n) / sizeof(Numbers); k++) {
			printf("%d. Test:\n", counter++);
			printf("Test Serialize-Deserialize: %d\n\n",
					testSerializeDeserialize(s[i], n[k], dat, expectedData[i][k],
							s[i], n[k]));
		}
	}
	printf("\n-------------- End Serialize-Deserialize Test -----------\n");
}

Test testSerializeDeserialize(Status s, Numbers n, short int *data,
	short int expectedData, Status expectedStatus, Numbers expectedNumber){
	Status *ptrs = &s;
	Numbers *ptrn = &n;
	Test t=OK;
	serialize(s,n,data);
	printf("Status: %04X, Number: %04X, Serialized: %04hX, Expected: %04hX\n",
			s, n, *data, expectedData);
	deserialize(*data,ptrs,ptrn);
	printf("Data: %04hX, Status: %04X, Number: %04X, Expected Status: %04X, "
			"Expected Number: %04X\n", *data, *ptrs, *ptrn, expectedStatus,
			expectedNumber);
	if((*ptrs == expectedStatus) && (*ptrn == expectedNumber)){
		t=OK;
	}else{
		t=FAIL;
	}

	return t;

}
void runDeserializeSerializeTests(){
	Status expectedStatus[] = { Stop, Start, Finish, Fail };
	Status stat = 0;
	Status *s = &stat;
	Numbers expectedNumber[] = { One, Fifteen, Last };
	Numbers numb = 0;
	Numbers *n = &numb;
	short int data[4][3] = { { 0x0001, 0x000F, 0x00FF }, { 0x0101, 0x010F,
			0x01FF }, { 0x0501, 0x050F, 0x05FF }, { 0xFF01, 0xFF0F, 0xFFFF } };
	int counter = 1;
	printf("\n-------------- Start Deserialize-Serialize Test -----------\n");
	for (int i = 0; i < sizeof(data) / sizeof(*data); i++) {
		for (int k = 0; k < sizeof(*data) / sizeof(**data); k++) {
			printf("%d. Test:\n", counter++);
			printf("Test Deserialize-Serialize: %d\n\n",
					testDeserializeSerialize(s, n, data[i][k],
							expectedStatus[i], expectedNumber[k], data[i][k]));
		}
	}
	printf("\n-------------- End Deserialize-Serialize Test -----------\n");
}

Test testDeserializeSerialize(Status *s, Numbers *n, short int data,
		Status expectedStatus, Numbers expectedNumber, short int expectedData){
	Test t=OK;
	short int *ptrd = &data;
	deserialize(data, s, n);
	printf("Data: %04hX, Status: %04X, Number: %04X, Expected Status: %04X, "
			"Expected Number: %04X\n", data, *s, *n, expectedStatus,
			expectedNumber);
	serialize(*s,*n,ptrd);
	printf("Status: %04X, Number: %04X, Serialized: %04hX, Expected: %04hX\n",
			*s, *n, *ptrd, expectedData);
	if(*ptrd == expectedData){
		t=OK;
	}else{
		t=FAIL;
	}
	return t;
}

