/*
 * TestBitmanipulation.c
 *
 *  Created on: 01.11.2018
 *      Author: eric
 */

#include "TestBitmanipulation.h"

/*
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
*/
void runTestLowHigh(int no, TestCaseLowHigh test[]){
	Test t = FAIL;
	for(int i=0; i<no; i++){
		printf("Test %d:\n", i+1);
		t = testLowHigh(test[i].input, test[i].expected);
		if(t){
			printf("Test: OK");
		}else{
			printf("Test FAIL");
		}
		printf("\n\n");
	}

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

void runTestSerialize(int no, TestCaseSerialize test[]) {
	Test t;
	short int data = 0;

	for (int i = 0; i < no; i++) {
		printf("%d. Test:\n", i+1);
		t = testSerialize(test[i].status, test[i].number, &data, test[i].expected);
		if(t){
			printf("Test: OK");
		}else{
			printf("Test: FAIL");
		}
		printf("\n\n");
	}
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

void runTestDeserialize(int no, TestCaseDeserialize test[]) {
	Test t;
	Status status = 0;
	Numbers number = 0;

	for(int i=0; i<no; i++){
		printf("Test %d: ", i+1);
		t = testDeserialize(&status, &number, test[i].data, test[i].expectedStatus,
				test[i].expectedNumber);
		if(t){
			printf("Test: OK");
		}else{
			printf("Test: FAIL");
		}
		printf("\n\n");
	}
}

Test testDeserialize(Status *s, Numbers *n, short int data,
		Status expectedStatus, Numbers expectedNumber) {
	Test t = OK;
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
